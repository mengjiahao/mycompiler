
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

        Scope *s = processPostfixBeforeCall(nodeType);
        if (NULL == s) {
            stopWalk();
            return;

        } else {
            //genCode
        }

        break;
    }

    case T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST: {
        std::cout << "walk in T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST"<< std::endl;

        Scope *s = processPostfixBeforeCall(nodeType);
        if (NULL == s) {
            stopWalk();
            return;

        }

        childs.at(1)->walk();
        if (checkIsNotWalking()) {
            return ;
        }

        if (ItmCode::OPR_ARGLIST == s_context->tmpOpType) {
            if (s->symbolSeqList.size() != s_context->tmpExpList.size()) {

                std::cout << "error in T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST: the func "
                << s->getScopeName() << "params's num mismatch at line " << getLineno() << std::endl;
                stopWalk();
                return ;
            }

            list<Symbol *>::iterator itr1;
            vector<void *>::iterator itr2;

            for(itr1 = s->symbolSeqList.begin(), itr2 = s_context->tmpExpList.begin();
                itr1 != s->symbolSeqList.end() && itr2 != s_context->tmpExpList.end();
                ++itr1, ++itr2) {
                if ( false == TypeClass::compare((*itr1)->getTypeClass(),
                    ((Symbol *)*itr2)->getTypeClass()) ) {
                    std::cout << "error in T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST: the func "
                    << s->getScopeName() << "params's type mismatch at line " << getLineno() << std::endl;
                    stopWalk();
                    return ;
                }
            }

            //genCodeCallArgExpList(s, ItmCode::copyVectorToAllExpList(s_context->tmpExpList));

        } else {
            std::cout << "error in T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST: the func "
            << s_context->tmpIdenName << "doesn't has argExpList " << getLineno() << std::endl;
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

        if (ItmCode::OPR_ID == s_context->tmpOpType) {
            Scope *s = Scope::resolveScope(s_context->tmpIdenName, Scope::SCOPE_CLASS);
            if (NULL != s) {
                childs.at(1)->walk();
                if (checkIsNotWalking()) {
                    return ;
                }

                Symbol *t = Scope::resolveSymbolMemVar(s, s_context->tmpIdenName);
                if (NULL != t) {
                    s_context->tmpClassScope = s;
                    //s_context->tmpIdenName;
                    s_context->isMemVar = true;

                    s_context->tmpOpType = ItmCode::OPR_CLASS_REFLIST;
                    s_context->addToExpList(s);
                    s_context->addToExpList(t);
                }

            }

        } else if (ItmCode::OPR_CLASS_REFLIST == s_context->tmpOpType) {


        } else {
            //error
        }



        break;
    }

    case T_CPOSTEXP_POSTEXP_INC_OP: {
        break;
    }

    case T_CPOSTEXP_POSTEXP_DEC_OP: {
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


Scope* PostfixExpAst::processPostfixBeforeCall(NodeAst::NodeType nodeType_t)
{
        switch(childs.at(0)->getNodeType()) {
        case T_CTERMINATE_CPRIMEXP_ID: {

            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return NULL;
            }

            Scope *s = Scope::s_curScope->resolveGlobalFuncScope(s_context->tmpIdenName);

            if (NULL != s) {
                //genCode

            } else {
                std::cout << "error in processPostfixBeforeCall(" << nodeType_t << "): the func "
                << s_context->tmpIdenName << "doesn't exist at line " << getLineno() << std::endl;
                stopWalk();
                return NULL;
            }

            break;
        }

        case T_CTERMINATE_CPOSTEXP_POSTEXP_REF_ID: {
            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return NULL;
            }

            if (ItmCode::OPR_CLASS_REFLIST == s_context->tmpOpType) {
                if (NULL != s_context->tmpClassScope) {

                    Scope *s = Scope::s_curScope->resolveClassFuncScope(s_context->tmpClassScope,
                    s_context->tmpIdenName);

                    if (NULL != s) {
                        //genCode
                    } else {
                    }
                }
            }

            break;
        }

        default: {
            break;
        }

        }

        return NULL;
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



