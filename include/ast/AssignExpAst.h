#ifndef INCLUDE_ASSIGNEXPAST_H
#define INCLUDE_ASSIGNEXPAST_H

#include "NodeAst.h"


class AssignExpAst: public NodeAst {
	public:
	public:
		AssignExpAst(NodeAst::NodeType nodeType_t);

		virtual void walk();

};

#endif
