#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include "tp.h"
#include "code.h"
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

classeP classes = NIL(classe); /* liste des classes*/
objectP objets = NIL(object); /*liste des objets */
methodP methodes = NIL(method); /*liste des objets */
pileVar pileVariables; /* pile des variables pour la vérification contextuelles*/

/* classes predefinies int str et void */
classeP cInteger,cString, cVoid;
int taille=0;

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


void lancerCompilation(TreeP defClasses, TreeP root){
	/*affichageArbre(root,0);*/
    
    /* definition des classes prefinies*/
    cInteger = makeClass("Integer",NULL,NULL,NULL,NULL);
    cVoid = makeClass("Void",NULL,NULL,NULL,NULL);
    cString = makeClass("String",NULL,NULL,NULL,NULL);
    affichageClasses();
    affichageObjets();
    affichageMethodes();

    FILE *fileToWrite;
    fileToWrite = fopen("test.txt", "w+");
    lancerGeneration(defClasses,fileToWrite);
}

classeP makeClass(char* nameP,  VarDeclP parametresP, TreeP superP, TreeP constructeurP, TreeP corps){
	classeP nouvClasse = NEW(1, classe);
	nouvClasse->name = nameP;
	nouvClasse->parametres = parametresP;
    /*nouvClasse->attributs = getChild(corps, 0);
	nouvClasse->lmethodes = getChild(corps, 1);*/ 
	nouvClasse->constructeur = constructeurP; 
    nouvClasse->super = getClasseMere(superP);
	nouvClasse->next = NIL(classe);
    addClasse(nouvClasse);
	return nouvClasse;
} 

