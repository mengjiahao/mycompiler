#include "../../include/ast/ClassDectionAst.h"

ClassDectionAst::ClassDectionAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ClassDectionAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch (nodeType){
        case T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST:{
            std::cout << "walk in T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST" << endl;

            if (2 != childs.size()) {
                std::cout << "error in T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST: doesn't have 2 children at line " << getLineno() << std::endl;
                //exit(0);
                stopWalk();
                return ;
            }

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
                std::cout << "error in T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST: ClassDectionAst scope should not have func declaration at line "
                << getLineno() << std::endl;
                stopWalk();
                return ;
            } else {

                /*Symbol *tmpsymbol = new Symbol(Symbol::SYMBOL_CLASSMEMVAR);
                tmpsymbol->symbolName = s_context->tmpIdenName;
                tmpsymbol->typeClass.clone(&tmpType);*/

                if (NULL != Scope::s_curScope->searchSymbolVarMap(s_context->tmpIdenName)) {
                    std::cout << "error in T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST: ClassDectionAst duplicate var "
                    << s_context->tmpIdenName << " at line " << getLineno() << std::endl;
                    stopWalk();
                    return ;
                }

                Symbol *tmpsymbol = new Symbol(Symbol::SYMBOL_CLASSMEMVAR);
                tmpsymbol->setSymbolName(s_context->tmpIdenName);
                tmpsymbol->setTypeClass(&tmpType);

                tmpsymbol->setOffset(Scope::s_curScope->getTotalByteSize());
                Scope::s_curScope->incTotalByteSize(tmpsymbol->getByteSize());

                /*if (Scope::s_curScope->symbolVarMap.find(tmpsymbol->symbolName) != Scope::s_curScope->symbolVarMap.end())
                {
                    std::cout << "error: duplicate var at line " << getLineno() << std::endl;
                    exit(0);
                }*/

                Scope::s_curScope->defineSymbol(tmpsymbol);
            }
            break;
        }

        case T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST_COMPSTM:{
            std::cout << "walk in T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST_COMPSTM" << endl;

            if (3 != childs.size()) {
                std::cout << "error in T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST_COMPSTM:  doesn't have 3 children at line "
                << getLineno() << std::endl;
                stopWalk();
                return ;
            }

            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            Scope *tmpScope = new Scope();
            TypeClass tmpType;
            tmpType.clone(&(s_context->tmpDeclType));
            //tmpScope->setReturnTypeClass(&(s_context->tmpDeclType));

            childs.at(1)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            if (!s_context->isFunc)
            {
                std::cout << "error in T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST_COMPSTM: ClassDectionAst should not have a func at line "
                << getLineno() << std::endl;
                delete tmpScope;

                stopWalk();
                return ;
            }

            tmpScope->initClassFuncScope(s_context->tmpIdenName);
            tmpScope->setReturnTypeClass(&tmpType);
            tmpScope->setCurStartOffset(0);
            tmpScope->setTotalByteSize(0);
            /*tmpScope->setScopeName(s_context->tmpIdenName);
            tmpScope->setScopeType(Scope::SCOPE_CLASSFUNC);*/
            Scope *tmpVirFunc=Scope::s_curScope->resolveMemFunByName(tmpScope->getScopeName());
            if (tmpVirFunc)
            {
                tmpScope->setFuncOffest(tmpVirFunc->getFuncOffset());
            }
            else
            {
                tmpScope->setFuncOffest(Scope::s_curScope->getTotalFuncByteSize());
                Scope::s_curScope->incTotalFuncByteSize(4);
            }
            Scope::pushScope(Scope::s_curScope,tmpScope);
            Scope::setCurScope(tmpScope);

            if (s_context->tmpParaWithoutIdNum)
            {
                std::cout << "error in T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST_COMPSTM: ClassDectionAst-func's argument list do not have identifier"
                << std::endl;
                stopWalk();
                return ;
            }

            if (s_context->tmpParaWithIdNum)
            {
                for (int i = 0; i < s_context->tmpParaWithIdNum; ++i)
                {
                    /*Symbol *tmpsymbol = new Symbol(Symbol::SYMBOL_VAR);
                    tmpsymbol->symbolName = s_context->tmpParaWithIdList.at(i).symbolName;
                    tmpsymbol->typeClass.clone(&(s_context->tmpParaWithIdList.at(i).typeClass));*/

                    if (NULL != Scope::s_curScope->searchSymbolVarMap(s_context->tmpParaWithIdList.at(i).symbolName)) {
                        std::cout << "error in T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST_COMPSTM: ClassDectionAst-func's duplicate argument "
                        << s_context->tmpParaWithIdList.at(i).symbolName << " at line " << getLineno() << std::endl;
                        stopWalk();
                        return ;
                    }

                    Symbol *tmpsymbol = new Symbol(Symbol::SYMBOL_VAR);
                    tmpsymbol->setSymbolName(s_context->tmpParaWithIdList.at(i).symbolName);
                    tmpsymbol->setTypeClass(&(s_context->tmpParaWithIdList.at(i).typeClass));



                    /*if (Scope::s_curScope->symbolVarMap.find(tmpsymbol->symbolName) != Scope::s_curScope->symbolVarMap.end())
                    {
                        std::cout << "error: ClassDecl-func's duplicate argument " << tmpsymbol->symbolName
                        << " at line " << getLineno() << std::endl;
                        delete tmpsymbol;
                        exit(0);
                    }*/


                    Scope::s_curScope->defineSymbol(tmpsymbol);
                }
                list<Symbol *>::reverse_iterator r_itr;
                for (r_itr= Scope::s_curScope->symbolSeqList.rbegin(); r_itr!=Scope::s_curScope->symbolSeqList.rend(); r_itr++)
                {
                    (*r_itr)->setOffset(Scope::s_curScope->getTotalByteSize());
                    Scope::s_curScope->incTotalByteSize((*r_itr)->getByteSize());
                }
                Scope::s_curScope->incTotalByteSize(12);

            }

            childs.at(2)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            Scope::setCurScope(Scope::encloseScope(Scope::s_curScope));
            break;
        }

        case T_CCLASSDECTION_CLASSDECTORLIST_COMPSTM:{
            std::cout << "walk in T_CCLASSDECTION_CLASSDECTORLIST_COMPSTM" << endl;

            //Scope *tmpScope=new Scope();
            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            if (!s_context->isFunc)
            {
                std::cout << "error in T_CCLASSDECTION_CLASSDECTORLIST_COMPSTM: ClassDectionAst should have a func at line "
                << getLineno() << std::endl;
                stopWalk();
                return ;
            }

            Scope *tmpScope = new Scope();
            tmpScope->setScopeName(s_context->tmpIdenName);
            tmpScope->setScopeType(Scope::SCOPE_CLASSFUNC);
            tmpScope->setCurStartOffset(0);
            tmpScope->setTotalByteSize(0);

            Scope::pushScope(Scope::s_curScope, tmpScope);
            Scope::setCurScope(tmpScope);

            if (s_context->tmpParaWithoutIdNum)
            {
                std::cout << "error in T_CCLASSDECTION_CLASSDECTORLIST_COMPSTM: ClassDectionAst-func's argument list do not have identifier"
                << std::endl;
                stopWalk();
                return ;
            }

            if (s_context->tmpParaWithIdNum)
            {
                for (int i = 0; i < s_context->tmpParaWithIdNum; ++i)
                {
                    /*Symbol *tmpsymbol = new Symbol(Symbol::SYMBOL_VAR);
                    tmpsymbol->symbolName = s_context->tmpParaWithIdList.at(i).symbolName;
                    tmpsymbol->typeClass.clone(&(s_context->tmpParaWithIdList.at(i).typeClass));*/

                    if (NULL != Scope::s_curScope->searchSymbolVarMap(s_context->tmpParaWithIdList.at(i).symbolName)) {
                        std::cout << "error in T_CCLASSDECTION_CLASSDECTORLIST_COMPSTM: ClassDectionAst-func's duplicate argument "
                        << s_context->tmpParaWithIdList.at(i).symbolName << " at line " << getLineno() << std::endl;
                        stopWalk();
                        return ;
                    }

                    Symbol *tmpsymbol = new Symbol(Symbol::SYMBOL_VAR);
                    tmpsymbol->setSymbolName(s_context->tmpParaWithIdList.at(i).symbolName);
                    tmpsymbol->setTypeClass(&(s_context->tmpParaWithIdList.at(i).typeClass));

                    /*if (Scope::s_curScope->symbolVarMap.find(tmpsymbol->symbolName) != Scope::s_curScope->symbolVarMap.end())
                    {
                        std::cout<<"error: ClassDecl-func's duplicate argument " << tmpsymbol->symbolName
                        << "at line " <<getLineno()<<std::endl;
                        delete tmpsymbol;
                        exit(0);
                    }*/

                    Scope::s_curScope->defineSymbol(tmpsymbol);
                }
                list<Symbol *>::reverse_iterator r_itr;
                for (r_itr= Scope::s_curScope->symbolSeqList.rbegin(); r_itr!=Scope::s_curScope->symbolSeqList.rend(); r_itr++)
                {
                    (*r_itr)->setOffset(Scope::s_curScope->getTotalByteSize());
                    Scope::s_curScope->incTotalByteSize((*r_itr)->getByteSize());
                }
                Scope::s_curScope->incTotalByteSize(12);
            }

            childs.at(1)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            Scope::setCurScope(Scope::encloseScope(Scope::s_curScope));

            break;
        }
        default:{

            std::cout << "error in ClassDectionAst: nodeType is invalid" << std::endl;

            break;
        }
    }

    //NodeAst::s_context->clearContext();
}
