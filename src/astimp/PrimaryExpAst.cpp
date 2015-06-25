
#include "../../include/ast/PrimaryExpAst.h"

PrimaryExpAst::PrimaryExpAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void PrimaryExpAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType) {
    case T_CTERMINATE_CPRIMEXP_ID: {
        std::cout << "walk in T_CTERMINATE_CPRIMEXP_ID" << endl;

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        //Symbol *rst = s_context->tmpExpSymbol;

        break;
    }

    case T_CPRIMEXP_CONST: {
        std::cout << "walk in T_CPRIMEXP_CONST" << endl;

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        break;
    }

    case T_CTERMINATE_CPRIMEXP_STR: {
        std::cout << "walk in T_CTERMINATE_CPRIMEXP_STR" << endl;

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        break;
    }

    case T_CPRIMEXP_EXP: {
        std::cout << "walk in T_CPRIMEXP_EXP" << endl;

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        break;
    }

    default: {
        std::cout << "error in PrimaryExpAst: nodeType is invalid" << std::endl;
        break;
    }
    }


}
