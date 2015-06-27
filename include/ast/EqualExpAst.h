#ifndef INCLUDE_EQUALEXPAST_H
#define INCLUDE_EQUALEXPAST_H

#include "NodeAst.h"


class  EqualExpAst: public NodeAst {
	public:
	public:
		EqualExpAst(NodeAst::NodeType nodeType_t);

		virtual void walk();

};


#endif
