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
#define YYLAST   212

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  165

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
       0,    44,    44,    47,    48,    51,    53,    56,    57,    60,
      63,    64,    67,    68,    71,    72,    75,    76,    79,    80,
      81,    82,    85,    86,    89,    90,    93,    94,    95,    96,
      97,    98,    99,   100,   101,   102,   105,   109,   112,   115,
     116,   119,   120,   123,   124,   127,   128,   131,   132,   133,
     136,   137,   138,   141,   144,   145,   148,   151,   152,   155,
     156,   159,   160,   162,   165,   166,   168,   169,   171,   172,
     173,   174,   177,   178,   179,   182,   185,   186,   187,   190,
     191,   192,   193,   194,   197,   200,   201,   204,   205,   208,
     211,   212
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
  "ListInstructions", "Instruction", "InstIfElse", "Expression",
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

#define YYPACT_NINF -81

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-81)))

#define YYTABLE_NINF -92

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,    -6,    10,    13,   -19,   -81,     8,   -81,   -81,     6,
      40,   -81,    56,   -81,   -81,     3,    33,    45,   145,    32,
     145,   145,    46,    42,   -81,   -81,   -81,    54,     4,    47,
     -81,   113,    52,   177,   -81,    66,   -81,    64,    65,    68,
     -81,    84,    85,   -81,    58,   -81,    57,   -81,    59,    72,
      85,    62,   164,   -81,   -81,    23,    23,    70,   127,    -9,
     127,    67,   -81,   -81,   -81,   145,   145,   145,   145,   145,
     145,   145,   127,    12,   113,   -81,    91,    93,    93,    69,
      39,   -81,    80,    92,   127,    74,    77,   -81,    64,    68,
      86,   -81,    23,    23,   -81,   -81,    31,    23,   190,    82,
     -81,    97,    99,   -19,   -81,   -81,   -81,   -81,   107,   108,
     -81,   101,   -81,    39,   133,   122,   -81,   -81,   135,   111,
     127,   -81,   -81,   -81,   -81,   116,   146,   -81,   120,   144,
     -81,   -81,   139,   127,   132,    92,   -81,   -81,   127,   129,
     140,   127,   134,   -81,   -81,   -81,   142,    85,   -81,   144,
     -81,     3,   -81,    39,   143,   137,   131,   -81,   148,   175,
     172,   -19,   127,   -81,   -81
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     0,     0,     3,     6,     7,     8,     0,
       0,     1,    15,     2,     5,    49,     0,     0,     0,     0,
       0,     0,     0,    79,    78,    81,    70,    74,     0,     0,
      14,    17,     0,    25,    24,    35,    69,    68,     0,    71,
      80,     0,    88,    57,     0,    47,    52,    48,    55,     0,
      86,     0,     0,    35,    19,    33,    34,     0,    65,     0,
      78,     0,    12,    16,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    87,    62,    58,    58,     0,
      40,    85,     0,     0,    65,    67,     0,    64,    72,    73,
       0,    82,    27,    28,    29,    30,    31,    32,    26,     0,
      75,     0,     0,    11,    61,    50,    51,    54,     0,     0,
      90,     0,    39,    42,     0,    60,    23,    22,     0,     0,
       0,    84,    83,    20,    13,     0,     0,    10,     0,    53,
       9,    41,     0,     0,     0,     0,    36,    66,    65,     0,
       0,     0,     0,    59,    89,    21,     0,    86,    37,     0,
      56,    49,    63,    40,     0,     0,    46,    38,     0,     0,
      45,     0,     0,    44,    43
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -81,   -81,   -81,   179,   -81,   -81,   -81,    -4,   -81,   -14,
     -76,    53,   -27,   -15,   -81,   -81,   -81,    34,    76,   -81,
     -81,    49,   121,   -81,   -11,   -81,   112,   -81,   -81,   -81,
     -80,    81,   -10,   -81,   138,   -81,   -48,   -81,    55,    -3,
     -81,   -81
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,   126,   116,    29,    30,
      31,   118,    32,    33,    34,     8,   148,   111,   112,   113,
     159,    44,    45,    46,    47,    48,    49,   134,   103,   104,
      86,    87,    53,    36,    37,    38,    39,    40,    80,    81,
      42,   114
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    61,    35,    52,   119,    55,    56,   117,    43,    41,
      12,    89,     1,    11,    23,    24,    25,    63,     9,    20,
      21,    35,     2,    28,    22,   100,   -58,    23,    60,    25,
      26,    85,    27,    90,    10,    23,    28,    25,    15,    75,
      67,    68,    69,    16,    28,    99,   -91,   110,    67,    68,
      92,    93,    94,    95,    96,    97,    98,    85,   146,   117,
     101,    17,    50,    54,    35,    18,   106,   107,    51,    19,
      57,    20,    21,    35,    58,    59,    22,    62,    72,    23,
      24,    25,    26,    64,    27,   -76,    73,    74,    28,   -77,
      17,    76,    77,    85,    78,    79,    82,   102,    43,   127,
      91,    18,    84,   109,   115,    19,   143,    20,    21,   120,
     121,    85,    22,   123,   150,    23,    24,    25,    26,   122,
      27,    12,    18,   125,    28,    35,    19,   124,    20,    21,
     128,   130,   129,    22,   133,   164,    23,    24,    25,    26,
     132,    27,    20,    21,   136,    28,   135,    22,   138,   139,
      23,    24,    25,    26,   140,    27,   141,   163,   147,    28,
      20,    21,   142,   144,   149,   158,   151,   157,    23,    24,
      25,    26,   160,    27,    83,   152,   156,    28,   161,    65,
      66,    67,    68,    69,   162,    14,    70,   155,   145,   131,
     108,    71,    65,    66,    67,    68,    69,    88,   105,    70,
     154,   137,   153,     0,    71,    65,    66,    67,    68,    69,
       0,     0,    70
};

