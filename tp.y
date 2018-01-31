/* attention: NEW est defini dans tp.h Utilisez un autre nom de token */
%token IS CLASS VAR EXTENDS DEF OVERRIDE IF THEN ELSE AFF /*add*/ RETURN OBJ ADD SUB PROD QUOT REST NEW DOT AND
%token<S> Id ClassId Cstr
%token<I> Cste
%token<C> RelOp
/* Pointeur vers classe */
%token<ClasseP> THIS
%type<B> OverrideOpt VarOpt
%type<S> NomClasseOpt
/* Pointeur vers méthode (methodP) */
%type<MethP>  Methode ListMethodeOpt ListMethode
/* Pointeur vers classe (classP) */
%type<ClasseP> Classe
/* Pointeur vers objet (objectP) */
%type<ObjetP> Objet
/* Pointeur vers Tree (TreeP) */
%type<pT> ListInstructions ListInstructionsOpt Instruction InstIfElse BlocOpt Bloc BlocNonVide DeclExpressionOpt Expression ListSelection Selection SelWithClassID Operation Message ThisSelect DefClasseObjetOpt DefClasseObjet ArgumentOuCible Instanciation Extends ExtendsOpt ListArgumentsOpt ListArguments CorpsClasse ObjetouClasse
/* Pointeur vers VarDecl */
%type<pV> Parametre ParametreDef Champ ListChamp ListChampOpt  ListParametresDef ListParametreOpt ListParametres

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
Programme : DefClasseObjetOpt Bloc { lancerCompilation($1, $2); }
;

DefClasseObjetOpt : DefClasseObjet   {$$ = $1;}
|                                    {$$ = NIL(Tree);}
;

DefClasseObjet : ObjetouClasse DefClasseObjet   {$$ = makeTree(LCLASS, 2, $1, $2);}
| ObjetouClasse                                 {$$ = makeTree(LOBJET, 1, $1);}
;

ObjetouClasse : Objet   {$$ = makeTree(EDEFOBJ, 1, $1);}
| Classe                {$$ = makeTree(EDEFCLASS, 1, $1);}
;

Objet: OBJ ClassId IS '{'ListChampOpt ListMethodeOpt'}' {$$ = makeObjet($2,$5,$6); }
;

BlocOpt : Bloc  {$$ = $1;}
|               { $$ = NIL(Tree); }
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
| RETURN ';'                                        {$$ = makeLeafStr(ERETURN, "return");}
| ArgumentOuCible AFF Expression ';'                {$$ = makeTree(EAFF, 2, $1, $3);}
| IF Operation THEN InstIfElse ELSE InstIfElse      {$$ = makeTree(ITE, 3, $2, $4, $6);}
;

InstIfElse : Instruction    {$$ = $1;}
| Bloc                      {$$ = makeTree(EBLOC, 1, $1);}
;

Expression: Instanciation   {$$ = makeTree(EINST, 1, $1);}
| Operation                 {$$ = $1;}
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
| ArgumentOuCible                               {$$ = $1;}
;

Instanciation: NEW ClassId '(' ListArgumentsOpt ')' {$$ = makeTree(ENEW, 2, $2, $4);}
;

Classe: CLASS ClassId '('ListParametreOpt')' ExtendsOpt BlocOpt IS CorpsClasse { $$ = makeClass($2, $4, $6, $7, $9); }
;

CorpsClasse : '{'ListChampOpt ListMethodeOpt'}'     {$$ = makeTree(ECORPS, 2, $2, $3);}
;

ListMethodeOpt : ListMethode    {$$ = $1;}
|                               {$$ = NIL(method);}
;

ListMethode : Methode ListMethode   {$$ = $1; $1->next = $2;}
| Methode                           {$$ = $1; $1->next = NIL(method);}
;

