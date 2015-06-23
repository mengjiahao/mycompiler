#include "../../include/ast/ExtDectionAst.h"

ExtDectionAst::ExtDectionAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ExtDectionAst::walk()
{
    std::cout << "walk in ExtDectionAst" << endl;

    for(int i = 0; i < childs.size(); ++i) {

        if (NULL != childs.at(i)) {
            (childs.at(i))->walk();
        }
    }
}

