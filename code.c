#include <string.h>
#include <stdio.h>
#include "tp.h"
#include "tp_y.h"
#include "code.h"

extern char* strdup(const char *);

/*
Stack stack = {0, NULL};*/
FILE* out;
int i;

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

void lancerGeneration(TreeP programme, FILE* chOut) {
    out = chOut;
    fprintf(out, "START\n");
    if(getChild(programme,0) != NIL(Tree)) { generDefClassObjOpt(getChild(programme,0)); } 
    generBlocOpt(getChild(programme,1)); 
}
void generDefClassObjOpt(TreeP defClassObj){
    if(defClassObj == NIL(Tree)) return;
}
void generDefClassObj(TreeP defClassObj){
/* TODO */
        printf("aie");
}
void generObjetOuClasse(TreeP objetOuClasse)
{
    TreeP treeObjClass = getChild(objetOuClasse,0);
    if(getChild(treeObjClass,1) == NIL(Tree)) return;
    else generListInst(getChild(treeObjClass,0));
}
void generClass(classeP class)
{
    if(class == NULL) return;
    generClassId(class->name);
    generListParam(class->parametres);
    /* TODO generExtendsOpt(class->super); */
    generBlocOpt(class->constructeur);
    /* TODO generCorpsClass(class->body); */
    /* TODO Il faut revoir extends et corps */
}
void generListParamOpt(VarDeclP listParamOpt)
{
    if(listParamOpt == NIL(VarDecl)) return;
    generListParam(listParamOpt);
}
void generListParam(VarDeclP listParam)
{
    
}
void generCorpsClass(TreeP corpsClasse)
{
    generListChpOpt(getChild(corpsClasse,0));
    generListMethOpt(getChild(corpsClasse,1));
}
void generBlocOpt(TreeP blocOpt)
{
    if(blocOpt == NIL(Tree)) return;            /* Cas Bloc vide */
    generBloc(blocOpt);
}
void generBloc(TreeP bloc)
{
    if(getChild(bloc,1) == NIL(Tree))           /* Bloc est une liste d'Instructions */
        generListInstOpt(getChild(bloc,0));    
    else{                                       /* Bloc est une liste de champs IS Liste Instructions */
        generListChp((VarDeclP)getChild(bloc,0));
        generListInst(getChild(bloc,1));
    }
}
void generBlocNonVide(TreeP bloc)
{
    if(getChild(bloc,1) == NIL(Tree))           /* Bloc est une liste d'Instructions */
        generListInst(getChild(bloc,0));    
    else{                                       /* Bloc est une liste de champs IS Liste Instructions */
        generListChp((VarDeclP)getChild(bloc,0));
        generListInst(getChild(bloc,1));
    }
}
void generListInstOpt(TreeP listInstOpt)
{
    if(listInstOpt == NIL(Tree)) return;        /* Cas Liste vide */
}
void generListInst(TreeP listInst)
{
    generInst(getChild(listInst,0));            /* Cas Inst */
    if(listInst->op == LINST)                   /* Cas Liste Inst */
        generListInst(getChild(listInst,1));
}
void generInst(TreeP inst)
{
    if( inst == NIL(Tree) ) /* Cas Instruction vide */
    {
        printf("Instruction null"); return;
    }
    switch(inst->op){
        case ERETURN : 
            return; /* TODO */
        case EAFF : 
            generArgOuCible(getChild(inst,0));
        case ITE : 
            generOperation(getChild(inst,0));
            generIfElse(getChild(inst,1)); 
            generIfElse(getChild(inst,2));
        default : generExpression(getChild(inst,0));
    }
}
void generArgOuCible(TreeP argOuCible)
{
    if(argOuCible->op == CSTE)                  /* Cas Cste */
        ; /*TODO*/
    else{
        TreeP treeArg = getChild(argOuCible,0);
        /* TODO */
        
    }
}
void generOperation(TreeP operation)
{
    switch(operation->op){
        case EADD : 
            generOperation(getChild(operation,0));
            /* TODO */
            generOperation(getChild(operation,1));
            /* TODO si add tout seul? */
        case ESUB : 
            generOperation(getChild(operation,0));
            /* TODO */
            generOperation(getChild(operation,1));
            /* TODO si sub tout seul? */
        case EMUL : 
            generOperation(getChild(operation,0));
            /* TODO */
            generOperation(getChild(operation,1));
        case EQUOT : 
            generOperation(getChild(operation,0));
            /* TODO */
            generOperation(getChild(operation,1));
        case EREST : 
            generOperation(getChild(operation,0));
            /* TODO */
            generOperation(getChild(operation,1));
        case EAND : 
            generOperation(getChild(operation,0));
            /* TODO */
            generOperation(getChild(operation,1));
        default :
            generValeur(getChild(operation,0));
    }
}
void generValeur(TreeP valeur)
{
    generArgOuCible(getChild(valeur,0));
}
void generIfElse(TreeP ifElse)
{
    TreeP treeIfElse = getChild(ifElse,0);
    if(treeIfElse->op == EBLOC) generBloc(treeIfElse);
    else generInst(treeIfElse);
}
void generExpression(TreeP expr)
{
}
void generListChpOpt(VarDeclP listChpOpt)
{
    if(listChpOpt == NIL(VarDecl)) return;
    generListChp(listChpOpt);
}
void generListChp(VarDeclP listChp)
{
}
void generListMethOpt(methodP listMethOpt)
{
    if(listMethOpt == NIL(method)) return;
    generListMeth(listMethOpt);
}
void generListMeth(methodP listMeth)
{
    
    /* TODO comment savoir nb methodes */
}
void generMeth(methodP meth)
{
    /* TODO comment savoir which one */
}

void generClassId(char* classId)
{
    /* TODO */
}
void generOverride(bool override)
{
    /* TODO */
}
void generExtendsOpt(TreeP extends)
{
    if(extends == NIL(Tree)) return;
    else generExtends(extends);
}
void generExtends(TreeP extends)
{
    /* TODO */
}
void generObject(objectP obj)
{
    if(obj == NULL) return;
    generClassId(obj->name);
    generListChpOpt(obj->attributs);
    generListMethOpt(obj->lmethodes);
}
void generListArgOpt(TreeP listArgOpt)
{
    if(listArgOpt == NIL(Tree)) return;
    generListArg(listArgOpt);
}
void generListArg(TreeP listArg)
{
    /* TODO Commment trouver? 
    generExpr(getChild(listArg,0))
    if...
        generListArg(getChild(listArg,1))*/
}
void generInstanciation(TreeP instanciation)
{
    generClassId(getChild(instanciation,0)->u.str);
    generListArgOpt(getChild(instanciation,1));
}


