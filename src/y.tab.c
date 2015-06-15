/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "yacc.y" /* yacc.c:339  */


#include <iostream>
#include <string>
#include "../include/AstHead.h"

/*using namespace std;*/

extern "C"{
int yyparse(void);
int yyerror(const char *msg);
int yylex(void);
int yywrap(void);
}
extern int yycolumn;
extern int yylineno;

#line 84 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    IDENTIFIER = 258,
    CONSTANT = 259,
    INTEGER_CONSTANT = 260,
    CHARACTER_CONSTANT = 261,
    FLOATING_CONSTANT = 262,
    STRING_LITERAL = 263,
    SIZEOF = 264,
    PTR_OP = 265,
    INC_OP = 266,
    DEC_OP = 267,
    LEFT_OP = 268,
    RIGHT_OP = 269,
    LE_OP = 270,
    GE_OP = 271,
    EQ_OP = 272,
    NE_OP = 273,
    NEW_OP = 274,
    DELETE_OP = 275,
    AND_OP = 276,
    OR_OP = 277,
    MUL_ASSIGN = 278,
    DIV_ASSIGN = 279,
    MOD_ASSIGN = 280,
    ADD_ASSIGN = 281,
    SUB_ASSIGN = 282,
    LEFT_ASSIGN = 283,
    RIGHT_ASSIGN = 284,
    AND_ASSIGN = 285,
    XOR_ASSIGN = 286,
    OR_ASSIGN = 287,
    TYPE_NAME = 288,
    TYPEDEF = 289,
    EXTERN = 290,
    STATIC = 291,
    AUTO = 292,
    REGISTER = 293,
    CHAR = 294,
    SHORT = 295,
    INT = 296,
    LONG = 297,
    SIGNED = 298,
    UNSIGNED = 299,
    FLOAT = 300,
    DOUBLE = 301,
    CONST = 302,
    VOLATILE = 303,
    VOID = 304,
    VIRTUAL = 305,
    STRUCT = 306,
    UNION = 307,
    CLASS = 308,
    ENUM = 309,
    ELLIPSIS = 310,
    CASE = 311,
    DEFAULT = 312,
    IF = 313,
    ELSE = 314,
    SWITCH = 315,
    WHILE = 316,
    DO = 317,
    FOR = 318,
    GOTO = 319,
    CONTINUE = 320,
    BREAK = 321,
    RETURN = 322,
    LOWER_THAN_ELSE = 323
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define CONSTANT 259
#define INTEGER_CONSTANT 260
#define CHARACTER_CONSTANT 261
#define FLOATING_CONSTANT 262
#define STRING_LITERAL 263
#define SIZEOF 264
#define PTR_OP 265
#define INC_OP 266
#define DEC_OP 267
#define LEFT_OP 268
#define RIGHT_OP 269
#define LE_OP 270
#define GE_OP 271
#define EQ_OP 272
#define NE_OP 273
#define NEW_OP 274
#define DELETE_OP 275
#define AND_OP 276
#define OR_OP 277
#define MUL_ASSIGN 278
#define DIV_ASSIGN 279
#define MOD_ASSIGN 280
#define ADD_ASSIGN 281
#define SUB_ASSIGN 282
#define LEFT_ASSIGN 283
#define RIGHT_ASSIGN 284
#define AND_ASSIGN 285
#define XOR_ASSIGN 286
#define OR_ASSIGN 287
#define TYPE_NAME 288
#define TYPEDEF 289
#define EXTERN 290
#define STATIC 291
#define AUTO 292
#define REGISTER 293
#define CHAR 294
#define SHORT 295
#define INT 296
#define LONG 297
#define SIGNED 298
#define UNSIGNED 299
#define FLOAT 300
#define DOUBLE 301
#define CONST 302
#define VOLATILE 303
#define VOID 304
#define VIRTUAL 305
#define STRUCT 306
#define UNION 307
#define CLASS 308
#define ENUM 309
#define ELLIPSIS 310
#define CASE 311
#define DEFAULT 312
#define IF 313
#define ELSE 314
#define SWITCH 315
#define WHILE 316
#define DO 317
#define FOR 318
#define GOTO 319
#define CONTINUE 320
#define BREAK 321
#define RETURN 322
#define LOWER_THAN_ELSE 323

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 21 "yacc.y" /* yacc.c:355  */

   string* yystring;
   NodeAst* pnode;

#line 265 "y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 280 "y.tab.c" /* yacc.c:358  */

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
#define YYFINAL  30
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1232

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  90
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  192
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  314

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   323

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    88,     2,     2,     2,    85,    86,     2,
      75,    76,    79,    82,    70,    83,    89,    84,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    74,    69,
      80,    71,    81,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    77,     2,    78,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    72,     2,    73,    87,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   131,   131,   140,   145,   157,   164,   173,   182,   189,
     198,   203,   214,   219,   226,   231,   238,   243,   252,   258,
     264,   270,   276,   284,   290,   296,   302,   308,   314,   320,
     326,   332,   343,   350,   356,   362,   370,   375,   384,   391,
     400,   407,   412,   419,   509,   517,   525,   535,   540,   549,
     556,   563,   572,   577,   586,   641,   648,   655,   663,   668,
     675,   682,   689,   696,   707,   712,   717,   722,   729,   734,
     745,   750,   757,   762,   771,   778,   783,   794,   800,   810,
     817,   826,   831,   841,   846,   855,   860,   865,   872,   877,
     882,   887,   892,   897,   902,   907,   912,   921,   926,   931,
     936,   941,   946,   953,   961,   968,   977,   983,   992,   998,
    1005,  1012,  1021,  1026,  1035,  1042,  1049,  1058,  1065,  1072,
    1081,  1089,  1095,  1101,  1107,  1118,  1123,  1132,  1139,  1146,
    1154,  1164,  1170,  1176,  1182,  1187,  1193,  1199,  1204,  1209,
    1214,  1219,  1226,  1233,  1240,  1245,  1254,  1259,  1307,  1312,
    1319,  1328,  1333,  1340,  1347,  1354,  1382,  1387,  1394,  1403,
    1408,  1415,  1422,  1429,  1434,  1441,  1446,  1453,  1460,  1467,
    1474,  1479,  1484,  1490,  1496,  1501,  1508,  1513,  1520,  1527,
    1534,  1542,  1547,  1554,  1563,  1571,  1578,  1586,  1595,  1602,
    1611,  1617,  1623
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "CONSTANT",
  "INTEGER_CONSTANT", "CHARACTER_CONSTANT", "FLOATING_CONSTANT",
  "STRING_LITERAL", "SIZEOF", "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP",
  "RIGHT_OP", "LE_OP", "GE_OP", "EQ_OP", "NE_OP", "NEW_OP", "DELETE_OP",
  "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN", "AND_ASSIGN",
  "XOR_ASSIGN", "OR_ASSIGN", "TYPE_NAME", "TYPEDEF", "EXTERN", "STATIC",
  "AUTO", "REGISTER", "CHAR", "SHORT", "INT", "LONG", "SIGNED", "UNSIGNED",
  "FLOAT", "DOUBLE", "CONST", "VOLATILE", "VOID", "VIRTUAL", "STRUCT",
  "UNION", "CLASS", "ENUM", "ELLIPSIS", "CASE", "DEFAULT", "IF", "ELSE",
  "SWITCH", "WHILE", "DO", "FOR", "GOTO", "CONTINUE", "BREAK", "RETURN",
  "LOWER_THAN_ELSE", "';'", "','", "'='", "'{'", "'}'", "':'", "'('",
  "')'", "'['", "']'", "'*'", "'<'", "'>'", "'+'", "'-'", "'/'", "'%'",
  "'&'", "'~'", "'!'", "'.'", "$accept", "program_start",
  "translation_unit", "external_declaration", "function_definition",
  "declaration", "declaration_list", "declaration_specifiers",
  "storage_class_specifier", "type_specifier", "type_qualifier",
  "init_declarator_list", "init_declarator", "specifier_qualifier_list",
  "class_specifier", "class_declaration_list", "class_declaration",
  "class_declarator_list", "class_declarator", "declarator",
  "direct_declarator", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "initializer", "initializer_list", "type_name",
  "abstract_declarator", "direct_abstract_declarator", "statement",
  "labeled_statement", "expression_statement", "compound_statement",
  "statement_list", "selection_statement", "iteration_statement",
  "jump_statement", "expression", "assignment_expression",
  "assignment_operator", "conditional_expression", "constant_expression",
  "logical_or_expression", "logical_and_expression", "equality_expression",
  "relational_expression", "additive_expression",
  "multiplicative_expression", "cast_expression", "unary_expression",
  "unary_operator", "postfix_expression", "primary_expression",
  "argument_expression_list", "constant_value", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,    59,
      44,    61,   123,   125,    58,    40,    41,    91,    93,    42,
      60,    62,    43,    45,    47,    37,    38,   126,    33,    46
};
# endif

