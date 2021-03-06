#ifndef INCLUDE_NODEAST_H
#define INCLUDE_NODEAST_H

#include <vector>
#include <string>
#include <list>
#include "../LogiMsg.h"
#include "../symbol/Scope.h"
#include "../symbol/Context.h"
#include "../symbol/ItmCode.h"
#include <cstdlib>

using namespace std;


class LexNodeAst {
public:
	string token;
	int lineno;
	static list<LexNodeAst *> s_lexNodeList;

public:
	LexNodeAst(char *token_t, int lineno_t);

	string getToken();
	int getLineno();

	static void freeLexNodeList();
};


class NodeAst {
	public:

		enum NodeType {
			//invalid
			T_INVALID,

		    //const_value
			T_CTERMINATE_CCONSTVAR_INT_CONST,
			T_CTERMINATE_CCONSTVAR_CHAR_CONST,
			T_CTERMINATE_CCONSTVAR_FLOAT_CONST,

			//argument_expression_list
			T_CARGEXPLIST_ASSGEXP,
			T_CARGEXPLIST_ARGEXPLIST_ASSGEXP,

			//primary_expression
			T_CPRIMEXP_ID, T_CTERMINATE_CPRIMEXP_ID,
			T_CPRIMEXP_CONST,
			T_CPRIMEXP_STR, T_CTERMINATE_CPRIMEXP_STR,
			T_CPRIMEXP_EXP,

			//postfix_expression
			T_CPOSTEXP_PRIMEXP,
			T_CPOSTEXP_POSTEXP_ARRAY_EXP,
			T_CPOSTEXP_POSTEXP_CALL_VOID,
			T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST,
			T_CPOSTEXP_POSTEXP_REF_ID, T_CTERMINATE_CPOSTEXP_POSTEXP_REF_ID,
			T_CPOSTEXP_POSTEXP_PTR_ID, T_CTERMINATE_CPOSTEXP_POSTEXP_PTR_ID,
			T_CPOSTEXP_POSTEXP_INC_OP,
			T_CPOSTEXP_POSTEXP_DEC_OP,

			//unary_operator
			T_CTERMINATE_CUNARY_OP_AND_OP,
			T_CTERMINATE_CUNARY_OP_REF_OP,
			T_CTERMINATE_CUNARY_OP_ADD_OP,
			T_CTERMINATE_CUNARY_OP_SUB_OP,
			T_CTERMINATE_CUNARY_OP_COMP_OP,
			T_CTERMINATE_CUNARY_OP_NOT_OP,

			//unary_expression
			T_CUNARYEXP_POSTEXP,
			T_CUNARYEXP_INC_OP_UNARAYEXP,
			T_CUNARYEXP_DEC_OP_UNARYEXP,
			T_CUNARYEXP_UNARY_OP_CASTEXP,
			T_CUNARYEXP_SIZEOF_UNARAYEXP,

			//cast_expression
			T_CCASTEXP_UNARYEXP,
			T_CCASTEXP_TYPENAME_CASTEXP,

			//multiplicative_expression
			T_CMULEXP_CASTEXP,
			T_CMULEXP_MULEXP_MUL_OP_CASTEXP,
			T_CMULEXP_MULEXP_DIV_OP_CASTEXP,
			T_CMULEXP_MULEXP_MOD_OP_CASTEXP,

			//additive_expression
			T_CADDEXP_MULEXP,
			T_CADDEXP_ADDEXP_ADD_OP_MULEXP,
			T_CADDEXP_ADDEXP_SUB_OP_MULEXP,

			/*shift_expression*/

			//relational_expression
			T_CRELEXP_ADDEXP,
			T_CRELEXP_RELEXP_L_OP_ADDEXP,
			T_CRELEXP_RELEXP_G_OP_ADDEXP,
			T_CRELEXP_RELEXP_LE_OP_ADDEXP,
			T_CRELEXP_RELEXP_GE_OP_ADDEXP,

			//equality_expression
			T_CEQUALEXP_RELEXP,
			T_CEQUALEXP_EQUALEXP_EQ_OP_RELEXP,
			T_CEQUALEXP_EQUALEXP_NE_OP_RELEXP,

			/*inclusive_or_expression, exclusive_or_expression, and_expression*/

			//logical_and_expression
			T_CLOGANDEXP_EQUALEXP,
			T_CLOGANDEXP_LOGANDEXP_AND_OP_EQUALEXP,

