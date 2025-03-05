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
    #include "semanticAnalysis.h"
    #include "tree.h"

    #define MAXBUFFER 1000

    int yylex(void);
    extern int yylineno;
    extern char *yytext;
    void yyerror(const char *s);

    char synErrorMessage[MAXBUFFER];

/* Line 371 of yacc.c  */
#line 84 "solaris.tab.c"

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
     TOKEN_DATA_TYPE_INTEGER = 275,
     TOKEN_DATA_TYPE_FLOAT = 276,
     TOKEN_DATA_TYPE_DOUBLE = 277,
     TOKEN_DATA_TYPE_BOOLEAN = 278,
     TOKEN_COMMENT_LINE = 279,
     TOKEN_COMMENT_BLOCK = 280,
     TOKEN_SHOW = 281,
     TOKEN_READ = 282,
     TOKEN_FUNCTION = 283,
     TOKEN_FUNCTION_RECEIVE = 284,
     TOKEN_FUNCTION_RETURN = 285,
     TOKEN_USE = 286,
     TOKEN_BOOLEAN = 287,
     TOKEN_UNKNOWN = 288
   };
#endif


#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{
/* Line 387 of yacc.c  */
#line 17 "solaris.y"

    char * str;
    struct treeNode * synTree;


/* Line 387 of yacc.c  */
#line 166 "solaris.tab.c"
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
#line 194 "solaris.tab.c"

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
#define YYLAST   247

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNRULES -- Number of states.  */
#define YYNSTATES  165

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   288

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      34,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      36,    37,     2,     2,    41,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    40,    35,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    38,     2,    39,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
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
      43,     0,    -1,    43,    44,    34,    -1,    43,    45,    34,
      -1,    43,    46,    34,    -1,    43,    47,    34,    -1,    43,
      49,    34,    -1,    43,    50,    34,    -1,    43,    53,    34,
      -1,    43,    54,    34,    -1,    43,    55,    34,    -1,    43,
      56,    34,    -1,    43,    58,    34,    -1,    43,    59,    34,
      -1,    43,    34,    -1,    -1,    18,     4,    35,    -1,    18,
      45,    -1,    19,     4,    35,    -1,    19,     4,    12,     7,
      35,    -1,    18,     4,    -1,    18,    -1,    19,     4,    -1,
      19,     4,    12,     7,    -1,     4,    12,     4,    35,    -1,
       4,    12,     7,    35,    -1,     4,    12,     5,    35,    -1,
       4,    12,     6,    35,    -1,     4,    12,    46,    35,    -1,
       4,    12,     4,    -1,     4,    12,     7,    -1,     4,    12,
       5,    -1,     4,    12,     6,    -1,     4,    12,    46,    -1,
       4,    12,    -1,    46,     8,    46,    -1,    46,     9,    46,
      -1,    46,    10,    46,    -1,    36,    46,    37,    -1,     4,
      -1,     5,    -1,     6,    -1,    46,     8,    -1,    36,    37,
      -1,    36,    46,    -1,     8,    46,    -1,     8,    -1,    13,
      36,    46,    37,    38,    48,    39,    -1,    13,    36,    46,
      37,    38,    48,    39,    14,    38,    48,    39,    -1,    13,
      36,    46,    -1,    13,    36,    37,    -1,    13,    36,    46,
      37,    -1,    13,    36,    46,    37,    38,    48,    39,    14,
      -1,    13,    36,    46,    37,    38,    48,    -1,    -1,    48,
      34,    -1,    48,    44,    -1,    48,    45,    -1,    48,    47,
      -1,    48,    49,    -1,    48,    50,    -1,    48,    53,    -1,
      48,    55,    -1,    48,    54,    -1,    15,    36,    51,    37,
      16,    36,    52,    37,    38,    48,    39,    -1,    17,    36,
      52,    37,    38,    48,    39,    -1,     4,    12,     5,    -1,
       4,    12,     4,    -1,    18,     4,    12,     5,    -1,    52,
       9,    52,    -1,    52,    10,    52,    -1,    36,    52,    37,
      -1,     4,    -1,     5,    -1,     6,    -1,    24,    -1,    25,
      -1,    26,     4,    35,    -1,    26,     7,    35,    -1,    27,
       4,    35,    -1,    28,    36,    18,    37,    40,     4,    29,
      36,    57,    37,    38,    48,    58,    39,    -1,    28,    36,
      18,    37,    40,     4,    29,    36,    57,    37,    38,    48,
      58,    34,    39,    -1,    18,     4,    -1,    57,    41,    18,
       4,    -1,    30,     4,    35,    -1,    30,     7,    35,    -1,
      30,     5,    35,    -1,    30,     6,    35,    -1,    31,     7,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    81,    81,    85,    89,    93,    97,   101,   105,   109,
     113,   117,   121,   125,   129,   132,   138,   149,   159,   173,
     187,   193,   199,   205,   213,   226,   239,   252,   265,   279,
     287,   295,   303,   311,   319,   329,   340,   351,   362,   373,
     378,   383,   389,   397,   403,   411,   419,   429,   444,   464,
     470,   476,   482,   488,   496,   500,   504,   508,   512,   516,
     520,   524,   528,   532,   539,   561,   579,   590,   601,   616,
     627,   638,   648,   653,   658,   666,   675,   687,   698,   712,
     726,   748,   773,   782,   796,   807,   818,   829,   843
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
  "TOKEN_DATA_TYPE_STRING", "TOKEN_DATA_TYPE_INTEGER",
  "TOKEN_DATA_TYPE_FLOAT", "TOKEN_DATA_TYPE_DOUBLE",
  "TOKEN_DATA_TYPE_BOOLEAN", "TOKEN_COMMENT_LINE", "TOKEN_COMMENT_BLOCK",
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
     285,   286,   287,   288,    10,    59,    40,    41,   123,   125,
      58,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    42,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    44,    44,    44,    44,
      44,    44,    44,    44,    45,    45,    45,    45,    45,    45,
      45,    45,    45,    45,    45,    46,    46,    46,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    47,    47,    47,
      47,    47,    47,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48,    49,    50,    51,    51,    51,    52,
      52,    52,    52,    52,    52,    53,    53,    54,    54,    55,
      56,    56,    57,    57,    58,    58,    58,    58,    59
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
#define YYPACT_NINF -103
static const yytype_int16 yypact[] =
{
    -103,     7,  -103,     9,  -103,  -103,    12,   -26,     4,    23,
      69,    71,  -103,  -103,    35,    77,    57,   195,    95,  -103,
     103,    94,   101,   183,   104,   112,   114,   122,   128,   130,
     132,   145,   161,   137,  -103,  -103,   121,     5,    48,   118,
    -103,   125,   120,   168,   169,   178,   170,   171,   172,   174,
    -103,  -103,   124,  -103,  -103,    12,     0,     0,  -103,  -103,
    -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,   162,   173,
     177,   175,   180,  -103,   141,   147,   207,   176,  -103,  -103,
    -103,    48,    54,  -103,   209,  -103,  -103,  -103,  -103,   181,
    -103,  -103,  -103,  -103,  -103,  -103,   206,   111,  -103,  -103,
    -103,  -103,  -103,   182,    -2,   210,   203,    62,    48,    48,
     185,   186,   184,  -103,  -103,  -103,   220,   190,  -103,  -103,
     218,  -103,  -103,   224,    43,  -103,    48,    61,   200,     9,
    -103,   216,  -103,  -103,  -103,  -103,  -103,  -103,  -103,  -103,
      80,  -103,   196,   193,   197,   215,  -103,  -103,   230,   157,
      79,    97,  -103,   198,   219,  -103,  -103,  -103,   234,   150,
    -103,   113,   201,  -103,  -103
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -103,  -103,   238,    56,    -6,   240,  -102,   241,   242,  -103,
     -80,   243,   244,   245,  -103,  -103,    88,  -103
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -42
static const yytype_int16 yytable[] =
{
      35,   107,   114,   115,    34,     4,     5,     2,     6,    75,
      36,     3,     4,     5,    52,     6,    34,     4,     5,   127,
       7,    33,     8,    76,     9,    10,    11,    72,   119,   120,
      74,    12,    13,    14,    15,    16,    20,    17,    18,    42,
      37,    19,    43,    20,   150,   151,   140,   129,    20,    95,
      96,    97,    78,    79,    80,   159,     7,    22,     8,    38,
       9,    10,    11,   108,   109,   129,    40,    12,    13,    14,
      15,   108,   109,    39,     7,    41,     8,   130,     9,    10,
      11,    44,   131,   129,    81,    12,    13,    14,    15,   108,
     109,   110,     7,    45,     8,   130,     9,    10,    11,   118,
     141,   129,    50,    12,    13,    14,    15,    34,     4,     5,
       7,     6,     8,   130,     9,    10,    11,   144,   155,    55,
      56,    12,    13,    14,    15,    34,     4,     5,    53,     6,
      33,   130,    55,    56,    57,    54,   156,    84,    59,    20,
      51,    68,    69,    70,    71,     6,    60,   162,    61,    55,
      56,    57,   163,    83,   129,    86,    62,    20,    73,   104,
      85,    94,    63,     7,    64,     8,    65,     9,    10,    11,
     -39,   -39,   -39,    20,    12,    13,    14,    15,   103,    66,
      17,   -40,   -40,   -40,   130,   -41,   -41,   -41,    55,    56,
      57,    55,    56,    57,   153,    67,    89,    98,   154,    46,
      47,    48,    49,    87,    88,    90,    91,    92,    99,    93,
     101,   105,   100,   106,    55,   102,   111,    58,   112,   117,
     113,   122,   116,   121,   123,   125,   126,   108,   128,   142,
     143,   146,   145,   148,   152,   147,   157,   158,   160,    21,
     164,    24,    25,    26,    27,    28,    29,   161
};

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-103)))

