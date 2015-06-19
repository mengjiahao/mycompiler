#ifndef INCLUDE_TRANSLATIONUNITAST_H
#define INCLUDE_TRANSLATIONUNITAST_H

#include "NodeAst.h"


class  TranslationUnitAst: public NodeAst {
	public:
	    virtual void walk();
	public:
		TranslationUnitAst(NodeAst::NodeType nodeType_t);

};

#endif
