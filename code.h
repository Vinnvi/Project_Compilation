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

void lancerGeneration(TreeP tree, FILE* out);
void generBloc(TreeP bloc);
void generObject(objectP obj);
void generClass(classeP class);
void generListInst(TreeP listInst);
void generInst(TreeP instr);
void lancerGeneration(TreeP tree, FILE* out);
void generCouOP(TreeP couOP);
void generArgOuCible(TreeP argOuCible);
void generOperation(TreeP operation);
void generIfElse(TreeP ifElse);
void generExpression(TreeP expr);
void generOperation(TreeP operation);
void generValeur(TreeP valeur);
void generExpression(TreeP expr);
void generListChp(VarDeclP listChp);
void generClassId(char* classId);
void generListParam(VarDeclP listParam);
void generCorpsClass(TreeP corpsClasse);
void generExtends(TreeP extends);
void generOverride(bool override);
void generDefClassObj(TreeP defClassObj);
void generObjetOuClasse(TreeP objetOuClasse);
void generListMeth(methodP listMeth);
