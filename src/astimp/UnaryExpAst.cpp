
#include "../../include/ast/UnaryExpAst.h"

UnaryExpAst::UnaryExpAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void UnaryExpAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    //do not clear s_context

    switch(nodeType) {
    case T_CUNARYEXP_INC_OP_UNARAYEXP: {
        LogiMsg::logi("T_CUNARYEXP_INC_OP_UNARAYEXP", getLineno());

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        if ( T_CPOSTEXP_POSTEXP_CALL_VOID == childs.at(0)->getNodeType()
            || T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST == childs.at(0)->getNodeType() ) {
            LogiMsg::logi("error in T_CUNARYEXP_INC_OP_UNARAYEXP: cannot use the func return value in UnaryExpAst",
            getLineno());
            stopWalk();
            return ;
        }

        void *t = processUnaryChildOperand();
        if (NULL == t) {
            LogiMsg::logi("error in T_CUNARYEXP_INC_OP_UNARAYEXP: operand is invalid", getLineno());
            stopWalk();
            return ;
        }

        if (false == genCodeUnaryChildOperand(nodeType, s_context->tmpOpType, t)) {
            LogiMsg::logi("error in T_CUNARYEXP_INC_OP_UNARAYEXP: the return value of genCodeUnaryChildOperand() is invalid",
            getLineno());
            stopWalk();
            return ;
        }


        break;
    }

    case T_CUNARYEXP_DEC_OP_UNARYEXP: {
        LogiMsg::logi("T_CUNARYEXP_DEC_OP_UNARYEXP", getLineno());

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        if ( T_CPOSTEXP_POSTEXP_CALL_VOID == childs.at(0)->getNodeType()
            || T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST == childs.at(0)->getNodeType() ) {
            LogiMsg::logi("error in T_CUNARYEXP_INC_OP_UNARAYEXP: cannot use the func return value in UnaryExpAst",
            getLineno());
            stopWalk();
            return ;
        }

        void *t = processUnaryChildOperand();
        if (NULL == t) {
            LogiMsg::logi("error in T_CUNARYEXP_DEC_OP_UNARYEXP: operand is invalid", getLineno());
        }

        if (false == genCodeUnaryChildOperand(nodeType, s_context->tmpOpType, t)) {
            LogiMsg::logi("error in T_CUNARYEXP_DEC_OP_UNARYEXP: the return value of genCodeUnaryChildOperand() is invalid",
            getLineno());
            stopWalk();
            return ;
        }

        break;
    }

    case T_CUNARYEXP_UNARY_OP_CASTEXP: {
        LogiMsg::logi("T_CUNARYEXP_UNARY_OP_CASTEXP", getLineno());


        NodeType uopNodeType = childs.at(0)->getNodeType();

        childs.at(1)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        if ( T_CPOSTEXP_POSTEXP_CALL_VOID == childs.at(1)->getNodeType()
            || T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST == childs.at(1)->getNodeType() ) {
            LogiMsg::logi("error in T_CUNARYEXP_INC_OP_UNARAYEXP: cannot use the func return value in UnaryExpAst",
            getLineno());
            stopWalk();
            return ;
        }

        void *t = processUnaryChildOperand();
        if (NULL == t) {
            LogiMsg::logi("error in T_CUNARYEXP_UNARY_OP_CASTEXP: operand is invalid", getLineno());
        }

        if (false == genCodeUnaryChildOperand(uopNodeType, s_context->tmpOpType, t)) {
            LogiMsg::logi("error in T_CUNARYEXP_UNARY_OP_CASTEXP: genCodeUnaryChildOperand() is invalid",
            getLineno());
            stopWalk();
            return ;
        }

        break;
    }

    default: {
        LogiMsg::logi("error in UnaryOpAst: nodeType is invalid", getLineno());
        stopWalk();
        return ;
        break;
    }
    }

}



bool UnaryExpAst::genCodeUnaryChildOperand(NodeAst::NodeType nodeType_t, ItmCode::OperandType opType_t, void *t)
{
    if (NULL == t) {
        return false;
    }

    ItmCode::IRtype codeType;

    switch(nodeType_t) {
    case T_CUNARYEXP_INC_OP_UNARAYEXP: {
        codeType = ItmCode::IR_INC_OP;
        break ;
    }

    case T_CUNARYEXP_DEC_OP_UNARYEXP: {
        codeType = ItmCode::IR_DEC_OP;
        break ;
    }

    case T_CTERMINATE_CUNARY_OP_ADD_OP: {
        codeType = ItmCode::IR_UADD_OP;
        break ;
    }

    case T_CTERMINATE_CUNARY_OP_SUB_OP: {
        codeType = ItmCode::IR_USUB_OP;
        break ;
    }

    default: {
        return false;
        break ;
    }
    }

    switch(opType_t) {
        case ItmCode::OPR_SYMBOL: {

            ItmCode::genCodeUnaryOpSymbol(codeType, (Symbol *)t);

            return true;
            break;
        }

        case ItmCode::OPR_CLASS_REFLIST_POINTER: {

            ItmCode::genCodeUnaryOpClassRefList(codeType, (vector<void *>*)t);

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