#define yytable_value_is_error(Yytable_value) \
  YYID (0)

static const yytype_uint8 yycheck[] =
{
       6,    81,     4,     5,     4,     5,     6,     0,     8,     4,
      36,     4,     5,     6,    20,     8,     4,     5,     6,   121,
      13,    12,    15,    18,    17,    18,    19,    33,   108,   109,
      36,    24,    25,    26,    27,    28,    36,    30,    31,     4,
      36,    34,     7,    36,   146,   147,   126,     4,    36,    55,
      56,    57,     4,     5,     6,   157,    13,     1,    15,    36,
      17,    18,    19,     9,    10,     4,    10,    24,    25,    26,
      27,     9,    10,     4,    13,     4,    15,    34,    17,    18,
      19,     4,    39,     4,    36,    24,    25,    26,    27,     9,
      10,    37,    13,    36,    15,    34,    17,    18,    19,    37,
      39,     4,     7,    24,    25,    26,    27,     4,     5,     6,
      13,     8,    15,    34,    17,    18,    19,    37,    39,     8,
       9,    24,    25,    26,    27,     4,     5,     6,    34,     8,
      12,    34,     8,     9,    10,    34,    39,    12,    34,    36,
      37,     4,     5,     6,     7,     8,    34,    34,    34,     8,
       9,    10,    39,    35,     4,    35,    34,    36,    37,    12,
      35,    37,    34,    13,    34,    15,    34,    17,    18,    19,
       8,     9,    10,    36,    24,    25,    26,    27,    37,    34,
      30,     8,     9,    10,    34,     8,     9,    10,     8,     9,
      10,     8,     9,    10,    37,    34,    18,    35,    41,     4,
       5,     6,     7,    35,    35,    35,    35,    35,    35,    35,
      35,     4,    35,    37,     8,    35,     7,    34,    37,    16,
      38,    35,    12,    38,    40,     5,    36,     9,     4,    29,
      14,    38,    36,    18,     4,    38,    38,    18,     4,     1,
      39,     1,     1,     1,     1,     1,     1,   159
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    43,     0,     4,     5,     6,     8,    13,    15,    17,
      18,    19,    24,    25,    26,    27,    28,    30,    31,    34,
      36,    44,    45,    46,    47,    49,    50,    53,    54,    55,
      56,    58,    59,    12,     4,    46,    36,    36,    36,     4,
      45,     4,     4,     7,     4,    36,     4,     5,     6,     7,
       7,    37,    46,    34,    34,     8,     9,    10,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,     4,     5,
       6,     7,    46,    37,    46,     4,    18,    51,     4,     5,
       6,    36,    52,    35,    12,    35,    35,    35,    35,    18,
      35,    35,    35,    35,    37,    46,    46,    46,    35,    35,
      35,    35,    35,    37,    12,     4,    37,    52,     9,    10,
      37,     7,    37,    38,     4,     5,    12,    16,    37,    52,
      52,    38,    35,    40,    48,     5,    36,    48,     4,     4,
      34,    39,    44,    45,    47,    49,    50,    53,    54,    55,
      52,    39,    29,    14,    37,    36,    38,    38,    18,    57,
      48,    48,     4,    37,    41,    39,    39,    38,    18,    48,
       4,    58,    34,    39,    39
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
        case 2:
/* Line 1792 of yacc.c  */
#line 81 "solaris.y"
    {
        if (!synTree) synTree = createNode("program", (yyvsp[(2) - (3)].synTree)->value);
        addChild(synTree, (yyvsp[(2) - (3)].synTree));
    }
    break;

  case 3:
/* Line 1792 of yacc.c  */
#line 85 "solaris.y"
    {
        if (!synTree) synTree = createNode("program", (yyvsp[(2) - (3)].synTree)->value);
        addChild(synTree, (yyvsp[(2) - (3)].synTree));
    }
    break;

  case 4:
/* Line 1792 of yacc.c  */
#line 89 "solaris.y"
    {
        if (!synTree) synTree = createNode("program", (yyvsp[(2) - (3)].synTree)->value);
        addChild(synTree, (yyvsp[(2) - (3)].synTree));
    }
    break;

  case 5:
/* Line 1792 of yacc.c  */
#line 93 "solaris.y"
    {
        if (!synTree) synTree = createNode("program", (yyvsp[(2) - (3)].synTree)->value);
        addChild(synTree, (yyvsp[(2) - (3)].synTree));
    }
    break;

  case 6:
/* Line 1792 of yacc.c  */
#line 97 "solaris.y"
    {
        if (!synTree) synTree = createNode("program", (yyvsp[(2) - (3)].synTree)->value);
        addChild(synTree, (yyvsp[(2) - (3)].synTree));
    }
    break;

  case 7:
/* Line 1792 of yacc.c  */
#line 101 "solaris.y"
    {
        if (!synTree) synTree = createNode("program", (yyvsp[(2) - (3)].synTree)->value);
        addChild(synTree, (yyvsp[(2) - (3)].synTree));
    }
    break;

  case 8:
/* Line 1792 of yacc.c  */
#line 105 "solaris.y"
    {
        if (!synTree) synTree = createNode("program", (yyvsp[(2) - (3)].synTree)->value);
        addChild(synTree, (yyvsp[(2) - (3)].synTree));
    }
    break;

  case 9:
/* Line 1792 of yacc.c  */
#line 109 "solaris.y"
    {
        if (!synTree) synTree = createNode("program", (yyvsp[(2) - (3)].synTree)->value);
        addChild(synTree, (yyvsp[(2) - (3)].synTree));
    }
    break;

  case 10:
/* Line 1792 of yacc.c  */
#line 113 "solaris.y"
    {
        if (!synTree) synTree = createNode("program", (yyvsp[(2) - (3)].synTree)->value);
        addChild(synTree, (yyvsp[(2) - (3)].synTree));
    }
    break;

  case 11:
/* Line 1792 of yacc.c  */
#line 117 "solaris.y"
    {
        if (!synTree) synTree = createNode("program", (yyvsp[(2) - (3)].synTree)->value);
        addChild(synTree, (yyvsp[(2) - (3)].synTree));
    }
    break;

  case 12:
/* Line 1792 of yacc.c  */
#line 121 "solaris.y"
    {
        if (!synTree) synTree = createNode("program", (yyvsp[(2) - (3)].synTree)->value);
        addChild(synTree, (yyvsp[(2) - (3)].synTree));
    }
    break;

  case 13:
/* Line 1792 of yacc.c  */
#line 125 "solaris.y"
    {
        if (!synTree) synTree = createNode("program", (yyvsp[(2) - (3)].synTree)->value);
        addChild(synTree, (yyvsp[(2) - (3)].synTree));
    }
    break;

  case 14:
/* Line 1792 of yacc.c  */
#line 129 "solaris.y"
    {

    }
    break;

  case 15:
/* Line 1792 of yacc.c  */
#line 132 "solaris.y"
    {
        if (!synTree) synTree = createNode("program", " ");
    }
    break;

  case 16:
/* Line 1792 of yacc.c  */
#line 138 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        tree variableDeclaration = createNode("variable_declaration", buffer);
        addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE", (yyvsp[(1) - (3)].str)));
        addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", (yyvsp[(2) - (3)].str)));
        addChild(variableDeclaration, createNode(";", ";\n"));
        (yyval.synTree) = variableDeclaration;
    }
    break;

  case 17:
