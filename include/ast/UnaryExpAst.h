#ifndef INCLUDE_UNARYEXPAST_H
#define INCLUDE_UNARYEXPAST_H

#include "NodeAst.h"

using namespace std;

/*{ T_CUNARYEXP_INC_UNARAYEXP, T_CUNARYEXP_DEC_UNARYEXP, T_CUNARYEXP_UNARYOP_CASTEXP, T_CUNARYEXP_SIZEOF_UNARAYEXP }*/

class  UnaryExpAst: public NodeAst {
	public:

	public:
		UnaryExpAst(NodeAst::NodeType nodeType_t);

}

#endif
