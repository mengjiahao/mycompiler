#ifndef INCLUDE_SYMBOL_H
#define INCLUDE_SYMBOL_H

class Symbol {
public:

    enum SymbolType {SYM_C};

    int symbolId;
    string symbolName;
    int offset;

    int symbolType;
    int attributes;


};


#endif
