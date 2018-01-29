#include <stdlib.h>

/*Instructions de Label*/
/*
void NOP();
void LABEL(char* c);
void NEWLABEL(char* c);
void NEWMETHLABEL(char* nomMeth, char* typeRetour);
*/
/*Instructions sur la pile*/
/*
void PUSHI(int i);
void PUSHS(char *c);
void WRITES();
void PUSHG(int a);
void PUSHG_addr(char* c);
void PUSHL(int a);
void PUSHL_addr(char* c);
void STOREL(int x);
void STOREG(int x);*/
char* makeLabel(char* nameLabel);
int getAddr(char* name);

void lancerGeneration(TreeP programme, FILE* chOut);
void generDefClassObjOpt(TreeP defClassObj);
void generDefClassObj(TreeP defClassObj);
void generObjetOuClasse(TreeP objetOuClasse);
void generObject(objectP obj);
void generBlocOpt(TreeP blocOpt);
void generBloc(TreeP bloc);
void generBlocNonVide(TreeP bloc);
void generListInstOpt(TreeP listInstOpt);
void generListInst(TreeP listInst);
void generInst(TreeP inst);
void generIfElse(TreeP ifElse);
void generExpr(TreeP expr);
void generValeur(TreeP valeur);
void generOperation(TreeP operation);
void generInstanciation(TreeP instanciation);
void generClass(classeP class);
void generCorpsClass(TreeP corpsClasse);
void generListMethOpt(methodP listMethOpt);
void generListMeth(methodP listMeth);
void generMeth(methodP meth);
void generListParamOpt(VarDeclP listParamOpt);
void generListParam(VarDeclP listParam);
void generParam(VarDeclP param);
void generDeclExprOpt(TreeP declExprOpt);
void generExtendsOpt(TreeP extends);
void generExtends(TreeP extends);
void generListArgOpt(TreeP listArgOpt);
void generListArg(TreeP listArg);
void generArgOuCible(TreeP argOuCible);
void generThisSelect(TreeP thisSelect);
void generListSelection(TreeP listSelection);
void generSelWithClassID(TreeP selWithClassID);
void generSelection(TreeP selection);
void generMessage(TreeP message);
void generListChpOpt(VarDeclP listChpOpt);
void generListChp(VarDeclP listChp);
void generChp(VarDeclP chp);
void generClassId(char* classId);
void generOverride(bool override);
