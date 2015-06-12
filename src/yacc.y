%{
#include "../include/AstHead.h"
#include <string>

using namespace std;

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
   string yystring;
   NodeAst *pnode;
}

/**********************Terminator******************************/

%token<yystring> IDENTIFIER CONSTANT INTEGER_CONSTANT CHARACTER_CONSTANT FLOATING_CONSTANT STRING_LITERAL SIZEOF
%token<yystring> PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP NEW_OP DELETE_OP
%token<yystring> AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token<yystring> SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token<yystring> XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token<yystring> TYPEDEF EXTERN STATIC AUTO REGISTER
%token<yystring> CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
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
%type<pnode>  struct_or_union_specifier
%type<pnode>  struct_or_union
%type<pnode>  struct_declaration_list
%type<pnode>  struct_declaration
%type<pnode>  struct_declarator_list
%type<pnode>  struct_declarator
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
		$$ = p;
	}
	;


/***************************declaration***********************************/

external_declaration
	: function_definition
	{ /*global scope func*/
		NodeAst *p = new ExtDectionAst(NodeAst::T_CEXTDECTION_FUNCDEF);
		p->addChild1($1);
		$$ = p;
	}

	| declaration
	{ /*global scope var*/
		NodeAst *p = new ExtDectionAst(NodeAst::T_CEXTDECTION_DECTION);
		p->addChild1($1);
		$$ = p;
	}
	;

function_definition
	:
	| declaration_specifiers declarator compound_statement
	{ /*func scope*/
		NodeAst *p = new FuncDefAst(NodeAst::T_CFUNCDEF_DECTIONSFS_DECTOR_COMPSTM);
		p->addChild3($1, $2, $3);
		$$ = p;
	}

	| declarator compound_statement
	{ /*this func can be the Constructor or Destructor*/
		NodeAst *p = new FuncDefAst(NodeAst::T_CFUNCDEF_DECTOR_COMPSTM);
		p->addChild2($1, $2);
		$$ = p;
	}
	;

declaration
	: declaration_specifiers ';'
	{
		NodeAst *p = new DectionAst(NodeAst::T_CDECTION_DECTIONSFS);
		p->addChild1($1);
		$$ = p;
	}

	| declaration_specifiers init_declarator_list ';'
	{
		NodeAst *p = new DectionAst(NodeAst::T_CDECTION_DECTIONSFS_INITDECTORLIST);
		p->addChild2($1, $2);
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
		NodeAst *p = new DectionSpecifiersAst(NodeAst::T_CDECTIONSF_STORCLASSSF_DECTIONSF);
		p->addChild2($1, $2);
		$$ = p;
	}

	| type_specifier
	{ /*directly return the child node*/
		$$ = $1;
	}

	| type_specifier declaration_specifiers
	{
		NodeAst *p = new DectionSpecifiersAst(NodeAst::T_CDECTIONSF_TYPESF_DECTIONSF);
		p->addChild2($1, $2);
		$$ = p;
	}

	| type_qualifier
	{ /*directly return the child node*/
		$$ = $1;
	}

	| type_qualifier declaration_specifiers
	{
		NodeAst *p = new DectionSpecifiersAst(NodeAst::T_CDECTIONSF_TYPEQF_DECTIONSF);
		p->addChild2($1, $2);
		$$ = p;
	}
	;

storage_class_specifier
	: TYPEDEF
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CSTORCLASSSF_TYPEDEF, $1);
		$$ = p;
	}

	| EXTERN
	{
	    NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CSTORCLASSSF_EXTERN, $1);
		$$ = p;
	}

	| STATIC
	{
	    NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CSTORCLASSSF_STATIC, $1);
		$$ = p;
	}

	| AUTO
	{
	    NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CSTORCLASSSF_AUTO, $1);
		$$ = p;
	}

	| REGISTER
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CSTORCLASSSF_REGISITER, $1);
		$$ = p;
	}
	;

