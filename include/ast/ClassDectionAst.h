#ifndef INCLUDE_CLASSDECTIONAST_H
#define INCLUDE_CLASSDECTIONAST_H

#include "NodeAst.h"


class  ClassDectionAst: public NodeAst {
	public:

	public:
		ClassDectionAst(NodeAst::NodeType nodeType_t);
        virtual void walk();
};

#endif
