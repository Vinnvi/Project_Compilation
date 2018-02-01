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
                while(methodesMere != NIL(method) || ok == 1 ){
                
                    if( strcmp(methodesMere->name,methodes->name) == 0){ /* On a trouve la methode de la classe mere */
                        
                        /* On verifie que les parametres sont bien les bons */
                        VarDeclP paramsMethode = methodes->param;
                        VarDeclP paramsMethodeMere = methodesMere->param;
                        
                        while( paramsMethode != NIL(VarDecl) || paramsMethodeMere != NIL(VarDecl)) {

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
