#include <string.h>
#include <stdio.h>
#include "tp.h"
#include "tp_y.h"

extern char *strdup(const char*);

extern void setError(int code);

/*Fonction de test des paramètres d'un appel de méthode*/
int verifParam(methodP meth, VarDeclP params)
{
	if(meth != NIL(method))
	{
		if((params != NIL(VarDecl) && meth->param == NIL(VarDecl)) || (params == NIL(VarDecl) && meth->param != NIL(VarDecl)))
    	{
    		return 4;
    	}
	
	int test = 42;
	/*if(verifTailleListe(meth->param) != verifTailleListe(params))
    	{
    		return 3;
    	}*/
	if(params != NIL(VarDecl) && meth->param != NIL(VarDecl))
    {
    	VarDeclP methParam = NEW(1,VarDecl);
    	methParam = meth->param;
    	VarDeclP param = NEW(1,VarDecl);
    	param = params;
    	
    	while(methParam != NIL(VarDecl) && param != NIL(VarDecl))
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
    		if((methParam->type == NIL(classe) && param->type != NIL(classe)) || (methParam->type != NIL(classe) && param->type == NIL(classe)))
    	    {
    			return 5;
    		}
    		test = 1;
    		
    		methParam = methParam->next;
    		param = param->next;
    		
    	}
    }
   	return test;
   }
   else return 12;
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

/*Fonction de test de la taille de la liste de paramètres d'une méthode*/
int verifTailleListe(VarDeclP liste)
{
	int taille = 0;
	VarDeclP listtmp = NEW(1,VarDecl);
	listtmp = liste;
	while(listtmp != NIL(VarDecl))
	{
		taille++;
		listtmp = listtmp->next;
	}
	return taille;
}