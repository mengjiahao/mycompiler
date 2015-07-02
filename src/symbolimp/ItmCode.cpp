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
    } else {
        LogiMsg::logi("error in Reg::getReg(): the regIndex_t is out of range");
    }

    return NULL;
}




/*********************************ItmCode********************************************/
list< vector<void *>* > ItmCode::s_allExpList;
vector<ItmCode *> ItmCode::s_allItmCode;
int ItmCode::totalItmNo = 0;

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
    totalItmNo=s_codeId;
}

unsigned long ItmCode::getCodeId()
{
    return codeId;
}

void ItmCode::setTargetLabel(Symbol* label_t)
{
    if (NULL == label_t) {
        LogiMsg::logi("error in ItmCode::setTargetLabel(): label_t is NULL");
        return ;
    }
    v3 = label_t;
}

void ItmCode::copyLabelList(list<ItmCode* >& a, list<ItmCode *>& b)
{
    a.clear();

    list<ItmCode *>::iterator itrb;
    for(itrb = b.begin(); b.end() != itrb; ++itrb) {
        a.push_back(*itrb);
    }

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
        if (NULL == op_t) {
            cout << "!sb" << endl;
        }

            ofs_t << "Symbol(" << ((Symbol *)op_t)->getSymbolId()
            << "): " << ((Symbol *)op_t)->getTypeClass()->getTypeSfType()
            << " " << ((Symbol *)op_t)->getSymbolName();
            break;
        }
        case OPR_SCOPE: {
        if (NULL == op_t) {
            cout << "!sc" << endl;
        }
            ofs_t << "Scope(" << ((Scope *)op_t)->getScopeId()
            << "): " << ((Scope *)op_t)->getScopeId();
            break;
        }
        case OPR_ARGLIST: {
        if (NULL == op_t) {
            cout << "!ar" << endl;
        }
            ofs_t << "ARGLIST(";

            ofs_t << ")";
            break;
        }
        case OPR_CLASS_REFLIST: {
        if (NULL == op_t) {
            cout << "!cr" << endl;
        }
            ofs_t << "OPR_CLASS_REFLIST(";

            ofs_t << ")";
            break;
        }
        case OPR_CLASS_REFLIST_POINTER: {
        if (NULL == op_t) {
            cout << "!crp" << endl;
        }
            ofs_t << "OPR_CLASS_REFLIST_POINTER(";

            ofs_t << ")";
            break;
        }
        case OPR_REGISTER: {
        if (NULL == op_t) {
            cout << "!r" << endl;
        }
            ofs_t << "Reg(";
            ofs_t << ((Reg *)op_t)->getRegIndex();
            ofs_t << "): " << ((Reg *)op_t)->getTypeSfType();
            break;
        }
        default: {
            ofs_t << "NULL";
            break;
        }


        }


    } else {
        /*cout << "error in printOperand(): IR.txt is not open" << endl;*/
        LogiMsg::logi("error in ItmCode::printOperand(): IR.txt is not open");
    }
}


void ItmCode::printItmCode(ofstream &ofs_t)
{
    if (ofs_t.is_open()) {

        ofs_t << codeId << "#{ " << iRType << " , ";
        printOperand(ofs_t, t1, v1);
        ofs_t << " , ";
        printOperand(ofs_t, t2, v2);
        ofs_t << " , ";
        printOperand(ofs_t, t3, v3);
        ofs_t << " }\n";

    } else {
        /*cout << "error in printItmCode(): IR.txt is not open" << endl;*/
        LogiMsg::logi("error in ItmCode::printItmCode(): IR.txt is not open");
    }
}

