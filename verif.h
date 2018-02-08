
#include <stdlib.h>

/* Pile pour l'analyse de portée */
typedef struct _elmtVar elmtVar, *elmtVarP;
typedef struct _pileVar pileVar, *pileVarP;


/* Structures de pile pour l'analyse de portée */
struct _pileVar{
    elmtVarP sommet;
    int taille;
};

struct _elmtVar{
    VarDeclP var;
    elmtVarP next;
};

void initPile();
void empiler(VarDeclP decl);
void depiler();
void depilerBloc();

void analysePortee (TreeP corps, pileVar env);
bool verifId(char* id, pileVar env);
bool verifClass(char* nomClasse, pileVar env);
void empilerBloc();


bool verifSurcharges(classeP c);
bool verifSurcharges2(classeP maClasse,classeP maClasse2);
