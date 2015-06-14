
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


TerminateAst::~TerminateAst()
{

}