methodP makeMethod(bool redefP, char* nameP, VarDeclP paramP, char* typeRetourP, TreeP bodyP) {
	methodP nouvMethode = NEW(1, method);
	nouvMethode->redef = redefP;
	nouvMethode->name = nameP;
	nouvMethode->param = paramP;
    /* TODO
	if (type == NIL(char)){
		nouvMethode->typeRetourP = "Void";
	}
	else { nouvMethode->typeRetourP = type; }
    */
    
	nouvMethode->body = bodyP;
    
	nouvMethode->next = NIL(method);
    addMethode(nouvMethode);
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

objectP makeObjet(char* name, VarDeclP attributs, methodP lmethodes){
    objectP nouvObjet = NEW(1, object);
    nouvObjet->name = name;
    nouvObjet->lmethodes = lmethodes;
    nouvObjet->attributs = attributs;    
    nouvObjet->next = NIL(object);
    
    addObjet(nouvObjet);
    return nouvObjet;
}

void affichageArbre(TreeP tree,int niveauArbre){
    
    int i,j = 0;
    if(tree == NIL(Tree)){
        printf("NIL\n");
    }       
    else if(tree->nbChildren > 0 ){
        printf("%s(%hi):%d:(nbchildren=%d)\n", recupEtiquette(tree->op),tree->op,niveauArbre,tree->nbChildren);
        for (i=0;i<tree->nbChildren;i++) {
            for (j=0;j<niveauArbre;j++)
                printf("__");
            affichageArbre(tree->u.children[i],niveauArbre+1);
        }          
    }
    else{  
        printf("%s(%hi):%d\n", recupEtiquette(tree->op),tree->op, niveauArbre);
    }
}


char* recupEtiquette(short op){
    switch(op){
        case 1 : return "NE";
        case 2 : return "EQ";
        case 3 : return "LT";
        case 4 : return "LE";
        case 5 : return "GT";
        case 6 : return "GE";
        case 7 : return "EADD";
        case 8 : return "ESUB";
        case 9 : return "EMUL";
        case 10 : return "EQUOT";
        case 11 : return "EREST";
        case 12 : return "EAND";
        case 13 : return "EAFF";
        case 14 : return "EDOT";
        case 15 : return "EEXTND";
        case 16 : return "ETHIS";
        case 17 : return "ERETURN";
        case 18 : return "CSTE";
        case 19 : return "CSTR";
        case 20 : return "EID";
        case 21 : return "ECLASS";
        case 22 : return "CAST";
        case 23 : return "ITE";
        case 24 : return "LCHAMP";
        case 25 : return "LARG";
        case 26 : return "LPARAM";
        case 27 : return "LMETH";
        case 28 : return "LINST";
        case 29 : return "LCLASS";
        case 30 : return "MSG";
        case 31 : return "EBLOC";
        case 32 : return "ENEW";
        case 33 : return "over";
        case 34 : return "CHMP";
        case 35 : return "EEXPR";
        case 36 : return "ESEL";
        case 37 : return "EARG";
        case 38 : return "EVAR";
        case 39 : return "EPAR";
        case 40 : return "EMETHOD";
        case 41 : return "EOBJ";
        case 42 : return "EPROG";
        case 43 : return "LSEL";
        case 44 : return "EIDCLASS";
        case 45 : return "ECORPS";
        case 46 : return "LOBJET";
        case 47 : return "EDEFOBJ";
        case 48 : return "EDEFCLASS";
        default : return "ERREUR";
    }   
    
}

void addClasse(classeP c){
    c->next = classes;
    classes = c;
}

void addObjet(objectP o){
    o->next = objets;
    objets = o;
}

void addMethode(methodP m){
    printf("%s\n",m->name);
    m->next = methodes;
    methodes = m;
}

void affichageClasses(){
    classeP listClass = NEW(1, classe);
    listClass = classes;
    printf("\n ---Liste des classes--- \n");
    while(listClass != NIL(classe)){
        printf("Nom de classe : %s ",listClass->name);
        if(listClass->super != NULL){
            printf("| Classe mere : %s ",listClass->super->name);
            
        }
        printf("| liste des parametres : ");
        VarDeclP params = NEW(1,VarDecl);
        params = listClass->parametres;
        while(params != NIL(VarDecl)){
            printf(" %s", params->name);
            params = params->next;
        }
        printf("\n");

        

        listClass = listClass->next;
    }
}

void affichageObjets(){
    objectP listObjet = NEW(1, object);
    listObjet = objets;
    printf("\n ---Liste des objets--- \n");
    while(listObjet != NIL(object)){
        printf("%s\n",listObjet->name);

        printf("| liste des methodes : \n");
        methodP meths = NEW(1,method);
        meths = listObjet->lmethodes;
        while(meths != NIL(method)){
            printf(" %s", meths->name);

            printf("\t| liste des parametres : ");
            VarDeclP params = NEW(1,VarDecl);
            params = meths->param;
            while(params != NIL(VarDecl)){
              printf(" %s", params->name);
              params = params->next;
            }
            
            /*TODO :printf("| type de retour : %s", meths->typeRetour->name);*/
            /*TODO :printf(" | Methode Mere : %s", meths->methodeMere->name);*/
            printf(" | Redef : %s",meths->redef ? "True" : "False");
            printf("\n");œ
            meths = meths->next;
        }
        printf("\n\n");

        listObjet = listObjet->next;
    }
    
}

void affichageMethodes(){
    methodP listMethodes = NEW(1, method);
    listMethodes = methodes;
    printf("\n ---Liste des methodes--- \n");
    while(listMethodes != NIL(method)){
        printf("%s\n",listMethodes->name);
        listMethodes = listMethodes->next;
    }
    
}


/* A partir du Tree P de la classe, avoir le pointeur de la classe mere*/
classeP getClasseMere(TreeP tree){
    char* res = NULL;    
    int i,indice = 0;
    
    if(tree == NIL(Tree)){
        res = NULL;
    }       
    else{
        TreeP arbre [5];
        arbre[0] = tree;
        while(1){
            if(strcmp(recupEtiquette(arbre[indice]->op),"EIDCLASS") == 0 ){
                res = arbre[indice]->u.str;
                break;
            }
            else{
                for (i=0;i<arbre[indice]->nbChildren;i++){
                    arbre[indice+(i+1)] = arbre[indice]->u.children[i];
                }
                indice++;
            }  
        }
    }

    classeP c = getPointeurClasse(res);
    return c;

    
}

classeP getPointeurClasse(char* s){
    classeP listClass = NEW(1, classe);
    listClass = classes;
    if(s == NULL){
        return NULL;
    }
    while(listClass != NIL(classe)){
        if(strcmp(listClass->name,s)==0){
            return listClass;
        }
        else{
            listClass = listClass->next;
        }
    }
    return NULL;
}

VarDeclP idToDecl(char* id){
  int compte = 0;
  if (!pileVariables.sommet){
    printf("Pas de variables");
    return NIL(VarDecl);
  }
  ptrVar elemActuel = pileVariables.sommet;
    
  while (compte < pileVariables.taille){
		if( strcmp(elemActuel->var->name, id) == 0) return elemActuel->var;
		elemActuel = elemActuel->next;
		compte += 1;
	}
	printf("Variable introuvable");
	return NIL(VarDecl);
}

classeP idToClass(char* id){
  if (!classes){
    printf("Pas de classes");
    return NIL(classe);
  }
  classeP classActuelle = classes;
    
  while (classActuelle){
    if( strcmp(classActuelle->name, id) == 0) return classActuelle;
    classActuelle = classActuelle->next;
  }
  printf("Classe introuvable");
  return NIL(classe);
}

objectP idToObj(char* id){
  if (!objets){
    printf("Pas d'objets'");
    return NIL(object);
  }
  objectP objetActuel = objets;
    
  while (objetActuel){
    if( strcmp(objetActuel->name, id) == 0) return objetActuel;
    objetActuel = objetActuel->next;
  }
  printf("Classe introuvable");
  return NIL(object);
}

methodP idToMeth(char* id, methodP lmethodes){
  if (!lmethodes){
    printf("Pas de methodes");
    return NIL(method);
  }
  methodP methActuelle = lmethodes;
    
  while (methActuelle){
    if( strcmp(methActuelle->name, id) == 0) return methActuelle;
    methActuelle = methActuelle->next;
  }
  printf("Methode introuvable");
  return NIL(method);
}










