#ifndef INCLUDE_SCOPE_H
#define INCLUDE_SCOPE_H

#include <map>
#include <list>
#include <string>
#include "Symbol.h"

class Context;

class Scope {

public:
    enum ScopeType {SCOPE_INVALID, SCOPE_GLOBAL, SCOPE_CLASS,
    SCOPE_GLOBALFUNC, SCOPE_CLASSFUNC, SCOPE_LOCAL};

    int scopeId;
    ScopeType scopeType;
    string scopeName;
    int level;
    int startOffset;
    int symbolsNo;
    int totalByteSize;

    Scope *parent;
    Scope *superClass;
    list<Scope *> childs;
    map<string, Symbol *> symbolVarMap;
    list<Symbol *> symbolSeqList;

    static Scope *curScope;

    static map<string, Symbol *> s_labelMap;
    static map<string, Symbol *> s_constMap;
    static map<string, Symbol *> s_tempVarMap;
    static list<Symbol *> s_allSymbolList;
    static map<int, Symbol*> s_allSymbolMap;

    static Context* s_context;

public:
    Scope();
    virtual ~Scope();

    virtual void initGlobalScope();
    virtual void initClassScope();
    virtual void initGlobalFuncScope();
    virtual void initClassFuncScope();
    virtual void initLocalScope();

    virtual void setScopeId();
    virtual int getScopeId();

    virtual void setScopeType(Scope::ScopeType scopeType_t);
    virtual Scope::ScopeType  getScopeType();

    virtual void setLevel(int level_t);
    virtual int getlevel();

    virtual void setStartOffset(int startOffset_t);
    virtual int getStartOffset();

    virtual void setSymbolsNo(int symbolsNo_t);
    virtual int getSymbolsNo();

    virtual void setTotalByteSize(int totalByteSize_t);
    virtual int getTotalByteSize();

    virtual void setParent(Scope *parent_t);
    virtual Scope* getParent();

    virtual void setSuperClass(Scope *superClass_t);
    virtual Scope* getSuperClass();

    virtual addChild(Scope *child_t);
    virtual Scope* searchChild(string childName_t);

    virtual addToSymbolVarMap(Symbol *symbolVar_t);
    virtual Symbol* searchSymbolVarMap(string symbolName_t);

    virtual addToSymbolSeqList(Symbol *symbolVar_t);
    virtual list<Symbol *>& getSymbolSeqList();

    static void addToLabelMap(Symbol *label_t);

    static void addToConstantMap(Symbol *constant_t)

    static void addToTempVarMap(Symbol *tempVar_t);

    static void addToAllSymbolList(Symbol *symbol_t);

    static void addToAllSymbolMap(Symbol *symbol_t);
    static Symbol* searchAllSymbolMap(int symbolId_t);

    virtual void pushScope(Scope *newScope_t);
    virtual Scope* enterScope();
    virtual Scope* encloseScope();
};


/*****************************Context***********************************************/

class Context {

public:
    Symbol* s_newSymbol;

public:
    Constext();
    ~Constext();

    static void clearNewSymbol();

    static Context* getSingletonContext();

};

#endif


