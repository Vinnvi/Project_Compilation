/* attention: NEW est defini dans tp.h Utilisez un autre nom de token */
%token IS CLASS VAR EXTENDS DEF OVERRIDE IF THEN ELSE AFF /*add*/ RETURN OBJ ADD SUB PROD QUOT REST NEW DOT AND
%token<S> Id ClassId Cstr THIS
%token<I> Cste 
%token<C> RelOp

/* Pointeur vers Tree */
%type<pT> ListInstructions ListInstructionsOpt Instruction InstIfElse BlocOpt Bloc BlocNonVide DeclExpressionOpt Expression ListSelection Selection SelWithClassID Operation Message ThisSelect DefClasseObjetOpt DefClasseObjet ArgumentOuCible Valeur Instanciation Extends ExtendsOpt ListArgumentsOpt ListArguments Parametre ParametreDef Champ ListChamp ListChampOpt  ListParametresDef ListParametreOpt ListParametres ObjetouClasse Objet Classe Methode ListMethodeOpt ListMethode NomClasseOpt OverrideOpt VarOpt Programme 


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
Programme : DefClasseObjetOpt Bloc { $$ = makeTree(EPROG, 2, $1, $2); /*affichageArbre($$, 0);*/ }
;

DefClasseObjetOpt : DefClasseObjet   {$$ = $1;}
|                                    {$$ = NIL(Tree);}
;

DefClasseObjet : ObjetouClasse DefClasseObjet   {$$ = makeTree(LCLASS, 2, $1, $2);}
| ObjetouClasse                                 {$$ = makeTree(LCLASS, 1, $1);}
;

ObjetouClasse : Objet   {$$ = $1;}
| Classe                {$$ = $1;}
;

Objet: OBJ ClassId IS '{'ListChampOpt ListMethodeOpt'}' {$$ = makeTree(EOBJ, 3, $2,$5,$6); }
;

BlocOpt : Bloc  {$$ = $1;}
|               {$$ = NIL(Tree); }
;

Bloc: '{' ListInstructionsOpt '}'           { $$ = makeTree(EBLOC, 2, $2, NIL(Tree)); } 
| '{' ListChamp IS ListInstructions '}'     { $$ = makeTree(EBLOC, 2, $2, $4); } 
;

BlocNonVide: '{' ListInstructions '}'       {$$ = $2;}
| '{' ListChamp IS ListInstructions '}'     { $$ = makeTree(EBLOC, 2, $2, $4);   } 
;

ListInstructionsOpt : ListInstructions  {$$ = $1;}
|                                       {$$ = NIL(Tree);}
;

ListInstructions: Instruction ListInstructions      {$$ = makeTree(LINST, 2, $1, $2);}
| Instruction                                       {$$ = $1;}
;

Instruction : Expression ';'                        {$$ = $1;}
| RETURN ';'                                        {$$ = makeLeafStr(ERETURN, NIL(char));}
| ArgumentOuCible AFF Expression ';'                {$$ = makeTree(EAFF, 2, $1, $3);}
| IF Operation THEN InstIfElse ELSE InstIfElse      {$$ = makeTree(ITE, 3, $2, $4, $6);}
;

InstIfElse : Instruction    {$$ = $1;}
| Bloc                      {$$ = $1;}
;

Expression: Instanciation   {$$ = $1;}
| Operation                 {$$ = $1;}   
;

Valeur : ArgumentOuCible    {$$ = $1;}
;

Operation : Operation RelOp Operation           {$$ = makeTree(yylval.C, 2, $1, $3);}
| Operation ADD Operation                       {$$ = makeTree(EADD, 2, $1, $3);}
| Operation SUB Operation                       {$$ = makeTree(ESUB, 2, $1, $3);}
| Operation PROD Operation                      {$$ = makeTree(EMUL, 2, $1, $3);}    
| Operation QUOT Operation                      {$$ = makeTree(EQUOT, 2, $1, $3);}
| Operation REST Operation                  	{$$ = makeTree(EREST, 2, $1, $3);}
| Operation AND Operation 						{$$ = makeTree(EAND, 2, $1, $3);}
| ADD Operation                                 {$$ = makeTree(EADD, 1, $2);}                                 
| SUB Operation                                 {$$ = makeTree(ESUB, 1, $2);}
| Valeur                                        {$$ = $1;}
;

Instanciation: NEW ClassId '(' ListArgumentsOpt ')' {$$ = makeTree(ENEW, 2, $2, $4);}
;

Classe: CLASS ClassId '('ListParametreOpt')' ExtendsOpt BlocOpt IS '{'ListChampOpt ListMethodeOpt'}' { $$ = makeTree(ECLASS, 6, $2, $4, $6, $7, $10, $11); } 
;

ListMethodeOpt : ListMethode    {$$ = makeTree(LMETH, 1, $1);}
|                               {$$ = NIL(Tree);}
;

