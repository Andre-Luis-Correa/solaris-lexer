/* A Bison parser, made by GNU Bison 2.7.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2012 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
/* Line 371 of yacc.c  */
#line 1 "solaris.y"

    #include <stdio.h>
    #include "syntacticAnalysis.h"
    #define MAXBUFFER 1000

    int yylex(void);
    extern int yylineno;
    extern char *yytext;
    void yyerror(const char *s);

    char synErrorMessage[MAXBUFFER];

/* Line 371 of yacc.c  */
#line 81 "solaris.tab.c"

# ifndef YY_NULL
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULL nullptr
#  else
#   define YY_NULL 0
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
   by #include "solaris.tab.h".  */
#ifndef YY_YY_SOLARIS_TAB_H_INCLUDED
# define YY_YY_SOLARIS_TAB_H_INCLUDED
/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TOKEN_RESERVED_WORD = 258,
     TOKEN_IDENTIFIER = 259,
     TOKEN_INTEGER_NUMBER = 260,
     TOKEN_FLOAT_NUMBER = 261,
     TOKEN_STRING = 262,
     TOKEN_ARITHMETIC_OP = 263,
     TOKEN_RELATIONAL_OP = 264,
     TOKEN_LOGICAL_OP = 265,
     TOKEN_DELIMITER = 266,
     TOKEN_ASSIGNMENT_OP = 267,
     TOKEN_CONDITIONAL_CHOOSE = 268,
     TOKEN_CONDITIONAL_OTHERWISE = 269,
     TOKEN_LOOP = 270,
     TOKEN_LOOP_UNTIL = 271,
     TOKEN_LOOP_WHILE = 272,
     TOKEN_DATA_TYPE = 273,
     TOKEN_DATA_TYPE_STRING = 274,
     TOKEN_COMMENT_LINE = 275,
     TOKEN_COMMENT_BLOCK = 276,
     TOKEN_SHOW = 277,
     TOKEN_READ = 278,
     TOKEN_FUNCTION = 279,
     TOKEN_FUNCTION_RECEIVE = 280,
     TOKEN_FUNCTION_RETURN = 281,
     TOKEN_USE = 282,
     TOKEN_BOOLEAN = 283,
     TOKEN_UNKNOWN = 284
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 14 "solaris.y"

    char *str;  // Para armazenar strings
    int intval; // Para armazenar inteiros, se necessário


/* Line 387 of yacc.c  */
#line 159 "solaris.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */

#endif /* !YY_YY_SOLARIS_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

