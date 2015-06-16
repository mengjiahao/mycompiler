#ifndef INCLUDE_SYMBOL_H
#define INCLUDE_SYMBOL_H

#include <vector>

class Symbol {

public:

    enum SymbolType {SYMBOL_INVALID, SYMBOL_INTEGER_CONSTANT, SYMBOL_CHARACTER_CONSTANT,
    SYMBOL_FLOATING_CONSTANT, SYMBOL_STRING_LITERAL, SYMBOL_TEMPVAR, SYMBOL_LABEL,
    SYMBOL_VAR, SYMBOL_CONSTANTVAR, SYMBOL_CLASSDECL, SYMBOL_FUNCDECL, SYMBOL_LABELDECL};

    enum StorageType {STOR_INVALID = 0, STOR_EXTERN = 1, STOR_STATIC = 2,
    STOR_AUTO = 4, STOR_REGISTER = 8};

    enum TypeSfType {SF_INVALID = 0, SF_VOID = 1, SF_CHAR = 2, SF_SHORT = 4, SF_INT = 8,
    SF_LONG = 16, SF_FLOAT = 32, SF_DOUBLE = 64, SF_SIGNED = 128, SF_UNSIGNED = 256};

    enum TypeQfType {QF_INVALID = 0, QF_CONST = 1, QF_VOLATILE = 2, QF_VIRTUAL = 4};

    unsigned long symbolId;
    vector<string> symbolValue;
    SymbolType symbolType;

    int storageType;
    int typeSfType;
    int typeQfType;

    int offset;
    int byteSize;

    bool isArray;
    vector<int> dimensions;

public:

    Symbol();
    virtual ~Symbol();

    virtual void initSymbol(Symbol::SymbolType symbolType_t);

    virtual void clearSymbol();

    virtual void setSymbolId();
    virtual unsigned long getSymbolId();

    virtual void addSymbolValue(string symbolValue_t);
    virtual string getSymbolValue();
    virtual vector<string> getSymbolArrayValue();

    virtual void setSymbolType(Symbol::SymbolType symbolType_t);
    virtual Symbol::SymbolType getSymbolType();

    virtual void setStorageType(Symbol::StorageType storageType_t);
    virtual int getStorageType();

    virtual void setTypeSfType(Symbol::TypeSfType typeSfType_t);
    virtual int getTypeSfType();

    virtual void setTypeQfType(Symbol::TypeQfType typeQfType_t);
    virtual int getTypeQfType();

    virtual void setOffset(int offset_t);
    virtual int getOffset();

    virtual void setByteSize(int byteSize_t);
    virtual int getByteSize();

    virtual void setIsArray(bool isArray_t);
    virtual bool getIsArray();

    virtual void setDimension(int dim_t);
    virtual vector<int> getDimension();

};


#endif
