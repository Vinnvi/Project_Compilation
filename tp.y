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

Objet: OBJ Id IS BlocNonVide
;

BlocOpt : Bloc
|
;

Bloc: '{' ListInstructionsOpt '}'
| '{' ListVariables IS ListInstructions '}'
;

BlocNonVide: '{' ListInstructions '}'
| '{' ListVariables IS ListInstructions '}'
;

ListVariables : Champ ListVariables
| Champ
;

ListInstructionsOpt : ListInstructions
|
;

ListInstructions: Instruction ListInstructions
| Instruction
;

Instruction: Expression ';'
| Bloc
| RETURN ';'
| ArgumentOuCible AFF Expression ';'
| IF Valeur THEN Instruction ELSE Instruction
;

Expression: '(' Expression ')'
| '(' ClassId Expression ')'
| Instanciation
| ArgumentOuCible
;

Valeur : ArgumentOuCible
| '('Valeur')'
| Operation
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

NomClasseOpt : ClassId
|
;

ListParametreOpt : ListParametres
|  
;
ListParametres : Parametre',' ListParametres
| Parametre
;
Parametre: VarOpt Id ':' ClassId DeclExpressionOpt
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



