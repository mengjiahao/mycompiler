#include "../../include/ast/ParamTypeListAst.h"

ParamTypeListAst::ParamTypeListAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ParamTypeListAst::walk()
{
    if (nodeType == T_CPARAMLIST_PARAMLIST_PARAMDECTION)
    {
        childs.at(1)->walk();

        if (childs.at(1)->nodeType == T_CPARAMDECTION_DECTIONSFS) {
            TypeClass tmp;
            tmp.clone(&(s_context->tmpParaTypeList.at(0)));

            childs.at(0)->walk();

            s_context->addParawithoutid(tmp);

        } else if (childs.at(1)->nodeType == T_CPARAMDECTION_DECTIONSFS_DECTOR) {
            Symbol tmpsymbol(Symbol::SYMBOL_VAR);
            tmpsymbol.symbolName = s_context->tmpParaWithIdList.at(0).symbolName;
            tmpsymbol.typeClass.clone(&(s_context->tmpParaWithIdList.at(0).typeClass));

            childs.at(0)->walk();

            s_context->addParawithid(tmpsymbol);
        } else {
            std::cout<<"error in T_CPARAMDECTION_DECTIONSFS_DECTOR: nodetype is not T_CPARAMLIST_PARAMLIST_PARAMDECTION"
            <<std::endl;
            exit(0);
        }

    }
    else
    {
        std::cout<<"error: nodetype error at ParamTypeListAst"<<std::endl;
        exit(0);
    }
}
