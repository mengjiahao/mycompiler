#include "../../include/ast/ProgramStartAst.h"

ProgramStartAst::ProgramStartAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}
Info *ProgramStartAst::walk()
{
    Scope *tmp=new Scope();
    tmp->initGlobalScope();
    if (Scope::pushScope(NULL,tmp)!=NULL)
    {
        Scope::setGlobalScope(tmp);
        Scope::setCurScope(tmp);
    }
    childs.at(0)->walk();
    return NULL;
}
