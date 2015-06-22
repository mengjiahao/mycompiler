#ifndef INCLUDE_DECTIONLISTAST_H
#define INCLUDE_DECTIONLISTAST_H

#include "NodeAst.h"


class  DectionListAst: public NodeAst {
	public:

	public:
		DectionListAst(NodeAst::NodeType nodeType_t);
        virtual void walk();
};

#endif
