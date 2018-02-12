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
void PUSHL(int a) { fprintf(out, "PUSHL %d\n", a); stack.size++; }
void PUSHG_addr(char* c) {
    int a = getAddr(c);
    if (a < 0) { fprintf(out, "PUSHG addr(%s)(%d)\n", c, a); stack.size++; }
    else PUSHG(a); }
void WRITES() { fprintf(out, "WRITES\n"); stack.size --; }
void STOREL(int x) { fprintf(out, "STOREL %d\n", x); stack.size--; }
void STOREG(int x) { fprintf(out, "STOREG %d\n", x); stack.size--; }
void STOREG_addr(char* c) {
	int a = getAddr(c);
	if (a < 0) { fprintf(out, "STOREG addr(%s)(%d)\n", c, a); stack.size--; }
  else STOREG(a); }
void STORE(int x) { fprintf(out, "STORE %d\n", x); stack.size -= 2; }
void POPN(int x) { fprintf(out, "POPN %d\n", x); stack.size -= x; }
void DUPN(int x) { fprintf(out, "DUPN %d\n", x); stack.size+= x; }
void JUMP(char* label) { fprintf(out, "JUMP %s\n", label); }
void JZ(char* label) { fprintf(out, "JZ %s\n", label); }
void LOAD(int x) { fprintf(out, "LOAD %d\n", x); }
void ALLOC(int x) { fprintf(out, "ALLOC %d\n", x); stack.size++; }
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

/* Retourne le nombre de champs d une classe ou d un objet */
int getNbChpClass(char* chClass)
{
    if(!strcmp(chClass,"String") || !strcmp(chClass,"Integer")) return 1;
    else {
        if(getPointeurClasse(chClass) != NULL) return getPointeurClasse(chClass)->nbChp;
        else return idToObj(chClass)->nbChp;
    }
}
/* Retourne l adresse ou la variable est stockee si elle existe, utile pour les instrucitons de piles par adresse */
int getAddr(char* name) {
    if(!strcmp(name,"result")) {
        fprintf(out, "Variable result, quelle adresse renvoyer?\n");
        return -1;
    }
    else{
        /* Comment gerer les adresses des variables ? */
        return 0;
    }
}

/* ############# FONCTION DE GENERATION ############# */

