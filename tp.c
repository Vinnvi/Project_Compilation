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
methodP methodesTemp = NIL(method);

int indexTab = 0;
methodP tableau[50];

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

VarDeclP getChildList(TreeP tree, int rank) {
    if (tree->nbChildren < rank -1) {
        fprintf(stderr, "Incorrect rank in getChild: %d\n", rank);
        abort(); /* plante le programme en cas de rang incorrect */
    }
    return tree->u.lvar;
}


void setChild(TreeP tree, int rank, TreeP arg) {
  if (tree->nbChildren < rank -1) {
    fprintf(stderr, "Incorrect rank in getChild: %d\n", rank);
    abort(); /* plante le programme en cas de rang incorrect */
  }
  tree->u.children[rank] = arg;
}

TreeP makeLeafClass(short op, classeP chClasse) {
  TreeP tree = makeNode(0, op);
  tree->u.lclass = chClasse;
  return tree;
}

TreeP makeLeafObjet(short op, objectP chObjet) {
  TreeP tree = makeNode(0, op);
  tree->u.lobj = chObjet;
  return tree;
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


/* Fonction principale */
void lancerCompilation(TreeP defClasses, TreeP root){
	/*affichageArbre(root,0);*/

    /* definition des classes prefinies*/
    affichageClasses();
    affichageObjets();
    affichageMethodes();

    FILE *fileToWrite;
    fileToWrite = fopen("test.txt", "w+");
    lancerGeneration(defClasses,fileToWrite);
    fprintf(fileToWrite, "------------DEBUT Bloc Principal\n");
    generBloc(root);
    freeStack();
    fprintf(fileToWrite, "------------FIN Bloc Principal\n");
    fprintf(fileToWrite, "\n");
    /* fclose(fileToWrite);*/
}

/* Initialise les classes de bases */
void initClasses(){

  cInteger = NEW(1, classe);
  cInteger->name = "Integer";
  addClasse(cInteger);
  makeClass("Void",NULL,NULL,NULL,NULL);
    makeClass("String",NULL,NULL,NULL,NULL);
}

/* Créateur de structure classe */
classeP makeClass(char* nameP,  VarDeclP parametresP, TreeP superP, TreeP constructeurP, TreeP corps){
	classeP nouvClasse = NEW(1, classe);
	nouvClasse->name = nameP;
	nouvClasse->parametres = parametresP;
    methodesTemp= NIL(method);
    int i =0;
    while(i<indexTab){
            tableau[i]->next = methodesTemp;
            methodesTemp = tableau[i];
            tableau[i] = NIL(method);
            i++;
    }
    indexTab = 0;
    nouvClasse->lmethodes = methodesTemp;
    methodesTemp = NIL(method);

	nouvClasse->constructeur = constructeurP;
    nouvClasse->super = getClasseMere(superP);
	nouvClasse->next = NIL(classe);
    nouvClasse->body = corps;
    if (!classes) initClasses();
    addClasse(nouvClasse);
    associationClasse(nouvClasse);
	return nouvClasse;
}

/* Créateur de structure methode */
methodP makeMethod(bool redefP, char* nameP, VarDeclP paramP, char* typeRetourP, TreeP bodyP) {
	methodP nouvMethode = NEW(1, method);
	nouvMethode->redef = redefP;
	nouvMethode->name = nameP;
	nouvMethode->param = paramP;
	nouvMethode->body = bodyP;
  if (!classes) initClasses();
  nouvMethode->typeRetour = idToClass(typeRetourP);
	nouvMethode->body = bodyP;
    /* TODO gérer les overrides */
	nouvMethode->next = NIL(method);
  addMethode(nouvMethode);
  addMethodeTemp(nouvMethode);
	return nouvMethode;
}

/* Créateur de structure VarDecl */
VarDeclP makeVar(bool aVar, char *name, char* type, TreeP expr){
    VarDeclP nouvVar = NEW(1, VarDecl);
    nouvVar->name = name;
    /*if (!nouvVar->type){
      printf("\n/!\\ Variable sans type /!\\\n");
      abort();
    }*/
    nouvVar->nomType = type;
    nouvVar->expr = expr;
    nouvVar->aVar = aVar;
    nouvVar->next = NIL(VarDecl);

    return nouvVar;
}

/* Créateur de structure object */
objectP makeObjet(char* name, VarDeclP attributs, methodP lmethodes){
    objectP nouvObjet = NEW(1, object);
    nouvObjet->name = name;
    nouvObjet->lmethodes = lmethodes;
    nouvObjet->attributs = attributs;
    methodesTemp = NIL(method);

    /*vidage tableau*/
    int i =0;
    while(i<indexTab-1){
            tableau[i] = NIL(method);
            i++;
    }
    indexTab = 0;

    addObjet(nouvObjet);
    associationObjet(nouvObjet);
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

void associationClasse(classeP cl){
    methodP methActuelle = cl->lmethodes;
    while(methActuelle){
        methActuelle->appartenance.classe = cl;
        methActuelle->typeRetour = idToClass(methActuelle->nomTypeRetour);
        methActuelle = methActuelle->next;
    }
    VarDeclP attributActuel = cl->attributs;
    while(attributActuel){
        attributActuel->appartenance.classe = cl;
        attributActuel->type = idToClass(attributActuel->nomType);
        attributActuel = attributActuel->next;
    }
}

void associationObjet(objectP obj){
    methodP methActuelle = obj->lmethodes;
    while(methActuelle){
        methActuelle->appartenance.objet = obj;
        methActuelle = methActuelle->next;
    }

    VarDeclP attributActuel = obj->attributs;
    while(attributActuel){
        attributActuel->appartenance.objet = obj;
        attributActuel->type = idToClass(attributActuel->nomType);
        attributActuel = attributActuel->next;
    }
}

/* Ajoute une classe dans la variable globale des classes */
void addClasse(classeP c){
    c->next = classes;
    classes = c;
}

/* Ajoute un objet dans la variable globale des objets */
void addObjet(objectP o){
    o->next = objets;
    objets = o;
}

/* Ajoute une methodes dans la variable globale des methodes */
void addMethode(methodP m){
    m->next = methodes;
    methodes = m;
    tableau[indexTab] = m;
    indexTab++;
}

void addMethodeTemp(methodP m){
    m->next = methodesTemp;
    methodesTemp = m;
}

/* Fonction de test */
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
        printf("| liste des methodes : ");
        methodP methodes = NEW(1,method);
        methodes = listClass->lmethodes;
        while(methodes != NIL(method)){
            printf(" %s (%s, %s)", methodes->name, methodes->typeRetour->name, methodes->appartenance.classe->name);
            methodes = methodes->next;
        }
        printf("\n");
        listClass = listClass->next;
    }
}

