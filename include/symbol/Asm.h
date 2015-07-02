#ifndef INCLUDE_ASM_H
#define INCLUDE_ASM_H
#include "Context.h"
#include "ItmCode.h"
#include "Scope.h"
#include "Symbol.h"
#include "../LogiMsg.h"
#include <string>
#include <sstream>
#include <fstream>
#include <list>
#include <vector>
#include <map>


class Asm{
public:
    static list<string> dataSectionList;
    static list<string> bssSectionList;
    static list<string> textSectionList;


    /*static ofstream dataSection;
    static ofstream bssSection;
    static ofstream textSection;*/

    static void printScopeAsm(Scope *scope_t);
    static void printExpAsm(ItmCode *code_t, Scope *scope_t);
    static void printAllAsm();

    static string genSymbol(void *v1, Scope *scope_t);
    static string genRefList(void *v1, Scope *scope_t);
    static string genReg(int reg_t, int type_t);
    static void genMovToReg(int reg_t, int type_t, string opr);
    static void genRegMovTo(int reg_t, int regtype_t, int othertype_t, string opr);

    static void genFuncStart(Scope *scope_t);
    static void genFuncEnd(Scope *scope_t);

    static string genMov(int type_t);

    static int genPushArgu(void *v1, bool isthis, Scope *scope_t, string thisstr);

    static void genJum(string jmp_t, ItmCode *code_t);

    static void genFLoatOpe(string ope_t, void *v1, void *v2, void *v3);
    static void genIntOpe(string ope_t, void *v1, void *v2, void *v3);

    static void printAsm();

    static void addToDataSectionList(const string &a);
    static void addToBssSectionList(const string &a);
    static void addToTextSectionList(const string &a);
};



















#endif
