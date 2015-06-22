#include "../../include/ast/InitDectorAst.h"

InitDectorAst::InitDectorAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}


void InitDectorAst::walk()
{
    switch (nodeType){
        case T_CINITDECTOR_DECTOR:{

            childs.at(0)->walk();

            break;
        }
        case T_CINITDECTOR_ASSGIN_INITZER:{
            break;
        }
        default:{
            std::cout<<"error in InitDectorAst: nodetype is invalid"<<std::endl;
            exit(0);
        }
    }
}
