#include "../../include/ast/ClassDectionListAst.h"

ClassDectionListAst::ClassDectionListAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ClassDectionListAst::walk()
{
    if (nodeType!=T_CCLASSDECTIONLIST_CLASSDECTIONLIST_CLASSDECTION)
    {
        std::cout << "nodetype error at ClassDectionListAst" << std::endl;
        exit(0);
    }
    childs.at(0)->walk();
    childs.at(1)->walk();
}
