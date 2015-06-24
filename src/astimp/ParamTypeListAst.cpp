#include "../../include/ast/ParamTypeListAst.h"

ParamTypeListAst::ParamTypeListAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ParamTypeListAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    if (nodeType == T_CPARAMLIST_PARAMLIST_PARAMDECTION)
    {
        std::cout << "walk in T_CPARAMLIST_PARAMLIST_PARAMDECTION" << endl;

        childs.at(1)->walk();
        if (checkIsNotWalking()) {
                return ;
        }

        if (childs.at(1)->nodeType == T_CPARAMDECTION_DECTIONSFS) {
            TypeClass tmp;
            tmp.clone(&(s_context->tmpParaTypeList.at(0)));

            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            s_context->addParawithoutid(tmp);

        } else if (childs.at(1)->nodeType == T_CPARAMDECTION_DECTIONSFS_DECTOR) {
            Symbol tmpsymbol(Symbol::SYMBOL_VAR);
            //tmpsymbol.symbolName = s_context->tmpParaWithIdList.at(0).symbolName;
            //tmpsymbol.typeClass.clone(&(s_context->tmpParaWithIdList.at(0).typeClass));
            tmpsymbol.setSymbolName(s_context->tmpParaWithIdList.at(0).symbolName);
            tmpsymbol.setTypeClass(&(s_context->tmpParaWithIdList.at(0).typeClass));

            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            s_context->addParawithid(tmpsymbol);
        } else {
            std::cout<<"error in T_CPARAMDECTION_DECTIONSFS_DECTOR: nodetype is not T_CPARAMLIST_PARAMLIST_PARAMDECTION"
            <<std::endl;
            stopWalk();
            return ;
        }

    }
    else
    {
        std::cout<<"error in ParamTypeListAst: nodetype is invalid"<<std::endl;
        stopWalk();
        return ;
    }

}
