#ifndef INCLUDE_POSTFIXEXPAST_H
#define INCLUDE_POSTFIXEXPAST_H

#include "NodeAst.h"



class  PostfixExpAst: public NodeAst {
	public:

	public:
		PostfixExpAst(NodeAst::NodeType nodeType_t);

		virtual void walk();

		void genCodeCallVoid(Scope *func_t);
		void genCodeCallArgExpList(Scope *func_t, vector<void* >* argExpList_t);

};

#endif
