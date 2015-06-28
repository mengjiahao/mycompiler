#ifndef INCLUDE_EXPSTMAST_H
#define INCLUDE_EXPSTMAST_H

#include "NodeAst.h"


class  ExpStmAst: public NodeAst {
	public:
	public:
		ExpStmAst(NodeAst::NodeType nodeType_t);

		virtual void walk();

};

#endif