/* Line 390 of yacc.c  */
#line 187 "solaris.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(N) (N)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

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
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   248

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  165

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   284

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      30,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      32,    33,     2,     2,    37,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    36,    31,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     7,    11,    15,    19,    23,    27,    31,
      35,    39,    43,    47,    51,    54,    55,    59,    62,    66,
      72,    75,    77,    80,    85,    90,    95,   100,   105,   110,
     114,   118,   122,   126,   130,   133,   137,   141,   145,   149,
     151,   153,   155,   158,   161,   164,   167,   169,   177,   189,
     193,   197,   202,   211,   218,   219,   222,   225,   228,   231,
     234,   237,   240,   243,   246,   258,   266,   270,   274,   279,
     283,   287,   291,   293,   295,   297,   299,   301,   305,   309,
     313,   328,   344,   347,   352,   356,   360,   364,   368
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      39,     0,    -1,    39,    40,    30,    -1,    39,    41,    30,
      -1,    39,    42,    30,    -1,    39,    43,    30,    -1,    39,
      45,    30,    -1,    39,    46,    30,    -1,    39,    49,    30,
      -1,    39,    50,    30,    -1,    39,    51,    30,    -1,    39,
      52,    30,    -1,    39,    54,    30,    -1,    39,    55,    30,
      -1,    39,    30,    -1,    -1,    18,     4,    31,    -1,    18,
      41,    -1,    19,     4,    31,    -1,    19,     4,    12,     7,
      31,    -1,    18,     4,    -1,    18,    -1,    19,     4,    -1,
      19,     4,    12,     7,    -1,     4,    12,     4,    31,    -1,
       4,    12,     7,    31,    -1,     4,    12,     5,    31,    -1,
       4,    12,     6,    31,    -1,     4,    12,    42,    31,    -1,
       4,    12,     4,    -1,     4,    12,     7,    -1,     4,    12,
       5,    -1,     4,    12,     6,    -1,     4,    12,    42,    -1,
       4,    12,    -1,    42,     8,    42,    -1,    42,     9,    42,
      -1,    42,    10,    42,    -1,    32,    42,    33,    -1,     4,
      -1,     5,    -1,     6,    -1,    42,     8,    -1,    32,    33,
      -1,    32,    42,    -1,     8,    42,    -1,     8,    -1,    13,
      32,    42,    33,    34,    44,    35,    -1,    13,    32,    42,
      33,    34,    44,    35,    14,    34,    44,    35,    -1,    13,
      32,    42,    -1,    13,    32,    33,    -1,    13,    32,    42,
      33,    -1,    13,    32,    42,    33,    34,    44,    35,    14,
      -1,    13,    32,    42,    33,    34,    44,    -1,    -1,    44,
      30,    -1,    44,    40,    -1,    44,    41,    -1,    44,    43,
      -1,    44,    45,    -1,    44,    46,    -1,    44,    49,    -1,
      44,    51,    -1,    44,    50,    -1,    15,    32,    47,    33,
      16,    32,    48,    33,    34,    44,    35,    -1,    17,    32,
      48,    33,    34,    44,    35,    -1,     4,    12,     5,    -1,
       4,    12,     4,    -1,    18,     4,    12,     5,    -1,    48,
       9,    48,    -1,    48,    10,    48,    -1,    32,    48,    33,
      -1,     4,    -1,     5,    -1,     6,    -1,    20,    -1,    21,
      -1,    22,     4,    31,    -1,    22,     7,    31,    -1,    23,
       4,    31,    -1,    24,    32,    18,    33,    36,     4,    25,
      32,    53,    33,    34,    44,    54,    35,    -1,    24,    32,
      18,    33,    36,     4,    25,    32,    53,    33,    34,    44,
      54,    30,    35,    -1,    18,     4,    -1,    53,    37,    18,
       4,    -1,    26,     4,    31,    -1,    26,     7,    31,    -1,
      26,     5,    31,    -1,    26,     6,    31,    -1,    27,     7,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    73,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    90,    96,   102,   108,
     115,   121,   127,   133,   141,   147,   153,   159,   165,   172,
     180,   188,   196,   204,   212,   222,   228,   234,   239,   244,
     247,   250,   254,   262,   268,   276,   284,   294,   300,   307,
     313,   319,   325,   331,   339,   342,   345,   348,   351,   354,
     357,   360,   363,   366,   372,   381,   390,   396,   402,   411,
     417,   422,   427,   430,   433,   439,   445,   454,   460,   469,
     478,   484,   493,   498,   506,   512,   518,   524,   533
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOKEN_RESERVED_WORD",
  "TOKEN_IDENTIFIER", "TOKEN_INTEGER_NUMBER", "TOKEN_FLOAT_NUMBER",
  "TOKEN_STRING", "TOKEN_ARITHMETIC_OP", "TOKEN_RELATIONAL_OP",
  "TOKEN_LOGICAL_OP", "TOKEN_DELIMITER", "TOKEN_ASSIGNMENT_OP",
  "TOKEN_CONDITIONAL_CHOOSE", "TOKEN_CONDITIONAL_OTHERWISE", "TOKEN_LOOP",
  "TOKEN_LOOP_UNTIL", "TOKEN_LOOP_WHILE", "TOKEN_DATA_TYPE",
  "TOKEN_DATA_TYPE_STRING", "TOKEN_COMMENT_LINE", "TOKEN_COMMENT_BLOCK",
  "TOKEN_SHOW", "TOKEN_READ", "TOKEN_FUNCTION", "TOKEN_FUNCTION_RECEIVE",
  "TOKEN_FUNCTION_RETURN", "TOKEN_USE", "TOKEN_BOOLEAN", "TOKEN_UNKNOWN",
  "'\\n'", "';'", "'('", "')'", "'{'", "'}'", "':'", "','", "$accept",
  "program", "variable_declaration", "assignment", "expression",
  "conditional", "possible_content", "loop", "loop_while", "loop_start",
  "loop_condition", "comment", "write_data", "read_data",
  "function_declaration", "function_parameter", "function_return",
  "library_inclusion", YY_NULL
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
      10,    59,    40,    41,   123,   125,    58,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    38,    39,    39,    39,    39,    39,    39,    39,    39,
      39,    39,    39,    39,    39,    39,    40,    40,    40,    40,
      40,    40,    40,    40,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    43,    43,    43,
      43,    43,    43,    43,    44,    44,    44,    44,    44,    44,
      44,    44,    44,    44,    45,    46,    47,    47,    47,    48,
      48,    48,    48,    48,    48,    49,    49,    50,    50,    51,
      52,    52,    53,    53,    54,    54,    54,    54,    55
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     0,     3,     2,     3,     5,
       2,     1,     2,     4,     4,     4,     4,     4,     4,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     1,
       1,     1,     2,     2,     2,     2,     1,     7,    11,     3,
       3,     4,     8,     6,     0,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    11,     7,     3,     3,     4,     3,
       3,     3,     1,     1,     1,     1,     1,     3,     3,     3,
      14,    15,     2,     4,     3,     3,     3,     3,     2
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      15,     0,     1,    39,    40,    41,    46,     0,     0,     0,
      21,     0,    75,    76,     0,     0,     0,     0,     0,    14,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    39,    45,     0,     0,     0,    20,
      17,    22,     0,     0,     0,     0,     0,     0,     0,     0,
      88,    43,    44,     2,     3,    42,     0,     0,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    29,    31,
      32,    30,    33,    50,    49,     0,     0,     0,    72,    73,
      74,     0,     0,    16,     0,    18,    77,    78,    79,     0,
      84,    86,    87,    85,    38,    35,    36,    37,    24,    26,
      27,    25,    28,    51,     0,     0,     0,     0,     0,     0,
       0,    23,     0,    54,    67,    66,     0,     0,    71,    69,
      70,    54,    19,     0,    53,    68,     0,     0,     0,     0,
      55,    47,    56,    57,    58,    59,    60,    61,    63,    62,
       0,    65,     0,    52,     0,     0,    54,    54,     0,     0,
       0,     0,    82,     0,     0,    48,    64,    54,     0,     0,
      83,     0,     0,    80,    81
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   132,   133,    23,   134,   124,   135,   136,    77,
      82,   137,   138,   139,    30,   149,    31,    32
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -116
static const yytype_int16 yypact[] =
{
    -116,    39,  -116,    29,  -116,  -116,    82,   -19,    16,    38,
      68,    72,  -116,  -116,    85,    80,    61,   142,    90,  -116,
       4,    75,    77,   187,    83,    88,    99,   101,   120,   147,
     168,   169,   170,   134,  -116,  -116,   122,    -1,   129,    22,
    -116,    43,   153,   171,   172,   183,   173,   174,   176,   177,
    -116,  -116,   135,  -116,  -116,    82,   104,   104,  -116,  -116,
    -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,   154,   178,
     181,   179,   184,  -116,   143,   194,   207,   180,  -116,  -116,
    -116,   129,    58,  -116,   209,  -116,  -116,  -116,  -116,   185,
    -116,  -116,  -116,  -116,  -116,  -116,   206,    -4,  -116,  -116,
    -116,  -116,  -116,   186,   175,   210,   203,   148,   129,   129,
     189,   190,   188,  -116,  -116,  -116,   220,   195,  -116,  -116,
     217,  -116,  -116,   224,     3,  -116,   129,    60,   204,    29,
    -116,   216,  -116,  -116,  -116,  -116,  -116,  -116,  -116,  -116,
     150,  -116,   199,   198,   200,   215,  -116,  -116,   231,   -18,
      81,   102,  -116,   202,   219,  -116,  -116,  -116,   234,   152,
    -116,     5,   205,  -116,  -116
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,   238,     1,    -6,   240,  -115,   241,   242,  -116,
     -80,   243,   244,   245,  -116,  -116,    89,  -116
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -42
static const yytype_int16 yytable[] =
{
      35,   107,    22,    75,    55,    56,   127,   129,    34,     4,
       5,    40,     6,    36,    52,   153,     7,    76,     8,   154,
       9,    10,    11,    12,    13,    14,    15,    72,   119,   120,
      74,   150,   151,   130,    33,   162,    20,    51,   131,     2,
     163,    33,   159,     3,     4,     5,   140,     6,    37,    95,
      96,    97,     7,    83,     8,    84,     9,    10,    11,    12,
      13,    14,    15,    16,   129,    17,    18,   108,   109,    19,
      38,    20,    39,     7,    85,     8,    41,     9,    10,    11,
      12,    13,    14,    15,    44,   129,    34,     4,     5,    42,
     130,   110,    43,    45,     7,   141,     8,    50,     9,    10,
      11,    12,    13,    14,    15,    53,   129,    54,    34,     4,
       5,   130,     6,    59,    20,     7,   155,     8,    60,     9,
      10,    11,    12,    13,    14,    15,    34,     4,     5,    61,
       6,    62,   130,    78,    79,    80,    20,   156,    68,    69,
      70,    71,     6,    55,    56,    57,    46,    47,    48,    49,
      63,    55,    56,    57,    20,    73,   129,   108,   109,   108,
     109,    81,   -39,   -39,   -39,     7,    20,     8,    94,     9,
      10,    11,    12,    13,    14,    15,   103,    64,    17,   114,
     115,   118,   130,   144,    86,    98,   -40,   -40,   -40,   -41,
     -41,   -41,    55,    56,    57,    55,    56,    57,    65,    66,
      67,    89,    87,    88,    90,    91,   104,    92,    93,    99,
     101,   105,   100,   106,    55,   102,   111,    58,   112,   117,
     113,   122,   116,   121,   123,   125,   108,   126,   128,   142,
     143,   145,   146,   148,   147,   152,   157,   158,   160,    21,
     164,    24,    25,    26,    27,    28,    29,     0,   161
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-116)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       6,    81,     1,     4,     8,     9,   121,     4,     4,     5,
       6,    10,     8,    32,    20,    33,    13,    18,    15,    37,
      17,    18,    19,    20,    21,    22,    23,    33,   108,   109,
      36,   146,   147,    30,    12,    30,    32,    33,    35,     0,
      35,    12,   157,     4,     5,     6,   126,     8,    32,    55,
      56,    57,    13,    31,    15,    12,    17,    18,    19,    20,
      21,    22,    23,    24,     4,    26,    27,     9,    10,    30,
      32,    32,     4,    13,    31,    15,     4,    17,    18,    19,
      20,    21,    22,    23,     4,     4,     4,     5,     6,     4,
      30,    33,     7,    32,    13,    35,    15,     7,    17,    18,
      19,    20,    21,    22,    23,    30,     4,    30,     4,     5,
       6,    30,     8,    30,    32,    13,    35,    15,    30,    17,
      18,    19,    20,    21,    22,    23,     4,     5,     6,    30,
       8,    30,    30,     4,     5,     6,    32,    35,     4,     5,
       6,     7,     8,     8,     9,    10,     4,     5,     6,     7,
      30,     8,     9,    10,    32,    33,     4,     9,    10,     9,
      10,    32,     8,     9,    10,    13,    32,    15,    33,    17,
      18,    19,    20,    21,    22,    23,    33,    30,    26,     4,
       5,    33,    30,    33,    31,    31,     8,     9,    10,     8,
       9,    10,     8,     9,    10,     8,     9,    10,    30,    30,
      30,    18,    31,    31,    31,    31,    12,    31,    31,    31,
      31,     4,    31,    33,     8,    31,     7,    30,    33,    16,
      34,    31,    12,    34,    36,     5,     9,    32,     4,    25,
      14,    32,    34,    18,    34,     4,    34,    18,     4,     1,
      35,     1,     1,     1,     1,     1,     1,    -1,   159
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    39,     0,     4,     5,     6,     8,    13,    15,    17,
      18,    19,    20,    21,    22,    23,    24,    26,    27,    30,
      32,    40,    41,    42,    43,    45,    46,    49,    50,    51,
      52,    54,    55,    12,     4,    42,    32,    32,    32,     4,
      41,     4,     4,     7,     4,    32,     4,     5,     6,     7,
       7,    33,    42,    30,    30,     8,     9,    10,    30,    30,
      30,    30,    30,    30,    30,    30,    30,    30,     4,     5,
       6,     7,    42,    33,    42,     4,    18,    47,     4,     5,
       6,    32,    48,    31,    12,    31,    31,    31,    31,    18,
      31,    31,    31,    31,    33,    42,    42,    42,    31,    31,
      31,    31,    31,    33,    12,     4,    33,    48,     9,    10,
      33,     7,    33,    34,     4,     5,    12,    16,    33,    48,
      48,    34,    31,    36,    44,     5,    32,    44,     4,     4,
      30,    35,    40,    41,    43,    45,    46,    49,    50,    51,
      48,    35,    25,    14,    33,    32,    34,    34,    18,    53,
      44,    44,     4,    33,    37,    35,    35,    34,    18,    44,
       4,    54,    30,    35,    35
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

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
      YYERROR;							\
    }								\
