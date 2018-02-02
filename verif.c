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



/*Fonction de test d'un appel de méthode appartenant à une classe*/
int verifMethodeClasse(classeP classtemoin, methodP methtest)
{
	int test = 8;
	if(methtest != NIL(method))
	{
		classeP classtmp = NEW(1,classe);
		classtmp= classtemoin;
		methodP methtmp = NEW(1,method);
		methtmp = methtest;
		while(classtmp->next != NIL(classe))
		{
			while(classtmp->lmethodes != NIL(method))
			{
				if(strcmp(classtmp->lmethodes->name, methtmp->name) == 0)
				{
					test = verifParam(classtmp->lmethodes,methtmp->param);
					if(test !=1 && test != 8 && test != 42)
						return test;
					else
					{
						return verifRetour(classtmp->lmethodes, methtmp->typeRetour);
					}
				}
				classtmp->lmethodes = classtmp->lmethodes->next;
			}

			classtmp = classtmp->next;
		}
	}
	return test;
}

/*Fonction de test d'un appel de méthode appartenant à un objet*/
int verifMethodeObjet(objectP objettemoin, methodP methtest)
{
	int test = 8;
	if(methtest != NIL(method))
	{
		objectP objettmp = NEW(1,object);
		objettmp= objettemoin;
		methodP methtmp = NEW(1,method);
		methtmp = methtest;
		while(objettmp->next != NIL(object))
		{
			while(objettmp->lmethodes != NIL(method))
			{
				if(strcmp(objettmp->lmethodes->name, methtmp->name) == 0)
				{
					test = verifParam(objettmp->lmethodes,methtmp->param);
					if(test !=1 && test != 8 && test != 42)
						return test;
					else
					{
						return verifRetour(objettmp->lmethodes, methtmp->typeRetour);
					}
				}
				objettmp->lmethodes = objettmp->lmethodes->next;
			}

			objettmp = objettmp->next;
		}
	}
	return test;
}

/*Fonction de test des paramètres d'un appel de méthode*/
int verifParam(methodP meth, VarDeclP params)
{
	int test = 42;
	if(params != NIL(VarDecl) && meth->param != NIL(VarDecl))
    {

    	VarDeclP methParam = NEW(1,VarDecl);
    	methParam = meth->param;
    	VarDeclP param = NEW(1,VarDecl);
    	param = params;
    	while(methParam->next != NIL(VarDecl) && param->next != NIL(VarDecl))
    	{
    		if(methParam->type != NIL(classe) && param->type != NIL(classe))
    		{
    			if(strcmp(methParam->type->name, param->type->name) != 0)
    			{
    				if(verifSuper(methParam->type,param->type))
    				{
    					test = 1;
    				}
    				else return 2;
    			}
    		}
    		else if((methParam->type == NIL(classe) || param->type == NIL(classe)) && methParam->type != param->type)
    				{
    					return 5;
    				}
    				else test = 1;
    		if((methParam->next == NIL(VarDecl) || param->next == NIL(VarDecl)) && methParam->next != param->next)
    		{
    			return 3;
    		}
    		methParam = methParam->next;
    		param = param->next;
    	}
     	
    }
    else if((params == NIL(VarDecl) || meth->param == NIL(VarDecl)) && params != meth->param)
    		{
    			return 4;
    		}
   	return test;
}

/*Fonction de test de la généricité des paramètres d'un appel de méthode*/
bool verifSuper(classeP temoin, classeP ctest)
{
	classeP test = NEW(1,classe);
	test = ctest;
	while(test->super != NIL(classe))
    {
    	if(strcmp(temoin->name, test->super->name) == 0)
    	{
	    	return 1;
    	}

    	test = test->super;
    }
    return 0;
}

/*Fonction de test du type de retour d'un appel de méthode*/
bool verifRetour(methodP meth, classeP typeTest)
{
	if(typeTest != NIL(classe) && meth->typeRetour != NIL(classe))
    {
    	classeP methRetour = meth->typeRetour;
    	classeP test = typeTest;
    	
    	if(strcmp(methRetour->name, test->name) != 0)
    	{
    		if(verifSuper(methRetour,test))
    		{
    			return 1;
			}
			else return 0;
    	}
    	methRetour = methRetour->next;
    	test = test->next;
    }
    if((typeTest == NIL(classe) || meth->typeRetour == NIL(classe)) && meth->typeRetour != typeTest)
    {
    	return 0;
    }
    return 1;
}