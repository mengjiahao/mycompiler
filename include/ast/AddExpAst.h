#ifndef INCLUDE_ADDEXPAST_H
#define INCLUDE_ADDEXPAST_H

#include "NodeAst.h"

class  AddExpAst: public NodeAst {
	public:
	public:
		AddExpAst(NodeAst::NodeType nodeType_t);
		virtual void walk();

};

#endif
