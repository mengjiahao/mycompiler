#ifndef INCLUDE_SCOPE_H
#define INCLUDE_SCOPE_H

#include <map>
#include <list>
#include <string>
#include "Symbol.h"

class Scope {

public:
    enum ScopeType {SCOPE_GLOBAL, SCOPE_CLASS, SCOPE_GLOBALFUNC, SCOPE_CLASSFUNC, SCOPE_LOCAL};

    map<string, Symbol*> symbolMap;
    list<Symbol *> symbolList;
    int level;
    int startOffset;
    int symbolNo;

    Scope *parent;
    Scope *superClass;

    static list<Symbol *> s_labelList;
    static list<Symbol *> s_constvarList;
    static list<Symbol *> s_tempvarList;
    static list<Symbol *> s_symbolList;

public:
    Scope::ScopeType getScopeType();
    void pushScope(Scope *newScope_t);
    Scope* enterScope();
    Scope* encloseScope();
    Scope* getParentScope();
    Scope* getSuperClassScope();
    //void defineSymbol(Symbol *Symbol_t);
    void searchSymbol(string symbolName_t);


};


class


#endif


