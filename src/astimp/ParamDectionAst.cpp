#include "../../include/ast/ParamDectionAst.h"

ParamDectionAst::ParamDectionAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ParamDectionAst::walk()
{
    switch(nodeType){
        case T_CPARAMDECTION_DECTIONSFS_DECTOR:{
            if (childs.at(1)->nodeType!=T_CDIRDECTOR_ID)
            {
                std::cout<<"error: the argument of function is not identifier at line "<<getLineno()<<std::endl;
                exit(0);
            }
            childs.at(0)->walk();
            TypeClass *tmp=new TypeClass();
            tmp->clone(&(s_context->tmpDeclType));
            childs.at(1)->walk();
            Symbol tmpsymbol(Symbol::SYMBOL_VAR);
            tmpsymbol.symbolName=s_context->tmpIdenName;
            tmpsymbol.typeClass.clone(tmp);
            s_context->clearContext();
            s_context->addParawithid(tmpsymbol);
            delete tmp;
            break;
        }
        case T_CPARAMDECTION_DECTIONSFS:{

            childs.at(0)->walk();
            TypeClass *tmp=new TypeClass();
            tmp->clone(&(s_context->tmpDeclType));
            s_context->clearContext();
            s_context->addParawithoutid(*tmp);
            delete tmp;
            break;
        }
        default:{
            std::cout<<"unknown nodetype in ParamDectionAst"<<endl;
            exit(0);
        }
    }
}
