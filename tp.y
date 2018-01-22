/* attention: NEW est defini dans tp.h Utilisez un autre nom de token */
%token IS CLASS VAR EXTENDS DEF OVERRIDE IF THEN ELSE AFF /*add*/ RETURN THIS OBJ ADD SUB PROD QUOT REST NEW DOT AND
%token<S> Id ClassId Cstr
%token<I> Cste 
%token<C> RelOp
%type <B> OverrideOpt
%type<MethP> ListMethodeOpt ListMethode Methode
%type<ClasseP> Classe NomClasseOpt DefClasseObjetOpt DefClasseObjet ObjetouClasse
%type<ObjetP> Objet
%type<pT> ListInstructions ListInstructionsOpt Instruction InstIfElse BlocOpt Bloc BlocNonVide DeclExpressionOpt Expression ListSelection Selection SelWithClassID Operation Message Instanciation
%type<attP> Champ ListChamp ListChampOpt ListParametreOpt ListParametres Parametre ListParametresDef ParametreDef VarOpt ListArgumentsOpt ListArguments ArgumentOuCible Valeur


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

DefClasseObjetOpt : DefClasseObjet   {$$ = $1; /* Demander au prof si on fait un arbre à 1 fils ou pas besoin*/}
|                                    {$$ = NIL(class);}
;

DefClasseObjet : ObjetouClasse DefClasseObjet   {$$ = makeTree(LCLASS, 2, $1, $2);}
| ObjetouClasse                                 {$$ = $1;}
;

ObjetouClasse : Objet   {$$ = $1;}
| Classe                {$$ = $1;}
;

Objet: OBJ ClassId IS '{'ListChampOpt ListMethodeOpt'}'
;

BlocOpt : Bloc  {$$ = $1;}
|               { $$ = NIL(Tree); }
;

Bloc: '{' ListInstructionsOpt '}'           { $$ = makeTree(BLOC, 2, $2, NIL(Tree)); } //here
| '{' ListChamp IS ListInstructions '}'     { $$ = makeTree(BLOC, 2, $2, $4); } //here
;

BlocNonVide: '{' ListInstructions '}'       {$$ = $2;}
| '{' ListChamp IS ListInstructions '}'     { $$ = makeTree(BLOC, 2, makeLeafLCh(LISTCH, $2), $4);   } //here
;

ListInstructionsOpt : ListInstructions  {$$ = $1;}
|                                       {$$ = NIL(instr);}
;

ListInstructions: Instruction ListInstructions      {$$ = makeTree(LINST, 2, $1, $2);}
| Instruction                                       {$$ = $1;}
;

Instruction : Expression ';'                        {$$ = $1;}
| RETURN ';'                                        
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

Instanciation: NEW ClassId '(' ListArgumentsOpt ')' 
;

Classe: CLASS ClassId '('ListParametreOpt')' ExtendsOpt BlocOpt IS '{'ListChampOpt ListMethodeOpt'}' { $$ = makeClass($2, $4, $6, $7, $10, $11); } //here
;

ListMethodeOpt : ListMethode    {$$ = $1;}
|                               {$$ = NIL(method);}
;

ListMethode : Methode ListMethode   {$$ = makeTree(LPARAM, 2, $1, $2);}
| Methode                           {$$ = $1;}
;

Methode : OverrideOpt DEF Id '('ListParametreOpt')' ':' ClassId AFF Expression  { $$ = makeMethodExpr($1, $3, $5, $8, $10); }
|  OverrideOpt DEF Id '('ListParametreOpt')' NomClasseOpt IS BlocNonVide        { $$ = makeMethodBloc($1, $3, $5, $7, $9); }
;

NomClasseOpt : ':' ClassId  {$$ = makeLeafStr(CLASS, $2);}
|                           {$$ = NIL(class);}
;

ListParametreOpt : ListParametres   {$$ = $1;}
| ListParametresDef                 {$$ = $1;}
|                                   {$$ = NIL(varDecl);}
;

ListParametres : Parametre ',' ListParametres       {$$ = makeTree(LPARAM, 2, $1, $3);}
| Parametre',' ListParametresDef                    {$$ = makeTree(LPARAM, 2, $1, $3);}
| Parametre                                         {$$ = $1;}
;

Parametre : VarOpt Id ':' ClassId
;

ListParametresDef : ParametreDef',' ListParametresDef   {$$ = makeTree(LPARAM, 2, $1, $3);}
| ParametreDef                                          {$$ = $1;}
;

ParametreDef : VarOpt Id ':' ClassId AFF Expression
;

VarOpt: VAR     {$$ = $1;}
|               {$$ = NULL;}
;

DeclExpressionOpt : AFF Expression      {$$ = makeTree(EAFF, 1, $2); /* pas sur? un $1 = $2 suffit ptet jsute*/}
|                                       {$$ = NIL(varDecl);}
;

ExtendsOpt : Extends    {$$ = $1;}
|                       {$$ = NIL(class);}
;
Extends: EXTENDS ClassId '(' ListArgumentsOpt ')'
;

ListArgumentsOpt : ListArguments    {$$ = $1;}
|                                   {$$ = NULL;}
;
ListArguments: Expression ',' ListArguments     {$$ = makeTree(LARG, 2, $1, $3);}
| Expression                                    {$$ = $1;}
;
ArgumentOuCible: ListSelection  {$$ = $1;}
| ThisSelect                    {$$ = $1;}
| Cste                          {$$ = makeLeafInt(CSTR, $1);}
| Selection                     {$$ = $1;}
;

ThisSelect : THIS DOT ListSelection             { $$ = makeTree(, 2, $1, NIL(Tree)); }
| THIS DOT Selection                            
| THIS
;

ListSelection : SelWithClassID DOT Selection    {$$ = makeTree(EDOT, 2, $1, $3);}
;

SelWithClassID : ListSelection      {$$ = $1;}
| Selection                         {$$ = $1;}
| ClassId                           {$$ = makeLeafStr(CLASS, $1);}
;

Selection : Id                  {$$ = makeLeafInt(ID, $1);}
| Message                       {$$ = $1;}
| Cstr                          {$$ = makeLeafStr(CSTR, $1);}
| '('Expression')'              {$$ = $2;}
| '(' ClassId Expression ')'    {$$ = makeTree(CAST, 2, $2, $3);}
;

Message : Id '('ListArgumentsOpt')' {$$ = makeTree(MSG, 2, $1, $3);}
;

ListChampOpt : ListChamp    {$$ = $1;}
|                           {$$ = NIL(varDecl);}
;

ListChamp : Champ ListChamp     {$$ = makeTree(LCHAMP, 2, $1, $2);} 
| Champ                         {$$ = $1;}
;

Champ : VAR Id ':' ClassId DeclExpressionOpt';'
;

OverrideOpt : OVERRIDE      {$$ = true;}
|                           {$$ = false;}
;



