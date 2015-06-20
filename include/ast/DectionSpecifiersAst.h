#ifndef INCLUDE_DECTIONSPECIFIERSAST_H
#define INCLUDE_DECTIONSPECIFIERSAST_H

#include "NodeAst.h"

using namespace std;

class  DectionSpecifiersAst: public NodeAst {
	public:
	    virtual void walk();
	    void judgetType(TypeClass *type1_t,TypeClass *type2_t); //判断两个类型能否组合,出错直接退出
	public:
		DectionSpecifiersAst(NodeAst::NodeType nodeType_t);

};

#endif
