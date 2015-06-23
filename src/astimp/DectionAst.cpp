#include "../../include/ast/DectionAst.h"

DectionAst::DectionAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void DectionAst::walk()
{
    switch (nodeType){
        case T_CDECTION_DECTIONSFS:{
            std::cout << "walk in T_CDECTION_DECTIONSFS" << endl;

            if ((childs.at(0)->nodeType != T_CCLASSSF_CLASS_ID_CLASSDECTIONLIST)
            && (childs.at(0)->nodeType != T_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST))
            {
                if (childs.at(0)->nodeType == T_CCLASSSF_CLASS_ID)
                {
                    std::cout << "sorry in T_CDECTION_DECTIONSFS, our compiler do not support class declaration at line "
                    << getLineno() << std::endl;
                }
                else {
                    std::cout << "error in T_CDECTION_DECTIONSFS: this type is builtin type, you can not define it at line "
                    <<getLineno()<<std::endl;
                }


                exit(0);
            }

            childs.at(0)->walk();
            break;
        }
        case T_CDECTION_DECTIONSFS_INITDECTORLIST:{
            std::cout << "walk in T_CDECTION_DECTIONSFS_INITDECTORLIST" << endl;

            childs.at(0)->walk();

            TypeClass tmpType;
            tmpType.clone(&(s_context->tmpDeclType));

            childs.at(1)->walk();

            if (s_context->isFunc) {
                Scope *tmpScope = new Scope();
                tmpScope->setReturnTypeClass(&tmpType);
                tmpScope->setScopeName(s_context->tmpIdenName);
                tmpScope->setScopeType(Scope::SCOPE_GLOBALFUNCDECL);

                Scope::pushScope(Scope::s_curScope, tmpScope);  //do not change s_curscope

                if (s_context->tmpParaWithoutIdNum && s_context->tmpParaWithIdNum)
                {
                    std::cout<<"error in T_CDECTION_DECTIONSFS_INITDECTORLIST: func's param do not support mix style at line "
                    <<getLineno()<<std::endl;
                    exit(0);
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
                Symbol *tmpsymbol = new Symbol(Symbol::SYMBOL_VAR);
                tmpsymbol->symbolName = s_context->tmpIdenName;


                tmpsymbol->typeClass.clone(&tmpType);

                if (NULL != Scope::s_curScope->searchSymbolVarMap(tmpsymbol->symbolName)) {
                    std::cout<<"error in T_CDECTION_DECTIONSFS_INITDECTORLIST: duplicate var "
                    << tmpsymbol->symbolName << " at line " << getLineno() << std::endl;
                    delete tmpsymbol;
                    exit(0);
                }

                /*if (Scope::s_curScope->symbolVarMap.find(tmpsymbol->symbolName) != Scope::s_curScope->symbolVarMap.end())
                {
                    std::cout<<"error in T_CDECTION_DECTIONSFS_INITDECTORLIST: duplicate var "
                    << tmpsymbol->symbolName << " at line " << getLineno() << std::endl;
                    delete tmpType;
                    exit(0);
                }*/

                Scope::s_curScope->defineSymbol(tmpsymbol);
            }

            //delete tmpType;
            break;
        }
        default:{

            std::cout<<"error in DectionAst: nodetype is invalid"<<std::endl;
            exit(0);
            break;
        }
    }
}
