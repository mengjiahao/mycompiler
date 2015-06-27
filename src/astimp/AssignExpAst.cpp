#include "../../include/ast/AssignExpAst.h"

AssignExpAst::AssignExpAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void AssignExpAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType) {

    default: {

        break;
    }
    }


}
