Chiffre [0-9]
Entier {Chiffre}+
Lower	[a-z]
Upper	[A-Z]
Lettre	[a-zA-Z]
LC 	({Lettre}|{Chiffre})
Delim   [ \n\t\r]
BS      \\
PasBSG [^\\"]
Guill	"\""
Symbole [&();:,{}]|{Guill}|{BS}
Star  		"*"
NotStar		[^*]
NotStarPar      [^*/]
InterieurCom  ({NotStar}|({Star}+{NotStarPar}))*{Star}*
Comm 	"/*"{InterieurCom}"*/"

%{
#include <string.h>
#include <strings.h>
#include "tp.h"
#include "tp_y.h"

extern char *strdup(char *);
extern YYSTYPE yylval;
extern int yylineno;
extern int yylex();

int keywordOrId() { 
  /* A COMPLETER */
  if (! strcmp(yytext, "if")) return IF;
  if (! strcmp(yytext, "then")) return THEN;
  if (! strcmp(yytext, "else")) return ELSE; /* cc tp.y */
  if (! strcmp(yytext, "def")) return DEF;
  if (! strcmp(yytext, "var")) return VAR;
  if (! strcmp(yytext, "class")) return CLASS;
  if (! strcmp(yytext, "extends")) return EXTENDS;
  if (! strcmp(yytext, "is")) return IS;
  if (! strcmp(yytext, "return")) return RETURN;
  if (! strcmp(yytext, "this")) return THIS;
  if (! strcmp(yytext, "object")) return OBJ;
  if (! strcmp(yytext, "override")) return OVERRIDE;
  if (! strcmp(yytext, "new")) return NEW;
  yylval.S = strdup(yytext); /* S est un string */
  return(Id);
}

int keywordOrClass() { /* les objets aussi commencent par une maj */

  yylval.S = strdup(yytext); 
  return(ClassId);
}

void lexError(char c) {
  fprintf(stderr, "Error: Skipping invalid character '%c' on line %d\n",
          c, yylineno);
  setError(LEXICAL_ERROR);
}

%}

%%
{Entier} 		{ yylval.I = atoi(yytext); return(Cste); }
{Symbole}		{ return(yytext[0]); } /* peut-etre les diviser??? */

"+"				{ return(ADD); }
"-"				{ return(SUB); }
"*"				{ return(PROD); }
"/"				{ return(QUOT); }
"%"				{ return(REST); }

"."				{ return(DOT); }

{Lower}{LC}*	{ return keywordOrId(); } /* add */
{Upper}{LC}*	{ return keywordOrClass(); } /* add, c'est pas CLASS qu'il faut retourner là... => Id? */

{Delim}+		{ }
{Comm}			{ }

":="			{ return(AFF); } /* add */
"="				{ yylval.C = EQ; return(RelOp); }
"<>"			{ yylval.C = NE; return(RelOp); }
"<="			{ yylval.C = LE; return(RelOp); }
">="			{ yylval.C = GE; return(RelOp); }
">"				{ yylval.C = GT; return(RelOp); }
"<"				{ yylval.C = LT; return(RelOp); }

.				{ lexError(yytext[0]);} /* cas default; faire un return? */
%%