/*Lancement de la génération de code cf tp.c */
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
    fprintf(out, "---------------------------- DEBUT Objet\n");
    generListChpOpt(obj->attributs, obj->name);
    generListMethOpt(obj->lmethodes,obj->name);
    fprintf(out, "---------------------------- FIN Objet\n");
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
    else{
        generListChpBloc((VarDeclP)getChild(bloc,0));
        generListInst(getChild(bloc,1));
    }
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
/* Generation de code pour une Instruciton */
void generInst(TreeP inst)
{
    switch(inst->op){
        case ERETURN :                                      /* Return */
            fprintf(out, "RETURN\n");
            break;
        case EAFF :                                         /* ArgumentOuCible AFF Expression; */
            fprintf(out,"-- Instruction avec affectation\n");
            TreeP partieGauche = getChild(inst,0);
            TreeP partieDroite = getChild(inst,1);
            if(partieGauche->op == EID) { /* Juste un id a gauche */
                if(partieDroite->op == EINST) { /*Instanciation */
                    generExpr(getChild(inst,1));        /* on genere code du NEW Class */
                    STOREG_addr(partieGauche->u.str);   /* On store a l adresse de l id */
                }
                else { /* Une operation */
                    PUSHG_addr(partieGauche->u.str);
                    generExpr(getChild(inst,1));
                    STORE(0);
                }
            }
            else { /* Autre chose que juste un Id */
                if( (partieGauche->op == CSTE) || (partieGauche->op == CSTR) ){
                    printf("Pourquoi mettre une constante int ou String a gauche?");
                    fprintf(out,"Pourquoi mettre une constante int ou String a gauche?");
                }
                else if (partieGauche->op == EDOT) { /* Liste de Selection */
                    generListSelection(getChild(partieGauche,0));
                    generExpr(getChild(inst,1));
                    STORE(0);
                }
            }
            break;
        case ITE :                         /* IF Operation THEN InstIfElse ELSE InstIfElse */
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
/* Bloc dans un If et Else */
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
/* Expression */
void generExpr(TreeP expr)
{
    if(expr->op == EINST) generInstanciation(getChild(expr,0));
    else generOperation(expr);
}
/* Operations unaires et binaires */
void generOperation(TreeP operation)
{
    switch(operation->op){
        case EADD :         /* x + y */
            generOperation(getChild(operation,0));
            generOperation(getChild(operation,1));
            O_ADD();
            break;
        case EADDSOLO :     /* + x */
            generOperation(getChild(operation,0));
            O_ADD();
            break;
        case ESUB :         /* x - y */
            generOperation(getChild(operation,0));
            generOperation(getChild(operation,1));
            O_SUB();
            break;
        case ESUBSOLO :         /* - x */
            generOperation(getChild(operation,0));
            O_SUB();
            break;
        case EMUL :             /* x * y */
            generOperation(getChild(operation,0));
            generOperation(getChild(operation,1));
            O_MUL();
            break;
        case EQUOT :            /* x / y */
            generOperation(getChild(operation,0));
            generOperation(getChild(operation,1));
            O_DIV();
            break;
        case EREST :            /* x % y */
            generOperation(getChild(operation,0));
            generOperation(getChild(operation,1));
            O_REST();
            break;
        case EAND :             /* x && y */
            generOperation(getChild(operation,0));
            generOperation(getChild(operation,1));
            O_CONCAT();
            break;
        case NE :               /* x != y */
            generOperation(getChild(operation,0));
            generOperation(getChild(operation,1));
        break;
        case EQ :               /* x == y */
            generOperation(getChild(operation,0));
            generOperation(getChild(operation,1));
            O_EQUAL();
        break;
        case LT :               /* x < y */
            generOperation(getChild(operation,0));
            generOperation(getChild(operation,1));
            O_INF();
        break;
        case LE :               /* x <= y */
            generOperation(getChild(operation,0));
            generOperation(getChild(operation,1));
            O_INFEQ();
        break;
        case GT :               /* x > y */
            generOperation(getChild(operation,0));
            generOperation(getChild(operation,1));
            O_SUP();
        break;
        case GE :               /* x >= y */
            generOperation(getChild(operation,0));
            generOperation(getChild(operation,1));
            O_SUPEQ();
        break;
        default :
            generArgOuCible(operation);
            break;
    }
}
/* Instanciation NEW Class... */
void generInstanciation(TreeP instanciation)
{
    char* nomClass = getChild(instanciation,0)->u.str;
    fprintf(out, "-- Nouvelle Instanciation de type  : %s\n",nomClass);
    int nb = getNbChpClass(nomClass);
    ALLOC(nb);
    generListArgOptInst(getChild(instanciation,1),0);
}
void generClass(classeP class)
{
    fprintf(out, "\n---------------------------- DEBUT Classe\n");
    if(class == NIL(classe)) return;
    /* On ne genere que le code des methodes a la definition de la classe */
    if(class->parametres != NIL(VarDecl)) fprintf(out, "---- Parametres de la Classe\n");
    if(class->constructeur != NIL(Tree)) fprintf(out, "---- Constructeur de la Classe\n");
    generCorpsClass(class->body, class->name);
    fprintf(out, "---------------------------- Fin Classe\n\n");
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
void generMeth(methodP meth)
{

    fprintf(out,"---- Definition de la methode %s\n",meth->name);
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
    /* On empile chacun des parametres dans la pile */
    paramMeth = meth->param;
    while(paramMeth){
        PUSHL(position);
        position++;
        paramMeth = paramMeth->next;
    }
    /* ##### GENERATION DU CODE DU CORPS DE LA METHODE #####*/
    if(meth->body->op == EBLOC) generBloc(meth->body);
    else generExpr(meth->body);
}
void generListParamDef(VarDeclP listParamDef)
{
    /* TODO differencier ? */
    if(listParamDef->aVar == TRUE){
        generExpr(listParamDef->expr);
    }
    else{
        generExpr(listParamDef->expr);
    }
    generParamDef(listParamDef);
    if(listParamDef->next != NIL(VarDecl)) generListParamDef(listParamDef->next);
}
/* Parametre definit avec une valeur comme VAR idNum : Integer := 2+1 */
void generParamDef(VarDeclP paramDef)
{
    /* quelque chose a faire ici ? */
    generExpr(paramDef->expr);
    if(strcmp(paramDef->nomType,"Integer") == 0){
        fprintf(out, "PARAMDEF INTEGER\n");
    }
    else if (strcmp(paramDef->nomType,"String") == 0){
        fprintf(out, "PARAMDEF STRING\n");
    }
}

void generDeclExprOpt(TreeP declExprOpt)
{
  if(declExprOpt == NIL(Tree)) return;
  generExpr(getChild(declExprOpt,0));
}
/* Liste optionelle des arguments d un appel d une methode */
void generListArgOpt(TreeP listArgOpt, char* nomMethod)
{
    if(listArgOpt == NIL(Tree)) return;
    generListArg(listArgOpt,nomMethod, 0);
}
/* Liste des arguments d un appel d une methode */
void generListArg(TreeP listArg, char* nomMethod, int pos)
{
    if(listArg->op == LARG)
    {
        generExpr(getChild(listArg,0));
        PUSHG(pos);
        generListArg(getChild(listArg,1),nomMethod, pos++);
    }
    else {
        generExpr(listArg);
        PUSHG(pos);
        PUSHA(nomMethod);
        CALL();
        POPN(pos);
    }
}
/* Liste optionelle des arguments d un appel d une instanciation */
void generListArgOptInst(TreeP listArgOpt, int pos)
{
    if(listArgOpt == NIL(Tree)) return;
    generListArgInst(listArgOpt, pos);
}
/* Liste des arguments d un appel d une instanciation */
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
/* Cible d une operation ou autre, comme un id, this.x, etc... */
void generArgOuCible(TreeP argOuCible)
{
    switch(argOuCible->op){
        case EDOT :                                     /* ListSelection */
            generListSelection(getChild(argOuCible,0));
            break;
        case ETHISSELECT :                              /* ThisSelect */
            generThisSelect(getChild(argOuCible,0));
            break;
        case CSTE :                                     /* Integer */
            PUSHI(argOuCible->u.val);
            break;
        default : generSelection(argOuCible); break;
  }
}
/* Combinaison de this et de Selection */
void generThisSelect(TreeP thisSelect)
{
    switch(thisSelect->op){
        case LISTDOT :                                  /* This.ListSelection */
            generListSelection(getChild(thisSelect,1));
            break;
        case EDOT :                                     /* This.Selection */
            generSelection(getChild(thisSelect,1));
            break;
        default : break;                                /* This */
    }
}
void generListSelection(TreeP listSelection)
{
    generSelWithClassID(getChild(listSelection,0));
    generSelection(getChild(listSelection,1));
}
/* Selection qui pourrait commencer par un appel a une classe, il faut donc qu il soit en premier */
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
            break;
        case CSTR :
            PUSHS(selection->u.str);
            break;
        case CAST :
             generExpr(getChild(selection,1));
             break;
        case ESEL :
            /*TODO*/
            break;
        case EEXPR :
            generExpr(getChild(selection,0));
            break;
      default : generMessage(selection); break;
    }
}
/* Appel d une fonction */
void generMessage(TreeP message)
{
    TreeP nomMethode = getChild(message,0);
    if(!strcmp(nomMethode->u.str,"print") ) {
        fprintf(out,"-- Appel methode print\n");
        WRITES();
        PUSHS("\"\\n\"");
        WRITES();
    }
    else if(!strcmp(nomMethode->u.str,"println") ) { /* redefinition? */
        fprintf(out,"-- Appel methode println\n");
        WRITES();
    }
    else{
        fprintf(out,"-- Appel methode %s\n",nomMethode->u.str);
    }
    generListArgOpt(getChild(message,1),nomMethode->u.str);
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
/* Declarations de variables dans une definition de classe ou d objet, un simple message */
void generChp(VarDeclP chp)
{
    if (chp->aVar == TRUE){
        fprintf(out, "---- Definition du champ %s \n",chp->name);
    }
    else {
    }
}

/* Declarations de variables dans un bloc, il faut donc allouer ici*/
void generChpBloc(VarDeclP chp)
{
    if (chp->aVar == TRUE){ /* Nouvelle definition de variable */
        fprintf(out, "---- Définition du champ %s \n",chp->name);
        /* On doit allouer la place necessaire selon le nombre de champs */
        /* je ne pense pas qu on alloue simplement a la declaration */
        /*ALLOC(getNbChpClass(chp->nomType));
        DUPN(1);*/
        generDeclExprOpt(chp->expr);
        STORE(0);
    }
    else {

    }
}