type_specifier
	: VOID
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_VOID, $1);
		$$ = p;
	}

	| CHAR
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_CHAR, $1);
		$$ = p;
	}

	| SHORT
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_SHORT, $1);
		$$ = p;
	}

	| INT
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_INT, $1);
		$$ = p;
	}

	| LONG
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_LONG, $1);
		$$ = p;
	}

	| FLOAT
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_FLOAT, $1);
		$$ = p;
	}

	| DOUBLE
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_DOUBLE, $1);
		$$ = p;
	}

	| SIGNED
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_SIGNED, $1);
		$$ = p;
	}

	| UNSIGNED
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPESF_UNSIGNED, $1);
		$$ = p;
	}

	| struct_or_union_specifier
	{ /*directly return the child node*/
		$$ = $1;
	}

	| class_specifier
	{ /*directly return the child node*/
		$$ = $1;
	}
	;

type_qualifier
	: CONST
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPEQF_CONST, $1);
		$$ = p;
	}

	| VOLATILE
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPEQF_VOLATILE, $1);
		$$ = p;
	}

	| VIRTUAL
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CTYPEQF_VIRTUAL, $1);
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
		$$ = p;
	}
	;

init_declarator
	: declarator
	{
		NodeAst *p = new InitDectorAst(NodeAst::T_CINITDECTOR_DECTOR);
		p->addChild1($1);
		$$ = p;
	}

	: declarator '=' initializer
	{
		NodeAst *p = new InitDectorAst(NodeAst::T_CINITDECTOR_ASSGIN_INITZER);
		p->addChild2($1, $3);
		$$ = p;
	}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list
	{
		NodeAst *p = new SpeciQualiFierListAst(NodeAst::T_CSQFLIST_TYPESF_SQFLIST);
		p->addChild2($1, $2);
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
		$$ = p;
	}

	| type_qualifier
	{ /*directly return the child node*/
		$$ = $1;
	}
	;

/****************************struct***************************************/

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

/***************************class**************************************/

class_specifier
	: CLASS IDENTIFIER '{' class_declaration_list '}'
	{ /*class scope def*/
		NodeAst *p = new ClassSpecifierAst(NodeAst::T_CCLASSSF_CLASS_ID_CLASSDECTIONLIST);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CCLASSSF_CLASS_ID_CLASSDECTIONLIST, $2);
		p->addChild3($1, t, $4);
		$$ = p;
	}

	| CLASS IDENTIFIER ':' identifier_list '{' class_declaration_list '}'
	{ /*class scope def*/
		NodeAst *p = new ClassSpecifierAst(NodeAst::T_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST, $2);
		p->addChild4($1, t, $4, $6);
		$$ = p;
	}

	| CLASS IDENTIFIER
	{ /*class declaration*/
		NodeAst *p = new ClassSpecifierAst(NodeAst::T_CCLASSSF_CLASS_ID);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CCLASSSF_CLASS_ID, $2);
		p->addChild2($1, t);
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
		$$ = p;
	}
	;

class_declaration
	: specifier_qualifier_list class_declarator_list ';'
	{
		NodeAst *p = new ClassDectionAst(NodeAst::T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST);
		p->addChild2($1, $2);
		$$ = p;
	}

	: function_definition
	{
		NodeAst *p = new ClassDectionAst(NodeAst::T_CCLASSDECTION_FUNCDEF);
		p->addChild1($1);
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
		$$ = p;
	}
	;

class_declarator
	: declarator
	{
		NodeAst *p = new ClassDectorAst(NodeAst::T_CCLASSDECTOR_DECTOR);
		p->addChild1($1);
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
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CDIRDECTOR_ID, $1);
		$$ = p;
	}

	| '(' declarator ')'
	{ /*directly return the child node*/
		$$ = $1;
	}

	| direct_declarator '[' constant_expression ']'
	{
		NodeAst *p = new DirDectorAst(NodeAst::T_CDIRDECTOR_DIRDECTOR_ARRAY_CONSTEXP);
		p->addChild2($1, $3);
		$$ = p;
	}

	| direct_declarator '[' ']'
	{
		NodeAst *p = new DirDectorAst(NodeAst::T_CDIRDECTOR_DIRDECTOR_ARRAY_VOID);
		p->addChild1($1);
		$$ = p;
	}

	| direct_declarator '(' parameter_type_list ')'
	{
		NodeAst *p = new DirDectorAst(NodeAst::T_CDIRDECTOR_DIRDECTOR_CALL_PARAMTYPELIST);
		p->addChild2($1, $3);
		$$ = p;
	}

	| direct_declarator '(' expression ')'
	{
		NodeAst *p = new DirDectorAst(NodeAst::T_CDIRDECTOR_DIRDECTOR_CALL_EXP);
		p->addChild2($1, $3);
		$$ = p;
	}

	| direct_declarator '(' ')'
	{
		NodeAst *p = new DirDectorAst(NodeAst::T_CDIRDECTOR_DIRDECTOR_CALL_VOID);
		p->addChild1($1);
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
		$$ = p;
	}
	;

