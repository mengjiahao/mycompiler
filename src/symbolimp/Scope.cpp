#include "../../include/symbol/Scope.h"

using namespace std;

/***********************************Scope***************************************/

Scope::Scope()
{
    scopeId = 0;
    scopeType = SCOPE_INVALID;

    parent = NULL;
    superClass = NULL;

    level = -1;
    startOffset = 0;
    totalByteSize = 0;

    returnType = NULL;

    symbolsNo = 0;

    addToAllScopeList(this);
}

Scope::~Scope()
{
    scopeId = 0;
    scopeType = SCOPE_INVALID;

    parent = NULL;
    superClass = NULL;

    level = -1;
    startOffset = 0;
    totalByteSize = 0;

    returnType = NULL;

    symbolsNo = 0;
}

void Scope::setScopeId()
{
    static unsigned long s_scopeId = 0;
    scopeId = ++s_scopeId;
}

unsigned long Scope::getScopeId()
{
    return scopeId;
}

void Scope::setScopeType(Scope::ScopeType scopeType_t)
{
    scopeType = scopeType_t;
}

Scope::ScopeType Scope::getScopeType()
{
    return scopeType;
}

void Scope::setScopeName(const string &scopeName_t)
{
    scopeName = scopeName_t;
}

string Scope::getScopeName()
{
    return scopeName;
}

void Scope::setParent(Scope* parent_t)
{
    parent = parent_t;
}

Scope* Scope::getParent()
{
    return parent;
}

void Scope::setSuperClass(Scope* superClass_t)
{
    superClass = superClass_t;
}

Scope* Scope::getSuperClass()
{
    return superClass;
}

void Scope::setLevel(int level_t)
{
    level = level_t;
}

int Scope::getlevel()
{
    return level;
}

void Scope::setCurStartOffset(int curStartOffset_t)
{
    curStartOffset = curStartOffset_t;
}

void Scope::incCurStartOffset(int incOffset_t)
{
    curStartOffset += incOffset_t;
}

int Scope::getCurStartOffset()
{
    return curStartOffset;
}

void Scope::setTotalByteSize(unsigned int totalByteSize_t)
{
    totalByteSize = totalByteSize_t;
}

void Scope::incTotalByteSize(unsigned int incByteSize_t)
{
    totalByteSize += incByteSize_t;
}

unsigned int Scope::getTotalByteSize()
{
    return totalByteSize;
}

void Scope::setReturnTypeClass(TypeClass* typeClass_t)
{
    if (NULL == returnTypeClass) {
        returnTypeClass = new TypeClass();

        returnTypeClass->clone(typeClass_t);
    }
}

TypeClass* Scope::getReturnTypeClass()
{
    return returnTypeClass;
}

int Scope::addChild(Scope* child_t)
{
    if (NULL != child_t) {
        childs.push_back(child_t);
        return 1;
    }
    return 0;
}

Scope* Scope::searchChildName(const string &childName_t)
{
    vector<Scope *>::iterator itr;

    for(itr = childs.begin(); itr != childs.end(); ++itr) {
        if ( 0 == ( (*itr)->getScopeName().compare(childName_t) ) ) {
            return *itr;
        }
    }
}

void Scope::setSymbolsNo(unsigned int symbolsNo_t)
{
    symbolsNo = symbolsNo_t;
}

void Scope::incSymbolsNo()
{
    ++symbolsNo;
}


unsigned int Scope::getSymbolsNo()
{
    return symbolsNo;
}

int Scope::addToSymbolVarMap(Symbol* symbolVar_t)
{
    if (NULL != symbolVar_t) {

        pair< map<string, Symbol *>::iterator, bool > insertFlag;
        insertFlag = symbolVarMap.insert( pair<string, Symbol *>(symbolVar_t.getSymbolName(), symbolVar_t) );
        if (true == insertFlag.second) {
            return 1;
        }
    }

    return 0;
}

Symbol* Scope::searchSymbolVarMap(const string &symbolName_t)
{
    map<string, Symbol *>::iterator itr;
    itr = symbolVarMap.find(symbolName_t);
    if (symbolVarMap.end() != itr) {
        return itr->second;
    }

    return NULL;

}

Symbol* Scope::searchDownUpSymbolVarMap(Scope *curScope_t, const string& symbolName_t)
{
    if (NULL == curScope_t)
        return NULL;

    Symbol *result = curScope_t->searchSymbolVarMap(symbolName_t);
    if (NULL != result) {
        return result;
    }

    if (NULL == result) {

        if ( (Scope::SCOPE_CLASS == curScope_t->scopeType) && (NULL != curScope_t->superClass) ) {
            result = searchDownUpSymbolVarMap(curScope_t->superClass, symbolName_t);
            if (NULL != result) {
                return result;
            }
        }

        if (NULL != curScope_t->parent) {
            result = searchDownUpSymbolVarMap(curScope_t->parent, symbolName_t);
            if (NULL != result) {
                return result;
            }
        }
    }

    return NULL;
}

