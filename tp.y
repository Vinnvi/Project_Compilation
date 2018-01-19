/* attention: NEW est defini dans tp.h Utilisez un autre nom de token */
%token IS CLASS VAR EXTENDS DEF OVERRIDE IF THEN ELSE AFF /*add*/ RETURN THIS OBJ ADD SUB PROD QUOT REST NEW DOT AND
%token<S> Id ClassId Cstr
%token<I> Cste 
%token<C> RelOp
/* ^ Pour chaque non terminal faut faire ça ^ */
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
| IF Operation THEN InstIfElse ELSE InstIfElse
;

InstIfElse : Instruction    {$$ = $1}
| Bloc                      {$$ = $1}
;

Expression: Instanciation   {$$ = $1}
| Operation                 {$$ = $1}   
;

Valeur : ArgumentOuCible    {$$ = $1}
;

Operation : Operation RelOp Operation           {$$ = makeTree(yylval.C, 2, $1, $3);}
| Operation ADD Operation                       {$$ = makeTree(PLUS, 2, $1, $3);}
| Operation SUB Operation                       {$$ = makeTree(MINUS, 2, $1, $3);}
| Operation PROD Operation                      {$$ = makeTree(TIMES, 2, $1, $3);}    
| Operation QUOT Operation                      {$$ = makeTree(DIV, 2, $1, $3);}
| Operation REST Operation                  	{$$ = makeTree(MOD, 2, $1, $3);}
| Operation AND Operation 						{$$ = makeTree(CONC, 2, $1, $3);}
| ADD Operation                                 {$$ = makeTree(PLUS, 1, $2);}                                 
| SUB Operation                                 {$$ = makeTree(MINUS, 1, $2);}
| Valeur                                        {$$ = $1}
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
ListArguments: Expression ',' ListArguments
| Expression
;
ArgumentOuCible: ListSelection
| ThisSelect
| Cste
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
| Cstr
| '('Expression')'
| '(' ClassId Expression ')'
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



