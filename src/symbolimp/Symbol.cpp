#include "../../include/symbol/Symbol.h"

using namespace std;

/************************TypeClass*****************************************/

TypeClass::TypeClass()
{
    storageType = TypeClass::STOR_INVALID;
    typeSfType = TypeClass::SF_INVALID;
    typeQfType = TypeClass::QF_INVALID;

    isArray = false;

}

TypeClass::~TypeClass()
{
    storageType = TypeClass::STOR_INVALID;
    typeSfType = TypeClass::SF_INVALID;
    typeQfType = TypeClass::QF_INVALID;

    isArray = false;
    dimensions.clear();
}

void TypeClass::clearTypeClass()
{
    storageType = TypeClass::STOR_INVALID;
    typeSfType = TypeClass::SF_INVALID;
    typeQfType = TypeClass::QF_INVALID;

    isArray = false;
    dimensions.clear();
}


void TypeClass::clone(TypeClass *typeClass_t)
{
    if (NULL == typeClass_t)
        return;

    storageType = typeClass_t->getStorageType();
    typeSfType = typeClass_t->getTypeSfType();
    typeQfType = typeClass_t->getTypeQfType();

    isArray = typeClass_t->getIsArray();
    dimensions = typeClass_t->getDimensions()
}

void TypeClass::setStorageType(TypeClass::StorageType storageType_t)
{
    storageType = storageType_t;
}

int TypeClass::getStorageType()
{
    return storageType;
}

void TypeClass::setTypeSfType(TypeClass::TypeSfType typeSfType_t)
{
    typeSfType |= typeSfType_t;
}

int TypeClass::getTypeSfType()
{
    return typeSfType;

}

void TypeClass::setTypeQfType(TypeClass::TypeQfType typeQfType_t)
{
    typeQfType |= typeQfType_t;
}

int TypeClass::getTypeQfType()
{
    return typeQfType;
}

void TypeClass::setIsArray(bool isArray_t)
{
    isArray = isArray_t;
}

bool TypeClass::getIsArray()
{
    return isArray;
}

void TypeClass::addDimensions(int dim_t)
{
    dimensions.push_back(dim_t);
}

vector<int> TypeClass::getDimensions()
{
    return dimensions;
}

void TypeClass::checkType()
{

}

unsigned int TypeClass::getTypeByteSize()
{
    unsigned int elemSize = 0;

    if (typeSfType & SF_CHAR) {
        elemSize = 1;
    } else if (typeSfType & SF_SHORT) {
        elemSize = 2;
    } else if (typeSfType & SF_INT) {
        elemSize = 4;
    } else if (typeSfType & SF_LONG) {
        elemSize = 4;
    } else if (typeSfType & SF_FLOAT) {
        elemSize = 4;
    } else if (typeSfType & SF_DOUBLE) {
        elemSize = 8;
    }

    if (true == isArray) {
        vector<int>::iterator itr;
        unsigned int elemsNo = 1;
        for (itr = dimensions.begin(); itr != dimensions.end(); ++itr) {
            elemsNo *= *itr;
        }
        elemSize *= elemsNo;
    }

    return elemSize;
}


int TypeClass::compare(TypeClass* a, TypeClass* b)
{

}



/***********************************Symbol*********************************************/

Symbol::Symbol()
{
    symbolId = 0;
    symbolType = Symbol::SYMBOL_INVALID;

    offset = -1;
    byteSize = 0;

}

Symbol::Symbol(Symbol::SymbolType symbolType_t)
{
    symbolId = 0;
    symbolType = symbolType_t;

    offset = -1;
    byteSize = 0;
}


Symbol::~Symbol()
{
    symbolId = 0;
    symbolValue.clear();
    symbolType = Symbol::SYMBOL_INVALID;

    typeClass.clearTypeClass();

    offset = -1;
    byteSize = 0;
}

void Symbol::clearSymbol()
{
    symbolId = 0;
    symbolValue.clear();
    symbolType = Symbol::SYMBOL_INVALID;

    typeClass.clearTypeClass();

    offset = -1;
    byteSize = 0;
}

void Symbol::setSymbolId()
{
    static unsigned long s_symbolId = 0;
    symbolId = ++s_symbolId;
}

unsigned long Symbol::getSymbolId()
{
    return symbolId;
}

void Symbol::setSymbolType(Symbol::SymbolType symbolType_t)
{
    symbolType = symbolType_t;
}

Symbol::SymbolType Symbol::getSymbolType()
{
    return symbolType;
}

void Symbol::addSymbolName(const string &symbolName_t)
{
    symbolName = symbolName_t;
}

string Symbol::getSymbolName()
{
    return symbolName;
}


void Symbol::addSymbolValue(const string &symbolValue_t)
{
    if ( (0 == symbolValue.size()) && (false == typeClass.isArray())
    || (true == typeClass.isArray()) ) {
        symbolValue.push_back(symbolValue_t);
    }
}

vector<string> Symbol::getSymbolValue()
{
    return symbolValue;
}

string Symbol::getFirstSymbolValue()
{
    if (symbolValue.size() > 0) {
        return symbolValue.at(0);
    }

    return string("");
}

void Symbol::setRefScope(Scope* refScope_t)
{
    refScope = refScope_t;
}

Scope* Symbol::getRefScope()
{
    return refScope;
}


void Symbol::setTypeClass(TypeClass* typeClass_t)
{
    if (NULL == typeClass_t)
        return;

    typeClass.clone(typeClass_t);
}


TypeClass Symbol::getTypeClass()
{
    return typeClass;
}

void Symbol::setOffset(int offset_t)
{
    offset = offset_t;
}

int Symbol::getOffset()
{
    return offset;
}

void Symbol::setByteSize(unsigned int byteSize_t)
{
    byteSize = byteSize_t;
}

void Symbol::computeByteSize()
{
    switch(symbolType) {
    case SYMBOL_INTEGER_CONSTANT: {
        byteSize = 4;
        break;
    }
    case SYMBOL_CHARACTER_CONSTANT: {
        byteSize = 1;
        break;
    }
    case SYMBOL_FLOATING_CONSTANT: {
        byteSize = typeClass.getTypeByteSize();
        break;
    }
    case SYMBOL_STRING_LITERAL: {
        byteSize = symbolName.size() - 2;
        break;
    }
    case SYMBOL_VAR: {
        byteSize = typeClass.getTypeByteSize();
        break;
    }
    case SYMBOL_CLASSREFVAR: {
        byteSize = 4;
        break;
    }
    case SYMBOL_CONSTANTVAR: {
        byteSize = typeClass.getTypeByteSize();
        break;
    }
    case SYMBOL_TEMPVAR: {
        byteSize = typeClass.getTypeByteSize();
        break;
    }
    case SYMBOL_CLASSMEMVAR: {
        byteSize = typeClass.getTypeByteSize();
        break;
    }
    case SYMBOL_LABEL: {
        byteSize = 4;
        break;
    }
    default: {
        byteSize = 0;
        break;
    }

    }
}

int Symbol::getByteSize()
{
    computeByteSize();
    return byteSize;
}

void Symbol::printSymbol()
{

}











