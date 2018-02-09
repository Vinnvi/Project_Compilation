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
void STOREG_addr(char* c) {
	int a = getAddr(c);
	if (a < 0) { fprintf(out, "STOREG addr(%s)(%d)\n", c, a); stack.size--; }
  else STOREG(a); }
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

/* Actualise la structure de classe/objet en indiquant nombre de champs */
void setNbChpClass(char* name, int chNbChp){
    classeP chClasse = getPointeurClasse(name);
    if(chClasse != NIL(classe)) chClasse->nbChp = chNbChp;
    else{ /* On est sur un objet */
        objectP chObjet = idToObj(name);
        chObjet->nbChp = chNbChp;
    }
}

/* On libere la pile */
void freeStack() {
    LevelP level = stack.top_level;
    while (level) {
        VariableP var = level->varLevel;
        while (var) {
            VariableP temp = var;   /* On copie la variable pour la liberer */
            var = var->next;        /* On doit liberer les suivantes */
            free(temp);             /* On peut liberer cette variable */
        }
        LevelP temp = level;        /* Pareil avec les niveaux */
        level = level->next;
        free(temp);
    }
}
/* On rentre dans un nouveau niveau de portee */
void entreeLevel(LevelP levelP) {
    levelP->next = stack.top_level;    /* On lie au niveau precedent */
    stack.top_level = levelP;          /* Ce niveau est desormais au dessus */
    levelP->offset = stack.size - 1;    /* TODO */
}
/* On sort d'un niveau de portee */
void sortieLevel() {
    if (stack.top_level == NULL) return;   /* Pas de niveau, rien a faire */
    LevelP levelP = stack.top_level->next; /* Niveau precedent devient le plus haut */
    stack.top_level = levelP;              /* On actualise sur la pile */
}
/* On rajoute une variable a notre liste definit */
void addVariable(VarDeclP chVar) {
    VariableP oldVar = stack.top_level->varLevel;
    VariableP variable = NEW(1, Variable);
    variable->var = chVar;                            /* Pointeur vers la variable */
    variable->addr = stack.size;                    /* Adresse dans la pile */
    variable->next = oldVar;
    stack.top_level->varLevel = variable;
}
VariableP getVariable(char* name) {
    LevelP levelP = stack.top_level;
    while(levelP) {
        VariableP chVar = levelP->varLevel;
        if(chVar != NULL){
            while (chVar) {
                if (!strcmp(name,chVar->var->name)) {
                    return chVar;
                }
                chVar = chVar->next;
            }
        }
        levelP = levelP->next;
    }
    return NULL;
}

