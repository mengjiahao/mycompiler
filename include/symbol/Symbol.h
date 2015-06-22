#ifndef INCLUDE_SYMBOL_H
#define INCLUDE_SYMBOL_H

#include <string>
#include <vector>
//#include "Scope.h"
#include <cstdlib>
using namespace std;


/*********************************TypeClass*****************************************/

class Scope;

class TypeClass {
public:
    enum StorageType {STOR_INVALID = 0, STOR_EXTERN = 1, STOR_STATIC = 2,
    STOR_AUTO = 4, STOR_REGISTER = 8};

    enum TypeSfType {SF_INVALID = 0, SF_VOID = 1, SF_CHAR = 2, SF_SHORT = 4, SF_INT = 8,
    SF_LONG = 16, SF_FLOAT = 32, SF_DOUBLE = 64, SF_SIGNED = 128, SF_UNSIGNED = 256};

    enum TypeQfType {QF_INVALID = 0, QF_CONST = 1, QF_VOLATILE = 2, QF_VIRTUAL = 4};

    int storageType;
    int typeSfType;
    int typeQfType;
    Scope *scopeType;      //用于类型是类的情况
    bool isArray;
    vector<int> dimensions;

public:
    TypeClass();
    virtual ~TypeClass();

    virtual void clearTypeClass();

    virtual void clone(TypeClass *typeClass_t);

    virtual void setStorageType(TypeClass::StorageType storageType_t);
    virtual int getStorageType();

    virtual void setTypeSfType(TypeClass::TypeSfType typeSfType_t);
    virtual int getTypeSfType();

    virtual void setTypeQfType(TypeClass::TypeQfType typeQfType_t);
    virtual int getTypeQfType();

    virtual void setIsArray(bool isArray_t);
    virtual bool getIsArray();

    virtual void addDimensions(int dim_t);
    virtual vector<int> getDimensions();

    virtual int checkType();

    virtual unsigned int getTypeByteSize();

    virtual void printTypeClass(ofstream &ofs_t);
    static void judgetType(TypeClass *type1_t,TypeClass *type2_t, int lineno);
    static int compare(TypeClass *a, TypeClass *b);
};


/************************************Symbol************************************************/

class Symbol {

public:

    enum SymbolType {SYMBOL_INVALID, SYMBOL_INTEGER_CONSTANT, SYMBOL_CHARACTER_CONSTANT,
    SYMBOL_FLOATING_CONSTANT, SYMBOL_STRING_LITERAL, SYMBOL_VAR, SYMBOL_PARAMVAR, SYMBOL_CLASSREFVAR,
    SYMBOL_CONSTANTVAR, SYMBOL_TEMPVAR, SYMBOL_CLASSMEMVAR, SYMBOL_LABEL};


    unsigned long symbolId;
    SymbolType symbolType;
    string symbolName;

    vector<string> symbolValue;

    Scope *refScope;


    TypeClass typeClass;

    int offset;
    unsigned int byteSize;



public:

    Symbol();
    Symbol(Symbol::SymbolType symbolType_t);
    virtual ~Symbol();

    virtual void clearSymbol();

    virtual void setSymbolId();
    virtual unsigned long getSymbolId();

    virtual void setSymbolType(Symbol::SymbolType symbolType_t);
    virtual Symbol::SymbolType getSymbolType();

    virtual void addSymbolName(const string &symbolName_t);
    virtual string getSymbolName();

    virtual void addSymbolValue(const string &symbolValue_t);
    virtual vector<string> getSymbolValue();
    virtual string getFirstSymbolValue();

    virtual void setRefScope(Scope *refScope_t);
    virtual Scope* getRefScope();

    virtual void setTypeClass(TypeClass *typeClass_t);
    virtual  TypeClass* getTypeClass();

    virtual void setOffset(int offset_t);
    virtual int getOffset();

    virtual void setByteSize(unsigned int byteSize_t);
    virtual void computeByteSize();
    virtual unsigned int getByteSize();

    virtual void printSymbol(ofstream &ofs_t);

};

/*******************************
class FuncSymble:public Symbol{
private:
	vector<TypeClass *> argu;
public:
	int arguNum;
	void addArgu(TypeClass *type);
	FuncSymble();
};******************************/


#endif
