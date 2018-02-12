#include <stdlib.h>

/*Instructions de Label*/
/*
void NOP();
void LABEL(char* c);
void NEWLABEL(char* c);
void NEWMETHLABEL(char* nomMeth, char* typeRetour);
*/
/*Instructions sur la pile*/


/* Structure des variables stockées dans notre pile */
typedef struct _Stack {
    int size;
} Stack, *stackP;

void PUSHI(int i);
void PUSHS(char *c);
void WRITES();
void PUSHG(int a);
void PUSHG_addr(char* c);
void PUSHL(int a);
void PUSHG_addr(char* c);
void STOREL(int x);
void STOREG(int x);
char* makeLabel(char* nameLabel);
int getAddr(char* name);

void lancerGeneration(TreeP programme, FILE* chOut);
void generDefClassObjOpt(TreeP defClassObj);
void generDefClassObj(TreeP defClassObj);
void generObjetOuClasse(TreeP objetOuClasse);
void generObject(objectP obj);
void generBlocOpt(TreeP blocOpt);
void generBloc(TreeP bloc);
void generListInstOpt(TreeP listInstOpt);
void generListInst(TreeP listInst);
void generInst(TreeP inst);
void generIfElse(TreeP ifElse);
void generExpr(TreeP expr);
void generOperation(TreeP operation);
void generInstanciation(TreeP instanciation);
void generClass(classeP class);
void generCorpsClass(TreeP corpsClasse, char* name);
void generListMethOpt(methodP listMethOpt,char* name);
void generMeth(methodP meth);
void generListParamOpt(VarDeclP listParamOpt);
void generListParam(VarDeclP listParam);
void generListParamDef(VarDeclP listParamDef);
void generParamDef(VarDeclP paramDef);
void generDeclExprOpt(TreeP declExprOpt);
void generListArgOpt(TreeP listArgOpt, char* nomMethod);
void generListArg(TreeP listArg, char* nomMethod, int pos);
void generListArgOptInst(TreeP listArgOpt, int pos);
void generListArgInst(TreeP listArg, int pos);
void generArgOuCible(TreeP argOuCible);
void generThisSelect(TreeP thisSelect);
void generListSelection(TreeP listSelection);
void generSelWithClassID(TreeP selWithClassID);
void generSelection(TreeP selection);
void generMessage(TreeP message);
void generListChpOpt(VarDeclP listChpOpt, char* name);
void generListChp(VarDeclP listChp, char* name, int pos);
void generListChpBloc(VarDeclP listChp);
void generChp(VarDeclP chp);
void generChpBloc(VarDeclP chp);

void setNbChpClass(char* name, int nbChp);
int getNbChpClass(char* chClass);
