#ifndef INCLUDE_PROGRAMSTARTAST_H
#define INCLUDE_PROGRAMSTARTAST_H

#include "NodeAst.h"



class  ProgramStartAst: public NodeAst {
	public:

	public:
		ProgramStartAst(NodeAst::NodeType nodeType_t);

		virtual void walk();

};

#endif
