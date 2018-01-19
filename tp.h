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


/* Adapt as needed. Currently it is simply a list of names ! */
typedef struct _varDecl {
  char *name;
  struct _varDecl *next;
} VarDecl, *VarDeclP;


/* la structure d'un arbre (noeud ou feuille) */
typedef struct _Tree {
  short op;         /* etiquette de l'operateur courant */
  short nbChildren; /* nombre de sous-arbres */
  union {
    char *str;      /* valeur de la feuille si op = Id ou STR */
    int val;        /* valeur de la feuille si op = Cste */
    VarDeclP lvar;  /* ne pas utiliser tant qu'on n'en a pas besoin :-) */
    struct _Tree **children; /* tableau des sous-arbres */
  } u;
} Tree, *TreeP;


typedef union
{ 	char *S;
    char C;
	int I;
	TreeP pT;
	VarDeclP pV; /* same comment as above */
} YYSTYPE;

#define YYSTYPE YYSTYPE

/* definition des structures dans lesquelles nous allons stocker toutes
 * nos donnees, faire fonctionner le programme : classes, methodes... */
 
typedef struct _Class class, *classP;
typedef struct _Att att, *attP;
typedef struct _Method method, *methodP;
typedef struct _Object object, *objectP;
typedef struct _Pile pile, *pileP;
typedef struct _Expression expr, *exprP;
typedef struct _Instruction instr,*instrP;
typedef struct _Programme prog,*ProgP;
/* revoir * ou non *       */


/* structure du programme  */
struct _Programme{
	classP classes; /*classes du programme */
	objectP objets; /*objets du programme */
	TreeP main; /* bloc main */
};

/*Structure d'une classe */
struct _Class{
	 char* name; /* identificateur */
	 methodP lmethodes; /*pointeur sur la liste des methodes de la classe*/
     methodP constructeur;
     attP attributs; /*Attributs de la classe*/
     VarDeclP parametres; /* liste des parametres de la classe */
	 struct _Class *super; /*classe mere*/
	 struct _Class *next; /*Pour chainer les classes*/
};



/* Structure d'une méthode */
struct _Method{
	char* name; /* identificateur */
    VarDeclP param; /*liste des parametres*/
    TreeP body; /*Corps de la methode*/
	struct _Class *typeRetour; /* type retour methode */
	struct _Method *methodeMere; /*Override*/
    bool redef;
	struct _Method *next;
};

/* structure d'un objet*/
struct _Object{
	char* name; /* identificateur */
    TreeP body; /*corps de l'objet*/
	methodP lmethodes; /* pointeur sur la liste des methodes de l'objet */
	attP attributs; /* pointeur sur la liste des attributs de l'objet */
	struct _Object *next;
};

/*structure d'un attribut*/
struct _Att{
	char* name; /* Nom de l'attribut */
	struct _Class type; /*type de l'attribut */
	/*   struct _Class valeur; */ /* valeur de l'attribut */
	struct _Att *next; /* pointeur vers l'attribut suivant */
};


:/*
struct _Expression{
    union{
	    struct _Identificateur *ident;
	    struct _Constante *constante;
	    struct _Selection *select;
	    struct _Cast *cast;
	    struct _Instantiation *instant;
	    struct _Message *message;
	    struct _exprOpe *exprOpe;
    } monU;
    struct _Expression *next;
};


struct _Identificateur{
    char * nomIdentificateur;
};

struct _Selection{
    struct _Expression expression; 
    VarDecl nom;
};


struct _Cast{
    struct _Class *nomClasse;
    struct _Expression *expression;
    
};


struct _Instantation{
    struct _Class *classe;
    struct _att *listeParam;
};

struct _Message{ 
    struct _Expression destinataire; 
    struct _Method message; 
    VarDecl param;
    method mehtode; 
};

struct _exprOpe{
    struct _Expression *expressionLeft;
    struct _Expression *expressionRight;
    
};

*/

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

