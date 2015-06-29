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
        LogiMsg::logi("walk in T_CLOGANDEXP_LOGANDEXP_AND_OP_EQUALEXP", getLineno());

        list<ItmCode *> trueLableList;
        ItmCode::copyLabelList(trueLableList, s_context->tmpTrueLabelList);

        s_context->tmpTrueLabelList.clear();

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



        ItmCode *newCode = ItmCode::genCodeRegIfNotGotoLabel(r1, NULL);
        s_context->addToFalseLabelList(newCode);

        Symbol *trueLabel = new Symbol(Symbol::SYMBOL_LABEL);
        Scope::s_curScope->defineSymbol(trueLabel);
        ItmCode::genCodeEmitLabel(trueLabel);

        s_context->backFillTrueLabelList(trueLabel);
        ItmCode::copyLabelList(s_context->tmpTrueLabelList, trueLableList);


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

        ItmCode::genCodeRegBinOpRegToReg(ItmCode::IR_LOG_AND_OP, r1, r2, r3);*/


        break;
    }

    default: {
        LogiMsg::logi("error in T_CLOGANDEXP_LOGANDEXP_AND_OP_EQUALEXP: nodeType is invalid", getLineno());
        stopWalk();
        break;
    }

    }

}
