#include <string.h>
#include <stdio.h>
#include "tp.h"
#include "tp_y.h"
#include "code.h"

extern char* strdup(const char *);

Stack stack = {0, NULL};
FILE* out;
int i;
static int numLabel = 0;

/*##### On définit les instructions utilises par la machine generatrice de code ##### */
/*Instructions de Label */
void NOP() { fprintf(out, "NOP\n"); }
char* makeLabel(char* nameLabel) {
  static char buf[30];
  sprintf(buf, "%s%d", nameLabel, numLabel++);
  return strdup(buf);
}
void LABEL(char* c) { fprintf(out, "%s : \t", c); }
void NEWLABEL(char* c) { LABEL(c); NOP(); }
void NEWMETHLABEL(char* nomMeth, char* typeRetour) { fprintf(out, "%s_%s: ", typeRetour, nomMeth); NOP(); }
/* Instructions sur la pile */
void PUSHI(int i) { fprintf(out, "PUSHI %d\n", i); stack.size++; }
void PUSHS(char *c) { fprintf(out, "PUSHS %s\n", c); stack.size++; }
void PUSHG(int a) { fprintf(out, "PUSHG %d\n", a); stack.size++; }
void PUSHL(int a) { fprintf(out, "PUSHL %d\n", a); stack.size++; }/*
void PUSHG_addr(char* c) {
    int a = getAddr(c);
    if (a < 0) { fprintf(out, "PUSHG addr(%s)(%d)\n", c, a); stack.size++; }
    else PUSHG(a); }
void PUSHL_addr(char* c) {
	int a = getAddr(c);
	if (a < 0) { fprintf(out, "PUSHL addr(%s)(%d)\n", c, a); stack.size++; }
    else PUSHL(a); }*/
void WRITES() { fprintf(out, "WRITES\n"); stack.size --; }
void STOREL(int x) { fprintf(out, "STOREL %d\n", x); stack.size--; }
void STOREG(int x) { fprintf(out, "STOREG %d\n", x); stack.size--; }
/*
void STOREG_addr(char* c) {
	int a = getAddr(c);
	if (a < 0) { fprintf(out, "STOREG addr(%s)(%d)\n", c, a); stack.size--; }
  else STOREG(a); }*/
void STORE(int x) { fprintf(out, "STORE %d\n", x); stack.size -= 2; }
void PUSHN(int x) { fprintf(out, "PUSHN %d\n", x); stack.size += x; }
void POPN(int x) { fprintf(out, "POPN %d\n", x); stack.size -= x; }
void DUPN(int x) { fprintf(out, "DUPN %d\n", x); stack.size+= x; }
void SWAP() { fprintf(out, "SWAP\n"); }
void JUMP(char* label) { fprintf(out, "JUMP %s\n", label); }
void JZ(char* label) { fprintf(out, "JZ %s\n", label); }
void LOAD(int x) { fprintf(out, "LOAD %d\n", x); }
void ALLOC(int x) { fprintf(out, "ALLOC %d\n", x); stack.size++; }
void WRITEI() { fprintf(out, "WRITEI\n"); stack.size--; }
void PUSHA(char* a) { fprintf(out, "PUSHA %s\n", a); stack.size++; }
void CALL() { fprintf(out, "CALL\n"); }
/* Instructions d'Opérations */
void O_ADD() { fprintf(out, "ADD\n"); stack.size--; }
void O_MUL() { fprintf(out, "MUL\n"); stack.size--; }
void O_SUB() { fprintf(out, "SUB\n"); stack.size--;}
void O_DIV() { fprintf(out, "DIV\n"); stack.size--; }
void O_REST() { fprintf(out, "REST\n"); stack.size--;}
void O_EQUAL() { fprintf(out, "EQUAL\n"); stack.size--; }
void O_CONCAT() { fprintf(out, "CONCAT\n"); stack.size--; }
void O_NOT() { fprintf(out, "NOT\n"); }
void O_INFEQ() { fprintf(out, "INFEQ\n"); stack.size--; }
void O_SUPEQ() { fprintf(out, "SUPEQ\n"); stack.size--; }
void O_INF() { fprintf(out, "INF\n"); stack.size--; }
void O_SUP() { fprintf(out, "SUP\n"); stack.size--; }

/**
renvoie l'adresse de la variable si elle est pr�sente dans la table des symboles
*/
/*
int getAddr(char* name) {
    LevelP level = stack.top_level;
    while(level) {
        SymboleP sy = level->symboles;
        while (sy) {
            if (!strcmp(name,sy->name)) return sy->addr;
            sy = sy->next;
        }
        level = level->next;
    }
    fprintf(out, "couldn't find %s in :", name);
    return -1;
}*/

