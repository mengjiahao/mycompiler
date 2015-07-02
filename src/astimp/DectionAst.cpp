#include "../../include/ast/DectionAst.h"

DectionAst::DectionAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void DectionAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch (nodeType){
        case T_CDECTION_DECTIONSFS:{
            //std::cout << "walk in T_CDECTION_DECTIONSFS" << endl;
            LogiMsg::logi("walk in T_CDECTION_DECTIONSFS", getLineno());

            if ((childs.at(0)->nodeType != T_CCLASSSF_CLASS_ID_CLASSDECTIONLIST)
            && (childs.at(0)->nodeType != T_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST))
            {
                if (childs.at(0)->nodeType == T_CCLASSSF_CLASS_ID)
                {
                    /*std::cout << "sorry in T_CDECTION_DECTIONSFS, our compiler do not support class declaration at line "
                    << getLineno() << std::endl;*/
                    LogiMsg::logi("sorry in T_CDECTION_DECTIONSFS, our compiler do not support class declaration", getLineno());
                    stopWalk();
                    return ;
                }
                else {
                    /*std::cout << "error in T_CDECTION_DECTIONSFS: this type is builtin type, you can not define it at line "
                    <<getLineno()<<std::endl;*/
                    LogiMsg::logi("error in T_CDECTION_DECTIONSFS: this type is builtin type, you can not define it",
                    getLineno());
                    stopWalk();
                    return ;
                }


                stopWalk();
                return ;
            }
            if (Scope::s_curScope!=Scope::s_globalScope)
            {
                /*std::cout << "error int T_CDECTION_DECTIONSFS: class definition can not appear in local at line "
                << getLineno() <<std::endl;*/
                LogiMsg::logi("error int T_CDECTION_DECTIONSFS: class definition can not appear in local", getLineno());
                stopWalk();
                return ;
            }

            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            break;
        }
        case T_CDECTION_DECTIONSFS_INITDECTORLIST:{
            //std::cout << "walk in T_CDECTION_DECTIONSFS_INITDECTORLIST" << endl;
            LogiMsg::logi("walk in T_CDECTION_DECTIONSFS_INITDECTORLIST", getLineno());

            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            TypeClass tmpType;
            tmpType.clone(&(s_context->tmpDeclType));

            childs.at(1)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            if (s_context->isFunc) {
                /*Scope *tmpScope = new Scope();
                tmpScope->setReturnTypeClass(&tmpType);
                tmpScope->setScopeName(s_context->tmpIdenName);
                tmpScope->setScopeType(Scope::SCOPE_GLOBALFUNCDECL);*/
                if (NULL != Scope::s_curScope->searchSymbolVarMap(s_context->tmpIdenName)) {
                    /*std::cout<<"error in T_CDECTION_DECTIONSFS_INITDECTORLIST: duplicate func "
                    << s_context->tmpIdenName << " has the same name with var at line " << getLineno() << std::endl;*/
                    string errorStr = "error in T_CDECTION_DECTIONSFS_INITDECTORLIST: duplicate func "
                    + s_context->tmpIdenName + " has the same name with var";
                    LogiMsg::logi(errorStr, getLineno());
                    stopWalk();
                    return ;
                }

                if (Scope::resolveScope(s_context->tmpIdenName, Scope::SCOPE_GLOBALFUNC))
                {
                    /*std::cout<<"error in FuncDefAst: the function"
                    << s_context->tmpIdenName << " has been defined at line "<<getLineno()<<std::endl;*/
                    string errorStr = "error in FuncDefAst: the function"
                    + s_context->tmpIdenName + " has been defined";
                    LogiMsg::logi(errorStr, getLineno());
                    stopWalk();
                    return ;
                }
                if (Scope::resolveScope(s_context->tmpIdenName, Scope::SCOPE_GLOBALFUNCCHAN))
                {
                    /*std::cout<<"error in FuncDefAst: the function"
                    << s_context->tmpIdenName << " has been defined at line "<<getLineno()<<std::endl;*/
                    string errorStr = "error in FuncDefAst: the function"
                    + s_context->tmpIdenName + " has been defined";
                    LogiMsg::logi(errorStr, getLineno());
                    stopWalk();
                    return ;
                }
                if (Scope::resolveScope(s_context->tmpIdenName, Scope::SCOPE_GLOBALFUNCDECL))
                {
                    /*std::cout<<"error in FuncDefAst: the function"
                    << s_context->tmpIdenName << " has been defined at line "<<getLineno()<<std::endl;*/
                    string errorStr = "error in FuncDefAst: the function"
                    + s_context->tmpIdenName + " has been defined";
                    LogiMsg::logi(errorStr, getLineno());
                    stopWalk();
                    return ;
                }

                Scope *tmpScope = new Scope();
                tmpScope->setReturnTypeClass(&tmpType);
                tmpScope->setScopeName(s_context->tmpIdenName);
                tmpScope->setScopeType(Scope::SCOPE_GLOBALFUNCDECL);

                Scope::pushScope(Scope::s_curScope, tmpScope);  //do not change s_curscope

                if (s_context->tmpParaWithoutIdNum && s_context->tmpParaWithIdNum)
                {
                    /*std::cout<<"error in T_CDECTION_DECTIONSFS_INITDECTORLIST: func's param do not support mix style at line "
                    <<getLineno()<<std::endl;*/
                    LogiMsg::logi("error in T_CDECTION_DECTIONSFS_INITDECTORLIST: func's param do not support mix style",
                     getLineno());
                    stopWalk();
                    return ;
                }

                if (s_context->tmpParaWithIdNum)
                {
                    for (int i = 0; i < s_context->tmpParaWithIdNum ;i++)
                    {
                        //tmpScope->addParaType(&(s_context->tmpParaWithIdList.at(i).typeClass));
                        Symbol *paramType = new Symbol(Symbol::SYMBOL_PARAMVAR);
                        paramType->setTypeClass(&(s_context->tmpParaWithIdList.at(i).typeClass));
                        tmpScope->defineSymbol(paramType);
                    }
                }
                if (s_context->tmpParaWithoutIdNum)
                {
                    for (int i = 0; i < s_context->tmpParaWithoutIdNum; i++)
                    {
                        //tmpScope->addParaType(&(s_context->tmpParaTypeList.at(i)));
                        Symbol *paramType = new Symbol(Symbol::SYMBOL_PARAMVAR);
                        paramType->setTypeClass(&(s_context->tmpParaTypeList.at(i)));
                        tmpScope->defineSymbol(paramType);
                    }
                }

            } else {

                /*Symbol *tmpsymbol = new Symbol(Symbol::SYMBOL_VAR);
                tmpsymbol->symbolName = s_context->tmpIdenName;
                tmpsymbol->typeClass.clone(&tmpType);*/
                if (Scope::resolveScope(s_context->tmpIdenName, Scope::SCOPE_GLOBALFUNC)
                || Scope::resolveScope(s_context->tmpIdenName, Scope::SCOPE_GLOBALFUNCDECL)
                || Scope::resolveScope(s_context->tmpIdenName, Scope::SCOPE_GLOBALFUNCCHAN))
                {
                    /*std::cout<<"error in FuncDefAst: the var"
                    << s_context->tmpIdenName << " has the same name with func  at line "<<getLineno()<<std::endl;*/
                    string errorStr = "error in FuncDefAst: the var"
                    + s_context->tmpIdenName + " has the same name with func";
                    LogiMsg::logi(errorStr, getLineno());
                    stopWalk();
                    return ;
                }

                if (NULL != Scope::s_curScope->searchSymbolVarMap(s_context->tmpIdenName)) {
                    /*std::cout<<"error in T_CDECTION_DECTIONSFS_INITDECTORLIST: duplicate var "
                    << s_context->tmpIdenName << " at line " << getLineno() << std::endl;*/
                    string errorStr = "error in T_CDECTION_DECTIONSFS_INITDECTORLIST: duplicate var "
                    + s_context->tmpIdenName;
                    LogiMsg::logi(errorStr, getLineno());
                    stopWalk();
                    return ;
                }
                Symbol *tmpsymbol=NULL;
                if (!tmpType.scopeType)
                {
                    tmpsymbol= new Symbol(Symbol::SYMBOL_VAR);
                }
                else
                {
                    tmpsymbol= new Symbol(Symbol::SYMBOL_CLASSREFVAR);
                }

                tmpsymbol->setSymbolName(s_context->tmpIdenName);
                tmpsymbol->setTypeClass(&tmpType);
                if (Scope::s_curScope!=Scope::s_globalScope && !(tmpType.storageType&TypeClass::STOR_STATIC))
                {
                    Scope::s_curScope->incTotalByteSize(tmpsymbol->getByteSize());
                    tmpsymbol->setOffset(Scope::s_curScope->getTotalByteSize());

                }
                if (Scope::s_curScope==Scope::s_globalScope)
                {
                    tmpsymbol->isglobal=true;
                }

                /*if (Scope::s_curScope->symbolVarMap.find(tmpsymbol->symbolName) != Scope::s_curScope->symbolVarMap.end())
                {
                    std::cout<<"error in T_CDECTION_DECTIONSFS_INITDECTORLIST: duplicate var "
                    << tmpsymbol->symbolName << " at line " << getLineno() << std::endl;
                    delete tmpType;
                    exit(0);
                }*/

                Scope::s_curScope->defineSymbol(tmpsymbol);

                if (childs.at(1)->nodeType == NodeAst::T_CINITDECTOR_ASSGIN_INITZER)
                {
                    Reg *r = processChildOperand(0);
                    ItmCode::genCodeAssignRegToSymbol(ItmCode::IR_ASSIGN_OP, r, tmpsymbol);
                }
            }

            //delete tmpType;
            break;
        }
        default:{

            //std::cout<<"error in DectionAst: nodetype is invalid"<<std::endl;
            LogiMsg::logi("error in DectionAst: nodetype is invalid", getLineno());
            stopWalk();
            return ;
        }
    }

}
