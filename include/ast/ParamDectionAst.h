#ifndef INCLUDE_PARAMDECTIONAST_H
#define INCLUDE_PARAMDECTIONAST_H

#include "NodeAst.h"


class  ParamDectionAst: public NodeAst {
	public:
	public:
		ParamDectionAst(NodeAst::NodeType nodeType_t);
		virtual void walk();

};

#endif
