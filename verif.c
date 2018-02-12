#include <string.h>
#include <stdio.h>

#include "tp.h"
#include "tp_y.h"
#include "verif.h"

extern char *strdup(const char*);
extern void setError(int code);

pileVar environnement; /* pile des variables pour la vérification contextuelles*/
extern classeP classes;
extern objectP objets;

 /* Initialise la pile */
void initPile(){
    environnement.sommet = NIL(elmtVar);
    environnement.taille = 0;
}

/* Empile un element de pile ayant pour VarDecl decl */
void empiler(VarDeclP decl){
    elmtVarP elem = NEW(1, elmtVar);
    elem->var = decl;
    elem->next = environnement.sommet;
    environnement.sommet = elem;
    environnement.taille += 1;
}

/* Dépile le sommet de la pile d'environnement */
void depiler(){
    elmtVarP temp = environnement.sommet;
    environnement.sommet = environnement.sommet->next;
    environnement.taille -= 1;
    free(temp);
}

/* Fait les empilements nécessaires pour gérer la portée des variables dans un bloc */
void empilerBloc(VarDeclP listeChamp){
    VarDeclP declActuel = listeChamp;
    empiler(NIL(VarDecl));
    while (declActuel){
        empiler(declActuel);
        declActuel = declActuel->next;
    }
}

/* Fait les dépilements nécessaires pour gérer la portée des variables dans un bloc */
void depilerBloc(){
    elmtVarP elemActuel = environnement.sommet;
    while(elemActuel->next){
        elemActuel = elemActuel->next;
        depiler();
    }
    depiler();
}


/* Fonction principale de l'analyse de portée */
void analysePortee (TreeP corps){
	switch(corps->op){
		case EADD :
        case ESUB :
        case NE :
        case EQ :
        case LT :
        case LE :
        case GT :
        case GE :
        case EMUL :
        case EQUOT :
        case EREST :
        case EAND :
        case ELISTSEL :
        case EAFF :
        case LARG :
        case LINST :

        	analysePortee(getChild(corps, 0));
            analysePortee(getChild(corps, 1));
        	break;

        case ESEL :
        case LSEL :
        case ESELDOT :
        case EADDSOLO :
        case ESUBSOLO :
            analysePortee(getChild(corps, 0));
            break;

        case ITE :
            analysePortee(getChild(corps, 0));
            analysePortee(getChild(corps, 1));
            analysePortee(getChild(corps, 2));
            break;

        case CAST :
        case ENEW :
        case EEXTND :
        	if(!verifClass(getChildStr(corps, 0))) printf("Erreur : ClassId introuvable : %s \n", getChildStr(corps, 0));
            analysePortee(getChild(corps, 1));
        	break;

        /* cas spécial des cas ^au dessus^ pck on a fait un truc bizarre dans la grammaire, à base de leafStr (on n'a pas fait partout comme ça)
        le mieux ce serait quand même de rendre cohérente la grammaire de ce côté là hein*/
        case MSG :
            ; /* empty statement*/
             char* id = getChildStr(getChild(corps, 0), 0);
             /* TODO le fils gauche c'est pas un clasId donc c'est pas un verifClass qu'il faut faire */
            if(!verifClass(id)) printf("Erreur : Id introuvable : %s \n", id);

            /* ici c'est un ListArgumentOpt donc peut valoir Nil(Tree) */
            if (getChild(corps, 1)) analysePortee(getChild(corps, 1));
            break;

        case ETHIS :
        case ERETURN :
        case CSTE :
        case CSTR :
        case OVER :
        	break;

        case EID :
        	if(!verifId(getChildStr(corps, 0))) printf("Erreur : Id introuvable : %s \n", getChildStr(corps, 0));
        	break;

        case EIDCLASS :
            if(!verifClass(getChildStr(corps, 0))) printf("Erreur : ClassId introuvable : %s \n", getChildStr(corps, 0));
            break;

        case EBLOC :
            if(getChild(corps, 1)){
                empilerBloc((VarDeclP)getChild(corps, 0)); /* On a une fonction nommée getChildDecl() qui a la même utilité que getChild mais renvoie de manière "propre" un fils de type VarDeclP. Cependant, l'utiliser ici nous donne une Segmentation Fault inattendue dont la source n'est pas de notre ressort */

                analysePortee(getChild(corps, 1));

                depilerBloc();
            }
            else{
                analysePortee(getChild(corps, 0));
            }

            break;

        case EDOT :
            if (!verifDot(getChild(corps,0))) printf("Erreur : Appel à une méthode inconnue (Opération DOT)\n");
            break;

        default :
            printf("Erreur : Etiquette non prise en compte ou non reconnue : %s \n", recupEtiquette(corps->op));
            break;
	}
}

/* Renvoie true si un VarDecl ayant pour nom id existe */
bool verifId(char* id){
	elmtVarP elemActuel = environnement.sommet;
    while (elemActuel->var){
        if(strcmp(elemActuel->var->name, id) == 0) return TRUE;
        elemActuel = elemActuel->next;
    }
    return FALSE;
}

/* Renvoie true si une classe ayant pour nom nomClasse existe */
bool verifClass(char* nomClasse){
    classeP classeActuelle = classes;
    while (classeActuelle){
        if(strcmp(classeActuelle->name, nomClasse) == 0) return TRUE;
        classeActuelle = classeActuelle->next;
    }
    return FALSE;
}

/* Renvoie true si la classe a une methode ayant pour nom nomMethode */
bool verifMethodeDansClasse(classeP class, char* nomMethode){
    methodP methActuelle = class->lmethodes;
    while (methActuelle){
        if(strcmp(methActuelle->name, nomMethode) == 0) return TRUE;
        methActuelle = methActuelle->next;
    }
    return FALSE;
}

/* Renvoie true si la classe a un champ ayant pour nom nomChamp */
bool verifChampDansClasse(classeP class, char* nomChamp){
    VarDeclP chpActuel = class->attributs;
    while (chpActuel){
        if(strcmp(chpActuel->name, nomChamp) == 0) return TRUE;
        chpActuel = chpActuel->next;
    }
    return FALSE;
}

/* Parcours l'arbre jusqu'à tomber sur un Id */
char* getId(TreeP arbre){
    int i = 0;
    char* id = NEW(1, char);
    switch(arbre->op){
        case EID :
            return getChildStr(arbre, 0);
            break;
        default :
            if (arbre->nbChildren > 0){
                for (i = 0; i < arbre->nbChildren; i++){
                    id = getId(getChild(arbre, i));
                    if (id) return id;
                }
                return NIL(char);
            }
            else return NIL(char);
    }
}

/* Fait les vérifications nécésaires pour un arbre dont l'étiquette est EDOT */
bool verifDot(TreeP sel){
    char* varId = getId(getChild(sel, 0));
    if (!varId){
        fprintf(stderr, "Erreur : Tentative d'appel de fonction de recherche avec une entrée = null. Arrêt du programme.\n");
        exit(DECL_ERROR);
    }
    VarDeclP var = idToDecl(varId);
    classeP cl = var->type;
    char* id = getId(getChild(sel, 1));
    if (verifChampDansClasse(cl, id)) return TRUE;
    else return verifMethodeDansClasse(cl, id);
}

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
