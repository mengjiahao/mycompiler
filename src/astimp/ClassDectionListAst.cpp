#include "../../include/ast/ClassDectionListAst.h"

ClassDectionListAst::ClassDectionListAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ClassDectionListAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    if (nodeType != T_CCLASSDECTIONLIST_CLASSDECTIONLIST_CLASSDECTION)
    {
        std::cout << "error: nodetype is not T_CCLASSDECTIONLIST_CLASSDECTIONLIST_CLASSDECTION in ClassDectionListAst"
        << std::endl;
        stopWalk();
        return ;
    }
    std::cout << "walk in T_CCLASSDECTIONLIST_CLASSDECTIONLIST_CLASSDECTION" << endl;

    childs.at(0)->walk();
    if (checkIsNotWalking()) {
        return ;
    }

    childs.at(1)->walk();
    if (checkIsNotWalking()) {
        return ;
    }

}