void ItmCode::printSymboLSeqListItmCode(Scope* root_t, ofstream& ofs_t)
{
    if (NULL == root_t) {
        LogiMsg::logi("error in printSymboLSeqListItmCode(): root_t is NULL");
    }

    if (!ofs_t.is_open()) {
       LogiMsg::logi("error in printSymboLSeqListItmCode(): cannot open IR1.txt");
       return ;
    }

    list<Symbol *>::iterator itr;
    for(itr = root_t->symbolSeqList.begin(); root_t->symbolSeqList.end() != itr; ++itr) {
        ofs_t << "{ emit, " << (*itr)->getSymbolName()
         << "(" << (*itr)->getSymbolId() << ")}\n";
    }

    vector<ItmCode *>::iterator vitr;
    for(vitr = root_t->itemcodeVec.begin(); root_t->itemcodeVec.end() != vitr; ++vitr) {
        (*vitr)->printItmCode(ofs_t);
    }

}


void ItmCode::printScopeItmCode(Scope *root_t, ofstream &ofs_t)
{
    if (NULL == root_t) {
        LogiMsg::logi("error in printAllItmCode(): root_t is NULL");
    }


    if (!ofs_t.is_open()) {
       LogiMsg::logi("error in printAllItmCode(): cannot open IR1.txt");
       return ;
    }

    switch(root_t->getScopeType()) {
    case Scope::SCOPE_GLOBAL: {
        ofs_t << ".global_scope\n";
        printSymboLSeqListItmCode(root_t, ofs_t);

        vector<Scope *>::iterator itr;
        for(itr = root_t->childs.begin(); root_t->childs.end() != itr; ++itr) {
            printScopeItmCode((*itr), ofs_t);
        }
        break ;
    }

    case Scope::SCOPE_CLASS: {
        ofs_t << ".class_scope " << root_t->getScopeName() << "\n";
        printSymboLSeqListItmCode(root_t, ofs_t);

        vector<Scope *>::iterator itr;
        for(itr = root_t->childs.begin(); root_t->childs.end() != itr; ++itr) {
            printScopeItmCode((*itr), ofs_t);
        }
        break ;
    }

    case Scope::SCOPE_GLOBALFUNC: {
        ofs_t << ".global_func_scope " << root_t->getScopeName() << "\n";
        printSymboLSeqListItmCode(root_t, ofs_t);

        vector<Scope *>::iterator itr;
        for(itr = root_t->childs.begin(); root_t->childs.end() != itr; ++itr) {
            printScopeItmCode((*itr), ofs_t);
        }
        break ;
    }

    case Scope::SCOPE_GLOBALFUNCDECL: {
        ofs_t << ".global_func_decl_scope " << root_t->getScopeName() << "\n";
        printSymboLSeqListItmCode(root_t, ofs_t);

        vector<Scope *>::iterator itr;
        for(itr = root_t->childs.begin(); root_t->childs.end() != itr; ++itr) {
            printScopeItmCode((*itr), ofs_t);
        }
        break ;
    }

    case Scope::SCOPE_GLOBALFUNCCHAN: {
        ofs_t << ".global_func_change_scope " << root_t->getScopeName() << "\n";
        printSymboLSeqListItmCode(root_t, ofs_t);

        vector<Scope *>::iterator itr;
        for(itr = root_t->childs.begin(); root_t->childs.end() != itr; ++itr) {
            printScopeItmCode((*itr), ofs_t);
        }
        break;
    }

    case Scope::SCOPE_CLASSFUNC: {
        ofs_t << ".class_func_scope " << root_t->getScopeName() << "\n";
        printSymboLSeqListItmCode(root_t, ofs_t);

        vector<Scope *>::iterator itr;
        for(itr = root_t->childs.begin(); root_t->childs.end() != itr; ++itr) {
            printScopeItmCode((*itr), ofs_t);
        }
        break;
    }

    case Scope::SCOPE_LOCAL: {
        ofs_t << ".local_scope " << "\n";
        printSymboLSeqListItmCode(root_t, ofs_t);

        vector<Scope *>::iterator itr;
        for(itr = root_t->childs.begin(); root_t->childs.end() != itr; ++itr) {
            printScopeItmCode((*itr), ofs_t);
        }
        break;
    }

    default: {
        LogiMsg::logi("error in ItmCode::printScopeItmCode: root_t->getScopeType() is invalid");
        break;
    }
    }




}

