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
    OPR_ARGLIST, OPR_CLASS_REFLIST, OPR_ARRAY_ELEMLIST, OPR_CLASS_REFLIST_POINTER};*/
    ItmCode::OperandType tmpOpType;
    Reg *tmpExpReg;
    Symbol *tmpExpSymbol;

    vector<void *> tmpExpList;
    vector<void *> *tmpExpListPointer;

    list<ItmCode *> tmpTrueLabelList;
    list<ItmCode *> tmpFalseLabelList;


public:
    Context();
    ~Context();

    void clearContext();

    void clearAllContext();

    void addParawithoutid(TypeClass m);
    void addParawithid(Symbol m);

    void addToExpList(void *m);
    void* getExpListLast();
    void clearExpList();



    void addToTrueLabelList(ItmCode *newCode_t);
    void addToFalseLabelList(ItmCode *newCode_t);
    void clearLabelList();
    void backFillTrueLabelList(Symbol *trueLabel_t);
    void backFillFalseLabelList(Symbol *falseLabel_t);

    void clearSingleOperand();
    void resetSingleOperand(void *p, ItmCode::OperandType tmpOpType_t);




};


#endif // INCLUDE_CONTEXT_H

