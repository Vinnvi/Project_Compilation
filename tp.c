#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "tp.h"
#include "tp_y.h"

extern int yyparse();
extern int yylineno;

/* Peut servir a controloer le niveau de 'verbosite'.
 * Par defaut, n'imprime que le resultat et les messages d'erreur
 */
bool verbose = FALSE;

/* Peut servir a controler la generation de code. Par defaut, on produit le code
 * On pourrait avoir un flag similaire pour s'arreter avant les verifications
 * contextuelles (certaines ou toutes...)
 */
bool noCode = FALSE;

/* Pour controler la pose de points d'arret ou pas dans le code produit */
bool debug = FALSE;

/* code d'erreur a retourner */
int errorCode = NO_ERROR; /* defini dans tp.h */

FILE *out; /* fichier de sortie pour le code engendre */


int main(int argc, char **argv) {
  int fi;
  int i, res;

  out = stdout;
  for(i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      switch (argv[i][1]) {
      case 'd': case 'D':
	debug = TRUE; continue;
      case 'v': case 'V':
	verbose = TRUE; continue;
      case 'e': case 'E':
	noCode = TRUE; continue;
      case '?': case 'h': case 'H':
	fprintf(stderr, "Appel: tp -v -e -d -o file.out programme.txt\n");
	exit(USAGE_ERROR);
      case'o':
	  if ((out= fopen(argv[++i], "w")) == NULL) {
	    fprintf(stderr, "erreur: Cannot open %s\n", argv[i]);
	    exit(USAGE_ERROR);
	  }
	break;
      default:
	fprintf(stderr, "Option inconnue: %c\n", argv[i][1]);
	exit(USAGE_ERROR);
      }
    } else break;
  }

  if (i == argc) {
    fprintf(stderr, "Fichier programme manquant\n");
    exit(USAGE_ERROR);
  }

  if ((fi = open(argv[i++], O_RDONLY)) == -1) {
    fprintf(stderr, "erreur: Cannot open %s\n", argv[i-1]);
    exit(USAGE_ERROR);
  }

  /* redirige l'entree standard sur le fichier... */
  close(0); dup(fi); close(fi);

  res = yyparse();
  /* si yyparse renvoie 0, le programme en entree etait syntaxiquement correct.
   * Le plus simple est que les verifications contextuelles et la generation
   * de copde soient lancees par les actions associees a la regle de grammaire
   * pour l'axiome. Dans ce cas, quand yyparse renvoie sa valeur on n'a plus
   * rien a faire, sauf fermer les fichiers qui doivent l'etre.
   * Si yyparse renvoie autre chose que 0 c'est que le programme avait une
   * erreur lexicale ou syntaxique
   */

  printf("Analyse syntaxique réussie\n");

   

  if (out != NIL(FILE) && out != stdout) fclose(out);
  return res ? SYNTAX_ERROR : errorCode;
}


void setError(int code) {
  errorCode = code;
  if (code != NO_ERROR) {
    noCode = TRUE;
    /* la ligne suivante peut servir a "planter" volontairement le programme
     * des qu'une de vos fonctions detectent une erreur et appelle setError.
     * Si vous executez le rpogramme sous le debuggeur vous aurez donc la main
     * et pourrez examiner la pile d'execution.
     */
    /*  abort(); */
  }
}


/* yyerror:  fonction importee par Bison et a fournir explicitement. Elle
 * est appelee quand Bison detecte une erreur syntaxique.
 * Ici on se contente d'un message a minima.
 */
void yyerror(char *ignore) {
  printf("erreur de syntaxe: Ligne %d\n", yylineno);
  setError(SYNTAX_ERROR);
}



/* ****** Fonctions pour la construction d'AST   ********************
 *
 * Ajoutez vos propres constructeurs, si besoin
 *
 */

/* Tronc commun pour la construction d'arbre. Normalement on ne l'appelle
 * pas directement. Elle ne fait qu'allouer, sans remplir les champs
 */
TreeP makeNode(int nbChildren, short op) {
  TreeP tree = NEW(1, Tree);
  tree->op = op;
  tree->nbChildren = nbChildren;
  tree->u.children = nbChildren > 0 ? NEW(nbChildren, TreeP) : NIL(TreeP);
  return(tree);
}


/* Construction d'un arbre a nbChildren branches, passees en parametres.
 * Pour comprendre en detail (si necessaire), regardez un tutorial sur
 * comment on passe un nombre variable d'arguments à une fonction et
 * comment on recupere chacun de ces arguments.
 * cf va_list, va_start, va_arg et va_end.
 * makeTree prend donc toujours au moins 2 arguments
 */
