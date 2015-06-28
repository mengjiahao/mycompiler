#ifndef INCLUDE_JUMPSTMAST_H
#define INCLUDE_JUMPSTMAST_H

#include "NodeAst.h"


class  JumpStmAst: public NodeAst {
	public:
	public:
		JumpStmAst(NodeAst::NodeType nodeType_t);

		virtual void walk();

};


#endif