static const yytype_int16 yycheck[] =
{
       4,    28,    12,    18,    84,    20,    21,    83,     5,    12,
      29,    59,     4,     0,    23,    24,    25,    31,    24,    15,
      16,    31,    14,    32,    20,    73,    23,    23,    24,    25,
      26,    58,    28,    60,    24,    23,    32,    25,    32,    42,
      17,    18,    19,     3,    32,    72,     7,     8,    17,    18,
      65,    66,    67,    68,    69,    70,    71,    84,   138,   135,
      74,     5,    29,    31,    74,     9,    77,    78,    23,    13,
      24,    15,    16,    83,    32,    21,    20,    30,    12,    23,
      24,    25,    26,    31,    28,    21,    21,     3,    32,    21,
       5,    33,    35,   120,    35,    23,    34,     6,     5,   103,
      33,     9,    32,    34,    24,    13,   133,    15,    16,    35,
      33,   138,    20,    31,   141,    23,    24,    25,    26,    33,
      28,    29,     9,    24,    32,   135,    13,    30,    15,    16,
      23,    30,    24,    20,    12,   162,    23,    24,    25,    26,
       7,    28,    15,    16,    33,    32,    11,    20,    32,     3,
      23,    24,    25,    26,    34,    28,    12,   161,    29,    32,
      15,    16,    23,    31,    24,    34,    32,    30,    23,    24,
      25,    26,    24,    28,    10,    33,    33,    32,     3,    15,
      16,    17,    18,    19,    12,     6,    22,   153,   135,   113,
      78,    27,    15,    16,    17,    18,    19,    59,    77,    22,
     151,   120,   147,    -1,    27,    15,    16,    17,    18,    19,
      -1,    -1,    22
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     4,    14,    37,    38,    39,    40,    41,    51,    24,
      24,     0,    29,    43,    39,    32,     3,     5,     9,    13,
      15,    16,    20,    23,    24,    25,    26,    28,    32,    44,
      45,    46,    48,    49,    50,    68,    69,    70,    71,    72,
      73,    75,    76,     5,    57,    58,    59,    60,    61,    62,
      29,    23,    49,    68,    31,    49,    49,    24,    32,    21,
      24,    48,    30,    45,    31,    15,    16,    17,    18,    19,
      22,    27,    12,    21,     3,    75,    33,    35,    35,    23,
      74,    75,    34,    10,    32,    48,    66,    67,    70,    72,
      48,    33,    49,    49,    49,    49,    49,    49,    49,    48,
      72,    45,     6,    64,    65,    58,    60,    60,    62,    34,
       8,    53,    54,    55,    77,    24,    43,    46,    47,    66,
      35,    33,    33,    31,    30,    24,    42,    43,    23,    24,
      30,    54,     7,    12,    63,    11,    33,    67,    32,     3,
      34,    12,    23,    48,    31,    47,    66,    29,    52,    24,
      48,    32,    33,    74,    57,    53,    33,    30,    34,    56,
      24,     3,    12,    43,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    38,    38,    39,    39,    40,    40,    41,
      42,    42,    43,    43,    44,    44,    45,    45,    46,    46,
      46,    46,    47,    47,    48,    48,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    50,    51,    52,    53,
      53,    54,    54,    55,    55,    56,    56,    57,    57,    57,
      58,    58,    58,    59,    60,    60,    61,    62,    62,    63,
      63,    64,    64,    65,    66,    66,    67,    67,    68,    68,
      68,    68,    69,    69,    69,    70,    71,    71,    71,    72,
      72,    72,    72,    72,    73,    74,    74,    75,    75,    76,
      77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     0,     2,     1,     1,     1,     7,
       1,     0,     3,     5,     1,     0,     2,     1,     2,     2,
       4,     6,     1,     1,     1,     1,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     1,     5,     9,     4,     1,
       0,     2,     1,    10,     9,     2,     0,     1,     1,     0,
       3,     3,     1,     4,     3,     1,     6,     1,     0,     2,
       0,     1,     0,     5,     1,     0,     3,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     1,     1,     1,     1,
       1,     1,     3,     4,     4,     1,     0,     2,     1,     6,
       1,     0
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
#line 1361 "tp_y.c" /* yacc.c:1646  */
    break;

  case 3:
#line 47 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1367 "tp_y.c" /* yacc.c:1646  */
    break;

  case 4:
#line 48 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = NIL(Tree);}
#line 1373 "tp_y.c" /* yacc.c:1646  */
    break;

  case 5:
#line 51 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(LCLASS, 2, (yyvsp[-1].pT), (yyvsp[0].pT));}
#line 1379 "tp_y.c" /* yacc.c:1646  */
    break;

  case 6:
#line 53 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(LOBJET, 1, (yyvsp[0].pT));}
#line 1385 "tp_y.c" /* yacc.c:1646  */
    break;

  case 7:
#line 56 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeLeafObjet(EDEFOBJ, (yyvsp[0].ObjetP));}
#line 1391 "tp_y.c" /* yacc.c:1646  */
    break;

  case 8:
#line 57 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeLeafClass(EDEFCLASS, (yyvsp[0].ClasseP));}
#line 1397 "tp_y.c" /* yacc.c:1646  */
    break;

  case 9:
#line 60 "tp.y" /* yacc.c:1646  */
    {(yyval.ObjetP) = makeObjet((yyvsp[-5].S),(yyvsp[-2].pV),(yyvsp[-1].MethP)); }
#line 1403 "tp_y.c" /* yacc.c:1646  */
    break;

  case 10:
#line 63 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1409 "tp_y.c" /* yacc.c:1646  */
    break;

  case 11:
#line 64 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = NIL(Tree); }
#line 1415 "tp_y.c" /* yacc.c:1646  */
    break;

  case 12:
#line 67 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(EBLOC, 2, (yyvsp[-1].pT), NIL(Tree)); }
#line 1421 "tp_y.c" /* yacc.c:1646  */
    break;

  case 13:
#line 68 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(EBLOC, 2, (yyvsp[-3].pV), (yyvsp[-1].pT)); attributionType((yyvsp[-3].pV)); }
#line 1427 "tp_y.c" /* yacc.c:1646  */
    break;

  case 14:
#line 71 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1433 "tp_y.c" /* yacc.c:1646  */
    break;

  case 15:
#line 72 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = NIL(Tree);}
#line 1439 "tp_y.c" /* yacc.c:1646  */
    break;

  case 16:
#line 75 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(LINST, 2, (yyvsp[-1].pT), (yyvsp[0].pT));}
#line 1445 "tp_y.c" /* yacc.c:1646  */
    break;

  case 17:
#line 76 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1451 "tp_y.c" /* yacc.c:1646  */
    break;

  case 18:
#line 79 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[-1].pT);}
#line 1457 "tp_y.c" /* yacc.c:1646  */
    break;

  case 19:
#line 80 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeLeafStr(ERETURN, "return");}
#line 1463 "tp_y.c" /* yacc.c:1646  */
    break;

  case 20:
#line 81 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EAFF, 2, (yyvsp[-3].pT), (yyvsp[-1].pT));}
#line 1469 "tp_y.c" /* yacc.c:1646  */
    break;

  case 21:
#line 82 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(ITE, 3, (yyvsp[-4].pT), (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1475 "tp_y.c" /* yacc.c:1646  */
    break;

  case 22:
#line 85 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1481 "tp_y.c" /* yacc.c:1646  */
    break;

  case 23:
#line 86 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1487 "tp_y.c" /* yacc.c:1646  */
    break;

  case 24:
#line 89 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EINST, 1, (yyvsp[0].pT));}
#line 1493 "tp_y.c" /* yacc.c:1646  */
    break;

  case 25:
#line 90 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1499 "tp_y.c" /* yacc.c:1646  */
    break;

  case 26:
#line 93 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(yylval.C, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1505 "tp_y.c" /* yacc.c:1646  */
    break;

  case 27:
#line 94 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EADD, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1511 "tp_y.c" /* yacc.c:1646  */
    break;

  case 28:
#line 95 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(ESUB, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1517 "tp_y.c" /* yacc.c:1646  */
    break;

  case 29:
#line 96 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EMUL, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1523 "tp_y.c" /* yacc.c:1646  */
    break;

  case 30:
#line 97 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EQUOT, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1529 "tp_y.c" /* yacc.c:1646  */
    break;

  case 31:
#line 98 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EREST, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1535 "tp_y.c" /* yacc.c:1646  */
    break;

  case 32:
#line 99 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EAND, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1541 "tp_y.c" /* yacc.c:1646  */
    break;

  case 33:
#line 100 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EADDSOLO, 1, (yyvsp[0].pT));}
#line 1547 "tp_y.c" /* yacc.c:1646  */
    break;

  case 34:
#line 101 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(ESUBSOLO, 1, (yyvsp[0].pT));}
#line 1553 "tp_y.c" /* yacc.c:1646  */
    break;

  case 35:
#line 102 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1559 "tp_y.c" /* yacc.c:1646  */
    break;

  case 36:
#line 105 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(ENEW, 2,
    makeLeafStr(EIDCLASS,(yyvsp[-3].S)), (yyvsp[-1].pT));}
