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
    int tmpParaWithIdNum;

    bool isFunc;
    bool isMemVar;

    Scope *tmpClassScope;

    /*enum OperandType {OPR_INVALID, OPR_ID, OPR_SYMBOL, OPR_SCOPE, OPR_REGISTER,
    OPR_ARGLIST, OPR_CLASS_REFLIST, OPR_ARRAY_ELEMLIST};*/
    ItmCode::OperandType tmpOpType;

    Reg *tmpExpReg;
    Symbol *tmpExpSymbol;

    vector<void *> tmpExpList;
    int tmpExpNum;

    Symbol *tmpTrueLabel;
    Symbol *tmpFalseLabel;

    //Symbol *tmpGotoBeginLabel;


public:
    Context();
    ~Context();

    void clearContext();

    void addParawithoutid(TypeClass m);
    void addParawithid(Symbol m);

    void addToExpList(void *m);




};


#endif // INCLUDE_CONTEXT_H

