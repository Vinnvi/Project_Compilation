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
        	if(!verifClass(getChildStr(corps, 0))) printf("ClassId introuvable : %s \n", getChildStr(corps, 0));
            analysePortee(getChild(corps, 1));
        	break;

        /* cas spécial des cas ^au dessus^ pck on a fait un truc bizarre dans la grammaire, à base de leafStr (on n'a pas fait partout comme ça) 
        le mieux ce serait quand même de rendre cohérente la grammaire de ce côté là hein*/
        case MSG :
            ; /* empty statement*/
             char* id = getChildStr(getChild(corps, 0), 0);
             /* TODO le fils gauche c'est pas un clasId donc c'est pas un verifClass qu'il faut faire */
            if(!verifClass(id)) printf("Id introuvable : %s \n", id);

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
        	if(!verifId(getChildStr(corps, 0))) printf("Id introuvable : %s \n", getChildStr(corps, 0));
        	break;

        case EIDCLASS :
            if(!verifClass(getChildStr(corps, 0))) printf("ClassId introuvable : %s \n", getChildStr(corps, 0));
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
            if (!verifDot(getChild(corps,0))) printf("Appel à une méthode inconnue (Opération DOT)\n");
            break;

        default :
            printf("Etiquette non prise en compte ou non reconnue : %s \n", recupEtiquette(corps->op)); 
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

    VarDeclP var = idToDecl(getId(getChild(sel, 0)));
    classeP cl = var->type;
    char* id = getId(getChild(sel, 1));
    if (verifChampDansClasse(cl, id)) return TRUE;
    else return verifMethodeDansClasse(cl, id);
}

