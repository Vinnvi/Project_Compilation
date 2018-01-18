/* attention: NEW est defini dans tp.h Utilisez un autre nom de token */
%token IS CLASS VAR EXTENDS DEF OVERRIDE IF THEN ELSE AFF /*add*/ RETURN THIS OBJ ADD SUB PROD QUOT REST NEW DOT AND
%token<S> Id ClassId Cstr
%token<I> Cste 
%token<C> RelOp
/* indications de precedence (en ordre croissant) et d'associativite. Les
 * operateurs sur une meme ligne (separes par un espace) ont la meme priorite.
 */
%left RelOp
%left ADD SUB AND
%left REST
%left PROD QUOT
%left DOT
%{
#include "tp.h"
#include "tp_y.h"




extern int yylex();
extern void yyerror(char *);
%}

%%
Programme : DefClasseObjetOpt Bloc
;

DefClasseObjetOpt : DefClasseObjet  
|
;

DefClasseObjet : ObjetouClasse DefClasseObjet  
| ObjetouClasse
;

ObjetouClasse : Objet
| Classe
;

Objet: OBJ ClassId IS '{'ListChampOpt ListMethodeOpt'}'
;

BlocOpt : Bloc
|
;

Bloc: '{' ListInstructionsOpt '}'
| '{' ListChamp IS ListInstructions '}'
;

BlocNonVide: '{' ListInstructions '}'
| '{' ListChamp IS ListInstructions '}'
;

ListInstructionsOpt : ListInstructions
|
;

ListInstructions: Instruction ListInstructions
| Instruction
;

Instruction : Expression ';'
| RETURN ';'
| ArgumentOuCible AFF Expression ';'
| IF Valeur THEN InstIfElse ELSE InstIfElse
;

InstIfElse : Instruction ';'
| '{' ListInstructionsOpt '}'
;

Expression: '(' ClassId Expression ')'
| Instanciation
| ArgumentOuCible
| Operation
;

Valeur : ArgumentOuCible
| '('Expression')'
;

Operation : Valeur RelOp Valeur 
| Valeur ADD Valeur
| Valeur SUB Valeur
| Valeur PROD Valeur
| Valeur QUOT Valeur
| Valeur REST Valeur
| Valeur AND Valeur
;

Instanciation: NEW ClassId '(' ListArgumentsOpt ')'
;

Classe: CLASS ClassId '('ListParametreOpt')' ExtendsOpt BlocOpt IS '{'ListChampOpt ListMethodeOpt'}'
;

ListMethodeOpt : ListMethode
|
;

ListMethode : Methode ListMethode
| Methode
;

Methode : OverrideOpt DEF Id '('ListParametreOpt')' ':' ClassId AFF Expression
|  OverrideOpt DEF Id '('ListParametreOpt')' NomClasseOpt IS BlocNonVide
;

NomClasseOpt : ':' ClassId
|
;

ListParametreOpt : ListParametres 
| ListParametresDef
|
;

ListParametres : Parametre ',' ListParametres
| Parametre',' ListParametresDef
| Parametre
;

Parametre : VarOpt Id ':' ClassId
;

ListParametresDef : ParametreDef',' ListParametresDef
| ParametreDef
;

ParametreDef : VarOpt Id ':' ClassId AFF Expression
;

VarOpt: VAR
|  
;

DeclExpressionOpt : AFF Expression
| 
;

ExtendsOpt : Extends
|
;
Extends: EXTENDS ClassId '(' ListArgumentsOpt ')'
;

ListArgumentsOpt : ListArguments
|
;
ListArguments: ArgumentOuCible ',' ListArguments
| ArgumentOuCible
;
ArgumentOuCible: ListSelection
| ThisSelect
| Cste
| Cstr
| Selection
;

ThisSelect : THIS DOT ListSelection //Changement ici pour gérer ke changement du bas
| THIS DOT Selection    //Vu que ListSelection ne pouvait plus en donner 1 seul
| THIS
;

ListSelection : SelWithClassID DOT Selection //Changement ici pour prendre en compte classId
;

SelWithClassID : ListSelection
| Selection
| ClassId
;

Selection : Id
| Message
;

Message : Id '('ListArgumentsOpt')'
;

ListChampOpt : ListChamp
|
;

ListChamp : Champ ListChamp
| Champ
;

Champ : VAR Id ':' ClassId DeclExpressionOpt';'
;

OverrideOpt : OVERRIDE
|
;