/* Line 1792 of yacc.c  */
#line 149 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s", (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].synTree)->value);
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        tree variableDeclaration = createNode("variable_declaration", buffer);
        addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE", (yyvsp[(1) - (2)].str)));
        addChild(variableDeclaration, (yyvsp[(2) - (2)].synTree));
        (yyval.synTree) = variableDeclaration;
    }
    break;

  case 18:
/* Line 1792 of yacc.c  */
#line 159 "solaris.y"
    {
        check_declaration_exists((yyvsp[(2) - (3)].str));
        processSemanticStructure((yyvsp[(2) - (3)].str), TOKEN_IDENTIFIER, VARIABLE, TOKEN_DATA_TYPE_STRING, 0, 0.0, NULL);

        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        tree variableDeclaration = createNode("variable_declaration", buffer);
        addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE_STRING", (yyvsp[(1) - (3)].str)));
        addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", (yyvsp[(2) - (3)].str)));
        addChild(variableDeclaration, createNode(";", ";\n"));
        (yyval.synTree) = variableDeclaration;
    }
    break;

  case 19:
/* Line 1792 of yacc.c  */
#line 173 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s %s;", (yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str), (yyvsp[(4) - (5)].str));
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        tree variableDeclaration = createNode("variable_declaration", buffer);
        addChild(variableDeclaration, createNode("TOKEN_DATA_TYPE_STRING", (yyvsp[(1) - (5)].str)));
        addChild(variableDeclaration, createNode("TOKEN_IDENTIFIER", (yyvsp[(2) - (5)].str)));
        addChild(variableDeclaration, createNode("TOKEN_ASSIGNMENT_OP", (yyvsp[(3) - (5)].str)));
        addChild(variableDeclaration, createNode("TOKEN_STRING", (yyvsp[(4) - (5)].str)));
        addChild(variableDeclaration, createNode(";", ";\n"));
        (yyval.synTree) = variableDeclaration;
    }
    break;

  case 20:
