#include "../../include/ast/CompoundStmAst.h"

CompoundStmAst::CompoundStmAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void CompoundStmAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch (nodeType){
        case T_CCOMPSTM_VOID:{
            std::cout << "walk in T_CCOMPSTM_VOID" << endl;
            break;
        }
        case T_CCOMPSTM_STMLIST: {
            std::cout << "walk in T_CCOMPSTM_STMLIST" << endl;

            Scope *tmpScope = new Scope();
            tmpScope->setScopeType(Scope::SCOPE_LOCAL);
            Scope::pushScope(Scope::s_curScope, tmpScope);
            Scope::setCurScope(tmpScope);

            childs.at(0)->walk();

            Scope::setCurScope(Scope::encloseScope(Scope::s_curScope));
            break;
        }
        case T_CCOMPSTM_DECTION_LIST:{
            std::cout << "walk in T_CCOMPSTM_DECTION_LIST" << endl;

            Scope *tmpScope = new Scope();
            tmpScope->setScopeType(Scope::SCOPE_LOCAL);
            Scope::pushScope(Scope::s_curScope, tmpScope);
            Scope::setCurScope(tmpScope);

            childs.at(0)->walk();

            Scope::setCurScope(Scope::encloseScope(Scope::s_curScope));
            break;
        }
        case T_CCOMPSTM_DECTIONLIST_STMLIST:{
            std::cout << "walk in T_CCOMPSTM_DECTIONLIST_STMLIST" << endl;

            Scope *tmpScope = new Scope();
            tmpScope->setScopeType(Scope::SCOPE_LOCAL);
            Scope::pushScope(Scope::s_curScope, tmpScope);
            Scope::setCurScope(tmpScope);

            childs.at(0)->walk();

            childs.at(1)->walk();

            Scope::setCurScope(Scope::encloseScope(Scope::s_curScope));

            break;
        }
        default:{
            std::cout << "error in CompoundStmAst: nodeType is invalid" << std::endl;

            break;
        }
    }
}
