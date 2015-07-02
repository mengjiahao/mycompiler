#ifndef INCLUDE_SCOPE_H
#define INCLUDE_SCOPE_H

#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <stack>
#include "Symbol.h"
#include "ItmCode.h"

using namespace std;


/***********************************Scope***************************************/

class Context;


class Scope {

public:
    enum ScopeType {SCOPE_INVALID, SCOPE_GLOBAL, SCOPE_CLASS,
    SCOPE_GLOBALFUNC, SCOPE_GLOBALFUNCDECL, SCOPE_GLOBALFUNCCHAN, SCOPE_CLASSFUNC, SCOPE_LOCAL};

    unsigned long scopeId;
    ScopeType scopeType;
    string scopeName;

    Scope *parent;
    Scope *superClass;

    int level;
    int curStartOffset;
    unsigned int totalByteSize;
    int funcOffset;
    int totalFuncByteSize;

    int startCodeNo;

    TypeClass *returnTypeClass;

    vector<Scope *> childs;
    unsigned int symbolsNo;

    map<string, Symbol *> symbolVarMap;  //paramVar, classVar, localVar
    map<string, Symbol *> symbolTempVarMap;
    list<Symbol *> symbolSeqList;  //sequencialVar

    vector<ItmCode *> itemcodeVec;

    static map<string, Symbol *> s_labelMap;
    static map<string, Symbol *> s_constMap;
    static map<string, Symbol *> s_tempVarMap;
    static map<unsigned long, Symbol *> s_allSymbolMap;

    static list<Scope *> s_allScopeList;

    static list<Symbol *> s_allSymbolList;

    static Scope *s_globalScope;

    static Scope *s_curScope;




    //int paraTypeNum;
    //vector<TypeClass> paraType;



public:
    Scope();
    virtual ~Scope();

    virtual void setScopeId();
    virtual unsigned long getScopeId();

    virtual void setScopeType(Scope::ScopeType scopeType_t);
    virtual Scope::ScopeType getScopeType();

    virtual void setScopeName(const string &scopeName_t);
    virtual string getScopeName();

    virtual void setParent(Scope *parent_t);
    virtual Scope* getParent();

    virtual void setSuperClass(Scope *superClass_t);
    virtual Scope* getSuperClass();

    virtual void setLevel(int level_t);
    virtual int getlevel();

    virtual void setCurStartOffset(int curStartOffset_t);
    virtual void incCurStartOffset(int incOffset_t);
    virtual int getCurStartOffset();

    virtual void setTotalByteSize(unsigned int totalByteSize_t);
    virtual void incTotalByteSize(unsigned int incByteSize_t);
    virtual unsigned int getTotalByteSize();

    virtual void setFuncOffest(int funcOffset_t);
    virtual void incFuncOffset(int incOffset_t);
    virtual int getFuncOffset();

    virtual void setTotalFuncByteSize(int totalFuncByteSize_t);
    virtual void incTotalFuncByteSize(int incByteSize_t);
    virtual int getTotalFuncByteSize();

    virtual void setReturnTypeClass(TypeClass *typeClass_t);
    virtual TypeClass* getReturnTypeClass();

    virtual int addChild(Scope *child_t);
    virtual Scope* searchChildName(const string &childName_t);

    virtual void setSymbolsNo(unsigned int symbolsNo_t);
    virtual void incSymbolsNo();
    virtual unsigned int getSymbolsNo();

    virtual int addToSymbolVarMap(Symbol *symbolVar_t);
    virtual Symbol* searchSymbolVarMap(const string &symbolName_t);
    static Symbol* searchDownUpSymbolVarMap(Scope *curScope_t, const string &symbolName_t);

    virtual int addToSymbolTempVarMap(Symbol *symbolTempVar_t);
    virtual Symbol* searchSymbolTempVarMap(const string &symbolName_t);

    virtual int addToSymbolSeqList(Symbol *symbol_t);
    virtual void clearSymbolSeqList();

    static int addToLabelMap(Symbol *label_t);
    static Symbol* searchLabelMap(const string &labelName_t);

    static int addToConstantMap(Symbol *constant_t);
    static Symbol* searchConstantMap(const string &constantName_t);

    static int addToTempVarMap(Symbol *tempVar_t);
    static Symbol* searchTempVarMap(const string &tempVarName_t);

    static int addToAllSymbolMap(Symbol *symbol_t);
    static Symbol* searchAllSymbolMap(unsigned long symbolId_t);

    static int addToAllScopeList(Scope *scope_t);
    static void freeAllScopeList();

    static int addToAllSymbolList(Symbol *symbol_t);
    static void freeAllSymbolList();

    static void setCurScope(Scope *curScope_t);
    static Scope* getCurScope();

    static void setGlobalScope(Scope *globalScope_t);
    static Scope* getGlobalScope();

    virtual void initGlobalScope();
    virtual void initClassScope(const string &scopeName_t);
    virtual void initGlobalFuncScope(const string &scopeName_t);
    virtual void initClassFuncScope(const string &scopeName_t);
    virtual void initLocalScope();
    virtual void initGlabalFuncDeclScope(const string &scopeName_t);

    static Scope* pushScope(Scope* curScope_t, Scope *newScope_t);
    static Scope* enterScope(Scope *nextScope_t);
    static Scope* encloseScope(Scope* curScope_t);

    virtual int defineSymbol(Symbol *symbol_t);

    virtual Symbol* resolveSymbol(const string& symbolName_t, Symbol::SymbolType symbolType_t);

    static Symbol* resolveSymbolMemVar(Scope* classScope_t, const string &symbolName_t);
    static Scope* resolveScope(const string& scopeName_t, Scope::ScopeType scopeType_t);
    static Scope* resolveClassFuncScope(Scope *classScope_t, const string& scopeName_t);
    static Scope* resolveGlobalFuncScope(const string& scopeName_t);

    virtual Scope*  resolveMemFunByName(const string& funcName_t);
    virtual Scope*  resolveMemFunByOffset(int funcOffset_t);

    virtual Scope*  searchChildOffset(int funcOffset_t);

    static void printScopeTree();
    virtual void printScope(ofstream &ofs_t);

    void addItemCode(ItmCode *itmcode_t);


    static void scopeOffsetChange(Scope *scope_t, int inc_t);

    //virtual void addParaType(TypeClass *type_t);


};



#endif