int getNbChpClass(char* chClass)
{
    if(!strcmp(chClass,"String") || !strcmp(chClass,"Integer")) return 1;
    else return getPointeurClasse(chClass)->nbChp;
}
int getAddr(char* name) {
    LevelP level = stack.top_level; /* On se positionne sur dernier niveau de portee */
    while(level) {                  /* On parcourt nos niveaux pour chercher variable */
        VariableP chVar = level->varLevel;
        if(chVar != NULL){
            while (chVar) {
                if (!strcmp(name,chVar->var->name))
                    return chVar->addr;    /* Variable présente */
                chVar = chVar->next;
            }
        }
        level = level->next;
    }
    fprintf(out, "La variable %s n existe pas\n", name);
    return -1;
}
/*
int getOffset(ClassP class, char* field_name) {
    if (class == NULL) return -1;
    ClassP super = NULL;
    if (class->extendsClass) super = figureClass(getChild(class->extendsClass, 0)->u.str);
    VariableP fields = class->fields;
    int total = 0;
    int it = 0;
    if (super) {
        VariableP super_fields = super->fields;
        while (super_fields) {
            if (!strcmp(field_name,super_fields->name)) it = total;
            super_fields = super_fields->next;
            total++;
        }
    }
    if (!it) while (fields) {
        if (!strcmp(field_name,fields->name)) it = total;
        fields = fields->next;
        total++;
    }
    return it;
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
    entreeLevel(NEW(1,Level));
    fprintf(out, "/////////////// DEBUT Objet\n");
    generListChpOpt(obj->attributs, obj->name);
    generListMethOpt(obj->lmethodes,obj->name);
    fprintf(out, "/////////////// FIN Objet\n");
    sortieLevel(NEW(1,Level));
}

void generBlocOpt(TreeP blocOpt)
{
    if(blocOpt == NIL(Tree)) return;            /* Cas Bloc vide */
    generBloc(blocOpt);
}
void generBloc(TreeP bloc)
{
    entreeLevel(NEW(1,Level));
    if(getChild(bloc,1) == NIL(Tree))           /* Bloc est une liste d'Instructions */
        generListInstOpt(getChild(bloc,0));
    else{
        generListChpBloc((VarDeclP)getChild(bloc,0));
        generListInst(getChild(bloc,1));
    }
    sortieLevel();
}
void generListInstOpt(TreeP listInstOpt)
{
    if(listInstOpt == NIL(Tree)) return;        /* Cas Liste vide */
    generListInst(listInstOpt);
}
void generListInst(TreeP listInst)
{
    if(listInst->op == LINST)
    {
        generInst(getChild(listInst,0));                 /* Cas Liste Inst */
        generListInst(getChild(listInst,1));
    }
    else generInst(listInst);
}
void generInst(TreeP inst)
{
    switch(inst->op){
        case ERETURN :
            fprintf(out, "RETURN\n");
            break;
        case EAFF :
            ALLOC(1);   /* TODO nb */
            DUPN(1);    /* TODO nb */
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
            generOperation(getChild(operation,1));
            O_ADD();
            break;
        case EADDSOLO :
            generOperation(getChild(operation,0));
            O_ADD();
            break;
        case ESUB :
            generOperation(getChild(operation,0));
            generOperation(getChild(operation,1));
            O_SUB();
            break;
        case ESUBSOLO :
            generOperation(getChild(operation,0));
            O_SUB();
            break;
        case EMUL :
            generOperation(getChild(operation,0));
            generOperation(getChild(operation,1));
            O_MUL();
            break;
        case EQUOT :
            generOperation(getChild(operation,0));
            generOperation(getChild(operation,1));
            O_DIV();
            break;
        case EREST :
            generOperation(getChild(operation,0));
            generOperation(getChild(operation,1));
            O_REST();
            break;
        case EAND :
            generOperation(getChild(operation,0));
            generOperation(getChild(operation,1));
            O_CONCAT();
            break;
        case (NE || EQ || LT || LE || GT || GE) :
            generOperation(getChild(operation,0));
            generOperation(getChild(operation,1));
            break;
        default :
            generArgOuCible(operation);
            break;
    }
}
void generInstanciation(TreeP instanciation)
{
    char* nomClass = getChild(instanciation,0)->u.str;
    fprintf(out, "-- Nouvelle Instanciation de type  : %s\n",nomClass);
    int nb = getNbChpClass(nomClass);
    ALLOC(nb); /* TODO nb */
    generListArgOptInst(getChild(instanciation,1),0);
}
void generClass(classeP class)
{
    entreeLevel(NEW(1,Level));
    fprintf(out, "\n---------------------------- DEBUT Classe\n");
    if(class == NIL(classe)) return;
    /* On ne genere que le code des methodes a la definition de la classe */
    if(class->parametres != NIL(VarDecl)) fprintf(out, "---- Parametres de la Classe\n");
    /* generListParamOpt(class->parametres); */
    if(class->constructeur != NIL(Tree)) fprintf(out, "---- Constructeur de la Classe\n");
    generCorpsClass(class->body, class->name);
    /* TODO Il faut revoir extends et corps */
    fprintf(out, "---------------------------- Fin Classe\n\n");
    sortieLevel(NEW(1,Level));
}
void generCorpsClass(TreeP corpsClasse, char* name)
{
    fprintf(out, "---------- DEBUT CorpsCLasse\n");
    if(corpsClasse->op == ECORPS){
        generListChpOpt((VarDeclP)getChild(corpsClasse,0),name);
        generListMethOpt((methodP)getChild(corpsClasse,1),name);
    }
    fprintf(out, "---------- Fin CorpsClasse\n");
}

