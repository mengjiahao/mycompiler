#include "../../include/symbol/Scope.h"
#include "../../include/symbol/Symbol.h"
#include "../../include/LogiMsg.h"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/***********************************Scope***************************************/
map<string, Symbol *> Scope::s_labelMap;
map<string, Symbol *> Scope::s_constMap;
map<string, Symbol *> Scope::s_tempVarMap;
map<unsigned long, Symbol*> Scope::s_allSymbolMap;
list<Scope *> Scope::s_allScopeList;
list<Symbol *> Scope::s_allSymbolList;
Scope *Scope::s_globalScope = NULL;
Scope *Scope::s_curScope = NULL;

Scope::Scope()
{
    scopeId = 0;
    scopeType = SCOPE_INVALID;
    scopeName = "";

    parent = NULL;
    superClass = NULL;

    level = -1;
    curStartOffset = 0;
    totalByteSize = 0;
    funcOffset = -1;
    totalFuncByteSize = 0;

    returnTypeClass = NULL;

    symbolsNo = 0;

    itemcodeVec.clear();
    //paraTypeNum=0;
    //paraType.clear();

    //addToAllScopeList(this);
}

Scope::~Scope()
{
    scopeId = 0;
    scopeType = SCOPE_INVALID;

    parent = NULL;
    superClass = NULL;

    level = -1;
    curStartOffset = 0;
    totalByteSize = 0;
    funcOffset = -1;

    if (NULL != returnTypeClass) {
        delete returnTypeClass;
    }
    returnTypeClass = NULL;

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


void Scope::setFuncOffest(int funcOffset_t)
{
    funcOffset = funcOffset_t;
}

void Scope::incFuncOffset(int incOffset_t)
{
    funcOffset += incOffset_t;
}

int Scope::getFuncOffset()
{
    return funcOffset;
}


void Scope::setTotalFuncByteSize(int totalFuncByteSize_t)
{
    totalFuncByteSize = totalFuncByteSize_t;
}

void Scope::incTotalFuncByteSize(int incByteSize_t)
{
    totalFuncByteSize += incByteSize_t;
}

int Scope::getTotalFuncByteSize()
{
    return totalFuncByteSize;
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
	return NULL;
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
        insertFlag = symbolVarMap.insert( pair<string, Symbol *>(symbolVar_t->getSymbolName(), symbolVar_t) );
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
        insertFlag = symbolTempVarMap.insert( pair<string, Symbol *>(symbolTempVar_t->getSymbolName(), symbolTempVar_t) );
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
        ++symbolsNo;
        return 1;
    }

    return 0;
}

void Scope::clearSymbolSeqList()
{
    symbolSeqList.clear();
}


int Scope::addToLabelMap(Symbol* label_t)
{
    if (NULL != label_t) {
        pair< map<string, Symbol *>::iterator, bool > insertFlag;
        insertFlag = s_labelMap.insert( pair<string, Symbol *>(label_t->getSymbolName(), label_t) );
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
        insertFlag = s_constMap.insert( pair<string, Symbol *>(constant_t->getSymbolName(), constant_t) );
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
        insertFlag = s_tempVarMap.insert( pair<string, Symbol *>(tempVar_t->getSymbolName(), tempVar_t) );
        if (true == insertFlag.second) {
            return 1;
        }
    }

    return 0;
}

Symbol* Scope::searchTempVarMap(const string& tempVarName_t)
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
        insertFlag = s_allSymbolMap.insert( pair<unsigned long, Symbol *>(symbol_t->getSymbolId(), symbol_t) );
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

void Scope::freeAllScopeList()
{
    list<Scope *>::iterator itr;
    int i;
    for (i = 0, itr = Scope::s_allScopeList.begin(); Scope::s_allScopeList.end() != itr; ++itr) {
        delete(*itr);
        ++i;
    }
    cout << "Scope's Num is " << i << endl;

    Scope::s_allScopeList.clear();
}


int Scope::addToAllSymbolList(Symbol* symbol_t)
{
    if (NULL != symbol_t) {
        s_allSymbolList.push_back(symbol_t);
        return 1;
    }

    return 0;
}

void Scope::freeAllSymbolList()
{
    list<Symbol *>::iterator itr;
    int i;
    for (i = 0, itr = Scope::s_allSymbolList.begin(); Scope::s_allSymbolList.end() != itr; ++itr) {
        delete(*itr);
        ++i;
    }
    cout << "Symbol's Num is " << i << endl;

    Scope::s_allSymbolList.clear();
}


void Scope::setCurScope(Scope* curScope_t)
{
    if (NULL != curScope_t) {
        s_curScope = curScope_t;
    }
}

