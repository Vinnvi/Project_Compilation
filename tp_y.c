/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 29 "tp.y" /* yacc.c:339  */

#include "tp.h"
#include "tp_y.h"




extern int yylex();
extern void yyerror(char *);

#line 77 "tp_y.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "tp_y.h".  */
#ifndef YY_YY_TP_Y_H_INCLUDED
# define YY_YY_TP_Y_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IS = 258,
    CLASS = 259,
    VAR = 260,
    EXTENDS = 261,
    DEF = 262,
    OVERRIDE = 263,
    IF = 264,
    THEN = 265,
    ELSE = 266,
    AFF = 267,
    RETURN = 268,
    OBJ = 269,
    ADD = 270,
    SUB = 271,
    PROD = 272,
    QUOT = 273,
    REST = 274,
    NEW = 275,
    DOT = 276,
    AND = 277,
    Id = 278,
    ClassId = 279,
    Cstr = 280,
    Cste = 281,
    RelOp = 282,
    THIS = 283
  };
#endif

/* Value type.  */


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_TP_Y_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 152 "tp_y.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   219

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  173

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,     2,     2,    35,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    34,    31,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,    30,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    41,    41,    44,    45,    48,    49,    52,    53,    56,
      59,    60,    63,    64,    67,    68,    71,    72,    75,    76,
      79,    80,    81,    82,    85,    86,    89,    90,    93,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   108,
     111,   114,   117,   118,   121,   122,   125,   126,   129,   130,
     133,   134,   135,   138,   139,   140,   143,   146,   147,   150,
     153,   154,   157,   158,   161,   162,   164,   167,   168,   170,
     171,   173,   174,   175,   176,   179,   180,   181,   184,   187,
     188,   189,   192,   193,   194,   195,   196,   199,   202,   203,
     206,   207,   210,   213,   214
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IS", "CLASS", "VAR", "EXTENDS", "DEF",
  "OVERRIDE", "IF", "THEN", "ELSE", "AFF", "RETURN", "OBJ", "ADD", "SUB",
  "PROD", "QUOT", "REST", "NEW", "DOT", "AND", "Id", "ClassId", "Cstr",
  "Cste", "RelOp", "THIS", "'{'", "'}'", "';'", "'('", "')'", "':'", "','",
  "$accept", "Programme", "DefClasseObjetOpt", "DefClasseObjet",
  "ObjetouClasse", "Objet", "BlocOpt", "Bloc", "BlocNonVide",
  "ListInstructionsOpt", "ListInstructions", "Instruction", "InstIfElse",
  "Expression", "Valeur", "Operation", "Instanciation", "Classe",
  "CorpsClasse", "ListMethodeOpt", "ListMethode", "Methode",
  "NomClasseOpt", "ListParametreOpt", "ListParametres", "Parametre",
  "ListParametresDef", "ParametreDef", "VarOpt", "DeclExpressionOpt",
  "ExtendsOpt", "Extends", "ListArgumentsOpt", "ListArguments",
  "ArgumentOuCible", "ThisSelect", "ListSelection", "SelWithClassID",
  "Selection", "Message", "ListChampOpt", "ListChamp", "Champ",
  "OverrideOpt", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   123,
     125,    59,    40,    41,    58,    44
};
# endif

#define YYPACT_NINF -76

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-76)))

