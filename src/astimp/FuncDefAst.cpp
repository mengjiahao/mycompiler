#include "../../include/ast/FuncDefAst.h"

FuncDefAst::FuncDefAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void FuncDefAst::walk()
{
    if (nodeType!=T_CFUNCDEF_DECTIONSFS_DECTOR_COMPSTM)
    {
        std::cout<<"nodetype error at FuncDefAst"<<std::endl;
        exit(0);
    }
    if ((childs.at(1)->nodeType!=T_CDIRDECTOR_DIRDECTOR_CALL_PARAMTYPELIST)  && (childs.at(1)->nodeType!=T_CDIRDECTOR_DIRDECTOR_CALL_VOID))
    {
        std::cout<<"error: the name of function is not param either void at line "<<getLineno()<<std::endl;
        exit(0);
    }
    childs.at(0)->walk();
    Scope *tmpScope=new Scope();
    tmpScope->setReturnTypeClass(&(s_context->tmpDeclType));
    childs.at(1)->walk();
    tmpScope->setScopeName(s_context->tmpIdenName);
    if (s_context->tmpParaWithoutIdNum)
    {
        std::cout<<"error:argument list do not have identifier"<<std::endl;
        exit(0);
    }
    if (s_context->tmpParaWithIdNum)
    {
        for (int i=0;i<s_context->tmpParaWithIdNum;i++)
        {
            Symbol *tmpsymbol=new Symbol(Symbol::SYMBOL_VAR);
            tmpsymbol->symbolName=s_context->tmpParaWithIdList.at(i).symbolName;
            tmpsymbol->typeClass.clone(&(s_context->tmpParaWithIdList.at(i).typeClass));
            tmpScope->defineSymbol(tmpsymbol);
        }
    }
    tmpScope->setScopeType(Scope::SCOPE_GLOBALFUNC);
    Scope::pushScope(Scope::s_curScope,tmpScope);


}







