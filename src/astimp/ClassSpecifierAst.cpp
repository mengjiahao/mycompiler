#include "../../include/ast/ClassSpecifierAst.h"

ClassSpecifierAst::ClassSpecifierAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ClassSpecifierAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch (nodeType){
        case T_CCLASSSF_CLASS_ID_CLASSDECTIONLIST:{
            std::cout << "walk in T_CCLASSSF_CLASS_ID_CLASSDECTIONLIST" << endl;

            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            //Scope *tmpScope = new Scope();
            if (Scope::resolveScope(s_context->tmpIdenName, Scope::SCOPE_CLASS))
            {
                std::cout << "error in T_CCLASSSF_CLASS_ID_CLASSDECTIONLIST: " << s_context->tmpIdenName
                << " has been defined at line " << getLineno() << std::endl;
                stopWalk();
                return ;
            }

            Scope *tmpScope = new Scope();
            tmpScope->initClassScope(s_context->tmpIdenName);
            Scope::pushScope(Scope::s_curScope,tmpScope);
            Scope::setCurScope(tmpScope);

            childs.at(1)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            Scope::setCurScope(Scope::encloseScope(Scope::s_curScope));
            //std::cout<<"safsadfafasfsafasf"<<Scope::s_curScope->scopeName<<std::endl;

            TypeClass tmp;
            //tmp.scopeType = tmpScope;
            tmp.setScopeType(tmpScope);
            s_context->clearContext();
            s_context->tmpDeclType.clone(&tmp);
            break;
        }
        case T_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST:{
            std::cout << "walk in T_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST" << endl;

            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            //Scope *tmpScope = new Scope();
            if (Scope::resolveScope(s_context->tmpIdenName, Scope::SCOPE_CLASS))
            {
                std::cout << "error in T_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST: "
                << s_context->tmpIdenName << " has been defined at line " << getLineno() << std::endl;
                stopWalk();
                return ;
            }

            //tmpScope->initClassScope(s_context->tmpIdenName);

            if (childs.at(1)->nodeType!=T_CTERMINATE_CIDLIST_ID)
            {
                std::cout << "sorry in T_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST: our compiler do not support multiple inheritance at line "
                << getLineno() << std::endl;
                stopWalk();
                return ;
            }

            Scope *tmpScope = new Scope();
            tmpScope->initClassScope(s_context->tmpIdenName);

            childs.at(1)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            Scope *superScope = Scope::resolveScope(s_context->tmpIdenName, Scope::SCOPE_CLASS);

            if (!superScope)
            {
                std::cout<<"error in T_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST: the super class "
                << s_context->tmpIdenName << " does not exit at line " << getLineno() << std::endl;
                delete tmpScope;

                stopWalk();
                return ;
            }

            tmpScope->setSuperClass(superScope);
            Scope::pushScope(Scope::s_curScope,tmpScope);
            Scope::setCurScope(tmpScope);

            childs.at(2)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            Scope::setCurScope(Scope::encloseScope(Scope::s_curScope));

            TypeClass tmp;
            //tmp.scopeType = tmpScope;
            tmp.setScopeType(tmpScope);
            s_context->clearContext();
            s_context->tmpDeclType.clone(&tmp);
            break;
        }
        case T_CCLASSSF_CLASS_ID:{
            std::cout << "walk in T_CCLASSSF_CLASS_ID" << endl;

            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            Scope *tmpScope = Scope::resolveScope(s_context->tmpIdenName,Scope::SCOPE_CLASS);
            if (!tmpScope)
            {
                std::cout<<"error in T_CCLASSSF_CLASS_ID: the super class "
                << s_context->tmpIdenName << " does not exit at line "<<getLineno()<<std::endl;
                stopWalk();
                return ;
            }

            TypeClass tmp;
            //tmp.scopeType = tmpScope;
            tmp.setScopeType(tmpScope);
            s_context->clearContext();
            s_context->tmpDeclType.clone(&tmp);
            break;
        }
        default:{
            std::cout << "error in ClassSpecifierAst: nodeType is invalid" << std::endl;
            stopWalk();
            return ;
            break;
        }
    }

}