			//logical_or_expression
			T_CLOGOREXP_LOGANDEXP,
			T_CLOGOREXP_LOGOREXP_OR_OP_LOGANDEXP,

			//constant_expression
			T_CCONSTEXP_CONDITIONALEXP,

			//conditional_expression
			T_CCONDITIONALEXP_LOGOREXP,

			//assignment_operator
			T_CTERMINATE_CASSIGN_OP_ASSIGN,
			T_CTERMINATE_CASSIGN_OP_MUL_ASSIGN,
			T_CTERMINATE_CASSIGN_OP_DIV_ASSIGN,
			T_CTERMINATE_CASSIGN_OP_MOD_ASSIGN,
			T_CTERMINATE_CASSIGN_OP_ADD_ASSIGN,
			T_CTERMINATE_CASSIGN_OP_SUB_ASSIGN,
			T_CTERMINATE_CASSIGN_OP_LEFT_ASSIGN,
			T_CTERMINATE_CASSIGN_OP_RIGHT_ASSIGN,
			T_CTERMINATE_CASSIGN_OP_AND_ASSIGN,
			T_CTERMINATE_CASSIGN_OP_XOR_ASSIGN,
			T_CTERMINATE_CASSIGN_OP_OR_ASSIGN,

			//assignment_expression
			T_CASSIGNEXP_CONDITIONALEXP,
			T_CASSIGNEXP_UNARYEXP_ASSIGN_OP_ASSIGNEXP,
			T_CASSIGNEXP_NEW_ID_VOID, T_CTERMINATE_CASSIGNEXP_NEW_ID_VOID,
			T_CASSIGNEXP_DELETE_ID, T_CTERMINATE_CASSIGNEXP_DELETE_ID,

			//expression
			T_CEXP_ASSIGNEXP,
			T_CEXP_EXP_ASSIGNEXP,

			//jump_statement
			T_CJUMPSTM_GOTO_ID, T_CTERMINATE_CJUMPSTM_GOTO_ID,
			T_CJUMPSTM_CONTINUE,
			T_CJUMPSTM_BREAK,
			T_CJUMPSTM_RETURN,
			T_CJUMPSTM_RETURN_EXP,

			//iteration_statement
			T_CITRSTM_WHILE_EXP_STM,
			T_CITRSTM_DO_STM_WHILE_EXP,
			T_CITRSTM_FOR_EXPSTM_EXPSTM_EXP_STM,

			//selection_statement
			T_CSELSTM_IF_EXP_STM,
			T_CSELSTM_IF_EXP_STM_ELSE_STM,
			T_CSELSTM_SWITCH_EXP_STM,

			//statement_list
			T_CSTMLIST_STM,
			T_CSTMLIST_STMLIST_STM,

			//compound_statement
			T_CCOMPSTM_VOID,
			T_CCOMPSTM_STMLIST,
			T_CCOMPSTM_DECTION_LIST,
			T_CCOMPSTM_DECTIONLIST_STMLIST,

			//expression_statement
			T_CEXPSTM_VOID,
			T_CEXPSTM_EXP,

			//labeled_statement
			T_CLABSTM_ID_STM,
			T_CTERMINATE_CLABSTM_ID_STM,
			T_CLABSTM_CASE_CONSTEXP_STM,
			T_CLABSTM_DEFAULT_STM,

			//statement
			T_CSTM_LABSTM,
			T_CSTM_COMPSTM,
			T_CSTM_EXPSTM,
			T_CSTM_SELSTM,
			T_CSTM_ITRSTM,
			T_CSTM_JUMPSTM,

			//direct_abstract_declarator
			T_CDIRABSDECTOR_ABSDECTOR,
			T_CDIRABSDECTOR_ARRAY_VOID,
			T_CDIRABSDECTOR_ARRAY_CONSTEXP,
			T_CDIRABSDECTOR_DIRABSDECTOR_ARRAY_VOID,
			T_CDIRABSDECTOR_DIRABSDECTOR_ARRAY_CONSTEXP,
			T_CDIRABSDECTOR_CALL_VOID,
			T_CDIRABSDECTOR_CALL_PARAMTYPELIST,
			T_CDIRABSDECTOR_DIRABSDECTOR_CALL_VOID,
			T_CDIRABSDECTOR_DIRABSDECTOR_CALL_PARAMTYPELIST,

			//abstract_declarator
			T_CABSDECTOR_POINTER,
			T_CABSDECTOR_DIRABSDECTOR,
			T_CABSDECTOR_POINTER_DIRABSDECTOR,

