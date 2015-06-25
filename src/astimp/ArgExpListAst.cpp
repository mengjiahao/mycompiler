
#include "../../include/ast/ArgExpListAst.h"

ArgExpListAst::ArgExpListAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {


}

void ArgExpListAst::processAssgExp(NodeType nodeType_t)
{
        switch(s_context->tmpOpType) {
        case ItmCode::OPR_SYMBOL: {
            if (NULL != s_context->tmpExpSymbol) {
                s_context->addToArgExpList(s_context->tmpExpSymbol);
                s_context->tmpOpType = ItmCode::OPR_ARGLIST;
            } else {
                std::cout << "error in ArgExpListAst(" << nodeType_t
                << "): s_context->tmpExpSymbol is NULL" << std::endl;
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
                } else {
                    s_context->addToArgExpList(m);
                    s_context->tmpOpType = ItmCode::OPR_ARGLIST;
                }

            } else {
                std::cout << "error in ArgExpListAst(" << nodeType_t
                << "): s_context->tmpExpReg is NULL" << std::endl;
            }

            break;
        }
        default: {
            std::cout << "error in ArgExpListAst(" << nodeType_t
            << "): s_context->tmpOpType is invalid" << std::endl;
            break;
        }

        }
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

        processAssgExp(nodeType);

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

        processAssgExp(nodeType);


        break;
    }

    default: {
        std::cout << "error in ArgExpListAst: nodeType is invalid" << std::endl;
        break;
    }
    }

}