/* Line 1792 of yacc.c  */
#line 187 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a declaracao de [ %s ] na linha %d\n", (yyvsp[(2) - (2)].str), yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 21:
/* Line 1792 of yacc.c  */
#line 193 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Declaracao de variavel incompleta na linha %d\n", yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 22:
/* Line 1792 of yacc.c  */
#line 199 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a declaracao de [ %s ] na linha %d\n", (yyvsp[(2) - (2)].str), yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 23:
/* Line 1792 of yacc.c  */
#line 205 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a declaracao de [ %s ] na linha %d\n", (yyvsp[(2) - (4)].str), yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 24:
/* Line 1792 of yacc.c  */
#line 213 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s;", (yyvsp[(1) - (4)].str), (yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].str));
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        tree assignment = createNode("assignment", buffer);
        addChild(assignment, createNode("TOKEN_IDENTIFIER", (yyvsp[(1) - (4)].str)));
        addChild(assignment, createNode("TOKEN_ASSIGNMENT_OP", (yyvsp[(2) - (4)].str)));
        addChild(assignment, createNode("TOKEN_IDENTIFIER", (yyvsp[(3) - (4)].str)));
        addChild(assignment, createNode("TOKEN_DELIMITER", ";\n"));

        (yyval.synTree) = assignment;
    }
    break;

  case 25:
/* Line 1792 of yacc.c  */
#line 226 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s;", (yyvsp[(1) - (4)].str), (yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].str), ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        tree assignment = createNode("assignment", buffer);
        addChild(assignment, createNode("TOKEN_IDENTIFIER", (yyvsp[(1) - (4)].str)));
        addChild(assignment, createNode("TOKEN_ASSIGNMENT_OP", (yyvsp[(2) - (4)].str)));
        addChild(assignment, createNode("TOKEN_STRING", (yyvsp[(3) - (4)].str)));
        addChild(assignment, createNode("TOKEN_DELIMITER", ";\n"));

        (yyval.synTree) = assignment;
    }
    break;

  case 26:
/* Line 1792 of yacc.c  */
#line 239 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s;", (yyvsp[(1) - (4)].str), (yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].str), ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        tree assignment = createNode("assignment", buffer);
        addChild(assignment, createNode("TOKEN_IDENTIFIER", (yyvsp[(1) - (4)].str)));
        addChild(assignment, createNode("TOKEN_ASSIGNMENT_OP", (yyvsp[(2) - (4)].str)));
        addChild(assignment, createNode("TOKEN_INTEGER_NUMBER", (yyvsp[(3) - (4)].str)));
        addChild(assignment, createNode("TOKEN_DELIMITER", ";\n"));

        (yyval.synTree) = assignment;
    }
    break;

  case 27:
/* Line 1792 of yacc.c  */
#line 252 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s;", (yyvsp[(1) - (4)].str), (yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].str), ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        tree assignment = createNode("assignment", buffer);
        addChild(assignment, createNode("TOKEN_IDENTIFIER", (yyvsp[(1) - (4)].str)));
        addChild(assignment, createNode("TOKEN_ASSIGNMENT_OP", (yyvsp[(2) - (4)].str)));
        addChild(assignment, createNode("TOKEN_FLOAT_NUMBER", (yyvsp[(3) - (4)].str)));
        addChild(assignment, createNode("TOKEN_DELIMITER", ";\n"));

        (yyval.synTree) = assignment;
    }
    break;

  case 28:
/* Line 1792 of yacc.c  */
#line 265 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s;", (yyvsp[(1) - (4)].str), (yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].synTree)->value, ';');
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        tree assignment = createNode("assignment", buffer);
        addChild(assignment, createNode("TOKEN_IDENTIFIER", (yyvsp[(1) - (4)].str)));
        addChild(assignment, createNode("TOKEN_ASSIGNMENT_OP", (yyvsp[(2) - (4)].str)));
        addChild(assignment, (yyvsp[(3) - (4)].synTree));
        addChild(assignment, createNode("TOKEN_DELIMITER", ";\n"));

        (yyval.synTree) = assignment;
    }
    break;

  case 29:
/* Line 1792 of yacc.c  */
#line 279 "solaris.y"
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
#line 287 "solaris.y"
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
#line 295 "solaris.y"
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
#line 303 "solaris.y"
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
#line 311 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].synTree));
        sprintf(synErrorMessage, "Erro: Falta de ponto e virgula ';' apos a atribuicao [ %s ] na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 34:
/* Line 1792 of yacc.c  */
#line 319 "solaris.y"
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
#line 329 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].synTree)->value, (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].synTree)->value);
        processSyntacticStructure(SYN_ARITHMETIC_OPERATION, buffer);

        tree expression = createNode("expression", buffer);
        addChild(expression, (yyvsp[(1) - (3)].synTree));
        addChild(expression, createNode("TOKEN_ASSIGNMENT_OP", (yyvsp[(2) - (3)].str)));
        addChild(expression, (yyvsp[(3) - (3)].synTree));
        (yyval.synTree) = expression;
    }
    break;

  case 36:
/* Line 1792 of yacc.c  */
#line 340 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].synTree)->value, (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].synTree)->value);
        processSyntacticStructure(SYN_RELATIONAL_OPERATION, buffer);

        tree expression = createNode("expression", buffer);
        addChild(expression, (yyvsp[(1) - (3)].synTree));
        addChild(expression, createNode("TOKEN_ASSIGNMENT_OP", (yyvsp[(2) - (3)].str)));
        addChild(expression, (yyvsp[(3) - (3)].synTree));
        (yyval.synTree) = expression;
    }
    break;

  case 37:
/* Line 1792 of yacc.c  */
#line 351 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].synTree)->value, (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].synTree)->value);
        processSyntacticStructure(SYN_LOGICAL_OPERATION, buffer);

        tree expression = createNode("expression", buffer);
        addChild(expression, (yyvsp[(1) - (3)].synTree));
        addChild(expression, createNode("TOKEN_ASSIGNMENT_OP", (yyvsp[(2) - (3)].str)));
        addChild(expression, (yyvsp[(3) - (3)].synTree));
        (yyval.synTree) = expression;
    }
    break;

  case 38:
/* Line 1792 of yacc.c  */
#line 362 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "( %s )", (yyvsp[(2) - (3)].synTree)->value);
        processSyntacticStructure(SYN_OPERATION, buffer);

        tree expression = createNode("expression", buffer);
        addChild(expression, createNode("(", "("));
        addChild(expression, (yyvsp[(2) - (3)].synTree));
        addChild(expression, createNode(")", ")"));
        (yyval.synTree) = expression;
    }
    break;

  case 39:
