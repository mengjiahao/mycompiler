#include "../../include/ast/FuncDefAst.h"

FuncDefAst::FuncDefAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void FuncDefAst::walk()
{
    if (nodeType != T_CFUNCDEF_DECTIONSFS_DECTOR_COMPSTM)
    {
        std::cout<<"error: nodetype error in FuncDefAst"<<std::endl;
        exit(0);
    }
    if ((childs.at(1)->nodeType != T_CDIRDECTOR_DIRDECTOR_CALL_PARAMTYPELIST)
    && (childs.at(1)->nodeType != T_CDIRDECTOR_DIRDECTOR_CALL_VOID))
    {
        std::cout<<"error in FuncDefAst: the children's type of function is not param either void at line "
        <<getLineno()<<std::endl;
        exit(0);
    }

    childs.at(0)->walk();

    Scope *tmpScope = new Scope();
    tmpScope->setReturnTypeClass(&(s_context->tmpDeclType));

    childs.at(1)->walk();

    tmpScope->setScopeName(s_context->tmpIdenName);

    if (Scope::resolveScope(tmpScope->scopeName, Scope::SCOPE_GLOBALFUNC))
    {
        std::cout<<"error in FuncDefAst: the function"
        << tmpScope->scopeName << " has been defined at line "<<getLineno()<<std::endl;
        delete tmpScope;
        exit(0);
    }

    if (Scope::resolveScope(tmpScope->scopeName, Scope::SCOPE_GLOBALFUNCDECL)) {
        delete tmpScope;
        tmpScope=Scope::resolveScope(tmpScope->scopeName, Scope::SCOPE_GLOBALFUNCDECL);
        tmpScope->setScopeType(Scope::SCOPE_GLOBALFUNCCHAN);   //replace
        Scope::setCurScope(tmpScope);
    } else {
        tmpScope->setScopeType(Scope::SCOPE_GLOBALFUNC);
        Scope::pushScope(Scope::s_curScope,tmpScope);
        Scope::setCurScope(tmpScope);
    }


    if (s_context->tmpParaWithoutIdNum)
    {
        std::cout<<"error in FuncDefAst: argument list do not have identifier"<<std::endl;
        exit(0);
    }

    if (s_context->tmpParaWithIdNum)
    {
        for (int i=0;i<s_context->tmpParaWithIdNum;i++)
        {
            Symbol *tmpsymbol = new Symbol(Symbol::SYMBOL_VAR);
            tmpsymbol->symbolName = s_context->tmpParaWithIdList.at(i).symbolName;
            tmpsymbol->typeClass.clone(&(s_context->tmpParaWithIdList.at(i).typeClass));

            if (NULL != Scope::s_curScope->searchSymbolVarMap(tmpsymbol->symbolName)) {
                std::cout << "error in FuncDefAst: duplicate argument "
                << tmpsymbol->symbolName << " at line " << getLineno() << std::endl;
                delete tmpsymbol;
                exit(0);
            }

            /*if (Scope::s_curScope->symbolVarMap.find(tmpsymbol->symbolName)!=Scope::s_curScope->symbolVarMap.end())
            {
                std::cout<<"error in FuncDefAst: duplicate argument at line "<<getLineno()<<std::endl;
                delete tmpsymbol;
                exit(0);
            }*/

            Scope::s_curScope->defineSymbol(tmpsymbol);
        }
    }

    childs.at(2)->walk();

    Scope::setCurScope(Scope::encloseScope(Scope::s_curScope));


}







