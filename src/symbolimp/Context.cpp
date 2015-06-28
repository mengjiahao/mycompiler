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
    tmpExpListPointer = NULL;



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
    tmpExpListPointer = NULL;

    tmpTrueLabelList.clear();
    tmpFalseLabelList.clear();
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

}

void Context::clearAllContext()
{
    clearContext();
    clearSingleOperand();
    clearExpList();
    clearLabelList();
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

void Context::addToExpList(void* m)
{
    if (NULL != m) {
        tmpExpList.push_back(m);
    }
}

void* Context::getExpListLast()
{
    if (tmpExpList.empty()) {
        return NULL;
    }

    return tmpExpList.back();
}


void Context::clearExpList()
{
    tmpExpList.clear();
}

void Context::clearSingleOperand()
{
    tmpExpReg = NULL;
    tmpExpSymbol = NULL;
    tmpExpListPointer = NULL;

    tmpOpType = ItmCode::OPR_INVALID;
}

void Context::resetSingleOperand(void *p, ItmCode::OperandType tmpOpType_t)
{
    switch(tmpOpType) {
    case ItmCode::OPR_SYMBOL: {
        tmpOpType = tmpOpType_t;
        tmpExpSymbol = (Symbol *)p;
        break;
    }

    case ItmCode::OPR_REGISTER: {
        tmpOpType = tmpOpType_t;
        tmpExpReg = (Reg *)p;
        break;
    }

    case ItmCode::OPR_CLASS_REFLIST_POINTER: {
        tmpOpType = tmpOpType_t;
        tmpExpListPointer = (vector<void *> *)p;
        break;
    }

    default: {
        //clearSingleOperand();
        break;
    }
    }
}


void Context::addToTrueLabelList(ItmCode* newCode_t)
{
    if (NULL != newCode_t) {
        tmpTrueLabelList.push_back(newCode_t);

    }

}

void Context::addToFalseLabelList(ItmCode* newCode_t)
{
    if (NULL != newCode_t) {
        tmpFalseLabelList.push_back(newCode_t);
    }
}

void Context::clearLabelList()
{
    tmpTrueLabelList.clear();
    tmpFalseLabelList.clear();
}

void Context::backFillTrueLabelList(Symbol* trueLabel_t)
{
    if (NULL == trueLabel_t)
        return ;

    list<ItmCode *>::iterator itr;
    for (itr = tmpTrueLabelList.begin(); itr != tmpTrueLabelList.end(); ++itr) {
        (*itr)->setTargetLabel(trueLabel_t);
    }
    tmpTrueLabelList.clear();
}

void Context::backFillFalseLabelList(Symbol* falseLabel_t)
{
    if (NULL == falseLabel_t)
        return ;

    list<ItmCode *>::iterator itr;
    for (itr = tmpFalseLabelList.begin(); itr != tmpFalseLabelList.end(); ++itr) {
        (*itr)->setTargetLabel(falseLabel_t);
    }
    tmpFalseLabelList.clear();
}







