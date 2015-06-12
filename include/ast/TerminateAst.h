#ifndef INCLUDE_TERMINATEAST_H
#define INCLUDE_TERMINATEAST_H

#include <string>
#include "NodeAst.h"

using namespace std;

/**/

class TerminateAst : public NodeAst{
	public:
		string token;

	public:
		TerminateAst(NodeAst::NodeType nodeType_t, string token_t);
		void setToken(string token_t);



}




#endif