parameter_declaration
	: declaration_specifiers declarator
	{ /*this declaration may exist in func def*/
		NodeAst *p = new ParamDectionAst(NodeAst::T_CPARAMDECTION_DECTIONSFS_DECTOR);
		p->addChild2($1, $2);
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
		$$ = p;
	}
	;

/*********************************initializer*************************/

identifier_list
	: IDENTIFIER
	{
		NodeAst *p = new TerminateAst(NodeAst::T_CTERMINATE_CIDLIST_ID, $1);
		$$ = p;
	}

	| identifier_list ',' IDENTIFIER
	{
		NodeAst *p = new IdentifierListAst(NodeAst::T_CIDLIST_IDLIST_ID);
		NodeAst *t = new TerminateAst(NodeAst::T_CTERMINATE_CIDLIST_IDLIST_ID, $3);
		p->addChild2($1, t);
		$$ = p;
	}
	;

initializer
	: assignment_expression
	{
		NodeAst *p = new InitzerAst(NodeAst::T_CINITZER_ASSIGNEXP);
		p->addChild1($1);
		$$ = p;
	}

	| '{' initializer_list '}'
	{ /*init value*/
		NodeAst *p = new InitzerAst(NodeAst::T_CINITZER_CINITZERLIST);
		p->addChild1($1);
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
		p->addChild2($1, $2);
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
	{  }

	| CASE constant_expression ':' statement
	{  }

	| DEFAULT ':' statement
	{  }
	;

expression_statement
	: ';'
	{  }

	| expression ';'
	{  }
	;

compound_statement
	: '{' '}'
	{ /*local scope*/ }

	| '{' statement_list '}'
	{ /*local scope*/ }

	| '{' declaration_list '}'
	{ /*local scope*/ }

	| '{' declaration_list statement_list '}'
	{ /*local scope*/ }
	;

statement_list
	: statement
	{ /*directly return the child node*/ }

	| statement_list statement
	{  }
	;

selection_statement
	: IF '(' expression ')' statement %prec LOWER_THAN_ELSE
	{   }

	| IF '(' expression ')' statement ELSE statement
	{   }

	| SWITCH '(' expression ')' statement
	{  }
	;

iteration_statement
	: WHILE '(' expression ')' statement
	{   }

	| DO statement WHILE '(' expression ')' ';'
	{   }

	| FOR '(' expression_statement expression_statement expression ')' statement
	{  }
	;

jump_statement
	: GOTO IDENTIFIER ';'
	{   }

	| CONTINUE ';'
	{   }

	| BREAK ';'
	{   }

	| RETURN ';'
	{  }

	| RETURN expression ';'
	{   }
	;

/*******************************expression********************************/

expression
	: assignment_expression
	{/*directly return the child node*/  }

	| expression ',' assignment_expression
	{ }
	;

assignment_expression
	: conditional_expression
	{ }

	| unary_expression assignment_operator assignment_expression
	{  }
	;

assignment_operator
	: '='
	{ /*directly return the child node*/ }

	| MUL_ASSIGN
	{ /*directly return the child node*/ }

	| DIV_ASSIGN
	{ /*directly return the child node*/ }

	| MOD_ASSIGN
	{ /*directly return the child node*/ }

	| ADD_ASSIGN
	{ /*directly return the child node*/ }

	| SUB_ASSIGN
	{ /*directly return the child node*/ }

	| LEFT_ASSIGN
	{ /*directly return the child node*/ }

	| RIGHT_ASSIGN
	{ /*directly return the child node*/ }

	| AND_ASSIGN
	{ /*directly return the child node*/ }

	| XOR_ASSIGN
	{ /*directly return the child node*/ }

	| OR_ASSIGN
	{ /*directly return the child node*/ }
	;

conditional_expression
	: logical_or_expression
	{ /*directly return the child node*/ }
	;

constant_expression
	: conditional_expression
	{ /*directly return the child node*/ }
	;

logical_or_expression
	: logical_and_expression
	{ /*directly return the child node*/ }

	| logical_or_expression OR_OP logical_and_expression
	{  }
	;

logical_and_expression
	: equality_expression
	{ /*directly return the child node*/ }

	| logical_and_expression AND_OP equality_expression
	{  }
	;

/*************************inclusive or exclusive or and_exp***************************
inclusive_or_expression
	: exclusive_or_expression
	{ }

	| inclusive_or_expression '|' exclusive_or_expression
	{  }
	;

exclusive_or_expression
	: and_expression
	{ }

	| exclusive_or_expression '^' and_expression
	{  }
	;

and_expression
	: equality_expression
	{  }

	| and_expression '&' equality_expression
	{  }
	;
**************************************************************************/

equality_expression
	: relational_expression
	{ /*directly return the child node*/ }

	| equality_expression EQ_OP relational_expression
	{  }

	| equality_expression NE_OP relational_expression
	{  }
	;

relational_expression
	: additive_expression
	{ /*directly return the child node*/ }

	| relational_expression '<' additive_expression
	{ }

	| relational_expression '>' additive_expression
	{ }

	| relational_expression LE_OP additive_expression
	{ }

	| relational_expression GE_OP additive_expression
	{ }
	;

/**********************shift_expression*****************************
shift_expression
	: additive_expression
	{ }

	| shift_expression LEFT_OP additive_expression
	{ }

	| shift_expression RIGHT_OP additive_expression
	{ }
	;
************************************************************************/

additive_expression
	: multiplicative_expression
	{ /*directly return the child node*/ }

	| additive_expression '+' multiplicative_expression
	{ }

	| additive_expression '-' multiplicative_expression
	{ }
	;

multiplicative_expression
	: cast_expression
	{ /*directly return the child node*/ }

	| multiplicative_expression '*' cast_expression
	{  }

	| multiplicative_expression '/' cast_expression
	{  }

	| multiplicative_expression '%' cast_expression
	{  }
	;

cast_expression
	: unary_expression
	{ /*directly return the child node*/ }

	| '(' type_name ')' cast_expression
	{  }
	;

unary_expression
	: postfix_expression
	{ /*directly return the child node*/ }

	| INC_OP unary_expression
	{  }

	| DEC_OP unary_expression
	{  }

	| unary_operator cast_expression
	{  }

	| SIZEOF unary_expression
	{  }
	;

unary_operator
	: '&'
	{ /*directly return the child node*/ }

	| '*'
	{ /*directly return the child node*/ }

	| '+'
	{ /*directly return the child node*/  }

	| '-'
	{ /*directly return the child node*/ }

	| '~'
	{ /*directly return the child node*/ }

	| '!'
	{ /*directly return the child node*/ }
	;

postfix_expression
	: primary_expression
	{ /*directly return the child node*/ }

	| postfix_expression '[' expression ']'
	{ }

	| postfix_expression '(' ')'
	{ }

	| postfix_expression '(' argument_expression_list ')'
	{ /*call the func callee*/ }

	| postfix_expression '.' IDENTIFIER
	{ }

	| postfix_expression PTR_OP IDENTIFIER
	{ }

	| postfix_expression INC_OP
	{ }

	| postfix_expression DEC_OP
	{ }

	| NEW_OP IDENTIFIER '(' ')'
	{ }

	| DELETE_OP IDENTIFIER
	{ }
	;

primary_expression
	: IDENTIFIER
	{  }

	| constant_value
	{  }

	| STRING_LITERAL
	{  }

	| '(' expression ')'
	{  }
	;

argument_expression_list
	: assignment_expression
	{ /*directly return the child node*/ }

	| argument_expression_list ',' assignment_expression
	{ }
	;

constant_value
        : INTEGER_CONSTANT
        { /*directly return the child node*/ }

        | CHARACTER_CONSTANT
        { /*directly return the child node*/ }

        | FLOATING_CONSTANT
        { /*directly return the child node*/ }
        ;

%%




int yyerror(const char *msg)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", yycolumn, "^", yycolumn, msg);
	return 0;
}

list<NodeTag *> NodeTag::s_nodeList;
map< string, list<SymbolElm> >  NodeTag::s_symbolMap;

int main() {

   yyparse();

   cout << "yylineno" << yylineno <<endl;
   NodeTag::freeNodeList();
   return 0;
}

