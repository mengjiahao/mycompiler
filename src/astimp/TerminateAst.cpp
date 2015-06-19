
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
    if ((token=="typedef") || (token=="extern") || (token=="static") || (token=="auto") ||(token=="register"))


}

TerminateAst::~TerminateAst()
{

}




