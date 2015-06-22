#include "../../include/ast/DirDectorAst.h"

DirDectorAst::DirDectorAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void DirDectorAst::walk()
{
    switch(nodeType){
        case T_CDIRDECTOR_ID:{
            childs.at(0)->walk();
            break;
        }
        case T_CDIRDECTOR_DIRDECTOR_ARRAY_CONSTEXP:{

            break;
        }
        case T_CDIRDECTOR_DIRDECTOR_ARRAY_VOID:{

            break;
        }
        case T_CDIRDECTOR_DIRDECTOR_CALL_PARAMTYPELIST:{
            if (childs.at(0)->nodeType != T_CDIRDECTOR_ID)
            {
                std::cout<<"error in T_CDIRDECTOR_DIRDECTOR_CALL_PARAMTYPELIST: the children's type is not T_CDIRDECTOR_ID at line "
                <<getLineno()<<std::endl;
                exit(0);
            }

            childs.at(0)->walk();

            string tmp1 = s_context->tmpIdenName;

            childs.at(1)->walk();

            s_context->tmpIdenName = tmp1;
            s_context->isFunc = true;
            break;
        }
        case T_CDIRDECTOR_DIRDECTOR_CALL_EXP:{

            break;
        }
        case T_CDIRDECTOR_DIRDECTOR_CALL_VOID:{
            if (childs.at(0)->nodeType != T_CDIRDECTOR_ID)
            {
                std::cout<<"error in T_CDIRDECTOR_DIRDECTOR_CALL_VOID: the children's type is not T_CDIRDECTOR_ID at line "
                <<getLineno()<<std::endl;
                exit(0);
            }

            childs.at(0)->walk();

            string tmp1=s_context->tmpIdenName;
            s_context->clearContext();
            s_context->tmpIdenName=tmp1;
            s_context->isFunc=true;
            break;
        }
        default:{
            std::cout<<"error in DirDectorAst: nodetype is invalid"<<std::endl;
            exit(0);
        }
    }
}
