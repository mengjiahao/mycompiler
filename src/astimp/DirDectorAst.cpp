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
            if (childs.at(0)->nodeType!=T_CDIRDECTOR_ID)
            {
                std::cout<<"error: the name of function is not a identifier at line "<<getLineno()<<std::endl;
                exit(0);
            }
            childs.at(0)->walk();
            string tmp1=s_context->tmpIdenName;
            childs.at(1)->walk();
            s_context->tmpIdenName=tmp1;
            break;
        }
        case T_CDIRDECTOR_DIRDECTOR_CALL_EXP:{

            break;
        }
        case T_CDIRDECTOR_DIRDECTOR_CALL_VOID:{
            if (childs.at(0)->nodeType!=T_CDIRDECTOR_ID)
            {
                std::cout<<"error: the name of function is not a identifier at line "<<getLineno()<<std::endl;
                exit(0);
            }
            childs.at(0)->walk();
            string tmp1=s_context->tmpIdenName;
            s_context->clearContext();
            s_context->tmpIdenName=tmp1;

            break;
        }
        default:{
            std::cout<<"unknown nodetype in DirDectorAst"<<endl;
            exit(0);
        }
    }
}
