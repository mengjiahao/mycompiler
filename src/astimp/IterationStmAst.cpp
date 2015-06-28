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

        Symbol *trueLabel = new Symbol(Symbol::SYMBOL_LABEL);
        Scope::s_curScope->defineSymbol(trueLabel);

        ItmCode::genCodeEmitLabel(trueLabel);

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

        ItmCode::genCodeRegIsTrueAssign(r);
        ItmCode *newCode = ItmCode::genCodeRegIfNotGotoLabel(r, NULL);

        s_context->addToFalseLabelList(newCode);

        s_context->backFillTrueLabelList(trueLabel);

        list<ItmCode *> falseLabelList = s_context->tmpFalseLabelList;

        childs.at(1)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        Symbol *falseLabel = new Symbol(Symbol::SYMBOL_LABEL);
        Scope::s_curScope->defineSymbol(falseLabel);

        ItmCode::genCodeEmitLabel(falseLabel);

        s_context->tmpFalseLabelList = falseLabelList;
        s_context->backFillFalseLabelList(falseLabel);

        childs.at(2)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

    }

    default: {
        LogiMsg::logi("error in IterationStmAst: nodeType is invalid", getLineno());
        stopWalk();
        return ;
        break;
    }
    }
}