void Scope::setGlobalScope(Scope* globalScope_t)
{
    s_globalScope = globalScope_t;
}

Scope* Scope::getGlobalScope()
{
    return s_globalScope;
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


    /**if (NULL != superClass) {
        curStartOffset = superClass->getTotalByteSize();  //setStartOffset
        totalByteSize = superClass->getTotalByteSize();
    }**/

    curStartOffset = 0;
    totalByteSize = 0;


    returnTypeClass = NULL;

    symbolsNo = 0;
}

void Scope::initGlobalFuncScope(const string& scopeName_t)
{
    scopeType = Scope::SCOPE_GLOBALFUNC;
    scopeName = scopeName_t;

    superClass = NULL;

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

    //Symbol *symbol_t = new Symbol(Symbol::SYMBOL_CLASSREFVAR);
    //defineSymbol(symbol_t);

    curStartOffset = 0;
    totalByteSize = 0;

    returnTypeClass = NULL;

    symbolsNo = 0;
}

void Scope::initLocalScope()
{
    scopeType = Scope::SCOPE_LOCAL;
    scopeName = "LocalScope";

    superClass = NULL;

    curStartOffset = 0;
    totalByteSize = 0;

    returnTypeClass = NULL;

    symbolsNo = 0;

}

void Scope::initGlabalFuncDeclScope(const string& scopeName_t)
{
    scopeType = Scope::SCOPE_GLOBALFUNCDECL;
    scopeName = scopeName_t;

    superClass = NULL;

    curStartOffset = 0;
    totalByteSize = 0;

    returnTypeClass = NULL;

    symbolsNo = 0;

}

