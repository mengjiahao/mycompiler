#include "../../include/ast/DectionSpecifiersAst.h"

DectionSpecifiersAst::DectionSpecifiersAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void DectionSpecifiersAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    std::cout << "walk in DectionSpecifiersAst" << endl;

    TypeClass *tmp[getChildsNo()];
    for (int i = 0; i < getChildsNo(); i++)
    {
        tmp[i] = new TypeClass();
    }

    for (int i = 0; i<getChildsNo(); i++)
    {
        childs.at(0)->walk();

        tmp[i]->clone(&(s_context->tmpDeclType));
    }

    if (tmp[0]->scopeType || tmp[1]->scopeType)
    {
        std::cout<<"error at DectionSpecifiersAst: class type should not use with other type at line "
        <<getLineno()<<std::endl;
        stopWalk();
        return ;
    }
    TypeClass::judgetType(tmp[0],tmp[1], getLineno());
    tmp[0]->storageType |= tmp[1]->storageType;
    tmp[0]->typeQfType |= tmp[1]->typeQfType;
    tmp[0]->typeSfType |= tmp[1]->typeSfType;

    s_context->clearContext();
    s_context->tmpDeclType.clone(tmp[0]);

    for (int i = 0; i<getChildsNo(); i++)
    {
        delete tmp[i];
    }


}







