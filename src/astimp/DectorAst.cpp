#include "../../include/ast/DectorAst.h"

DectorAst::DectorAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void DectorAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    //std::cout << "error in DectorAst: we do not support '*' at line " << getLineno() << std::endl;
    LogiMsg::logi("error in DectorAst: we do not support '*'", getLineno());
    stopWalk();

}
