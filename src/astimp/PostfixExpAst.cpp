
#include "../../include/ast/PostfixExpAst.h"

PostfixExpAst::PostfixExpAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void PostfixExpAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType) {
    case T_CPOSTEXP_POSTEXP_ARRAY_EXP: {
        std::cout << "error in T_CPOSTEXP_POSTEXP_ARRAY_EXP: array is not support at line "
        << getLineno() << std::endl;
        stopWalk();
        return ;


        break;
    }

    case T_CPOSTEXP_POSTEXP_CALL_VOID: {
        std::cout << "walk in T_CPOSTEXP_POSTEXP_CALL_VOID" << endl;

        if (childs.at(0)->getNodeType() != T_CTERMINATE_CPRIMEXP_ID) {
            std::cout << "error in T_CPOSTEXP_POSTEXP_CALL_VOID: POSTEXP should be a funcName at line "
            << getLineno() << std::endl;
            stopWalk();
            return ;
        }

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        Scope *s = Scope::s_curScope->resolveScope(s_context->tmpIdenName, Scope::SCOPE_GLOBALFUNC);
        if (NULL == s) {
            s = Scope::s_curScope->resolveScope(s_context->tmpIdenName, Scope::SCOPE_GLOBALFUNCDECL);
            if (NULL == s) {
                s = Scope::s_curScope->resolveScope(s_context->tmpIdenName, Scope::SCOPE_GLOBALFUNCCHAN);
            }
        }

        /*if (Scope::SCOPE_CLASSFUNC === Scope::s_curScope->getScopeType()) {
            s = Scope::s_curScope->resolveClassFuncScope(Scope::s_curScope->getParent, s_context->tmpIdenName);
        }*/  //not support call class memberFunc in class memberFunc

        if (NULL != s) {
            genCodeCallVoid(s);
        } else {
            std::cout << "error in T_CPOSTEXP_POSTEXP_CALL_VOID: the func "
            << s_context->tmpIdenName << "has not be declared at line " << getLineno() << std::endl;
            stopWalk();
            return ;
        }


        break;
    }

    case T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST: {
        std::cout << "walk in T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST"<< std::endl;

        if (childs.at(0)->getNodeType() != T_CTERMINATE_CPRIMEXP_ID) {
            std::cout << "error in T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST: POSTEXP should be a funcName at line "
            << getLineno() << std::endl;
            stopWalk();
            return ;
        }

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        Scope *s = Scope::s_curScope->resolveScope(s_context->tmpIdenName, Scope::SCOPE_GLOBALFUNC);
        if (NULL == s) {
            s = Scope::s_curScope->resolveScope(s_context->tmpIdenName, Scope::SCOPE_GLOBALFUNCDECL);
            if (NULL == s) {
                s = Scope::s_curScope->resolveScope(s_context->tmpIdenName, Scope::SCOPE_GLOBALFUNCCHAN);
            }
        }

        if (NULL != s) {

            childs.at(1)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            if (ItmCode::OPR_ARGLIST == s_context->tmpOpType) {

                if (s->symbolSeqList.size() != s_context->tmpArgExpList.size()) {
                    std::cout << "error in T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST: the func "
                    << s->getScopeName() << "params's num mismatch at line " << getLineno() << std::endl;
                    stopWalk();
                    return ;
                }

                list<Symbol *>::iterator itr1;
                vector<void *>::iterator itr2;


                for(itr1 = s->symbolSeqList.begin(), itr2 = s_context->tmpArgExpList.begin();
                itr1 != s->symbolSeqList.end() && itr2 != s_context->tmpArgExpList.end();
                ++itr1, ++itr2) {
                    if ( false == TypeClass::compare((*itr1)->getTypeClass(), ((Symbol *)*itr2)->getTypeClass()) ) {
                        std::cout << "error in T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST: the func "
                        << s->getScopeName() << "params's type mismatch at line " << getLineno() << std::endl;
                        stopWalk();
                        return ;
                    }
                }

                genCodeCallArgExpList(s, ItmCode::copyVectorToAllArgList(s_context->tmpArgExpList));



            } else {
                std::cout << "error in T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST: the func "
                << s_context->tmpIdenName << "doesn't has argExpList " << getLineno() << std::endl;
                stopWalk();
                return ;
            }


        } else {
            std::cout << "error in T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST: the func "
            << s_context->tmpIdenName << "has not be declared at line " << getLineno() << std::endl;
            stopWalk();
            return ;
        }




        break;
    }

    case T_CPOSTEXP_POSTEXP_REF_ID: {
        std::cout << "walk in T_CPOSTEXP_POSTEXP_REF_ID" << endl;

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        break;
    }





    default: {
        std::cout << "error in PostfixExpAst: nodeType is invalid" << std::endl;
        break;
        stopWalk();
        return ;
    }


    }
}

void PostfixExpAst::genCodeCallVoid(Scope* func_t)
{
    if (NULL == func_t) {
        std::cout << "error in PostfixExpAst: exist one member of genCodeCallVoid()'s params is NULL"
        << std::endl;
        return ;
    }

    ItmCode *newCode = new ItmCode(ItmCode::IR_CALLFUNC,
    ItmCode::OPR_SCOPE, func_t);

    ItmCode::addToAllItmCode(newCode);

}

void PostfixExpAst::genCodeCallArgExpList(Scope* func_t, vector<void* >* argExpList_t)
{
    if (NULL == func_t || NULL == argExpList_t) {
        std::cout << "error in PostfixExpAst: exist one member of genCodeArgExpList()'s params is NULL"
        << std::endl;
        return ;
    }

    ItmCode *newCode = new ItmCode(ItmCode::IR_CALLFUNC,
    ItmCode::OPR_SCOPE, func_t,
    ItmCode::OPR_ARGLIST, argExpList_t);

    ItmCode::addToAllItmCode(newCode);
}