/* Line 1792 of yacc.c  */
#line 373 "solaris.y"
    {
        tree expression = createNode("expression", (yyvsp[(1) - (1)].str));
        addChild(expression, createNode("TOKEN_IDENTIFIER", (yyvsp[(1) - (1)].str)));
        (yyval.synTree) = expression;
    }
    break;

  case 40:
/* Line 1792 of yacc.c  */
#line 378 "solaris.y"
    {
        tree expression = createNode("expression", (yyvsp[(1) - (1)].str));
        addChild(expression, createNode("TOKEN_INTEGER_NUMBER", (yyvsp[(1) - (1)].str)));
        (yyval.synTree) = expression;
    }
    break;

  case 41:
/* Line 1792 of yacc.c  */
#line 383 "solaris.y"
    {
        tree expression = createNode("expression", (yyvsp[(1) - (1)].str));
        addChild(expression, createNode("TOKEN_FLOAT_NUMBER", (yyvsp[(1) - (1)].str)));
        (yyval.synTree) = expression;
    }
    break;

  case 42:
/* Line 1792 of yacc.c  */
#line 389 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s", (yyvsp[(1) - (2)].synTree), (yyvsp[(2) - (2)].str));
        sprintf(synErrorMessage, "Erro: Operacao incompleta apos operador '%s' na linha %d\n", (yyvsp[(2) - (2)].str), yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 43:
/* Line 1792 of yacc.c  */
#line 397 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Operacao incompleta entre parenteses na linha %d\n", yylineno + 1);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 44:
/* Line 1792 of yacc.c  */
#line 403 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "( %s", (yyvsp[(2) - (2)].synTree)->value);
        sprintf(synErrorMessage, "Erro: Operacao com fechamento de parenteses incompleto '%s' na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 45:
/* Line 1792 of yacc.c  */
#line 411 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s", (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].synTree)->value);
        sprintf(synErrorMessage, "Erro: Operacao incompleta '%s' na linha %d\n", buffer, yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 46:
/* Line 1792 of yacc.c  */
#line 419 "solaris.y"
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
#line 429 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %c %s %c %c %s %c", (yyvsp[(1) - (7)].str), '(', (yyvsp[(3) - (7)].synTree)->value, ')', '{', (yyvsp[(6) - (7)].synTree)->value, '}');
        processSyntacticStructure(SYN_CONDITIONAL_CHOOSE, buffer);

        tree conditional = createNode("conditional", buffer);
        addChild(conditional, createNode("TOKEN_CONDITIONAL_CHOOSE", (yyvsp[(1) - (7)].str)));
        addChild(conditional, createNode("(", "("));
        addChild(conditional, (yyvsp[(3) - (7)].synTree));
        addChild(conditional, createNode(")", ")"));
        addChild(conditional, createNode("{", "{"));
        addChild(conditional, (yyvsp[(6) - (7)].synTree));
        addChild(conditional, createNode("}", "}\n"));
        (yyval.synTree) = conditional;
    }
    break;

  case 48:
/* Line 1792 of yacc.c  */
#line 444 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %c %s %c %c %s %c %s %c %s %c", (yyvsp[(1) - (11)].str), '(', (yyvsp[(3) - (11)].synTree)->value, ')', '{', (yyvsp[(6) - (11)].synTree)->value, '}', (yyvsp[(8) - (11)].str), '{', (yyvsp[(10) - (11)].synTree)->value, '}');
        processSyntacticStructure(SYN_CONDITIONAL_CHOOSE, buffer);

        tree conditional = createNode("conditional", buffer);
        addChild(conditional, createNode("TOKEN_CONDITIONAL_CHOOSE", (yyvsp[(1) - (11)].str)));
        addChild(conditional, createNode("(", "("));
        addChild(conditional, (yyvsp[(3) - (11)].synTree));
        addChild(conditional, createNode(")", ")"));
        addChild(conditional, createNode("{", "{"));
        addChild(conditional, (yyvsp[(6) - (11)].synTree));
        addChild(conditional, createNode("}", "}"));
        addChild(conditional, createNode("TOKEN_CONDITIONAL_OTHERWISE", (yyvsp[(8) - (11)].str)));
        addChild(conditional, createNode("{", "{"));
        addChild(conditional, (yyvsp[(10) - (11)].synTree));
        addChild(conditional, createNode("}", "}\n"));
        (yyval.synTree) = conditional;
    }
    break;

  case 49:
/* Line 1792 of yacc.c  */
#line 464 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Falta de fechamento de parenteses no condicional na linha %d\n", yylineno + 1);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 50:
/* Line 1792 of yacc.c  */
#line 470 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Condicional sem expressao na linha %d\n", yylineno +1 );
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 51:
/* Line 1792 of yacc.c  */
#line 476 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Falta de abertura de bloco '{' no condicional na linha %d\n", yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 52:
/* Line 1792 of yacc.c  */
#line 482 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Bloco 'otherwise' incompleto na linha %d\n", yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 53:
/* Line 1792 of yacc.c  */
#line 488 "solaris.y"
    {
        sprintf(synErrorMessage, "Erro: Falta de fechamento de bloco '}' no condicional na linha %d\n", yylineno);
        processSyntacticStructure(SYN_ERROR, synErrorMessage);
        exit(EXIT_FAILURE);
    }
    break;

  case 54:
/* Line 1792 of yacc.c  */
#line 496 "solaris.y"
    {
        tree possible_content = createNode("possible_content", " ");
        (yyval.synTree) = possible_content;
    }
    break;

  case 55:
/* Line 1792 of yacc.c  */
#line 500 "solaris.y"
    {
        addChild((yyvsp[(1) - (2)].synTree), createNode("\\n", "\\n"));
        (yyval.synTree) = (yyvsp[(1) - (2)].synTree);
    }
    break;

  case 56:
/* Line 1792 of yacc.c  */
#line 504 "solaris.y"
    {
        addChild((yyvsp[(1) - (2)].synTree), (yyvsp[(2) - (2)].synTree));
        (yyval.synTree) = (yyvsp[(1) - (2)].synTree);
    }
    break;

  case 57:
/* Line 1792 of yacc.c  */
#line 508 "solaris.y"
    {
        addChild((yyvsp[(1) - (2)].synTree), (yyvsp[(2) - (2)].synTree));
        (yyval.synTree) = (yyvsp[(1) - (2)].synTree);
    }
    break;

  case 58:
/* Line 1792 of yacc.c  */
#line 512 "solaris.y"
    {
        addChild((yyvsp[(1) - (2)].synTree), (yyvsp[(2) - (2)].synTree));
        (yyval.synTree) = (yyvsp[(1) - (2)].synTree);
    }
    break;

  case 59:
/* Line 1792 of yacc.c  */
#line 516 "solaris.y"
    {
        addChild((yyvsp[(1) - (2)].synTree), (yyvsp[(2) - (2)].synTree));
        (yyval.synTree) = (yyvsp[(1) - (2)].synTree);
    }
    break;

  case 60:
/* Line 1792 of yacc.c  */
#line 520 "solaris.y"
    {
        addChild((yyvsp[(1) - (2)].synTree), (yyvsp[(2) - (2)].synTree));
        (yyval.synTree) = (yyvsp[(1) - (2)].synTree);
    }
    break;

  case 61:
/* Line 1792 of yacc.c  */
#line 524 "solaris.y"
    {
        addChild((yyvsp[(1) - (2)].synTree), (yyvsp[(2) - (2)].synTree));
        (yyval.synTree) = (yyvsp[(1) - (2)].synTree);
    }
    break;

  case 62:
/* Line 1792 of yacc.c  */
#line 528 "solaris.y"
    {
        addChild((yyvsp[(1) - (2)].synTree), (yyvsp[(2) - (2)].synTree));
        (yyval.synTree) = (yyvsp[(1) - (2)].synTree);
    }
    break;

  case 63:
/* Line 1792 of yacc.c  */
#line 532 "solaris.y"
    {
        addChild((yyvsp[(1) - (2)].synTree), (yyvsp[(2) - (2)].synTree));
        (yyval.synTree) = (yyvsp[(1) - (2)].synTree);
    }
    break;

  case 64:
/* Line 1792 of yacc.c  */
#line 539 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) %s ( %s ) { %s }", (yyvsp[(1) - (11)].str), (yyvsp[(3) - (11)].synTree)->value, (yyvsp[(5) - (11)].str), (yyvsp[(7) - (11)].synTree)->value, (yyvsp[(10) - (11)].synTree)->value);
        processSyntacticStructure(SYN_LOOP, buffer);

        tree loop = createNode("loop", buffer);
        addChild(loop, createNode("TOKEN_LOOP", (yyvsp[(1) - (11)].str)));
        addChild(loop, createNode("(", "("));
        addChild(loop, (yyvsp[(3) - (11)].synTree));
        addChild(loop, createNode(")", ")"));
        addChild(loop, createNode("TOKEN_LOOP_UNTIL", (yyvsp[(5) - (11)].str)));
        addChild(loop, createNode("(", "("));
        addChild(loop, (yyvsp[(7) - (11)].synTree));
        addChild(loop, createNode(")", ")"));
        addChild(loop, createNode("{", "{"));
        addChild(loop, (yyvsp[(10) - (11)].synTree));
        addChild(loop, createNode("}", "}\n"));
        (yyval.synTree) = loop;
    }
    break;

  case 65:
