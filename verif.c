#include <string.h>
#include <stdio.h>

#include "tp.h"
#include "tp_y.h"
#include "verif.h"

extern char *strdup(const char*);
extern void setError(int code);

bool verifSurcharges(classeP c){
    printf("---Verifications surcharges ---\n");
    classeP maClasse = c;
    if(maClasse == NIL(classe) ) return true;
    while(maClasse != NIL(classe) ) {
        if(!verifSurcharges2(maClasse)) return false; /* Vraie verification entre les 2 classes */
        maClasse = maClasse ->next;
    }

    return true;
}

bool verifSurcharges2(classeP maClasse){
    methodP methodes = maClasse->lmethodes;
    while(methodes != NIL(method) ){


        /* On verifie que 2 methodes de la meme classe n'ont pas un meme nom */
        if(methodes->next != NIL(method) ){
            methodP methodes2 = methodes->next;
            while(methodes2 != NIL(method) ){ /*Tant que on peut comparer des methodes */
                if(strcmp(methodes->name,methodes2->name) == 0) return false; /* Si on a 2 méthodes du meme nom */
                methodes2 = methodes2->next;
            }
        }
        /* ------------------------- */


        /* On verifie que les overrides fonctionnent (sont bien lies) */
        if(methodes->redef == true){ /*Si on a ecrit Override -> on verifie qu'on est bien lie a une fonction plus haut */
            classeP classeMere = maClasse->super;
            if(classeMere == NIL(classe)){
                return false;
            }
            else{
                methodP methodesMere= classeMere->lmethodes;
                int ok = 0;
                while(methodesMere != NIL(method) && ok == 0 ){

                    if( strcmp(methodesMere->name,methodes->name) == 0){ /* On a trouve la methode de la classe mere */
                        if(methodesMere->typeRetour != methodes->typeRetour) /* Retours differents */
                            return false;

                        /* On verifie que les parametres sont bien les bons */
                        VarDeclP paramsMethode = methodes->param;
                        VarDeclP paramsMethodeMere = methodesMere->param;

                        while( paramsMethode != NIL(VarDecl) && paramsMethodeMere != NIL(VarDecl)) { /* Tant que au moins une fonction n'est pas vide */

                            if( strcmp(paramsMethode->nomType,paramsMethodeMere->nomType)!=0 ){
                                return false;
                            }

                            paramsMethode = paramsMethode->next;
                            paramsMethodeMere = paramsMethodeMere->next;
                        }

                        if( (paramsMethode != NIL(VarDecl) &&  paramsMethodeMere == NIL(VarDecl)) || (paramsMethode == NIL(VarDecl) &&  paramsMethodeMere != NIL(VarDecl)) ){ /* on a pas le meme nombre de parametres*/
                            return false;
                        }
                        ok = 1;
                    }
                    else{
                        methodesMere = methodesMere->next;
                    }
                }
                if(ok == 0){ /* si c'est vide : c'est que l'on a parcouru toutes les methodes de la mere sans trouver notre methode mere, ou que l'on a pas de methodes dans la mere*/
                    return false;
                }
            }
        }
        /* -------------------------- */
        /* On verifie que il n y a pas de surcharges entre classes */
        if(maClasse->super != NIL(classe)){ /* si on a une classe mere*/
            classeP classeM = maClasse->super;
            methodP methodeMere = NEW(1,method);
            methodeMere = classeM->lmethodes;
            while(methodeMere != NIL(method) ){
                if( strcmp(methodeMere->name,methodes->name) == 0 && methodes->redef == false){ /* 2 classes ont le meme nom */
                    VarDeclP paramsMethode = methodes->param;
                    VarDeclP paramsMethodeMere = methodeMere->param;
                    while( paramsMethode != NIL(VarDecl) || paramsMethodeMere != NIL(VarDecl)) {
                        if( strcmp(paramsMethode->nomType,paramsMethodeMere->nomType) ){ /* A CORRIGER AVEC NOM TYPE */
                            return false;
                        }
                        paramsMethode = paramsMethode->next;
                        paramsMethodeMere = paramsMethodeMere->next;
                    }
                    if( (paramsMethode != NIL(VarDecl) &&  paramsMethodeMere == NIL(VarDecl)) || (paramsMethode == NIL(VarDecl) &&  paramsMethodeMere != NIL(VarDecl)) ){ /* on a pas le meme nombre de parametres*/
                        return false;
                    }
                }
                methodeMere = methodeMere->next;
            }
            /* On verifie que aucune methode n'extends les classes predefinies (Str,int,void) */

            if(strcmp(classeM->name,"Void") == 0 || strcmp(classeM->name,"") == 0 || strcmp(classeM->name,"String") == 0 ){
                return false;
            }

            /* ----------------------------- */
        }
        /* ----------------------------- */
        methodes = methodes->next;

    }
    return true;

}

