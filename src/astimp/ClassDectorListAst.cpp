#include "../../include/ast/ClassDectorListAst.h"

ClassDectorListAst::ClassDectorListAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ClassDectorListAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    /*std::cout << "sorry in ClassDectorListAst: we do not support this kind of declaration at line "
    << getLineno() << std::endl;*/

    LogiMsg::logi("sorry in ClassDectorListAst: we do not support this kind of declaration", getLineno());

    stopWalk();
}