			//type_name
			T_CTYPENAME_SQFLIST,
			T_CTYPENAME_SQFLIST_ABSDECTOR,

			//initializer_list
			T_CINITZERLIST_INITZER,
			T_CINITZERLIST_INITZERLIST_INITZER,

			//initializer
			T_CINITZER_ASSIGNEXP,
			T_CINITZER_CINITZERLIST,

			//identifier_list
			T_CTERMINATE_CIDLIST_ID,
			T_CIDLIST_IDLIST_ID, T_CTERMINATE_CIDLIST_IDLIST_ID,

			//parameter_declaration
			T_CPARAMDECTION_DECTIONSFS_DECTOR,
			T_CPARAMDECTION_DECTIONSFS_ABSDECTOR,
			T_CPARAMDECTION_DECTIONSFS,

			//parameter_list
			T_CPARAMLIST_PARAMDECTION,
			T_CPARAMLIST_PARAMLIST_PARAMDECTION,

			//parameter_type_list
			T_CPARAMTYPELIST_PARAMLIST,
			T_CPARAMTYPELIST_PARAMLIST_ELLIPSIS,

			//type_qualifier_list
			T_CTYPEQFLIST_TYPEQF,
			T_CTYPEQFLIST_TYPEQFLIST_TYPEQF,

			//pointer
			T_CPOINTER_REF_OP,
			T_CPOINTER_REF_OP_TYPEQFLIST,
			T_CPOINTER_REF_OP_POINTER,
			T_CPOINTER_REF_OP_TYPEQFLIST_POINTER,

			//direct_declarator
			T_CDIRDECTOR_ID, T_CTERMINATE_CDIRDECTOR_ID,
			T_CDIRDECTOR_DECTOR,
			T_CDIRDECTOR_DIRDECTOR_ARRAY_CONSTEXP,
			T_CDIRDECTOR_DIRDECTOR_ARRAY_VOID,
			T_CDIRDECTOR_DIRDECTOR_CALL_PARAMTYPELIST,
			T_CDIRDECTOR_DIRDECTOR_CALL_EXP,
			T_CDIRDECTOR_DIRDECTOR_CALL_VOID,

			//declarator
			T_CDECTOR_POINTER_DIRDECTOR,
			T_CDECTOR_DIRDECTOR,

			/*enum_specifier, enumerator_list, enumerator*/

			//class_declarator
			T_CCLASSDECTOR_DECTOR,

			//class_declarator_list
			T_CCLASSDECTORLIST_CLASSDECTOR,
			T_CCLASSDECTORLIST_CLASSDECTORLIST_CLASSDECTOR,

			//class_declaration
			T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST,
			T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST_COMPSTM,
			T_CCLASSDECTION_CLASSDECTORLIST_COMPSTM,

			//class_declaration_list
			T_CCLASSDECTIONLIST_CLASSDECTION,
			T_CCLASSDECTIONLIST_CLASSDECTIONLIST_CLASSDECTION,

			//class_specifier
			T_CCLASSSF_CLASS_ID_CLASSDECTIONLIST, T_CTERMINATE_CCLASSSF_CLASS_ID_CLASSDECTIONLIST,
			T_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST, T_CTERMINATE_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST,
			T_CCLASSSF_CLASS_ID, T_CTERMINATE_CCLASSSF_CLASS_ID,

			/*struct_or_union_specifier, struct_or_union, struct_declaration_list, struct_declaration, struct_declarator_list, struct_declarator*/

			//specifier_qualifier_list
			T_CSQFLIST_TYPESF_SQFLIST,
			T_CSQFLIST_TYPESF,
			T_CSQFLIST_TYPEQF_SQFLIST,
			T_CSQFLIST_TYPEQF,

			//init_declarator
			T_CINITDECTOR_DECTOR,
			T_CINITDECTOR_ASSGIN_INITZER,

			//init_declarator_list
			T_CINITDECTORLIST_INITDECTOR,
			T_CINITDECTORLIST_INITDECTORLIST_INITDECTOR,

			//type_qualifier
			T_CTERMINATE_CTYPEQF_CONST,
			T_CTERMINATE_CTYPEQF_VOLATILE,
			T_CTERMINATE_CTYPEQF_VIRTUAL,

