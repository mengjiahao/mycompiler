#ifndef INCLUDE_TERMINATEAST_H
#define INCLUDE_TERMINATEAST_H

#include <string>
#include "NodeAst.h"



class TerminateAst : public NodeAst{
	public:


	public:
		TerminateAst(NodeAst::NodeType nodeType_t, string *token_t);
		TerminateAst(NodeAst::NodeType nodeType_t, const char *token_t);
		virtual ~TerminateAst();

};




#endif