void ItmCode::printSymbolTableItmCode(Scope* root_t)
{

    if (NULL == root_t) {
        LogiMsg::logi("error in printTreeItmCode(): root_t is NULL");
    }

    ofstream ofs;
    LogiMsg::logi(">>>printItmCode in IR1.txt");

    ofs.open("IR1.txt");


    if (!ofs.is_open()) {
       LogiMsg::logi("error in printAllItmCode(): cannot open IR1.txt");
       ofs.close();
       return ;
    }

    printScopeItmCode(root_t, ofs);

    ofs.close();
}

void ItmCode::printAllItmCode()
{
    ofstream ofs;
    LogiMsg::logi(">>>printItmCode in IR2.txt");

    ofs.open("IR2.txt");


    if (!ofs.is_open()) {
       LogiMsg::logi("error in printAllItmCode(): cannot open IR2.txt");
       ofs.close();
       return ;
    }

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
    ItmNo = itmNo_t;
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
    LogiMsg::logi("error in genCode(): the func is invalid");
}

void ItmCode::genCodeMoveRegToReg(Reg* opReg_t, Reg* rstReg_t)
{
    if (NULL == opReg_t || NULL == rstReg_t) {
        LogiMsg::logi("error in genCodeMoveRegToReg(): exist one of params is NULL");
    }

    ItmCode *newCode = new ItmCode(ItmCode::IR_ASSIGN_OP,
    ItmCode::OPR_REGISTER, opReg_t,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_REGISTER, rstReg_t);

    Scope::s_curScope->addItemCode(newCode);

}

void ItmCode::genCodeMoveSymbolToReg(Symbol* symbol_t, Reg* rstReg_t)
{
    if (NULL == symbol_t || NULL == rstReg_t) {
        LogiMsg::logi("error in genCodeMoveSymbolToReg(): exist one of params is NULL");
    }

    ItmCode *newCode = new ItmCode(ItmCode::IR_ASSIGN_OP,
    ItmCode::OPR_SYMBOL, symbol_t,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_REGISTER, rstReg_t);

    Scope::s_curScope->addItemCode(newCode);
}

void ItmCode::genCodeMoveRefListToReg(vector<void* >* refList_t, Reg *rstReg_t)
{
    if (NULL == refList_t || NULL == rstReg_t) {
        LogiMsg::logi("error in genCodeMoveRefListToReg(): exist one of params is NULL");
    }

    ItmCode *newCode = new ItmCode(ItmCode::IR_ASSIGN_OP,
    ItmCode::OPR_CLASS_REFLIST_POINTER, refList_t,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_REGISTER, rstReg_t);

    Scope::s_curScope->addItemCode(newCode);
}

void ItmCode::genCodeRegBinOpRegToReg(IRtype iRType_t, Reg* reg1_t, Reg* reg2_t, Reg* rstReg_t)
{
    if (NULL == reg1_t || NULL == reg2_t || NULL == rstReg_t) {
        LogiMsg::logi("error in genCodeRegBinOpRegToReg(): exist one of params is NULL");
    }

    ItmCode *newCode = new ItmCode(iRType_t,
    ItmCode::OPR_REGISTER, reg1_t,
    ItmCode::OPR_REGISTER, reg2_t,
    ItmCode::OPR_REGISTER, rstReg_t);

    Scope::s_curScope->addItemCode(newCode);
}

