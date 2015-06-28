#include "../../include/ast/ExpStmAst.h"

ExpStmAst::ExpStmAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ExpStmAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType) {
    case T_CEXPSTM_VOID: {
        LogiMsg::logi("walk in T_CEXPSTM_VOID", getLineno());

        s_context->clearAllContext();
        break;
    }

    case T_CEXPSTM_EXP: {
        LogiMsg::logi("walk in T_CEXPSTM_EXP", getLineno());

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        s_context->clearAllContext();

        break;
    }

    default: {
        LogiMsg::logi("error in ExpStmAst: nodeType is invalid", getLineno());
        stopWalk();
        return ;
        break;
    }
    }
}

