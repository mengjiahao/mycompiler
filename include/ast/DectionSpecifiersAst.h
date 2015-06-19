#ifndef INCLUDE_DECTIONSPECIFIERSAST_H
#define INCLUDE_DECTIONSPECIFIERSAST_H

#include "NodeAst.h"

using namespace std;

class  DectionSpecifiersAst: public NodeAst {
	public:
	    virtual void walk();
	public:
		DectionSpecifiersAst(NodeAst::NodeType nodeType_t);

};

#endif
