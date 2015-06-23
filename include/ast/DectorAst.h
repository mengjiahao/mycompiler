#ifndef INCLUDE_DECTORAST_H
#define INCLUDE_DECTORAST_H

#include "NodeAst.h"


class  DectorAst: public NodeAst {
	public:

	public:
		DectorAst(NodeAst::NodeType nodeType_t);
        virtual void walk();
};

#endif
