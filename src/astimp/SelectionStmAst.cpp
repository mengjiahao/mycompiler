#include "../../include/ast/SelectionStmAst.h"

SelectionStmAst::SelectionStmAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void SelectionStmAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType) {
    case T_CSELSTM_IF_EXP_STM: {
        LogiMsg::logi("walk in T_CSELSTM_IF_EXP_STM", getLineno());

        list<ItmCode *> trueLabelList = s_context->tmpTrueLabelList;
        s_context->tmpTrueLabelList.clear();

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r = processChildOperand(0);
        if (NULL == r) {
            LogiMsg::logi("error in T_CSELSTM_IF_EXP_STM: conditon expression is invalid", getLineno());
            stopWalk();
            return ;
        }

        ItmCode::genCodeRegIsTrueAssign(r);
        ItmCode *newCode = ItmCode::genCodeRegIfNotGotoLabel(r, NULL);
        s_context->addToFalseLabelList(newCode);

        Symbol *trueLabel = new Symbol(Symbol::SYMBOL_LABEL);
        Scope::s_curScope->defineSymbol(trueLabel);
        ItmCode::genCodeEmitLabel(trueLabel);

        s_context->backFillTrueLabelList(trueLabel);
        s_context->tmpTrueLabelList = trueLabelList;

        list<ItmCode *> falseLabelList = s_context->tmpFalseLabelList;
        s_context->tmpFalseLabelList.clear();

        childs.at(1)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        Symbol *falseLabel = new Symbol(Symbol::SYMBOL_LABEL);
        Scope::s_curScope->defineSymbol(falseLabel);
        ItmCode::genCodeEmitLabel(falseLabel);

        s_context->backFillFalseLabelList(falseLabel);
        s_context->tmpFalseLabelList = falseLabelList;


        break;
    }

    case T_CSELSTM_IF_EXP_STM_ELSE_STM: {
        LogiMsg::logi("walk in T_CSELSTM_IF_EXP_STM_ELSE_STM", getLineno());

        list<ItmCode *> trueLabelList = s_context->tmpTrueLabelList;
        s_context->tmpTrueLabelList.clear();

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r = processChildOperand(0);
        if (NULL == r) {
            LogiMsg::logi("error in T_CSELSTM_IF_EXP_STM_ELSE_STM: conditon expression is invalid", getLineno());
            stopWalk();
            return ;
        }

        ItmCode::genCodeRegIsTrueAssign(r);
        ItmCode *newCode = ItmCode::genCodeRegIfNotGotoLabel(r, NULL);
        s_context->addToFalseLabelList(newCode);

        Symbol *trueLabel = new Symbol(Symbol::SYMBOL_LABEL);
        Scope::s_curScope->defineSymbol(trueLabel);
        ItmCode::genCodeEmitLabel(trueLabel);

        s_context->backFillTrueLabelList(trueLabel);
        s_context->tmpTrueLabelList = trueLabelList;

        list<ItmCode *> falseLabelList = s_context->tmpFalseLabelList;
        s_context->tmpFalseLabelList.clear();

        childs.at(1)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        Symbol *falseLabel = new Symbol(Symbol::SYMBOL_LABEL);
        Scope::s_curScope->defineSymbol(falseLabel);
        ItmCode::genCodeEmitLabel(falseLabel);

        s_context->backFillFalseLabelList(falseLabel);
        s_context->tmpFalseLabelList = falseLabelList;

        childs.at(2)->walk();
        if (checkIsNotWalking()) {
            return ;
        }


        break;
    }

    default: {
        LogiMsg::logi("error in SelectionStmAst: nodeType is invalid", getLineno());
        stopWalk();
        return ;
        break;
    }
    }
}
