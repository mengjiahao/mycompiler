
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
        break;
    }
    case T_CTERMINATE_CIDLIST_IDLIST_ID: {
        break;
    }

    //direct_declarator
    case T_CTERMINATE_CDIRDECTOR_ID: {
        break;
    }

    //class_specifier
    case T_CTERMINATE_CCLASSSF_CLASS_ID_CLASSDECTIONLIST: {
        break;
    }
    case T_CTERMINATE_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST: {
        break;
    }

    //type_qualifier
    case T_CTERMINATE_CTYPEQF_CONST: {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeQfType(TypeClass::QF_CONST);
        break;
    }
    case T_CTERMINATE_CTYPEQF_VOLATILE: {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeQfType(TypeClass::QF_VOLATILE);
        break;
    }
    case T_CTERMINATE_CTYPEQF_VIRTUAL: {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeQfType(TypeClass::QF_VIRTUAL);
        break;
    }

    //type_specifier
    case T_CTERMINATE_CTYPESF_VOID: {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_VOID);
        break;
    }
    case T_CTERMINATE_CTYPESF_CHAR: {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_CHAR);
        break;
    }
    case T_CTERMINATE_CTYPESF_SHORT: {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_SHORT);
        break;
    }
    case T_CTERMINATE_CTYPESF_INT: {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_INT);
        break;
    }
    case T_CTERMINATE_CTYPESF_LONG: {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_LONG);
        break;
    }
    case T_CTERMINATE_CTYPESF_FLOAT: {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_FLOAT);
        break;
    }
    case T_CTERMINATE_CTYPESF_DOUBLE: {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_DOUBLE);
        break;
    }
    case T_CTERMINATE_CTYPESF_SIGNED: {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_SIGNED);
        break;
    }
    case T_CTERMINATE_CTYPESF_UNSIGNED: {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_UNSIGNED);
        break;
    }

    //storage_class_specifier
    case T_CTERMINATE_CSTORCLASSSF_TYPEDEF: {
        break;
    }
    case T_CTERMINATE_CSTORCLASSSF_EXTERN: {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setStorageType(TypeClass::STOR_EXTERN);
        break;
    }
    case T_CTERMINATE_CSTORCLASSSF_STATIC: {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setStorageType(TypeClass::STOR_STATIC);
        break;
    }
    case T_CTERMINATE_CSTORCLASSSF_AUTO: {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setStorageType(TypeClass::STOR_AUTO);
        break;
    }
    case T_CTERMINATE_CSTORCLASSSF_REGISITER: {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setStorageType(TypeClass::STOR_REGISTER);
        break;
    }

    default: {
        break;
    }

    }

/***************************************************
    if (token == "typedef")
        return ;    //typedef is not support
    else if (token == "extern")
    {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setStorageType(TypeClass::STOR_EXTERN);
    }
    else if (token == "static")
    {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setStorageType(TypeClass::STOR_STATIC);
    }
    else if (token=="auto")
    {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setStorageType(TypeClass::STOR_AUTO);
    }
    else if (token=="register")
    {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setStorageType(TypeClass::STOR_REGISTER);
    }
    else if (token=="void")
    {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_VOID);
    }
    else if (token=="char")
    {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_CHAR);
    }
    else if (token=="short")
    {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_SHORT);
    }
    else if (token=="int")
    {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_INT);
    }
    else if (token=="long")
    {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_LONG);
    }
    else if (token=="float")
    {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_FLOAT);
    }
    else if (token=="double")
    {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_DOUBLE);
    }
    else if (token=="signed")
    {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_SIGNED);
    }
    else if (token=="unsigned")
    {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_UNSIGNED);
    }
    else if (token=="const")
    {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeQfType(TypeClass::QF_CONST);
    }
    else if (token=="volatile")
    {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeQfType(TypeClass::QF_VOLATILE);
    }
    else if (token=="virtual")
    {
        s_context->tmpDeclType.clearTypeClass();
        s_context->tmpDeclType.setTypeQfType(TypeClass::QF_VIRTUAL);

    }
**************************************************************/


}