/* Line 1792 of yacc.c  */
#line 561 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) { %s }", (yyvsp[(1) - (7)].str), (yyvsp[(3) - (7)].synTree)->value, (yyvsp[(6) - (7)].synTree)->value);
        processSyntacticStructure(SYN_LOOP_WHILE, buffer);

        tree loop_while = createNode("loop_while", buffer);
        addChild(loop_while, createNode("TOKEN_LOOP_WHILE", (yyvsp[(1) - (7)].str)));
        addChild(loop_while, createNode("(", "("));
        addChild(loop_while, (yyvsp[(3) - (7)].synTree));
        addChild(loop_while, createNode(")", ")"));
        addChild(loop_while, createNode("{", "{"));
        addChild(loop_while, (yyvsp[(6) - (7)].synTree));
        addChild(loop_while, createNode("}", "}\n"));
        (yyval.synTree) = loop_while;
    }
    break;

  case 66:
/* Line 1792 of yacc.c  */
#line 579 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        tree loop_start = createNode("loop_start", buffer);
        addChild(loop_start, createNode("TOKEN_IDENTIFIER", (yyvsp[(1) - (3)].str)));
        addChild(loop_start, createNode("TOKEN_ASSIGNMENT_OP", (yyvsp[(2) - (3)].str)));
        addChild(loop_start, createNode("TOKEN_INTEGER_NUMBER", (yyvsp[(3) - (3)].str)));
        (yyval.synTree) = loop_start;
    }
    break;

  case 67:
/* Line 1792 of yacc.c  */
#line 590 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].str));
        processSyntacticStructure(SYN_ASSIGNMENT, buffer);

        tree loop_start = createNode("loop_start", buffer);
        addChild(loop_start, createNode("TOKEN_IDENTIFIER", (yyvsp[(1) - (3)].str)));
        addChild(loop_start, createNode("TOKEN_ASSIGNMENT_OP", (yyvsp[(2) - (3)].str)));
        addChild(loop_start, createNode("TOKEN_IDENTIFIER", (yyvsp[(3) - (3)].str)));
        (yyval.synTree) = loop_start;
    }
    break;

  case 68:
/* Line 1792 of yacc.c  */
#line 601 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s %s", (yyvsp[(1) - (4)].str), (yyvsp[(2) - (4)].str), (yyvsp[(3) - (4)].str), (yyvsp[(4) - (4)].str));
        processSyntacticStructure(SYN_VARIABLE_DECLARATION, buffer);

        tree loop_start = createNode("loop_start", buffer);
        addChild(loop_start, createNode("TOKEN_DATA_TYPE", (yyvsp[(1) - (4)].str)));
        addChild(loop_start, createNode("TOKEN_IDENTIFIER", (yyvsp[(2) - (4)].str)));
        addChild(loop_start, createNode("TOKEN_ASSIGNMENT_OP", (yyvsp[(3) - (4)].str)));
        addChild(loop_start, createNode("TOKEN_INTEGER_NUMBER", (yyvsp[(4) - (4)].str)));
        (yyval.synTree) = loop_start;
    }
    break;

  case 69:
/* Line 1792 of yacc.c  */
#line 616 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].synTree)->value, (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].synTree)->value);
        processSyntacticStructure(SYN_RELATIONAL_OPERATION, buffer);

        tree loop_condition = createNode("loop_condition", buffer);
        addChild(loop_condition,(yyvsp[(1) - (3)].synTree));
        addChild(loop_condition, createNode("TOKEN_RELATIONAL_OP", (yyvsp[(2) - (3)].str)));
        addChild(loop_condition, (yyvsp[(3) - (3)].synTree));
        (yyval.synTree) = loop_condition;
    }
    break;

  case 70:
