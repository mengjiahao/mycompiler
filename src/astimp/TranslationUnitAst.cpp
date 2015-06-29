#include "../../include/ast/TranslationUnitAst.h"

TranslationUnitAst::TranslationUnitAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void TranslationUnitAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    //std::cout << "walk in TranslationUnitAst" << std::endl;
    LogiMsg::logi("walk in TranslationUnitAst", getLineno());

    for (int i = 0; i < childs.size(); ++i) {
        if (NULL != childs.at(i)) {
            childs.at(i)->walk();
            if (checkIsNotWalking()) {
                return ;
            }
        }
    }
}
