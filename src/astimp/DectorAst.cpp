#include "../../include/ast/DectorAst.h"

DectorAst::DectorAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void DectorAst::walk()
{
    std::cout << "sorry, in DectorAst we do not support '*' at line " << getLineno() << std::endl;
    exit(0);
}
