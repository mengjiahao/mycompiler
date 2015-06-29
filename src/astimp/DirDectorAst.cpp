#include "../../include/ast/DirDectorAst.h"

DirDectorAst::DirDectorAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}

void DirDectorAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType){
        case T_CDIRDECTOR_ID:{
            //std::cout << "walk in T_CDIRDECTOR_ID" << endl;
            LogiMsg::logi("walk in T_CDIRDECTOR_ID", getLineno());

            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            break;
        }
        case T_CDIRDECTOR_DIRDECTOR_ARRAY_CONSTEXP:{
            //std::cout << "walk in T_CDIRDECTOR_DIRDECTOR_ARRAY_CONSTEXP" << endl;
            LogiMsg::logi("walk in T_CDIRDECTOR_DIRDECTOR_ARRAY_CONSTEXP", getLineno());

            break;
        }
        case T_CDIRDECTOR_DIRDECTOR_ARRAY_VOID:{
            //std::cout << "walk in T_CDIRDECTOR_DIRDECTOR_ARRAY_VOID" << endl;
            LogiMsg::logi("walk in T_CDIRDECTOR_DIRDECTOR_ARRAY_VOID", getLineno());


            break;
        }
        case T_CDIRDECTOR_DIRDECTOR_CALL_PARAMTYPELIST:{
            //std::cout << "walk in T_CDIRDECTOR_DIRDECTOR_CALL_PARAMTYPELIST" << endl;
            LogiMsg::logi("walk in T_CDIRDECTOR_DIRDECTOR_CALL_PARAMTYPELIST", getLineno());

            if (childs.at(0)->nodeType != T_CDIRDECTOR_ID)
            {
                /*std::cout<<"error in T_CDIRDECTOR_DIRDECTOR_CALL_PARAMTYPELIST: the children's type is not T_CDIRDECTOR_ID at line "
                <<getLineno()<<std::endl;*/
                LogiMsg::logi("error in T_CDIRDECTOR_DIRDECTOR_CALL_PARAMTYPELIST: the children's type is not T_CDIRDECTOR_ID",
                getLineno());
                stopWalk();
                return ;
            }

            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            string tmp1 = s_context->tmpIdenName;

            childs.at(1)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            s_context->tmpIdenName = tmp1;
            s_context->isFunc = true;
            break;
        }
        case T_CDIRDECTOR_DIRDECTOR_CALL_EXP:{
            //std::cout << "walk in T_CDIRDECTOR_DIRDECTOR_CALL_EXP" << endl;
            LogiMsg::logi("walk in T_CDIRDECTOR_DIRDECTOR_CALL_EXP", getLineno());

            break;
        }
        case T_CDIRDECTOR_DIRDECTOR_CALL_VOID:{
            //std::cout << "walk in T_CDIRDECTOR_DIRDECTOR_CALL_VOID" << endl;
            LogiMsg::logi("walk in T_CDIRDECTOR_DIRDECTOR_CALL_VOID", getLineno());

            if (childs.at(0)->nodeType != T_CDIRDECTOR_ID)
            {
                /*std::cout<<"error in T_CDIRDECTOR_DIRDECTOR_CALL_VOID: the children's type is not T_CDIRDECTOR_ID at line "
                <<getLineno()<<std::endl;*/
                LogiMsg::logi("error in T_CDIRDECTOR_DIRDECTOR_CALL_VOID: the children's type is not T_CDIRDECTOR_ID",
                getLineno());
                stopWalk();
                return ;
            }

            childs.at(0)->walk();
            if (checkIsNotWalking()) {
                return ;
            }

            string tmp1 = s_context->tmpIdenName;
            s_context->clearContext();
            s_context->tmpIdenName = tmp1;
            s_context->isFunc = true;
            break;
        }
        default:{
            //std::cout<<"error in DirDectorAst: nodetype is invalid"<<std::endl;
            LogiMsg::logi("error in DirDectorAst: nodetype is invalid", getLineno());
            stopWalk();
            return ;
        }
    }

}
