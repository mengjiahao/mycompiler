#include "../../include/ast/DectionListAst.h"

DectionListAst::DectionListAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void DectionListAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    if (nodeType != T_CDECTIONLIST_DECTIONLIST_DECTION)
    {
        std::cout << "error in DectionListAst: nodetype is not T_CDECTIONLIST_DECTIONLIST_DECTION"
        << std::endl;
        stopWalk();
        return ;
    }
    std::cout << "walk in T_CDECTIONLIST_DECTIONLIST_DECTION" << endl;

    for (int i = 0; i < childsNo; ++i)
    {
        childs.at(i)->walk();
    }

}