/*Lancement de la génération de code*/
void lancerGeneration(TreeP programme, FILE* chOut) {
    out = chOut;
    fprintf(out, "START\n");
    generDefClassObjOpt(programme);
}
void generDefClassObjOpt(TreeP defClassObjOpt){
    if(defClassObjOpt == NIL(Tree)) return;
    generDefClassObj(defClassObjOpt);
}
void generDefClassObj(TreeP defClassObj){
    generObjetOuClasse(getChild(defClassObj,0));
    if(defClassObj->op == LCLASS) generDefClassObj(getChild(defClassObj,1));
}
void generObjetOuClasse(TreeP objetOuClasse)
{
    if(objetOuClasse->op == EDEFOBJ) generObject(objetOuClasse->u.lobj);
    if(objetOuClasse->op == EDEFCLASS) generClass(objetOuClasse->u.lclass);
}
void generObject(objectP obj)
{
    generClassId(obj->name);
    generListChpOpt(obj->attributs);
    generListMethOpt(obj->lmethodes);
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
        generListChp((VarDeclP)getChild(bloc,0)); /* TODO Possible?*/
        generListInst(getChild(bloc,1));
    }
}
void generBlocNonVide(TreeP bloc)
{
    if(bloc->op == EBLOC){        /* Bloc est une liste d'Instructions */
        generListChp((VarDeclP)getChild(bloc,0));
        generListInst(getChild(bloc,1));
    }
    else{
        generListInst(getChild(bloc,0));
    }
}
void generListInstOpt(TreeP listInstOpt)
{
    if(listInstOpt == NIL(Tree)) return;        /* Cas Liste vide */
    generListInst(listInstOpt);
}
void generListInst(TreeP listInst)
{
    if(listInst->op == LINST) {
        generInst(getChild(listInst,0));                 /* Cas Liste Inst */
        generListInst(getChild(listInst,1));
    }
    else generInst(listInst);
}
void generInst(TreeP inst)
{
    printf("avant switch %hi \n",inst->op);
    switch(inst->op){
        case ERETURN :
            fprintf(out, "RETURN\n");
            break;
        case EAFF :
            generArgOuCible(getChild(inst,0));
            generExpr(getChild(inst,1));
            break;
        case ITE :
            ; /* Besoin de laisser un statement a cause des anciens usages */
            char* labelTHEN = makeLabel("THEN");
            char* labelELSE = makeLabel("ELSE");
            char* labelIFELSE = makeLabel("ENDIFELSE");
            generOperation(getChild(inst,0));
            JZ(labelELSE);
            NEWLABEL(labelTHEN);
            generIfElse(getChild(inst,1));
            JUMP(labelIFELSE);
            NEWLABEL(labelELSE);
            printf("second ");
            generIfElse(getChild(inst,2));
            NEWLABEL("SORTIE IF/ELSE");
            break;
        default : generExpr(inst); break;
    }
}
void generIfElse(TreeP ifElse)
{
    switch(ifElse->op){
        case EBLOC :
            generBloc(getChild(ifElse,0));
            break;
        default :
            generInst(ifElse);
            break;
    }
}
void generExpr(TreeP expr)
{
    if(expr->op == EINST) generInstanciation(getChild(expr,0));
    else generOperation(expr);
}
void generOperation(TreeP operation)
{
    switch(operation->op){
        case EADD :
            generOperation(getChild(operation,0));
            /* TODO */
            generOperation(getChild(operation,1));
            O_ADD();
            break;
            /* TODO si add tout seul? */
        case EADDSOLO : /* TODO */
            generOperation(getChild(operation,0));
            O_ADD();
            break;
        case ESUB :
            generOperation(getChild(operation,0));
            /* TODO */
            generOperation(getChild(operation,1));
            O_SUB();
            break;
            /* TODO si sub tout seul? */
        case ESUBSOLO :
            generOperation(getChild(operation,0));
            O_SUB();
            break;
        case EMUL :
            generOperation(getChild(operation,0));
            /* TODO */
            generOperation(getChild(operation,1));
            O_MUL();
            break;
        case EQUOT :
            generOperation(getChild(operation,0));
            /* TODO */
            generOperation(getChild(operation,1));
            O_DIV();
            break;
        case EREST :
            generOperation(getChild(operation,0));
            /* TODO */
            generOperation(getChild(operation,1));
            O_REST();
            break;
        case EAND :
            generOperation(getChild(operation,0));
            /* TODO */
            generOperation(getChild(operation,1));
            O_CONCAT();
            break;
        case (NE || EQ || LT || LE || GT || GE) :
            generOperation(getChild(operation,0));
            /* TODO */
            generOperation(getChild(operation,1));
            break;
        default :
            generArgOuCible(operation);
            break;
    }
}
void generInstanciation(TreeP instanciation)
{
    generClassId(getChild(instanciation,0)->u.str);
    generListArgOpt(getChild(instanciation,1));
}
void generClass(classeP class)
{
    if(class == NULL) return;
    generClassId(class->name);
    generListParamOpt(class->parametres);
    /* TODO generExtendsOpt(class->super); */
    generBlocOpt(class->constructeur);
    /* TODO generCorpsClass(class->body); */
    /* TODO Il faut revoir extends et corps */
}
void generCorpsClass(TreeP corpsClasse)
{
    generListChpOpt(corpsClasse->u.lvar);
    generListMethOpt(corpsClasse->u.lmeth);
}

