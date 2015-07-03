#include "../../include/ast/EqualExpAst.h"

EqualExpAst::EqualExpAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void EqualExpAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType) {
    case T_CEQUALEXP_EQUALEXP_EQ_OP_RELEXP: {
        LogiMsg::logi("walk in T_CEQUALEXP_EQUALEXP_EQ_OP_RELEXP", getLineno());

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r1 = processChildOperand(1);
        if (NULL == r1) {
            LogiMsg::logi("error in T_CEQUALEXP_EQUALEXP_EQ_OP_RELEXP: left operand is invalid", getLineno());
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
            LogiMsg::logi("error in T_CEQUALEXP_EQUALEXP_EQ_OP_RELEXP: right operand is invalid", getLineno());
            stopWalk();
            return ;
        }

        ItmCode::genCodePopReg(r1);

        //Reg *r3 = Reg::getReg(0, TypeClass::promoteType(r1->getTypeSfType(), r2->getTypeSfType()));
        Reg *r3 = Reg::getReg(0, TypeClass::SF_INT);

        s_context->tmpExpReg = r3;
        s_context->tmpOpType = ItmCode::OPR_REGISTER;

        ItmCode::genCodeRegBinOpRegToReg(ItmCode::IR_EQ_OP, r1, r2, r3);


        break;
    }

    case T_CEQUALEXP_EQUALEXP_NE_OP_RELEXP: {
        LogiMsg::logi("walk in T_CEQUALEXP_EQUALEXP_NE_OP_RELEXP");

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r1 = processChildOperand(1);
        if (NULL == r1) {
            LogiMsg::logi("error in T_CEQUALEXP_EQUALEXP_NE_OP_RELEXP: left operand is invalid", getLineno());
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
            LogiMsg::logi("error in T_CEQUALEXP_EQUALEXP_NE_OP_RELEXP: right operand is invalid", getLineno());
            stopWalk();
            return ;
        }

        ItmCode::genCodePopReg(r1);

        //Reg *r3 = Reg::getReg(0, TypeClass::promoteType(r1->getTypeSfType(), r2->getTypeSfType()));
        Reg *r3 = Reg::getReg(0, TypeClass::SF_INT);

        s_context->tmpExpReg = r3;
        s_context->tmpOpType = ItmCode::OPR_REGISTER;

        ItmCode::genCodeRegBinOpRegToReg(ItmCode::IR_NE_OP, r1, r2, r3);

        break;
    }

    default: {
        LogiMsg::logi("error in EqualExpAst: nodeType is invalid", getLineno());
        stopWalk();
        return ;
        break;
    }
    }
}
