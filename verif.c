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
    environnement.sommet = environnement.sommet->next;
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
        	analysePortee(getChild(corps, 0), env);
        	analysePortee(getChild(corps, 1), env);
        	break;

        case EAFF :
        	analysePortee(getChild(corps, 0), env);
        	/*TODO ajout de variable dans environnement*/ 
        	break;

        case EDOTHIS : 
        	analysePortee(getChild(corps, 1), env);
        	break;

        case EDOT :
        case LARG :
        case LINST : 
        	analysePortee(getChild(corps, 0), env);
        	analysePortee(getChild(corps, 1), env);
        	break;


        case CAST :
        case MSG :
        case ENEW :
        case EEXTND : 
        	verifId(getChildStr(corps, 0), env);
        	analysePortee(getChild(corps, 1), env); 
        	break;

        case ETHIS :
        case ERETURN :
        case CSTE :
        case CSTR : 
        	break;

        case EID :
        	verifId(getChildStr(corps, 0), env);
        	break;

        /*case ECLASS : 
        	break; unused */

        case ITE :
        	analysePortee(getChild(corps, 0), env);
        	analysePortee(getChild(corps, 1), env);
        	analysePortee(getChild(corps, 2), env);
        	break;

        
        /*case LCHAMP : break;
        case LPARAM : break; unused 
        case LMETH : break;*/

        case LCLASS : break; /* < l'utilisation de l'étiquette permet pas de faire ce qu'on veut : go modifier légèrement les étiquettes pour différencier Liste -> elmt Liste et Liste -> elmt sinon on s'en sort pas */

        case EBLOC : /* < this shit */
            break;

        case OVER : break;

        /*case CHMP : break;
        case EEXPR : break;
        case ESEL : break;
        case EARG : break;
        case EVAR : break;
        case EPAR : break;
        case EMETHOD : break;
        case EOBJ : break;
        case EPROG : break;
        case LSEL : break;
        case EIDCLASS : break;
        default : break; 1 usé*/
	}
}

/* return un truc qui peut faire peter la fonction analyse */
void verifId(char* id, pileVar env){
	/* TODO */
}