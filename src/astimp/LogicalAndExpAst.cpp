#include "../../include/ast/LogicalAndExpAst.h"

LogicalAndExpAst::LogicalAndExpAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void LogicalAndExpAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType) {
    case T_CLOGANDEXP_LOGANDEXP_AND_OP_EQUALEXP: {

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r1 = processChildOperand(1);
        if (NULL == r1) {
            LogiMsg::logi("error in T_CLOGANDEXP_LOGANDEXP_AND_OP_EQUALEXP: left operand is invalid", getLineno());
            stopWalk();
            return ;
        }

        ItmCode::genCodeRegIsTrueAssign(r1);

        Symbol *trueLabel = new Symbol(Symbol::SYMBOL_LABEL);
        Scope::s_curScope->defineSymbol(trueLabel);

        ItmCode::genCodeEmitLabel(trueLabel);
        s_context->backFillTrueLabelList(trueLabel);

        ItmCode *newCode = ItmCode::genCodeRegIfNotGotoLabel(r1, NULL);
        s_context->addToFalseLabelList(newCode);


        childs.at(1)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r2 = processChildOperand(0);
        if (NULL == r2) {
            LogiMsg::logi("error in T_CLOGANDEXP_LOGANDEXP_AND_OP_EQUALEXP: right operand is invalid", getLineno());
            stopWalk();
            return ;
        }
        ItmCode::genCodeRegIsTrueAssign(r2);

        Reg *r3 = Reg::getReg(0, TypeClass::promoteType(r1->getTypeSfType(), r2->getTypeSfType()));

        s_context->tmpExpReg = r3;
        s_context->tmpOpType = ItmCode::OPR_REGISTER;


        ItmCode::genCodeRegBinOpRegToReg(ItmCode::IR_LOG_AND_OP, r1, r2, r3);


        break;
    }

    default: {
        LogiMsg::logi("error in T_CLOGANDEXP_LOGANDEXP_AND_OP_EQUALEXP: nodeType is invalid", getLineno());
        stopWalk();
        break;
    }

    }

}