while (YYID (0))

/* Error token number */
#define YYTERROR	1
#define YYERRCODE	256


/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */
#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
        break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULL, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULL;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULL, yytname[yyx]);
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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
        break;
    }
}




/* The lookahead symbol.  */
int yychar;


#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval YY_INITIAL_VALUE(yyval_default);

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

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
      yychar = YYLEX;
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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 16:
/* Line 1792 of yacc.c  */
#line 90 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s%c", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), ';');
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 96 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s", (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].str));
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 102 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
        processSyntacticStructure(SYN_STRING_DECLARATION, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 108 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s %s;", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str), (yyvsp[(4) - (5)].str));
        processSyntacticStructure(SYN_STRING_DECLARATION, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 115 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a declaracao de [ %s ] na linha %d\n", (yyvsp[(2) - (2)].str), yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 121 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Declaracao de variavel incompleta na linha %d\n", yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 127 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a declaracao de [ %s ] na linha %d\n", (yyvsp[(2) - (2)].str), yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 133 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a declaracao de [ %s ] na linha %d\n", (yyvsp[(2) - (4)].str), yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 141 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%c", (yyvsp[(1) - (4)].str), (yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].str), ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 147 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%c", (yyvsp[(1) - (4)].str), (yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].str), ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 153 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%c", (yyvsp[(1) - (4)].str), (yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].str), ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 159 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%c", (yyvsp[(1) - (4)].str), (yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].str), ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 165 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s%c", (yyvsp[(1) - (4)].str), (yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].str), ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 172 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a atribuicao [ %s ] na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 30:
