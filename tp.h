#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef unsigned char bool;

/* deux macros pour eviter de faire des malloc en se trompant de type : on
 * s'oblige a expliciter le type d'objet a allouer et on récupere une
 * de type pointeur sur le type alloue.
 * Exemple: Allouer 3 objets de la structure Tree (voir ci-dessous)
 * TreeP p := NEW(3, Tree);
 *
 * De meme, sobloiger à mettre un type au NIL ci-dessous permet souvent
 * d'eviter de confondre entre des pointeurs de type differents.
 */
#define NEW(howmany, type) (type *) calloc((unsigned) howmany, sizeof(type))
#define NIL(type) (type *) 0

/* Etiquettes additionnelles pour les arbres de syntaxe abstraite.
 * Certains tokens servent directement d'etiquette. Attention ici a ne pas
 * donner des valeurs identiques a celles des tokens.
 *
 * Il y a surement des choses a recuperer en plus de ce que vous avez
 * produit pour le tp.
 */

#define NE	1
#define EQ	2
#define LT	3
#define LE	4
#define GT	5
#define GE	6

#define EADD 	7
#define ESUB 	8
#define EMUL 	9
#define EQUOT 	10
#define EREST 	11
#define EAND 	12
#define EAFF	13
#define EDOT    14
#define EEXTND  15
#define ETHIS   16
#define ERETURN 17

#define CSTE 	18
#define CSTR 	19
#define EID      20
#define ECLASS  21
/* faire des étiquettes genre TYPE? CAST? et y attribuer des règles genre QQCHS -> Id dans le cas où on fait des casts ou ce genre de choses*/


#define CAST 22
#define ITE 23
#define LCHAMP 24
#define LARG 25
#define LPARAM 26
#define LMETH 27
#define LINST 28
#define LCLASS 29
#define MSG 30
#define EBLOC 31
#define ENEW 32
#define OVER 33
#define CHMP 34
#define EEXPR 35
#define ESEL 36
#define EARG 37
#define EVAR 38
#define EPAR 39
#define EMETHOD 40
#define EOBJ 41
#define EPROG 42
#define LSEL 43
#define EIDCLASS 44
#define ECORPS 45
#define LOBJET 46
#define EDEFOBJ 47
#define EDEFCLASS 48
#define ETHISSELECT 49
#define LISTDOT 50

/* Codes d'erreurs. Cette liste n'est pas obligatoire ni limitative */
#define NO_ERROR	0
#define USAGE_ERROR	1
#define LEXICAL_ERROR	2
#define SYNTAX_ERROR    3
#define CONTEXT_ERROR	40	/* default value for this stage */
#define DECL_ERROR	41	/* scope problem */
#define TYPE_ERROR	42	/* type checking problem */
#define OTHER_CONTEXTUAL_ERROR	43 /* replace by something more precise */
#define EVAL_ERROR	50	/* dubious when writing a compiler ! */
#define UNEXPECTED	10O

/* structures necessaires pour le programme */
typedef struct _Classe classe, *classeP;
typedef struct _Method method, *methodP;
typedef struct _Object object, *objectP;
typedef struct _Programme prog,*ProgP;
typedef struct _Tree Tree,*TreeP;
typedef union _ClasseOuObjet CouO, *CouOP;

/* Pile pour l'analyse de portée */
typedef struct _elmtVar elmtVar, *ptrVar;
typedef struct _pileVar pileVar, *ptrPileVar;

/* Adapt as needed. Currently it is simply a list of names ! */
typedef struct _varDecl {
  char *name;
  struct _varDecl *next;
  struct _Classe *type;
  TreeP expr;
  bool aVar;

} VarDecl, *VarDeclP;

/* la structure d'un arbre (noeud ou feuille) */
struct _Tree {
  short op;         /* etiquette de l'operateur courant */
  short nbChildren; /* nombre de sous-arbres */
  union {
    char *str;      /* valeur de la feuille si op = Id ou STR */
    int val;        /* valeur de la feuille si op = Cste */
    VarDeclP lvar;  /* ne pas utiliser tant qu'on n'en a pas besoin :-) */
    struct _Tree **children; /* tableau des sous-arbres */
    methodP lmeth;
    objectP lobj;
    classeP lclass;
  } u;
};

