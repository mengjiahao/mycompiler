#ifndef INCLUDE_EXTDECTIONAST_H
#define INCLUDE_EXTDECTIONAST_H

#include "NodeAst.h"

using namespace std;

class  ExtDectionAst: public NodeAst {
	public:
        virtual Info *walk();
	public:
		ExtDectionAst(NodeAst::NodeType nodeType_t);

};

#endif
