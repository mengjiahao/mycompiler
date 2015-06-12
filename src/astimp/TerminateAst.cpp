
#include "../../include/ast/TerminateAst.h"

using namespace std;

TerminateAst::TerminateAst(NodeAst::NodeType nodeType_t, char *token_t) : NodeAst(nodeType_t) {

    if (NULL == token_t) {
        logiMsg->attachLogiMsg("error: in Terminate, NULL == token_t\n");
    }
    setToken(token_t);


}





