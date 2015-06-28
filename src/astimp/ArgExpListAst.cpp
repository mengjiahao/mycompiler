
#include "../../include/ast/ArgExpListAst.h"

ArgExpListAst::ArgExpListAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {


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

            Reg *tmpReg = processChildOperand(0);
            Symbol *tmpsymbol = new Symbol(Symbol::SYMBOL_TEMPVAR);
            tmpsymbol->typeClass.typeSfType = tmpReg->getTypeSfType();
            tmpsymbol->setOffset(Scope::s_curScope->getTotalByteSize());
            Scope::s_curScope->incTotalByteSize(tmpsymbol->getByteSize());
            Scope::s_curScope->defineSymbol(tmpsymbol);
            ItmCode *tmpCode = new ItmCode(ItmCode::IR_ASSIGN_OP,
                                            ItmCode::OPR_REGISTER, tmpReg,
                                            ItmCode::OPR_INVALID, NULL,
                                            ItmCode::OPR_SYMBOL, tmpsymbol);
            Scope::s_curScope->addItemCode(tmpCode);
            s_context->clearContext();
            s_context->clearExpList();
            s_context->addToExpList((void *)tmpsymbol);
            s_context->tmpOpType=ItmCode::OPR_ARGLIST;


            break;
        }

        case NodeAst::T_CARGEXPLIST_ARGEXPLIST_ASSGEXP: {
            std::cout << "walk in T_CARGEXPLIST_ARGEXPLIST_ASSGEXP" << endl;

            childs.at(1)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            Reg *tmpReg = processChildOperand(0);
            Symbol *tmpsymbol = new Symbol(Symbol::SYMBOL_TEMPVAR);
            tmpsymbol->typeClass.typeSfType = tmpReg->getTypeSfType();
            tmpsymbol->setOffset(Scope::s_curScope->getTotalByteSize());
            Scope::s_curScope->incTotalByteSize(tmpsymbol->getByteSize());
            Scope::s_curScope->defineSymbol(tmpsymbol);
            ItmCode *tmpCode = new ItmCode(ItmCode::IR_ASSIGN_OP,
                                            ItmCode::OPR_REGISTER, tmpReg,
                                            ItmCode::OPR_INVALID, NULL,
                                            ItmCode::OPR_SYMBOL, tmpsymbol);
            Scope::s_curScope->addItemCode(tmpCode);


            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            s_context->addToExpList((void *)tmpsymbol);
            s_context->tmpOpType=ItmCode::OPR_ARGLIST;



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


