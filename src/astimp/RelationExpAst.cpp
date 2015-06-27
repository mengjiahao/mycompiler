#include "../../include/ast/RelationExpAst.h"

RelationExpAst::RelationExpAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void RelationExpAst::walk()
{
   if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType) {
    case T_CRELEXP_RELEXP_L_OP_ADDEXP: {
        LogiMsg::logi("walk in T_CRELEXP_RELEXP_L_OP_ADDEXP");

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r1 = processChildOperand(1);
        if (NULL == r1) {
            LogiMsg::logi("error in T_CRELEXP_RELEXP_L_OP_ADDEXP: left operand is invalid");
            stopWalk();
            return ;
        }

        childs.at(1)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r2 = processChildOperand(0);
        if (NULL == r2) {
            LogiMsg::logi("error in T_CRELEXP_RELEXP_L_OP_ADDEXP: right operand is invalid");
            stopWalk();
            return ;
        }

        Reg *r3 = Reg::getReg(0, TypeClass::promoteType(r1->getTypeSfType(), r2->getTypeSfType()));

        ItmCode::genCodeRegBinOpRegToReg(ItmCode::IR_L_OP, r1, r2, r3);


        break;
    }

    case T_CRELEXP_RELEXP_G_OP_ADDEXP: {
        LogiMsg::logi("walk in T_CRELEXP_RELEXP_G_OP_ADDEXP");

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r1 = processChildOperand(1);
        if (NULL == r1) {
            LogiMsg::logi("error in T_CRELEXP_RELEXP_G_OP_ADDEXP: left operand is invalid");
            stopWalk();
            return ;
        }

        childs.at(1)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r2 = processChildOperand(0);
        if (NULL == r2) {
            LogiMsg::logi("error in T_CRELEXP_RELEXP_G_OP_ADDEXP: right operand is invalid");
            stopWalk();
            return ;
        }

        Reg *r3 = Reg::getReg(0, TypeClass::promoteType(r1->getTypeSfType(), r2->getTypeSfType()));

        ItmCode::genCodeRegBinOpRegToReg(ItmCode::IR_G_OP, r1, r2, r3);

        break;
    }

    case T_CRELEXP_RELEXP_LE_OP_ADDEXP: {
        LogiMsg::logi("walk in T_CRELEXP_RELEXP_LE_OP_ADDEXP");

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r1 = processChildOperand(1);
        if (NULL == r1) {
            LogiMsg::logi("error in T_CRELEXP_RELEXP_LE_OP_ADDEXP: left operand is invalid");
            stopWalk();
            return ;
        }

        childs.at(1)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r2 = processChildOperand(0);
        if (NULL == r2) {
            LogiMsg::logi("error in T_CRELEXP_RELEXP_LE_OP_ADDEXP: right operand is invalid");
            stopWalk();
            return ;
        }

        Reg *r3 = Reg::getReg(0, TypeClass::promoteType(r1->getTypeSfType(), r2->getTypeSfType()));

        ItmCode::genCodeRegBinOpRegToReg(ItmCode::IR_LE_OP, r1, r2, r3);

        break;
    }

    case T_CRELEXP_RELEXP_GE_OP_ADDEXP: {
        LogiMsg::logi("walk in T_CRELEXP_RELEXP_GE_OP_ADDEXP");

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r1 = processChildOperand(1);
        if (NULL == r1) {
            LogiMsg::logi("error in T_CRELEXP_RELEXP_GE_OP_ADDEXP: left operand is invalid");
            stopWalk();
            return ;
        }

        childs.at(1)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r2 = processChildOperand(0);
        if (NULL == r2) {
            LogiMsg::logi("error in T_CRELEXP_RELEXP_GE_OP_ADDEXP: right operand is invalid");
            stopWalk();
            return ;
        }

        Reg *r3 = Reg::getReg(0, TypeClass::promoteType(r1->getTypeSfType(), r2->getTypeSfType()));

        ItmCode::genCodeRegBinOpRegToReg(ItmCode::IR_GE_OP, r1, r2, r3);

        break;
    }

    default: {
        LogiMsg::logi("error in RelationExpAst: nodeType is invalid");
        stopWalk();
        return ;
        break;
    }
    }
}
