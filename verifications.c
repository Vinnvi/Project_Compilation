#include <string.h>
#include <stdio.h>
#include "tp.h"
#include "tp_y.h"

bool verifSurcharges(classeP c){
    classeP maClasse = c;
    if(maClasse == NIL(classe) ) return true;
    classeP maClasse2 = maClasse;
    do{
        if(!verifSurcharges2(maClasse,maClasse2)) return false; /* Vraie verification entre les 2 classes */
    }while(maClasse2->next != NIL(classe) );  

    return true;
}

bool verifSurcharges2(classeP maClasse,classeP maClasse2){
    
    /* Si c'est la meme classe */
    if(maClasse == maClasse2){
        methodP methodes = maClasse->lmethodes;
        while(methodes == NIL(methode) ){
            methodP methodes2 = methodes;
            while(methodes2->next != NIL(methode) ){ /*Tant que on peut comparer des methodes */
                methodes2 = methodes2->next;
                if(strcmp(methodes,methodes2) == 0) return false;
            }
            methodes = methodes->next;   
        }
    }
    return true;
}

    