/* Line 1792 of yacc.c  */
#line 627 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s %s", (yyvsp[(1) - (3)].synTree)->value, (yyvsp[(2) - (3)].str), (yyvsp[(3) - (3)].synTree)->value);
        processSyntacticStructure(SYN_LOGICAL_OPERATION, buffer);

        tree loop_condition = createNode("loop_condition", buffer);
        addChild(loop_condition, (yyvsp[(1) - (3)].synTree));
        addChild(loop_condition, createNode("TOKEN_LOGICAL_OP", (yyvsp[(2) - (3)].str)));
        addChild(loop_condition, (yyvsp[(3) - (3)].synTree));
        (yyval.synTree) = loop_condition;
    }
    break;

  case 71:
/* Line 1792 of yacc.c  */
#line 638 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%c %s %c", '(', (yyvsp[(2) - (3)].synTree)->value, ')');

        tree loop_condition = createNode("loop_condition", buffer);
        addChild(loop_condition, createNode("(", "("));
        addChild(loop_condition, (yyvsp[(2) - (3)].synTree));
        addChild(loop_condition, createNode(")", ")"));
        (yyval.synTree) = loop_condition;
    }
    break;

  case 72:
/* Line 1792 of yacc.c  */
#line 648 "solaris.y"
    {
        tree loop_condition = createNode("loop_condition", (yyvsp[(1) - (1)].str));
        addChild(loop_condition, createNode("TOKEN_IDENTIFIER", (yyvsp[(1) - (1)].str)));
        (yyval.synTree) = loop_condition;
    }
    break;

  case 73:
/* Line 1792 of yacc.c  */
#line 653 "solaris.y"
    {
        tree loop_condition = createNode("loop_condition", (yyvsp[(1) - (1)].str));
        addChild(loop_condition, createNode("TOKEN_INTEGER_NUMBER", (yyvsp[(1) - (1)].str)));
        (yyval.synTree) = loop_condition;
    }
    break;

  case 74:
/* Line 1792 of yacc.c  */
#line 658 "solaris.y"
    {
        tree loop_condition = createNode("loop_condition", (yyvsp[(1) - (1)].str));
        addChild(loop_condition, createNode("TOKEN_FLOAT_NUMBER", (yyvsp[(1) - (1)].str)));
        (yyval.synTree) = loop_condition;
    }
    break;

  case 75:
/* Line 1792 of yacc.c  */
#line 666 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s", (yyvsp[(1) - (1)].str));
        processSyntacticStructure(SYN_COMMENT_LINE, buffer);

        tree comment = createNode("comment", buffer);
        addChild(comment, createNode("TOKEN_COMMENT_LINE", strcat((yyvsp[(1) - (1)].str), "\n")));
        (yyval.synTree) = comment;
    }
    break;

  case 76:
/* Line 1792 of yacc.c  */
#line 675 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s", (yyvsp[(1) - (1)].str));
        processSyntacticStructure(SYN_COMMENT_BLOCK, buffer);

        tree comment = createNode("comment", buffer);
        addChild(comment, createNode("TOKEN_COMMENT_BLOCK", strcat((yyvsp[(1) - (1)].str), "\n")));
        (yyval.synTree) = comment;
    }
    break;

  case 77:
/* Line 1792 of yacc.c  */
#line 687 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
        processSyntacticStructure(SYN_WRITE_DATA, buffer);

        tree write_data = createNode("write_data", buffer);
        addChild(write_data, createNode("TOKEN_SHOW", (yyvsp[(1) - (3)].str)));
        addChild(write_data, createNode("TOKEN_IDENTIFIER", (yyvsp[(2) - (3)].str)));
        addChild(write_data, createNode(";", ";\n"));
        (yyval.synTree) = write_data;
    }
    break;

  case 78:
/* Line 1792 of yacc.c  */
#line 698 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
        processSyntacticStructure(SYN_WRITE_DATA, buffer);

        tree write_data = createNode("write_data", buffer);
        addChild(write_data, createNode("TOKEN_SHOW", (yyvsp[(1) - (3)].str)));
        addChild(write_data, createNode("TOKEN_STRING", (yyvsp[(2) - (3)].str)));
        addChild(write_data, createNode(";", ";\n"));
        (yyval.synTree) = write_data;
    }
    break;

  case 79:
/* Line 1792 of yacc.c  */
#line 712 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
        processSyntacticStructure(SYN_READ_DATA, buffer);

        tree read_data = createNode("read_data", buffer);
        addChild(read_data, createNode("TOKEN_READ", (yyvsp[(1) - (3)].str)));
        addChild(read_data, createNode("TOKEN_IDENTIFIER", (yyvsp[(2) - (3)].str)));
        addChild(read_data, createNode(";", ";\n"));
        (yyval.synTree) = read_data;
    }
    break;

  case 80:
/* Line 1792 of yacc.c  */
#line 726 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) : %s %s ( %s ) { %s %s }", (yyvsp[(1) - (14)].str), (yyvsp[(3) - (14)].str), (yyvsp[(6) - (14)].str), (yyvsp[(7) - (14)].str), (yyvsp[(9) - (14)].synTree)->value, (yyvsp[(12) - (14)].synTree)->value, (yyvsp[(13) - (14)].synTree)->value);
        processSyntacticStructure(SYN_FUNCTION_DECLARATION, buffer);

        tree function_declaration = createNode("function_declaration", buffer);
        addChild(function_declaration, createNode("TOKEN_FUNCTION", (yyvsp[(1) - (14)].str)));
        addChild(function_declaration, createNode("(", "("));
        addChild(function_declaration, createNode("TOKEN_DATA_TYPE", (yyvsp[(3) - (14)].str)));
        addChild(function_declaration, createNode(")", ")"));
        addChild(function_declaration, createNode(":", ":"));
        addChild(function_declaration, createNode("TOKEN_IDENTIFIER", (yyvsp[(6) - (14)].str)));
        addChild(function_declaration, createNode("TOKEN_FUNCTION_RECEIVE", (yyvsp[(7) - (14)].str)));
        addChild(function_declaration, createNode("(", "("));
        addChild(function_declaration, (yyvsp[(9) - (14)].synTree));
        addChild(function_declaration, createNode(")", ")"));
        addChild(function_declaration, createNode("{", "{"));
        addChild(function_declaration, (yyvsp[(12) - (14)].synTree));
        addChild(function_declaration, (yyvsp[(13) - (14)].synTree));
        addChild(function_declaration, createNode("}", "}"));
        (yyval.synTree) = function_declaration;
    }
    break;

  case 81:
