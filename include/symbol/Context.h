#ifndef INCLUDE_CONTEXT_H
#define INCLUDE_CONTEXT_H

#include <string>
#include <vector>
#include <list>
#include "Symbol.h"
#include "Scope.h"
#include "ItmCode.h"

using namespace std;


/*****************************Context***********************************************/

class Context {

public:
    int state;

    TypeClass tmpDeclType;
    string tmpIdenName;
    vector<TypeClass> tmpParaTypeList;
    vector<Symbol> tmpParaWithIdList;
    int tmpParaWithoutIdNum;
    bool isFunc;

    Scope *tmpClassScope;

    ItmCode::OperandType tmpOpType;
    Reg *tmpExpReg;
    Symbol *tmpExpSymbol;

    Symbol *tmpTrueLabel;
    Symbol *tmpFalseLabel;

    //Symbol *tmpGotoBeginLabel;


public:
    Context();
    ~Context();

    void clearContext();

    void addParawithoutid(TypeClass m);
    int tmpParaWithIdNum;
    void addParawithid(Symbol m);




};


#endif // INCLUDE_CONTEXT_H

