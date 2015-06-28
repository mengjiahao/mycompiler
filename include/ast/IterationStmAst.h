#ifndef INCLUDE_ITERATIONSTMAST_H
#define INCLUDE_ITERATIONSTMAST_H

#include "NodeAst.h"


class  IterationStmAst: public NodeAst {
	public:
	public:
		IterationStmAst(NodeAst::NodeType nodeType_t);

		virtual void walk();

};

#endif
