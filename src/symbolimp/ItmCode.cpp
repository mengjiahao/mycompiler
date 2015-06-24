#include "../../include/symbol/ItmCode.h"
#include "../../include/symbol/Symbol.h"
#include "../../include/symbol/Scope.h"


#include <iostream>
#include <fstream>
#include <list>
#include <vector>


using namespace std;

/***********************************Reg**********************************************/
int Reg::RegTypeNo = 13;
int Reg::RegValueTypeNo = 10;
Reg Reg::regs[13][10];


int Reg::getRegType()
{
    return regType;
}

int Reg::getRegValueType()
{
    return regValueType;
}


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
    codeId = 0;
    iRType = ItmCode::IR_INVALID;
    t1 = ItmCode::OPR_INVALID;
    v1 = NULL;
    t2 = ItmCode::OPR_INVALID;
    v2 = NULL;
    t3 = ItmCode::OPR_INVALID;
    v3 = NULL;
}

ItmCode::ItmCode(IRtype iRType_t,
OperandType t1_t, void* v1_t,
OperandType t2_t, void* v2_t,
OperandType t3_t, void* v3_t)
{
    codeId = 0;
    iRType = iRType_t;
    t1 = t1_t;
    v1 = v1_t;
    t2 = t2_t;
    v2 = v2_t;
    t3 = t3_t;
    v3 = v3_t;
}

ItmCode::~ItmCode()
{
    codeId = 0;
    iRType = ItmCode::IR_INVALID;
    t1 = ItmCode::OPR_INVALID;
    v1 = NULL;
    t2 = ItmCode::OPR_INVALID;
    v2 = NULL;
    t3 = ItmCode::OPR_INVALID;
    v3 = NULL;
}

void ItmCode::setCodeId()
{
    static unsigned long s_codeId = 0;
    codeId = ++s_codeId;
}

unsigned long ItmCode::getCodeId()
{
    return codeId;
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

void ItmCode::printOperand(ofstream& ofs_t, OperandType opType_t, void *op_t)
{
    if (ofs_t.is_open()) {

        switch(opType_t) {
        case OPR_SYMBOL: {
            ofs_t << "Symbol(" << ((Symbol *)op_t)->getSymbolId()
            << "): " << ((Symbol *)op_t)->getSymbolName();
            break;
        }
        case OPR_SCOPE: {
            ofs_t << "Scope(" << ((Scope *)op_t)->getScopeId()
            << "): " << ((Scope *)op_t)->getScopeId();
            break;
        }
        case OPR_ARGLIST: {
            ofs_t << "ARGLIST(";
            list<Symbol *> *lop_t = (list<Symbol *>*)op_t;
            if (NULL != lop_t) {
                list<Symbol *>::iterator itr;
                for (itr = (*lop_t).begin(); itr != (*lop_t).end(); ++itr) {
                    if (NULL != *itr) {
                        ofs_t << (*itr)->getSymbolName() << "("
                        << (*itr)->getSymbolId() << ")--";
                    }
                }
            }
            ofs_t << ")";
            break;
        }
        case OPR_REGISTER: {
            ofs_t << "Reg(";
            ofs_t << ((Reg *)op_t)->getRegType();
            ofs_t << "): " << ((Reg *)op_t)->getRegValueType();
            break;
        }
        default: {
            ofs_t << "NULL";
            break;
        }


        }


    } else {
        cout << "error in printOperand(): IR.txt is not open" << endl;
    }
}


void ItmCode::printItmCode(ofstream &ofs_t)
{
    if (ofs_t.is_open()) {

        ofs_t << codeId << ": { " << iRType << " , ";
        printOperand(ofs_t, t1, v1);
        ofs_t << " , ";
        printOperand(ofs_t, t2, v2);
        ofs_t << " , ";
        printOperand(ofs_t, t3, v3);
        ofs_t << " }\n";

    } else {
        cout << "error in printItmCode(): IR.txt is not open" << endl;
    }
}


void ItmCode::printAllItmCode()
{
    ofstream ofs;
    cout << ">>>printItmCode in IR.txt" << endl;

    ofs.open("IR.txt");

    vector<ItmCode *>::iterator itr;
    for (itr = s_allItmCode.begin(); itr != s_allItmCode.end(); ++itr) {
        if (NULL != *itr) {
            (*itr)->printItmCode(ofs);
        }
    }


    ofs.close();
}
