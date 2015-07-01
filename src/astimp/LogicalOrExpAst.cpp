#include "../../include/ast/LogicalOrExpAst.h"

LogicalOrExpAst::LogicalOrExpAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void LogicalOrExpAst::walk()
{
   if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType) {
    case T_CLOGOREXP_LOGOREXP_OR_OP_LOGANDEXP: {
        LogiMsg::logi("walk in T_CLOGOREXP_LOGOREXP_OR_OP_LOGANDEXP", getLineno());

        list<ItmCode *> falseLableList;
        ItmCode::copyLabelList(falseLableList, s_context->tmpFalseLabelList);
        s_context->tmpFalseLabelList.clear();

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r1 = processChildOperand(0);
        if (NULL == r1) {
            LogiMsg::logi("error in T_CLOGOREXP_LOGOREXP_OR_OP_LOGANDEXP: left operand is invalid", getLineno());
            stopWalk();
            return ;
        }

        //ItmCode::genCodeRegIsTrueAssign(r1);
        if (checkNodeTypeReturnValueIsBool(childs.at(0)->getNodeType())) {

        } else {

             r1 = ItmCode::genCodeRegIsTrueAssign(r1);
             if (NULL == r1) {
                stopWalk();
                return ;
             }
             s_context->tmpExpReg = r1;
        }

        ItmCode *newCode = ItmCode::genCodeRegIfGotoLabel(r1, NULL);
        s_context->addToTrueLabelList(newCode);

        Symbol *falseLabel = new Symbol(Symbol::SYMBOL_LABEL);
        Scope::s_curScope->defineSymbol(falseLabel);
        ItmCode::genCodeEmitLabel(falseLabel);

        s_context->backFillFalseLabelList(falseLabel);
        ItmCode::copyLabelList(s_context->tmpFalseLabelList, falseLableList);


        childs.at(1)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r2 = processChildOperand(0);
        if (NULL == r2) {
            LogiMsg::logi("error in T_CLOGOREXP_LOGOREXP_OR_OP_LOGANDEXP: right operand is invalid", getLineno());
            stopWalk();
            return ;
        }


        //ItmCode::genCodeRegIsTrueAssign(r2);
        if (checkNodeTypeReturnValueIsBool(childs.at(1)->getNodeType())) {

        } else {
             r2 = ItmCode::genCodeRegIsTrueAssign(r2);
             if (NULL == r2) {
                stopWalk();
                return ;
             }
             s_context->tmpExpReg = r2;
        }

        //Reg *r3 = Reg::getReg(0, TypeClass::promoteType(r1->getTypeSfType(), r2->getTypeSfType()));
        /*Reg *r3 = Reg::getReg(0, TypeClass::SF_INT);

        s_context->tmpExpReg = r3;
        s_context->tmpOpType = ItmCode::OPR_REGISTER;

        ItmCode::genCodeRegBinOpRegToReg(ItmCode::IR_LOG_OR_OP, r1, r2, r3);*/


        break;
    }

    default: {
        LogiMsg::logi("error in T_CLOGOREXP_LOGOREXP_OR_OP_LOGANDEXP: nodeType is invalid", getLineno());
        stopWalk();
        break;
    }

    }
}