int Scope::addToSymbolTempVarMap(Symbol* symbolTempVar_t)
{
    if (NULL != symbolTempVar_t) {

        pair< map<string, Symbol *>::iterator, bool > insertFlag;
        insertFlag = symbolTempVarMap.insert( pair<string, Symbol *>(symbolTempVar_t.getSymbolName(), symbolTempVar_t) );
        if (true == insertFlag.second) {
            return 1;
        }
    }

    return 0;
}

Symbol* Scope::searchSymbolTempVarMap(const string& symbolName_t)
{
    map<string, Symbol *>::iterator itr;
    itr = symbolTempVarMap.find(symbolName_t);
    if (symbolTempVarMap.end() != itr) {
        return itr->second;
    }

    return NULL;
}


int Scope::addToSymbolSeqList(Symbol* symbol_t)
{
    if (NULL != symbol_t) {
        symbolSeqList.push_back(symbol_t);
        return 1;
    }

    ++symbolsNo;

    return 0;
}

int Scope::addToLabelMap(Symbol* label_t)
{
    if (NULL != label_t) {
        pair< map<string, Symbol *>::iterator, bool > insertFlag;
        insertFlag = s_labelMap.insert( pair<string, Symbol *>(label_t.getSymbolName(), label_t) );
        if (true == insertFlag.second) {
            return 1;
        }
    }

    return 0;
}

Symbol* Scope::searchLabelMap(const string& labelName_t)
{
    map<string, Symbol *>::iterator itr;
    itr = s_labelMap.find(labelName_t);
    if (s_labelMap.end() != itr) {
        return itr->second;
    }

    return NULL;
}

int Scope::addToConstantMap(Symbol* constant_t)
{
    if (NULL != constant_t) {
        pair< map<string, Symbol *>::iterator, bool > insertFlag;
        insertFlag = s_constMap.insert( pair<string, Symbol *>(constant_t.getSymbolName(), constant_t) );
        if (true == insertFlag.second) {
            return 1;
        }
    }

    return 0;
}

Symbol* Scope::searchConstantMap(const string& constantName_t)
{
    map<string, Symbol *>::iterator itr;
    itr = s_constMap.find(constantName_t);
    if (s_constMap.end() != itr) {
        return itr->second;
    }

    return NULL;
}

int Scope::addToTempVarMap(Symbol* tempVar_t)
{
    if (NULL != tempVar_t) {
        pair< map<string, Symbol *>::iterator, bool > insertFlag;
        insertFlag = s_tempVarMap.insert( pair<string, Symbol *>(tempVar_t.getSymbolName(), tempVar_t) );
        if (true == insertFlag.second) {
            return 1;
        }
    }

    return 0;
}

Symbol Scope::searchTempVarMap(const string& tempVarName_t)
{
    map<string, Symbol *>::iterator itr;
    itr = s_tempVarMap.find(tempVarName_t);
    if (s_tempVarMap.end() != itr) {
        return itr->second;
    }

    return NULL;
}

int Scope::addToAllSymbolMap(Symbol* symbol_t)
{
    if (NULL != symbol_t) {
        pair< map<unsigned long, Symbol *>::iterator, bool > insertFlag;
        insertFlag = s_allSymbolMap.insert( pair<unsigned long, Symbol *>(symbol_t.getSymbolId(), symbol_t) );
        if (true == insertFlag.second) {
            return 1;
        }
    }

    return 0;
}

Symbol* Scope::searchAllSymbolMap(unsigned long symbolId_t)
{
    map<unsigned long, Symbol *>::iterator itr;
    itr = s_allSymbolMap.find(symbolId_t);
    if (s_allSymbolMap.end() != itr) {
        return itr->second;
    }

    return NULL;
}

int Scope::addToAllScopeList(Scope* scope_t)
{
    if (NULL != scope_t) {
        s_allScopeList.push_back(scope_t);
        return 1;
    }

    return 0;
}

int Scope::addToAllSymbolList(Symbol* symbol_t)
{
    if (NULL != symbol_t) {
        s_allSymbolList.push_back(symbol_t);
        return 1;
    }

    return 0;
}

void Scope::setCurScope(Scope* curScope_t)
{
    if (NULL != curScope_t) {
        s_curScope = curScope_t;
    }
}

Scope* Scope::getCurScope()
{
    return s_curScope;
}

void Scope::initGlobalScope()
{
    scopeType = Scope::SCOPE_GLOBAL;
    scopeName = "GlobalScope";

    parent = NULL;
    superClass = NULL;

    level = 0;
    curStartOffset = 0;
    totalByteSize = 0;

    returnTypeClass = NULL;

    symbolsNo = 0;
}