Reg* ItmCode::genCodeRegIsTrueAssign(Reg* reg_t)
{
    if (NULL == reg_t) {
        LogiMsg::logi("error in genCodeRegIsTrueAssign(): exist one of params is NULL");
        return NULL;
    }

    Reg *boolReg = Reg::getReg(reg_t->getRegIndex(), TypeClass::SF_INT);

    ItmCode *newCode = new ItmCode(ItmCode::IR_REG_ISTRUE_ASSIGN,
    ItmCode::OPR_REGISTER, reg_t,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_REGISTER, boolReg);

    Scope::s_curScope->addItemCode(newCode);

    return boolReg;

}


ItmCode* ItmCode::genCodeRegIfNotGotoLabel(Reg* reg_t, Symbol* label_t)
{
    if (NULL == reg_t) {
        LogiMsg::logi("error in genCodeRegIfNotGotoLabel(): exist one of params is NULL");
    }

    ItmCode *newCode = new ItmCode(ItmCode::IR_IF_NOT_GOTO,
    ItmCode::OPR_REGISTER, reg_t,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_SYMBOL, label_t);

    Scope::s_curScope->addItemCode(newCode);
    return newCode;
}

ItmCode* ItmCode::genCodeRegIfGotoLabel(Reg* reg_t, Symbol* label_t)
{
    if (NULL == reg_t) {
        LogiMsg::logi("error in genCodeRegIfGotoLabel(): exist one of params is NULL");
    }

    ItmCode *newCode = new ItmCode(ItmCode::IR_IF_GOTO,
    ItmCode::OPR_REGISTER, reg_t,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_SYMBOL, label_t);

    Scope::s_curScope->addItemCode(newCode);
    return newCode;
}


void ItmCode::genCodeEmitLabel(Symbol* label_t)
{
    if (NULL == label_t) {
        LogiMsg::logi("error in genCodeRegIfGotoLabel(): exist one of params is NULL");
    }

    ItmCode *newCode = new ItmCode(ItmCode::IR_EMITLABEL,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_SYMBOL, label_t);

    Scope::s_curScope->addItemCode(newCode);
}

void ItmCode::genCodeGotoBeginLabel(Symbol* label_t)
{
    if (NULL == label_t) {
        LogiMsg::logi("error in genCodeGotoBeginLabel(): exist one of params is NULL");
    }

    ItmCode *newCode = new ItmCode(ItmCode::IR_GOTO,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_SYMBOL, label_t);

    Scope::s_curScope->addItemCode(newCode);
}

ItmCode* ItmCode::genCodeGotoOutLabel(Symbol* label_t)
{
    ItmCode *newCode = new ItmCode(ItmCode::IR_GOTO,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_SYMBOL, label_t);

    Scope::s_curScope->addItemCode(newCode);

    return newCode;
}

void ItmCode::setGotoOutLabel(ItmCode* itmCode_t, Symbol* label_t)
{
    if (NULL == itmCode_t || NULL == label_t) {
        LogiMsg::logi("error in setGotoOutLabel(): exist one of params is NULL");
    }

    itmCode_t->v3 = label_t;
}






void ItmCode::genCodeUnaryOpClassRefList(IRtype iRType_t, vector<void* >* refList_t)
{
    if (NULL == refList_t) {
        LogiMsg::logi("error in genCodeUnaryOpClassRefList(): exist one of params is NULL");
    }

    ItmCode *newCode = new ItmCode(iRType_t,
    ItmCode::OPR_CLASS_REFLIST_POINTER, refList_t,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_CLASS_REFLIST_POINTER, refList_t);

    Scope::s_curScope->addItemCode(newCode);
}

void ItmCode::genCodeUnaryOpSymbol(IRtype iRType_t, Symbol* symbol_t)
{
    if (NULL == symbol_t) {
        LogiMsg::logi("error in genCodeUnaryOpSymbol(): exist one of params is NULL");
    }

    ItmCode *newCode = new ItmCode(iRType_t,
    ItmCode::OPR_SYMBOL, symbol_t,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_SYMBOL, symbol_t);

    Scope::s_curScope->addItemCode(newCode);
}

