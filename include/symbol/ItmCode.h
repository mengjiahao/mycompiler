#ifndef INCLUDE_ITMCODE_H
#define INCLUDE_ITMCODE_H

#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <set>

class TypeClass;
class Symbol;
class Scope;

using namespace std;

/***************************************Reg***************************************************/
class RegSortComp;

class Reg {
public:
    enum RegType {REG_INVALID, REG_EAX, REG_EBX, REG_ECX, REG_EDX,
    REG_ST0, REG_ST1, REG_ST2, REG_ST3, REG_ST4, REG_ST5, REG_ST6, REG_ST7};


    //int regType;
    int typeSfType;

    static set<Reg, RegSortComp> s_regs;


public:

    //virtual void setRegType(int regType_t);
    //virtual int getRegType();

    virtual void setTypeSfType(int typeSfType_t);
    virtual int getTypeSfType();

    static void initRegs();

    static const Reg* getReg(int sf_t);

};

class RegSortComp {
public:

    bool operator() (const Reg &a, const Reg &b) const {
            if (a.typeSfType < b.typeSfType) {
                return true;
            }

        return false;
    }


};

/*******************************************ItemCode***********************************************************/

class ItmCode {
public:
    enum IRtype {IR_INVALID,
    IR_PUSHVAR, IR_POPVAR, IR_MOVVAR,
    IR_EMITVAR, IR_EMITFUNC, IR_EMITLABEL,
    IR_CALLFUNC, IR_CALLCLASSFUNC,
    IR_FETCHARRAY,
    IR_NEW_OP, IR_DELETE_OP,
    IR_ASSIGN_OP, IR_MUL_ASSIGN, IR_DIV_ASSIGN, IR_MOD_ASSIGN,
    IR_ADD_ASSIGN, IR_SUB_ASSIGN,
    IR_LEFT_ASSIGN, IR_RIGHT_ASSIGN,
    IR_AND_ASSIGN, IR_XOR_ASSIGN, IR_OR_ASSIGN,
    IR_LOGOR_OP, IR_LOGAND_OP,
    IR_EQ_OP, IR_NE_OP, IR_L_OP, IR_G_OP, IR_LE_OP, IR_GE_OP,
    IR_LEFT_OP, IR_RIGHT_OP,
    IR_ADD_OP, IR_SUB_OP, IR_MUL_OP, IR_DIV_OP, IR_MOD_OP,
    IR_INC_OP, IR_DEC_OP, IR_SIZEOF,
    IR_UAND_OP, IR_UREF_OP, IR_UADD_OP, IR_USUB_OP, IR_UCOMP_OP, IR_UNOT_OP,
    IR_GOTO, IR_IF_GOTO, IR_IF_NOT_GOTO,
    IR_RETURN};

    enum OperandType {OPR_INVALID, OPR_ID, OPR_SYMBOL, OPR_SCOPE, OPR_REGISTER,
    OPR_ARGLIST, OPR_CLASS_REFLIST, OPR_ARRAY_ELEMLIST};

    /*union OperandValue{
        Symbol *v1;
        Scope *v2;
        list<Symbol *> *v3;
        Reg *v4;
    };*/

    unsigned long codeId;
    IRtype iRType;
    OperandType t1;
    void *v1;
    OperandType t2;
    void *v2;
    OperandType t3;
    void *v3;

    static list< vector<void *> * > s_allExpList;
    static vector<ItmCode *> s_allItmCode;
    static int totalItmNo;
    int ItmNo;


public:
    ItmCode();
    ItmCode(IRtype iRType_t = ItmCode::IR_INVALID,
OperandType t1_t = ItmCode::OPR_INVALID, void* v1_t = NULL,
OperandType t2_t = ItmCode::OPR_INVALID, void* v2_t = NULL,
OperandType t3_t = ItmCode::OPR_INVALID, void* v3_t = NULL);
    ~ItmCode();

    virtual void setCodeId();
    virtual unsigned long getCodeId();

    virtual void printOperand(ofstream &ofs_t, OperandType opType_t, void *op_t);
    virtual void printItmCode(ofstream &ofs_t);

    static vector<void* >* copyVectorToAllExpList(vector<void *> &vargList_t);
    static void addToAllExpList(vector<void *> *expList_t);
    static void freeAllExpList();

    static void addToAllItmCode(ItmCode *itmCode_t);
    static void freeAllItmCode();

    static void printAllItmCode();

    static int getTotalItemNo();

    virtual void setItmNo(int itmNo_t);
    virtual int getItmNo();


};


#endif
