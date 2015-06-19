#include "../../include/ast/ExtDectionAst.h"

ExtDectionAst::ExtDectionAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

Info *ExtDectionAst::walk()
{
    childs.at(0)->walk();
    return NULL;
}

