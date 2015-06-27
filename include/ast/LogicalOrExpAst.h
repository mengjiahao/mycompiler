#ifndef INCLUDE_LOGICALOREXPAST_H
#define INCLUDE_LOGICALOREXPAST_H

#include "NodeAst.h"


class  LogicalOrExpAst: public NodeAst {
	public:
	public:
		LogicalOrExpAst(NodeAst::NodeType nodeType_t);

		virtual void walk();

};


#endif
