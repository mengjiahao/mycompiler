#include "../../include/ast/DectionListAst.h"

DectionListAst::DectionListAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void DectionListAst::walk()
{
    if (nodeType!=T_CDECTIONLIST_DECTIONLIST_DECTION)
    {
        std::cout << "nodetype error at DectionListAst" << std::endl;
        exit(0);
    }
    for (int i=0; i < childsNo; i++)
    {
        childs.at(i)->walk();
    }
}
