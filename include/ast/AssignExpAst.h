#ifndef INCLUDE_ASSIGNEXPAST_H
#define INCLUDE_ASSIGNEXPAST_H

#include "NodeAst.h"


class AssignExpAst: public NodeAst {
	public:
	public:
		AssignExpAst(NodeAst::NodeType nodeType_t);

		virtual void walk();

		bool genCodeAssignChildOperand(NodeAst::NodeType nodeType_t, ItmCode::OperandType opType_t,
		void *u, Reg *r);

};

#endif