Methode : OverrideOpt DEF Id '('ListParametreOpt')' ':' ClassId AFF Expression  { $$ = makeMethod($1, $3, $5, $8, $10); }
|  OverrideOpt DEF Id '('ListParametreOpt')' NomClasseOpt IS BlocNonVide        { $$ = makeMethod($1, $3, $5, $7, $9); }
;

NomClasseOpt : ':' ClassId  {$$ = $2;}
|                           {$$ = NIL(char);}
;

ListParametreOpt : ListParametres   {$$ = $1;}
| ListParametresDef                 {$$ = $1;}
|                                   {$$ = NIL(VarDecl);}
;

ListParametres : Parametre ',' ListParametres       {$$ = $1; $1->next = $3;}
| Parametre',' ListParametresDef                    {$$ = $1; $1->next = $3;}
| Parametre                                         {$$ = $1;}
;

Parametre : VarOpt Id ':' ClassId {$$ = makeVar($1,$2,$4,NIL(Tree));}
;

ListParametresDef : ParametreDef',' ListParametresDef   {$$ = $1; $1->next = $3;}
| ParametreDef                                          {$$ = $1;}
;

ParametreDef : VarOpt Id ':' ClassId AFF Expression     {$$ = makeVar($1,$2,$4,$6);}
;

VarOpt: VAR     {$$ = TRUE;}
|               {$$ = FALSE;}
;

DeclExpressionOpt : AFF Expression      {$$ = makeTree(EAFF, 1, $2);}
|                                       {$$ = NIL(Tree);}
;

ExtendsOpt : Extends    {$$ = $1;}
|                       {$$ = NIL(Tree);}
;
Extends: EXTENDS ClassId '(' ListArgumentsOpt ')' { $$ = makeTree(EEXTND, 2, makeLeafStr(EIDCLASS, $2), $4); }
;

ListArgumentsOpt : ListArguments    {$$ = $1;}
|                                   {$$ = NULL;}
;
ListArguments: Expression ',' ListArguments     {$$ = makeTree(LARG, 2, $1, $3);}
| Expression                                    {$$ = $1;}
;
ArgumentOuCible: ListSelection  {$$ = makeTree(EDOT,1,$1);}
| ThisSelect                    {$$ = makeTree(ETHISSELECT,1,$1);}
| Cste                          {$$ = makeLeafInt(CSTE, $1);}
| Selection                     {$$ = $1;}
;

ThisSelect : THIS DOT ListSelection             { $$ = makeTree(LISTDOT, 2, $1, $3); }
| THIS DOT Selection                            { $$ = makeTree(EDOT, 2, $1, $3); }
| THIS                                          { $$ = makeLeafStr(ETHIS, "this"); }
;

ListSelection : SelWithClassID DOT Selection    {$$ = makeTree(EDOT, 2, $1, $3);}
;

SelWithClassID : ListSelection      {$$ = makeTree(LSEL,1,$1);}
| Selection                         {$$ = $1;}
| ClassId                           {$$ = makeLeafStr(CLASS, $1);}
;

Selection : Id                  {$$ = makeLeafStr(EID, $1);}
| Message                       {$$ = $1;}
| Cstr                          {$$ = makeLeafStr(CSTR, $1);}
| '('Expression')'              {$$ = makeTree(EEXPR, 1, $2);}
| '(' ClassId Expression ')'    {$$ = makeTree(CAST, 2, $2, $3);}
;

Message : Id '('ListArgumentsOpt')' {$$ = makeTree(MSG, 2, $1, $3);}
;

ListChampOpt : ListChamp    {$$ = $1;}
|                           {$$ = NIL(VarDecl);}
;

ListChamp : Champ ListChamp     {$$ = $1; $1->next = $2;}
| Champ                         {$$ = $1;}
;

Champ : VAR Id ':' ClassId DeclExpressionOpt';' {$$ = makeVar(TRUE,$2,$4,$5);}
;

OverrideOpt : OVERRIDE      {$$ = TRUE;}
|                           {$$ = FALSE;}
;
