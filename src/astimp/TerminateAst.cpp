
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

}