/* Verifier qu'on a pas de boucle dans le schema d'heritage */
bool heritageSansCircuit(classeP classes){

  while(classes != NIL(classe)){
      classeP tableau[50];
      classeP classeEnCours = classes; /* classe qui sert a tester par rapport a la pile */

      int i = 0;
      while(classeEnCours != NIL(classe) ){
          /* on verifie par rapport a la pile*/
          int j = 0;

          while(j<i){
            if( strcmp(classeEnCours->name,tableau[j]->name) == 0 ) /* si la classe qu'on etudie a deja ete vue => circuit */
              return false;
            else
              j++;
          }

          /* on continue s'il y a plus haut */
          if(classeEnCours->super != NIL(classe) ){
            tableau[i] = classeEnCours;
            i++;
            classeEnCours = classeEnCours->super;
          }
          else{
            classeEnCours = NIL(classe);
          }
      }

      classes = classes->next;
  }
  return true;
}

/* return null si erreur de typage sinon renvoie la type de l'expression */
char* typeExpr(TreeP arbreExpression,classeP classe){
    switch(arbreExpression->op){
        case EADD:
        {
            char* sousExp1 = typeExpr(getChild(arbreExpression,0),classe);
            char* sousExp2 = typeExpr(getChild(arbreExpression,1),classe);
            if(strcmp(sousExp1,sousExp2) == 0 && strcmp(sousExp1,"Integer")==0 && strcmp(sousExp2,"Integer") == 0 ){
               return sousExp1;
            }
            else{
              fprintf(stderr, "Erreur : typage Incorrect : addition impossible entre un %s et un %s\n",sousExp1,sousExp2);
              exit(TYPE_ERROR);
            }
        }
        case EMUL:
        {
            char* sousExp1 = typeExpr(getChild(arbreExpression,0),classe);
            char* sousExp2 = typeExpr(getChild(arbreExpression,1),classe);
            if(strcmp(sousExp1,sousExp2) == 0 && strcmp(sousExp1,"Integer")==0 && strcmp(sousExp2,"Integer") == 0 ){
               return sousExp1;
            }
            else{
              fprintf(stderr, "Erreur : typage Incorrect : multiplication impossible entre un %s et un %s\n",sousExp1,sousExp2);
              exit(TYPE_ERROR);
            }
        }
        case EQUOT:
        {
            char* sousExp1 = typeExpr(getChild(arbreExpression,0),classe);
            char* sousExp2 = typeExpr(getChild(arbreExpression,1),classe);
            if(strcmp(sousExp1,sousExp2) == 0 && strcmp(sousExp1,"Integer")==0 && strcmp(sousExp2,"Integer") == 0 ){
               return sousExp1;
            }
            else{
              fprintf(stderr, "Erreur : typage Incorrect : division impossible entre un %s et un %s\n",sousExp1,sousExp2);
              exit(TYPE_ERROR);
            }
        }
        case ESUB:
        {
            char* sousExp1 = typeExpr(getChild(arbreExpression,0),classe);
            char* sousExp2 = typeExpr(getChild(arbreExpression,1),classe);
            if(strcmp(sousExp1,sousExp2) == 0 && strcmp(sousExp1,"Integer")==0 && strcmp(sousExp2,"Integer") == 0 ){
               return sousExp1;
            }
            else{
                fprintf(stderr, "Erreur : typage Incorrect : soustraction impossible entre un %s et un %s\n",sousExp1,sousExp2);
                exit(TYPE_ERROR);
            }
        }
        case ESUBSOLO :
        {
          char* sousExp1 = typeExpr(getChild(arbreExpression,0),classe);
          if(strcmp(sousExp1,"Integer")==0 ){
             return sousExp1;
          }
          else{
            fprintf(stderr, "Erreur : typage Incorrect : %s au lieu de Integer\n",sousExp1);
            exit(TYPE_ERROR);
          }
        }

        case EADDSOLO :
        {
          char* sousExp1 = typeExpr(getChild(arbreExpression,0),classe);
          if(strcmp(sousExp1,"Integer")==0 ){
             return sousExp1;
          }
          else{
            fprintf(stderr, "Erreur : typage Incorrect : %s au lieu de Integer\n",sousExp1);
            exit(TYPE_ERROR);
          }
        }
        case EREST:
        {
          char* sousExp1 = typeExpr(getChild(arbreExpression,0),classe);
          char* sousExp2 = typeExpr(getChild(arbreExpression,0),classe);
          if(strcmp(sousExp1,sousExp2) == 0 && strcmp(sousExp1,"Integer")==0 && strcmp(sousExp2,"Integer") == 0 ){
             return sousExp1;
          }
          else{
            fprintf(stderr, "Erreur : typage Incorrect : %s au lieu de Integer\n",sousExp1);
            exit(TYPE_ERROR);
          }
        }
        case EINST: /*instantiation*/
        {
          TreeP instantiation = getChild(arbreExpression,0);
          if(instantiation->op == ENEW){
            return getChild(instantiation,0)->u.str; /* On retourne le classId*/
          }
        }
        case EAND :
        {
          char* sousExp1 = typeExpr(getChild(arbreExpression,0),classe);
          char* sousExp2 = typeExpr(getChild(arbreExpression,0),classe);
          if(strcmp(sousExp1,sousExp2) == 0 && strcmp(sousExp1,"Integer")==0 && strcmp(sousExp2,"Integer") == 0 ){
             return sousExp1;
          }
          else{
            fprintf(stderr, "Erreur : typage Incorrect :\n");
            exit(TYPE_ERROR);
          }
        }
        /* Partie arguments ou cible */
        case CSTE:
        {
          return "Integer";
        }

        case ETHISSELECT:
        {
          char* classeName = classe->name;
          TreeP sousArbre = getChild(arbreExpression,0);
          /* Partie ThisSelect */
          switch(sousArbre->op){
            case ETHIS :
              return classeName;
            case EDOT :
            {
              char* maSelection = typeExpr(getChild(sousArbre,1),classe);
              return maSelection;
            }
            case LISTDOT :
            {
              return typeExpr(getChild(sousArbre,1),classe);
            }
          }
        }

        case EDOT:
        {
          if(arbreExpression->nbChildren == 2){
            /* On est dans ListSelection*/

            TreeP sousArbre1 = getChild(arbreExpression,0);
            TreeP sousArbre2 = getChild(arbreExpression,1);
            char* classeEnCours = NULL; /*classe a partir de laquelle on va chercher la selection*/

            /*Partie SelWithClassID*/
            switch (sousArbre1->op){
              case LSEL:
              {
                classeEnCours =  typeExpr(getChild(sousArbre1,0),classe);
              }
              case ESEL:
              {
                classeEnCours = typeExpr(getChild(sousArbre1,0),classe);
              }
              case CLASS:
              {
                classeEnCours = getChild(sousArbre1,0)->u.str;
              }
            }
            return typeExpr(sousArbre2,idToClass(classeEnCours));
          }
          else{
            return typeExpr(getChild(arbreExpression,0),classe);
          }
        }
        /*Partie selection( pour la récursivité) */
        case EID :
        {
          char* typeAtt = typeAttribut(getChild(arbreExpression,0)->u.str,classe);
          return typeAtt;
        }
        case CSTR :
        {
          return "String";
        }

        case EEXPR :
        {
          return typeExpr(getChild(arbreExpression,0),classe);
        }
        case CAST :
        {
          TreeP sousexp1 = getChild(arbreExpression,1);
          char* typeExpressionCast = typeExpr(sousexp1,classe);
          char* typeCast = getChild(arbreExpression,0)->u.str;
          if(verificationCast(typeExpressionCast,typeCast)) /* On verifie le lien entre les 2 classes*/
            return typeCast;
          else{
            fprintf(stderr, "Erreur : cast Incorrect : %s doit être une fille de %s\n",typeExpressionCast,typeCast);
            exit(TYPE_ERROR);
          }
        }

        case MSG:
        {
          /* On recherche d'abord le type de la fonction */
          char* typeMsg = typeFonction(getChild(arbreExpression,0)->u.str,classe);
          return typeMsg;
        }

        default:
        {
          fprintf(stderr, "Erreur : typage Incorrect \n");
          exit(TYPE_ERROR);
        }

    }
    fprintf(stderr, "Erreur : typage Incorrect\n");
    exit(TYPE_ERROR);
}