#define YYPACT_NINF -189

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-189)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1179,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,  -189,  -189,  -189,  -189,    31,    75,
    1179,  -189,  -189,  -189,    11,  1179,  1179,  1179,  -189,   -19,
    -189,  -189,  -189,  -189,    13,    -2,   125,  -189,   127,     4,
      19,  -189,  -189,  -189,  1048,    56,    49,  -189,  -189,    -2,
    -189,    13,   544,   209,  -189,   381,   316,     4,   431,   431,
      13,   985,  -189,    34,  -189,  -189,    87,  -189,  -189,  -189,
    -189,    28,  -189,  -189,  -189,  -189,  -189,   898,   898,   898,
     136,   153,   544,   602,  -189,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,   155,   143,   184,   116,   148,    66,  -189,
     142,   908,    59,  -189,  -189,   130,   908,   149,   135,   151,
     157,   651,   167,   188,   199,   208,   737,  -189,  -189,  -189,
     295,    11,  -189,  -189,  -189,  -189,   430,  -189,  -189,  -189,
     165,  -189,  -189,    23,   203,   210,  -189,    -8,  -189,  -189,
     205,  -189,  -189,  -189,   169,    34,  -189,  -189,  -189,   282,
    1048,   802,  -189,  -189,  -189,   211,  -189,  -189,    51,   113,
     213,     2,   908,   908,   908,   908,   908,   908,   908,   908,
     908,   908,   908,   908,   908,  -189,  -189,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,  -189,  -189,   802,  -189,   284,  -189,
    -189,   755,   802,   287,   651,   219,   651,   802,   802,   802,
     233,   775,   230,  -189,  -189,  -189,   171,  -189,  -189,   516,
    -189,  -189,  -189,   802,   965,   861,  -189,    30,  -189,    18,
    -189,  1157,  -189,  -189,  -189,    13,  -189,  -189,  1033,   229,
     544,  -189,  1094,   103,  -189,   908,  -189,   143,   184,   116,
     116,   148,   148,   148,   148,    66,    66,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,    27,    -5,  -189,  -189,   651,  -189,
      53,    71,    82,   234,   775,  -189,  -189,  -189,  -189,  -189,
     232,   235,  -189,   238,    18,  1114,   888,  -189,  -189,  -189,
    -189,  -189,  -189,  -189,   802,  -189,  -189,  -189,   651,   651,
     651,   802,   802,  -189,  -189,  -189,  -189,   236,  -189,   239,
    -189,   251,  -189,  -189,    84,   117,  -189,  -189,   651,   244,
     651,  -189,  -189,  -189
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    18,    19,    20,    21,    22,    24,    25,    26,    27,
      30,    31,    28,    29,    33,    34,    23,    35,     0,     0,
       2,     3,     5,     6,     0,    12,    14,    16,    32,    46,
       1,     4,    57,     8,     0,    64,     0,    36,    38,    56,
       0,    13,    15,    17,     0,     0,     0,    68,    66,    65,
       9,     0,     0,     0,     7,     0,     0,    55,    41,    43,
       0,     0,    47,     0,    54,    77,     0,    58,    69,    67,
      37,    38,   184,   190,   191,   192,   186,     0,     0,     0,
       0,     0,     0,     0,   171,   172,   173,   170,   174,   175,
      39,    79,   127,   142,   144,   146,   148,   151,   156,   159,
     163,     0,   165,   176,   185,   184,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,   108,    10,
       0,     0,   112,    97,    99,    98,     0,   100,   101,   102,
       0,   125,    63,    76,     0,    70,    72,     0,    60,   143,
       0,   163,    40,    42,     0,    52,    44,    48,    51,     0,
       0,     0,   169,   166,   167,     0,   130,    81,     0,    83,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   132,   133,   134,   135,   136,
     137,   138,   139,   140,   141,   131,     0,   168,     0,   182,
     183,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   121,   122,   123,     0,   110,    11,     0,
     109,   113,   107,     0,     0,     0,    74,    85,    75,    86,
      61,     0,    62,    59,    49,     0,    50,    78,     0,     0,
       0,    80,     0,    85,    84,     0,   187,   145,   147,   149,
     150,   154,   155,   152,   153,   157,   158,   160,   161,   162,
     128,   181,   178,   188,     0,     0,   180,   103,     0,   105,
       0,     0,     0,     0,     0,   120,   124,   111,   126,    93,
       0,     0,    89,     0,    87,     0,     0,    71,    73,    53,
      45,   129,    82,   164,     0,   179,   177,   104,     0,     0,
       0,     0,     0,    94,    88,    90,    95,     0,    91,     0,
     189,   114,   116,   117,     0,     0,    96,    92,     0,     0,
       0,   115,   118,   119
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -189,  -189,  -189,   298,  -189,   -33,  -189,    10,  -189,    -1,
     -17,  -189,   269,    -9,  -189,   176,   -53,  -189,   -49,     5,
     -31,   -32,  -189,   -50,  -189,   126,  -189,   -75,  -189,  -189,
     -95,  -166,  -105,  -189,  -188,   -23,   226,  -189,  -189,  -189,
     -55,   -51,  -189,   -52,   -87,  -189,   187,   191,    96,    40,
      93,   -89,   -54,  -189,  -189,  -189,  -189,  -189
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    19,    20,    21,    22,    23,   120,   133,    25,    26,
      27,    36,    37,    60,    28,    61,    62,   144,    63,    64,
      39,    40,    49,   270,   135,   136,    66,    90,   158,   160,
     271,   219,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   186,    92,   140,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   254,   104
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint16 yytable[] =
{
     137,    91,   141,    48,   139,   134,   200,   157,   147,    57,
      24,   145,   187,   264,    32,    54,    32,    69,    47,   195,
     119,   211,    32,   152,   153,   154,    32,    59,   161,    38,
      24,    91,    68,    32,    29,    41,    42,    43,   218,    46,
     148,    59,    59,    58,    59,    14,    15,   141,    17,   142,
     143,   274,   141,    44,   139,    45,    71,    58,    58,    65,
      58,   206,   213,   121,   234,   213,    59,   274,   222,   188,
     189,   190,   213,   286,   159,    30,   292,    35,   236,    55,
      33,    56,    58,   247,   248,   249,    34,   208,    34,   257,
      35,   259,    35,   275,    34,   276,   161,   284,   214,    52,
     215,   217,    35,   285,   211,   214,    53,   215,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   230,   226,   213,   231,    67,    71,   233,   273,   288,
     121,   166,   167,    59,   191,   250,   192,   255,   216,   155,
     253,   213,   260,   261,   262,   172,   283,   289,   193,    58,
     173,   174,   213,   287,   213,   282,   156,   149,   290,   150,
     309,   141,   268,   139,   163,   175,   176,   177,   178,   179,
     180,   181,   182,   183,   184,   147,   279,   162,   232,    91,
     215,   141,   217,   301,   302,   303,    57,   213,   232,   299,
     215,   202,    35,   310,    50,    51,   168,   169,    52,    53,
     233,   164,   165,   311,   194,   313,   241,   242,   243,   244,
     197,    59,   105,   185,    73,    74,    75,    76,    77,    46,
      78,    79,   141,   196,   139,   297,   198,    58,    80,    81,
     170,   171,   199,   300,   212,   213,   304,   305,   224,   225,
     266,   213,   201,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
     239,   240,    18,   245,   246,   106,   107,   108,   203,   109,
     110,   111,   112,   113,   114,   115,   116,   204,   117,   220,
     221,    53,   118,   223,    83,   227,   229,   251,    84,   235,
     256,    85,    86,   258,   263,    87,    88,    89,   105,   265,
      73,    74,    75,    76,    77,   281,    78,    79,   293,   291,
     308,   294,   306,   312,    80,    81,   295,   307,    31,    72,
      70,    73,    74,    75,    76,    77,   228,    78,    79,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,   209,   278,    18,   237,
       0,   106,   107,   108,   238,   109,   110,   111,   112,   113,
     114,   115,   116,     0,   117,     0,     0,    53,   207,     0,
      83,     0,     0,     0,    84,     0,     0,    85,    86,     0,
       0,    87,    88,    89,    72,     0,    73,    74,    75,    76,
      77,    83,    78,    79,   138,    84,     0,     0,    85,    86,
      80,    81,    87,    88,    89,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     0,   105,    18,    73,    74,    75,    76,    77,
       0,    78,    79,     0,     0,     0,     0,     0,     0,    80,
      81,     0,     0,     0,     0,     0,    83,   132,     0,     0,
      84,     0,     0,    85,    86,     0,     0,    87,    88,    89,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,     0,     0,    18,     0,   106,   107,   108,     0,
     109,   110,   111,   112,   113,   114,   115,   116,     0,   117,
       0,     0,    53,   210,     0,    83,     0,     0,     0,    84,
       0,     0,    85,    86,     0,     0,    87,    88,    89,   105,
       0,    73,    74,    75,    76,    77,     0,    78,    79,     0,
       0,     0,     0,     0,     0,    80,    81,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    72,     0,    73,
      74,    75,    76,    77,     0,    78,    79,     0,     0,     0,
       0,     0,     0,    80,    81,     0,     0,     0,     0,     0,
       0,     0,   106,   107,   108,     0,   109,   110,   111,   112,
     113,   114,   115,   116,     0,   117,     0,     0,    53,   267,
       0,    83,     0,     0,     0,    84,     0,     0,    85,    86,
       0,     0,    87,    88,    89,    72,     0,    73,    74,    75,
      76,    77,     0,    78,    79,     0,    82,     0,     0,    83,
       0,    80,    81,    84,     0,     0,    85,    86,     0,     0,
      87,    88,    89,     0,     0,     0,     0,     0,     0,     0,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,     0,   105,    18,    73,    74,    75,    76,
      77,     0,    78,    79,     0,     0,     0,     0,     0,     0,
      80,    81,     0,     0,     0,     0,     0,    83,     0,     0,
       0,    84,     0,     0,    85,    86,     0,     0,    87,    88,
      89,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   106,   107,   108,
       0,   109,   110,   111,   112,   113,   114,   115,   116,     0,
     117,     0,     0,    53,     0,     0,    83,     0,     0,     0,
      84,     0,     0,    85,    86,     0,     0,    87,    88,    89,
      72,     0,    73,    74,    75,    76,    77,     0,    78,    79,
       0,     0,     0,     0,     0,     0,    80,    81,    72,     0,
      73,    74,    75,    76,    77,     0,    78,    79,     0,     0,
       0,     0,     0,     0,    80,    81,     0,     0,    72,     0,
      73,    74,    75,    76,    77,     0,    78,    79,     0,     0,
       0,     0,     0,     0,    80,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    72,   205,    73,    74,    75,
      76,    77,    83,    78,    79,     0,    84,     0,     0,    85,
      86,    80,    81,    87,    88,    89,     0,     0,     0,     0,
      83,   252,     0,     0,    84,     0,     0,    85,    86,     0,
       0,    87,    88,    89,   117,     0,     0,     0,     0,     0,
      83,     0,     0,     0,    84,     0,     0,    85,    86,     0,
       0,    87,    88,    89,    72,     0,    73,    74,    75,    76,
      77,     0,    78,    79,     0,     0,     0,    83,     0,     0,
       0,    84,     0,     0,    85,    86,     0,     0,    87,    88,
      89,    72,     0,    73,    74,    75,    76,    77,     0,    78,
      79,    72,     0,    73,    74,    75,    76,    77,     0,    78,
      79,    72,     0,    73,    74,    75,    76,    77,     0,    78,
      79,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    83,     0,     0,   272,
      84,     0,     0,    85,    86,     0,     0,    87,    88,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    83,     0,     0,   298,    84,    32,     0,
      85,    86,     0,   151,    87,    88,    89,    84,     0,     0,
      85,    86,     0,    83,    87,    88,    89,    84,    32,     0,
      85,    86,     0,     0,    87,    88,    89,     0,     0,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,     0,     0,    18,     0,
       0,     0,     0,     0,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    32,     0,    18,     0,
     214,   269,   215,     0,    35,     0,     0,     0,     0,     0,
       0,    32,     0,     0,     0,     0,     0,     0,   146,     0,
      34,     0,     0,     0,    35,     0,     0,     0,     0,     0,
       0,     0,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,     0,     0,    18,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,     0,
       0,    18,     0,     0,     0,     0,   280,     0,    34,     0,
       0,     0,    35,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,    35,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     0,     0,    18,     1,     2,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,     0,     0,    18,     0,   232,
     269,   215,     0,    35,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     296,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,     0,     0,
      18,     0,   277,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
       0,     0,    18
};

