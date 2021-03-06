
#include "../../include/ast/PrimaryExpAst.h"

PrimaryExpAst::PrimaryExpAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void PrimaryExpAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType) {
    case T_CPRIMEXP_ID: {
        //std::cout << "walk in T_CPRIMEXP_ID" << endl;
        LogiMsg::logi("walk in T_CPRIMEXP_ID", getLineno());

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        if ((parent->nodeType != NodeAst::T_CPOSTEXP_POSTEXP_CALL_VOID) &&
            (parent->nodeType != NodeAst::T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST))
        {

            Symbol *tmpSymbol=NULL;
            tmpSymbol=Scope::s_curScope->resolveSymbol(s_context->tmpIdenName, Symbol::SYMBOL_VAR);
            if (!tmpSymbol)
            {
                /*std::cout << "error: in T_CPRIMEXP_ID there is no symbol named "
                << s_context->tmpIdenName << "at line " << getLineno() << std::endl;*/
                LogiMsg::logi("error: in T_CPRIMEXP_ID there is no symbol named", s_context->tmpIdenName, getLineno());
                stopWalk();
                return ;
            }
            s_context->clearContext();
            s_context->tmpOpType = ItmCode::OPR_SYMBOL;
            s_context->tmpExpSymbol = tmpSymbol;

        }



        //Symbol *rst = s_context->tmpExpSymbol;

        break;
    }

    case T_CPRIMEXP_CONST: {
        //std::cout << "walk in T_CPRIMEXP_CONST" << endl;
        LogiMsg::logi("walk in T_CPRIMEXP_CONST", getLineno());

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        break;
    }

    case T_CPRIMEXP_STR: {
        //std::cout << "walk in T_CPRIMEXP_STR" << endl;
        LogiMsg::logi("walk in T_CPRIMEXP_STR", getLineno());

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        break;
    }

    case T_CPRIMEXP_EXP: {
        //std::cout << "walk in T_CPRIMEXP_EXP" << endl;
        LogiMsg::logi("walk in T_CPRIMEXP_EXP", getLineno());

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        break;
    }

    default: {
        //std::cout << "error in PrimaryExpAst: nodeType is invalid" << std::endl;
        LogiMsg::logi("error in PrimaryExpAst: nodeType is invalid", getLineno());
        break;
    }
    }


}
