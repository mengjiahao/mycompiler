#include "../../include/ast/JumpStmAst.h"

JumpStmAst::JumpStmAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void JumpStmAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType) {
    case T_CJUMPSTM_RETURN: {

        ItmCode::genCodeReturnVoid();

        break;
    }

    case T_CJUMPSTM_RETURN_EXP: {
        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r = processChildOperand(0);
        if (NULL == r) {
            LogiMsg::logi("error in T_CJUMPSTM_RETURN_EXP: return value is invalid", getLineno());
            stopWalk();
            return ;
        }

        ItmCode::genCodeReturnReg(r);

        break;
    }

    default: {
        LogiMsg::logi("error in JumpStmAst: nodeType is invalid", getLineno());
        stopWalk();
        return ;
        break;
    }
    }
}