/* Line 1792 of yacc.c  */
#line 180 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a atribuicao [ %s ] na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 31:
/* Line 1792 of yacc.c  */
#line 188 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a atribuicao [ %s ] na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 32:
/* Line 1792 of yacc.c  */
#line 196 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a atribuicao [ %s ] na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 33:
/* Line 1792 of yacc.c  */
#line 204 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a atribuicao [ %s ] na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 212 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s", (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].str));
        sprintf(synErrorMessage, "Erro: Atribuicao incompleta [ %s ] na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 35:
/* Line 1792 of yacc.c  */
#line 222 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));
        processSyntacticStructure(SYN_ARITHMETIC_OPERATION, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 228 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));
        processSyntacticStructure(SYN_RELATIONAL_OPERATION, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 234 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));
        (yyval.str) = strdup(buffer);
    }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 239 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%c %s %c", '(', (yyvsp[(2) - (3)].str), ')');
        (yyval.str) = strdup(buffer);
    }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 244 "solaris.y"
    {
        (yyval.str) = strdup((yyvsp[(1) - (1)].str));
    }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 247 "solaris.y"
    {
        (yyval.str) = strdup((yyvsp[(1) - (1)].str));
    }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 250 "solaris.y"
    {
        (yyval.str) = strdup((yyvsp[(1) - (1)].str));
    }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 254 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s", (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].str));
        sprintf(synErrorMessage, "Erro: Operacao incompleta apos operador '%s' na linha %d\n", (yyvsp[(2) - (2)].str), yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 262 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Operacao incompleta entre parenteses na linha %d\n", yylineno + 1);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 268 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "( %s", (yyvsp[(2) - (2)].str));
        sprintf(synErrorMessage, "Erro: Operacao com fechamento de parenteses incompleto '%s' na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 276 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s", (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].str));
        sprintf(synErrorMessage, "Erro: Operacao incompleta '%s' na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 284 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s", (yyvsp[(1) - (1)].str));
        sprintf(synErrorMessage, "Erro: Operacao '%s' sem operandos na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 47:
/* Line 1792 of yacc.c  */
#line 294 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %c %s %c %c %s %c", (yyvsp[(1) - (7)].str), '(', (yyvsp[(3) - (7)].str), ')', '{', (yyvsp[(6) - (7)].str), '}');
        processSyntacticStructure(SYN_CONDITIONAL_CHOOSE, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 300 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %c %s %c %c %s %c %s %c %s %c", (yyvsp[(1) - (11)].str), '(', (yyvsp[(3) - (11)].str), ')', '{', (yyvsp[(6) - (11)].str), '}', (yyvsp[(8) - (11)].str), '{', (yyvsp[(10) - (11)].str), '}');
        processSyntacticStructure(SYN_CONDITIONAL_CHOOSE, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 307 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Falta de fechamento de parenteses no condicional na linha %d\n", yylineno + 1);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 313 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Condicional sem expressao na linha %d\n", yylineno +1 );
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 319 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Falta de abertura de bloco '{' no condicional na linha %d\n", yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 325 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Bloco 'otherwise' incompleto na linha %d\n", yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 331 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Falta de fechamento de bloco '}' no condicional na linha %d\n", yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 339 "solaris.y"
    {
        (yyval.str) = strdup("");
    }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 342 "solaris.y"
    {
        (yyval.str) = strdup("\n");
    }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 345 "solaris.y"
    {
        (yyval.str) = strdup((yyvsp[(2) - (2)].str));
    }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 348 "solaris.y"
    {
        (yyval.str) = strdup((yyvsp[(2) - (2)].str));
    }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 351 "solaris.y"
    {
        (yyval.str) = strdup((yyvsp[(2) - (2)].str));
    }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 354 "solaris.y"
    {
        (yyval.str) = strdup((yyvsp[(2) - (2)].str));
    }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 357 "solaris.y"
    {
        (yyval.str) = strdup((yyvsp[(2) - (2)].str));
    }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 360 "solaris.y"
    {
        (yyval.str) = strdup((yyvsp[(2) - (2)].str));
    }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 363 "solaris.y"
    {
        (yyval.str) = strdup((yyvsp[(2) - (2)].str));
    }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 366 "solaris.y"
    {
        (yyval.str) = strdup((yyvsp[(2) - (2)].str));
    }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 372 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) %s ( %s ) { %s }", (yyvsp[(1) - (11)].str), (yyvsp[(3) - (11)].str), (yyvsp[(5) - (11)].str), (yyvsp[(7) - (11)].str), (yyvsp[(10) - (11)].str));
        processSyntacticStructure(SYN_LOOP, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 381 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) { %s }", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].str), (yyvsp[(6) - (7)].str));
        processSyntacticStructure(SYN_LOOP_WHILE, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 390 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 396 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 402 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s %s", (yyvsp[(1) - (4)].str), (yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].str), (yyvsp[(4) - (4)].str));
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 411 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));
        processSyntacticStructure(SYN_RELATIONAL_OPERATION, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 417 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));
        (yyval.str) = strdup(buffer);
    }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 422 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%c %s %c", '(', (yyvsp[(2) - (3)].str), ')');
        (yyval.str) = strdup(buffer);
    }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 427 "solaris.y"
    {
        (yyval.str) = strdup((yyvsp[(1) - (1)].str));
    }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 430 "solaris.y"
    {
        (yyval.str) = strdup((yyvsp[(1) - (1)].str));
    }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 433 "solaris.y"
    {
        (yyval.str) = strdup((yyvsp[(1) - (1)].str));
    }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 439 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s", (yyvsp[(1) - (1)].str));
        processSyntacticStructure(SYN_COMMENT_LINE, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 445 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s", (yyvsp[(1) - (1)].str));
        processSyntacticStructure(SYN_COMMENT_BLOCK, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 454 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
        processSyntacticStructure(SYN_WRITE_DATA, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 460 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
        processSyntacticStructure(SYN_WRITE_DATA, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 469 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
        processSyntacticStructure(SYN_READ_DATA, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 478 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) : %s %s ( %s ) { %s; }", (yyvsp[(1) - (14)].str), (yyvsp[(3) - (14)].str), (yyvsp[(6) - (14)].str), (yyvsp[(7) - (14)].str), (yyvsp[(9) - (14)].str), (yyvsp[(12) - (14)].str));
        processSyntacticStructure(SYN_FUNCTION_DECLARATION, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 484 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) : %s %s ( %s ) { %s; }", (yyvsp[(1) - (15)].str), (yyvsp[(3) - (15)].str), (yyvsp[(6) - (15)].str), (yyvsp[(7) - (15)].str), (yyvsp[(9) - (15)].str), (yyvsp[(12) - (15)].str));
        processSyntacticStructure(SYN_FUNCTION_DECLARATION, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 493 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s", (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].str));
        (yyval.str) = strdup(buffer);
    }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 498 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s, %s %s", (yyvsp[(1) - (4)].str), (yyvsp[(3) - (4)].str), (yyvsp[(4) - (4)].str));
        (yyval.str) = strdup(buffer);
    }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 506 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
        processSyntacticStructure(SYN_FUNCTION_RETURN, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 512 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
        processSyntacticStructure(SYN_FUNCTION_RETURN, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 518 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
        processSyntacticStructure(SYN_FUNCTION_RETURN, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 524 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
        processSyntacticStructure(SYN_FUNCTION_RETURN, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 533 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].str));
        processSyntacticStructure(SYN_LIBRARY_INCLUSION, buffer);
        (yyval.str) = strdup(buffer);
    }
    break;


/* Line 1792 of yacc.c  */
#line 2297 "solaris.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


/* Line 2055 of yacc.c  */
#line 540 "solaris.y"


void yyerror(const char *s) {
    fprintf(stderr, "Erro sintatico na linha %d proximo a '%s': %s\n", yylineno, yytext, s);
    exit(EXIT_FAILURE);
}