void generListMethOpt(methodP listMethOpt)
{
    if(listMethOpt == NIL(method)) return;
    generListMeth(listMethOpt);
}
void generListMeth(methodP listMeth)
{
    printf("listMeth\n");
    /* TODO comment savoir nb methodes */
}
void generMeth(methodP meth)
{
    /* TODO comment savoir which one */
}
void generListParamOpt(VarDeclP listParamOpt)
{
    if(listParamOpt == NIL(VarDecl)) return;
    if(listParamOpt->expr == NULL) generListParam(listParamOpt);
    else generListParamDef(listParamOpt);
}
void generListParam(VarDeclP listParam)
{
    generParam(listParam);
    /*
    if(listParam->next != NIL(VarDecl))
    {
        if(listParam->next->expr == NULL) generListParam(listParam);
        else generListParamDef(listParam);
    }*/
}
void generParam(VarDeclP param)
{
  /* TODO var...*/
}
void generListParamDef(VarDeclP listParamDef)
{
    generParamDef(listParamDef);
    if(listParamDef->next != NIL(VarDecl)) generListParamDef(listParamDef->next);
}
void generParamDef(VarDeclP paramDef)
{
  /* TODO var...*/
}

void generDeclExprOpt(TreeP declExprOpt)
{
  /* TODO AFF*/
  if(declExprOpt == NIL(Tree)) return;
  generExpr(getChild(declExprOpt,0));
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
void generArgOuCible(TreeP argOuCible)/* TODO */
{
    /*
    switch(argOuCible->op){
        case EDOT :
            generListSelection(getChild(argOuCible,0));
        case ETHISSELECT :
            generThisSelect(getChild(argOuCible,0));
        case CSTE :
            PUSHI(argOuCible->u.val);
            return;
        default : generSelection(argOuCible);
  }*/
}
void generThisSelect(TreeP thisSelect)
{
    switch(thisSelect->op){
        case LISTDOT :
            /* generThis */
            generListSelection(getChild(thisSelect,1));
            break;
        case EDOT :
            /* generThis */
            generSelection(getChild(thisSelect,1));
            break;
        default : /* generThis */break;
    }
}
void generListSelection(TreeP listSelection)
{
    generSelWithClassID(getChild(listSelection,0));
    generSelection(getChild(listSelection,1));
}
void generSelWithClassID(TreeP selWithClassID)
{
    switch(selWithClassID->op){
        case LSEL :
            generListSelection(getChild(selWithClassID,0));
        case CLASS :
            /* generClassId(getChild(selection,0)); */
        default : generMessage(selWithClassID);
    }
}
void generSelection(TreeP selection)
{
    switch(selection->op){
        case EID :
            break; /* TODO */
        case CSTR :
            break; /* TODO */
        case CAST :
             /* generClassId(getChild(selection,0)); */
             generExpr(getChild(selection,1));
             break;
        case EEXPR :
            generExpr(getChild(selection,0));
            break;
      default : generMessage(selection); break;
    }
}
void generMessage(TreeP message)
{
    /* TODO Id */
    generListArgOpt(getChild(message,1));
}
void generListChpOpt(VarDeclP listChpOpt)
{
    if(listChpOpt == NIL(VarDecl)) return;
    generListChp(listChpOpt);
}
void generListChp(VarDeclP listChp)
{
  generChp(listChp);
  if(listChp->next != NULL) generListChp(listChp->next);
}
void generChp(VarDeclP chp)
{
  /* TODO PUSH new chp */
  /*TODO chp->name */
  /* generClassId(chp->type); */ /* TODO pas sur */
  generDeclExprOpt(chp->expr);
}
void generClassId(char* classId)
{
    /* TODO */
}
void generOverride(bool override)
{
    /* TODO */
}
