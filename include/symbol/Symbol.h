#ifndef INCLUDE_SYMBOL_H
#define INCLUDE_SYMBOL_H

class Symbol {
public:

    enum SymbolType {SYMBOL_INVALIDE, SYMBOL_INTEGER_CONSTANT, SYMBOL_CHARACTER_CONSTANT,
    SYMBOL_FLOATING_CONSTANT, SYMBOL_STRING_LITERAL, SYMBOL_TEMPVAR, SYMBOL_LABEL,
    SYMBOL_VAR, SYMBOL_CLASSDECL, SYMBOL_FUNCDECL, SYMBOL_LABELDECL};

    enum StorageType {STOR_INVALIDE = 0, STOR_EXTERN = 1, STOR_STATIC = 2,
    STOR_AUTO = 4, STOR_REGISTER = 8};

    enum TypeSfType {SF_INVALIDE = 0, SF_VOID = 1, SF_CHAR = 2, SF_SHORT = 4, SF_INT = 8,
    SF_LONG = 16, SF_FLOAT = 32, SF_DOUBLE = 64, SF_SIGNED = 128, SF_UNSIGNED = 256};

    enum TypeQfType {QF_INVALIDE = 0, QF_CONST = 1, QF_VOLATILE = 2, QF_VIRTUAL = 4};

    int symbolId;
    string symbolName;
    SymbolType symbolType;
    int storageType;
    int typeSfType;
    int typeQfType;

    int offset;
    int byteSize;

    bool isArray;
    int elemsNo;

    Symbol();
    virtual ~Symbol();

    virtual void initSymbol(Symbol::SymbolType symbolType_t);

    virtual void setSymbolId();
    virtual int getSymbolId();

    virtual void setSymbolName(string symbolName_t);
    virtual string getSymbolName();

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

    virtual void setElemsNo(int elemsNo);
    virtual int getElemsNo();

};


#endif
