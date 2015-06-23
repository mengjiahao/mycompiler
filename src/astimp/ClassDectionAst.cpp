#include "../../include/ast/ClassDectionAst.h"

ClassDectionAst::ClassDectionAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ClassDectionAst::walk()
{
    switch (nodeType){
        case T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST:{
            std::cout << "walk in T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST" << endl;

            if (2 != childs.size()) {
                std::cout << "error in T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST: doesn't have 2 children at line " << getLineno() << std::endl;
                exit(0);
            }

            childs.at(0)->walk();

            TypeClass tmpType;
            tmpType.clone(&(s_context->tmpDeclType));

            childs.at(1)->walk();

            if (s_context->isFunc) {
                std::cout << "error in T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST: ClassDectionAst scope should not have func declaration at line "
                << getLineno() << std::endl;
                exit(0);
            } else {
                Symbol *tmpsymbol = new Symbol(Symbol::SYMBOL_CLASSMEMVAR);
                tmpsymbol->symbolName = s_context->tmpIdenName;
                tmpsymbol->typeClass.clone(&tmpType);

                if (NULL != Scope::s_curScope->searchSymbolVarMap(tmpsymbol->symbolName)) {
                    std::cout << "error in T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST: ClassDectionAst duplicate var "
                    << tmpsymbol->symbolName << " at line " << getLineno() << std::endl;
                    delete tmpsymbol;
                    exit(0);
                }
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
                exit(0);
            }

            childs.at(0)->walk();

            Scope *tmpScope = new Scope();
            tmpScope->setReturnTypeClass(&(s_context->tmpDeclType));

            childs.at(1)->walk();

            if (!s_context->isFunc)
            {
                std::cout << "error in T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST_COMPSTM: ClassDectionAst should not have a func at line "
                << getLineno() << std::endl;
                delete tmpScope;
                exit(0);
            }

            tmpScope->initClassFuncScope(s_context->tmpIdenName);
            /*tmpScope->setScopeName(s_context->tmpIdenName);
            tmpScope->setScopeType(Scope::SCOPE_CLASSFUNC);*/
            Scope::pushScope(Scope::s_curScope,tmpScope);
            Scope::setCurScope(tmpScope);

            if (s_context->tmpParaWithoutIdNum)
            {
                std::cout << "error in T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST_COMPSTM: ClassDectionAst-func's argument list do not have identifier"
                << std::endl;
                exit(0);
            }

            if (s_context->tmpParaWithIdNum)
            {
                for (int i = 0; i < s_context->tmpParaWithIdNum; ++i)
                {
                    Symbol *tmpsymbol = new Symbol(Symbol::SYMBOL_VAR);
                    tmpsymbol->symbolName = s_context->tmpParaWithIdList.at(i).symbolName;
                    tmpsymbol->typeClass.clone(&(s_context->tmpParaWithIdList.at(i).typeClass));

                    if (NULL != Scope::s_curScope->searchSymbolVarMap(tmpsymbol->symbolName)) {
                        std::cout << "error in T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST_COMPSTM: ClassDectionAst-func's duplicate argument "
                        << tmpsymbol->symbolName << " at line " << getLineno() << std::endl;
                        delete tmpsymbol;
                        exit(0);
                    }
                    /*if (Scope::s_curScope->symbolVarMap.find(tmpsymbol->symbolName) != Scope::s_curScope->symbolVarMap.end())
                    {
                        std::cout << "error: ClassDecl-func's duplicate argument " << tmpsymbol->symbolName
                        << " at line " << getLineno() << std::endl;
                        delete tmpsymbol;
                        exit(0);
                    }*/


                    Scope::s_curScope->defineSymbol(tmpsymbol);
                }
            }

            childs.at(2)->walk();

            Scope::setCurScope(Scope::encloseScope(Scope::s_curScope));
            break;
        }

        case T_CCLASSDECTION_CLASSDECTORLIST_COMPSTM:{
            std::cout << "walk in T_CCLASSDECTION_CLASSDECTORLIST_COMPSTM" << endl;

            //Scope *tmpScope=new Scope();
            childs.at(0)->walk();

            if (!s_context->isFunc)
            {
                std::cout << "error in T_CCLASSDECTION_CLASSDECTORLIST_COMPSTM: ClassDectionAst should have a func at line "
                << getLineno() << std::endl;
                exit(0);
            }

            Scope *tmpScope = new Scope();
            tmpScope->setScopeName(s_context->tmpIdenName);
            tmpScope->setScopeType(Scope::SCOPE_CLASSFUNC);

            Scope::pushScope(Scope::s_curScope, tmpScope);
            Scope::setCurScope(tmpScope);

            if (s_context->tmpParaWithoutIdNum)
            {
                std::cout << "error in T_CCLASSDECTION_CLASSDECTORLIST_COMPSTM: ClassDectionAst-func's argument list do not have identifier"
                << std::endl;
                exit(0);
            }

            if (s_context->tmpParaWithIdNum)
            {
                for (int i = 0; i < s_context->tmpParaWithIdNum; ++i)
                {
                    Symbol *tmpsymbol = new Symbol(Symbol::SYMBOL_VAR);
                    tmpsymbol->symbolName = s_context->tmpParaWithIdList.at(i).symbolName;
                    tmpsymbol->typeClass.clone(&(s_context->tmpParaWithIdList.at(i).typeClass));

                    if (NULL != Scope::s_curScope->searchSymbolVarMap(tmpsymbol->symbolName)) {
                        std::cout << "error in T_CCLASSDECTION_CLASSDECTORLIST_COMPSTM: ClassDectionAst-func's duplicate argument "
                        << tmpsymbol->symbolName << " at line " << getLineno() << std::endl;
                        delete tmpsymbol;
                        exit(0);
                    }

                    /*if (Scope::s_curScope->symbolVarMap.find(tmpsymbol->symbolName) != Scope::s_curScope->symbolVarMap.end())
                    {
                        std::cout<<"error: ClassDecl-func's duplicate argument " << tmpsymbol->symbolName
                        << "at line " <<getLineno()<<std::endl;
                        delete tmpsymbol;
                        exit(0);
                    }*/

                    Scope::s_curScope->defineSymbol(tmpsymbol);
                }
            }

            childs.at(1)->walk();

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
