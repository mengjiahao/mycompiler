#include "../../include/symbol/ItmCode.h"
#include "../../include/symbol/Symbol.h"
#include "../../include/symbol/Scope.h"
#include "../../include/LogiMsg.h"


#include <iostream>
#include <fstream>
#include <list>
#include <vector>


using namespace std;

/***********************************Reg**********************************************/
Reg Reg::s_regs[4][16];

void Reg::setRegIndex(int regIndex_t)
{
    regIndex = regIndex_t;
}

int Reg::getRegIndex()
{
    return regIndex;
}

void Reg::setTypeSfType(int typeSfType_t)
{
    typeSfType = typeSfType_t;
}

int Reg::getTypeSfType()
{
    return typeSfType;
}

int Reg::convSfTypeToIndex(int typeSfType_t)
{
    int index = 0;

    switch(typeSfType_t) {
    case TypeClass::SF_INVALID: {
        index = 0;
        break;
    }
    case TypeClass::SF_VOID: {
        index = 1;
        break;
    }
    case TypeClass::SF_CHAR: {
        index = 2;
        break;
    }
    case TypeClass::SF_CHAR | TypeClass::SF_SIGNED: {
        index = 3;
        break;
    }
    case TypeClass::SF_CHAR | TypeClass::SF_UNSIGNED: {
        index = 4;
        break;
    }
    case TypeClass::SF_SHORT: {
        index = 5;
        break;
    }
    case TypeClass::SF_SHORT | TypeClass::SF_SIGNED: {
        index = 6;
        break;
    }
    case TypeClass::SF_SHORT | TypeClass::SF_UNSIGNED: {
        index = 7;
        break;
    }
    case TypeClass::SF_INT: {
        index = 8;
        break;
    }
    case TypeClass::SF_INT | TypeClass::SF_SIGNED: {
        index = 9;
        break;
    }
    case TypeClass::SF_INT | TypeClass::SF_UNSIGNED: {
        index = 10;
        break;
    }
    case TypeClass::SF_LONG: {
        index = 11;
        break;
    }
    case TypeClass::SF_LONG | TypeClass::SF_SIGNED: {
        index = 12;
        break;
    }
    case TypeClass::SF_LONG | TypeClass::SF_UNSIGNED: {
        index = 13;
        break;
    }
    case TypeClass::SF_FLOAT: {
        index = 14;
        break;
    }
    case TypeClass::SF_DOUBLE: {
        index = 15;
        break;
    }
    default: {
        LogiMsg::logi("error in Reg::convSfTypeToIndex(): typeSfType_t is invalid");
        index = 0;
        break;
    }
    }

    if (index < 0 || index >= 16) {
        index = 0;
    }

    return index;
}


void Reg::initRegs()
{
    Reg tmpReg;

    static int s_regNo = 4;

    int i;
    for (i = 0; i < s_regNo; ++i) {

        tmpReg.setRegIndex(i);

        tmpReg.setTypeSfType(TypeClass::SF_INVALID);
        s_regs[i][convSfTypeToIndex(TypeClass::SF_INVALID)] = tmpReg;

        tmpReg.setTypeSfType(TypeClass::SF_VOID);
        s_regs[i][convSfTypeToIndex(TypeClass::SF_VOID)] = tmpReg;

        tmpReg.setTypeSfType(TypeClass::SF_CHAR);
        s_regs[i][convSfTypeToIndex(TypeClass::SF_CHAR)] = tmpReg;

        tmpReg.setTypeSfType(TypeClass::SF_CHAR | TypeClass::SF_SIGNED);
        s_regs[i][convSfTypeToIndex(TypeClass::SF_CHAR | TypeClass::SF_SIGNED)] = tmpReg;

        tmpReg.setTypeSfType(TypeClass::SF_CHAR | TypeClass::SF_UNSIGNED);
        s_regs[i][convSfTypeToIndex(TypeClass::SF_CHAR | TypeClass::SF_UNSIGNED)] = tmpReg;

        tmpReg.setTypeSfType(TypeClass::SF_SHORT);
        s_regs[i][convSfTypeToIndex(TypeClass::SF_SHORT)] = tmpReg;

        tmpReg.setTypeSfType(TypeClass::SF_SHORT | TypeClass::SF_SIGNED);
        s_regs[i][convSfTypeToIndex(TypeClass::SF_SHORT | TypeClass::SF_SIGNED)] = tmpReg;

        tmpReg.setTypeSfType(TypeClass::SF_SHORT | TypeClass::SF_UNSIGNED);
        s_regs[i][convSfTypeToIndex(TypeClass::SF_SHORT | TypeClass::SF_UNSIGNED)] = tmpReg;

        tmpReg.setTypeSfType(TypeClass::SF_INT);
        s_regs[i][convSfTypeToIndex(TypeClass::SF_INT)] = tmpReg;

        tmpReg.setTypeSfType(TypeClass::SF_INT | TypeClass::SF_SIGNED);
        s_regs[i][convSfTypeToIndex(TypeClass::SF_INT | TypeClass::SF_SIGNED)] = tmpReg;

        tmpReg.setTypeSfType(TypeClass::SF_INT | TypeClass::SF_UNSIGNED);
        s_regs[i][convSfTypeToIndex(TypeClass::SF_INT | TypeClass::SF_UNSIGNED)] = tmpReg;

        tmpReg.setTypeSfType(TypeClass::SF_LONG);
        s_regs[i][convSfTypeToIndex(TypeClass::SF_LONG)] = tmpReg;

        tmpReg.setTypeSfType(TypeClass::SF_LONG | TypeClass::SF_SIGNED);
        s_regs[i][convSfTypeToIndex(TypeClass::SF_LONG | TypeClass::SF_SIGNED)] = tmpReg;

        tmpReg.setTypeSfType(TypeClass::SF_LONG | TypeClass::SF_UNSIGNED);
        s_regs[i][convSfTypeToIndex(TypeClass::SF_LONG | TypeClass::SF_UNSIGNED)] = tmpReg;

        tmpReg.setTypeSfType(TypeClass::SF_FLOAT);
        s_regs[i][convSfTypeToIndex(TypeClass::SF_FLOAT)] = tmpReg;

        tmpReg.setTypeSfType(TypeClass::SF_DOUBLE);
        s_regs[i][convSfTypeToIndex(TypeClass::SF_DOUBLE)] = tmpReg;
    }
}




