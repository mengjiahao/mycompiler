
#include "../../include/ast/TerminateAst.h"

using namespace std;

TerminateAst::TerminateAst(NodeAst::NodeType nodeType_t, string *token_t) : NodeAst(nodeType_t)
{
    token = *token_t;
    delete token_t;
}


TerminateAst::TerminateAst(NodeAst::NodeType nodeType_t, const char* token_t) : NodeAst(nodeType_t)
{
    token = string(token_t);
}

TerminateAst::TerminateAst(NodeAst::NodeType nodeType_t, const string& token_t) : NodeAst(nodeType_t)
{
    token = token_t;
}


string TerminateAst::getDotToken()
{
    return token + " : " + s_nodeTypeString[nodeType];
}

TerminateAst::~TerminateAst()
{

}

void TerminateAst::walk()
{
    cout << "TerminateAstWalk" << endl;

    switch(nodeType) {
    //const_value
    case T_CTERMINATE_CCONSTVAR_INT_CONST: {
        break;
    }
    case T_CTERMINATE_CCONSTVAR_CHAR_CONST: {
        break;
    }
    case T_CTERMINATE_CCONSTVAR_FLOAT_CONST: {
        break;
    }

    //primary_expression
    case T_CTERMINATE_CPRIMEXP_ID: {
        break;
    }
    case T_CTERMINATE_CPRIMEXP_STR: {
        break;
    }

    //postfix_expression
    case T_CTERMINATE_CPOSTEXP_POSTEXP_REF_ID: {
        break;
    }
    case T_CTERMINATE_CPOSTEXP_POSTEXP_PTR_ID: {
        break;
    }

    //unary_operator
    case T_CTERMINATE_CUNARY_OP_AND_OP: {
        break;
    }
	case T_CTERMINATE_CUNARY_OP_REF_OP: {
        break;
    }
	case T_CTERMINATE_CUNARY_OP_ADD_OP: {
        break;
    }
	case T_CTERMINATE_CUNARY_OP_SUB_OP: {
        break;
    }
	case T_CTERMINATE_CUNARY_OP_COMP_OP: {
        break;
    }
	case T_CTERMINATE_CUNARY_OP_NOT_OP: {
        break;
    }

    //assignment_operator
	case T_CTERMINATE_CASSIGN_OP_ASSIGN: {
        break;
    }
    case T_CTERMINATE_CASSIGN_OP_MUL_ASSIGN: {
        break;
    }
    case T_CTERMINATE_CASSIGN_OP_DIV_ASSIGN: {
        break;
    }
    case T_CTERMINATE_CASSIGN_OP_MOD_ASSIGN: {
        break;
    }
    case T_CTERMINATE_CASSIGN_OP_ADD_ASSIGN: {
        break;
    }
    case T_CTERMINATE_CASSIGN_OP_SUB_ASSIGN: {
        break;
    }
    case T_CTERMINATE_CASSIGN_OP_LEFT_ASSIGN: {
        break;
    }
    case T_CTERMINATE_CASSIGN_OP_RIGHT_ASSIGN: {
        break;
    }
    case T_CTERMINATE_CASSIGN_OP_AND_ASSIGN: {
        break;
    }
    case T_CTERMINATE_CASSIGN_OP_XOR_ASSIGN: {
        break;
    }
    case T_CTERMINATE_CASSIGN_OP_OR_ASSIGN: {
        break;
    }

    //assignment_expression
    case T_CTERMINATE_CASSIGNEXP_NEW_ID_VOID: {
        break;
    }
    case T_CTERMINATE_CASSIGNEXP_DELETE_ID: {
        break;
    }

    //jump_statement
    case T_CTERMINATE_CJUMPSTM_GOTO_ID: {
        break;
    }

    //labeled_statement
    case T_CTERMINATE_CLABSTM_ID_STM: {
        break;
    }

    //identifier_list
    case T_CTERMINATE_CIDLIST_ID: {
        s_context->clearContext();
        s_context->tmpIdenName=token;
        break;
    }
    case T_CTERMINATE_CIDLIST_IDLIST_ID: {
        break;
    }

    //direct_declarator
    case T_CTERMINATE_CDIRDECTOR_ID: {
        s_context->clearContext();
        s_context->tmpIdenName=token;
        break;
    }

    //class_specifier
    case T_CTERMINATE_CCLASSSF_CLASS_ID_CLASSDECTIONLIST: {
        s_context->clearContext();
        s_context->tmpIdenName=token;
        break;
    }
    case T_CTERMINATE_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST: {
        s_context->clearContext();
        s_context->tmpIdenName=token;
        break;
    }
    case T_CTERMINATE_CCLASSSF_CLASS_ID:{
        s_context->clearContext();
        s_context->tmpIdenName=token;
        break;
    }

    //type_qualifier
    case T_CTERMINATE_CTYPEQF_CONST: {
        s_context->clearContext();
        s_context->tmpDeclType.setTypeQfType(TypeClass::QF_CONST);
        break;
    }
    case T_CTERMINATE_CTYPEQF_VOLATILE: {
        s_context->clearContext();
        s_context->tmpDeclType.setTypeQfType(TypeClass::QF_VOLATILE);
        break;
    }
    case T_CTERMINATE_CTYPEQF_VIRTUAL: {
        s_context->clearContext();
        s_context->tmpDeclType.setTypeQfType(TypeClass::QF_VIRTUAL);
        break;
    }

    //type_specifier
    case T_CTERMINATE_CTYPESF_VOID: {
        s_context->clearContext();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_VOID);
        break;
    }
    case T_CTERMINATE_CTYPESF_CHAR: {
        s_context->clearContext();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_CHAR);
        break;
    }
    case T_CTERMINATE_CTYPESF_SHORT: {
        s_context->clearContext();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_SHORT);
        break;
    }
    case T_CTERMINATE_CTYPESF_INT: {
        s_context->clearContext();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_INT);
        break;
    }
    case T_CTERMINATE_CTYPESF_LONG: {
        s_context->clearContext();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_LONG);
        break;
    }
    case T_CTERMINATE_CTYPESF_FLOAT: {
        s_context->clearContext();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_FLOAT);
        break;
    }
    case T_CTERMINATE_CTYPESF_DOUBLE: {
        s_context->clearContext();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_DOUBLE);
        break;
    }
    case T_CTERMINATE_CTYPESF_SIGNED: {
        s_context->clearContext();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_SIGNED);
        break;
    }
    case T_CTERMINATE_CTYPESF_UNSIGNED: {
        s_context->clearContext();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_UNSIGNED);
        break;
    }

    //storage_class_specifier
    case T_CTERMINATE_CSTORCLASSSF_TYPEDEF: {
        break;
    }
    case T_CTERMINATE_CSTORCLASSSF_EXTERN: {
        s_context->clearContext();
        s_context->tmpDeclType.setStorageType(TypeClass::STOR_EXTERN);
        break;
    }
    case T_CTERMINATE_CSTORCLASSSF_STATIC: {
        s_context->clearContext();
        s_context->tmpDeclType.setStorageType(TypeClass::STOR_STATIC);
        break;
    }
    case T_CTERMINATE_CSTORCLASSSF_AUTO: {
        s_context->clearContext();
        s_context->tmpDeclType.setStorageType(TypeClass::STOR_AUTO);
        break;
    }
    case T_CTERMINATE_CSTORCLASSSF_REGISITER: {
        s_context->clearContext();
        s_context->tmpDeclType.setStorageType(TypeClass::STOR_REGISTER);
        break;
    }

    default: {
        break;
    }

    }



}




