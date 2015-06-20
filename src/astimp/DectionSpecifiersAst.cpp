#include "../../include/ast/DectionSpecifiersAst.h"

DectionSpecifiersAst::DectionSpecifiersAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void DectionSpecifiersAst::walk()
{
    cout << "DectionSpecifiersAstWalk" << endl;
    TypeClass *tmp[getChildsNo()];
    for (int i=0;i<getChildsNo();i++)
    {
        tmp[i]=new TypeClass();
    }
    for (int i=0;i<getChildsNo();i++)
    {
        childs.at(0)->walk();
        tmp[i]->clone(&(s_context->tmpDeclType));
    }
    judgetType(tmp[0],tmp[1]);
    tmp[0]->storageType|=tmp[1]->storageType;
    tmp[0]->typeQfType|=tmp[1]->typeQfType;
    tmp[0]->typeSfType|=tmp[1]->typeSfType;
    s_context->clearContext();
    s_context->tmpDeclType.clone(tmp[0]);
    for (int i=0;i<getChildsNo();i++)
    {
        delete tmp[i];
    }
}

void DectionSpecifiersAst::judgetType(TypeClass *type1_t,TypeClass *type2_t)
{
    if ((type1_t->getStorageType()!=0) && (type2_t->getStorageType()!=0))
    {
        std::cout<<"error: redundant storage type at line: "<<getLineno()<<std::endl;
        exit(0);
    }
    if ((type1_t->getTypeSfType()&TypeClass::SF_SIGNED) || (type1_t->getTypeSfType()&TypeClass::SF_UNSIGNED) )
    {
        if ((type2_t->getTypeSfType()&TypeClass::SF_UNSIGNED) || (type2_t->getTypeSfType()&TypeClass::SF_SIGNED) || (type2_t->getTypeSfType()&TypeClass::SF_DOUBLE) || (type2_t->getTypeSfType()&TypeClass::SF_FLOAT)  || (type2_t->getTypeSfType()&TypeClass::SF_VOID))
        {
           std::cout<<"error: wrong type at line: "<<getLineno()<<std::endl;
           exit(0);
        }
    }
    if ((type2_t->getTypeSfType()&TypeClass::SF_SIGNED) || (type2_t->getTypeSfType()&TypeClass::SF_UNSIGNED) )
    {
        if ((type1_t->getTypeSfType()&TypeClass::SF_UNSIGNED) || (type1_t->getTypeSfType()&TypeClass::SF_SIGNED) || (type1_t->getTypeSfType()&TypeClass::SF_DOUBLE) || (type1_t->getTypeSfType()&TypeClass::SF_FLOAT)  || (type1_t->getTypeSfType()&TypeClass::SF_VOID))
        {
           std::cout<<"error: wrong type at line: "<<getLineno()<<std::endl;
           exit(0);
        }
    }
    if ((type1_t->getTypeSfType()&TypeClass::SF_FLOAT) || (type1_t->getTypeSfType()&TypeClass::SF_DOUBLE) )
    {
        if (type2_t->getTypeSfType()!=TypeClass::SF_INVALID)
        {
           std::cout<<"error: wrong type at line: "<<getLineno()<<std::endl;
           exit(0);
        }
    }
    if ((type2_t->getTypeSfType()&TypeClass::SF_FLOAT) || (type2_t->getTypeSfType()&TypeClass::SF_DOUBLE) )
    {
        if (type1_t->getTypeSfType()!=TypeClass::SF_INVALID)
        {
           std::cout<<"error: wrong type at line: "<<getLineno()<<std::endl;
           exit(0);
        }
    }
    if (type1_t->getTypeSfType()&TypeClass::SF_VOID)
    {
        if (type2_t->getTypeSfType()!=TypeClass::SF_INVALID)
        {
           std::cout<<"error: wrong type at line: "<<getLineno()<<std::endl;
           exit(0);
        }
    }
    if (type2_t->getTypeSfType()&TypeClass::SF_VOID)
    {
        if (type1_t->getTypeSfType()!=TypeClass::SF_INVALID)
        {
           std::cout<<"error: wrong type at line: "<<getLineno()<<std::endl;
           exit(0);
        }
    }
    if (type1_t->getTypeSfType()&TypeClass::SF_LONG)
    {
        if (type2_t->getTypeSfType()&TypeClass::SF_SHORT)
        {
           std::cout<<"error: wrong type at line: "<<getLineno()<<std::endl;
           exit(0);
        }
    }
    if (type2_t->getTypeSfType()&TypeClass::SF_LONG)
    {
        if (type1_t->getTypeSfType()&TypeClass::SF_SHORT)
        {
           std::cout<<"error: wrong type at line: "<<getLineno()<<std::endl;
           exit(0);
        }
    }
    if (type1_t->getTypeSfType()&TypeClass::SF_CHAR)
    {
        if ((type2_t->getTypeSfType()&TypeClass::SF_SHORT) || (type2_t->getTypeSfType()&TypeClass::SF_LONG) || (type2_t->getTypeSfType()&TypeClass::SF_INT))
        {
            std::cout<<"error: wrong type at line: "<<getLineno()<<std::endl;
            exit(0);
        }
    }
    if (type2_t->getTypeSfType()&TypeClass::SF_CHAR)
    {
        if ((type1_t->getTypeSfType()&TypeClass::SF_SHORT) || (type1_t->getTypeSfType()&TypeClass::SF_LONG) || (type1_t->getTypeSfType()&TypeClass::SF_INT))
        {
            std::cout<<"error: wrong type at line: "<<getLineno()<<std::endl;
            exit(0);
        }
    }
    if (type1_t->getTypeSfType() & type2_t->getTypeSfType())
    {
        std::cout<<"error: redundant storage type at line: "<<getLineno()<<std::endl;
        exit(0);
    }
    if (type1_t->getTypeQfType() & type2_t->getTypeQfType())
    {
        std::cout<<"error: redundant storage type at line: "<<getLineno()<<std::endl;
        exit(0);
    }
}





