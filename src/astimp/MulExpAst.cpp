
#include "../../include/ast/MulExpAst.h"

MulExpAst::MulExpAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void MulExpAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType) {
    case T_CMULEXP_MULEXP_MUL_OP_CASTEXP: {
        LogiMsg::logi("walk in T_CMULEXP_MULEXP_MUL_OP_CASTEXP", getLineno());

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r1 = processChildOperand(1);
        if (NULL == r1) {
            LogiMsg::logi("error in T_CMULEXP_MULEXP_MUL_OP_CASTEXP: left operand is invalid", getLineno());
            stopWalk();
            return ;
        }

        childs.at(1)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r2 = processChildOperand(0);
        if (NULL == r2) {
            LogiMsg::logi("error in T_CMULEXP_MULEXP_MUL_OP_CASTEXP: right operand is invalid", getLineno());
            stopWalk();
            return ;
        }

        Reg *r3 = Reg::getReg(0, TypeClass::promoteType(r1->getTypeSfType(), r2->getTypeSfType()));

        s_context->tmpExpReg = r3;
        s_context->tmpOpType = ItmCode::OPR_REGISTER;

        ItmCode::genCodeRegBinOpRegToReg(ItmCode::IR_MUL_OP, r1, r2, r3);


        break;
    }

    case T_CMULEXP_MULEXP_DIV_OP_CASTEXP: {
        LogiMsg::logi("walk in T_CMULEXP_MULEXP_DIV_OP_CASTEXP", getLineno());

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r1 = processChildOperand(1);
        if (NULL == r1) {
            LogiMsg::logi("error in T_CMULEXP_MULEXP_DIV_OP_CASTEXP: left operand is invalid", getLineno());
            stopWalk();
            return ;
        }

        childs.at(1)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r2 = processChildOperand(0);
        if (NULL == r2) {
            LogiMsg::logi("error in T_CMULEXP_MULEXP_DIV_OP_CASTEXP: right operand is invalid", getLineno());
            stopWalk();
            return ;
        }

        Reg *r3 = Reg::getReg(0, TypeClass::promoteType(r1->getTypeSfType(), r2->getTypeSfType()));

        s_context->tmpExpReg = r3;
        s_context->tmpOpType = ItmCode::OPR_REGISTER;

        ItmCode::genCodeRegBinOpRegToReg(ItmCode::IR_DIV_OP, r1, r2, r3);

        break;
    }

    default: {
        LogiMsg::logi("error in MulExpAst: nodeType is invalid", getLineno());
        stopWalk();
        return ;
        break;
    }
    }


}