Reg* Reg::getReg(int regIndex_t, int sf_t)
{
    if (0 <= regIndex_t && regIndex_t < 4) {
        return &(s_regs[regIndex_t][convSfTypeToIndex(sf_t)]);
    }

    return NULL;
}




/*********************************ItmCode********************************************/
list< vector<void *>* > ItmCode::s_allExpList;
vector<ItmCode *> ItmCode::s_allItmCode;
int ItmCode::totalItmNo=0;

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
    ItmNo = 0;
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
    ItmNo = 0;
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
    ItmNo = 0;
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

vector<void* >* ItmCode::copyVectorToAllExpList(vector<void* > &vargList_t)
{
    vector<void* > *newArgList = new vector<void* >();
    vector<void* >::iterator itr;
    for(itr = vargList_t.begin(); vargList_t.end() != itr; ++itr) {
        newArgList->push_back(*itr);
    }

    addToAllExpList(newArgList);
    return newArgList;
}


void ItmCode::addToAllExpList(vector<void* >* expList_t)
{
    if (NULL != expList_t) {
        s_allExpList.push_back(expList_t);
    }
}

void ItmCode::freeAllExpList()
{
    list< vector<void* >* >::iterator itr;

    int i;

    for(i = 0, itr = s_allExpList.begin(); itr != s_allExpList.end(); ++itr) {
        if ( NULL != (*itr) ) {
            (*itr)->clear();
            delete(*itr);
        }

        ++i;
    }

    cout << "AllArgList's Num is " << i << endl;

    s_allExpList.clear();
}



void ItmCode::addToAllItmCode(ItmCode* itmCode_t)
{
    if (NULL != itmCode_t) {
        s_allItmCode.push_back(itmCode_t);
        totalItmNo++;
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

            ofs_t << ")";
            break;
        }
        case OPR_REGISTER: {
            ofs_t << "Reg(";
            //ofs_t << ((Reg *)op_t)->getRegType();
            ofs_t << "): " << ((Reg *)op_t)->getTypeSfType();
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


int ItmCode::getTotalItemNo()
{
    return totalItmNo;
}

void ItmCode::setItmNo(int itmNo_t)
{
    ItmNo=itmNo_t;
}

int ItmCode::getItmNo()
{
    return ItmNo;
}

void ItmCode::genCode(IRtype iRType_t,
OperandType t1_t, void* v1_t,
OperandType t2_t, void* v2_t,
OperandType t3_t, void* v3_t)
{

}

void ItmCode::genCodeMoveRegToReg(Reg* opReg_t, Reg* rstReg_t)
{
    ItmCode *newCode = new ItmCode(ItmCode::IR_ASSIGN_OP,
    ItmCode::OPR_REGISTER, opReg_t,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_REGISTER, rstReg_t);

    Scope::s_curScope->addItemCode(newCode);

}

void ItmCode::genCodeMoveSymbolToReg(Symbol* symbol_t, Reg* rstReg_t)
{
    ItmCode *newCode = new ItmCode(ItmCode::IR_ASSIGN_OP,
    ItmCode::OPR_SYMBOL, symbol_t,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_REGISTER, rstReg_t);

    Scope::s_curScope->addItemCode(newCode);
}

void ItmCode::genCodeMoveRefListToReg(vector<void* >* refList_t, Reg *rstReg_t)
{
    ItmCode *newCode = new ItmCode(ItmCode::IR_ASSIGN_OP,
    ItmCode::OPR_CLASS_REFLIST, refList_t,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_REGISTER, rstReg_t);

    Scope::s_curScope->addItemCode(newCode);
}

void ItmCode::genCodeRegBinOpRegToReg(IRtype iRType_t, Reg* reg1_t, Reg* reg2_t, Reg* rstReg_t)
{
    ItmCode *newCode = new ItmCode(iRType_t,
    ItmCode::OPR_REGISTER, reg1_t,
    ItmCode::OPR_REGISTER, reg2_t,
    ItmCode::OPR_REGISTER, rstReg_t);

    Scope::s_curScope->addItemCode(newCode);
}



