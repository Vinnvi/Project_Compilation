
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


bool verifSurcharges(classeP c);
bool verifSurcharges2(classeP maClasse,classeP maClasse2);