typedef union
{ 	char *S;
    char C;
	int I;
    bool B;
	TreeP pT;
	VarDeclP pV; /* same comment as above */
    methodP MethP;
    classeP ClasseP;
    objectP ObjetP;
    CouOP CouOP;
} YYSTYPE;

#define YYSTYPE YYSTYPE

/* structure du programme  */
struct _Programme{
	classeP classes; /*classes du programme */
	objectP objets; /*objets du programme */
	TreeP main; /* bloc main */
};

/*Structure d'une classe */
struct _Classe{
	 char* name; /* identificateur */
	 methodP lmethodes; /*pointeur sur la liste des methodes de la classe*/
     TreeP constructeur;
     VarDeclP attributs; /*Attributs de la classe*/
     VarDeclP parametres; /* liste des parametres de la classe */
	 classeP super; /*classe mere*/
	 struct _Classe *next; /*Pour chainer les classes*/
};



/* Structure d'une méthode */
struct _Method{
	char* name; /* identificateur */
    VarDeclP param; /*liste des parametres*/
    TreeP body; /*Corps de la methode*/
	struct _Classe *typeRetour; /* type retour methode */
	struct _Method *methodeMere; /*Override*/
    bool redef;
	struct _Method *next;
};

/* structure d'un objet*/
struct _Object{
	char* name; /* identificateur */
    /*TreeP body; corps de l'objet*/
	methodP lmethodes; /* pointeur sur la liste des methodes de l'objet */
	VarDeclP attributs; /* pointeur sur la liste des attributs de l'objet */
	struct _Object *next;
};

struct _pileVar{
    ptrVar sommet;
    int taille;
};

struct _elmtVar{
    VarDeclP var;
    ptrVar next;
};

union _ClasseOuObjet{
	classe c;
    object o;
};

struct _Instruction{
    union{
        TreeP exp;
        struct _bloc *bloc;
        TreeP aff;
        struct _ifThenElse *ifThenElse;
    } monU2;
    struct _Instruction *next;
};

struct _ifThenElse{
    TreeP *expressionIf;
    struct _Instruction *instructionThen;
    struct _Instruction *instructionElse;
};

struct _bloc{
   TreeP lInstruction;
};

/* Structures de gestion des variables (port�e, masquage) */
/**
Emcapsule une variable et son adresse dans le programme
*/
typedef struct _Symbole {
  /* VariableP var; */
  short addr;
  struct _Symbole* next;
} Symbole, *symboleList, *SymboleP;

/*
Couches de portée des différentes variables
*/
typedef struct _Level {
    int offset;
    SymboleP symboles;
    struct _Level* next;
} Level, *LevelP;

/**
Contient l'ensemble des symboles du programme
on a une pile de bulles, et on pile et d�pile � mesure que l'on entre et quitte des blocks
*/
typedef struct _Stack {
    int size;
    LevelP top_level;
} Stack, *stackP;

TreeP makeTree(short op, int nbChildren, ...);
TreeP makeLeafLVar(short op, VarDeclP lvar);
TreeP makeLeafInt(short op, int val);
TreeP makeLeafStr(short op, char *str);


classeP makeClass(char* nameP,  VarDeclP parametresP, TreeP superP, TreeP constructeurP, TreeP corps);
VarDeclP makeVar(bool aVar,char *name, char *type, TreeP expr);
objectP makeObjet(char* name, VarDeclP attributs, methodP lmethodes);
methodP makeMethod(bool redefP, char* nameP, VarDeclP paramP, char* typeRetourP, TreeP bodyP);

void lancerCompilation(TreeP defClasses, TreeP root);
char* recupEtiquette(short op);
void affichageArbre(TreeP tree,int niveauArbre);
void addClasse(classeP c);
void affichageClasses();
void addObjet(objectP o);
void affichageObjets();
classeP getClasseMere(TreeP tree);
classeP getPointeurClasse(char* s);
void addMethode(methodP m);
void affichageMethodes();
VarDeclP idToDecl(char* id);
classeP idToClass(char* id);
objectP idToObj(char* id);
methodP idToMeth(char* id, methodP lmethodes);
TreeP getChild(TreeP tree, int rank);
void addMethodeTemp(methodP m);
void addVarTemp(VarDeclP v);
