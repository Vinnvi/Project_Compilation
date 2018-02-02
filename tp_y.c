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
#line 31 "tp.y" /* yacc.c:339  */

#include "tp.h"
#include "tp_y.h"




extern int yylex();
extern void yyerror(char *);


#line 78 "tp_y.c" /* yacc.c:339  */

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

#line 153 "tp_y.c" /* yacc.c:358  */

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
#define YYLAST   209

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  92
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

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
       0,    44,    44,    47,    48,    51,    52,    55,    56,    59,
      62,    63,    66,    67,    70,    71,    74,    75,    78,    79,
      80,    81,    84,    85,    88,    89,    92,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   107,   110,   113,
     116,   117,   120,   121,   124,   125,   128,   129,   132,   133,
     134,   137,   138,   139,   142,   145,   146,   149,   152,   153,
     156,   157,   160,   161,   163,   166,   167,   169,   170,   172,
     173,   174,   175,   178,   179,   180,   183,   186,   187,   188,
     191,   192,   193,   194,   195,   198,   201,   202,   205,   206,
     209,   212,   213
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
  "ObjetouClasse", "Objet", "BlocOpt", "Bloc", "ListInstructionsOpt",
  "ListInstructions", "Instruction", "InstIfElse", "Expression", "Valeur",
  "Operation", "Instanciation", "Classe", "CorpsClasse", "ListMethodeOpt",
  "ListMethode", "Methode", "NomClasseOpt", "ListParametreOpt",
  "ListParametres", "Parametre", "ListParametresDef", "ParametreDef",
  "VarOpt", "DeclExpressionOpt", "ExtendsOpt", "Extends",
  "ListArgumentsOpt", "ListArguments", "ArgumentOuCible", "ThisSelect",
  "ListSelection", "SelWithClassID", "Selection", "Message",
  "ListChampOpt", "ListChamp", "Champ", "OverrideOpt", YY_NULLPTR
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

#define YYPACT_NINF -79

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-79)))