/* Fonction de test */
void affichageObjets(){
    objectP listObjet = NEW(1, object);
    listObjet = objets;
    printf("\n ---Liste des objets--- \n");
    while(listObjet != NIL(object)){
        printf("%s,",listObjet->name);
        printf("| liste des attributs : ");
        VarDeclP v = NEW(1,VarDecl);
        v = listObjet->attributs;
        while(v != NIL(VarDecl)){
            printf("%s,", v->name);
            v = v->next;
        }
        printf("| liste des methodes : ");
        methodP methodes = NEW(1,method);
        methodes = listObjet->lmethodes;
        while(methodes != NIL(method)){
            printf(" %s (%s, %s)", methodes->name, methodes->typeRetour->name, methodes->appartenance.objet->name);
            methodes = methodes->next;
        }
        printf("\n");
        listObjet = listObjet->next;

    }

}

/* Fonction de test */
void affichageMethodes(){
    methodP listMethodes = NEW(1, method);
    listMethodes = methodes;
    printf("\n ---Liste des methodes--- \n");
    while(listMethodes != NIL(method)){
        printf("%s; | classe associée : %s | typeRetour : %s\n",listMethodes->name, listMethodes->appartenance.classe->name, listMethodes->typeRetour->name);
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

/* Doublon idToClass :,( */
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

/* Prend une chaine de caractère et retourne un ptr vers la structure VarDecl ayant ce nom */
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
	printf("Variable introuvable : %s", id);
	return NIL(VarDecl);
}

/* Prend une chaine de caractère et retourne un ptr vers la structure classe ayant ce nom */
classeP idToClass(char* id){
  if (!classes){
    initClasses();
  }
  if (!id) return idToClass("Void");

  classeP classActuelle = classes;
  while (classActuelle){
    if( strcmp(classActuelle->name, id) == 0) return classActuelle;
    classActuelle = classActuelle->next;
  }
  printf("Classe introuvable : %s", id);
  return NIL(classe);
}

/* Prend une chaine de caractère et retourne un ptr la structure object ayant ce nom */
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
  printf("Objet introuvable : %s", id);
  return NIL(object);
}

/* Prend une chaine de caractère et retourne un ptr la structure methode ayant ce nom */
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
  printf("Methode introuvable : %s", id);
  return NIL(method);
}


/* Prend en entrée une étiquette et renvoie sa représentation en chaine de car */
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
        case 49 : return "ETHISSELECT";
        case 50 : return "LISTDOT";
        case 51 : return "EINST";
        case 52 : return "EADDSOLO";
        case 53 : return "ESUBSOLO";
        default : return "ERREUR";
    }

}
