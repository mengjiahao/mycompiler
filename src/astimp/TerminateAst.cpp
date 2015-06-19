
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

Info *TerminateAst::walk()
{
    if (token=="typedef")
        return NULL;    //typedef is not support
    else if (token=="extern")
    {
        TypeInfo *tmp=new TypeInfo();
        tmp->clearTypeClass();
        tmp->setStorageType(TypeClass::STOR_EXTERN);
        infoCarry=tmp;
        return tmp;
    }
    else if (token=="static")
    {
        TypeInfo *tmp=new TypeInfo();
        tmp->clearTypeClass();
        tmp->setStorageType(TypeClass::STOR_STATIC);
        infoCarry=tmp;
        return tmp;
    }
    else if (token=="auto")
    {
        TypeInfo *tmp=new TypeInfo();
        tmp->clearTypeClass();
        tmp->setStorageType(TypeClass::STOR_AUTO);
        infoCarry=tmp;
        return tmp;
    }
    else if (token=="register")
    {
        TypeInfo *tmp=new TypeInfo();
        tmp->clearTypeClass();
        tmp->setStorageType(TypeClass::STOR_REGISTER);
        infoCarry=tmp;
        return tmp;
    }
    else if (token=="void")
    {
        TypeInfo *tmp=new TypeInfo();
        tmp->clearTypeClass();
        tmp->setTypeSfType(TypeClass::SF_VOID);
        infoCarry=tmp;
        return tmp;
    }
    else if (token=="char")
    {
        TypeInfo *tmp=new TypeInfo();
        tmp->clearTypeClass();
        tmp->setTypeSfType(TypeClass::SF_CHAR);
        infoCarry=tmp;
        return tmp;
    }
    else if (token=="short")
    {
        TypeInfo *tmp=new TypeInfo();
        tmp->clearTypeClass();
        tmp->setTypeSfType(TypeClass::SF_SHORT);
        infoCarry=tmp;
        return tmp;
    }
    else if (token=="int")
    {
        TypeInfo *tmp=new TypeInfo();
        tmp->clearTypeClass();
        tmp->setTypeSfType(TypeClass::SF_INT);
        infoCarry=tmp;
        return tmp;
    }
    else if (token=="long")
    {
        TypeInfo *tmp=new TypeInfo();
        tmp->clearTypeClass();
        tmp->setTypeSfType(TypeClass::SF_LONG);
        infoCarry=tmp;
        return tmp;
    }
    else if (token=="float")
    {
        TypeInfo *tmp=new TypeInfo();
        tmp->clearTypeClass();
        tmp->setTypeSfType(TypeClass::SF_FLOAT);
        infoCarry=tmp;
        return tmp;
    }
    else if (token=="double")
    {
        TypeInfo *tmp=new TypeInfo();
        tmp->clearTypeClass();
        tmp->setTypeSfType(TypeClass::SF_DOUBLE);
        infoCarry=tmp;
        return tmp;
    }
    else if (token=="signed")
    {
        TypeInfo *tmp=new TypeInfo();
        tmp->clearTypeClass();
        tmp->setTypeSfType(TypeClass::SF_SIGNED);
        infoCarry=tmp;
        return tmp;
    }
    else if (token=="unsigned")
    {
        TypeInfo *tmp=new TypeInfo();
        tmp->clearTypeClass();
        tmp->setTypeSfType(TypeClass::SF_UNSIGNED);
        infoCarry=tmp;
        return tmp;
    }
    else if (token=="const")
    {
        TypeInfo *tmp=new TypeInfo();
        tmp->clearTypeClass();
        tmp->setTypeQfType(TypeClass::QF_CONST);
        infoCarry=tmp;
        return tmp;
    }
    else if (token=="volatile")
    {
        TypeInfo *tmp=new TypeInfo();
        tmp->clearTypeClass();
        tmp->setTypeQfType(TypeClass::QF_VOLATILE);
        infoCarry=tmp;
        return tmp;
    }
    else if (token=="virtual")
    {
        TypeInfo *tmp=new TypeInfo();
        tmp->clearTypeClass();
        tmp->setTypeQfType(TypeClass::QF_VIRTUAL);
        infoCarry=tmp;
        return tmp;
    }
    return NULL:

}

TerminateAst::~TerminateAst()
{

}




