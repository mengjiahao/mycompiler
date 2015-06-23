#ifndef INCLUDE_ITMCODE_H
#define INCLUDE_ITMCODE_H

#include <list>
#include <vector>

using namespace std;

class Symbol;


class Reg {
public:
    enum RegType {REG_INVALID, REG_EAX, REG_EBX, REG_ECX, REG_EDX,
    REG_ST0, REG_ST1, REG_ST2, REG_ST3, REG_ST4, REG_ST5, REG_ST6, REG_ST7};

    enum RegValueType {REG_CHAR, REG_INT, REG_LONG, REG_FLOAT, REG_DOUBLE,
    REG_U_CHAR, REG_U_INT, REG_U_LONG, REG_U_FLOAT, REG_U_DOUBLE};

    static int RegTypeNo;
    static int RegValueTypeNo;

    int regType;
    int regValueType;

    static Reg regs[13][10];


public:
    static void initRegs();

    static Reg* getReg(RegType regType_t, RegValueType regValueType_t);

};

class ItmCode {
public:
    enum IRtype {IR_INVALID, IR_EMITFUNC, IR_EMITVAR, IR_CALLFUNC, IR_FETCHARRAY,
    IR_NEW_OP, IR_DELETE_OP, IR_ASSG_OP, IR_MUL_ASSIGN, IR_DIV_ASSIGN, IR_MOD_ASSIGN,
    IR_ADD_ASSIGN, IR_SUB_ASSIGN, IR_LEFT_ASSIGN, IR_RIGHT_ASSIGN, IR_AND_ASSIGN,
    IR_XOR_ASSIGN, IR_OR_ASSIGN, IR_LOGOR_OP, IR_LOGAND_OP, IR_EQ_OP, IR_NE_OP,
    IR_L_OP, IR_G_OP, IR_LE_OP, IR_GE_OP, IR_LEFT_OP, IR_RIGHT_OP, IR_ADD_OP, IR_SUB_OP,
    IR_MUL_OP, IR_DIV_OP, IR_MOD_OP, IR_INC_OP, IR_DEC_OP, IR_SIZEOF, IR_UAND_OP,
    IR_UREF_OP, IR_UADD_OP, IR_USUB_OP, IR_UCOMP_OP, IR_UNOT_OP, IR_GOTO, IR_IF_GOTO,
    IR_RETURN};

    enum OperandType {OPR_INVALID, OPR_SYMBOL, OPR_SCOPE, OPR_ARGLIST,
    OPR_REGISTER};

    /*union OperandValue{
        Symbol *v1;
        Scope *v2;
        list<Symbol *> *v3;
        Reg *v4;
    };*/

    IRtype iRType;
    OperandType t1;
    void *v1;
    OperandType t2;
    void *v2;
    OperandType t3;
    void *v3;

    static list< list<Symbol *>* > s_allArgList;
    static vector<ItmCode *> s_allItmCode;


public:
    ItmCode();
    ItmCode(IRtype iRType_t, OperandType t1_t, void *v1_t,
    OperandType t2_t, void *v2_t, OperandType t3_t, void *v3_t);

    static void addToAllArgList(list<Symbol *> *argList_t);
    static void freeAllArgList();

    static void addToAllItmCode(ItmCode *itmCode_t);
    static void freeAllItmCode();


};


#endif
