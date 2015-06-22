#include "../../include/ast/ClassSpecifierAst.h"

ClassSpecifierAst::ClassSpecifierAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void ClassSpecifierAst::walk()
{
    switch (nodeType){
        case T_CCLASSSF_CLASS_ID_CLASSDECTIONLIST:{
            childs.at(0)->walk();
            Scope *tmpScope=new Scope();
            if (Scope::resolveScope(s_context->tmpIdenName, Scope::SCOPE_CLASS))
            {
                std::cout<<"error: this class  has been defined at line "<<getLineno()<<std::endl;
                exit(0);
            }
            tmpScope->initClassScope(s_context->tmpIdenName);
            Scope::pushScope(Scope::s_curScope,tmpScope);
            Scope::setCurScope(tmpScope);
            childs.at(1)->walk();
            Scope::setCurScope(Scope::encloseScope(Scope::s_curScope));
            //std::cout<<"safsadfafasfsafasf"<<Scope::s_curScope->scopeName<<std::endl;
            TypeClass *tmp=new TypeClass();
            tmp->scopeType=tmpScope;
            s_context->clearContext();
            s_context->tmpDeclType.clone(tmp);
            delete tmp;
            break;
        }
        case T_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST:{
            childs.at(0)->walk();
            Scope *tmpScope=new Scope();
            if (Scope::resolveScope(s_context->tmpIdenName, Scope::SCOPE_CLASS))
            {
                std::cout<<"error: this class  has been defined at line "<<getLineno()<<std::endl;
                exit(0);
            }
            tmpScope->initClassScope(s_context->tmpIdenName);
            if (childs.at(1)->nodeType!=T_CTERMINATE_CIDLIST_ID)
            {
                std::cout<<"sorry, our compiler do not support multiple inheritance at line "<<getLineno()<<std::endl;
                exit(0);
            }
            childs.at(1)->walk();
            Scope *superScope=Scope::resolveScope(s_context->tmpIdenName,Scope::SCOPE_CLASS);
            if (!superScope)
            {
                std::cout<<"error: the super class do not exit at line "<<getLineno()<<std::endl;
                exit(0);
            }
            tmpScope->setSuperClass(superScope);
            Scope::pushScope(Scope::s_curScope,tmpScope);
            Scope::setCurScope(tmpScope);
            childs.at(2)->walk();
            Scope::setCurScope(Scope::encloseScope(Scope::s_curScope));
            TypeClass *tmp=new TypeClass();
            tmp->scopeType=tmpScope;
            s_context->clearContext();
            s_context->tmpDeclType.clone(tmp);
            delete tmp;
            break;
        }
        case T_CCLASSSF_CLASS_ID:{
            childs.at(0)->walk();
            Scope *tmpScope=Scope::resolveScope(s_context->tmpIdenName,Scope::SCOPE_CLASS);
            if (!tmpScope)
            {
                std::cout<<"error: the super class do not exit at line "<<getLineno()<<std::endl;
                exit(0);
            }
            TypeClass *tmp=new TypeClass();
            tmp->scopeType=tmpScope;
            s_context->clearContext();
            s_context->tmpDeclType.clone(tmp);
            delete tmp;
            break;
        }
        default:{
            std::cout<<"nodetype error at ClassSpecifierAst"<<std::endl;
            exit(0);
            break;
        }
    }
}