void generListMethOpt(methodP listMethOpt, char* name)
{
    if(listMethOpt == NIL(method)) return;
    else {
        methodP methodes = NEW(1,method);
        classeP chClass = getPointeurClasse(name);
        if(chClass != NIL(classe)) methodes = chClass->lmethodes;
        else{
            objectP chObj = idToObj(name);
            methodes = chObj->lmethodes;
        }
        while(methodes != NIL(method)){
            generMeth(methodes);
            methodes = methodes->next;
        }
    }
}
void generListMeth(methodP listMeth)
{
    fprintf(out,"AVANT methode %s\n",listMeth->name);
    entreeLevel(NEW(1,Level));
    generMeth(listMeth);
    if(listMeth->next != NIL(method)) {
        generListMeth(listMeth->next);}
    sortieLevel();
}
void generMeth(methodP meth) /* TODO */
{
    fprintf(out,"-- Definition de la methode %s\n",meth->name);
    entreeLevel(NEW(1,Level));
    if (meth == NULL) return;
    NEWMETHLABEL(meth->name,meth->typeRetour->name);
    /* ##### GENERATION DU CODE DES PARAMETRES #####*/
    /* On compte le nombre de parametres methode car necessaire pour position PUSHL*/
    int nbParam = 0; int position = 0;
    VarDeclP paramMeth = meth->param;
    while(paramMeth)
    {
        paramMeth = paramMeth->next;
        nbParam++;
    }
    position -= nbParam;
    /* On empile le resultat de l appel de la fonction */
    VarDeclP resultat = NEW(1,VarDecl);
    resultat->name = "this";
    addVariable(resultat);
    /* On empile chacun des parametres dans la pile */
    paramMeth = meth->param;
    while(paramMeth){
        addVariable(paramMeth);
        PUSHL(position);
        position++;
        paramMeth = paramMeth->next;
    }
    /* ##### GENERATION DU CODE DU CORPS DE LA METHODE #####*/
    generExpr(meth->body);
    sortieLevel();

}
void generListParamOpt(VarDeclP listParamOpt)
{
    if( (listParamOpt != NULL)&&(listParamOpt != NIL(VarDecl)) ){
        if(listParamOpt->expr == NIL(Tree)) generListParam(listParamOpt);
        else generListParamDef(listParamOpt);
    }
}
void generListParam(VarDeclP listParam)
{
    generParam(listParam);
    if(listParam->next != NIL(VarDecl))
    {
        if(listParam->next->expr == NULL) generListParam(listParam->next);
        else generListParamDef(listParam->next);
    }
}
void generParam(VarDeclP param)
{
    /* printf("name : %s\n",param->name); */
}
void generListParamDef(VarDeclP listParamDef)
{
    if(listParamDef->aVar == TRUE){
        generExpr(listParamDef->expr);
        /* STOREG_addr(listParamDef->); */
    }
    else{
        generExpr(listParamDef->expr);
        /* STOREG_addr(listParamDef->u.str); */
    }
    generParamDef(listParamDef);
    if(listParamDef->next != NIL(VarDecl)) generListParamDef(listParamDef->next);
}
/* Parametre definit avec une valeur comme VAR idNum : Integer := 2+1 */
void generParamDef(VarDeclP paramDef)
{
    generExpr(paramDef->expr);
    if(strcmp(paramDef->nomType,"Integer") == 0){
        fprintf(out, "PARAMDEF INTEGER\n");
        /*STOREG(paramDef->expr.adresse ?);*/

    }
    else if (strcmp(paramDef->nomType,"String") == 0){
        fprintf(out, "PARAMDEF STRING\n");
        /*STOREG(paramDef->expr.adresse ?);*/
    }

}

void generDeclExprOpt(TreeP declExprOpt)
{
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
    /* generListChpOpt((VarDeclP)extends);*/
}