Scope* Scope::pushScope(Scope* curScope_t, Scope* newScope_t)
{
    if (NULL != newScope_t) {

        if ( (NULL == curScope_t) && (Scope::SCOPE_GLOBAL == newScope_t->getScopeType()) ) {

            goto then_push;

        } else if ( NULL != curScope_t && (Scope::SCOPE_GLOBAL == curScope_t->getScopeType())
        && ( (Scope::SCOPE_CLASS == newScope_t->getScopeType())
        || (Scope::SCOPE_GLOBALFUNC == newScope_t->getScopeType())
        || (Scope::SCOPE_GLOBALFUNCDECL == newScope_t->getScopeType())
        || (Scope::SCOPE_GLOBALFUNCCHAN == newScope_t->getScopeType()) ) ) {

            goto then_push;

        } else if ( NULL != curScope_t && (Scope::SCOPE_CLASS == curScope_t->getScopeType())
        && (Scope::SCOPE_CLASSFUNC == newScope_t->getScopeType()) ) {

            goto then_push;

        } else if ( NULL != curScope_t && (Scope::SCOPE_GLOBALFUNC == curScope_t->getScopeType())
        && (Scope::SCOPE_LOCAL == newScope_t->getScopeType())  ) {

            goto then_push;

        } else if ( NULL != curScope_t && (Scope::SCOPE_GLOBALFUNCCHAN == curScope_t->getScopeType())
        && (Scope::SCOPE_LOCAL == newScope_t->getScopeType())  ) {

            goto then_push;

        } else if ( NULL != curScope_t && (Scope::SCOPE_CLASSFUNC == curScope_t->getScopeType())
        && (Scope::SCOPE_LOCAL == newScope_t->getScopeType()) ) {

            goto then_push;

        } else if ( NULL != curScope_t && (Scope::SCOPE_LOCAL == curScope_t->getScopeType())
        && (Scope::SCOPE_LOCAL == newScope_t->getScopeType()) ) {

            goto then_push;

        } else {
            return NULL;
        }

then_push:


        if (NULL != curScope_t) {

            //guarantee no func or class has the same name with others
            curScope_t->addChild(newScope_t);
            newScope_t->setParent(curScope_t);
            newScope_t->setLevel(curScope_t->getlevel() + 1);


        } else {  //globalScope init

            newScope_t->setParent(NULL);
            newScope_t->setLevel(0);
        }

        newScope_t->setScopeId();  //distribute id for new scope
        addToAllScopeList(newScope_t);

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
    if ((NULL != curScope_t)) {
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

            addToSymbolSeqList(symbol_t);
            addToSymbolVarMap(symbol_t);

            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        case Symbol::SYMBOL_PARAMVAR: {
            symbol_t->setSymbolId();

            addToSymbolSeqList(symbol_t);

            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);
            break;
        }

        case Symbol::SYMBOL_TEMPVAR: {
            symbol_t->setSymbolId();

            string tmpVarName("@t");
            stringstream ss;
            string tmpStrId;
            ss << symbol_t->getSymbolId();
            ss >> tmpStrId;
            tmpVarName += tmpStrId;

            symbol_t->setSymbolName(tmpVarName);

            addToSymbolSeqList(symbol_t);
            addToSymbolTempVarMap(symbol_t);

            addToTempVarMap(symbol_t);

            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        case Symbol::SYMBOL_CLASSREFVAR: {
            symbol_t->setSymbolId();

            addToSymbolSeqList(symbol_t);
            addToSymbolVarMap(symbol_t);

            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        case Symbol::SYMBOL_CLASSMEMVAR: {
            symbol_t->setSymbolId();

            addToSymbolSeqList(symbol_t);
            addToSymbolVarMap(symbol_t);

            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        case Symbol::SYMBOL_CONSTANTVAR: {
            symbol_t->setSymbolId();

            addToSymbolSeqList(symbol_t);
            addToSymbolVarMap(symbol_t);

            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        case Symbol::SYMBOL_INTEGER_CONSTANT: {
            symbol_t->setSymbolId();

            addToConstantMap(symbol_t);

            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        case Symbol::SYMBOL_CHARACTER_CONSTANT: {
            symbol_t->setSymbolId();

            addToConstantMap(symbol_t);

            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        case Symbol::SYMBOL_FLOATING_CONSTANT: {
            symbol_t->setSymbolId();

            addToConstantMap(symbol_t);

            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        case Symbol::SYMBOL_STRING_LITERAL: {
            symbol_t->setSymbolId();

            addToConstantMap(symbol_t);

            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        case Symbol::SYMBOL_LABEL: {
            symbol_t->setSymbolId();

            string labelVarName(".l");
            stringstream ss;
            string tmpStrId;
            ss << symbol_t->getSymbolId();
            ss >> tmpStrId;
            labelVarName += tmpStrId;

            symbol_t->setSymbolName(labelVarName);

            addToLabelMap(symbol_t);

            addToAllSymbolMap(symbol_t);
            addToAllSymbolList(symbol_t);

            break;
        }

        default: {

            /*std::cout<<"error in defineSymbol(): SymbolType is invalid"<<std::endl;*/
            LogiMsg::logi("error in Scope::defineSymbol(): SymbolType is invalid");
            return 0;
        }

        }


        return 1;

    }

    return 0;
}


Symbol* Scope::resolveSymbol(const string& symbolName_t, Symbol::SymbolType symbolType_t)
{
    switch (symbolType_t) {
    case Symbol::SYMBOL_VAR:
    case Symbol::SYMBOL_CLASSREFVAR:
    case Symbol::SYMBOL_CONSTANTVAR: {
        return searchDownUpSymbolVarMap(Scope::s_curScope, symbolName_t);
        break;
    }
    case Symbol::SYMBOL_PARAMVAR: {
        return searchSymbolVarMap(symbolName_t);
        break;
    }
    case Symbol::SYMBOL_TEMPVAR: {
        return searchTempVarMap(symbolName_t);
        break;
    }
    case Symbol::SYMBOL_INTEGER_CONSTANT:
    case Symbol::SYMBOL_CHARACTER_CONSTANT:
    case Symbol::SYMBOL_FLOATING_CONSTANT:
    case Symbol::SYMBOL_STRING_LITERAL: {
        return searchConstantMap(symbolName_t);
        break;
    }
    case Symbol::SYMBOL_LABEL: {
        return searchLabelMap(symbolName_t);
        break;
    }
    default: {
        /*std::cout<<"error in resolveSymbol(): SymbolType is invalid"<<std::endl;*/
        LogiMsg::logi("error in resolveSymbol(): SymbolType is invalid");
        return NULL;
    }

    }

    return NULL;

}


Symbol* Scope::resolveSymbolMemVar(Scope* classScope_t, const string &symbolName_t)
{
    if (NULL == classScope_t ) {
        return NULL;
    }

    /*while(Scope::SCOPE_CLASS != classScope_t->scopeType)
    {
        classScope_t = classScope_t->getParent();
    }*/

    Symbol *result = classScope_t->searchSymbolVarMap(symbolName_t);

    if (NULL != result) {
        return result;
    } else {

        if ( (Scope::SCOPE_CLASS == classScope_t->scopeType) && (NULL != classScope_t->superClass) ) {
            result = resolveSymbolMemVar(classScope_t->superClass, symbolName_t);
            if (NULL != result) {
                return result;
            }
        }
    }

    return NULL;

}

Scope* Scope::resolveScope(const string& scopeName_t, Scope::ScopeType scopeType_t)
{
    if (NULL != s_globalScope) {
        Scope *scope_t = s_globalScope->searchChildName(scopeName_t);
        if ( (NULL != scope_t) && (scopeType_t == scope_t->getScopeType()) ) {
            return scope_t;
        }
    }

    return NULL;
}

Scope* Scope::resolveClassFuncScope(Scope* classScope_t, const string& scopeName_t)
{
    if (NULL == classScope_t ) {
        return NULL;
    }

    while (Scope::SCOPE_CLASS != classScope_t->getScopeType()) {
        classScope_t = classScope_t->getParent();
    }  //for class member func

    Scope *scope_t = classScope_t->searchChildName(scopeName_t);

    if ( (NULL != scope_t) && (Scope::SCOPE_CLASSFUNC == scope_t->getScopeType()) ) {
        return scope_t;
    } else {
        if (NULL != classScope_t->superClass) {
            scope_t = resolveClassFuncScope(classScope_t->superClass, scopeName_t);
            if (NULL != scope_t) {
                return scope_t;
            }
        }

    }
    return NULL;
}

Scope* Scope::resolveGlobalFuncScope(const string& scopeName_t)
{
    if (NULL != s_globalScope) {
        Scope *scope_t = s_globalScope->searchChildName(scopeName_t);
        if ( (NULL != scope_t) ) {
            if ( (scope_t->getScopeType() == Scope::SCOPE_GLOBALFUNC)
            || (scope_t->getScopeType() == Scope::SCOPE_GLOBALFUNCDECL)
            || (scope_t->getScopeType() == Scope::SCOPE_GLOBALFUNCCHAN) ) {
                return scope_t;
            }
        }
    }

    return NULL;

}



void Scope::printScopeTree()
{
    ofstream ofs;
    /*cout << ">>>printScopeTree in SymbolTable.txt" << endl;*/
    LogiMsg::logi(">>>printScopeTree in SymbolTable.txt");

    ofs.open("SymbolTable.txt");

    if (NULL != s_globalScope) {
        s_globalScope->printScope(ofs);
    }

    ofs.close();

}



void Scope::printScope(ofstream &ofs_t)
{
    if (ofs_t.is_open()) {
        ofs_t << "$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n";
        ofs_t << "$Scope: " << scopeId << " " << scopeType << " " << scopeName << "\n";
        ofs_t << "$level: " << level << " " << curStartOffset << " " << totalByteSize << " "
        << funcOffset << " " << totalFuncByteSize << "\n";
        ofs_t << "$returnTypeClass:\n";
        if (NULL != returnTypeClass) {
            returnTypeClass->printTypeClass(ofs_t);
        } else {
            ofs_t << "      has no returnTypeClass\n";
        }

        ofs_t << "$symbolSeqList:\n";
        list<Symbol *>::iterator seqItr;
        if (!symbolSeqList.empty()) {
            for(seqItr = symbolSeqList.begin(); seqItr != symbolSeqList.end(); ++seqItr) {
            if (NULL != (*seqItr)) {
                (*seqItr)->printSymbol(ofs_t);
            }
        }
        } else {
            ofs_t << "      symbolSeqList has no symbols\n";
        }

        vector<Scope *>::iterator childItr;
        for(childItr = childs.begin(); childItr != childs.end(); ++childItr) {
            if (NULL != (*childItr)) {
                (*childItr)->printScope(ofs_t);
            }
        }


    } else {
        /*std::cout << "error in printScope(): SymbolTable.txt is not open" << std::endl;*/
        LogiMsg::logi("error in printScope(): SymbolTable.txt is not open");

    }


}

Scope*  Scope::resolveMemFunByName(const string& funcName_t)
{
    Scope *scope_t = searchChildName(funcName_t);
    if (scope_t)
    {
        return scope_t;
    }
    if (superClass)
        return superClass->resolveMemFunByName(funcName_t);
    else
        return NULL;
}


Scope* Scope::searchChildOffset(int funcOffset_t)
{
    vector<Scope *>::iterator itr;

    for(itr = childs.begin(); itr != childs.end(); ++itr) {
        if ( funcOffset_t == ( (*itr)->getFuncOffset() ) ) {
            return *itr;
        }
    }
	return NULL;
}

Scope*  Scope::resolveMemFunByOffset(int funcOffset_t)
{
    Scope *scope_t = searchChildOffset(funcOffset_t);
    if (scope_t)
    {
        return scope_t;
    }
    if (superClass)
        return superClass->resolveMemFunByOffset(funcOffset_t);
    else
        return NULL;
}





void Scope::addItemCode(ItmCode *itmcode_t)
{
    itmcode_t->setCodeId();
    ItmCode::addToAllItmCode(itmcode_t);
    itemcodeVec.push_back(itmcode_t);

}


/*void Scope::addParaType(TypeClass *type_t)
{
    TypeClass tmp;
    tmp.clone(type_t);
    paraType.push_back(tmp);
    ++paraTypeNum;
}*/