#define YYTABLE_NINF -95

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,   -18,     5,    23,    16,   -76,     8,   -76,   -76,     1,
      34,   -76,    15,   -76,   -76,     4,    32,    29,   145,    36,
     145,   145,    56,    52,   -76,   -76,   -76,    65,    95,    58,
     -76,    74,    60,   -76,    -1,   -76,    80,   -76,    72,    82,
      84,   -76,    92,    96,   -76,    75,   -76,    77,   -76,    78,
      93,    96,    73,   115,   -76,   -76,   126,   126,    90,   131,
     142,   131,   103,   -76,   -76,   -76,   145,   145,   145,   145,
     145,   145,   145,   131,    19,    74,   -76,   120,   123,   123,
     105,    42,   -76,   116,    53,   131,    94,   117,   -76,    72,
      84,   129,   -76,   126,   126,   -76,   -76,    57,   126,   163,
     118,   -76,   134,   124,    16,   -76,   -76,   -76,   -76,   149,
     151,   -76,   146,   -76,    42,   176,   172,   -76,   -76,   175,
     154,   131,   -76,   -76,   -76,   -76,   156,   186,   -76,   157,
     178,   -76,   -76,   169,   131,   162,    53,   -76,   -76,   131,
     165,   171,   131,   164,   -76,   -76,   -76,   166,    96,   -76,
     178,   -76,     4,   -76,    42,   167,   168,   170,   -76,   173,
     198,   190,   174,   131,    15,   -76,   -76,   177,   202,   -76,
      74,   179,   -76
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,     3,     6,     7,     8,     0,
       0,     1,    17,     2,     5,    52,     0,     0,     0,     0,
       0,     0,     0,    82,    81,    84,    73,    77,     0,     0,
      16,    19,     0,    38,    27,    26,    28,    72,    71,     0,
      74,    83,     0,    91,    60,     0,    50,    55,    51,    58,
       0,    89,     0,     0,    28,    21,    36,    37,     0,    68,
       0,    81,     0,    12,    18,    20,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    90,    65,    61,    61,
       0,    43,    88,     0,     0,    68,    70,     0,    67,    75,
      76,     0,    85,    30,    31,    32,    33,    34,    35,    29,
       0,    78,     0,     0,    11,    64,    53,    54,    57,     0,
       0,    93,     0,    42,    45,     0,    63,    25,    24,     0,
       0,     0,    87,    86,    22,    13,     0,     0,    10,     0,
      56,     9,    44,     0,     0,     0,     0,    39,    69,    68,
       0,     0,     0,     0,    62,    92,    23,     0,    89,    40,
       0,    59,    52,    66,    43,     0,     0,    49,    41,     0,
       0,    48,     0,     0,     0,    47,    46,     0,     0,    14,
       0,     0,    15
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   -76,   200,   -76,   -76,   -76,     0,   -76,   -76,
     -29,   -71,    76,   -25,   -76,   -13,   -76,   -76,   -76,    54,
      97,   -76,   -76,    61,   132,   -76,    -8,   -76,   135,   -76,
     -76,   -76,   -75,    98,   -12,   -76,   155,   -76,   -49,   -76,
      68,   -11,   -76,   -76
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,   127,   117,   165,    29,
      30,    31,   119,    32,    33,    34,    35,     8,   149,   112,
     113,   114,   160,    45,    46,    47,    48,    49,    50,   135,
     104,   105,    87,    88,    54,    37,    38,    39,    40,    41,
      81,    82,    43,   115
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,    42,    64,    62,    13,    53,     9,    56,    57,    44,
     120,    90,     1,   118,    66,    67,    68,    69,    70,    36,
      17,    71,     2,    11,    18,   101,    72,   -61,    19,    10,
      20,    21,    76,    15,    86,    22,    91,    16,    23,    24,
      25,    26,    23,    27,    25,    12,   102,    28,   100,   -94,
     111,    28,    52,    93,    94,    95,    96,    97,    98,    99,
      86,    51,    18,    36,   147,   118,    19,    55,    20,    21,
     107,   108,    36,    22,    68,    69,    23,    24,    25,    26,
      58,    27,    12,    18,    59,    28,    60,    19,    63,    20,
      21,    65,    73,   -79,    22,    75,    86,    23,    24,    25,
      26,    17,    27,    74,   128,   -80,    28,    83,    77,   144,
      20,    21,    78,    79,    86,    22,    80,   151,    23,    61,
      25,    26,    85,    27,    36,    84,   103,    28,    44,   121,
      66,    67,    68,    69,    70,   167,    92,    71,   166,   110,
     116,   171,    72,    68,    69,    70,    20,    21,   126,   124,
     122,    22,    36,   168,    23,    24,    25,    26,    36,    27,
      20,    21,   123,    28,   125,    23,    24,    25,    23,    24,
      25,    26,   129,    27,    28,   130,   131,    28,    66,    67,
      68,    69,    70,   133,   134,    71,   136,   137,   139,   140,
     142,   141,   143,   145,   148,   150,   152,   161,   158,   153,
     157,   162,   163,   164,   159,   170,    14,   169,   156,   172,
     106,   132,   146,   155,   109,    89,   154,     0,     0,   138
};

