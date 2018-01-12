Chiffre [0-9]
Entier {Chiffre}+
Lower	[a-z]
Upper	[A-Z]
Lettre	[a-zA-Z]
LC 	({Lettre}|{Chiffre})
Delim   [ \n\t\r]
Symbole [&();:,.{}]
BS      \\.
PasBSG [^\\"]
Guill		"\""
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
  if (! strcmp(yytext, "super")) return SUPER;
  if (! strcmp(yytext, "override")) return OVERRIDE;
  yylval.S = strdup(yytext); /* S est un string */
  return(Id);
}

int keywordOrClass() { /* les objets aussi commencent par une maj */

  if (! strcmp(yytext, "Integer")) return INT;
  if (! strcmp(yytext, "Void")) return VOID;
  if (! strcmp(yytext, "String")) return STR;
  yylval.S = strdup(yytext); 
  return(ClassId);
}
%}

%%
{Entier} 		{ yylval.I = atoi(yytext); return(Cste); }
{Symbole}		{ return(yytext[0]); } /* peut-etre les diviser??? */
"+"				{ return(ADD); }
"-"				{ return(SUB); }
"*"				{ return(PROD); }
"/"				{ return(QUOT); }

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
%%