void generListArgOpt(TreeP listArgOpt)
{
    if(listArgOpt == NIL(Tree)) return;
    generListArg(listArgOpt);
}
void generListArgOptInst(TreeP listArgOpt, int pos)
{
    if(listArgOpt == NIL(Tree)) return;
    generListArgInst(listArgOpt, pos);
}
void generListArg(TreeP listArg)
{
    if(listArg->op == LARG)
    {
        generExpr(getChild(listArg,0));
        generListArg(getChild(listArg,1));
    }
    else generExpr(listArg);
}
void generListArgInst(TreeP listArg, int pos)
{
    DUPN(1);
    if(listArg->op == LARG)
    {
        fprintf(out, "-- Parametre Instanciation\n");
        generExpr(getChild(listArg,0));
        STORE(pos);
        generListArgInst(getChild(listArg,1),pos++);
    }
    else {
        fprintf(out, "-- Parametre Instanciation\n");
        generExpr(listArg);
        STORE(pos);
    }
}
void generArgOuCible(TreeP argOuCible)/* TODO */
{
    switch(argOuCible->op){
        case EDOT :
            generListSelection(getChild(argOuCible,0));
            break;
        case ETHISSELECT :
            generThisSelect(getChild(argOuCible,0));
            break;
        case CSTE :
            PUSHI(argOuCible->u.val);
            break;
        default : generSelection(argOuCible); break;
  }
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
    /* BUG qui fait segmentation */
    switch(selWithClassID->op){
        case LSEL :
            generListSelection(getChild(selWithClassID,0));
            break;
        case CLASS :
            break;
        case ESEL :
            generSelection(selWithClassID);
        default : break;
    }
}
void generSelection(TreeP selection)
{
    switch(selection->op){
        case EID :
            break; /* TODO */
        case CSTR :
            /*printf("REGARDE LA \n %s\n",selection->u.str);*/
            PUSHS(selection->u.str);
            break;
        case CAST :
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
    PUSHN(1);
    generListArgOpt(getChild(message,1));
    PUSHA(getChild(message,0)->u.str);
    CALL();
    POPN(2);    /*TODO TODO TODO Trouver nombre POPN ICI */
}
void generListChpOpt(VarDeclP listChpOpt, char* name)
{
    if(listChpOpt == NIL(VarDecl)) return;
    generListChp(listChpOpt, name, 1);
}
void generListChp(VarDeclP listChp, char* name, int pos)
{
  generChp(listChp);
  if(listChp->next != NULL) generListChp(listChp->next, name, pos+1);
  else {
      setNbChpClass(name, pos);
  }
}
void generListChpBloc(VarDeclP listChp)
{
  generChpBloc(listChp);
  if(listChp->next != NULL) generListChpBloc(listChp->next);
}
/* Declarations de variables dans une definition de classe ou d objet */
void generChp(VarDeclP chp)
{
    if (chp->aVar == TRUE){
        if( getVariable(chp->name) == NULL) addVariable(chp);
        fprintf(out, "---- Définition du champ %s \n",chp->name);
    }
    else {
        if( getVariable(chp->name) == NULL){
            printf("ERROR, variable %s non définie",chp->name);
            fprintf(out,"ERROR, variable %s non définie",chp->name);
        }
    }
}

/* Declarations de variables dans un bloc, il faut donc allouer ici*/
void generChpBloc(VarDeclP chp)
{
    if (chp->aVar == TRUE){ /* Nouvelle definition de variable */
        if( getVariable(chp->name) == NULL){ /* nom de la variable non utilise */
            addVariable(chp);
            fprintf(out, "---- Définition du champ %s \n",chp->name);
            /* On doit allouer la place necessaire selon le nombre de champs */
            ALLOC(getNbChpClass(chp->nomType));
            DUPN(1);
            generDeclExprOpt(chp->expr);
            STORE(0);
        }
        else { /* erreur nom de la variable deja existant */
            printf("ERROR, nom de la variable %s déja existant\n",chp->name);
            fprintf(out,"ERROR, nom de la variable %s déja existant\n",chp->name);
        }
    }
    else {
        if( getVariable(chp->name) == NULL){
            printf("ERROR, variable %s non définie\n",chp->name);
            fprintf(out,"ERROR, variable %s non définie\n",chp->name);
        }
        else{

        }
    }
}