void ItmCode::genCodeAssignRegToSymbol(IRtype iRType_t, Reg* reg_t, Symbol* symbol_t)
{
    if (NULL == reg_t || NULL == symbol_t) {
        LogiMsg::logi("error in genCodeAssignRegToSymbol(): exist one of params is NULL");
    }

    ItmCode *newCode = new ItmCode(iRType_t,
    ItmCode::OPR_REGISTER, reg_t,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_SYMBOL, symbol_t);

    Scope::s_curScope->addItemCode(newCode);
}

void ItmCode::genCodeAssignRegToRefList(IRtype iRType_t, Reg* reg_t, vector<void* >* refList_t)
{
    if (NULL == reg_t || NULL == refList_t) {
        LogiMsg::logi("error in genCodeAssignRegToRefList(): exist one of params is NULL");
    }

    ItmCode *newCode = new ItmCode(iRType_t,
    ItmCode::OPR_REGISTER, reg_t,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_CLASS_REFLIST_POINTER, refList_t);

    Scope::s_curScope->addItemCode(newCode);
}

void ItmCode::genCodeNewClassIdToReg(Reg* reg_t, Scope *scope_t)
{
    if (NULL == reg_t) {
        LogiMsg::logi("error in genCodeNewClassIdToReg(): exist one of params is NULL");
    }

    ItmCode *newCode = new ItmCode(IR_NEW_OP,
    ItmCode::OPR_SCOPE, scope_t,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_REGISTER, reg_t);

    Scope::s_curScope->addItemCode(newCode);
}

void ItmCode::genCodeDeleteClassRefId(Symbol* symboL_t)
{
    if (NULL == symboL_t) {
        LogiMsg::logi("error in genCodeDeleteClassRefId(): exist one of params is NULL");
    }

    ItmCode *newCode = new ItmCode(IR_DELETE_OP,
    ItmCode::OPR_SYMBOL, symboL_t,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_INVALID, NULL);

    Scope::s_curScope->addItemCode(newCode);
}

void ItmCode::genCodeReturnVoid()
{
    ItmCode *newCode = new ItmCode(IR_RETURN_VOID,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_INVALID, NULL);

    Scope::s_curScope->addItemCode(newCode);
}

void ItmCode::genCodeReturnReg(Reg *reg_t)
{
    if (NULL == reg_t) {
        LogiMsg::logi("error in genCodeReturnReg(): exist one of params is NULL");
    }

    ItmCode *newCode = new ItmCode(IR_RETURN_REG,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_REGISTER, reg_t);

    Scope::s_curScope->addItemCode(newCode);
}

void ItmCode::genCodeEmitVar(Symbol* symbol_t)
{
    ItmCode *newCode = new ItmCode(IR_EMITVAR,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_SYMBOL, symbol_t);

    Scope::s_curScope->addItemCode(newCode);
}

void ItmCode::genCodeEmitClassMemVar(Symbol* symbol_t)
{
    ItmCode *newCode = new ItmCode(IR_EMITCLASSMEMVAR,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_SYMBOL, symbol_t);

    Scope::s_curScope->addItemCode(newCode);
}


void ItmCode::genCodeEmitGlobalFunc(Scope* scope_t)
{
    ItmCode *newCode = new ItmCode(IR_EMITFUNC,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_SCOPE, scope_t);

    Scope::s_curScope->addItemCode(newCode);
}

void ItmCode::genCodeEmitClassFunc(Scope* scope_t)
{
    ItmCode *newCode = new ItmCode(IR_EMITCLASSFUNC,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_SCOPE, scope_t);

    Scope::s_curScope->addItemCode(newCode);
}

void ItmCode::genCodeEmitClass(Scope* scope_t)
{
    ItmCode *newCode = new ItmCode(IR_EMITCLASS,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_INVALID, NULL,
    ItmCode::OPR_SCOPE, scope_t);

    Scope::s_curScope->addItemCode(newCode);
}