#line 1566 "tp_y.c" /* yacc.c:1646  */
    break;

  case 37:
#line 109 "tp.y" /* yacc.c:1646  */
    { (yyval.ClasseP) = makeClass((yyvsp[-7].S), (yyvsp[-5].pV), (yyvsp[-3].pT), (yyvsp[-2].pT), (yyvsp[0].pT)); }
#line 1572 "tp_y.c" /* yacc.c:1646  */
    break;

  case 38:
#line 112 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(ECORPS, 2, (yyvsp[-2].pV), (yyvsp[-1].MethP));}
#line 1578 "tp_y.c" /* yacc.c:1646  */
    break;

  case 39:
#line 115 "tp.y" /* yacc.c:1646  */
    {(yyval.MethP) = (yyvsp[0].MethP);}
#line 1584 "tp_y.c" /* yacc.c:1646  */
    break;

  case 40:
#line 116 "tp.y" /* yacc.c:1646  */
    {(yyval.MethP) = NIL(method);}
#line 1590 "tp_y.c" /* yacc.c:1646  */
    break;

  case 41:
#line 119 "tp.y" /* yacc.c:1646  */
    {(yyval.MethP) = (yyvsp[-1].MethP); (yyvsp[-1].MethP)->next = (yyvsp[0].MethP);}
