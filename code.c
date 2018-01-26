#include <string.h>
#include <stdio.h>
#include "tp.h"
#include "tp_y.h"
#include "code.h"

extern char* strdup(const char *);

/*
Stack stack = {0, NULL};*/
FILE* out;

/*##### On définit les instructions utilises par la machine generatrice de code ##### */
/*Instructions de Label */
/*
void NOP() { fprintf(out, "NOP\n"); }
void LABEL(char* c) { fprintf(out, "%s : \t", c); }
void NEWLABEL(char* c) { LABEL(c); NOP(); }
void NEWMETHLABEL(char* nomMeth, char* typeRetour) { fprintf(out, "%s_%s: ", typeRetour, nomMeth); NOP(); }
*/
/* Instructions sur la pile */
/*
void PUSHI(int i) { fprintf(out, "PUSHI %d\n", i); stack.size++; }
void PUSHS(char *c) { fprintf(out, "PUSHS %s\n", c); stack.size++; }
void WRITES() { fprintf(out, "WRITES\n"); stack.size --; }
void PUSHG(int a) { fprintf(out, "PUSHG %d\n", a); stack.size++; }
void PUSHG_addr(char* c) { 
    int a = getAddr(c); 
    if (a < 0) { fprintf(out, "PUSHG addr(%s)(%d)\n", c, a); stack.size++; }
    else PUSHG(a); }
void PUSHL(int a) { fprintf(out, "PUSHL %d\n", a); stack.size++; }
void PUSHL_addr(char* c) {
	int a = getAddr(c);
	if (a < 0) { fprintf(out, "PUSHL addr(%s)(%d)\n", c, a); stack.size++; }
    else PUSHL(a); }
void STOREL(int x) { fprintf(out, "STOREL %d\n", x); stack.size--; }
void STOREG(int x) { fprintf(out, "STOREG %d\n", x); stack.size--; }
*/
/*Lancement de la génération de code*/

void lancerGeneration(TreeP tree, FILE* out) {
    fprintf(out, "START\n");
}

void generBloc(TreeP bloc)
{
    if(bloc == NIL(Tree))
    {
        printf("bloc null"); return;
    }
    if(getChild(bloc,0) != NIL(Tree))
    {
        generCodeListInst(getChild(bloc,0));
    }
    if(getChild(bloc,1) != NIL(Tree))
    {
        generCodeListChpCode(getChild(bloc,1));
    }
}
void generCodeListInst(TreeP t)
{

}
void generCodeListChpCode(TreeP t)
{
}
void generObject(objectP obj)
{
    if(obj == NULL)
    {
        
    }
}
void generClass(classeP class)
{
    if(class == NULL)
    {
    }
}

