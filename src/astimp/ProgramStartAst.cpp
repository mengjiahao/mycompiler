#include "../../include/ast/ProgramStartAst.h"
#include "../../include/symbol/Scope.h"

ProgramStartAst::ProgramStartAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}



void ProgramStartAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    Scope *tmp = new Scope();
    tmp->initGlobalScope();

    if (NULL != Scope::pushScope(NULL, tmp))
    {
        Scope::setGlobalScope(tmp);
        Scope::setCurScope(tmp);
    }

    cout << "walk in ProgramStartAst" << endl;

    for (int i = 0; i < childs.size(); ++i) {
        if (NULL != childs.at(i)) {
            childs.at(i)->walk();
            if (checkIsNotWalking()) {
                return ;
            }
        }
    }


}
