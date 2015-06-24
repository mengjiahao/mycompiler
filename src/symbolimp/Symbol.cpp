#include "../../include/symbol/Symbol.h"
#include "../../include/symbol/Scope.h"

#include <iostream>
#include <fstream>


using namespace std;

/************************TypeClass*****************************************/

TypeClass::TypeClass()
{
    storageType = TypeClass::STOR_INVALID;
    typeSfType = TypeClass::SF_INVALID;
    typeQfType = TypeClass::QF_INVALID;
    scopeType = NULL;
    isArray = false;

}

TypeClass::~TypeClass()
{
    storageType = TypeClass::STOR_INVALID;
    typeSfType = TypeClass::SF_INVALID;
    typeQfType = TypeClass::QF_INVALID;
    scopeType = NULL;
    isArray = false;
    dimensions.clear();
}

void TypeClass::clearTypeClass()
{
    storageType = TypeClass::STOR_INVALID;
    typeSfType = TypeClass::SF_INVALID;
    typeQfType = TypeClass::QF_INVALID;
    scopeType = NULL;
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
    scopeType = typeClass_t->scopeType;
    isArray = typeClass_t->getIsArray();
    dimensions = typeClass_t->getDimensions();
}

void TypeClass::setStorageType(TypeClass::StorageType storageType_t)
{
    storageType |= storageType_t;
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

void TypeClass::setScopeType(Scope* scopeType_t)
{
    if (NULL != scopeType_t) {
        scopeType = scopeType_t;
    }
}

Scope* TypeClass::getScopeType()
{
    return scopeType;
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

int TypeClass::checkType()
{

    return 0;
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

void TypeClass::printTypeClass(ofstream& ofs_t)
{
    if (ofs_t.is_open()) {
        ofs_t << "#typeClass: " << storageType << " " << typeSfType << " " << typeQfType << "\n";
        if (NULL != scopeType) {
            ofs_t << "#refClassScope: " << scopeType->getScopeName() << "\n";
        }

        ofs_t << "#isArray: " << isArray << "\n";
        if (isArray) {
        ofs_t << "#dimensions: ";
        for(int i = 0; i < dimensions.size(); ++i) {
            ofs_t << dimensions[i] << " ";
        }
        ofs_t << "\n";
        }

    } else {
        std::cout << "error in printTypeClass(): SymbolTable.txt is not open" << std::endl;
    }
}



int TypeClass::compare(TypeClass* a, TypeClass* b)
{
    return 0;
}

static int getSfTypeMatrixNo(TypeClass* a)
{
    if (NULL == a) {
        return 0;
    }

    int no;

    if (a->getTypeSfType() & TypeClass::SF_INVALID) {
        return 0;

    } else if (a->getTypeSfType() & TypeClass::SF_VOID) {
        return 1;

    } else if (a->getTypeSfType() & TypeClass::SF_CHAR) {
        no = 2;

    } else if (a->getTypeSfType() & TypeClass::SF_SHORT) {
        no = 3;

    } else if (a->getTypeSfType() & TypeClass::SF_INT) {
        no = 4;

    } else if (a->getTypeSfType() & TypeClass::SF_LONG) {
        no = 5;

    } else if (a->getTypeSfType() & TypeClass::SF_FLOAT) {
        return 6;

    } else if (a->getTypeSfType() & TypeClass::SF_DOUBLE) {
        return 7;

    } else {
        return 0;
    }

    if (a->getTypeSfType() & TypeClass::SF_UNSIGNED) {
        no += 6;
    } else {
    }

    return no;
}

int TypeClass::promoteType(TypeClass* a, TypeClass* b)
{
    static int s_promoteMatrix[12][12] = {
        //SF_INVALID
     {SF_INVALID, SF_INVALID, SF_INVALID, SF_INVALID, SF_INVALID, SF_INVALID,
     SF_INVALID, SF_INVALID, SF_INVALID, SF_INVALID, SF_INVALID, SF_INVALID},

        //SF_VOID
     {SF_INVALID, SF_VOID, SF_VOID, SF_VOID, SF_VOID, SF_VOID,
     SF_VOID, SF_VOID, SF_VOID, SF_VOID, SF_VOID, SF_VOID},

        //SF_CHAR
     {SF_INVALID, SF_VOID, SF_CHAR, SF_SHORT, SF_INT, SF_LONG, SF_FLOAT, SF_DOUBLE,
     SF_CHAR, SF_SHORT, SF_INT, SF_LONG},

        //SF_SHORT
     {SF_INVALID, SF_VOID, SF_SHORT, SF_SHORT, SF_INT, SF_LONG, SF_FLOAT, SF_DOUBLE,
     SF_SHORT, SF_SHORT, SF_INT, SF_LONG},

        //SF_INT
     {SF_INVALID, SF_VOID, SF_INT, SF_INT, SF_INT, SF_LONG, SF_FLOAT, SF_DOUBLE,
     SF_INT, SF_INT, SF_INT, SF_LONG},

        //SF_LONG
     {SF_INVALID, SF_VOID, SF_LONG, SF_LONG, SF_LONG, SF_LONG, SF_FLOAT, SF_DOUBLE,
     SF_LONG, SF_LONG, SF_LONG, SF_LONG},

        //SF_FLOAT
     {SF_INVALID, SF_VOID, SF_FLOAT, SF_FLOAT, SF_FLOAT, SF_FLOAT, SF_FLOAT, SF_DOUBLE,
     SF_FLOAT, SF_FLOAT, SF_FLOAT, SF_FLOAT},

        //SF_DOUBLE
     {SF_INVALID, SF_VOID, SF_DOUBLE, SF_DOUBLE, SF_DOUBLE, SF_DOUBLE, SF_DOUBLE, SF_DOUBLE,
     SF_DOUBLE, SF_DOUBLE, SF_DOUBLE, SF_DOUBLE},

        //SF_CHAR & SF_UNSIGNED
     {SF_INVALID, SF_VOID, SF_CHAR, SF_SHORT, SF_INT, SF_LONG, SF_FLOAT, SF_DOUBLE,
     SF_CHAR & SF_UNSIGNED, SF_SHORT & SF_UNSIGNED, SF_INT & SF_UNSIGNED,
     SF_LONG & SF_UNSIGNED},

        //SF_SHORT & SF_UNSIGNED
     {SF_INVALID, SF_VOID, SF_SHORT & SF_UNSIGNED, SF_SHORT, SF_INT, SF_LONG, SF_FLOAT, SF_DOUBLE,
     SF_SHORT & SF_UNSIGNED, SF_SHORT & SF_UNSIGNED, SF_INT & SF_UNSIGNED,
     SF_LONG & SF_UNSIGNED},

        //SF_INT & SF_UNSIGNED
     {SF_INVALID, SF_VOID, SF_INT & SF_UNSIGNED, SF_INT & SF_UNSIGNED, SF_INT, SF_LONG, SF_FLOAT, SF_DOUBLE,
     SF_INT & SF_UNSIGNED, SF_INT & SF_UNSIGNED, SF_INT & SF_UNSIGNED,
     SF_LONG & SF_UNSIGNED},

        //SF_LONG & SF_UNSIGNED
     {SF_INVALID, SF_VOID, SF_LONG & SF_UNSIGNED, SF_LONG & SF_UNSIGNED, SF_LONG & SF_UNSIGNED,
     SF_LONG, SF_FLOAT, SF_DOUBLE,
     SF_LONG & SF_UNSIGNED, SF_LONG & SF_UNSIGNED, SF_LONG & SF_UNSIGNED,
     SF_LONG & SF_UNSIGNED},

    };

    if (NULL == a || NULL == b) {
        return TypeClass::SF_INVALID;
    }

    int row = getSfTypeMatrixNo(a);
    int column = getSfTypeMatrixNo(b);

    return s_promoteMatrix[row][column];


}





bool TypeClass::judgeType(TypeClass *type1_t,TypeClass *type2_t, int lineno)
{
    if (NULL == type1_t || NULL == type2_t) {
        return false;
    }

    if (type1_t->scopeType || type2_t->scopeType
    || type2_t->getStorageType() != TypeClass::STOR_INVALID
    || type2_t->getTypeSfType() != TypeClass::SF_INVALID
    || type2_t->getTypeQfType() != TypeClass::QF_INVALID) {

        std::cout<<"error in TypeClass: class type should not be used with other type at line "
        <<lineno<<std::endl;
        return false;
    }

    if ((type1_t->getStorageType()!=TypeClass::STOR_INVALID) && (type2_t->getStorageType()!=TypeClass::STOR_INVALID))
    {
        std::cout<<"error in TypeClass: redundant storage type at line "<<lineno<<std::endl;
        return false;
    }

    if ((type1_t->getTypeSfType()&TypeClass::SF_SIGNED) || (type1_t->getTypeSfType()&TypeClass::SF_UNSIGNED) )
    {
        if ((type2_t->getTypeSfType()&TypeClass::SF_UNSIGNED)
        || (type2_t->getTypeSfType()&TypeClass::SF_SIGNED)
        || (type2_t->getTypeSfType()&TypeClass::SF_DOUBLE)
        || (type2_t->getTypeSfType()&TypeClass::SF_FLOAT)
        || (type2_t->getTypeSfType()&TypeClass::SF_VOID))
        {
           std::cout<<"error in TypeClass: specifier type "
           <<  type1_t->getTypeSfType() << " & " << type2_t->getTypeSfType()
           << " are conflict at line "<<lineno<<std::endl;
           return false;
        }
    }
    if ((type2_t->getTypeSfType()&TypeClass::SF_SIGNED) || (type2_t->getTypeSfType()&TypeClass::SF_UNSIGNED) )
    {
        if ((type1_t->getTypeSfType()&TypeClass::SF_UNSIGNED)
        || (type1_t->getTypeSfType()&TypeClass::SF_SIGNED)
        || (type1_t->getTypeSfType()&TypeClass::SF_DOUBLE)
        || (type1_t->getTypeSfType()&TypeClass::SF_FLOAT)
        || (type1_t->getTypeSfType()&TypeClass::SF_VOID))
        {
           std::cout<<"error in TypeClass: specifier type "
           <<  type1_t->getTypeSfType() << " & " << type2_t->getTypeSfType()
           << " are conflict at line "<<lineno<<std::endl;
           return false;
        }
    }
    if ((type1_t->getTypeSfType()&TypeClass::SF_FLOAT) || (type1_t->getTypeSfType()&TypeClass::SF_DOUBLE) )
    {
        if (type2_t->getTypeSfType()!=TypeClass::SF_INVALID)
        {
           std::cout<<"error in TypeClass: specifier type is redefined with float or double at line "
           <<lineno<<std::endl;
           return false;
        }
    }
    if ((type2_t->getTypeSfType()&TypeClass::SF_FLOAT) || (type2_t->getTypeSfType()&TypeClass::SF_DOUBLE) )
    {
        if (type1_t->getTypeSfType()!=TypeClass::SF_INVALID)
        {
           std::cout<<"error in TypeClass: specifier type is redefined with float or double at line "
           <<lineno<<std::endl;
           return false;
        }
    }
    if (type1_t->getTypeSfType()&TypeClass::SF_VOID)
    {
        if (type2_t->getTypeSfType()!=TypeClass::SF_INVALID)
        {
           std::cout<<"error in TypeClass: specifier type is redefined with void at line "
           <<lineno<<std::endl;
           return false;
        }
    }
    if (type2_t->getTypeSfType()&TypeClass::SF_VOID)
    {
        if (type1_t->getTypeSfType()!=TypeClass::SF_INVALID)
        {
           std::cout<<"error in TypeClass: specifier type is redefined with void at line "
           <<lineno<<std::endl;
           return false;
        }
    }
    if (type1_t->getTypeSfType()&TypeClass::SF_LONG)
    {
        if (type2_t->getTypeSfType()&TypeClass::SF_SHORT)
        {
           std::cout<<"error in TypeClass: specifier type long and short are conflict at line "
           <<lineno<<std::endl;
           return false;
        }
    }
    if (type2_t->getTypeSfType()&TypeClass::SF_LONG)
    {
        if (type1_t->getTypeSfType()&TypeClass::SF_SHORT)
        {
           std::cout<<"error in TypeClass: specifier type long and short are conflict at line "
           <<lineno<<std::endl;
           return false;
        }
    }
    if (type1_t->getTypeSfType()&TypeClass::SF_CHAR)
    {
        if ((type2_t->getTypeSfType()&TypeClass::SF_SHORT)
        || (type2_t->getTypeSfType()&TypeClass::SF_LONG)
        || (type2_t->getTypeSfType()&TypeClass::SF_INT))
        {
            std::cout<<"error in TypeClass: specifier type char and integer(short, int, long) are conflict at line "
            <<lineno<<std::endl;
            return false;
        }
    }
    if (type2_t->getTypeSfType()&TypeClass::SF_CHAR)
    {
        if ((type1_t->getTypeSfType()&TypeClass::SF_SHORT)
        || (type1_t->getTypeSfType()&TypeClass::SF_LONG)
        || (type1_t->getTypeSfType()&TypeClass::SF_INT))
        {
            std::cout<<"error in TypeClass: specifier type char and integer(short, int, long) are conflict at line "
            <<lineno<<std::endl;
            return false;
        }
    }
    if (type1_t->getTypeSfType() & type2_t->getTypeSfType())
    {
        std::cout<<"error in TypeClass: redundant specifier type at line: "<<lineno<<std::endl;
        return false;
    }

    if (type1_t->getTypeQfType() & type2_t->getTypeQfType())
    {
        std::cout<<"error in TypeClass: redundant qualifier type at line: "<<lineno<<std::endl;
        return false;
    }

    return true;
}


/***********************************Symbol*********************************************/

Symbol::Symbol()
{
    symbolId = 0;
    symbolType = Symbol::SYMBOL_INVALID;

    offset = 0;
    byteSize = 0;

}

Symbol::Symbol(Symbol::SymbolType symbolType_t)
{
    symbolId = 0;
    symbolType = symbolType_t;

    offset = 0;
    byteSize = 0;
}


Symbol::~Symbol()
{
    symbolId = 0;
    symbolValue.clear();
    symbolType = Symbol::SYMBOL_INVALID;

    typeClass.clearTypeClass();

    offset = 0;
    byteSize = 0;
}

void Symbol::clearSymbol()
{
    symbolId = 0;
    symbolValue.clear();
    symbolType = Symbol::SYMBOL_INVALID;

    typeClass.clearTypeClass();

    offset = 0;
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

void Symbol::setSymbolName(const string &symbolName_t)
{
    symbolName = symbolName_t;
}

string Symbol::getSymbolName()
{
    return symbolName;
}


void Symbol::addSymbolValue(const string &symbolValue_t)
{
    if ( ( (0 == symbolValue.size()) && (false == typeClass.getIsArray()) )
    || (true == typeClass.getIsArray()) ) {
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


TypeClass* Symbol::getTypeClass()
{
    return &typeClass;
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
    case SYMBOL_PARAMVAR: {
        byteSize = 0;
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

unsigned Symbol::getByteSize()
{
    computeByteSize();
    return byteSize;
}

void Symbol::printSymbol(ofstream& ofs_t)
{
    if (ofs_t.is_open()) {
        ofs_t << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        ofs_t << "@Symbol: " << symbolId << " " << symbolType << " " << symbolName << "\n";
        ofs_t << "@SymbolValue: ";
        for(int i = 0; i < symbolValue.size(); ++i) {
            ofs_t << symbolValue[i] << " ";
        }
        ofs_t << "\n";
        ofs_t << "@offset&&byteSize: " << offset << " " << byteSize << "\n";
        typeClass.printTypeClass(ofs_t);
        ofs_t << "@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";

    } else {
        std::cout << "error in printSymbol(): SymbolTable.txt is not open" << std::endl;
    }
}


/****************************
FuncSymble::FuncSymble()
{
	symbolType=SYMBOL_LABEL;
	arguNum=0;
}

void FuncSymble::addArgu(TypeClass *type)
{
	argu.push_back(type);
	arguNum++;
}*****************************/







