#ifndef INCLUDE_UNARYEXPAST_H
#define INCLUDE_UNARYEXPAST_H

#include "NodeAst.h"


class  UnaryExpAst: public NodeAst {
	public:

	public:
		UnaryExpAst(NodeAst::NodeType nodeType_t);

		virtual void walk();

		bool genCodeUnaryChildOperand(NodeAst::NodeType nodeType_t, ItmCode::OperandType opType_t, void *t);

};

#endif