/* verifier la declaration d'un champ (verifier que le type de la decl correspond au type qu'on donne a var) */
bool verificationChamp(TreeP arbreExpression,classeP classe){
  char* typeVar = getChild(arbreExpression,1)->u.str;
  TreeP exprOpt = getChild(arbreExpression,2);
  if(exprOpt != NIL(Tree)){
    if(exprOpt->op == EAFF){
      char* typeExpression = typeExpr(getChild(exprOpt,0),classe);
      if(typeExpression != NULL){
        if(strcmp(typeVar,typeExpression) == 0){
          return true;
        }
        else{
          return false;
        }
      }
    }
    else{
      return true;
    }
  }
  return false;
}

/* s'assurer qu'il y a bien un lien entre la mere et la fille pour la verification de cast (fonctionnal) */
bool verificationCast(char* fille,char* mere){
  classeP classeFille = idToClass(fille);
  classeP classeMere  = idToClass(mere);
  if(classeFille->super != NIL(classe)){
    classeFille = classeFille->super;
  }
  else{
    return false;
  }
  while(classeFille != NIL(classe)){
    if(strcmp(classeFille->name,classeMere->name)==0){
      return true; /* On a trouve le lien */
    }
    else{
      if(classeFille->super != NIL(classe)){
        classeFille = classeFille->super;
      }
      else{ /* On a pas trouve la classe mere en remontant les classes*/
        return false;
      }
    }
  }
  return false;
}

