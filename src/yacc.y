%{

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
%}



%union {
   LexNodeAst* yystring;
   NodeAst* pnode;
}

/**********************Terminator******************************/

%token<yystring> IDENTIFIER CONSTANT INTEGER_CONSTANT CHARACTER_CONSTANT FLOATING_CONSTANT STRING_LITERAL SIZEOF
%token<yystring> PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP NEW_OP DELETE_OP
%token<yystring> AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token<yystring> SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token<yystring> XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token<yystring> TYPEDEF EXTERN STATIC AUTO REGISTER
%token<yystring> CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID VIRTUAL
%token<yystring> STRUCT UNION CLASS ENUM ELLIPSIS

%token<yystring> CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
/***************************************************************/

/********************NonTerminator******************************/
%type<pnode>  program_start
%type<pnode>  translation_unit
%type<pnode>  external_declaration
%type<pnode>  function_definition
%type<pnode>  declaration
%type<pnode>  declaration_list
%type<pnode>  declaration_specifiers
%type<pnode>  storage_class_specifier
%type<pnode>  type_specifier
%type<pnode>  type_qualifier
%type<pnode>  init_declarator_list
%type<pnode>  init_declarator
%type<pnode>  specifier_qualifier_list
/************************************
%type<pnode>  struct_or_union_specifier
%type<pnode>  struct_or_union
%type<pnode>  struct_declaration_list
%type<pnode>  struct_declaration
%type<pnode>  struct_declarator_list
%type<pnode>  struct_declarator
***************************************/
%type<pnode>  class_specifier
%type<pnode>  class_declaration_list
%type<pnode>  class_declaration
%type<pnode>  class_declarator_list
%type<pnode>  class_declarator
/********************************
*%type<pnode>  enum_specifier
*%type<pnode>  enumerator_list
*%type<pnode>  enumerator
**********************************/
%type<pnode>  declarator
%type<pnode>  direct_declarator
%type<pnode>  pointer
%type<pnode>  type_qualifier_list
%type<pnode>  parameter_type_list
%type<pnode>  parameter_list
%type<pnode>  parameter_declaration
%type<pnode>  identifier_list
%type<pnode>  initializer
%type<pnode>  initializer_list
%type<pnode>  type_name
%type<pnode>  abstract_declarator
%type<pnode>  direct_abstract_declarator
%type<pnode>  statement
%type<pnode>  labeled_statement
%type<pnode>  expression_statement
%type<pnode>  compound_statement
%type<pnode>  statement_list
%type<pnode>  selection_statement
%type<pnode>  iteration_statement
%type<pnode>  jump_statement
%type<pnode>  expression
%type<pnode>  assignment_expression
%type<pnode>  assignment_operator
%type<pnode>  conditional_expression
%type<pnode>  constant_expression
%type<pnode>  logical_or_expression
%type<pnode>  logical_and_expression
/************************************
*%type<pnode>  inclusive_or_expression
*%type<pnode>  exclusive_or_expression
*%type<pnode>  and_expression
*************************************/
%type<pnode>  equality_expression
%type<pnode>  relational_expression
/***********************************
*%type<pnode>  shift_expression
************************************/
%type<pnode>  additive_expression
%type<pnode>  multiplicative_expression
%type<pnode>  cast_expression
%type<pnode>  unary_expression
%type<pnode>  unary_operator
%type<pnode>  postfix_expression
%type<pnode>  primary_expression
%type<pnode>  argument_expression_list
%type<pnode>  constant_value

/*****************************grammar*************************************/


%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

%start program_start
%%

program_start
        :translation_unit
        { /*global scope*/
		NodeAst *p = new ProgramStartAst(NodeAst::T_CPROGRAMSTART_TRANSUNIT);
		p->addChild1($1);
		p->setLineno($1->getLineno());
		$$ = p;
        }
        ;

