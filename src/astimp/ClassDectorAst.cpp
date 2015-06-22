#include "../../include/ast/ClassDectorAst.h"

ClassDectorAst::ClassDectorAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ClassDectorAst::walk()
{
    if (nodeType!=T_CCLASSDECTOR_DECTOR)
    {
        std::cout << "nodetype error at ClassDectorAst" << std::endl;
        exit(0);
    }
    childs.at(0)->walk();
}