/*renvoie le type d'une fonction*/
char* typeFonction(char* name,classeP maClasse){
  methodP methodes = maClasse->lmethodes;
  while(methodes != NIL(method)){

    if(strcmp(methodes->name,name) == 0){ /* on a trouve la methode*/
      return methodes->nomTypeRetour;
    }
    else{
      methodes = methodes->next;
    }
  }
  /*On a pas trouve la methode dans la classe courante*/
  if(maClasse->super != NIL(classe) ){
    return typeFonction(name,maClasse->super);
  }
  else{
    fprintf(stderr, "Erreur : typage Fonction Incorrect\n");
    exit(TYPE_ERROR);
  }
}


char* typeAttribut(char* name,classeP maClasse){
  VarDeclP attributs = maClasse->attributs;
  while(attributs != NIL(VarDecl)){

    if(strcmp(attributs->name,name) == 0){ /* on a trouve la methode*/
      return attributs->nomType;
    }
    else{
      attributs = attributs->next;
    }
  }
  /*On a pas trouve la methode dans la classe courante*/
  if(maClasse->super != NIL(classe) ){
    return typeFonction(name,maClasse->super);
  }
  else{
    fprintf(stderr, "Erreur : typage Fonction Incorrect\n");
    exit(TYPE_ERROR);
  }
}
