#ifndef INCLUDE_SELECTIONSTMAST_H
#define INCLUDE_SELECTIONSTMAST_H

#include "NodeAst.h"

class  SelectionStmAst: public NodeAst {
	public:
	public:
		SelectionStmAst(NodeAst::NodeType nodeType_t);

		virtual void walk();

};

#endif
