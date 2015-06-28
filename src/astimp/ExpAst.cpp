#include "../../include/ast/ExpAst.h"

ExpAst::ExpAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ExpAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType) {
    case T_CEXP_EXP_ASSIGNEXP: {
        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        childs.at(1)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r2 = processChildOperand(0);
        if (NULL == r2) {
            LogiMsg::logi("error in T_CEXP_EXP_ASSIGNEXP: right operand is invalid", getLineno());
            stopWalk();
            return ;
        }


        break;
    }

    default: {
        LogiMsg::logi("error in ExpAst: nodeType is invalid", getLineno());
        stopWalk();
        return ;
        break;
    }
    }
}
