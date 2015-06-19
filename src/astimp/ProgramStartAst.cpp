#include "../../include/ast/ProgramStartAst.h"
#include "../../include/symbol/Scope.h"

ProgramStartAst::ProgramStartAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}


void ProgramStartAst::walk()
{
    Scope *globalScope = new Scope();
    globalScope->initGlobalScope();



    Scope *p = Scope::pushScope(NULL, globalScope);
    if (NULL != p) {

        Scope::setGlobalScope(p);
        Scope::setCurScope(p);

    }

    Scope::printScopeTree();

}
