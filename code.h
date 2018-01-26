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
void generCodeListChpCode(TreeP t);
void generCodeListInst(TreeP t);
void lancerGeneration(TreeP tree, FILE* out);