/* Line 1792 of yacc.c  */
#line 748 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s ( %s ) : %s %s ( %s ) { %s %s }", (yyvsp[(1) - (15)].str), (yyvsp[(3) - (15)].str), (yyvsp[(6) - (15)].str), (yyvsp[(7) - (15)].str), (yyvsp[(9) - (15)].synTree)->value, (yyvsp[(12) - (15)].synTree)->value, (yyvsp[(13) - (15)].synTree)->value);
        processSyntacticStructure(SYN_FUNCTION_DECLARATION, buffer);

        tree function_declaration = createNode("function_declaration", buffer);
        addChild(function_declaration, createNode("TOKEN_FUNCTION", (yyvsp[(1) - (15)].str)));
        addChild(function_declaration, createNode("(", "("));
        addChild(function_declaration, createNode("TOKEN_DATA_TYPE", (yyvsp[(3) - (15)].str)));
        addChild(function_declaration, createNode(")", ")"));
        addChild(function_declaration, createNode(":", ":"));
        addChild(function_declaration, createNode("TOKEN_IDENTIFIER", (yyvsp[(6) - (15)].str)));
        addChild(function_declaration, createNode("TOKEN_FUNCTION_RECEIVE", (yyvsp[(7) - (15)].str)));
        addChild(function_declaration, createNode("(", "("));
        addChild(function_declaration, (yyvsp[(9) - (15)].synTree));
        addChild(function_declaration, createNode(")", ")"));
        addChild(function_declaration, createNode("{", "{"));
        addChild(function_declaration, (yyvsp[(12) - (15)].synTree));
        addChild(function_declaration, (yyvsp[(13) - (15)].synTree));
        addChild(function_declaration, createNode("}", "}"));
        (yyval.synTree) = function_declaration;
    }
    break;

  case 82:
/* Line 1792 of yacc.c  */
#line 773 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s", (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].str));

        tree function_parameter = createNode("function_parameter", buffer);
        addChild(function_parameter, createNode("TOKEN_DATA_TYPE", (yyvsp[(1) - (2)].str)));
        addChild(function_parameter, createNode("TOKEN_IDENTIFIER", (yyvsp[(2) - (2)].str)));
        (yyval.synTree) = function_parameter;
    }
    break;

  case 83:
/* Line 1792 of yacc.c  */
#line 782 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s, %s %s", (yyvsp[(1) - (4)].synTree)->value, (yyvsp[(3) - (4)].str), (yyvsp[(4) - (4)].str));

        tree function_parameter = createNode("function_parameter", buffer);
        addChild(function_parameter, (yyvsp[(1) - (4)].synTree));
        addChild(function_parameter, createNode(",", ","));
        addChild(function_parameter, createNode("TOKEN_DATA_TYPE", (yyvsp[(3) - (4)].str)));
        addChild(function_parameter, createNode("TOKEN_IDENTIFIER", (yyvsp[(4) - (4)].str)));
        (yyval.synTree) = function_parameter;
    }
    break;

  case 84:
/* Line 1792 of yacc.c  */
#line 796 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
        processSyntacticStructure(SYN_FUNCTION_RETURN, buffer);

        tree function_return = createNode("function_return", buffer);
        addChild(function_return, createNode("TOKEN_FUNCTION_RETURN", (yyvsp[(1) - (3)].str)));
        addChild(function_return, createNode("TOKEN_IDENTIFIER", (yyvsp[(2) - (3)].str)));
        addChild(function_return, createNode(";", ";\n"));
        (yyval.synTree) = function_return;
    }
    break;

  case 85:
/* Line 1792 of yacc.c  */
#line 807 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
        processSyntacticStructure(SYN_FUNCTION_RETURN, buffer);

        tree function_return = createNode("function_return", buffer);
        addChild(function_return, createNode("TOKEN_FUNCTION_RETURN", (yyvsp[(1) - (3)].str)));
        addChild(function_return, createNode("TOKEN_STRING", (yyvsp[(2) - (3)].str)));
        addChild(function_return, createNode(";", ";\n"));
        (yyval.synTree) = function_return;
    }
    break;

  case 86:
/* Line 1792 of yacc.c  */
#line 818 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
        processSyntacticStructure(SYN_FUNCTION_RETURN, buffer);

        tree function_return = createNode("function_return", buffer);
        addChild(function_return, createNode("TOKEN_FUNCTION_RETURN", (yyvsp[(1) - (3)].str)));
        addChild(function_return, createNode("TOKEN_INTEGER_NUMBER", (yyvsp[(2) - (3)].str)));
        addChild(function_return, createNode(";", ";\n"));
        (yyval.synTree) = function_return;
    }
    break;

  case 87:
/* Line 1792 of yacc.c  */
#line 829 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", (yyvsp[(1) - (3)].str), (yyvsp[(2) - (3)].str));
        processSyntacticStructure(SYN_FUNCTION_RETURN, buffer);

        tree function_return = createNode("function_return", buffer);
        addChild(function_return, createNode("TOKEN_FUNCTION_RETURN", (yyvsp[(1) - (3)].str)));
        addChild(function_return, createNode("TOKEN_FLOAT_NUMBER", (yyvsp[(2) - (3)].str)));
        addChild(function_return, createNode(";", ";\n"));
        (yyval.synTree) = function_return;
    }
    break;

  case 88:
/* Line 1792 of yacc.c  */
#line 843 "solaris.y"
    {
        char buffer[MAXBUFFER];
        sprintf(buffer, "%s %s;", (yyvsp[(1) - (2)].str), (yyvsp[(2) - (2)].str));
        processSyntacticStructure(SYN_LIBRARY_INCLUSION, buffer);

        tree library_inclusion = createNode("library_inclusion", buffer);
        addChild(library_inclusion, createNode("TOKEN_USE", (yyvsp[(1) - (2)].str)));
        addChild(library_inclusion, createNode("TOKEN_STRING", (yyvsp[(2) - (2)].str)));
        addChild(library_inclusion, createNode(";", ";\n"));
        (yyval.synTree) = library_inclusion;
    }
    break;


/* Line 1792 of yacc.c  */
#line 2698 "solaris.tab.c"
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
#line 855 "solaris.y"


void yyerror(const char *s) {
    fprintf(stderr, "Erro sintatico na linha %d proximo a '%s': %s\n", yylineno, yytext, s);
    exit(EXIT_FAILURE);
}
