#include "../../include/ast/DectionSpecifiersAst.h"

DectionSpecifiersAst::DectionSpecifiersAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

Info *DectionSpecifiersAst::walk()
{
    Info *tmp1=childs.at(0)->walk();
    Info *tmp2=childs.at(1)->walk();

}
