#include "../../include/ast/TranslationUnitAst.h"

TranslationUnitAst::TranslationUnitAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

Info *TranslationUnitAst::walk()
{
    childs.at(0)->walk();
    childs.at(1)->walk();
    return NULL;
}
