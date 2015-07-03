#include "../../include/ast/AddExpAst.h"

AddExpAst::AddExpAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void AddExpAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType) {
    case T_CADDEXP_ADDEXP_ADD_OP_MULEXP: {
        LogiMsg::logi("walk in T_CADDEXP_ADDEXP_ADD_OP_MULEXP", getLineno());

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r1 = processChildOperand(1);
        if (NULL == r1) {
            LogiMsg::logi("error in T_CADDEXP_ADDEXP_ADD_OP_MULEXP: left operand is invalid", getLineno());
            stopWalk();
            return ;
        }

        ItmCode::genCodePushReg(r1);

        childs.at(1)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r2 = processChildOperand(0);
        if (NULL == r2) {
            LogiMsg::logi("error in T_CADDEXP_ADDEXP_ADD_OP_MULEXP: right operand is invalid", getLineno());
            stopWalk();
            return ;
        }

        ItmCode::genCodePopReg(r1);

        Reg *r3 = Reg::getReg(0, TypeClass::promoteType(r1->getTypeSfType(), r2->getTypeSfType()));

        s_context->tmpExpReg = r3;
        s_context->tmpOpType = ItmCode::OPR_REGISTER;

        ItmCode::genCodeRegBinOpRegToReg(ItmCode::IR_ADD_OP, r1, r2, r3);


        break;
    }

    case T_CADDEXP_ADDEXP_SUB_OP_MULEXP: {
        LogiMsg::logi("walk in T_CADDEXP_ADDEXP_SUB_OP_MULEXP", getLineno());

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r1 = processChildOperand(1);
        if (NULL == r1) {
            LogiMsg::logi("error in T_CADDEXP_ADDEXP_SUB_OP_MULEXP: left operand is invalid", getLineno());
            stopWalk();
            return ;
        }

        ItmCode::genCodePushReg(r1);

        childs.at(1)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r2 = processChildOperand(0);
        if (NULL == r2) {
            LogiMsg::logi("error in T_CADDEXP_ADDEXP_SUB_OP_MULEXP: right operand is invalid", getLineno());
            stopWalk();
            return ;
        }

        ItmCode::genCodePopReg(r1);

        Reg *r3 = Reg::getReg(0, TypeClass::promoteType(r1->getTypeSfType(), r2->getTypeSfType()));

        s_context->tmpExpReg = r3;
        s_context->tmpOpType = ItmCode::OPR_REGISTER;

        ItmCode::genCodeRegBinOpRegToReg(ItmCode::IR_SUB_OP, r1, r2, r3);

        break;
    }

    default: {
        LogiMsg::logi("error in AddExpAst: nodeType is invalid", getLineno());
        stopWalk();
        return ;
        break;
    }
    }
}

