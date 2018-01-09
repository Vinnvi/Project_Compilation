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
      { char *S;
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

struct _Class{
	 char* name; /* identificateur */
	 methodP lmethodes; /*pointeur sur la liste des methodes de la classe*/
	 attP attributs; /*pointeur sur la liste des attributs de la classe*/
	 struct _Class *m; /*classe mere*/
	 struct _Class *next; /*Pour chainer les classes*/
};


/*Structure d'un attribut */
struct _Att{
	char* name; /* Nom de l'attribut */
	struct _Class type; /*type de l'attribut */
	struct _Class valeur; /* valeur de l'attribut */
	struct _Class *next; /* pointeur vers l'attribut suivant */
};


/* Structure d'une méthode */
struct _Method{
	char* name; /* identificateur */
	struct _Class *typeRetour; /* type retour methode */
	struct _Method *methodeMere; /*Override*/
	attP parametres; /* Liste des parametres */
	instrP instructions; /*Liste des expressions*/
	struct _Method *next;
};

/* structure d'un objet*/
struct _Object{
	char* name; /* identificateur */
	methodP lmethodes; /* pointeur sur la liste des methodes de l'objet */
	attP attributs; /* pointeur sur la liste des attributs de l'objet */
	struct _Object *next;
};

/* la structure d'une pile (pas encore bien definie pouir le moment) */
struct _Pile{
	struct _Class *donnee; /*Valeur de l element de la pile*/
	struct _pile *precedent; /* lien vers autre element pile*/
}; 


/****Not defined****/


struct _Expression{
	struct _Identificateur *ident;
	struct _Constante *constante;
	struct _Selection *select;
	struct _Cast *cast;
	struct _Instantiation *instant;
	struct _Message *message;
	struct _InstrOpe *instrope;
	
};


struct _Identificateur{
    char * nomIdentificateur;
};

/*Structure d'une selection ( = expression.nom)*/
struct _Selection{
    struct _Expression expression; /*expression*/
    att nom; /* nom de l'attribut de la classe */
};

/* Structure d'un Cast (= (nomClasse espression) ) */
struct _Cast{
    struct _Class *nomClasse;
    struct _Expression expression;
    
};

struct _Argument{
    char* name; /*Nom de la variable entrée en argument*/
    struct _Class classe; /*classe de l'argument */
    struct _Expression expr; 
};

struct _Instantation{
    struct _Class classe;
    struct _Argument *lArguments;   
};

struct _Message{
    struct _Expression expr;
    method mehtode;
};


//
enum typeNode{
    Add,
    Mult,
    Div,
    Minus,
    NotDefined,
    NumberValue
};

struct ASTTree{
    typeNode type; // type de la valeur;
     
};
