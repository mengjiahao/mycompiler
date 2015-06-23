#include "../../include/ast/ClassDectionListAst.h"

ClassDectionListAst::ClassDectionListAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ClassDectionListAst::walk()
{
    if (nodeType != T_CCLASSDECTIONLIST_CLASSDECTIONLIST_CLASSDECTION)
    {
        std::cout << "error: nodetype is not T_CCLASSDECTIONLIST_CLASSDECTIONLIST_CLASSDECTION in ClassDectionListAst"
        << std::endl;
        exit(0);
    }
    std::cout << "walk in T_CCLASSDECTIONLIST_CLASSDECTIONLIST_CLASSDECTION" << endl;

    childs.at(0)->walk();
    childs.at(1)->walk();
}
