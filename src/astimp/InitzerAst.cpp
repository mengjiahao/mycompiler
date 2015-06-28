#include "../../include/ast/InitzerAst.h"

InitzerAst::InitzerAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void InitzerAst::walk()
{
    switch (nodeType){
        case NodeAst::T_CINITZER_ASSIGNEXP:{

            childs.at(0)->walk();
            break;
        }
        case NodeAst::T_CINITZER_CINITZERLIST:{

            break;
        }

    }
}