static const yytype_int16 yycheck[] =
{
      55,    52,    56,    35,    56,    55,   111,    82,    61,    40,
       0,    60,   101,   201,     3,    38,     3,    49,    35,   106,
      53,   126,     3,    77,    78,    79,     3,    44,    83,    24,
      20,    82,    49,     3,     3,    25,    26,    27,   133,    34,
      63,    58,    59,    44,    61,    47,    48,   101,    50,    58,
      59,   217,   106,    72,   106,    74,    51,    58,    59,     3,
      61,   116,    70,    53,   159,    70,    83,   233,    76,    10,
      11,    12,    70,    78,    83,     0,   264,    79,    76,    75,
      69,    77,    83,   172,   173,   174,    75,   120,    75,   194,
      79,   196,    79,    75,    75,    77,   151,    70,    75,    71,
      77,   133,    79,    76,   209,    75,    72,    77,   162,   163,
     164,   165,   166,   167,   168,   169,   170,   171,   172,   173,
     174,    70,   145,    70,    73,    76,   121,   159,   215,    76,
     120,    15,    16,   150,    75,   186,    77,   192,   133,     3,
     191,    70,   197,   198,   199,    79,   235,    76,    89,   150,
      84,    85,    70,   258,    70,   230,     3,    70,    76,    72,
      76,   215,   213,   215,    21,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,   228,   225,    22,    75,   230,
      77,   235,   214,   288,   289,   290,   217,    70,    75,   276,
      77,     3,    79,    76,    69,    70,    80,    81,    71,    72,
     232,    17,    18,   308,    74,   310,   166,   167,   168,   169,
      75,   228,     3,    71,     5,     6,     7,     8,     9,   214,
      11,    12,   276,    74,   276,   275,    75,   228,    19,    20,
      82,    83,    75,   284,    69,    70,   291,   292,    69,    70,
      69,    70,    75,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
     164,   165,    53,   170,   171,    56,    57,    58,    69,    60,
      61,    62,    63,    64,    65,    66,    67,    69,    69,    76,
      70,    72,    73,    78,    75,     3,    75,     3,    79,    76,
       3,    82,    83,    74,    61,    86,    87,    88,     3,    69,
       5,     6,     7,     8,     9,    76,    11,    12,    76,    75,
      59,    76,    76,    69,    19,    20,    78,    78,    20,     3,
      51,     5,     6,     7,     8,     9,   150,    11,    12,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,   120,   221,    53,   162,
      -1,    56,    57,    58,   163,    60,    61,    62,    63,    64,
      65,    66,    67,    -1,    69,    -1,    -1,    72,    73,    -1,
      75,    -1,    -1,    -1,    79,    -1,    -1,    82,    83,    -1,
      -1,    86,    87,    88,     3,    -1,     5,     6,     7,     8,
       9,    75,    11,    12,    78,    79,    -1,    -1,    82,    83,
      19,    20,    86,    87,    88,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,     3,    53,     5,     6,     7,     8,     9,
      -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      20,    -1,    -1,    -1,    -1,    -1,    75,    76,    -1,    -1,
      79,    -1,    -1,    82,    83,    -1,    -1,    86,    87,    88,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    -1,    -1,    53,    -1,    56,    57,    58,    -1,
      60,    61,    62,    63,    64,    65,    66,    67,    -1,    69,
      -1,    -1,    72,    73,    -1,    75,    -1,    -1,    -1,    79,
      -1,    -1,    82,    83,    -1,    -1,    86,    87,    88,     3,
      -1,     5,     6,     7,     8,     9,    -1,    11,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,    -1,     5,
       6,     7,     8,     9,    -1,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    56,    57,    58,    -1,    60,    61,    62,    63,
      64,    65,    66,    67,    -1,    69,    -1,    -1,    72,    73,
      -1,    75,    -1,    -1,    -1,    79,    -1,    -1,    82,    83,
      -1,    -1,    86,    87,    88,     3,    -1,     5,     6,     7,
       8,     9,    -1,    11,    12,    -1,    72,    -1,    -1,    75,
      -1,    19,    20,    79,    -1,    -1,    82,    83,    -1,    -1,
      86,    87,    88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,     3,    53,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      19,    20,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,
      -1,    79,    -1,    -1,    82,    83,    -1,    -1,    86,    87,
      88,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    56,    57,    58,
      -1,    60,    61,    62,    63,    64,    65,    66,    67,    -1,
      69,    -1,    -1,    72,    -1,    -1,    75,    -1,    -1,    -1,
      79,    -1,    -1,    82,    83,    -1,    -1,    86,    87,    88,
       3,    -1,     5,     6,     7,     8,     9,    -1,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    19,    20,     3,    -1,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    -1,    -1,     3,    -1,
       5,     6,     7,     8,     9,    -1,    11,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,    69,     5,     6,     7,
       8,     9,    75,    11,    12,    -1,    79,    -1,    -1,    82,
      83,    19,    20,    86,    87,    88,    -1,    -1,    -1,    -1,
      75,    76,    -1,    -1,    79,    -1,    -1,    82,    83,    -1,
      -1,    86,    87,    88,    69,    -1,    -1,    -1,    -1,    -1,
      75,    -1,    -1,    -1,    79,    -1,    -1,    82,    83,    -1,
      -1,    86,    87,    88,     3,    -1,     5,     6,     7,     8,
       9,    -1,    11,    12,    -1,    -1,    -1,    75,    -1,    -1,
      -1,    79,    -1,    -1,    82,    83,    -1,    -1,    86,    87,
      88,     3,    -1,     5,     6,     7,     8,     9,    -1,    11,
      12,     3,    -1,     5,     6,     7,     8,     9,    -1,    11,
      12,     3,    -1,     5,     6,     7,     8,     9,    -1,    11,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    -1,    -1,    78,
      79,    -1,    -1,    82,    83,    -1,    -1,    86,    87,    88,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    -1,    78,    79,     3,    -1,
      82,    83,    -1,    75,    86,    87,    88,    79,    -1,    -1,
      82,    83,    -1,    75,    86,    87,    88,    79,     3,    -1,
      82,    83,    -1,    -1,    86,    87,    88,    -1,    -1,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    -1,    -1,    53,    -1,
      -1,    -1,    -1,    -1,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,     3,    -1,    53,    -1,
      75,    76,    77,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,     3,    -1,    -1,    -1,    -1,    -1,    -1,    73,    -1,
      75,    -1,    -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    -1,    53,    39,    40,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    -1,
      -1,    53,    -1,    -1,    -1,    -1,    73,    -1,    75,    -1,
      -1,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    -1,    -1,    -1,    79,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    53,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    -1,    53,    -1,    75,
      76,    77,    -1,    79,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    -1,    -1,
      53,    -1,    55,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    53,    91,
      92,    93,    94,    95,    97,    98,    99,   100,   104,     3,
       0,    93,     3,    69,    75,    79,   101,   102,   109,   110,
     111,    97,    97,    97,    72,    74,   109,   100,   111,   112,
      69,    70,    71,    72,   125,    75,    77,   110,    99,   100,
     103,   105,   106,   108,   109,     3,   116,    76,   100,   111,
     102,   109,     3,     5,     6,     7,     8,     9,    11,    12,
      19,    20,    72,    75,    79,    82,    83,    86,    87,    88,
     117,   131,   133,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   147,     3,    56,    57,    58,    60,
      61,    62,    63,    64,    65,    66,    67,    69,    73,    95,
      96,    97,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,    76,    97,   113,   114,   115,   130,    78,   133,
     134,   142,   103,   103,   107,   108,    73,   106,   125,    70,
      72,    75,   142,   142,   142,     3,     3,   117,   118,   103,
     119,   130,    22,    21,    17,    18,    15,    16,    80,    81,
      82,    83,    79,    84,    85,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    71,   132,   141,    10,    11,
      12,    75,    77,    89,    74,   134,    74,    75,    75,    75,
     122,    75,     3,    69,    69,    69,   130,    73,    95,   126,
      73,   122,    69,    70,    75,    77,   109,   111,   120,   121,
      76,    70,    76,    78,    69,    70,   125,     3,   105,    75,
      70,    73,    75,   111,   120,    76,    76,   136,   137,   138,
     138,   139,   139,   139,   139,   140,   140,   141,   141,   141,
     131,     3,    76,   131,   146,   130,     3,   122,    74,   122,
     130,   130,   130,    61,   124,    69,    69,    73,   131,    76,
     113,   120,    78,   134,   121,    75,    77,    55,   115,   108,
      73,    76,   117,   141,    70,    76,    78,   122,    76,    76,
      76,    75,   124,    76,    76,    78,    76,   113,    78,   134,
     131,   122,   122,   122,   130,   130,    76,    78,    59,    76,
      76,   122,    69,   122
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    90,    91,    92,    92,    93,    93,    94,    95,    95,
      96,    96,    97,    97,    97,    97,    97,    97,    98,    98,
      98,    98,    98,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,   100,   100,   100,   101,   101,   102,   102,
     103,   103,   103,   103,   104,   104,   104,   105,   105,   106,
     106,   106,   107,   107,   108,   109,   109,   110,   110,   110,
     110,   110,   110,   110,   111,   111,   111,   111,   112,   112,
     113,   113,   114,   114,   115,   115,   115,   116,   116,   117,
     117,   118,   118,   119,   119,   120,   120,   120,   121,   121,
     121,   121,   121,   121,   121,   121,   121,   122,   122,   122,
     122,   122,   122,   123,   123,   123,   124,   124,   125,   125,
     125,   125,   126,   126,   127,   127,   127,   128,   128,   128,
     129,   129,   129,   129,   129,   130,   130,   131,   131,   131,
     131,   132,   132,   132,   132,   132,   132,   132,   132,   132,
     132,   132,   133,   134,   135,   135,   136,   136,   137,   137,
     137,   138,   138,   138,   138,   138,   139,   139,   139,   140,
     140,   140,   140,   141,   141,   142,   142,   142,   142,   142,
     143,   143,   143,   143,   143,   143,   144,   144,   144,   144,
     144,   144,   144,   144,   145,   145,   145,   145,   146,   146,
     147,   147,   147
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     2,     3,
       1,     2,     1,     2,     1,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       2,     1,     2,     1,     5,     7,     2,     1,     2,     3,
       3,     2,     1,     3,     1,     2,     1,     1,     3,     4,
       3,     4,     4,     3,     1,     2,     2,     3,     1,     2,
       1,     3,     1,     3,     2,     2,     1,     1,     3,     1,
       3,     1,     3,     1,     2,     1,     1,     2,     3,     2,
       3,     3,     4,     2,     3,     3,     4,     1,     1,     1,
       1,     1,     1,     3,     4,     3,     1,     2,     2,     3,
       3,     4,     1,     2,     5,     7,     5,     5,     7,     7,
       3,     2,     2,     2,     3,     1,     3,     1,     3,     4,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     4,     1,     2,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     4,     3,     4,
       3,     3,     2,     2,     1,     1,     1,     3,     1,     3,
       1,     1,     1
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
#line 132 "yacc.y" /* yacc.c:1646  */
    { /*global scope*/
		NodeAst *p = new ProgramStartAst(NodeAst::T_CPROGRAMSTART_TRANSUNIT);
		p->addChild1((yyvsp[0].pnode));
		(yyval.pnode) = p;
        }
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 141 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 1809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 146 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TranslationUnitAst(NodeAst::T_CTRANSUNIT_TRANSUNIT_EXTDECTION);
		p->addChild2((yyvsp[-1].pnode), (yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 1819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 158 "yacc.y" /* yacc.c:1646  */
    { /*global scope func*/
		NodeAst *p = new ExtDectionAst(NodeAst::T_CEXTDECTION_FUNCDEF);
		p->addChild1((yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 1829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 165 "yacc.y" /* yacc.c:1646  */
    { /*global scope var*/
		NodeAst *p = new ExtDectionAst(NodeAst::T_CEXTDECTION_DECTION);
		p->addChild1((yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 1839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 174 "yacc.y" /* yacc.c:1646  */
    { /*func scope*/
		NodeAst *p = new FuncDefAst(NodeAst::T_CFUNCDEF_DECTIONSFS_DECTOR_COMPSTM);
		p->addChild3((yyvsp[-2].pnode), (yyvsp[-1].pnode), (yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 1849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 183 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new DectionAst(NodeAst::T_CDECTION_DECTIONSFS);
		p->addChild1((yyvsp[-1].pnode));
		(yyval.pnode) = p;
	}
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 190 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new DectionAst(NodeAst::T_CDECTION_DECTIONSFS_INITDECTORLIST);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[-1].pnode));
		(yyval.pnode) = p;
	}
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 199 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 204 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new DectionListAst(NodeAst::T_CDECTIONLIST_DECTIONLIST_DECTION);
		p->addChild2((yyvsp[-1].pnode), (yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 1887 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 215 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 1895 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 220 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new DectionSpecifiersAst(NodeAst::T_CDECTIONSF_STORCLASSSF_DECTIONSFS);
		p->addChild2((yyvsp[-1].pnode), (yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 1905 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 227 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 1913 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 232 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new DectionSpecifiersAst(NodeAst::T_CDECTIONSF_TYPESF_DECTIONSFS);
		p->addChild2((yyvsp[-1].pnode), (yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 239 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 1931 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 244 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new DectionSpecifiersAst(NodeAst::T_CDECTIONSF_TYPEQF_DECTIONSFS);
		p->addChild2((yyvsp[-1].pnode), (yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 1941 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 253 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CSTORCLASSSF_TYPEDEF, (yyvsp[0].yystring));
		(yyval.pnode) = p;
	}
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 259 "yacc.y" /* yacc.c:1646  */
    {
	    NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CSTORCLASSSF_EXTERN, (yyvsp[0].yystring));
		(yyval.pnode) = p;
	}
#line 1959 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 265 "yacc.y" /* yacc.c:1646  */
    {
	    NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CSTORCLASSSF_STATIC, (yyvsp[0].yystring));
		(yyval.pnode) = p;
	}
#line 1968 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 271 "yacc.y" /* yacc.c:1646  */
    {
	    NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CSTORCLASSSF_AUTO, (yyvsp[0].yystring));
		(yyval.pnode) = p;
	}
#line 1977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 277 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CSTORCLASSSF_REGISITER, (yyvsp[0].yystring));
		(yyval.pnode) = p;
	}
#line 1986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 285 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_VOID, (yyvsp[0].yystring));
		(yyval.pnode) = p;
	}
#line 1995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 291 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_CHAR, (yyvsp[0].yystring));
		(yyval.pnode) = p;
	}
#line 2004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 297 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_SHORT, (yyvsp[0].yystring));
		(yyval.pnode) = p;
	}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 303 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_INT, (yyvsp[0].yystring));
		(yyval.pnode) = p;
	}
#line 2022 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 309 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_LONG, (yyvsp[0].yystring));
		(yyval.pnode) = p;
	}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 315 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_FLOAT, (yyvsp[0].yystring));
		(yyval.pnode) = p;
	}
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 321 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_DOUBLE, (yyvsp[0].yystring));
		(yyval.pnode) = p;
	}