#line 1596 "tp_y.c" /* yacc.c:1646  */
    break;

  case 42:
#line 120 "tp.y" /* yacc.c:1646  */
    {(yyval.MethP) = (yyvsp[0].MethP); (yyvsp[0].MethP)->next = NIL(method);}
#line 1602 "tp_y.c" /* yacc.c:1646  */
    break;

  case 43:
#line 123 "tp.y" /* yacc.c:1646  */
    { (yyval.MethP) = makeMethod((yyvsp[-9].B), (yyvsp[-7].S), (yyvsp[-5].pV), (yyvsp[-2].S), (yyvsp[0].pT)); }
#line 1608 "tp_y.c" /* yacc.c:1646  */
    break;

  case 44:
#line 124 "tp.y" /* yacc.c:1646  */
    { (yyval.MethP) = makeMethod((yyvsp[-8].B), (yyvsp[-6].S), (yyvsp[-4].pV), (yyvsp[-2].S), (yyvsp[0].pT)); }
#line 1614 "tp_y.c" /* yacc.c:1646  */
    break;

  case 45:
#line 127 "tp.y" /* yacc.c:1646  */
    {(yyval.S) = (yyvsp[0].S);}
#line 1620 "tp_y.c" /* yacc.c:1646  */
    break;

  case 46:
