#ifndef INCLUDE_ARGEXPLISTAST_H
#define INCLUDE_ARGEXPLISTAST_H

#include "NodeAst.h"


class ArgExpListAst : public NodeAst {
public:

public:
		ArgExpListAst(NodeAst::NodeType nodeType_t);

		virtual void processAssgExp(NodeType nodeType_t);
		virtual void walk();

		virtual void genCode(Reg *reg_t, Symbol *symbol_t);
};




#endif