translation_unit
	: external_declaration
	{ /*directly return the child node*/
		$$ = $1;
	}

	| translation_unit external_declaration
	{
		NodeAst *p = new TranslationUnitAst(NodeAst::T_CTRANSUNIT_TRANSUNIT_EXTDECTION);
		p->addChild2($1, $2);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;


/***************************declaration***********************************/

external_declaration
	: function_definition
	{ /*global scope func*/
		NodeAst *p = new ExtDectionAst(NodeAst::T_CEXTDECTION_FUNCDEF);
		p->addChild1($1);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| declaration
	{ /*global scope var*/
		NodeAst *p = new ExtDectionAst(NodeAst::T_CEXTDECTION_DECTION);
		p->addChild1($1);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

function_definition
	: declaration_specifiers declarator compound_statement
	{ /*func scope*/
		NodeAst *p = new FuncDefAst(NodeAst::T_CFUNCDEF_DECTIONSFS_DECTOR_COMPSTM);
		p->addChild3($1, $2, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

declaration
	: declaration_specifiers ';'
	{
		NodeAst *p = new DectionAst(NodeAst::T_CDECTION_DECTIONSFS);
		p->addChild1($1);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| declaration_specifiers init_declarator_list ';'
	{
		NodeAst *p = new DectionAst(NodeAst::T_CDECTION_DECTIONSFS_INITDECTORLIST);
		p->addChild2($1, $2);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

declaration_list
	: declaration
	{ /*directly return the child node*/
		$$ = $1;
	}

	| declaration_list declaration
	{
		NodeAst *p = new DectionListAst(NodeAst::T_CDECTIONLIST_DECTIONLIST_DECTION);
		p->addChild2($1, $2);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

/*******************************type********************************/

declaration_specifiers
	: storage_class_specifier
	{ /*directly return the child node*/
		$$ = $1;
	}

	| storage_class_specifier declaration_specifiers
	{
		NodeAst *p = new DectionSpecifiersAst(NodeAst::T_CDECTIONSF_STORCLASSSF_DECTIONSFS);
		p->addChild2($1, $2);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| type_specifier
	{ /*directly return the child node*/
		$$ = $1;
	}

	| type_specifier declaration_specifiers
	{
		NodeAst *p = new DectionSpecifiersAst(NodeAst::T_CDECTIONSF_TYPESF_DECTIONSFS);
		p->addChild2($1, $2);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| type_qualifier
	{ /*directly return the child node*/
		$$ = $1;
	}

	| type_qualifier declaration_specifiers
	{
		NodeAst *p = new DectionSpecifiersAst(NodeAst::T_CDECTIONSF_TYPEQF_DECTIONSFS);
		p->addChild2($1, $2);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

storage_class_specifier
	: TYPEDEF
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CSTORCLASSSF_TYPEDEF, $1->getToken());
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| EXTERN
	{
	    NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CSTORCLASSSF_EXTERN, $1->getToken());
	    p->setLineno($1->getLineno());
		$$ = p;
	}

	| STATIC
	{
	    NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CSTORCLASSSF_STATIC, $1->getToken());
	    p->setLineno($1->getLineno());
		$$ = p;
	}

	| AUTO
	{
	    NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CSTORCLASSSF_AUTO, $1->getToken());
	    p->setLineno($1->getLineno());
		$$ = p;
	}

	| REGISTER
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CSTORCLASSSF_REGISITER, $1->getToken());
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

type_specifier
	: VOID
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_VOID, $1->getToken());
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| CHAR
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_CHAR, $1->getToken());
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| SHORT
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_SHORT, $1->getToken());
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| INT
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_INT, $1->getToken());
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| LONG
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_LONG, $1->getToken());
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| FLOAT
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_FLOAT, $1->getToken());
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| DOUBLE
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_DOUBLE, $1->getToken());
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| SIGNED
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_SIGNED, $1->getToken());
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| UNSIGNED
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_UNSIGNED, $1->getToken());
		p->setLineno($1->getLineno());
		$$ = p;
	}

	/*| struct_or_union_specifier
	{
		$$ = $1;
	}*/

	| class_specifier
	{ /*directly return the child node*/
		$$ = $1;
	}
	;

type_qualifier
	: CONST
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPEQF_CONST, $1->getToken());
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| VOLATILE
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPEQF_VOLATILE, $1->getToken());
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| VIRTUAL
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPEQF_VIRTUAL, $1->getToken());
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

