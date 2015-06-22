#include "../../include/ast/CompoundStmAst.h"

CompoundStmAst::CompoundStmAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void CompoundStmAst::walk()
{

    switch (nodeType){
        case T_CCOMPSTM_VOID:{

            break;
        }
        case T_CCOMPSTM_STMLIST:
        case T_CCOMPSTM_DECTION_LIST:{

            Scope *tmpScope = new Scope();
            tmpScope->setScopeType(Scope::SCOPE_LOCAL);
            Scope::pushScope(Scope::s_curScope, tmpScope);
            Scope::setCurScope(tmpScope);

            childs.at(0)->walk();

            Scope::setCurScope(Scope::encloseScope(Scope::s_curScope));
            break;
        }
        case T_CCOMPSTM_DECTIONLIST_STMLIST:{
        cout << "!:comp" << endl;
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

            break;
        }
    }
}
