/* attention: NEW est defini dans tp.h Utilisez un autre nom de token */
%token IS CLASS VAR EXTENDS DEF OVERRIDE IF THEN ELSE AFF /*add*/ RETURN THIS OBJ ADD SUB PROD QUOT REST NEW DOT
%token<S> Id ClassId Cstr
%token<I> Cste 
%token<C> RelOp
/* indications de precedence (en ordre croissant) et d'associativite. Les
 * operateurs sur une meme ligne (separes par un espace) ont la meme priorite.
 */
%left RelOp
%left ADD SUB
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
| IF Valeur THEN Instruction ELSE Instruction
;

Expression:| '(' ClassId Expression ')'
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
| Cstr RelOp Cstr
| Valeur PROD Valeur
| Valeur QUOT Valeur
| Valeur REST Valeur
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

ListParametreOpt : ListParametres','ListParametresDef
| ListParametres
| ListParametresDef
|  
;

ListParametres : ListParametres',' Parametre
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
;

ThisSelect : THIS DOT ListSelection
| THIS
;

ListSelection : ListSelection DOT Selection
| Selection
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