static const yytype_int16 yycheck[] =
{
      12,    12,    31,    28,     4,    18,    24,    20,    21,     5,
      85,    60,     4,    84,    15,    16,    17,    18,    19,    31,
       5,    22,    14,     0,     9,    74,    27,    23,    13,    24,
      15,    16,    43,    32,    59,    20,    61,     3,    23,    24,
      25,    26,    23,    28,    25,    29,    75,    32,    73,     7,
       8,    32,    23,    66,    67,    68,    69,    70,    71,    72,
      85,    29,     9,    75,   139,   136,    13,    31,    15,    16,
      78,    79,    84,    20,    17,    18,    23,    24,    25,    26,
      24,    28,    29,     9,    32,    32,    21,    13,    30,    15,
      16,    31,    12,    21,    20,     3,   121,    23,    24,    25,
      26,     5,    28,    21,   104,    21,    32,    34,    33,   134,
      15,    16,    35,    35,   139,    20,    23,   142,    23,    24,
      25,    26,    32,    28,   136,    10,     6,    32,     5,    35,
      15,    16,    17,    18,    19,   164,    33,    22,   163,    34,
      24,   170,    27,    17,    18,    19,    15,    16,    24,    31,
      33,    20,   164,   164,    23,    24,    25,    26,   170,    28,
      15,    16,    33,    32,    30,    23,    24,    25,    23,    24,
      25,    26,    23,    28,    32,    24,    30,    32,    15,    16,
      17,    18,    19,     7,    12,    22,    11,    33,    32,     3,
      12,    34,    23,    31,    29,    24,    32,    24,    30,    33,
      33,     3,    12,    29,    34,     3,     6,    30,   154,    30,
      78,   114,   136,   152,    79,    60,   148,    -1,    -1,   121
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    14,    37,    38,    39,    40,    41,    53,    24,
      24,     0,    29,    43,    39,    32,     3,     5,     9,    13,
      15,    16,    20,    23,    24,    25,    26,    28,    32,    45,
      46,    47,    49,    50,    51,    52,    70,    71,    72,    73,
      74,    75,    77,    78,     5,    59,    60,    61,    62,    63,
      64,    29,    23,    51,    70,    31,    51,    51,    24,    32,
      21,    24,    49,    30,    46,    31,    15,    16,    17,    18,
      19,    22,    27,    12,    21,     3,    77,    33,    35,    35,
      23,    76,    77,    34,    10,    32,    49,    68,    69,    72,
      74,    49,    33,    51,    51,    51,    51,    51,    51,    51,
      49,    74,    46,     6,    66,    67,    60,    62,    62,    64,
      34,     8,    55,    56,    57,    79,    24,    43,    47,    48,
      68,    35,    33,    33,    31,    30,    24,    42,    43,    23,
      24,    30,    56,     7,    12,    65,    11,    33,    69,    32,
       3,    34,    12,    23,    49,    31,    48,    68,    29,    54,
      24,    49,    32,    33,    76,    59,    55,    33,    30,    34,
      58,    24,     3,    12,    29,    44,    49,    46,    77,    30,
       3,    46,    30
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    40,    40,    41,
      42,    42,    43,    43,    44,    44,    45,    45,    46,    46,
      47,    47,    47,    47,    48,    48,    49,    49,    50,    51,
      51,    51,    51,    51,    51,    51,    51,    51,    51,    52,
      53,    54,    55,    55,    56,    56,    57,    57,    58,    58,
      59,    59,    59,    60,    60,    60,    61,    62,    62,    63,
      64,    64,    65,    65,    66,    66,    67,    68,    68,    69,
      69,    70,    70,    70,    70,    71,    71,    71,    72,    73,
      73,    73,    74,    74,    74,    74,    74,    75,    76,    76,
      77,    77,    78,    79,    79
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,     1,     1,     1,     7,
       1,     0,     3,     5,     3,     5,     1,     0,     2,     1,
       2,     2,     4,     6,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     1,     5,
       9,     4,     1,     0,     2,     1,    10,     9,     2,     0,
       1,     1,     0,     3,     3,     1,     4,     3,     1,     6,
       1,     0,     2,     0,     1,     0,     5,     1,     0,     3,
       1,     1,     1,     1,     1,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     3,     4,     4,     1,     0,
       2,     1,     6,     1,     0
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 41 "tp.y" /* yacc.c:1646  */
    { lancerCompilation((yyvsp[-1].pT), (yyvsp[0].pT)); }
#line 1364 "tp_y.c" /* yacc.c:1646  */
    break;

  case 3:
#line 44 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1370 "tp_y.c" /* yacc.c:1646  */
    break;

  case 4:
#line 45 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = NIL(Tree);}
#line 1376 "tp_y.c" /* yacc.c:1646  */
    break;

  case 5:
#line 48 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(LCLASS, 2, (yyvsp[-1].pT), (yyvsp[0].pT));}
#line 1382 "tp_y.c" /* yacc.c:1646  */
    break;

  case 6:
#line 49 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(LOBJET, 1, (yyvsp[0].pT));}
#line 1388 "tp_y.c" /* yacc.c:1646  */
    break;

  case 7:
#line 52 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EDEFOBJ, 1, (yyvsp[0].ObjetP));}
#line 1394 "tp_y.c" /* yacc.c:1646  */
    break;

  case 8:
#line 53 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EDEFCLASS, 1, (yyvsp[0].ClasseP));}
#line 1400 "tp_y.c" /* yacc.c:1646  */
    break;

  case 9:
#line 56 "tp.y" /* yacc.c:1646  */
    {(yyval.ObjetP) = makeObjet((yyvsp[-5].S),(yyvsp[-2].pV),(yyvsp[-1].MethP)); }
#line 1406 "tp_y.c" /* yacc.c:1646  */
    break;

  case 10:
#line 59 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1412 "tp_y.c" /* yacc.c:1646  */
    break;

  case 11:
#line 60 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = NIL(Tree); }
#line 1418 "tp_y.c" /* yacc.c:1646  */
    break;

  case 12:
#line 63 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(EBLOC, 2, (yyvsp[-1].pT), NIL(Tree)); }
#line 1424 "tp_y.c" /* yacc.c:1646  */
    break;

  case 13:
#line 64 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(EBLOC, 2, (yyvsp[-3].pV), (yyvsp[-1].pT)); }
#line 1430 "tp_y.c" /* yacc.c:1646  */
    break;

  case 14:
#line 67 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[-1].pT);}
#line 1436 "tp_y.c" /* yacc.c:1646  */
    break;

  case 15:
#line 68 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(EBLOC, 2, (yyvsp[-3].pV), (yyvsp[-1].pT));   }
#line 1442 "tp_y.c" /* yacc.c:1646  */
    break;

  case 16:
#line 71 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1448 "tp_y.c" /* yacc.c:1646  */
    break;

  case 17:
#line 72 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = NIL(Tree);}
#line 1454 "tp_y.c" /* yacc.c:1646  */
    break;

  case 18:
#line 75 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(LINST, 2, (yyvsp[-1].pT), (yyvsp[0].pT));}
#line 1460 "tp_y.c" /* yacc.c:1646  */
    break;

  case 19:
#line 76 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1466 "tp_y.c" /* yacc.c:1646  */
    break;

  case 20:
#line 79 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[-1].pT);}
#line 1472 "tp_y.c" /* yacc.c:1646  */
    break;

  case 21:
#line 80 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeLeafStr(ERETURN, "return");}
#line 1478 "tp_y.c" /* yacc.c:1646  */
    break;

  case 22:
#line 81 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EAFF, 2, (yyvsp[-3].pT), (yyvsp[-1].pT));}
#line 1484 "tp_y.c" /* yacc.c:1646  */
    break;

  case 23:
#line 82 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(ITE, 3, (yyvsp[-4].pT), (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1490 "tp_y.c" /* yacc.c:1646  */
    break;

  case 24:
#line 85 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1496 "tp_y.c" /* yacc.c:1646  */
    break;

  case 25:
#line 86 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1502 "tp_y.c" /* yacc.c:1646  */
    break;

  case 26:
#line 89 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1508 "tp_y.c" /* yacc.c:1646  */
    break;

  case 27:
#line 90 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1514 "tp_y.c" /* yacc.c:1646  */
    break;

  case 28:
#line 93 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1520 "tp_y.c" /* yacc.c:1646  */
    break;

  case 29:
#line 96 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(yylval.C, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1526 "tp_y.c" /* yacc.c:1646  */
    break;

  case 30:
#line 97 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EADD, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1532 "tp_y.c" /* yacc.c:1646  */
    break;

  case 31:
#line 98 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(ESUB, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1538 "tp_y.c" /* yacc.c:1646  */
    break;

  case 32:
#line 99 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EMUL, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1544 "tp_y.c" /* yacc.c:1646  */
    break;

  case 33:
#line 100 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EQUOT, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1550 "tp_y.c" /* yacc.c:1646  */
    break;

  case 34:
#line 101 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EREST, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1556 "tp_y.c" /* yacc.c:1646  */
    break;

  case 35:
#line 102 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EAND, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1562 "tp_y.c" /* yacc.c:1646  */
    break;

  case 36:
#line 103 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EADD, 1, (yyvsp[0].pT));}
#line 1568 "tp_y.c" /* yacc.c:1646  */
    break;

  case 37:
#line 104 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(ESUB, 1, (yyvsp[0].pT));}
#line 1574 "tp_y.c" /* yacc.c:1646  */
    break;

  case 38:
#line 105 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1580 "tp_y.c" /* yacc.c:1646  */
    break;

  case 39:
#line 108 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(ENEW, 2, (yyvsp[-3].S), (yyvsp[-1].pT));}
#line 1586 "tp_y.c" /* yacc.c:1646  */
    break;

  case 40:
#line 111 "tp.y" /* yacc.c:1646  */
    { (yyval.ClasseP) = makeClass((yyvsp[-7].S), (yyvsp[-5].pV), (yyvsp[-3].pT), (yyvsp[-2].pT), (yyvsp[0].pT)); }
#line 1592 "tp_y.c" /* yacc.c:1646  */
    break;

  case 41:
#line 114 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(ECORPS, 2, (yyvsp[-2].pV), (yyvsp[-1].MethP));}
#line 1598 "tp_y.c" /* yacc.c:1646  */
    break;

  case 42:
#line 117 "tp.y" /* yacc.c:1646  */
    {(yyval.MethP) = (yyvsp[0].MethP);}
#line 1604 "tp_y.c" /* yacc.c:1646  */
    break;

  case 43:
#line 118 "tp.y" /* yacc.c:1646  */
    {(yyval.MethP) = NIL(method);}
#line 1610 "tp_y.c" /* yacc.c:1646  */
    break;

  case 44:
<<<<<<< HEAD
#line 121 "tp.y" /* yacc.c:1646  */
    {(yyval.MethP) = (yyvsp[-1].MethP); /*$1->next = $2;*/}
=======
#line 123 "tp.y" /* yacc.c:1646  */
    {(yyval.MethP) = (yyvsp[-1].MethP); (yyvsp[-1].MethP)->next = (yyvsp[0].MethP);}
>>>>>>> 637f4b03ac829905824c1819f8230547e7fa31c9
#line 1616 "tp_y.c" /* yacc.c:1646  */
    break;

  case 45:
<<<<<<< HEAD
#line 122 "tp.y" /* yacc.c:1646  */
    {(yyval.MethP) = (yyvsp[0].MethP);}
=======
#line 124 "tp.y" /* yacc.c:1646  */
    {(yyval.MethP) = (yyvsp[0].MethP); (yyvsp[0].MethP)->next = NIL(method);}
>>>>>>> 637f4b03ac829905824c1819f8230547e7fa31c9
#line 1622 "tp_y.c" /* yacc.c:1646  */
    break;

  case 46:
#line 125 "tp.y" /* yacc.c:1646  */
    { (yyval.MethP) = makeMethod((yyvsp[-9].B), (yyvsp[-7].S), (yyvsp[-5].pV), (yyvsp[-2].S), (yyvsp[0].pT)); }
#line 1628 "tp_y.c" /* yacc.c:1646  */
    break;

  case 47:
#line 126 "tp.y" /* yacc.c:1646  */
    { (yyval.MethP) = makeMethod((yyvsp[-8].B), (yyvsp[-6].S), (yyvsp[-4].pV), (yyvsp[-2].S), (yyvsp[0].pT)); }
#line 1634 "tp_y.c" /* yacc.c:1646  */
    break;

  case 48:
#line 129 "tp.y" /* yacc.c:1646  */
    {(yyval.S) = (yyvsp[0].S);}
#line 1640 "tp_y.c" /* yacc.c:1646  */
    break;

  case 49:
#line 130 "tp.y" /* yacc.c:1646  */
    {(yyval.S) = NIL(char);}
#line 1646 "tp_y.c" /* yacc.c:1646  */
    break;

  case 50:
#line 133 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[0].pV);}
#line 1652 "tp_y.c" /* yacc.c:1646  */
    break;

  case 51:
#line 134 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[0].pV);}
#line 1658 "tp_y.c" /* yacc.c:1646  */
    break;

  case 52:
#line 135 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = NIL(VarDecl);}
#line 1664 "tp_y.c" /* yacc.c:1646  */
    break;

  case 53:
#line 138 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[-2].pV); (yyvsp[-2].pV)->next = (yyvsp[0].pV);}
#line 1670 "tp_y.c" /* yacc.c:1646  */
    break;

  case 54:
#line 139 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[-2].pV); (yyvsp[-2].pV)->next = (yyvsp[0].pV);}
#line 1676 "tp_y.c" /* yacc.c:1646  */
    break;

  case 55:
#line 140 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[0].pV);}
#line 1682 "tp_y.c" /* yacc.c:1646  */
    break;

  case 56:
#line 143 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = makeVar((yyvsp[-3].B),(yyvsp[-2].S),(yyvsp[0].S),NIL(Tree));}
#line 1688 "tp_y.c" /* yacc.c:1646  */
    break;

  case 57:
#line 146 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[-2].pV); (yyvsp[-2].pV)->next = (yyvsp[0].pV);}
#line 1694 "tp_y.c" /* yacc.c:1646  */
    break;

  case 58:
#line 147 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[0].pV);}
#line 1700 "tp_y.c" /* yacc.c:1646  */
    break;

  case 59:
#line 150 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = makeVar((yyvsp[-5].B),(yyvsp[-4].S),(yyvsp[-2].S),(yyvsp[0].pT));}
#line 1706 "tp_y.c" /* yacc.c:1646  */
    break;

  case 60:
#line 153 "tp.y" /* yacc.c:1646  */
    {(yyval.B) = TRUE;}
#line 1712 "tp_y.c" /* yacc.c:1646  */
    break;

  case 61:
#line 154 "tp.y" /* yacc.c:1646  */
    {(yyval.B) = FALSE;}
#line 1718 "tp_y.c" /* yacc.c:1646  */
    break;

  case 62:
#line 157 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EAFF, 1, (yyvsp[0].pT));}
#line 1724 "tp_y.c" /* yacc.c:1646  */
    break;

  case 63:
#line 158 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = NIL(Tree);}
#line 1730 "tp_y.c" /* yacc.c:1646  */
    break;

  case 64:
#line 161 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1736 "tp_y.c" /* yacc.c:1646  */
    break;

  case 65:
#line 162 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = NIL(Tree);}
#line 1742 "tp_y.c" /* yacc.c:1646  */
    break;

  case 66:
#line 164 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(EEXTND, 2, makeLeafStr(EIDCLASS, (yyvsp[-3].S)), (yyvsp[-1].pT)); }
#line 1748 "tp_y.c" /* yacc.c:1646  */
    break;

  case 67:
#line 167 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1754 "tp_y.c" /* yacc.c:1646  */
    break;

  case 68:
#line 168 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = NULL;}
#line 1760 "tp_y.c" /* yacc.c:1646  */
    break;

  case 69:
#line 170 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(LARG, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1766 "tp_y.c" /* yacc.c:1646  */
    break;

  case 70:
#line 171 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1772 "tp_y.c" /* yacc.c:1646  */
    break;

  case 71:
#line 173 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1778 "tp_y.c" /* yacc.c:1646  */
    break;

  case 72:
#line 174 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1784 "tp_y.c" /* yacc.c:1646  */
    break;

  case 73:
#line 175 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeLeafInt(CSTE, (yyvsp[0].I));}
#line 1790 "tp_y.c" /* yacc.c:1646  */
    break;

  case 74:
#line 176 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1796 "tp_y.c" /* yacc.c:1646  */
    break;

  case 75:
#line 179 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(EDOT, 2, (yyvsp[-2].ClasseP), (yyvsp[0].pT)); }
#line 1802 "tp_y.c" /* yacc.c:1646  */
    break;

  case 76:
#line 180 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(EDOT, 2, (yyvsp[-2].ClasseP), (yyvsp[0].pT)); }
#line 1808 "tp_y.c" /* yacc.c:1646  */
    break;

  case 77:
#line 181 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeLeafStr(ETHIS, "this"); }
#line 1814 "tp_y.c" /* yacc.c:1646  */
    break;

  case 78:
#line 184 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EDOT, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1820 "tp_y.c" /* yacc.c:1646  */
    break;

  case 79:
#line 187 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1826 "tp_y.c" /* yacc.c:1646  */
    break;

  case 80:
#line 188 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1832 "tp_y.c" /* yacc.c:1646  */
    break;

  case 81:
#line 189 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeLeafStr(CLASS, (yyvsp[0].S));}
#line 1838 "tp_y.c" /* yacc.c:1646  */
    break;

  case 82:
#line 192 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeLeafStr(EID, (yyvsp[0].S));}
#line 1844 "tp_y.c" /* yacc.c:1646  */
    break;

  case 83:
#line 193 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1850 "tp_y.c" /* yacc.c:1646  */
    break;

  case 84:
#line 194 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeLeafStr(CSTR, (yyvsp[0].S));}
#line 1856 "tp_y.c" /* yacc.c:1646  */
    break;

  case 85:
#line 195 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[-1].pT);}
#line 1862 "tp_y.c" /* yacc.c:1646  */
    break;

  case 86:
#line 196 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(CAST, 2, (yyvsp[-2].S), (yyvsp[-1].pT));}
#line 1868 "tp_y.c" /* yacc.c:1646  */
    break;

  case 87:
#line 199 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(MSG, 2, (yyvsp[-3].S), (yyvsp[-1].pT));}
#line 1874 "tp_y.c" /* yacc.c:1646  */
    break;

  case 88:
#line 202 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[0].pV);}
#line 1880 "tp_y.c" /* yacc.c:1646  */
    break;

  case 89:
#line 203 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = NIL(VarDecl);}
#line 1886 "tp_y.c" /* yacc.c:1646  */
    break;

  case 90:
#line 206 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[-1].pV); (yyvsp[-1].pV)->next = (yyvsp[0].pV);}
#line 1892 "tp_y.c" /* yacc.c:1646  */
    break;

  case 91:
#line 207 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[0].pV);}
#line 1898 "tp_y.c" /* yacc.c:1646  */
    break;

  case 92:
#line 210 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = makeVar(TRUE,(yyvsp[-4].S),(yyvsp[-2].S),(yyvsp[-1].pT));}
#line 1904 "tp_y.c" /* yacc.c:1646  */
    break;

  case 93:
#line 213 "tp.y" /* yacc.c:1646  */
    {(yyval.B) = TRUE;}
#line 1910 "tp_y.c" /* yacc.c:1646  */
    break;

  case 94:
#line 214 "tp.y" /* yacc.c:1646  */
    {(yyval.B) = FALSE;}
#line 1916 "tp_y.c" /* yacc.c:1646  */
    break;


#line 1920 "tp_y.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
