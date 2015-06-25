#include "../../include/symbol/Context.h"


using namespace std;

/*****************************Context***********************************************/
Context::Context()
{
    tmpDeclType.clearTypeClass();
    tmpIdenName = "";
    tmpParaTypeList.clear();
    tmpParaWithIdList.clear();
    tmpParaWithIdNum = 0;
    tmpParaWithoutIdNum = 0;
    isFunc = false;

    tmpClassScope = NULL;

    tmpOpType = ItmCode::OPR_INVALID;
    tmpExpReg = NULL;
    tmpExpSymbol = NULL;

    tmpTrueLabel = NULL;
    tmpFalseLabel = NULL;


}

Context::~Context()
{
    tmpDeclType.clearTypeClass();
    tmpIdenName = "";
    tmpParaTypeList.clear();
    tmpParaWithIdList.clear();
    tmpParaWithIdNum = 0;
    tmpParaWithoutIdNum = 0;
    isFunc = false;

    tmpClassScope = NULL;

    tmpOpType = ItmCode::OPR_INVALID;
    tmpExpReg = NULL;
    tmpExpSymbol = NULL;

    tmpTrueLabel = NULL;
    tmpFalseLabel = NULL;
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

    tmpClassScope = NULL;

    tmpOpType = ItmCode::OPR_INVALID;
    tmpExpReg = NULL;
    tmpExpSymbol = NULL;

    tmpTrueLabel = NULL;
    tmpFalseLabel = NULL;

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

void Context::addToArgExpList(void* m)
{
    if (NULL != m) {
        tmpArgExpList.push_back(m);
        ++tmpArgExpNum;
    }
}


