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

void depilerBloc(){
    elmtVarP elemActuel = environnement.sommet;
    while(elemActuel){
        elemActuel = elemActuel->next;
        depiler();
    }
    depiler();
}


/* IL SE PEUT QUE LES 'env' SOIENT INUTILES */
void analysePortee (TreeP corps, pileVar env){
	switch(corps->op){
		case EADD : 
        case ESUB :
        	if(corps->nbChildren == 1){
        		analysePortee(getChild(corps, 0), env);
        		break;
        	}

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
        	analysePortee(getChild(corps, 0), env);
        	analysePortee(getChild(corps, 1), env);
        	break;

        case EAFF :
        	analysePortee(getChild(corps, 1), env);
            analysePortee(getChild(corps, 0), env);
            /*if(getChild(corps, 0)->op == EID){
                if(!verifId(getChildStr(corps, 0), env)) empiler();    
            } TODO pas necessaire a priori de faire d'ajouts ici*/
        	break;

        case ESELDOT : 
        	analysePortee(getChild(corps, 0), env);
        	break;

        case EDOT :
        case LARG :
        case LINST :
        case LCLASS :
        	analysePortee(getChild(corps, 0), env);
        	analysePortee(getChild(corps, 1), env);
        	break;


        case CAST :
        case MSG :
        case ENEW :
        case EEXTND : 
        	if(!verifClass(getChildStr(corps, 0), env)) printf("Id introuvable : %s \n", getChildStr(corps, 0));
        	analysePortee(getChild(corps, 1), env); 
        	break;

        case ETHIS : 
        case ERETURN :
        case CSTE :
        case CSTR : 
        	break;

        case EID :
        	if(!verifId(getChildStr(corps, 0), env)) printf("Id introuvable : %s \n", getChildStr(corps, 0));
        	break;


        case ITE :
        	analysePortee(getChild(corps, 0), env);
        	analysePortee(getChild(corps, 1), env);
        	analysePortee(getChild(corps, 2), env);
        	break;

        case EBLOC : 
            empiler(NIL(VarDecl));
            /* TODO empiler les valeurs du premier fils du bloc (= la liste des champs) [env = empilageChamps(getchild, env) qui fait l'analyse en même temps pour chaque expression de valeur de champ] puis faire l'analyse du 2e fils avec */ 
            analysePortee(getChild(corps, 0), env);
            depilerBloc();
            break;

        /*case ECLASS : break; 
        case EOBJ : break; TODO traitement à part : pour chaque classe et objet, faire l'analyse sur le corps des méthodes et expressions des vardecl */

        case OVER : break;

        /*
        case ECLASS : break; unused 
        case LCHAMP : break;
        case LPARAM : break; unused 
        case LMETH : break;
        case CHMP : break;
        case EEXPR : break;
        case ESEL : break;
        case EARG : break;
        case EVAR : break;
        case EPAR : break;
        case EMETHOD : break;
        case EPROG : break;
        case LSEL : break;
        case EIDCLASS : break; unused */
        default :
            printf("Etiquette non prise en compte ou non reconnue : %s \n", recupEtiquette(corps->op)); 
            break;
	}
}

/* return un truc qui peut faire peter la fonction analyse */
bool verifId(char* id, pileVar env){
	elmtVarP elemActuel = env.sommet;
    while (elemActuel){
        if(strcmp(elemActuel->var->name, id) == 0) return TRUE;
        elemActuel = elemActuel->next;
    }
    return FALSE;
}

bool verifClass(char* nomClasse, pileVar env){
    classeP classeActuelle = classes;
    while (classeActuelle){
        if(strcmp(classeActuelle->name, nomClasse) == 0) return TRUE;
        classeActuelle = classeActuelle->next;
    }
    return FALSE;
}
