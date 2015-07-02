#include "../../include/ast/FuncDefAst.h"

FuncDefAst::FuncDefAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void FuncDefAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }


    if (nodeType != T_CFUNCDEF_DECTIONSFS_DECTOR_COMPSTM)
    {
        //std::cout<<"error: nodetype error in FuncDefAst"<<std::endl;
        LogiMsg::logi("error: nodetype error in FuncDefAst", getLineno());
        stopWalk();
        return ;
    }
    //std::cout << "walk in T_CFUNCDEF_DECTIONSFS_DECTOR_COMPSTM" << endl;
    LogiMsg::logi("walk in T_CFUNCDEF_DECTIONSFS_DECTOR_COMPSTM", getLineno());

    if ((childs.at(1)->nodeType != T_CDIRDECTOR_DIRDECTOR_CALL_PARAMTYPELIST)
    && (childs.at(1)->nodeType != T_CDIRDECTOR_DIRDECTOR_CALL_VOID))
    {
        /*std::cout<<"error in FuncDefAst: the children's type of function is not param either void at line "
        <<getLineno()<<std::endl;*/
        LogiMsg::logi("error in FuncDefAst: the children's type of function is not param either void", getLineno());
        stopWalk();
        return ;
    }

    childs.at(0)->walk();
    if (checkIsNotWalking()) {
        return ;
    }

    Scope *tmpScope = new Scope();
    tmpScope->setReturnTypeClass(&(s_context->tmpDeclType));
    tmpScope->setCurStartOffset(0);
    tmpScope->setTotalByteSize(0);
    childs.at(1)->walk();
    if (checkIsNotWalking()) {
        return ;
    }


    tmpScope->setScopeName(s_context->tmpIdenName);

    if (Scope::resolveScope(tmpScope->scopeName, Scope::SCOPE_GLOBALFUNC))
    {
        /*std::cout<<"error in FuncDefAst: the function"
        << tmpScope->scopeName << " has been defined at line "<<getLineno()<<std::endl;*/
        string erroStr = "error in FuncDefAst: the function"
        + tmpScope->scopeName + " has been defined";
        LogiMsg::logi(erroStr, getLineno());
        delete tmpScope;
        stopWalk();
        return ;
    }
    if (Scope::resolveScope(tmpScope->scopeName, Scope::SCOPE_GLOBALFUNCCHAN))
    {
        /*std::cout<<"error in FuncDefAst: the function"
        << tmpScope->scopeName << " has been defined at line "<<getLineno()<<std::endl;*/
        string erroStr = "error in FuncDefAst: the function"
        + tmpScope->scopeName + " has been defined";
        LogiMsg::logi(erroStr, getLineno());
        delete tmpScope;
        stopWalk();
        return ;
    }

    Scope *tmpFuncImp = NULL;
    tmpFuncImp = Scope::resolveScope(tmpScope->scopeName, Scope::SCOPE_GLOBALFUNCDECL);


    if ( NULL != tmpFuncImp ) {

        delete tmpScope;
        tmpScope = tmpFuncImp;
        tmpScope->clearSymbolSeqList();

        tmpScope->setScopeType(Scope::SCOPE_GLOBALFUNCCHAN);   //replace
        tmpScope->setCurStartOffset(0);
        tmpScope->setTotalByteSize(0);

        Scope::setCurScope(tmpScope);
    } else {
        tmpScope->setScopeType(Scope::SCOPE_GLOBALFUNC);

        Scope::pushScope(Scope::s_curScope, tmpScope);
        Scope::setCurScope(tmpScope);
    }


    if (s_context->tmpParaWithoutIdNum)
    {
        //std::cout<<"error in FuncDefAst: argument list do not have identifier"<<std::endl;
        LogiMsg::logi("error in FuncDefAst: argument list do not have identifier", getLineno());
        stopWalk();
        return ;
    }

    if (s_context->tmpParaWithIdNum)
    {
        for (int i = 0; i <s_context->tmpParaWithIdNum ; i++)
        {
            /*Symbol *tmpsymbol = new Symbol(Symbol::SYMBOL_VAR);
            tmpsymbol->symbolName = s_context->tmpParaWithIdList.at(i).symbolName;
            tmpsymbol->typeClass.clone(&(s_context->tmpParaWithIdList.at(i).typeClass));*/

            if (NULL != Scope::s_curScope->searchSymbolVarMap(s_context->tmpParaWithIdList.at(i).symbolName)) {
                /*std::cout << "error in FuncDefAst: duplicate argument "
                << s_context->tmpParaWithIdList.at(i).symbolName << " at line " << getLineno() << std::endl;*/
                string errorStr = "error in FuncDefAst: duplicate argument "
                + s_context->tmpParaWithIdList.at(i).symbolName;
                LogiMsg::logi(errorStr, getLineno());
                stopWalk();
                return ;
            }

            Symbol *tmpsymbol = new Symbol(Symbol::SYMBOL_VAR);
            tmpsymbol->setSymbolName(s_context->tmpParaWithIdList.at(i).symbolName);
            tmpsymbol->setTypeClass(&(s_context->tmpParaWithIdList.at(i).typeClass));


            /*if (Scope::s_curScope->symbolVarMap.find(tmpsymbol->symbolName)!=Scope::s_curScope->symbolVarMap.end())
            {
                std::cout<<"error in FuncDefAst: duplicate argument at line "<<getLineno()<<std::endl;
                delete tmpsymbol;
                exit(0);
            }*/

            Scope::s_curScope->defineSymbol(tmpsymbol);
        }
        list<Symbol *>::reverse_iterator r_itr;
        for (r_itr= Scope::s_curScope->symbolSeqList.rbegin(); r_itr!=Scope::s_curScope->symbolSeqList.rend(); r_itr++)
        {
            Scope::s_curScope->incTotalByteSize((*r_itr)->getByteSize());
            (*r_itr)->setOffset(Scope::s_curScope->getTotalByteSize());

        }
        Scope::s_curScope->incTotalByteSize(4);
    }

    childs.at(2)->walk();
    if (checkIsNotWalking()) {
        return ;
    }


    Scope::setCurScope(Scope::encloseScope(Scope::s_curScope));


}







