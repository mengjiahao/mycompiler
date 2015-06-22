#include "../../include/ast/ClassDectionAst.h"

ClassDectionAst::ClassDectionAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ClassDectionAst::walk()
{
    switch (nodeType){
        case T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST:{

            childs.at(0)->walk();
            TypeClass *tmpType=new TypeClass();
            tmpType->clone(&(s_context->tmpDeclType));
            childs.at(1)->walk();
            if (s_context->isFunc)
            {
                std::cout << "error: class scope should not has func declaration at line " << getLineno() <<std::endl;
                exit(0);
            }
            else
            {
                Symbol *tmpsymbol=new Symbol(Symbol::SYMBOL_VAR);
                tmpsymbol->symbolName=s_context->tmpIdenName;
                tmpsymbol->typeClass.clone(tmpType);
                if (Scope::s_curScope->symbolVarMap.find(tmpsymbol->symbolName)!=Scope::s_curScope->symbolVarMap.end())
                {
                    std::cout<<"error: duplicate var at line "<<getLineno()<<std::endl;
                    exit(0);
                }
                Scope::s_curScope->defineSymbol(tmpsymbol);
            }
            delete tmpType;
            break;
        }
        case T_CCLASSDECTION_SQFLIST_CLASSDECTORLIST_COMPSTM:{
            childs.at(0)->walk();
            Scope *tmpScope=new Scope();
            tmpScope->setReturnTypeClass(&(s_context->tmpDeclType));
            childs.at(1)->walk();
            if (!s_context->isFunc)
            {
                std::cout << "error: this place should be a func at line " << getLineno() <<std::endl;
                exit(0);
            }
            tmpScope->setScopeName(s_context->tmpIdenName);
            tmpScope->setScopeType(Scope::SCOPE_CLASSFUNC);
            Scope::pushScope(Scope::s_curScope,tmpScope);
            Scope::setCurScope(tmpScope);

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
                    if (Scope::s_curScope->symbolVarMap.find(tmpsymbol->symbolName)!=Scope::s_curScope->symbolVarMap.end())
                    {
                        std::cout<<"error: duplicate argument at line "<<getLineno()<<std::endl;
                        exit(0);
                    }
                    Scope::s_curScope->defineSymbol(tmpsymbol);
                }
            }
            childs.at(2)->walk();
            Scope::setCurScope(Scope::encloseScope(Scope::s_curScope));
            break;
        }
        case T_CCLASSDECTION_CLASSDECTORLIST_COMPSTM:{
            Scope *tmpScope=new Scope();
            childs.at(0)->walk();
            if (!s_context->isFunc)
            {
                std::cout << "error: this place should be a func at line " << getLineno() <<std::endl;
                exit(0);
            }
            tmpScope->setScopeName(s_context->tmpIdenName);
            tmpScope->setScopeType(Scope::SCOPE_CLASSFUNC);
            Scope::pushScope(Scope::s_curScope,tmpScope);
            Scope::setCurScope(tmpScope);

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
                    if (Scope::s_curScope->symbolVarMap.find(tmpsymbol->symbolName)!=Scope::s_curScope->symbolVarMap.end())
                    {
                        std::cout<<"error: duplicate argument at line "<<getLineno()<<std::endl;
                        exit(0);
                    }
                    Scope::s_curScope->defineSymbol(tmpsymbol);
                }
            }
            childs.at(1)->walk();
            Scope::setCurScope(Scope::encloseScope(Scope::s_curScope));

            break;
        }
        default:{

            break;
        }
    }
}
