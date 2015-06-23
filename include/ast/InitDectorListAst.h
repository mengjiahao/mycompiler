#ifndef INCLUDE_INITDECTORLISTAST_H
#define INCLUDE_INITDECTORLISTAST_H

#include "NodeAst.h"


class  InitDectorListAst: public NodeAst {
	public:
	public:
		InitDectorListAst(NodeAst::NodeType nodeType_t);
        virtual void walk();
};

#endif