void Scope::initClassScope(const string& scopeName_t)
{
    scopeType = Scope::SCOPE_CLASS;
    scopeName = scopeName_t;

    if (NULL != parent) {
        level = parent->getlevel() + 1;
    }
    if (NULL != superClass) {
        curStartOffset = superClass->getTotalByteSize();
        totalByteSize = superClass->getTotalByteSize();
    }


    returnTypeClass = NULL;

    symbolsNo = 0;
}

void Scope::initGlobalFuncScope(const string& scopeName_t)
{
    scopeType = Scope::SCOPE_GLOBALFUNC;
    scopeName = scopeName_t;

    superClass = NULL;

    if (NULL != parent) {
        level = parent->getlevel() + 1;
    }
    curStartOffset = 0;
    totalByteSize = 0;

    returnTypeClass = NULL;

    symbolsNo = 0;

}

void Scope::initClassFuncScope(const string& scopeName_t)
{
    scopeType = Scope::SCOPE_CLASSFUNC;
    scopeName = scopeName_t;

    superClass = NULL;

    if (NULL != parent) {
        level = parent->getlevel() + 1;
    }
    curStartOffset = 4;  //pointer this?
    totalByteSize = 4;

    returnTypeClass = NULL;

    symbolsNo = 0;
}

void Scope::initLocalScope()
{
    scopeType = Scope::SCOPE_LOCAL;
    scopeName = "LocalScope";

    superClass = NULL;

    if (NULL != parent) {
        level = parent->getlevel() + 1;
        curStartOffset = parent->getCurStartOffset();
    }
    totalByteSize = 0;

    returnTypeClass = NULL;

    symbolsNo = 0;

}

Scope* Scope::pushScope(Scope* curScope_t, Scope* newScope_t)
{
    if (NULL != newScope_t) {

        newScope_t->setScopeId();  //id

        if (NULL != curScope) {
            curScope_t->addChild(newScope_t);
            newScope_t->setParent(curScope_t);
        } else {
            newScope_t->setParent(NULL);
        }

        return newScope_t;
    }

    return curScope_t;
}

Scope* Scope::enterScope(Scope* nextScope_t)
{
    if (NULL != nextScope_t) {
        return nextScope_t;
    }

    return s_curScope;
}


Scope* Scope::encloseScope(Scope* curScope_t)
{
    if ((NULL != curScope_t) && (NULL != curScope_t->parent)) {
        return curScope_t->getParent();
    }

    return curScope_t;
}

int Scope::defineSymbol(Symbol* symbol_t)
{
    if (NULL != symbol_t) {

        switch(symbol_t->getSymbolType()) {

        case Symbol::SYMBOL_VAR: {
            symbol_t->setSymbolId();
            symbol_t->setOffset(curStartOffset);
            incCurStartOffset(symbol_t->getByteSize());
            incTotalByteSize(symbol_t->getByteSize());

            addToSymbolSeqList(symbol_t);
            addToSymbolVarMap(symbol_t);
            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        case Symbol::SYMBOL_TEMPVAR: {
            symbol_t->setOffset(curStartOffset);
            incCurStartOffset(symbol_t->getByteSize());
            incTotalByteSize(symbol_t->getByteSize());

            addToSymbolSeqList(symbol_t);
            addToSymbolTempVarMap(symbol_t);
            addToTempVarMap(symbol_t);
            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        case Symbol::SYMBOL_CLASSREFVAR: {
            symbol_t->setOffset(curStartOffset);
            incCurStartOffset(symbol_t->getByteSize());
            incTotalByteSize(symbol_t->getByteSize());

            addToSymbolSeqList(symbol_t);
            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        case Symbol::SYMBOL_CLASSMEMVAR: {
            symbol_t->setOffset(curStartOffset);
            incCurStartOffset(symbol_t->getByteSize());
            incTotalByteSize(symbol_t->getByteSize());

            addToSymbolSeqList(symbol_t);
            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        case Symbol::SYMBOL_CONSTANTVAR: {
            symbol_t->setOffset(curStartOffset);
            incCurStartOffset(symbol_t->getByteSize());
            incTotalByteSize(symbol_t->getByteSize());

            addToSymbolSeqList(symbol_t);
            addToSymbolTempVarMap(symbol_t);
            addToTempVarMap(symbol_t);
            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        case Symbol::SYMBOL_INTEGER_CONSTANT: {
            addToConstantMap(symbol_t);
            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        case Symbol::SYMBOL_CHARACTER_CONSTANT: {
            addToConstantMap(symbol_t);
            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        case Symbol::SYMBOL_FLOATING_CONSTANT: {
            addToConstantMap(symbol_t);
            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        case Symbol::SYMBOL_STRING_LITERAL: {
            addToConstantMap(symbol_t);
            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        case Symbol::SYMBOL_LABEL: {
            addToLabelMap(symbol_t);
            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        default: {
            return 0;
        }

        }


        return 1;

    }

    return 0;
}



/*****************************Context***********************************************/