#line 128 "tp.y" /* yacc.c:1646  */
    {(yyval.S) = NIL(char);}
#line 1626 "tp_y.c" /* yacc.c:1646  */
    break;

  case 47:
#line 131 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[0].pV);}
#line 1632 "tp_y.c" /* yacc.c:1646  */
    break;

  case 48:
#line 132 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[0].pV);}
#line 1638 "tp_y.c" /* yacc.c:1646  */
    break;

  case 49:
#line 133 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = NIL(VarDecl);}
#line 1644 "tp_y.c" /* yacc.c:1646  */
    break;

  case 50:
#line 136 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[-2].pV); (yyvsp[-2].pV)->next = (yyvsp[0].pV);}
#line 1650 "tp_y.c" /* yacc.c:1646  */
    break;

  case 51:
#line 137 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[-2].pV); (yyvsp[-2].pV)->next = (yyvsp[0].pV);}
#line 1656 "tp_y.c" /* yacc.c:1646  */
    break;

  case 52:
#line 138 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[0].pV);}
#line 1662 "tp_y.c" /* yacc.c:1646  */
    break;

  case 53:
#line 141 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = makeVar((yyvsp[-3].B),(yyvsp[-2].S),(yyvsp[0].S),NIL(Tree));}
#line 1668 "tp_y.c" /* yacc.c:1646  */
    break;

  case 54:
#line 144 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[-2].pV); (yyvsp[-2].pV)->next = (yyvsp[0].pV);}
#line 1674 "tp_y.c" /* yacc.c:1646  */
    break;

  case 55:
#line 145 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[0].pV);}
#line 1680 "tp_y.c" /* yacc.c:1646  */
    break;

  case 56:
#line 148 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = makeVar((yyvsp[-5].B),(yyvsp[-4].S),(yyvsp[-2].S),(yyvsp[0].pT));}
#line 1686 "tp_y.c" /* yacc.c:1646  */
    break;

  case 57:
#line 151 "tp.y" /* yacc.c:1646  */
    {(yyval.B) = TRUE;}
#line 1692 "tp_y.c" /* yacc.c:1646  */
    break;

  case 58:
#line 152 "tp.y" /* yacc.c:1646  */
    {(yyval.B) = FALSE;}
#line 1698 "tp_y.c" /* yacc.c:1646  */
    break;

  case 59:
#line 155 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EAFFDECL, 1, (yyvsp[0].pT));}
#line 1704 "tp_y.c" /* yacc.c:1646  */
    break;

  case 60:
#line 156 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = NIL(Tree);}
#line 1710 "tp_y.c" /* yacc.c:1646  */
    break;

  case 61:
#line 159 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1716 "tp_y.c" /* yacc.c:1646  */
    break;

  case 62:
#line 160 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = NIL(Tree);}
#line 1722 "tp_y.c" /* yacc.c:1646  */
    break;

  case 63:
#line 162 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(EEXTND, 2, makeLeafStr(EIDCLASS, (yyvsp[-3].S)), (yyvsp[-1].pT)); }
#line 1728 "tp_y.c" /* yacc.c:1646  */
    break;

  case 64:
#line 165 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1734 "tp_y.c" /* yacc.c:1646  */
    break;

  case 65:
#line 166 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = NIL(Tree);}
#line 1740 "tp_y.c" /* yacc.c:1646  */
    break;

  case 66:
#line 168 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(LARG, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1746 "tp_y.c" /* yacc.c:1646  */
    break;

  case 67:
#line 169 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1752 "tp_y.c" /* yacc.c:1646  */
    break;

  case 68:
#line 171 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EDOT,1,(yyvsp[0].pT));}
#line 1758 "tp_y.c" /* yacc.c:1646  */
    break;

  case 69:
#line 172 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(ETHISSELECT,1,(yyvsp[0].pT));}
#line 1764 "tp_y.c" /* yacc.c:1646  */
    break;

  case 70:
