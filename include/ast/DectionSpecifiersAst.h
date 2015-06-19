#ifndef INCLUDE_DECTIONSPECIFIERSAST_H
#define INCLUDE_DECTIONSPECIFIERSAST_H

#include "NodeAst.h"

using namespace std;

class  DectionSpecifiersAst: public NodeAst {
	public:
	    virtual Info *walk();
	public:
		DectionSpecifiersAst(NodeAst::NodeType nodeType_t);

};

#endif
