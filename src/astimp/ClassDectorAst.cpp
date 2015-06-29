#include "../../include/ast/ClassDectorAst.h"

ClassDectorAst::ClassDectorAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ClassDectorAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    if (nodeType != T_CCLASSDECTOR_DECTOR)
    {
        //std::cout << "error: nodetype is not T_CCLASSDECTOR_DECTOR in ClassDectorAst" << std::endl;
        LogiMsg::logi("error: nodetype is not T_CCLASSDECTOR_DECTOR in ClassDectorAst", getLineno());
        stopWalk();
        return ;
    }
    //std::cout << "walk in T_CCLASSDECTOR_DECTOR" << endl;
    LogiMsg::logi("walk in T_CCLASSDECTOR_DECTOR", getLineno());

    childs.at(0)->walk();
    if (checkIsNotWalking()) {
        return ;
    }

}
