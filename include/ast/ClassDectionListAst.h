#ifndef INCLUDE_CLASSDECTIONLISTAST_H
#define INCLUDE_CLASSDECTIONLISTAST_H

#include "NodeAst.h"


class  ClassDectionListAst: public NodeAst {
	public:

	public:
		ClassDectionListAst(NodeAst::NodeType nodeType_t);
        virtual void walk();
};

#endif