ListMethode : Methode ListMethode   {$$ = makeTree(LMETH, 2, $1, $2);}
| Methode                           {$$ = makeTree(LMETH, 1, $1);}
;

Methode : OverrideOpt DEF Id '('ListParametreOpt')' ':' ClassId AFF Expression  { $$ = makeTree(EMETHOD, 5, $1, $3, $5, $8, $10); }
|  OverrideOpt DEF Id '('ListParametreOpt')' NomClasseOpt IS BlocNonVide        { $$ = makeTree(EMETHOD, 5, $1, $3, $5, $7, $9); }
;

NomClasseOpt : ':' ClassId  {$$ = makeLeafStr(ECLASS, $2);}
|                           {$$ = NIL(Tree);}
;

ListParametreOpt : ListParametres   {$$ = makeTree(LPARAM, 1, $1);}
| ListParametresDef                 {$$ = makeTree(LPARAM, 1, $1);}
|                                   {$$ = NIL(Tree);}
;

ListParametres : Parametre ',' ListParametres       {$$ = makeTree(LPARAM, 2, $1, $3);}
| Parametre',' ListParametresDef                    {$$ = makeTree(LPARAM, 2, $1, $3);}
| Parametre                                         {$$ = makeTree(LPARAM, 1, $1);}
;

Parametre : VarOpt Id ':' ClassId {$$ = makeTree(EPAR, 3, $1, $2, $4);}
;

ListParametresDef : ParametreDef',' ListParametresDef   {$$ = makeTree(LPARAM, 2, $1, $3);}
| ParametreDef                                          {$$ = makeTree(LPARAM, 1, $1);}
;

ParametreDef : VarOpt Id ':' ClassId AFF Expression     {$$ = makeTree(EPAR, 4, $1, $2, $4, $6);}
;

VarOpt: VAR     {$$ = makeLeafStr(EVAR, "var");}
|               {$$ = NIL(Tree);}
;

DeclExpressionOpt : AFF Expression      {$$ = makeTree(EAFF, 1, $2);}
|                                       {$$ = NIL(Tree);}
;

ExtendsOpt : Extends    {$$ = makeTree(EEXTND, 1, $1);}
|                       {$$ = NIL(Tree);}
;
Extends: EXTENDS ClassId '(' ListArgumentsOpt ')' { $$ = makeTree(EEXTND, 2, makeLeafStr(ID, $2), $4); }
;

ListArgumentsOpt : ListArguments    {$$ = makeTree(LARG, 1, $1);}
|                                   {$$ = NIL(Tree);}
;
ListArguments: Expression ',' ListArguments     {$$ = makeTree(LARG, 2, $1, $3);}
| Expression                                    {$$ = makeTree(LARG, 1, $1);}
;
ArgumentOuCible: ListSelection  {$$ = makeTree(EARG, 1, $1);}
| ThisSelect                    {$$ = makeTree(EARG, 1, $1);}
| Cste                          {$$ = makeLeafInt(CSTE, $1);}
| Selection                     {$$ = makeTree(EARG, 1, $1);}
;

ThisSelect : THIS DOT ListSelection             { $$ = makeTree(EDOT, 2, $1, $3); }
| THIS DOT Selection                            { $$ = makeTree(EDOT, 2, $1, $3); }                            
| THIS                                          { $$ = makeLeafStr(ETHIS, "this"); }
;

ListSelection : SelWithClassID DOT Selection    {$$ = makeTree(EDOT, 2, $1, $3);}
;

SelWithClassID : ListSelection      {$$ = makeTree(LSEL, 1, $1);}
| Selection                         {$$ = makeTree(LSEL, 1, $1);}
| ClassId                           {$$ = makeLeafStr(CLASS, $1);}
;

Selection : Id                  {$$ = makeLeafStr(ID, $1);}
| Message                       {$$ = makeTree(ESEL, 1, $1);}
| Cstr                          {$$ = makeLeafStr(CSTR, $1);}
| '('Expression')'              {$$ = makeTree(ESEL, 1, $2);}
| '(' ClassId Expression ')'    {$$ = makeTree(CAST, 2, $2, $3);}
;

Message : Id '('ListArgumentsOpt')' {$$ = makeTree(MSG, 2, $1, $3);}
;

ListChampOpt : ListChamp    {$$ = makeTree(LCHAMP, 1, $1);}
|                           {$$ = NIL(Tree);}
;

ListChamp : Champ ListChamp     {$$ = makeTree(LCHAMP, 2, $1, $2);} 
| Champ                         {$$ = makeTree(LCHAMP, 1, $1);}
;

Champ : VAR Id ':' ClassId DeclExpressionOpt';' {$$ = makeTree(CHMP, 3, $2, $4, $5);}
;

OverrideOpt : OVERRIDE      {$$ = makeLeafStr(OVER, "override");}
|                           {$$ = NIL(Tree);}
;



