#include <string.h>
#include <stdio.h>
#include "tp.h"
#include "tp_y.h"
#include "verif.h"


extern char *strdup(const char*);

extern void setError(int code);

/*
bool verifSurcharges(classeP c){
    classeP maClasse = c;
    if(maClasse == NIL(classe) ) return TRUE;
    classeP maClasse2 = maClasse;
    do{
        if(!verifSurcharges2(maClasse,maClasse2)) return FALSE; 
    }while(maClasse2->next != NIL(classe) );  

    return TRUE;
}

bool verifSurcharges2(classeP maClasse,classeP maClasse2){
    
    if(maClasse == maClasse2){
        methodP methodes = maClasse->lmethodes;
        while(methodes == NIL(methode) ){
            methodP methodes2 = methodes;
            while(methodes2->next != NIL(methode) ){ 
                methodes2 = methodes2->next;
                if(strcmp(methodes,methodes2) == 0) return FALSE;
            }
            methodes = methodes->next;

        }
    }
    return TRUE;
}
*/
/* #############################################################################################################*/


pileVar environnement; /* pile des variables pour la vérification contextuelles*/
extern classeP classes;
extern objectP objets;

void initPile(){
    environnement.sommet = NIL(elmtVar);
    environnement.taille = 0;
}

void empiler(VarDeclP decl){
    elmtVarP elem = NEW(1, elmtVar);
    elem->var = decl;
    elem->next = environnement.sommet;
    environnement.sommet = elem;
    environnement.taille += 1; 
}

void depiler(){
    elmtVarP temp = environnement.sommet;
    environnement.sommet = environnement.sommet->next;
    environnement.taille -= 1;
    free(temp);
}

void empilerBloc(VarDeclP listeChamp){
    VarDeclP declActuel = listeChamp;
    empiler(NIL(VarDecl));
    while (declActuel){
        empiler(declActuel);
        declActuel = declActuel->next;
    }
}

void depilerBloc(){
    elmtVarP elemActuel = environnement.sommet;
    while(elemActuel->next){
        elemActuel = elemActuel->next;
        depiler();
    }
    depiler();
}


/* IL SE PEUT QUE LES 'env' SOIENT INUTILES */
void analysePortee (TreeP corps){
    /*printf("Etiquette %s \n", recupEtiquette(corps->op));*/
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

            printf("%s 0\n", recupEtiquette(corps->op));
        	analysePortee(getChild(corps, 0));
            printf("%s 1\n", recupEtiquette(corps->op));
            analysePortee(getChild(corps, 1));
        	break;

        case ESEL : 
        case EDOT :
        case LSEL :
        case ESELDOT :
        case EADDSOLO : 
        case ESUBSOLO :
            printf("%s\n", recupEtiquette(corps->op));
            analysePortee(getChild(corps, 0));
            break;

        case ITE :
            printf("%s 0\n", recupEtiquette(corps->op));
            analysePortee(getChild(corps, 0));
            printf("%s 1\n", recupEtiquette(corps->op));
            analysePortee(getChild(corps, 1));
            printf("%s 2\n", recupEtiquette(corps->op));
            analysePortee(getChild(corps, 2));
            break;

        case CAST :
        case ENEW :
        case EEXTND : 
        	if(!verifClass(getChildStr(corps, 0))) printf("Id introuvable : %s \n", getChildStr(corps, 0));
            printf("%s\n", recupEtiquette(corps->op));
            analysePortee(getChild(corps, 1));
        	break;

        /* cas spécial des cas ^au dessus^ pck on a fait un truc bizarre dans la grammaire, à base de leafStr (on n'a pas fait partout comme ça) 
        le mieux ce serait quand même de rendre cohérente la grammaire de ce côté là hein*/
        case MSG :
            ; /* empty statement*/
             char* id = getChildStr(getChild(corps, 0), 0);
             /* TODO le fils gauche c'est pas un clasId donc c'est pas un verifClass qu'il faut faire */
            if(!verifClass(id)) printf("Id introuvable : %s \n", id);
            printf("%s\n", recupEtiquette(corps->op));

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



        case EBLOC :
            printf("%s\n", recupEtiquette(corps->op)); 
            if(getChild(corps, 1)){
                printf("#### Empilage Bloc\n");
                empilerBloc(getChild(corps, 0));

                printf("#### Bloc\n");
                analysePortee(getChild(corps, 1));

                printf("#### Depilage Bloc\n");
                depilerBloc();
            }
            else{
                analysePortee(getChild(corps, 0));
            }

            break;

        /*case ECLASS : break; 
        case EOBJ : break; TODO traitement à part : pour chaque classe et objet, faire l'analyse sur le corps des méthodes et expressions des vardecl */

        /*
        case ECLASS : break; unused 
        case LCHAMP : break;
        case LPARAM : break; unused 
        case LMETH : break;
        case CHMP : break;
        case EEXPR : break;
        case EARG : break;
        case EVAR : break;
        case EPAR : break;
        case EMETHOD : break;
        case EPROG : break;
         break;
        case EIDCLASS : break; unused */
        default :
            printf("Etiquette non prise en compte ou non reconnue : %s \n", recupEtiquette(corps->op)); 
            break;
	}
}

/* return un truc qui peut faire peter la fonction analyse */
bool verifId(char* id){
	elmtVarP elemActuel = environnement.sommet;
    while (elemActuel->var){
        if(strcmp(elemActuel->var->name, id) == 0) return TRUE;
        elemActuel = elemActuel->next;
    }
    return FALSE;
}

bool verifClass(char* nomClasse){
    classeP classeActuelle = classes;
    while (classeActuelle){
        if(strcmp(classeActuelle->name, nomClasse) == 0) return TRUE;
        classeActuelle = classeActuelle->next;
    }
    return FALSE;
}

