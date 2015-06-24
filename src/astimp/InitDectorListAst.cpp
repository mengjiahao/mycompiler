#include "../../include/ast/InitDectorListAst.h"

InitDectorListAst::InitDectorListAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void InitDectorListAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    std::cout << "error in InitDectorListAst: we do not support this type of definition at line " << getLineno() << std::endl;
    stopWalk();

}