#define YYTABLE_NINF -93

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       9,     1,     6,    14,     2,   -79,     9,   -79,   -79,    11,
      41,   -79,    13,   -79,   -79,     4,    18,    25,   122,    19,
     122,   122,    39,    32,   -79,   -79,   -79,    46,    73,    40,
     -79,    93,    44,   -79,   158,   -79,    59,   -79,    51,    62,
      63,   -79,    77,    81,   -79,    54,   -79,    55,   -79,    56,
      69,    81,    61,   145,   -79,   -79,   134,   134,    71,   107,
     117,   107,    78,   -79,   -79,   -79,   122,   122,   122,   122,
     122,   122,   122,   107,    17,    93,   -79,    98,   105,   105,
      80,    12,   -79,    96,    53,   107,    89,    95,   -79,    51,
      63,   101,   -79,   134,   134,   -79,   -79,    -6,   134,   171,
     112,   -79,    99,   120,     2,   -79,   -79,   -79,   -79,   133,
     135,   -79,   127,   -79,    12,   159,   153,   -79,   -79,   157,
     136,   107,   -79,   -79,   -79,   -79,   138,   168,   -79,   144,
     167,   -79,   -79,   160,   107,   150,    53,   -79,   -79,   107,
     155,   170,   107,   163,   -79,   -79,   -79,   149,    81,   -79,
     167,   -79,     4,   -79,    12,   164,   161,   162,   -79,   174,
     189,   187,     2,   107,   -79,   -79
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,     3,     6,     7,     8,     0,
       0,     1,    15,     2,     5,    50,     0,     0,     0,     0,
       0,     0,     0,    80,    79,    82,    71,    75,     0,     0,
      14,    17,     0,    36,    25,    24,    26,    70,    69,     0,
      72,    81,     0,    89,    58,     0,    48,    53,    49,    56,
       0,    87,     0,     0,    26,    19,    34,    35,     0,    66,
       0,    79,     0,    12,    16,    18,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    88,    63,    59,    59,
       0,    41,    86,     0,     0,    66,    68,     0,    65,    73,
      74,     0,    83,    28,    29,    30,    31,    32,    33,    27,
       0,    76,     0,     0,    11,    62,    51,    52,    55,     0,
       0,    91,     0,    40,    43,     0,    61,    23,    22,     0,
       0,     0,    85,    84,    20,    13,     0,     0,    10,     0,
      54,     9,    42,     0,     0,     0,     0,    37,    67,    66,
       0,     0,     0,     0,    60,    90,    21,     0,    87,    38,
       0,    57,    50,    64,    41,     0,     0,    47,    39,     0,
       0,    46,     0,     0,    45,    44
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -79,   -79,   -79,   194,   -79,   -79,   -79,    -4,   -79,   -16,
     -76,    65,   -27,   -79,   -15,   -79,   -79,   -79,    48,    90,
     -79,   -79,    57,   125,   -79,   -62,   -79,   126,   -79,   -79,
     -79,   -78,    85,   -10,   -79,   147,   -79,   -50,   -79,    60,
      -8,   -79,   -79
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,   127,   117,    29,    30,
      31,   119,    32,    33,    34,    35,     8,   149,   112,   113,
     114,   160,    45,    46,    47,    48,    49,    50,   135,   104,
     105,    87,    88,    54,    37,    38,    39,    40,    41,    81,
      82,    43,   115
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    62,    36,    53,    42,    56,    57,   120,   118,    44,
      90,    68,    69,     1,    11,    64,   107,   108,    17,   -92,
     111,    36,    18,     2,   101,     9,    19,   -59,    20,    21,
      10,    12,    86,    22,    91,    76,    23,    24,    25,    26,
      23,    27,    25,    15,    16,    28,   100,    51,    52,    28,
      55,    93,    94,    95,    96,    97,    98,    99,    86,   102,
     118,   147,    18,    58,    59,    36,    19,    60,    20,    21,
      63,    73,   -77,    22,    36,    65,    23,    24,    25,    26,
      75,    27,    12,    74,   -78,    28,    17,    77,    20,    21,
      78,    79,    80,    22,    86,    83,    23,    61,    25,    26,
     128,    27,    18,    85,   103,    28,    19,   144,    20,    21,
      44,    92,    86,    22,   110,   151,    23,    24,    25,    26,
     116,    27,    20,    21,   121,    28,    36,    22,   122,   125,
      23,    24,    25,    26,   123,    27,   165,    20,    21,    28,
      23,    24,    25,   124,   126,    23,    24,    25,    26,    28,
      27,    68,    69,    70,    28,    84,   129,   131,   164,   130,
      66,    67,    68,    69,    70,   134,   133,    71,   136,   137,
     139,   140,    72,    66,    67,    68,    69,    70,   141,   142,
      71,   145,   153,   143,   148,    72,    66,    67,    68,    69,
      70,   158,   162,    71,   150,   152,   159,   157,   161,   163,
      14,   146,   156,   106,   132,   109,   138,    89,   154,   155
};

