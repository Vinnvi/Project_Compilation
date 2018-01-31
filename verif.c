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


pileVar pileVariables; /* pile des variables pour la vérification contextuelles*/

void initPile(){
    pileVariables.sommet = NIL(elmtVar);
    pileVariables.taille = 0;
}

void empiler(VarDeclP decl){
    elmtVarP elem = NEW(1, elmtVar);
    elem->var = decl;
    elem->next = pileVariables.sommet;
    pileVariables.sommet = elem;
    pileVariables.taille += 1; 
}

void depiler(){
    pileVariables.sommet = pileVariables.sommet.next;
}
