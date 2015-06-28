#include "../../include/ast/InitDectorAst.h"

InitDectorAst::InitDectorAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}


void InitDectorAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch (nodeType){
        case T_CINITDECTOR_DECTOR:{
            std::cout << "walk in T_CINITDECTOR_DECTOR" << endl;

            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }


            break;
        }
        case T_CINITDECTOR_ASSGIN_INITZER:{
            std::cout << "walk in T_CINITDECTOR_ASSGIN_INITZER" << endl;

            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }
            string tmpName = s_context->tmpIdenName;

            childs.at(1)->walk();
            if (checkIsNotWalking()) {
                return ;
            }
            s_context->tmpIdenName=tmpName;
            s_context->isFunc = false;



            break;
        }
        default:{
            std::cout<<"error in InitDectorAst: nodetype is invalid"<<std::endl;
            stopWalk();
            return ;
        }
    }

}
