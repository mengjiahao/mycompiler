#include "../../include/symbol/Context.h"
#include "../../include/symbol/ItmCode.h"

using namespace std;

/*****************************Context***********************************************/
Context::Context()
{

}

Context::~Context()
{

}

void Context::clearContext()
{
    tmpDeclType.clearTypeClass();
    tmpIdenName = "";
    tmpParaTypeList.clear();
    tmpParaWithIdList.clear();
    tmpParaWithIdNum = 0;
    tmpParaWithoutIdNum = 0;
    isFunc = false;
}

void Context::addParawithid(Symbol m)
{
    tmpParaWithIdList.push_back(m);
    ++tmpParaWithIdNum;
}

void Context::addParawithoutid(TypeClass m)
{
    tmpParaTypeList.push_back(m);
    ++tmpParaWithoutIdNum;
}

