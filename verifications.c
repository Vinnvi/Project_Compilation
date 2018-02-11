#include <string.h>
#include <stdio.h>
#include "tp.h"
#include "tp_y.h"

bool verifSurcharges(classeP c){
    classeP maClasse = c;
    if(maClasse == NIL(classe) ) return true;
    while(maClasse->next != NIL(classe) )
        if(!verifSurcharges2(maClasse)) return false; /* Vraie verification entre les 2 classes */
    }

    return true;
}

bool verifSurcharges2(classeP maClasse){
    

    /* On verifie que 2 methodes de la meme classe n'ont pas un meme nom */
    methodP methodes2 = methodes;
    while(methodes2->next != NIL(methode) ){ /*Tant que on peut comparer des methodes */
        methodes2 = methodes2->next;
        if(strcmp(methodes,methodes2) == 0) return false; /* Si on a 2 méthodes du meme nom */
    }
    /* ------------------------- */
    /* On verifie que les overrides fonctionnent */
    if(methodes->redef == true){ /*Si on a ecrit Override -> on verifie qu'on est bien lie a une fonction plus haut */
        classeP classeMere = maClasse->super;
        if(classeMere == NIL(classe)) return false;
        else{
            methodP methodesMere= classeMere->lmethodes;
            while(methodP != NIL(methode) ){
                methodesMere = methodesMere->next;
                if( strcmp(methodesMere->name,methodes->name) == 0){ /* On a trouve la methode de la classe mere */
                    /* On verifie que les parametres sont bien les bons */
                    VarDeclP paramsMethode = methodes->param;
                    VarDeclP paramsMethodeMere = methodesMere->param;
                    while(paramsMethode != NIL(VarDecl) || paramsMethodeMere != NIL(VarDecl) ){
                        if(! paramsMethode->type == paramsMethodeMere->type){
                            return false;
                        }
                        paramsMethode = paramsMethode->next;
                        paramsMethodeMere = paramsMethodeMere->next;
                    }
                    break;
                }
            }
            if(methodP == NIL(method)){ /* si c'est vide : c'est que l'on a parcouru toutes les methodes de la mere sans trouver notre methode mere, ou que l'on a pas de methodes dans la mere*/
                return false;
            }
        }
    }
    /* -------------------------- */
    return true;

}
