#include "../../include/ast/IterationStmAst.h"

IterationStmAst::IterationStmAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void IterationStmAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType) {
    case T_CITRSTM_WHILE_EXP_STM: {
        LogiMsg::logi("walk in T_CITRSTM_WHILE_EXP_STM", getLineno());

        Symbol *trueBeginLabel = new Symbol(Symbol::SYMBOL_LABEL);
        Scope::s_curScope->defineSymbol(trueBeginLabel);
        ItmCode::genCodeEmitLabel(trueBeginLabel);

        list<ItmCode *> trueLabelList;
        ItmCode::copyLabelList(trueLabelList, s_context->tmpTrueLabelList);
        s_context->tmpTrueLabelList.clear();

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r = processChildOperand(0);
        if (NULL == r) {
            LogiMsg::logi("error in T_CITRSTM_WHILE_EXP_STM: conditon expression is invalid", getLineno());
            stopWalk();
            return ;
        }

        //ItmCode::genCodeRegIsTrueAssign(r);
        if (checkNodeTypeReturnValueIsBool(childs.at(0)->getNodeType())
        || (T_CASSIGNEXP_CONDITIONALEXP == childs.at(0)->getNodeType()
        && !childs.at(0)->childs.empty()
        && checkNodeTypeReturnValueIsBool(childs.at(0)->childs.at(0)->getNodeType())) ) {

        } else {
             r = ItmCode::genCodeRegIsTrueAssign(r);
             if (NULL == r) {
                stopWalk();
                return ;
             }
             s_context->tmpExpReg = r;
        }

        ItmCode *newCode = ItmCode::genCodeRegIfNotGotoLabel(r, NULL);
        s_context->addToFalseLabelList(newCode);

        Symbol *trueLabel = new Symbol(Symbol::SYMBOL_LABEL);
        Scope::s_curScope->defineSymbol(trueLabel);
        ItmCode::genCodeEmitLabel(trueLabel);

        s_context->backFillTrueLabelList(trueLabel);
        ItmCode::copyLabelList(s_context->tmpTrueLabelList, trueLabelList);

        list<ItmCode *> falseLabelList;
        ItmCode::copyLabelList(falseLabelList, s_context->tmpFalseLabelList);
        s_context->tmpFalseLabelList.clear();

        childs.at(1)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        ItmCode::genCodeGotoBeginLabel(trueBeginLabel);

        Symbol *falseLabel = new Symbol(Symbol::SYMBOL_LABEL);
        Scope::s_curScope->defineSymbol(falseLabel);
        ItmCode::genCodeEmitLabel(falseLabel);

        ItmCode::copyLabelList(s_context->tmpFalseLabelList, falseLabelList);
        s_context->backFillFalseLabelList(falseLabel);
        break;

    }

    default: {
        LogiMsg::logi("error in IterationStmAst: nodeType is invalid", getLineno());
        stopWalk();
        return ;
        break;
    }
    }
}
