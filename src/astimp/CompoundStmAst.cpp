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
            //std::cout << "walk in T_CCOMPSTM_VOID" << endl;
            LogiMsg::logi("walk in T_CCOMPSTM_VOID", getLineno());
            break;
        }
        case T_CCOMPSTM_STMLIST: {
            //std::cout << "walk in T_CCOMPSTM_STMLIST" << endl;
            LogiMsg::logi("walk in T_CCOMPSTM_STMLIST", getLineno());
           // Scope::s_curScope->incTotalByteSize(4);

            Scope *tmpScope = new Scope();
            tmpScope->setScopeType(Scope::SCOPE_LOCAL);

            tmpScope->startCodeNo=ItmCode::totalItmNo;

            tmpScope->setCurStartOffset(Scope::s_curScope->getTotalByteSize()+4);
            tmpScope->setTotalByteSize(Scope::s_curScope->getTotalByteSize()+4);

            Scope::pushScope(Scope::s_curScope, tmpScope);
            Scope::setCurScope(tmpScope);

            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            Scope::setCurScope(Scope::encloseScope(Scope::s_curScope));
            break;
        }
        case T_CCOMPSTM_DECTION_LIST:{
            //std::cout << "walk in T_CCOMPSTM_DECTION_LIST" << endl;
            LogiMsg::logi("walk in T_CCOMPSTM_DECTION_LIST", getLineno());
           // Scope::s_curScope->incTotalByteSize(4);

            Scope *tmpScope = new Scope();
            tmpScope->setScopeType(Scope::SCOPE_LOCAL);

            tmpScope->startCodeNo=ItmCode::totalItmNo;

            tmpScope->setCurStartOffset(Scope::s_curScope->getTotalByteSize()+4);
            tmpScope->setTotalByteSize(Scope::s_curScope->getTotalByteSize()+4);

            Scope::pushScope(Scope::s_curScope, tmpScope);
            Scope::setCurScope(tmpScope);

            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            Scope::setCurScope(Scope::encloseScope(Scope::s_curScope));
            break;
        }
        case T_CCOMPSTM_DECTIONLIST_STMLIST:{
            //std::cout << "walk in T_CCOMPSTM_DECTIONLIST_STMLIST" << endl;
            LogiMsg::logi("walk in T_CCOMPSTM_DECTIONLIST_STMLIST", getLineno());
           // Scope::s_curScope->incTotalByteSize(4);

            Scope *tmpScope = new Scope();
            tmpScope->setScopeType(Scope::SCOPE_LOCAL);

            tmpScope->startCodeNo=ItmCode::totalItmNo;

            tmpScope->setCurStartOffset(Scope::s_curScope->getTotalByteSize()+4);
            tmpScope->setTotalByteSize(Scope::s_curScope->getTotalByteSize()+4);

            Scope::pushScope(Scope::s_curScope, tmpScope);
            Scope::setCurScope(tmpScope);

            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            childs.at(1)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            Scope::setCurScope(Scope::encloseScope(Scope::s_curScope));

            break;
        }
        default:{
            //std::cout << "error in CompoundStmAst: nodeType is invalid" << std::endl;
            LogiMsg::logi("error in CompoundStmAst: nodeType is invalid", getLineno());
            stopWalk();
            return ;

            break;
        }
    }
}
