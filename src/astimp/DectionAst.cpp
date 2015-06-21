#include "../../include/ast/DectionAst.h"

DectionAst::DectionAst(NodeAst::NodeType nodeType_t) : NodeAst(nodeType_t) {

}
void DectionAst::walk()
{
    switch (nodeType){
        case T_CDECTION_DECTIONSFS:{
            if ((childs.at(0)->nodeType!=T_CCLASSSF_CLASS_ID_CLASSDECTIONLIST) && (childs.at(0)->nodeType!=T_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST))
            {
                if (childs.at(0)->nodeType==T_CCLASSSF_CLASS_ID)
                {
                    std::cout<<"sorry, our compiler do not support class declaration at line "<<getLineno()<<std::endl;
                }
                else
                    std::cout<<"error: this type is builtin type, you can not define it at line "<<getLineno()<<std::endl;
                exit(0);
            }
            childs.at(0)->walk();
            break;
        }
        case T_CDECTION_DECTIONSFS_INITDECTORLIST:{

            break;
        }
        default:{
            std::cout<<"nodetype error at DectionAst"<<std::endl;
            exit(0);
            break;
        }
    }
}