static const yytype_uint8 yycheck[] =
{
       4,    28,    12,    18,    12,    20,    21,    85,    84,     5,
      60,    17,    18,     4,     0,    31,    78,    79,     5,     7,
       8,    31,     9,    14,    74,    24,    13,    23,    15,    16,
      24,    29,    59,    20,    61,    43,    23,    24,    25,    26,
      23,    28,    25,    32,     3,    32,    73,    29,    23,    32,
      31,    66,    67,    68,    69,    70,    71,    72,    85,    75,
     136,   139,     9,    24,    32,    75,    13,    21,    15,    16,
      30,    12,    21,    20,    84,    31,    23,    24,    25,    26,
       3,    28,    29,    21,    21,    32,     5,    33,    15,    16,
      35,    35,    23,    20,   121,    34,    23,    24,    25,    26,
     104,    28,     9,    32,     6,    32,    13,   134,    15,    16,
       5,    33,   139,    20,    34,   142,    23,    24,    25,    26,
      24,    28,    15,    16,    35,    32,   136,    20,    33,    30,
      23,    24,    25,    26,    33,    28,   163,    15,    16,    32,
      23,    24,    25,    31,    24,    23,    24,    25,    26,    32,
      28,    17,    18,    19,    32,    10,    23,    30,   162,    24,
      15,    16,    17,    18,    19,    12,     7,    22,    11,    33,
      32,     3,    27,    15,    16,    17,    18,    19,    34,    12,
      22,    31,    33,    23,    29,    27,    15,    16,    17,    18,
      19,    30,     3,    22,    24,    32,    34,    33,    24,    12,
       6,   136,   154,    78,   114,    79,   121,    60,   148,   152
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    14,    37,    38,    39,    40,    41,    52,    24,
      24,     0,    29,    43,    39,    32,     3,     5,     9,    13,
      15,    16,    20,    23,    24,    25,    26,    28,    32,    44,
      45,    46,    48,    49,    50,    51,    69,    70,    71,    72,
      73,    74,    76,    77,     5,    58,    59,    60,    61,    62,
      63,    29,    23,    50,    69,    31,    50,    50,    24,    32,
      21,    24,    48,    30,    45,    31,    15,    16,    17,    18,
      19,    22,    27,    12,    21,     3,    76,    33,    35,    35,
      23,    75,    76,    34,    10,    32,    48,    67,    68,    71,
      73,    48,    33,    50,    50,    50,    50,    50,    50,    50,
      48,    73,    45,     6,    65,    66,    59,    61,    61,    63,
      34,     8,    54,    55,    56,    78,    24,    43,    46,    47,
      67,    35,    33,    33,    31,    30,    24,    42,    43,    23,
      24,    30,    55,     7,    12,    64,    11,    33,    68,    32,
       3,    34,    12,    23,    48,    31,    47,    67,    29,    53,
      24,    48,    32,    33,    75,    58,    54,    33,    30,    34,
      57,    24,     3,    12,    43,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    40,    40,    41,
      42,    42,    43,    43,    44,    44,    45,    45,    46,    46,
      46,    46,    47,    47,    48,    48,    49,    50,    50,    50,
      50,    50,    50,    50,    50,    50,    50,    51,    52,    53,
      54,    54,    55,    55,    56,    56,    57,    57,    58,    58,
      58,    59,    59,    59,    60,    61,    61,    62,    63,    63,
      64,    64,    65,    65,    66,    67,    67,    68,    68,    69,
      69,    69,    69,    70,    70,    70,    71,    72,    72,    72,
      73,    73,    73,    73,    73,    74,    75,    75,    76,    76,
      77,    78,    78
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,     1,     1,     1,     7,
       1,     0,     3,     5,     1,     0,     2,     1,     2,     2,
       4,     6,     1,     1,     1,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     2,     2,     1,     5,     9,     4,
       1,     0,     2,     1,    10,     9,     2,     0,     1,     1,
       0,     3,     3,     1,     4,     3,     1,     6,     1,     0,
       2,     0,     1,     0,     5,     1,     0,     3,     1,     1,
       1,     1,     1,     3,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     3,     4,     4,     1,     0,     2,     1,
       6,     1,     0
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
#line 44 "tp.y" /* yacc.c:1646  */
    { lancerCompilation((yyvsp[-1].pT), (yyvsp[0].pT)); }
#line 1359 "tp_y.c" /* yacc.c:1646  */
    break;

  case 3:
#line 47 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1365 "tp_y.c" /* yacc.c:1646  */
    break;

  case 4:
#line 48 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = NIL(Tree);}
#line 1371 "tp_y.c" /* yacc.c:1646  */
    break;

  case 5:
#line 51 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(LCLASS, 2, (yyvsp[-1].CouOP), (yyvsp[0].pT));}
#line 1377 "tp_y.c" /* yacc.c:1646  */
    break;

  case 6:
#line 52 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(LCLASS, 1, (yyvsp[0].CouOP));}
#line 1383 "tp_y.c" /* yacc.c:1646  */
    break;

  case 7:
#line 55 "tp.y" /* yacc.c:1646  */
    {(yyval.CouOP) = (CouOP)(yyvsp[0].ObjetP);}
#line 1389 "tp_y.c" /* yacc.c:1646  */
    break;

  case 8:
#line 56 "tp.y" /* yacc.c:1646  */
    {(yyval.CouOP) = (CouOP)(yyvsp[0].ClasseP);}
#line 1395 "tp_y.c" /* yacc.c:1646  */
    break;

  case 9:
#line 59 "tp.y" /* yacc.c:1646  */
    {(yyval.ObjetP) = makeObjet((yyvsp[-5].S),(yyvsp[-2].pV),(yyvsp[-1].MethP)); }
#line 1401 "tp_y.c" /* yacc.c:1646  */
    break;

  case 10:
#line 62 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1407 "tp_y.c" /* yacc.c:1646  */
    break;

  case 11:
#line 63 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = NIL(Tree); }
#line 1413 "tp_y.c" /* yacc.c:1646  */
    break;

  case 12:
#line 66 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(EBLOC, 2, (yyvsp[-1].pT), NIL(Tree)); }
#line 1419 "tp_y.c" /* yacc.c:1646  */
    break;

  case 13:
#line 67 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(EBLOC, 2, (yyvsp[-3].pV), (yyvsp[-1].pT)); }
#line 1425 "tp_y.c" /* yacc.c:1646  */
    break;

  case 14:
#line 70 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1431 "tp_y.c" /* yacc.c:1646  */
    break;

  case 15:
#line 71 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = NIL(Tree);}
#line 1437 "tp_y.c" /* yacc.c:1646  */
    break;

  case 16:
#line 74 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(LINST, 2, (yyvsp[-1].pT), (yyvsp[0].pT));}
#line 1443 "tp_y.c" /* yacc.c:1646  */
    break;

  case 17:
#line 75 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1449 "tp_y.c" /* yacc.c:1646  */
    break;

  case 18:
#line 78 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[-1].pT);}
#line 1455 "tp_y.c" /* yacc.c:1646  */
    break;

  case 19:
#line 79 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeLeafStr(ERETURN, "return");}
#line 1461 "tp_y.c" /* yacc.c:1646  */
    break;

  case 20:
#line 80 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EAFF, 2, (yyvsp[-3].pT), (yyvsp[-1].pT));}
#line 1467 "tp_y.c" /* yacc.c:1646  */
    break;

  case 21:
#line 81 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(ITE, 3, (yyvsp[-4].pT), (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1473 "tp_y.c" /* yacc.c:1646  */
    break;

  case 22:
#line 84 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1479 "tp_y.c" /* yacc.c:1646  */
    break;

  case 23:
#line 85 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1485 "tp_y.c" /* yacc.c:1646  */
    break;

  case 24:
#line 88 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1491 "tp_y.c" /* yacc.c:1646  */
    break;

  case 25:
#line 89 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1497 "tp_y.c" /* yacc.c:1646  */
    break;

  case 26:
#line 92 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1503 "tp_y.c" /* yacc.c:1646  */
    break;

  case 27:
#line 95 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(yylval.C, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1509 "tp_y.c" /* yacc.c:1646  */
    break;

  case 28:
#line 96 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EADD, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1515 "tp_y.c" /* yacc.c:1646  */
    break;

  case 29:
#line 97 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(ESUB, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1521 "tp_y.c" /* yacc.c:1646  */
    break;

  case 30:
#line 98 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EMUL, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1527 "tp_y.c" /* yacc.c:1646  */
    break;

  case 31:
#line 99 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EQUOT, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1533 "tp_y.c" /* yacc.c:1646  */
    break;

  case 32:
#line 100 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EREST, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1539 "tp_y.c" /* yacc.c:1646  */
    break;

  case 33:
#line 101 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EAND, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1545 "tp_y.c" /* yacc.c:1646  */
    break;

  case 34:
#line 102 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EADD, 1, (yyvsp[0].pT));}
#line 1551 "tp_y.c" /* yacc.c:1646  */
    break;

  case 35:
#line 103 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(ESUB, 1, (yyvsp[0].pT));}
#line 1557 "tp_y.c" /* yacc.c:1646  */
    break;

  case 36:
#line 104 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1563 "tp_y.c" /* yacc.c:1646  */
    break;

  case 37:
#line 107 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(ENEW, 2, (yyvsp[-3].S), (yyvsp[-1].pT));}
#line 1569 "tp_y.c" /* yacc.c:1646  */
    break;

  case 38:
#line 110 "tp.y" /* yacc.c:1646  */
    { (yyval.ClasseP) = makeClass((yyvsp[-7].S), (yyvsp[-5].pV), (yyvsp[-3].pT), (yyvsp[-2].pT), (yyvsp[0].pT)); }
#line 1575 "tp_y.c" /* yacc.c:1646  */
    break;

  case 39:
#line 113 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(ECORPS, 2, (yyvsp[-2].pV), (yyvsp[-1].MethP));}
#line 1581 "tp_y.c" /* yacc.c:1646  */
    break;

  case 40:
#line 116 "tp.y" /* yacc.c:1646  */
    {(yyval.MethP) = (yyvsp[0].MethP);}
#line 1587 "tp_y.c" /* yacc.c:1646  */
    break;

  case 41:
#line 117 "tp.y" /* yacc.c:1646  */
    {(yyval.MethP) = NIL(method);}
#line 1593 "tp_y.c" /* yacc.c:1646  */
    break;

  case 42:
#line 120 "tp.y" /* yacc.c:1646  */
    {(yyval.MethP) = (yyvsp[-1].MethP); (yyvsp[-1].MethP)->next = (yyvsp[0].MethP);}
#line 1599 "tp_y.c" /* yacc.c:1646  */
    break;

  case 43:
#line 121 "tp.y" /* yacc.c:1646  */
    {(yyval.MethP) = (yyvsp[0].MethP); (yyvsp[0].MethP)->next = NIL(method);}
#line 1605 "tp_y.c" /* yacc.c:1646  */
    break;

  case 44:
#line 124 "tp.y" /* yacc.c:1646  */
    { (yyval.MethP) = makeMethod((yyvsp[-9].B), (yyvsp[-7].S), (yyvsp[-5].pV), (yyvsp[-2].S), (yyvsp[0].pT)); }
#line 1611 "tp_y.c" /* yacc.c:1646  */
    break;

  case 45:
#line 125 "tp.y" /* yacc.c:1646  */
    { (yyval.MethP) = makeMethod((yyvsp[-8].B), (yyvsp[-6].S), (yyvsp[-4].pV), (yyvsp[-2].S), (yyvsp[0].pT)); }
#line 1617 "tp_y.c" /* yacc.c:1646  */
    break;

  case 46:
#line 128 "tp.y" /* yacc.c:1646  */
    {(yyval.S) = (yyvsp[0].S);}
#line 1623 "tp_y.c" /* yacc.c:1646  */
    break;

  case 47:
#line 129 "tp.y" /* yacc.c:1646  */
    {(yyval.S) = NIL(char);}
#line 1629 "tp_y.c" /* yacc.c:1646  */
    break;

  case 48:
#line 132 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[0].pV);}
#line 1635 "tp_y.c" /* yacc.c:1646  */
    break;

  case 49:
#line 133 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[0].pV);}
#line 1641 "tp_y.c" /* yacc.c:1646  */
    break;

  case 50:
#line 134 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = NIL(VarDecl);}
#line 1647 "tp_y.c" /* yacc.c:1646  */
    break;

  case 51:
#line 137 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[-2].pV); (yyvsp[-2].pV)->next = (yyvsp[0].pV);}
#line 1653 "tp_y.c" /* yacc.c:1646  */
    break;

  case 52:
#line 138 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[-2].pV); (yyvsp[-2].pV)->next = (yyvsp[0].pV);}
#line 1659 "tp_y.c" /* yacc.c:1646  */
    break;

  case 53:
#line 139 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[0].pV);}
#line 1665 "tp_y.c" /* yacc.c:1646  */
    break;

  case 54:
#line 142 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = makeVar((yyvsp[-3].B),(yyvsp[-2].S),(yyvsp[0].S),NIL(Tree));}
#line 1671 "tp_y.c" /* yacc.c:1646  */
    break;

  case 55:
#line 145 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[-2].pV); (yyvsp[-2].pV)->next = (yyvsp[0].pV);}
#line 1677 "tp_y.c" /* yacc.c:1646  */
    break;

  case 56:
#line 146 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[0].pV);}
#line 1683 "tp_y.c" /* yacc.c:1646  */
    break;

  case 57:
#line 149 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = makeVar((yyvsp[-5].B),(yyvsp[-4].S),(yyvsp[-2].S),(yyvsp[0].pT));}
#line 1689 "tp_y.c" /* yacc.c:1646  */
    break;

  case 58:
#line 152 "tp.y" /* yacc.c:1646  */
    {(yyval.B) = TRUE;}
#line 1695 "tp_y.c" /* yacc.c:1646  */
    break;

  case 59:
#line 153 "tp.y" /* yacc.c:1646  */
    {(yyval.B) = FALSE;}
#line 1701 "tp_y.c" /* yacc.c:1646  */
    break;

  case 60:
#line 156 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EAFF, 1, (yyvsp[0].pT));}
#line 1707 "tp_y.c" /* yacc.c:1646  */
    break;

  case 61:
#line 157 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = NIL(Tree);}
#line 1713 "tp_y.c" /* yacc.c:1646  */
    break;

  case 62:
#line 160 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1719 "tp_y.c" /* yacc.c:1646  */
    break;

  case 63:
#line 161 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = NIL(Tree);}
#line 1725 "tp_y.c" /* yacc.c:1646  */
    break;

  case 64:
#line 163 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(EEXTND, 2, makeLeafStr(EIDCLASS, (yyvsp[-3].S)), (yyvsp[-1].pT)); }
#line 1731 "tp_y.c" /* yacc.c:1646  */
    break;

  case 65:
#line 166 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1737 "tp_y.c" /* yacc.c:1646  */
    break;

  case 66:
#line 167 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = NULL;}
#line 1743 "tp_y.c" /* yacc.c:1646  */
    break;

  case 67:
#line 169 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(LARG, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1749 "tp_y.c" /* yacc.c:1646  */
    break;

  case 68:
#line 170 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1755 "tp_y.c" /* yacc.c:1646  */
    break;

  case 69:
#line 172 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1761 "tp_y.c" /* yacc.c:1646  */
    break;

  case 70:
#line 173 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1767 "tp_y.c" /* yacc.c:1646  */
    break;

  case 71:
#line 174 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeLeafInt(CSTE, (yyvsp[0].I));}
#line 1773 "tp_y.c" /* yacc.c:1646  */
    break;

  case 72:
#line 175 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1779 "tp_y.c" /* yacc.c:1646  */
    break;

  case 73:
#line 178 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(EDOTHIS, 2, (yyvsp[-2].ClasseP), (yyvsp[0].pT)); }
#line 1785 "tp_y.c" /* yacc.c:1646  */
    break;

  case 74:
#line 179 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(EDOTHIS, 2, (yyvsp[-2].ClasseP), (yyvsp[0].pT)); }
#line 1791 "tp_y.c" /* yacc.c:1646  */
    break;

  case 75:
#line 180 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeLeafStr(ETHIS, "this"); }
#line 1797 "tp_y.c" /* yacc.c:1646  */
    break;

  case 76:
#line 183 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EDOT, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1803 "tp_y.c" /* yacc.c:1646  */
    break;

  case 77:
#line 186 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1809 "tp_y.c" /* yacc.c:1646  */
    break;

  case 78:
#line 187 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1815 "tp_y.c" /* yacc.c:1646  */
    break;

  case 79:
#line 188 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeLeafStr(CLASS, (yyvsp[0].S));}
#line 1821 "tp_y.c" /* yacc.c:1646  */
    break;

  case 80:
#line 191 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeLeafStr(EID, (yyvsp[0].S));}
#line 1827 "tp_y.c" /* yacc.c:1646  */
    break;

  case 81:
#line 192 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1833 "tp_y.c" /* yacc.c:1646  */
    break;

  case 82:
#line 193 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeLeafStr(CSTR, (yyvsp[0].S));}
#line 1839 "tp_y.c" /* yacc.c:1646  */
    break;

  case 83:
#line 194 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[-1].pT);}
#line 1845 "tp_y.c" /* yacc.c:1646  */
    break;

  case 84:
#line 195 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(CAST, 2, (yyvsp[-2].S), (yyvsp[-1].pT));}
#line 1851 "tp_y.c" /* yacc.c:1646  */
    break;

  case 85:
#line 198 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(MSG, 2, (yyvsp[-3].S), (yyvsp[-1].pT));}
#line 1857 "tp_y.c" /* yacc.c:1646  */
    break;

  case 86:
#line 201 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[0].pV);}
#line 1863 "tp_y.c" /* yacc.c:1646  */
    break;

  case 87:
#line 202 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = NIL(VarDecl);}
#line 1869 "tp_y.c" /* yacc.c:1646  */
    break;

  case 88:
#line 205 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[-1].pV); (yyvsp[-1].pV)->next = (yyvsp[0].pV);}
#line 1875 "tp_y.c" /* yacc.c:1646  */
    break;

  case 89:
#line 206 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[0].pV);}
#line 1881 "tp_y.c" /* yacc.c:1646  */
    break;

  case 90:
#line 209 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = makeVar(TRUE,(yyvsp[-4].S),(yyvsp[-2].S),(yyvsp[-1].pT));}
#line 1887 "tp_y.c" /* yacc.c:1646  */
    break;

  case 91:
#line 212 "tp.y" /* yacc.c:1646  */
    {(yyval.B) = TRUE;}
#line 1893 "tp_y.c" /* yacc.c:1646  */
    break;

  case 92:
#line 213 "tp.y" /* yacc.c:1646  */
    {(yyval.B) = FALSE;}
#line 1899 "tp_y.c" /* yacc.c:1646  */
    break;


#line 1903 "tp_y.c" /* yacc.c:1646  */
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
