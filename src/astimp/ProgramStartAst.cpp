#include "../../include/ast/ProgramStartAst.h"
#include "../../include/symbol/Scope.h"

ProgramStartAst::ProgramStartAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}



void ProgramStartAst::walk()
{
    Scope *tmp = new Scope();
    tmp->initGlobalScope();

    if (NULL != Scope::pushScope(NULL, tmp))
    {
        Scope::setGlobalScope(tmp);
        Scope::setCurScope(tmp);
    }

    cout << "ProgStartWalk" << endl;

    for (int i = 0; i < childs.size(); ++i) {
        if (NULL != childs.at(i)) {
            childs.at(i)->walk();
        }
    }


}
