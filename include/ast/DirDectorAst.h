#ifndef INCLUDE_DIRDECTORAST_H
#define INCLUDE_DIRDECTORAST_H

#include "NodeAst.h"


class DirDectorAst: public NodeAst {
	public:
	public:
		DirDectorAst(NodeAst::NodeType nodeType_t);
		virtual void walk();

};

#endif
