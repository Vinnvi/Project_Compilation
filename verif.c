#include <string.h>
#include <stdio.h>
#include "tp.h"
#include "tp_y.h"

extern char *strdup(const char*);

extern void setError(int code);

/*bool verifSurcharges(classeP c){
    classeP maClasse = c;
    if(maClasse == NIL(classe) ) return true;
    classeP maClasse2 = maClasse;
    do{
        if(!verifSurcharges2(maClasse,maClasse2)) return false;  Vraie verification entre les 2 classes 
    }while(maClasse2->next != NIL(classe) );  

    return true;
}

bool verifSurcharges2(classeP maClasse,classeP maClasse2){
    
     Si c'est la meme classe 
    if(maClasse == maClasse2){
        methodP methodes = maClasse->lmethodes;
        while(methodes == NIL(methode) ){        
            methodP methodes2 = methodes;
            while(methodes2->next != NIL(methode) ){ Tant que on peut comparer des methodes 
                methodes2 = methodes2->next;
                if(strcmp(methodes,methodes2) == 0) return false;
            }
            methodes = methodes->next;   
        }
    }

    return true;
}*/


bool verifParam(methodP meth, VarDeclP params)
{
	if(params != NIL(VarDecl) && meth->param != NIL(VarDecl))
    {
    	VarDeclP methParam = meth->param;
    	VarDeclP param = params;
    	while(methParam->next != NIL(VarDecl) && param->next != NIL(VarDecl))
    	{
    		if(strcmp(methParam->nomType, param->nomType))
    		{
    			return 0;
    		}
    		methParam = methParam->next;
    		param = param->next;
    	}
    	if((methParam->next != NIL(VarDecl) || param->next != NIL(VarDecl)) && methParam->next != param->next)
    	{
    		return 0;
    	}
    }
    return 1;
}

bool verifRetour(methodP meth, char* type)
{
	if(strcmp(meth->nomTypeRetour,type))
		return 1;
	else
		return 0;
}