			//type_specifier
			T_CTERMINATE_CTYPESF_VOID,
			T_CTERMINATE_CTYPESF_CHAR,
			T_CTERMINATE_CTYPESF_SHORT,
			T_CTERMINATE_CTYPESF_INT,
			T_CTERMINATE_CTYPESF_LONG,
			T_CTERMINATE_CTYPESF_FLOAT,
			T_CTERMINATE_CTYPESF_DOUBLE,
			T_CTERMINATE_CTYPESF_SIGNED,
			T_CTERMINATE_CTYPESF_UNSIGNED,
			T_CTYPEQF_STRUCTORUNIONSF,
			T_CTYPEQF_CLASSSF,

			//storage_class_specifier
			T_CTERMINATE_CSTORCLASSSF_TYPEDEF,
			T_CTERMINATE_CSTORCLASSSF_EXTERN,
			T_CTERMINATE_CSTORCLASSSF_STATIC,
			T_CTERMINATE_CSTORCLASSSF_AUTO,
			T_CTERMINATE_CSTORCLASSSF_REGISITER,

			//declaration_specifiers
			T_CDECTIONSF_STORCLASSSF,
			T_CDECTIONSF_STORCLASSSF_DECTIONSFS,
			T_CDECTIONSF_TYPESF,
			T_CDECTIONSF_TYPESF_DECTIONSFS,
			T_CDECTIONSF_TYPEQF,
			T_CDECTIONSF_TYPEQF_DECTIONSFS,

			//declaration_list
			T_CDECTIONLIST_DECTION,
			T_CDECTIONLIST_DECTIONLIST_DECTION,

			//declaration
			T_CDECTION_DECTIONSFS,
			T_CDECTION_DECTIONSFS_INITDECTORLIST,

			//function_definition
			T_CFUNCDEF_DECTIONSFS_DECTOR_COMPSTM,

			//declaration
			T_CEXTDECTION_FUNCDEF,
			T_CEXTDECTION_DECTION,

			//translation_unit
			T_CTRANSUNIT_EXTDECTION,
			T_CTRANSUNIT_TRANSUNIT_EXTDECTION,

			//program_start
			T_CPROGRAMSTART_TRANSUNIT

			//OTHERS

		};

		int nodeId;
		int lineno;
		int childsNo;
		NodeAst *parent;
		vector<NodeAst *> childs;
		NodeType nodeType;
		string token;

		static const int s_nodeTypeNo;
		static const char *s_nodeTypeString[];
		static LogiMsg *s_logiMsg;
		static list<NodeAst *> s_nodeList;
		static NodeAst *s_root;

		static Context *s_context;

		static bool s_isInstalled;

	public:
		NodeAst(NodeAst::NodeType nodeType_t);
		NodeAst();
		virtual ~NodeAst();

		static void addToNodeList(NodeAst *node_t);
		static void freeNodeList();

		virtual void setNodeId();
		virtual int getNodeId();

		virtual void setLineno(int lineno_t);
		virtual int getLineno();

		virtual void setChildsNo(int childNo_t);
		virtual int getChildsNo();

		virtual void setNodeType(NodeAst::NodeType nodeType_t);
		virtual NodeAst::NodeType getNodeType();
		virtual void printNodetype();
		static void printNodeTree(NodeAst *root, int depth);

		virtual void setToken(const string token_t);
		virtual string getToken();
		virtual string getDotToken();

		virtual void setParent(NodeAst *parent_t);
		virtual NodeAst *getParent();

		virtual int addChild1(NodeAst *child1_t);
		virtual int addChild2(NodeAst *child1_t, NodeAst *child2_t);
		virtual int addChild3(NodeAst *child1_t, NodeAst *child2_t, NodeAst *child3_t);
		virtual int addChild4(NodeAst *child1_t, NodeAst *child2_t, NodeAst *child3_t, NodeAst *child4_t);
		virtual int addChild5(NodeAst *child1_t, NodeAst *child2_t, NodeAst *child3_t, NodeAst *child4_t, NodeAst *child5_t);

		static void setNodeTreeRoot(NodeAst *root_t);
		static NodeAst *getNodeTreeRoot();

		static LogiMsg *getSingletonLogiMsg();

		static Context *getSingletonContext();
		static void setContext(Context *context_t);

		static void dotBfsNodeTree(NodeAst *root_t);

		virtual void stopWalk();
		static bool checkIsNotWalking();

		virtual void walk();

		virtual Reg* processChildOperand(int side_t);

		virtual void* processUnaryChildOperand();

		virtual bool checkNodeTypeReturnValueIsBool(NodeAst::NodeType nodeType_t);


};



#endif
