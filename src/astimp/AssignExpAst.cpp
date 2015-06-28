#include "../../include/ast/AssignExpAst.h"

AssignExpAst::AssignExpAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void AssignExpAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType) {
    case T_CASSIGNEXP_CONDITIONALEXP: {
        LogiMsg::logi("walk in T_CASSIGNEXP_CONDITIONALEXP", getLineno());


        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r = processChildOperand(0);
        if (NULL == r) {
            LogiMsg::logi("error in T_CASSIGNEXP_CONDITIONALEXP: assigment operand is invalid", getLineno());
            stopWalk();
            return ;
        }

        break;
    }

    case T_CASSIGNEXP_UNARYEXP_ASSIGN_OP_ASSIGNEXP: {
        LogiMsg::logi("walk in T_CASSIGNEXP_UNARYEXP_ASSIGN_OP_ASSIGNEXP", getLineno());

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        void *u = processUnaryChildOperand();
        if (NULL == u) {
            LogiMsg::logi("error: in T_CASSIGNEXP_UNARYEXP_ASSIGN_OP_ASSIGNEXP: unary_expression is invalid",
            getLineno());
            stopWalk();
            return ;
        }
        ItmCode::OperandType optp = s_context->tmpOpType;
        s_context->clearSingleOperand();

        NodeType uopNodeType = childs.at(1)->getNodeType();

        childs.at(2)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *r = processChildOperand(0);
        if (NULL == r) {
            LogiMsg::logi("error in T_CASSIGNEXP_UNARYEXP_ASSIGN_OP_ASSIGNEXP: assigment operand is invalid", getLineno());
            stopWalk();
            return ;
        }

        s_context->clearSingleOperand();
        s_context->resetSingleOperand(u, optp);

        if (false == genCodeAssignChildOperand(uopNodeType, optp, u, r)) {
            LogiMsg::logi("error in T_CASSIGNEXP_UNARYEXP_ASSIGN_OP_ASSIGNEXP: genCodeAssignChildOperand() is invalid", getLineno());
            stopWalk();
            return ;
        }


        break;
    }

    case T_CASSIGNEXP_NEW_ID_VOID: {
        LogiMsg::logi("walk in T_CASSIGNEXP_NEW_ID_VOID", getLineno());

        if (T_CTERMINATE_CASSIGNEXP_NEW_ID_VOID != childs.at(0)->getNodeType()) {
            LogiMsg::logi("error in T_CASSIGNEXP_NEW_ID_VOID: child type is not T_CTERMINATE_CASSIGNEXP_NEW_ID_VOID",
            getLineno());
            stopWalk();
            return ;
        }

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        Scope *s = Scope::s_curScope->resolveScope(s_context->tmpIdenName, Scope::SCOPE_CLASS);
        if (NULL == s) {
            LogiMsg::logi("error in T_CASSIGNEXP_NEW_ID_VOID: cannot find the class type",
            s_context->tmpIdenName, getLineno());
            stopWalk();
            return ;
        }

        Reg *r = Reg::getReg(0, TypeClass::SF_INT);

        ItmCode::genCodeNewClassIdToReg(r);

        s_context->clearSingleOperand();
        s_context->tmpOpType = ItmCode::OPR_REGISTER;
        s_context->tmpExpReg = r;


        break;
    }

    case T_CASSIGNEXP_DELETE_ID: {
        LogiMsg::logi("walk in T_CASSIGNEXP_DELETE_ID", getLineno());

        if (T_CTERMINATE_CASSIGNEXP_DELETE_ID != childs.at(0)->getNodeType()) {
            LogiMsg::logi("error in T_CASSIGNEXP_DELETE_ID: child type is not T_CASSIGNEXP_DELETE_ID",
            getLineno());
            stopWalk();
            return ;
        }

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        Symbol *s = Scope::s_curScope->resolveSymbol(s_context->tmpIdenName, Symbol::SYMBOL_CLASSREFVAR);
        if (NULL == s) {
            LogiMsg::logi("error in T_CASSIGNEXP_DELETE_ID: cannot find the class refSymbol",
            s_context->tmpIdenName, getLineno());
            stopWalk();
            return ;
        }

        ItmCode::genCodeDeleteClassRefId(s);

        s_context->clearSingleOperand();


        break;
    }

    default: {
        LogiMsg::logi("error in AssignExpAst: nodeType is invalid", getLineno());
        stopWalk();
        return ;
        break;
    }
    }


}


bool AssignExpAst::genCodeAssignChildOperand(NodeAst::NodeType nodeType_t, ItmCode::OperandType opType_t,
void *u, Reg *r)
{
    if (NULL == u || NULL == r) {
        return false;
    }

    ItmCode::IRtype codeType;

    switch(nodeType_t) {
    case T_CTERMINATE_CASSIGN_OP_ASSIGN: {
        codeType = ItmCode::IR_ASSIGN_OP;
        break ;
    }

    case T_CTERMINATE_CASSIGN_OP_MUL_ASSIGN: {
        codeType = ItmCode::IR_MUL_ASSIGN;
        break ;
    }

    case T_CTERMINATE_CASSIGN_OP_DIV_ASSIGN: {
        codeType = ItmCode::IR_DIV_ASSIGN;
        break ;
    }

    case T_CTERMINATE_CASSIGN_OP_ADD_ASSIGN: {
        codeType = ItmCode::IR_ADD_ASSIGN;
        break ;
    }

    case T_CTERMINATE_CASSIGN_OP_SUB_ASSIGN: {
        codeType = ItmCode::IR_SUB_ASSIGN;
        break ;
    }

    default: {
        return false;
        break ;
    }
    }

    switch(opType_t) {
        case ItmCode::OPR_SYMBOL: {

            ItmCode::genCodeAssignRegToSymbol(codeType, r, (Symbol *)u);

            return true;
            break;
        }

        case ItmCode::OPR_CLASS_REFLIST:
        case ItmCode::OPR_CLASS_REFLIST_POINTER: {

            ItmCode::genCodeAssignRegToRefList(codeType, r, (vector<void *>*)u);

            return true;
            break;
        }

        default: {
            return false;
            break;
        }
        }

    return false;
}

