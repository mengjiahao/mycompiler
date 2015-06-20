#include "../../include/ast/DectionSpecifiersAst.h"

DectionSpecifiersAst::DectionSpecifiersAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void DectionSpecifiersAst::walk()
{
    cout << "DectionSpecifiersAstWalk" << endl;

    for (int i = 0; i < childs.size(); ++i) {
        if (NULL != childs.at(i)) {
            childs.at(i)->walk();
        }
    }

}
