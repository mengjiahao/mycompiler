#include "../../include/ast/ClassDectorListAst.h"

ClassDectorListAst::ClassDectorListAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ClassDectorListAst::walk()
{
    std::cout << "sorry, we do not support this kind of declaration at line " << getLineno() << std::endl;
    exit(0);
}