#line 2049 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 327 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_SIGNED, (yyvsp[0].yystring));
		(yyval.pnode) = p;
	}
#line 2058 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 333 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_UNSIGNED, (yyvsp[0].yystring));
		(yyval.pnode) = p;
	}
#line 2067 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 344 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2075 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 351 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPEQF_CONST, (yyvsp[0].yystring));
		(yyval.pnode) = p;
	}
#line 2084 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 357 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPEQF_VOLATILE, (yyvsp[0].yystring));
		(yyval.pnode) = p;
	}
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 363 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPEQF_VIRTUAL, (yyvsp[0].yystring));
		(yyval.pnode) = p;
	}
#line 2102 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 371 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2110 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 376 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new InitDectorListAst(NodeAst::T_CINITDECTORLIST_INITDECTORLIST_INITDECTOR);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 385 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new InitDectorAst(NodeAst::T_CINITDECTOR_DECTOR);
		p->addChild1((yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 2130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 392 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new InitDectorAst(NodeAst::T_CINITDECTOR_ASSGIN_INITZER);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 2140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 401 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new SpeciQualiFierListAst(NodeAst::T_CSQFLIST_TYPESF_SQFLIST);
		p->addChild2((yyvsp[-1].pnode), (yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 408 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 413 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new SpeciQualiFierListAst(NodeAst::T_CSQFLIST_TYPEQF_SQFLIST);
		p->addChild2((yyvsp[-1].pnode), (yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 2168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 420 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 510 "yacc.y" /* yacc.c:1646  */
    { /*class scope def*/
		NodeAst *p = new ClassSpecifierAst(NodeAst::T_CCLASSSF_CLASS_ID_CLASSDECTIONLIST);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CCLASSSF_CLASS_ID_CLASSDECTIONLIST, (yyvsp[-3].yystring));
		p->addChild2(t, (yyvsp[-1].pnode));
		(yyval.pnode) = p;
	}
#line 2187 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 518 "yacc.y" /* yacc.c:1646  */
    { //class scope def
		NodeAst *p = new ClassSpecifierAst(NodeAst::T_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST, (yyvsp[-5].yystring));
		p->addChild3(t, (yyvsp[-3].pnode), (yyvsp[-1].pnode));
		(yyval.pnode) = p;
	}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 526 "yacc.y" /* yacc.c:1646  */
    { /*class declaration*/
		NodeAst *p = new ClassSpecifierAst(NodeAst::T_CCLASSSF_CLASS_ID);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CCLASSSF_CLASS_ID, (yyvsp[0].yystring));
		p->addChild1(t);
		(yyval.pnode) = p;
	}
#line 2209 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 536 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2217 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 541 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new ClassDectionListAst(NodeAst::T_CCLASSDECTIONLIST_CLASSDECTIONLIST_CLASSDECTION);
		p->addChild2((yyvsp[-1].pnode), (yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 550 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new ClassDectionAst(NodeAst::T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[-1].pnode));
		(yyval.pnode) = p;
	}
#line 2237 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 557 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new ClassDectionAst(NodeAst::T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST_COMPSTM);
		p->addChild3((yyvsp[-2].pnode), (yyvsp[-1].pnode), (yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 2247 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 564 "yacc.y" /* yacc.c:1646  */
    { /*this func can be the Constructor or Destructor*/
		NodeAst *p = new ClassDectionAst(NodeAst::T_CCLASSDECTION_CLASSDECTORLIST_COMPSTM);
		p->addChild2((yyvsp[-1].pnode), (yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 573 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2265 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 578 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new ClassDectorListAst(NodeAst::T_CCLASSDECTORLIST_CLASSDECTORLIST_CLASSDECTOR);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 2275 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 587 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new ClassDectorAst(NodeAst::T_CCLASSDECTOR_DECTOR);
		p->addChild1((yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 642 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new DectorAst(NodeAst::T_CDECTOR_POINTER_DIRDECTOR);
		p->addChild2((yyvsp[-1].pnode), (yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 2295 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 649 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2303 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 656 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new DirDectorAst(NodeAst::T_CDIRDECTOR_ID);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CDIRDECTOR_ID, (yyvsp[0].yystring));
		p->addChild1(t);
		(yyval.pnode) = p;
	}
#line 2314 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 664 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[-1].pnode);
	}
#line 2322 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 669 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new DirDectorAst(NodeAst::T_CDIRDECTOR_DIRDECTOR_ARRAY_CONSTEXP);
		p->addChild2((yyvsp[-3].pnode), (yyvsp[-1].pnode));
		(yyval.pnode) = p;
	}
#line 2332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 676 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new DirDectorAst(NodeAst::T_CDIRDECTOR_DIRDECTOR_ARRAY_VOID);
		p->addChild1((yyvsp[-2].pnode));
		(yyval.pnode) = p;
	}
#line 2342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 683 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new DirDectorAst(NodeAst::T_CDIRDECTOR_DIRDECTOR_CALL_PARAMTYPELIST);
		p->addChild2((yyvsp[-3].pnode), (yyvsp[-1].pnode));
		(yyval.pnode) = p;
	}
#line 2352 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 690 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new DirDectorAst(NodeAst::T_CDIRDECTOR_DIRDECTOR_CALL_EXP);
		p->addChild2((yyvsp[-3].pnode), (yyvsp[-1].pnode));
		(yyval.pnode) = p;
	}
#line 2362 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 697 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new DirDectorAst(NodeAst::T_CDIRDECTOR_DIRDECTOR_CALL_VOID);
		p->addChild1((yyvsp[-2].pnode));
		(yyval.pnode) = p;
	}
#line 2372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 708 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 2380 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 713 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 2388 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 718 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 2396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 723 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 2404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 730 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 735 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TypeQualifierListAst(NodeAst::T_CTYPEQFLIST_TYPEQFLIST_TYPEQF);
		p->addChild2((yyvsp[-1].pnode), (yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 2422 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 746 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2430 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 751 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 2438 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 758 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2446 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 763 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new ParamTypeListAst(NodeAst::T_CPARAMLIST_PARAMLIST_PARAMDECTION);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 2456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 772 "yacc.y" /* yacc.c:1646  */
    { /*this declaration may exist in func def*/
		NodeAst *p = new ParamDectionAst(NodeAst::T_CPARAMDECTION_DECTIONSFS_DECTOR);
		p->addChild2((yyvsp[-1].pnode), (yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 2466 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 779 "yacc.y" /* yacc.c:1646  */
    { /*this declaration may exist in func declaration*/
		(yyval.pnode) = NULL;
	}
#line 2474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 784 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new ParamDectionAst(NodeAst::T_CPARAMDECTION_DECTIONSFS);
		p->addChild1((yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 2484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 795 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CIDLIST_ID, (yyvsp[0].yystring));
		(yyval.pnode) = p;
	}
#line 2493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 801 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new IdentifierListAst(NodeAst::T_CIDLIST_IDLIST_ID);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CIDLIST_IDLIST_ID, (yyvsp[0].yystring));
		p->addChild2((yyvsp[-2].pnode), t);
		(yyval.pnode) = p;
	}
#line 2504 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 811 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new InitzerAst(NodeAst::T_CINITZER_ASSIGNEXP);
		p->addChild1((yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 2514 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 818 "yacc.y" /* yacc.c:1646  */
    { /*init value*/
		NodeAst *p = new InitzerAst(NodeAst::T_CINITZER_CINITZERLIST);
		p->addChild1((yyvsp[-1].pnode));
		(yyval.pnode) = p;
	}
#line 2524 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 827 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2532 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 832 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new InitzerListAst(NodeAst::T_CINITZERLIST_INITZERLIST_INITZER);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 2542 "y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 842 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2550 "y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 847 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 2558 "y.tab.c" /* yacc.c:1646  */
    break;

  case 85:
#line 856 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 2566 "y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 861 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 2574 "y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 866 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 2582 "y.tab.c" /* yacc.c:1646  */
    break;

  case 88:
#line 873 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 2590 "y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 878 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 2598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 883 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 2606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 888 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 2614 "y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 893 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 2622 "y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 898 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 2630 "y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 903 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 2638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 908 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 2646 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 913 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 2654 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 922 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2662 "y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 927 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 932 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2678 "y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 937 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 942 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2694 "y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 947 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 954 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new LabeledStmAst(NodeAst::T_CLABSTM_ID_STM);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CLABSTM_ID_STM, (yyvsp[-2].yystring));
        	p->addChild2(t, (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 2713 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 962 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new LabeledStmAst(NodeAst::T_CLABSTM_CASE_CONSTEXP_STM);
        	p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 2723 "y.tab.c" /* yacc.c:1646  */
    break;

  case 105:
#line 969 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new LabeledStmAst(NodeAst::T_CLABSTM_DEFAULT_STM);
        	p->addChild1((yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 2733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 978 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new ExpStmAst(NodeAst::T_CEXPSTM_VOID);
       		(yyval.pnode) = p;
	}
#line 2742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 984 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new ExpStmAst(NodeAst::T_CEXPSTM_EXP);
		p->addChild1((yyvsp[-1].pnode));
		(yyval.pnode) = p;
	}
#line 2752 "y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 993 "yacc.y" /* yacc.c:1646  */
    { /*local scope*/
		NodeAst *p = new CompoundStmAst(NodeAst::T_CCOMPSTM_VOID);
        	(yyval.pnode) = p;
	}
#line 2761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 999 "yacc.y" /* yacc.c:1646  */
    { /*local scope*/
		NodeAst *p = new CompoundStmAst(NodeAst::T_CCOMPSTM_STMLIST);
		p->addChild1((yyvsp[-1].pnode));
        	(yyval.pnode) = p;
	}
#line 2771 "y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 1006 "yacc.y" /* yacc.c:1646  */
    { /*local scope*/
		NodeAst *p = new CompoundStmAst(NodeAst::T_CCOMPSTM_DECTION_LIST);
		p->addChild1((yyvsp[-1].pnode));
        	(yyval.pnode) = p;
	}
#line 2781 "y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 1013 "yacc.y" /* yacc.c:1646  */
    { /*local scope*/
		NodeAst *p = new CompoundStmAst(NodeAst::T_CCOMPSTM_DECTIONLIST_STMLIST);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[-1].pnode));
        	(yyval.pnode) = p;
	}
#line 2791 "y.tab.c" /* yacc.c:1646  */
    break;

  case 112:
#line 1022 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 1027 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new StmListAst(NodeAst::T_CSTMLIST_STMLIST_STM);
		p->addChild2((yyvsp[-1].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 2809 "y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 1036 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new SelectionStmAst(NodeAst::T_CSELSTM_IF_EXP_STM);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 2819 "y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 1043 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new SelectionStmAst(NodeAst::T_CSELSTM_IF_EXP_STM_ELSE_STM);
		p->addChild3((yyvsp[-4].pnode), (yyvsp[-2].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 2829 "y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 1050 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new SelectionStmAst(NodeAst::T_CSELSTM_SWITCH_EXP_STM);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 2839 "y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 1059 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new IterationStmAst(NodeAst::T_CITRSTM_WHILE_EXP_STM);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 2849 "y.tab.c" /* yacc.c:1646  */
    break;

  case 118:
#line 1066 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new IterationStmAst(NodeAst::T_CITRSTM_DO_STM_WHILE_EXP);
		p->addChild2((yyvsp[-5].pnode), (yyvsp[-2].pnode));
        	(yyval.pnode) = p;
	}
#line 2859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 1073 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new IterationStmAst(NodeAst::T_CITRSTM_FOR_EXPSTM_EXPSTM_EXP_STM);
		p->addChild4((yyvsp[-4].pnode), (yyvsp[-3].pnode), (yyvsp[-2].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 2869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 1082 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new JumpStmAst(NodeAst::T_CJUMPSTM_GOTO_ID);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CJUMPSTM_GOTO_ID, (yyvsp[-1].yystring));
		p->addChild1(t);
        	(yyval.pnode) = p;
	}
#line 2880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 1090 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new JumpStmAst(NodeAst::T_CJUMPSTM_CONTINUE);
        	(yyval.pnode) = p;
	}
#line 2889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 1096 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new JumpStmAst(NodeAst::T_CJUMPSTM_BREAK);
        	(yyval.pnode) = p;
	}
#line 2898 "y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 1102 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new JumpStmAst(NodeAst::T_CJUMPSTM_RETURN);
        	(yyval.pnode) = p;
	}
#line 2907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 1108 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new JumpStmAst(NodeAst::T_CJUMPSTM_RETURN_EXP);
		p->addChild1((yyvsp[-1].pnode));
        	(yyval.pnode) = p;
	}
#line 2917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 125:
#line 1119 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 2925 "y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 1124 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new ExpAst(NodeAst::T_CEXP_EXP_ASSIGNEXP);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 2935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 1133 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new AssignExpAst(NodeAst::T_CASSIGNEXP_CONDITIONALEXP);
		p->addChild1((yyvsp[0].pnode));
       		(yyval.pnode) = p;
	}
#line 2945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 1140 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new AssignExpAst(NodeAst::T_CASSIGNEXP_UNARYEXP_ASSIGN_OP_ASSIGNEXP);
		p->addChild3((yyvsp[-2].pnode), (yyvsp[-1].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 2955 "y.tab.c" /* yacc.c:1646  */
    break;

  case 129:
#line 1147 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new AssignExpAst(NodeAst::T_CASSIGNEXP_NEW_ID_VOID);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CASSIGNEXP_NEW_ID_VOID, (yyvsp[-2].yystring));
		p->addChild1(t);
        	(yyval.pnode) = p;
	}
#line 2966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 1155 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new AssignExpAst(NodeAst::T_CASSIGNEXP_DELETE_ID);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CASSIGNEXP_DELETE_ID, (yyvsp[0].yystring));
		p->addChild1(t);
        	(yyval.pnode) = p;
	}
#line 2977 "y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 1165 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CASSIGN_OP_ASSIGN, "=");
        	(yyval.pnode) = p;
	}
#line 2986 "y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 1171 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CASSIGN_OP_MUL_ASSIGN, (yyvsp[0].yystring));
        	(yyval.pnode) = p;
	}
#line 2995 "y.tab.c" /* yacc.c:1646  */
    break;

  case 133:
#line 1177 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CASSIGN_OP_DIV_ASSIGN, (yyvsp[0].yystring));
        	(yyval.pnode) = p;
	}
#line 3004 "y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 1183 "yacc.y" /* yacc.c:1646  */
    {
        	(yyval.pnode) = NULL;
	}
#line 3012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 1188 "yacc.y" /* yacc.c:1646  */
    {
        	NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CASSIGN_OP_ADD_ASSIGN, (yyvsp[0].yystring));
        	(yyval.pnode) = p;
	}
#line 3021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 1194 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CASSIGN_OP_SUB_ASSIGN, (yyvsp[0].yystring));
        	(yyval.pnode) = p;
	}
#line 3030 "y.tab.c" /* yacc.c:1646  */
    break;

  case 137:
#line 1200 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 3038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 1205 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 3046 "y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 1210 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 3054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 1215 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 3062 "y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 1220 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 3070 "y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 1227 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 3078 "y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 1234 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 3086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 1241 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 3094 "y.tab.c" /* yacc.c:1646  */
    break;

  case 145:
#line 1246 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new LogicalOrExpAst(NodeAst::T_CLOGOREXP_LOGOREXP_OR_OP_LOGANDEXP);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 3104 "y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 1255 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 3112 "y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 1260 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new LogicalAndExpAst(NodeAst::T_CLOGANDEXP_LOGANDEXP_AND_OP_EQUALEXP);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 3122 "y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 1308 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 3130 "y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 1313 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new EqualExpAst(NodeAst::T_CEQUALEXP_EQUALEXP_EQ_OP_RELEXP);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
       		(yyval.pnode) = p;
	}
#line 3140 "y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 1320 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new EqualExpAst(NodeAst::T_CEQUALEXP_EQUALEXP_NE_OP_RELEXP);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 3150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 151:
#line 1329 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 3158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 1334 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new RelationExpAst(NodeAst::T_CRELEXP_RELEXP_L_OP_ADDEXP);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 3168 "y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 1341 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new RelationExpAst(NodeAst::T_CRELEXP_RELEXP_G_OP_ADDEXP);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 3178 "y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 1348 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new RelationExpAst(NodeAst::T_CRELEXP_RELEXP_LE_OP_ADDEXP);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 3188 "y.tab.c" /* yacc.c:1646  */
    break;

  case 155:
#line 1355 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new RelationExpAst(NodeAst::T_CRELEXP_RELEXP_GE_OP_ADDEXP);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
       		(yyval.pnode) = p;
	}
#line 3198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 1383 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 3206 "y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 1388 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new AddExpAst(NodeAst::T_CADDEXP_ADDEXP_ADD_OP_MULEXP);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 3216 "y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 1395 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new AddExpAst(NodeAst::T_CADDEXP_ADDEXP_SUB_OP_MULEXP);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 3226 "y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 1404 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 3234 "y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 1409 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new MulExpAst(NodeAst::T_CMULEXP_MULEXP_MUL_OP_CASTEXP);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 3244 "y.tab.c" /* yacc.c:1646  */
    break;

  case 161:
#line 1416 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new MulExpAst(NodeAst::T_CMULEXP_MULEXP_DIV_OP_CASTEXP);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 3254 "y.tab.c" /* yacc.c:1646  */
    break;

  case 162:
#line 1423 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 3262 "y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 1430 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 3270 "y.tab.c" /* yacc.c:1646  */
    break;

  case 164:
#line 1435 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 3278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 1442 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 3286 "y.tab.c" /* yacc.c:1646  */
    break;

  case 166:
#line 1447 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new UnaryExpAst(NodeAst::T_CUNARYEXP_INC_OP_UNARAYEXP);
		p->addChild1((yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 3296 "y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 1454 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new UnaryExpAst(NodeAst::T_CUNARYEXP_DEC_OP_UNARYEXP);
		p->addChild1((yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 3306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 1461 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new UnaryExpAst(NodeAst::T_CUNARYEXP_UNARY_OP_CASTEXP);
		p->addChild2((yyvsp[-1].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 3316 "y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 1468 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 3324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 1475 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 3332 "y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 1480 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 3340 "y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 1485 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CUNARY_OP_ADD_OP, "+");
		(yyval.pnode) = p;
	}
#line 3349 "y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 1491 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CUNARY_OP_SUB_OP, "-");
		(yyval.pnode) = p;
	}
#line 3358 "y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 1497 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 3366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 1502 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 3374 "y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 1509 "yacc.y" /* yacc.c:1646  */
    { /*directly return the child node*/
		(yyval.pnode) = (yyvsp[0].pnode);
	}
#line 3382 "y.tab.c" /* yacc.c:1646  */
    break;

  case 177:
#line 1514 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new PostfixExpAst(NodeAst::T_CPOSTEXP_POSTEXP_ARRAY_EXP);
		p->addChild2((yyvsp[-3].pnode), (yyvsp[-1].pnode));
        	(yyval.pnode) = p;
	}
#line 3392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 1521 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new PostfixExpAst(NodeAst::T_CPOSTEXP_POSTEXP_CALL_VOID);
		p->addChild1((yyvsp[-2].pnode));
        	(yyval.pnode) = p;
	}
#line 3402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 1528 "yacc.y" /* yacc.c:1646  */
    { /*call the func callee*/
		NodeAst *p = new PostfixExpAst(NodeAst::T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST);
		p->addChild2((yyvsp[-3].pnode), (yyvsp[-1].pnode));
        	(yyval.pnode) = p;
	}
#line 3412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 180:
#line 1535 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new PostfixExpAst(NodeAst::T_CPOSTEXP_POSTEXP_REF_ID);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CPOSTEXP_POSTEXP_REF_ID, (yyvsp[0].yystring));
		p->addChild2((yyvsp[-2].pnode), t);
       		(yyval.pnode) = p;
	}
#line 3423 "y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 1543 "yacc.y" /* yacc.c:1646  */
    {
		(yyval.pnode) = NULL;
	}
#line 3431 "y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 1548 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new PostfixExpAst(NodeAst::T_CPOSTEXP_POSTEXP_INC_OP);
		p->addChild1((yyvsp[-1].pnode));
        	(yyval.pnode) = p;
	}
#line 3441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 1555 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new PostfixExpAst(NodeAst::T_CPOSTEXP_POSTEXP_DEC_OP);
		p->addChild1((yyvsp[-1].pnode));
        	(yyval.pnode) = p;
	}
#line 3451 "y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 1564 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new PrimaryExpAst(NodeAst::T_CPRIMEXP_ID);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CPRIMEXP_ID, (yyvsp[0].yystring));
		p->addChild1(t);
		(yyval.pnode) = p;
	}
