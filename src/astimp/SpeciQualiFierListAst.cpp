#include "../../include/ast/SpeciQualiFierListAst.h"

SpeciQualiFierListAst::SpeciQualiFierListAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void SpeciQualiFierListAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    //std::cout << "walk in SpeciQualiFierListAst" << endl;
    LogiMsg::logi("walk in SpeciQualiFierListAst", getLineno());

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

    if (2 != getChildsNo()) {
        /*std::cout<<"error in SpeciQualiFierListAst: SpeciQualiFierListAst doesn't have 2 children"
        << std::endl;*/
        LogiMsg::logi("error in SpeciQualiFierListAst: SpeciQualiFierListAst doesn't have 2 children", getLineno());
        stopWalk();
        return ;
    }

    /*if (tmp[0]->scopeType || tmp[1]->scopeType)
    {
        std::cout<<"error in SpeciQualiFierListAst: class type should not be used with other type at line "
        <<getLineno()<<std::endl;
        stopWalk();
        return ;
    }*/

    if(false == TypeClass::judgeType(tmp[0],tmp[1], getLineno())) {
        stopWalk();
        return ;
    }


    tmp[0]->storageType |= tmp[1]->storageType;
    tmp[0]->typeQfType |= tmp[1]->typeQfType;
    tmp[0]->typeSfType |= tmp[1]->typeSfType;

    s_context->clearContext();
    s_context->tmpDeclType.clone(tmp[0]);

    for (int i = 0; i < getChildsNo(); i++)
    {
        delete tmp[i];
    }

}