TreeP makeTree(short op, int nbChildren, ...) {
  va_list args;
  int i;
  TreeP tree = makeNode(nbChildren, op);
  va_start(args, nbChildren);
  for (i = 0; i < nbChildren; i++) {
    tree->u.children[i] = va_arg(args, TreeP);
  }
  va_end(args);
  return(tree);
}


/* Retourne le rank-ieme fils d'un arbre (de 0 a n-1) */
TreeP getChild(TreeP tree, int rank) {
  if (tree->nbChildren < rank -1) {
    fprintf(stderr, "Incorrect rank in getChild: %d\n", rank);
    abort(); /* plante le programme en cas de rang incorrect */
  }
  return tree->u.children[rank];
}


void setChild(TreeP tree, int rank, TreeP arg) {
  if (tree->nbChildren < rank -1) {
    fprintf(stderr, "Incorrect rank in getChild: %d\n", rank);
    abort(); /* plante le programme en cas de rang incorrect */
  }
  tree->u.children[rank] = arg;
}


/* Constructeur de feuille dont la valeur est une chaine de caracteres */
TreeP makeLeafStr(short op, char *str) {
  TreeP tree = makeNode(0, op);
  tree->u.str = str;
  return tree;
}


/* Constructeur de feuille dont la valeur est un entier */
TreeP makeLeafInt(short op, int val) {
  TreeP tree = makeNode(0, op);
  tree->u.val = val;
  return(tree);
}

/* Constructeur de feuille dont la valeur est une declaration */
TreeP makeLeafLVar(short op, VarDeclP lvar) {
  TreeP tree = makeNode(0, op);
  tree->u.lvar = lvar;
  return(tree);
}

void lancerCompilation(TreeP def, TreeP arbre){
    /*TODO
    TODO
    TODO
    */
}

/* les P à la fin des paramètres c'est P comme "Paramètre" et pas Pointeur. (my bad) */
classeP makeClass(char* nameP,  TreeP parametresP, TreeP superP, TreeP constructeurP, TreeP attributsP, TreeP lmethodesP){
	classeP nouvClasse = NEW(1, classe);
	nouvClasse->name = nameP;
	/*nouvClasse->lmethodes = lmethodesP; TODO BLALAL*/ 
	nouvClasse->constructeur = constructeurP;
	/*nouvClasse->attributs = attributsP; TODO pareil qu'en dessous */
	/*nouvClasse->parametres = parametresP; TODO construire les paramètres à partir de l'arbre */
	/*nouvClasse->super = superP; TODO ici le traitement à faire est autre : il faut lire le nom de la classe qui est extended et chercher le pointeur vers la classe correspondant */
	
	nouvClasse->next = NIL(classe);
	return nouvClasse;
} 
/*
//A voir si on fait 2 fonctions, necessair ou non? Body peut il prendre expr comme il peut prendre bloc
methodP makeMethodExpr(bool redef, char* name, VarDeclP param, char* typeRetour, TreeP body) {
	MethodP nouvMethode = NEW(1, method);
	nouvMethode->redef = redef;
	nouvMethode->name = name;
	nouvMethode->param = param;
	//TODO 
    //if (type == NIL(char)){
	//	nouvMethode->typeRetourP = "Void";
	//}
    //else { nouvMethode->typeRetourP = type; }
	nouvMethode->body = expr;
	nouvMethode->next = NIL(method);
	return nouvMethode;
}
*/
methodP makeMethod(bool redefP, char* nameP, TreeP paramP, char* typeRetourP, TreeP bodyP) {
	methodP nouvMethode = NEW(1, method);
	nouvMethode->redef = redefP;
	nouvMethode->name = nameP;
	/*nouvMethode->param = paramP; TODO construire à partir de l'arbre */
    /* TODO
	if (type == NIL(char)){
		nouvMethode->typeRetourP = "Void";
	}
	else { nouvMethode->typeRetourP = type; }
    */
	nouvMethode->body = bodyP;
	nouvMethode->next = NIL(method);
	return nouvMethode;
}

VarDeclP makeVar(bool aVar, char *name, char* type, TreeP expr){
    VarDeclP nouvVar = NEW(1, VarDecl);
    nouvVar->name = name;
    /*nouvVar->type = type; TODO fonction qui retourne un type */
    nouvVar->expr = expr;
    nouvVar->aVar = aVar;

    nouvVar->next = NIL(VarDecl);
    return nouvVar;
}

objectP makeObjet(char* name, TreeP attributs, TreeP lmethodes){
    objectP nouvObjet = NEW(1, object);
    nouvObjet->name = name;
    /*nouvObjet->lmethodes = lmethodes;
    nouvObjet->attributs = attributs; TODO lire les arbres làààà */
    
    nouvObjet->next = NIL(object);
    return nouvObjet;
}


















