#include "../../include/symbol/ItmCode.h"

#include <iostream>
#include <list>
#include <vector>

using namespace std;

/***********************************Reg**********************************************/
int Reg::RegTypeNo = 13;
int Reg::RegValueTypeNo = 10;
Reg Reg::regs[13][10];

void Reg::initRegs()
{
    int i, j;
    for(i = 0; i < RegTypeNo; ++i) {
        for(j = 0; j < RegValueTypeNo; ++j) {
            regs[i][j].regType = i;
            regs[i][j].regValueType = j;
        }
    }
}

Reg* Reg::getReg(RegType regType_t, RegValueType regValueType_t)
{
    if ( (regType_t >= 0) && (regType_t < RegTypeNo)
    && (regValueType_t >= 0) && (regValueType_t < RegValueTypeNo) ) {
        return &regs[regType_t][regValueType_t];
    }

    return NULL;
}





/*********************************ItmCode********************************************/
list< list<Symbol *>* > ItmCode::s_allArgList;
vector<ItmCode *> ItmCode::s_allItmCode;

ItmCode::ItmCode()
{
    iRType = ItmCode::IR_INVALID;
}

ItmCode::ItmCode(IRtype iRType_t, OperandType t1_t, void* v1_t, OperandType t2_t, void* v2_t, OperandType t3_t, void* v3_t)
{
    iRType = iRType_t;
    t1 = t1_t;
    v1 = v1_t;
    t2 = t2_t;
    v2 = v2_t;
    t3 = t3_t;
    v3 = v3_t;
}

void ItmCode::addToAllArgList(list<Symbol* >* argList_t)
{
    if (NULL != argList_t) {
        s_allArgList.push_back(argList_t);
    }
}

void ItmCode::freeAllArgList()
{
    list< list<Symbol* >* >::iterator itr;

    int i;

    for(i = 0, itr = s_allArgList.begin(); itr != s_allArgList.end(); ++itr) {
        delete(*itr);
        ++i;
    }

    cout << "AllArgList's Num is " << i << endl;

    s_allArgList.clear();
}


void ItmCode::addToAllItmCode(ItmCode* itmCode_t)
{
    if (NULL != itmCode_t) {
        s_allItmCode.push_back(itmCode_t);
    }
}

void ItmCode::freeAllItmCode()
{
    vector<ItmCode *>::iterator itr;

    int i;

    for(i = 0, itr = s_allItmCode.begin(); itr != s_allItmCode.end(); ++itr) {
        delete(*itr);
        ++i;
    }

    cout << "AllItmCode's Num is " << i << endl;

    s_allItmCode.clear();
}