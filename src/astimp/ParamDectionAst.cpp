#include "../../include/ast/ParamDectionAst.h"

ParamDectionAst::ParamDectionAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ParamDectionAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType){
        case T_CPARAMDECTION_DECTIONSFS_DECTOR:{
            //std::cout << "walk in T_CPARAMDECTION_DECTIONSFS_DECTOR" << endl;
            LogiMsg::logi("walk in T_CPARAMDECTION_DECTIONSFS_DECTOR", getLineno());

            if (childs.at(1)->nodeType != T_CDIRDECTOR_ID)
            {
                /*std::cout<<"error in T_CPARAMDECTION_DECTIONSFS_DECTOR: the children's type of function is T_CDIRDECTOR_ID at line "
                <<getLineno()<<std::endl;*/
                LogiMsg::logi("error in T_CPARAMDECTION_DECTIONSFS_DECTOR: the children's type of function is T_CDIRDECTOR_ID",
                getLineno());
                stopWalk();
                return ;
            }

            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }


            TypeClass tmp;
            tmp.clone(&(s_context->tmpDeclType));

            childs.at(1)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            Symbol tmpsymbol(Symbol::SYMBOL_VAR);

            //tmpsymbol.symbolName=s_context->tmpIdenName;
            //tmpsymbol.typeClass.clone(&tmp);
            tmpsymbol.setSymbolName(s_context->tmpIdenName);
            tmpsymbol.setTypeClass(&tmp);


            s_context->clearContext();
            s_context->addParawithid(tmpsymbol);
            break;
        }
        case T_CPARAMDECTION_DECTIONSFS:{
            //std::cout << "walk in T_CPARAMDECTION_DECTIONSFS" << endl;
            LogiMsg::logi("walk in T_CPARAMDECTION_DECTIONSFS", getLineno());

            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            TypeClass tmp;
            tmp.clone(&(s_context->tmpDeclType));
            s_context->clearContext();
            s_context->addParawithoutid(tmp);
            break;
        }
        default:{
            //std::cout<<"error in ParamDectionAst: nodetype is invalid"<<endl;
            LogiMsg::logi("error in ParamDectionAst: nodetype is invalid", getLineno());

            stopWalk();
            return ;
        }
    }


}
