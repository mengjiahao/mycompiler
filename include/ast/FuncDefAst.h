#ifndef INCLUDE_FUNCDEFAST_H
#define INCLUDE_FUNCDEFAST_H

#include "NodeAst.h"


class FuncDefAst: public NodeAst {
	public:
	    virtual Info *walk();
	public:
		FuncDefAst(NodeAst::NodeType nodeType_t);

};

#endif
