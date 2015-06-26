
#include "../../include/ast/ArgExpListAst.h"

ArgExpListAst::ArgExpListAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {


}

bool ArgExpListAst::processAssgExp(NodeType nodeType_t)
{
        switch(s_context->tmpOpType) {
        case ItmCode::OPR_SYMBOL: {
            if (NULL != s_context->tmpExpSymbol) {
                s_context->addToExpList(s_context->tmpExpSymbol);
                s_context->tmpOpType = ItmCode::OPR_ARGLIST;
            } else {
                std::cout << "error in ArgExpListAst(" << nodeType_t
                << "): s_context->tmpExpSymbol is NULL" << std::endl;
                return false;

            }

            break;
        }
        case ItmCode::OPR_REGISTER: {
            if (NULL != s_context->tmpExpReg) {
                Symbol *m = new Symbol(Symbol::SYMBOL_TEMPVAR);
                TypeClass tp;

                tp.initRegTypeClass(s_context->tmpExpReg->getTypeSfType());
                m->setTypeClass(&tp);

                if (0 == Scope::s_curScope->defineSymbol(m)) {
                    std::cout << "error in ArgExpListAst(" << nodeType_t
                    << "): tmpExpReg can not be used in s_curScope->defineSymbol()"
                    << std::endl;
                    delete m;
                    return false;
                } else {
                    s_context->addToExpList(m);
                    s_context->tmpOpType = ItmCode::OPR_ARGLIST;

                    //genCode(s_context->tmpExpReg, m);
                }

            } else {
                std::cout << "error in ArgExpListAst(" << nodeType_t
                << "): s_context->tmpExpReg is NULL" << std::endl;
                return false;
            }

            break;
        }
        default: {
            std::cout << "error in ArgExpListAst(" << nodeType_t
            << "): s_context->tmpOpType is invalid" << std::endl;
            return false;
            break;
        }

        }

        return true;
}


void ArgExpListAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType) {
    case NodeAst::T_CARGEXPLIST_ASSGEXP: {
        std::cout << "walk in T_CARGEXPLIST_ASSGEXP" << endl;

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        if (false == processAssgExp(nodeType)) {
            stopWalk();
            return ;
        }

        break;
    }

    case NodeAst::T_CARGEXPLIST_ARGEXPLIST_ASSGEXP: {
        std::cout << "walk in T_CARGEXPLIST_ARGEXPLIST_ASSGEXP" << endl;

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        childs.at(1)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        if (false == processAssgExp(nodeType)) {
            stopWalk();
            return ;
        }


        break;
    }

    default: {
        std::cout << "error in ArgExpListAst: nodeType is invalid" << std::endl;
        stopWalk();
        return ;
        break;

    }
    }

}

void ArgExpListAst::genCode(Reg *reg_t, Symbol *symbol_t)
{
    if (NULL == symbol_t || NULL == reg_t) {
        //std::cout << "error in ArgExpListAst: exist member of genCode()'s params is NULL" << std::endl;
        LogiMsg::logi("error in ArgExpListAst: exist member of genCode()'s params is NULL");
    }
    ItmCode *newCode = new ItmCode(ItmCode::IR_ASSIGN_OP,
    ItmCode::OPR_REGISTER, reg_t,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_SYMBOL, symbol_t);

    ItmCode::addToAllItmCode(newCode);


}

