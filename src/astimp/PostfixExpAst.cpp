
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



        break;
    }

    case T_CPOSTEXP_POSTEXP_CALL_VOID: {
        std::cout << "walk in T_CPOSTEXP_POSTEXP_CALL_VOID" << endl;
        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        if (s_context->tmpOpType==ItmCode::OPR_CLASS_REFLIST)
        {
            Reg *result=Reg::getReg(0, ((Scope *)(s_context->getExpListLast()))->getReturnTypeClass()->getTypeSfType());
            vector<void* >* refList = ItmCode::copyVectorToAllExpList(s_context->tmpExpList);
            ItmCode *tmpCode=new ItmCode(ItmCode::IR_CALLCLASSFUNC, ItmCode::OPR_CLASS_REFLIST,(void *)refList, ItmCode::OPR_INVALID, NULL, ItmCode::OPR_REGISTER, result);
            Scope::s_curScope->addItemCode(tmpCode);
            s_context->clearContext();
            s_context->tmpOpType=ItmCode::OPR_REGISTER;
            s_context->tmpExpReg=result;

        }
        else
        {
            Scope *tmpScope=NULL;

            if (NULL != (tmpScope=Scope::s_curScope->resolveGlobalFuncScope(s_context->tmpIdenName)))
            {
                Reg *result=Reg::getReg(0, tmpScope->getReturnTypeClass()->getTypeSfType());
                ItmCode *tmpCode=new ItmCode(ItmCode::IR_CALLFUNC, ItmCode::OPR_SCOPE ,(void *)tmpScope, ItmCode::OPR_INVALID, NULL, ItmCode::OPR_REGISTER, result);
                Scope::s_curScope->addItemCode(tmpCode);
                s_context->clearContext();
                s_context->tmpOpType=ItmCode::OPR_REGISTER;
                s_context->tmpExpReg=result;
            }
            else if (NULL != (tmpScope=Scope::resolveClassFuncScope(Scope::s_curScope, s_context->tmpIdenName)))
            {
                Reg *result=Reg::getReg(0, tmpScope->getReturnTypeClass()->getTypeSfType());
                ItmCode *tmpCode=new ItmCode(ItmCode::IR_CALLCLASSFUNC, ItmCode::OPR_SCOPE ,(void *)tmpScope, ItmCode::OPR_INVALID, NULL, ItmCode::OPR_REGISTER, result);
                Scope::s_curScope->addItemCode(tmpCode);
                s_context->clearContext();
                s_context->tmpOpType=ItmCode::OPR_REGISTER;
                s_context->tmpExpReg=result;
            }
            else
            {
                std::cout << "error: in T_CPOSTEXP_POSTEXP_CALL_VOID the func " << s_context->tmpIdenName << "is not exist" << std::endl;
                stopWalk();
                return;
            }
        }



        break;
    }

    case T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST: {
        std::cout << "walk in T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST"<< std::endl;

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        if (s_context->tmpOpType==ItmCode::OPR_CLASS_REFLIST)
        {
            Reg *result=Reg::getReg(0, ((Scope *)(s_context->getExpListLast()))->getReturnTypeClass()->getTypeSfType());
            vector<void* >* refList = ItmCode::copyVectorToAllExpList(s_context->tmpExpList);
            childs.at(1)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            vector<void* >* arguList = ItmCode::copyVectorToAllExpList(s_context->tmpExpList);


            ItmCode *tmpCode=new ItmCode(ItmCode::IR_CALLCLASSFUNC, ItmCode::OPR_CLASS_REFLIST,(void *)refList, ItmCode::OPR_ARGLIST, (void *)arguList, ItmCode::OPR_REGISTER, result);
            Scope::s_curScope->addItemCode(tmpCode);
            s_context->clearContext();
            s_context->tmpOpType=ItmCode::OPR_REGISTER;
            s_context->tmpExpReg=result;

        }
        else
        {
            Scope *tmpScope=NULL;
            if (NULL != (tmpScope=Scope::s_curScope->resolveGlobalFuncScope(s_context->tmpIdenName)))
            {
                Reg *result=Reg::getReg(0, tmpScope->getReturnTypeClass()->getTypeSfType());
                childs.at(1)->walk();
                if (checkIsNotWalking()) {
                    return ;
                }

                vector<void* >* arguList = ItmCode::copyVectorToAllExpList(s_context->tmpExpList);

                ItmCode *tmpCode=new ItmCode(ItmCode::IR_CALLFUNC, ItmCode::OPR_SCOPE ,(void *)tmpScope, ItmCode::OPR_ARGLIST, (void *)arguList, ItmCode::OPR_REGISTER, result);
                Scope::s_curScope->addItemCode(tmpCode);
                s_context->clearContext();
                s_context->tmpOpType=ItmCode::OPR_REGISTER;
                s_context->tmpExpReg=result;
            }
            else if (NULL != (tmpScope=Scope::resolveClassFuncScope(Scope::s_curScope, s_context->tmpIdenName)))
            {
                Reg *result=Reg::getReg(0, tmpScope->getReturnTypeClass()->getTypeSfType());
                childs.at(1)->walk();
                if (checkIsNotWalking()) {
                    return ;
                }

                vector<void* >* arguList = ItmCode::copyVectorToAllExpList(s_context->tmpExpList);

                ItmCode *tmpCode=new ItmCode(ItmCode::IR_CALLCLASSFUNC, ItmCode::OPR_SCOPE ,(void *)tmpScope, ItmCode::OPR_ARGLIST, (void *)arguList, ItmCode::OPR_REGISTER, result);
                Scope::s_curScope->addItemCode(tmpCode);
                s_context->clearContext();
                s_context->tmpOpType=ItmCode::OPR_REGISTER;
                s_context->tmpExpReg=result;
            }
            else
            {
                std::cout << "error: in T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST the func " << s_context->tmpIdenName << "is not exist" << std::endl;
                stopWalk();
                return;
            }
        }


        break;
    }

    case T_CPOSTEXP_POSTEXP_REF_ID: {
        std::cout << "walk in T_CPOSTEXP_POSTEXP_REF_ID" << endl;

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        if (s_context->tmpExpSymbol->typeClass.scopeType==NULL)
        {
            std::cout << "error in T_CPOSTEXP_POSTEXP_REF_ID the id " << s_context->tmpExpSymbol->getSymbolName() << "is not a class type " << std::endl;
            stopWalk();
            return;
        }
        Symbol *tmpSymbol=s_context->tmpExpSymbol;
        childs.at(1)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        if (parent->nodeType==NodeAst::T_CPOSTEXP_POSTEXP_CALL_ARGEXPLIST
            || parent->nodeType==NodeAst::T_CPOSTEXP_POSTEXP_CALL_VOID)
        {
            Scope *tmpScope=Scope::resolveClassFuncScope(tmpSymbol->typeClass.scopeType, s_context->tmpIdenName);
            if (tmpScope==NULL)
            {
                std::cout << "error: there is no func named " << s_context->tmpIdenName << "at line " << getLineno() <<std::endl;
                stopWalk();
                return;
            }
            s_context->clearContext();
            s_context->addToExpList((void *)tmpSymbol);
            s_context->addToExpList((void *)tmpScope);
            s_context->tmpOpType=ItmCode::OPR_CLASS_REFLIST;

        }
        else
        {
            Symbol *tmpMemSymbol=Scope::resolveSymbolMemVar(tmpSymbol->typeClass.scopeType, s_context->tmpIdenName);
            if (tmpMemSymbol==NULL)
            {
                std::cout << "error: there is no var named " << s_context->tmpIdenName << "at line " << getLineno() <<std::endl;
                stopWalk();
                return;
            }
            s_context->clearContext();
            s_context->addToExpList((void *)tmpSymbol);
            s_context->addToExpList((void *)tmpMemSymbol);
            s_context->tmpOpType=ItmCode::OPR_CLASS_REFLIST;
        }


        break;
    }

    case T_CPOSTEXP_POSTEXP_INC_OP: {

        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *tmpReg=processChildOperand(1);
        if (s_context->tmpOpType == ItmCode::OPR_SYMBOL)
        {
            ItmCode *tmpCode = new ItmCode(ItmCode::IR_INC_OP,
                                       ItmCode::OPR_REGISTER, (void *)tmpReg,
                                       ItmCode::OPR_INVALID, NULL,
                                       ItmCode::OPR_SYMBOL, (void *)(s_context->tmpExpSymbol));
            Scope::s_curScope->addItemCode(tmpCode);
        }
        else if (s_context->tmpOpType == ItmCode::OPR_CLASS_REFLIST)
        {
            vector<void* >* refList = ItmCode::copyVectorToAllExpList(s_context->tmpExpList);
            ItmCode *tmpCode = new ItmCode(ItmCode::IR_INC_OP,
                                       ItmCode::OPR_REGISTER, (void *)tmpReg,
                                       ItmCode::OPR_INVALID, NULL,
                                       ItmCode::OPR_CLASS_REFLIST, (void *)(refList));
            Scope::s_curScope->addItemCode(tmpCode);
        }
        else
        {
            std::cout << "error in T_CPOSTEXP_POSTEXP_INC_OP: the op is not left value at line " << getLineno() <<std::endl;
            stopWalk();
            return;
        }
        s_context->clearContext();
        s_context->tmpOpType = ItmCode::OPR_REGISTER;
        s_context->tmpExpReg = tmpReg;

        break;
    }

    case T_CPOSTEXP_POSTEXP_DEC_OP: {
        childs.at(0)->walk();
        if (checkIsNotWalking()) {
            return ;
        }
        Reg *tmpReg=processChildOperand(1);
        if (s_context->tmpOpType == ItmCode::OPR_SYMBOL)
        {
            ItmCode *tmpCode = new ItmCode(ItmCode::IR_DEC_OP,
                                       ItmCode::OPR_REGISTER, (void *)tmpReg,
                                       ItmCode::OPR_INVALID, NULL,
                                       ItmCode::OPR_SYMBOL, (void *)(s_context->tmpExpSymbol));
            Scope::s_curScope->addItemCode(tmpCode);
        }
        else if (s_context->tmpOpType == ItmCode::OPR_CLASS_REFLIST)
        {
            vector<void* >* refList = ItmCode::copyVectorToAllExpList(s_context->tmpExpList);
            ItmCode *tmpCode = new ItmCode(ItmCode::IR_DEC_OP,
                                       ItmCode::OPR_REGISTER, (void *)tmpReg,
                                       ItmCode::OPR_INVALID, NULL,
                                       ItmCode::OPR_CLASS_REFLIST, (void *)(refList));
            Scope::s_curScope->addItemCode(tmpCode);
        }
        else
        {
            std::cout << "error in T_CPOSTEXP_POSTEXP_INC_OP: the op is not left value at line " << getLineno() <<std::endl;
            stopWalk();
            return;
        }
        s_context->clearContext();
        s_context->tmpOpType = ItmCode::OPR_REGISTER;
        s_context->tmpExpReg = tmpReg;
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





