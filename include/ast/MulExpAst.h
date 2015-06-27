#ifndef INCLUDE_MULEXPAST_H
#define INCLUDE_MULEXPAST_H

#include "NodeAst.h"


class  MulExpAst: public NodeAst {
	public:
	public:
		MulExpAst(NodeAst::NodeType nodeType_t);

		virtual void walk();

};

#endif