#line 173 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeLeafInt(CSTE, (yyvsp[0].I));}
#line 1770 "tp_y.c" /* yacc.c:1646  */
    break;

  case 71:
#line 174 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1776 "tp_y.c" /* yacc.c:1646  */
    break;

  case 72:
#line 177 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(LISTDOT, 2, (yyvsp[-2].ClasseP), (yyvsp[0].pT)); }
#line 1782 "tp_y.c" /* yacc.c:1646  */
    break;

  case 73:
#line 178 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeTree(ESELDOT, 2, (yyvsp[-2].ClasseP), (yyvsp[0].pT)); }
#line 1788 "tp_y.c" /* yacc.c:1646  */
    break;

  case 74:
#line 179 "tp.y" /* yacc.c:1646  */
    { (yyval.pT) = makeLeafStr(ETHIS, "this");/* les THIS ne peuvent apparaitre que dans les méthodes*/ }
#line 1794 "tp_y.c" /* yacc.c:1646  */
    break;

  case 75:
#line 182 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(ELISTSEL, 2, (yyvsp[-2].pT), (yyvsp[0].pT));}
#line 1800 "tp_y.c" /* yacc.c:1646  */
    break;

  case 76:
#line 185 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(LSEL,1,(yyvsp[0].pT));}
#line 1806 "tp_y.c" /* yacc.c:1646  */
    break;

  case 77:
#line 186 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(ESEL,1,(yyvsp[0].pT));}
#line 1812 "tp_y.c" /* yacc.c:1646  */
    break;

  case 78:
#line 187 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeLeafStr(EIDCLASS, (yyvsp[0].S));}
#line 1818 "tp_y.c" /* yacc.c:1646  */
    break;

  case 79:
#line 190 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeLeafStr(EID, (yyvsp[0].S));}
#line 1824 "tp_y.c" /* yacc.c:1646  */
    break;

  case 80:
#line 191 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = (yyvsp[0].pT);}
#line 1830 "tp_y.c" /* yacc.c:1646  */
    break;

  case 81:
#line 192 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeLeafStr(CSTR, (yyvsp[0].S));}
#line 1836 "tp_y.c" /* yacc.c:1646  */
    break;

  case 82:
#line 193 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(EEXPR, 1, (yyvsp[-1].pT));}
#line 1842 "tp_y.c" /* yacc.c:1646  */
    break;

  case 83:
#line 194 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(CAST, 2, (yyvsp[-2].S), (yyvsp[-1].pT));}
#line 1848 "tp_y.c" /* yacc.c:1646  */
    break;

  case 84:
#line 197 "tp.y" /* yacc.c:1646  */
    {(yyval.pT) = makeTree(MSG, 2,makeLeafStr(EID,(yyvsp[-3].S)), (yyvsp[-1].pT)); /*verifMethClasse($1, $3); */}
#line 1854 "tp_y.c" /* yacc.c:1646  */
    break;

  case 85:
#line 200 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[0].pV);}
#line 1860 "tp_y.c" /* yacc.c:1646  */
    break;

  case 86:
#line 201 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = NIL(VarDecl);}
#line 1866 "tp_y.c" /* yacc.c:1646  */
    break;

  case 87:
#line 204 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[-1].pV); (yyvsp[-1].pV)->next = (yyvsp[0].pV);}
#line 1872 "tp_y.c" /* yacc.c:1646  */
    break;

  case 88:
#line 205 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = (yyvsp[0].pV);}
#line 1878 "tp_y.c" /* yacc.c:1646  */
    break;

  case 89:
#line 208 "tp.y" /* yacc.c:1646  */
    {(yyval.pV) = makeVar(TRUE,(yyvsp[-4].S),(yyvsp[-2].S),(yyvsp[-1].pT));}
#line 1884 "tp_y.c" /* yacc.c:1646  */
    break;

  case 90:
#line 211 "tp.y" /* yacc.c:1646  */
    {(yyval.B) = TRUE;}
#line 1890 "tp_y.c" /* yacc.c:1646  */
    break;

  case 91:
#line 212 "tp.y" /* yacc.c:1646  */
    {(yyval.B) = FALSE;}
#line 1896 "tp_y.c" /* yacc.c:1646  */
    break;


#line 1900 "tp_y.c" /* yacc.c:1646  */
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