init_declarator_list
	: init_declarator
	{ /*directly return the child node*/
		$$ = $1;
	}

	| init_declarator_list ',' init_declarator
	{
		NodeAst *p = new InitDectorListAst(NodeAst::T_CINITDECTORLIST_INITDECTORLIST_INITDECTOR);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

init_declarator
	: declarator
	{
		NodeAst *p = new InitDectorAst(NodeAst::T_CINITDECTOR_DECTOR);
		p->addChild1($1);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| declarator '=' initializer
	{
		NodeAst *p = new InitDectorAst(NodeAst::T_CINITDECTOR_ASSGIN_INITZER);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	{
		NodeAst *p = new SpeciQualiFierListAst(NodeAst::T_CSQFLIST_TYPESF_SQFLIST);
		p->addChild2($1, $2);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| type_specifier
	{ /*directly return the child node*/
		$$ = $1;
	}

	| type_qualifier specifier_qualifier_list
	{
		NodeAst *p = new SpeciQualiFierListAst(NodeAst::T_CSQFLIST_TYPEQF_SQFLIST);
		p->addChild2($1, $2);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| type_qualifier
	{ /*directly return the child node*/
		$$ = $1;
	}
	;

/****************************struct***************************************

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}'
	{
		$$ = NULL;
	}

	| struct_or_union '{' struct_declaration_list '}'
	{
		$$ = NULL;
	}

	| struct_or_union IDENTIFIER
	{
		$$ = NULL;
	}
	;

struct_or_union
	: STRUCT
	{
		$$ = NULL;
	}

	| UNION
	{
		$$ = NULL;
	}
	;

struct_declaration_list
	: struct_declaration
	{
		$$ = NULL;
	}

	| struct_declaration_list struct_declaration
	{
		$$ = NULL;
	}
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	{
		$$ = NULL;
	}
	;


struct_declarator_list
	: struct_declarator
	{
		$$ = NULL;
	}

	| struct_declarator_list ',' struct_declarator
	{
		$$ = NULL;
	}
	;

struct_declarator
	: declarator
	{
		$$ = NULL;
	}

	| ':' constant_expression
	{
		$$ = NULL;
	}

	| declarator ':' constant_expression
	{
		$$ = NULL;
	}
	;
***************************************************************/

/************************************class**************************************/

class_specifier
	: CLASS IDENTIFIER '{' class_declaration_list '}'
	{ /*class scope def*/
		NodeAst *p = new ClassSpecifierAst(NodeAst::T_CCLASSSF_CLASS_ID_CLASSDECTIONLIST);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CCLASSSF_CLASS_ID_CLASSDECTIONLIST, $2->getToken());
		p->addChild2(t, $4);
		$$ = p;
	}

	| CLASS IDENTIFIER ':' identifier_list '{' class_declaration_list '}'
	{ //class scope def
		NodeAst *p = new ClassSpecifierAst(NodeAst::T_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST, $2->getToken());
		p->addChild3(t, $4, $6);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| CLASS IDENTIFIER
	{ /*class declaration*/
		NodeAst *p = new ClassSpecifierAst(NodeAst::T_CCLASSSF_CLASS_ID);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CCLASSSF_CLASS_ID, $2->getToken());
		p->addChild1(t);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

class_declaration_list
	: class_declaration
	{ /*directly return the child node*/
		$$ = $1;
	}

	| class_declaration_list class_declaration
	{
		NodeAst *p = new ClassDectionListAst(NodeAst::T_CCLASSDECTIONLIST_CLASSDECTIONLIST_CLASSDECTION);
		p->addChild2($1, $2);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

class_declaration
	: specifier_qualifier_list class_declarator_list ';'
	{
		NodeAst *p = new ClassDectionAst(NodeAst::T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST);
		p->addChild2($1, $2);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| specifier_qualifier_list class_declarator compound_statement
	{
		NodeAst *p = new ClassDectionAst(NodeAst::T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST_COMPSTM);
		p->addChild3($1, $2, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| class_declarator compound_statement
	{ /*this func can be the Constructor or Destructor*/
		NodeAst *p = new ClassDectionAst(NodeAst::T_CCLASSDECTION_CLASSDECTORLIST_COMPSTM);
		p->addChild2($1, $2);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

class_declarator_list
	: class_declarator
	{ /*directly return the child node*/
		$$ = $1;
	}

	| class_declarator_list ',' class_declarator
	{
		NodeAst *p = new ClassDectorListAst(NodeAst::T_CCLASSDECTORLIST_CLASSDECTORLIST_CLASSDECTOR);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

class_declarator
	: declarator
	{
		NodeAst *p = new ClassDectorAst(NodeAst::T_CCLASSDECTOR_DECTOR);
		p->addChild1($1);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

/*********************enum is not implemented************************
enum_specifier
	: ENUM '{' enumerator_list '}'
	{
		$$ = NULL;
	}

	| ENUM IDENTIFIER '{' enumerator_list '}'
	{
		$$ = NULL;
	}

	| ENUM IDENTIFIER
	{
		$$ = NULL;
	}
	;

enumerator_list
	: enumerator
	{
		$$ = NULL;
	}

	| enumerator_list ',' enumerator
	{
		$$ = NULL;
	}
	;

enumerator
	: IDENTIFIER
	{
		$$ = NULL;
	}

	| IDENTIFIER '=' constant_expression
	{
		$$ = NULL;
	}
	;

***********************************************************************/

/***************************declarator*****************************/

declarator
	: pointer direct_declarator
	{
		NodeAst *p = new DectorAst(NodeAst::T_CDECTOR_POINTER_DIRDECTOR);
		p->addChild2($1, $2);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| direct_declarator
	{ /*directly return the child node*/
		$$ = $1;
	}
	;

direct_declarator
	: IDENTIFIER
	{
		NodeAst *p = new DirDectorAst(NodeAst::T_CDIRDECTOR_ID);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CDIRDECTOR_ID, $1->getToken());
		p->addChild1(t);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| '(' declarator ')'
	{ /*directly return the child node*/
		$$ = $2;
	}

	| direct_declarator '[' constant_expression ']'
	{
		NodeAst *p = new DirDectorAst(NodeAst::T_CDIRDECTOR_DIRDECTOR_ARRAY_CONSTEXP);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| direct_declarator '[' ']'
	{
		NodeAst *p = new DirDectorAst(NodeAst::T_CDIRDECTOR_DIRDECTOR_ARRAY_VOID);
		p->addChild1($1);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| direct_declarator '(' parameter_type_list ')'
	{
		NodeAst *p = new DirDectorAst(NodeAst::T_CDIRDECTOR_DIRDECTOR_CALL_PARAMTYPELIST);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| direct_declarator '(' expression ')'
	{
		NodeAst *p = new DirDectorAst(NodeAst::T_CDIRDECTOR_DIRDECTOR_CALL_EXP);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| direct_declarator '(' ')'
	{
		NodeAst *p = new DirDectorAst(NodeAst::T_CDIRDECTOR_DIRDECTOR_CALL_VOID);
		p->addChild1($1);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

/******************************pointer*****************************/

pointer
	: '*'
	{
		$$ = NULL;
	}

	| '*' type_qualifier_list
	{
		$$ = NULL;
	}

	| '*' pointer
	{
		$$ = NULL;
	}

	| '*' type_qualifier_list pointer
	{
		$$ = NULL;
	}
	;

type_qualifier_list
	: type_qualifier
	{ /*directly return the child node*/
		$$ = $1;
	}

	| type_qualifier_list type_qualifier
	{
		NodeAst *p = new TypeQualifierListAst(NodeAst::T_CTYPEQFLIST_TYPEQFLIST_TYPEQF);
		p->addChild2($1, $2);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

/*****************************parameter_declartion*********************/

parameter_type_list
	: parameter_list
	{ /*directly return the child node*/
		$$ = $1;
	}

	| parameter_list ',' ELLIPSIS
	{
		$$ = NULL;
	}
	;

parameter_list
	: parameter_declaration
	{ /*directly return the child node*/
		$$ = $1;
	}

	| parameter_list ',' parameter_declaration
	{
		NodeAst *p = new ParamTypeListAst(NodeAst::T_CPARAMLIST_PARAMLIST_PARAMDECTION);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

parameter_declaration
	: declaration_specifiers declarator
	{ /*this declaration may exist in func def*/
		NodeAst *p = new ParamDectionAst(NodeAst::T_CPARAMDECTION_DECTIONSFS_DECTOR);
		p->addChild2($1, $2);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| declaration_specifiers abstract_declarator
	{ /*this declaration may exist in func declaration*/
		$$ = NULL;
	}

	| declaration_specifiers
	{
		NodeAst *p = new ParamDectionAst(NodeAst::T_CPARAMDECTION_DECTIONSFS);
		p->addChild1($1);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

/*********************************initializer*************************/

identifier_list
	: IDENTIFIER
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CIDLIST_ID, $1->getToken());
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| identifier_list ',' IDENTIFIER
	{
		NodeAst *p = new IdentifierListAst(NodeAst::T_CIDLIST_IDLIST_ID);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CIDLIST_IDLIST_ID, $3->getToken());
		p->addChild2($1, t);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

initializer
	: assignment_expression
	{
		NodeAst *p = new InitzerAst(NodeAst::T_CINITZER_ASSIGNEXP);
		p->addChild1($1);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| '{' initializer_list '}'
	{ /*init value*/
		NodeAst *p = new InitzerAst(NodeAst::T_CINITZER_CINITZERLIST);
		p->addChild1($2);
		p->setLineno($2->getLineno());
		$$ = p;
	}
	;

initializer_list
	: initializer
	{ /*directly return the child node*/
		$$ = $1;
	}

	| initializer_list ',' initializer
	{
		NodeAst *p = new InitzerListAst(NodeAst::T_CINITZERLIST_INITZERLIST_INITZER);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;


type_name
	: specifier_qualifier_list
	{ /*directly return the child node*/
		$$ = $1;
	}

	| specifier_qualifier_list abstract_declarator
	{
		$$ = NULL;
	}
	;

/****************************abstract_declaration*******************/

abstract_declarator
	: pointer
	{
		$$ = NULL;
	}

	| direct_abstract_declarator
	{
		$$ = NULL;
	}

	| pointer direct_abstract_declarator
	{
		$$ = NULL;
	}
	;

direct_abstract_declarator
	: '(' abstract_declarator ')'
	{
		$$ = NULL;
	}

	| '[' ']'
	{
		$$ = NULL;
	}

	| '[' constant_expression ']'
	{
		$$ = NULL;
	}

	| direct_abstract_declarator '[' ']'
	{
		$$ = NULL;
	}

	| direct_abstract_declarator '[' constant_expression ']'
	{
		$$ = NULL;
	}

	| '(' ')'
	{
		$$ = NULL;
	}

	| '(' parameter_type_list ')'
	{
		$$ = NULL;
	}

	| direct_abstract_declarator '(' ')'
	{
		$$ = NULL;
	}

	| direct_abstract_declarator '(' parameter_type_list ')'
	{
		$$ = NULL;
	}
	;

/*****************************statement*****************************/

statement
	: labeled_statement
	{ /*directly return the child node*/
		$$ = $1;
	}

	| compound_statement
	{ /*directly return the child node*/
		$$ = $1;
	}

	| expression_statement
	{ /*directly return the child node*/
		$$ = $1;
	}

	| selection_statement
	{ /*directly return the child node*/
		$$ = $1;
	}

	| iteration_statement
	{ /*directly return the child node*/
		$$ = $1;
	}

	| jump_statement
	{ /*directly return the child node*/
		$$ = $1;
	}
	;

labeled_statement
	: IDENTIFIER ':' statement
	{
		NodeAst *p = new LabeledStmAst(NodeAst::T_CLABSTM_ID_STM);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CLABSTM_ID_STM, $1->getToken());
		p->addChild2(t, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| CASE constant_expression ':' statement
	{
		NodeAst *p = new LabeledStmAst(NodeAst::T_CLABSTM_CASE_CONSTEXP_STM);
		p->addChild2($2, $4);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| DEFAULT ':' statement
	{
		NodeAst *p = new LabeledStmAst(NodeAst::T_CLABSTM_DEFAULT_STM);
		p->addChild1($3);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

expression_statement
	: ';'
	{
		NodeAst *p = new ExpStmAst(NodeAst::T_CEXPSTM_VOID);
		$$ = p;
	}

	| expression ';'
	{
		NodeAst *p = new ExpStmAst(NodeAst::T_CEXPSTM_EXP);
		p->addChild1($1);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

compound_statement
	: '{' '}'
	{ /*local scope*/
		NodeAst *p = new CompoundStmAst(NodeAst::T_CCOMPSTM_VOID);
		$$ = p;
	}

	| '{' statement_list '}'
	{ /*local scope*/
		NodeAst *p = new CompoundStmAst(NodeAst::T_CCOMPSTM_STMLIST);
		p->addChild1($2);
		p->setLineno($2->getLineno());
		$$ = p;
	}

	| '{' declaration_list '}'
	{ /*local scope*/
		NodeAst *p = new CompoundStmAst(NodeAst::T_CCOMPSTM_DECTION_LIST);
		p->addChild1($2);
		p->setLineno($2->getLineno());
		$$ = p;
	}

	| '{' declaration_list statement_list '}'
	{ /*local scope*/
		NodeAst *p = new CompoundStmAst(NodeAst::T_CCOMPSTM_DECTIONLIST_STMLIST);
		p->addChild2($2, $3);
		p->setLineno($2->getLineno());
		$$ = p;
	}
	;

statement_list
	: statement
	{ /*directly return the child node*/
		$$ = $1;
	}

	| statement_list statement
	{
		NodeAst *p = new StmListAst(NodeAst::T_CSTMLIST_STMLIST_STM);
		p->addChild2($1, $2);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

selection_statement
	: IF '(' expression ')' statement %prec LOWER_THAN_ELSE
	{
		NodeAst *p = new SelectionStmAst(NodeAst::T_CSELSTM_IF_EXP_STM);
		p->addChild2($3, $5);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| IF '(' expression ')' statement ELSE statement
	{
		NodeAst *p = new SelectionStmAst(NodeAst::T_CSELSTM_IF_EXP_STM_ELSE_STM);
		p->addChild3($3, $5, $7);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| SWITCH '(' expression ')' statement
	{
		NodeAst *p = new SelectionStmAst(NodeAst::T_CSELSTM_SWITCH_EXP_STM);
		p->addChild2($3, $5);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

iteration_statement
	: WHILE '(' expression ')' statement
	{
		NodeAst *p = new IterationStmAst(NodeAst::T_CITRSTM_WHILE_EXP_STM);
		p->addChild2($3, $5);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| DO statement WHILE '(' expression ')' ';'
	{
		NodeAst *p = new IterationStmAst(NodeAst::T_CITRSTM_DO_STM_WHILE_EXP);
		p->addChild2($2, $5);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| FOR '(' expression_statement expression_statement expression ')' statement
	{
		NodeAst *p = new IterationStmAst(NodeAst::T_CITRSTM_FOR_EXPSTM_EXPSTM_EXP_STM);
		p->addChild4($3, $4, $5, $7);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

jump_statement
	: GOTO IDENTIFIER ';'
	{
		NodeAst *p = new JumpStmAst(NodeAst::T_CJUMPSTM_GOTO_ID);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CJUMPSTM_GOTO_ID, $2->getToken());
		p->addChild1(t);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| CONTINUE ';'
	{
		NodeAst *p = new JumpStmAst(NodeAst::T_CJUMPSTM_CONTINUE);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| BREAK ';'
	{
		NodeAst *p = new JumpStmAst(NodeAst::T_CJUMPSTM_BREAK);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| RETURN ';'
	{
		NodeAst *p = new JumpStmAst(NodeAst::T_CJUMPSTM_RETURN);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| RETURN expression ';'
	{
		NodeAst *p = new JumpStmAst(NodeAst::T_CJUMPSTM_RETURN_EXP);
		p->addChild1($2);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

/*******************************expression********************************/

expression
	: assignment_expression
	{ /*directly return the child node*/
		$$ = $1;
	}

	| expression ',' assignment_expression
	{
		NodeAst *p = new ExpAst(NodeAst::T_CEXP_EXP_ASSIGNEXP);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

assignment_expression
	: conditional_expression
	{
		NodeAst *p = new AssignExpAst(NodeAst::T_CASSIGNEXP_CONDITIONALEXP);
		p->addChild1($1);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| unary_expression assignment_operator assignment_expression
	{
		NodeAst *p = new AssignExpAst(NodeAst::T_CASSIGNEXP_UNARYEXP_ASSIGN_OP_ASSIGNEXP);
		p->addChild3($1, $2, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| NEW_OP IDENTIFIER '(' ')'
	{
		NodeAst *p = new AssignExpAst(NodeAst::T_CASSIGNEXP_NEW_ID_VOID);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CASSIGNEXP_NEW_ID_VOID, $2->getToken());
		p->addChild1(t);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| DELETE_OP IDENTIFIER
	{
		NodeAst *p = new AssignExpAst(NodeAst::T_CASSIGNEXP_DELETE_ID);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CASSIGNEXP_DELETE_ID, $2->getToken());
		p->addChild1(t);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

assignment_operator
	: '='
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CASSIGN_OP_ASSIGN, "=");
		$$ = p;
	}

	| MUL_ASSIGN
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CASSIGN_OP_MUL_ASSIGN, $1->getToken());
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| DIV_ASSIGN
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CASSIGN_OP_DIV_ASSIGN, $1->getToken());
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| MOD_ASSIGN
	{
		$$ = NULL;
	}

	| ADD_ASSIGN
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CASSIGN_OP_ADD_ASSIGN, $1->getToken());
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| SUB_ASSIGN
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CASSIGN_OP_SUB_ASSIGN, $1->getToken());
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| LEFT_ASSIGN
	{
		$$ = NULL;
	}

	| RIGHT_ASSIGN
	{
		$$ = NULL;
	}

	| AND_ASSIGN
	{
		$$ = NULL;
	}

	| XOR_ASSIGN
	{
		$$ = NULL;
	}

	| OR_ASSIGN
	{
		$$ = NULL;
	}
	;

conditional_expression
	: logical_or_expression
	{ /*directly return the child node*/
		$$ = $1;
	}
	;

constant_expression
	: conditional_expression
	{ /*directly return the child node*/
		$$ = $1;
	}
	;

logical_or_expression
	: logical_and_expression
	{ /*directly return the child node*/
		$$ = $1;
	}

	| logical_or_expression OR_OP logical_and_expression
	{
		NodeAst *p = new LogicalOrExpAst(NodeAst::T_CLOGOREXP_LOGOREXP_OR_OP_LOGANDEXP);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

logical_and_expression
	: equality_expression
	{ /*directly return the child node*/
		$$ = $1;
	}

	| logical_and_expression AND_OP equality_expression
	{
		NodeAst *p = new LogicalAndExpAst(NodeAst::T_CLOGANDEXP_LOGANDEXP_AND_OP_EQUALEXP);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

/*************************inclusive or exclusive or and_exp***************************
inclusive_or_expression
	: exclusive_or_expression
	{
		$$ = NULL;
	}

	| inclusive_or_expression '|' exclusive_or_expression
	{
		$$ = NULL;
	}
	;

exclusive_or_expression
	: and_expression
	{
		$$ = NULL;
	}

	| exclusive_or_expression '^' and_expression
	{
		$$ = NULL;
	}
	;

and_expression
	: equality_expression
	{
		$$ = NULL;
	}

	| and_expression '&' equality_expression
	{
		$$ = NULL;
	}
	;

**************************************************************************/

equality_expression
	: relational_expression
	{ /*directly return the child node*/
		$$ = $1;
	}

	| equality_expression EQ_OP relational_expression
	{
		NodeAst *p = new EqualExpAst(NodeAst::T_CEQUALEXP_EQUALEXP_EQ_OP_RELEXP);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| equality_expression NE_OP relational_expression
	{
		NodeAst *p = new EqualExpAst(NodeAst::T_CEQUALEXP_EQUALEXP_NE_OP_RELEXP);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

relational_expression
	: additive_expression
	{ /*directly return the child node*/
		$$ = $1;
	}

	| relational_expression '<' additive_expression
	{
		NodeAst *p = new RelationExpAst(NodeAst::T_CRELEXP_RELEXP_L_OP_ADDEXP);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| relational_expression '>' additive_expression
	{
		NodeAst *p = new RelationExpAst(NodeAst::T_CRELEXP_RELEXP_G_OP_ADDEXP);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| relational_expression LE_OP additive_expression
	{
		NodeAst *p = new RelationExpAst(NodeAst::T_CRELEXP_RELEXP_LE_OP_ADDEXP);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| relational_expression GE_OP additive_expression
	{
		NodeAst *p = new RelationExpAst(NodeAst::T_CRELEXP_RELEXP_GE_OP_ADDEXP);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

/**********************shift_expression*****************************
shift_expression
	: additive_expression
	{
		$$ = NULL;
	}

	| shift_expression LEFT_OP additive_expression
	{
		$$ = NULL;
	}

	| shift_expression RIGHT_OP additive_expression
	{
		$$ = NULL;
	}
	;
************************************************************************/

additive_expression
	: multiplicative_expression
	{ /*directly return the child node*/
		$$ = $1;
	}

	| additive_expression '+' multiplicative_expression
	{
		NodeAst *p = new AddExpAst(NodeAst::T_CADDEXP_ADDEXP_ADD_OP_MULEXP);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| additive_expression '-' multiplicative_expression
	{
		NodeAst *p = new AddExpAst(NodeAst::T_CADDEXP_ADDEXP_SUB_OP_MULEXP);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

multiplicative_expression
	: cast_expression
	{ /*directly return the child node*/
		$$ = $1;
	}

	| multiplicative_expression '*' cast_expression
	{
		NodeAst *p = new MulExpAst(NodeAst::T_CMULEXP_MULEXP_MUL_OP_CASTEXP);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| multiplicative_expression '/' cast_expression
	{
		NodeAst *p = new MulExpAst(NodeAst::T_CMULEXP_MULEXP_DIV_OP_CASTEXP);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| multiplicative_expression '%' cast_expression
	{
		$$ = NULL;
	}
	;

cast_expression
	: unary_expression
	{ /*directly return the child node*/
		$$ = $1;
	}

	| '(' type_name ')' cast_expression
	{
		$$ = NULL;
	}
	;

unary_expression
	: postfix_expression
	{ /*directly return the child node*/
		$$ = $1;
	}

	| INC_OP unary_expression
	{
		NodeAst *p = new UnaryExpAst(NodeAst::T_CUNARYEXP_INC_OP_UNARAYEXP);
		p->addChild1($2);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| DEC_OP unary_expression
	{
		NodeAst *p = new UnaryExpAst(NodeAst::T_CUNARYEXP_DEC_OP_UNARYEXP);
		p->addChild1($2);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| unary_operator cast_expression
	{
		NodeAst *p = new UnaryExpAst(NodeAst::T_CUNARYEXP_UNARY_OP_CASTEXP);
		p->addChild2($1, $2);
		p->setLineno($2->getLineno());
		$$ = p;
	}

	| SIZEOF unary_expression
	{
		$$ = NULL;
	}
	;

unary_operator
	: '&'
	{
		$$ = NULL;
	}

	| '*'
	{
		$$ = NULL;
	}

	| '+'
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CUNARY_OP_ADD_OP, "+");
		$$ = p;
	}

	| '-'
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CUNARY_OP_SUB_OP, "-");
		$$ = p;
	}

	| '~'
	{
		$$ = NULL;
	}

	| '!'
	{
		$$ = NULL;
	}
	;

postfix_expression
	: primary_expression
	{ /*directly return the child node*/
		$$ = $1;
	}

	| postfix_expression '[' expression ']'
	{
		NodeAst *p = new PostfixExpAst(NodeAst::T_CPOSTEXP_POSTEXP_ARRAY_EXP);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| postfix_expression '(' ')'
	{
		NodeAst *p = new PostfixExpAst(NodeAst::T_CPOSTEXP_POSTEXP_CALL_VOID);
		p->addChild1($1);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| postfix_expression '(' argument_expression_list ')'
	{ /*call the func callee*/
		NodeAst *p = new PostfixExpAst(NodeAst::T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| postfix_expression '.' IDENTIFIER
	{
		NodeAst *p = new PostfixExpAst(NodeAst::T_CPOSTEXP_POSTEXP_REF_ID);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CPOSTEXP_POSTEXP_REF_ID, $3->getToken());
		p->addChild2($1, t);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| postfix_expression PTR_OP IDENTIFIER
	{
		$$ = NULL;
	}

	| postfix_expression INC_OP
	{
		NodeAst *p = new PostfixExpAst(NodeAst::T_CPOSTEXP_POSTEXP_INC_OP);
		p->addChild1($1);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| postfix_expression DEC_OP
	{
		NodeAst *p = new PostfixExpAst(NodeAst::T_CPOSTEXP_POSTEXP_DEC_OP);
		p->addChild1($1);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

primary_expression
	: IDENTIFIER
	{
		NodeAst *p = new PrimaryExpAst(NodeAst::T_CPRIMEXP_ID);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CPRIMEXP_ID, $1->getToken());
		p->addChild1(t);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| constant_value
	{
		NodeAst *p = new PrimaryExpAst(NodeAst::T_CPRIMEXP_CONST);
		p->addChild1($1);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| STRING_LITERAL
	{
		NodeAst *p = new PrimaryExpAst(NodeAst::T_CPRIMEXP_STR);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CPRIMEXP_STR, $1->getToken());
		p->addChild1(t);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| '(' expression ')'
	{
		NodeAst *p = new PrimaryExpAst(NodeAst::T_CPRIMEXP_EXP);
		p->addChild1($2);
		p->setLineno($2->getLineno());
		$$ = p;
	}
	;

argument_expression_list
	: assignment_expression
	{
		NodeAst *p = new ArgExpListAst(NodeAst::T_CARGEXPLIST_ASSGEXP);
		p->addChild1($1);
		p->setLineno($1->getLineno());
		$$ = p;
	}

	| argument_expression_list ',' assignment_expression
	{
		NodeAst *p = new ArgExpListAst(NodeAst::T_CARGEXPLIST_ARGEXPLIST_ASSGEXP);
		p->addChild2($1, $3);
		p->setLineno($1->getLineno());
		$$ = p;
	}
	;

constant_value
        : INTEGER_CONSTANT
        {
			NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CCONSTVAR_INT_CONST, $1->getToken());
			p->setLineno($1->getLineno());
			$$ = p;
        }

        | CHARACTER_CONSTANT
        {
			NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CCONSTVAR_CHAR_CONST, $1->getToken());
			p->setLineno($1->getLineno());
			$$ = p;
        }

        | FLOATING_CONSTANT
        {
			NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CCONSTVAR_FLOAT_CONST, $1->getToken());
			p->setLineno($1->getLineno());
			$$ = p;
        }
        ;

%%




int yyerror(const char *msg)
{

	return 0;
}


int main() {

   yyparse();

   cout << "yylineno" << yylineno <<endl;

   NodeAst::printNodeTree(NodeAst::getNodeTreeRoot(), 0);

   NodeAst::dotBfsNodeTree(NodeAst::getNodeTreeRoot());

   NodeAst::s_context = NodeAst::getSingletonContext();


   if (NULL != NodeAst::s_root) {
		NodeAst::s_root->walk();
   }


   LexNodeAst::freeLexNodeList();
   NodeAst::freeNodeList();



   return 0;
}