#line 3462 "y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 1572 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new PrimaryExpAst(NodeAst::T_CPRIMEXP_CONST);
		p->addChild1((yyvsp[0].pnode));
       		(yyval.pnode) = p;
	}
#line 3472 "y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 1579 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new PrimaryExpAst(NodeAst::T_CPRIMEXP_STR);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CPRIMEXP_STR, (yyvsp[0].yystring));
		p->addChild1(t);
		(yyval.pnode) = p;
	}
#line 3483 "y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 1587 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new PrimaryExpAst(NodeAst::T_CPRIMEXP_EXP);
		p->addChild1((yyvsp[-1].pnode));
        	(yyval.pnode) = p;
	}
#line 3493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 1596 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new ArgExpListAst(NodeAst::T_CARGEXPLIST_ASSGEXP);
		p->addChild1((yyvsp[0].pnode));
		(yyval.pnode) = p;
	}
#line 3503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 189:
#line 1603 "yacc.y" /* yacc.c:1646  */
    {
		NodeAst *p = new ArgExpListAst(NodeAst::T_CARGEXPLIST_ARGEXPLIST_ASSGEXP);
		p->addChild2((yyvsp[-2].pnode), (yyvsp[0].pnode));
        	(yyval.pnode) = p;
	}
#line 3513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 190:
#line 1612 "yacc.y" /* yacc.c:1646  */
    {
			NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CCONSTVAR_INT_CONST, (yyvsp[0].yystring));
			(yyval.pnode) = p;
        }
#line 3522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 1618 "yacc.y" /* yacc.c:1646  */
    {
			NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CCONSTVAR_CHAR_CONST, (yyvsp[0].yystring));
			(yyval.pnode) = p;
        }
#line 3531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 1624 "yacc.y" /* yacc.c:1646  */
    {
			NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CCONSTVAR_FLOAT_CONST, (yyvsp[0].yystring));
			(yyval.pnode) = p;
        }
#line 3540 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3544 "y.tab.c" /* yacc.c:1646  */
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
#line 1630 "yacc.y" /* yacc.c:1906  */





int yyerror(const char *msg)
{

	return 0;
}


int main() {

   yyparse();

   cout << "yylineno" << yylineno <<endl;

   NodeAst::printNodeTree(NodeAst::getNodeTreeRoot(), 0);

   NodeAst::dotBfsNodeTree(NodeAst::getNodeTreeRoot());

   NodeAst::freeNodeList();

   return 0;
}

