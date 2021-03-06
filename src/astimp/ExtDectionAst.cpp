#include "../../include/ast/ExtDectionAst.h"

ExtDectionAst::ExtDectionAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ExtDectionAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    //std::cout << "walk in ExtDectionAst" << endl;
    LogiMsg::logi("walk in ExtDectionAst", getLineno());

    for(int i = 0; i < childs.size(); ++i) {

        if (NULL != childs.at(i)) {
            (childs.at(i))->walk();
            if (checkIsNotWalking()) {
                return ;
            }
        }
    }
}

