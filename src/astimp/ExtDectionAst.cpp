#include "../../include/ast/ExtDectionAst.h"

ExtDectionAst::ExtDectionAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ExtDectionAst::walk()
{
    cout << "ExtDectionAstWalk" << endl;

    for(int i = 0; i < childs.size(); ++i) {

        if (NULL != childs.at(i)) {
            childs.at(i)->walk();
            cout << "ExtDectionAstWalkOK" << endl;
        }
    }
}

