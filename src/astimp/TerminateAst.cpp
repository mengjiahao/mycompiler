
#include "../../include/ast/TerminateAst.h"
#include <sstream>
using namespace std;

TerminateAst::TerminateAst(NodeAst::NodeType nodeType_t, string *token_t) : NodeAst(nodeType_t)
{
    token = *token_t;
    delete token_t;
}


TerminateAst::TerminateAst(NodeAst::NodeType nodeType_t, const char* token_t) : NodeAst(nodeType_t)
{
    token = string(token_t);
}

TerminateAst::TerminateAst(NodeAst::NodeType nodeType_t, const string& token_t) : NodeAst(nodeType_t)
{
    token = token_t;
}


string TerminateAst::getDotToken()
{
    return token + " : " + s_nodeTypeString[nodeType];
}

TerminateAst::~TerminateAst()
{

}

void TerminateAst::walk()
{
    if (checkIsNotWalking()) {
        return ;
    }

    switch(nodeType) {

    //const_value
    case T_CTERMINATE_CCONSTVAR_INT_CONST: {
        /*std::cout << "walk in T_CTERMINATE_CCONSTVAR_INT_CONST" << endl;*/
        LogiMsg::logi("walk in T_CTERMINATE_CCONSTVAR_INT_CONST", getLineno());

        Symbol *rst = Scope::s_globalScope->resolveSymbol(token, Symbol::SYMBOL_INTEGER_CONSTANT);

        if (NULL == rst) {
            rst = new Symbol(Symbol::SYMBOL_INTEGER_CONSTANT);
            rst->setSymbolName(token);
            rst->addSymbolValue(token);
            rst->typeClass.setTypeSfType(TypeClass::SF_INT);

            rst = (0 == Scope::s_globalScope->defineSymbol(rst)) ? NULL : rst;

        }
        s_context->clearContext();
        s_context->tmpOpType = ItmCode::OPR_SYMBOL;
        s_context->tmpExpSymbol = rst;

        break;
    }
    case T_CTERMINATE_CCONSTVAR_CHAR_CONST: {
        /*std::cout << "walk in T_CTERMINATE_CCONSTVAR_CHAR_CONST" << endl;*/
        LogiMsg::logi("walk in T_CTERMINATE_CCONSTVAR_CHAR_CONST", getLineno());

        Symbol *rst = Scope::s_globalScope->resolveSymbol(token, Symbol::SYMBOL_CHARACTER_CONSTANT);

        if (NULL == rst) {
            rst = new Symbol(Symbol::SYMBOL_CHARACTER_CONSTANT);
            rst->setSymbolName(token);
            //string charValue = token.substr(1, 1);
            rst->addSymbolValue(token);
            rst->typeClass.setTypeSfType(TypeClass::SF_CHAR);

            //cout << "!" << rst->getFirstSymbolValue() << endl;

            rst = (0 == Scope::s_globalScope->defineSymbol(rst)) ? NULL : rst;

        }
        s_context->clearContext();
        s_context->tmpOpType = ItmCode::OPR_SYMBOL;
        s_context->tmpExpSymbol = rst;

        break;
    }
    case T_CTERMINATE_CCONSTVAR_FLOAT_CONST: {
        /*std::cout << "walk in T_CTERMINATE_CCONSTVAR_FLOAT_CONST" << endl;*/
        LogiMsg::logi("walk in T_CTERMINATE_CCONSTVAR_FLOAT_CONST", getLineno());

        Symbol *rst = Scope::s_globalScope->resolveSymbol(token, Symbol::SYMBOL_FLOATING_CONSTANT);

        if (NULL == rst) {
            rst = new Symbol(Symbol::SYMBOL_FLOATING_CONSTANT);
            rst->setSymbolName(token);
            rst->addSymbolValue(token);
            rst->typeClass.setTypeSfType(TypeClass::SF_DOUBLE);

            rst = (0 == Scope::s_globalScope->defineSymbol(rst)) ? NULL : rst;

        }
        s_context->clearContext();
        s_context->tmpOpType = ItmCode::OPR_SYMBOL;
        s_context->tmpExpSymbol = rst;

        break;
    }

    //primary_expression
    case T_CTERMINATE_CPRIMEXP_ID: {
        //std::cout << "walk in T_CTERMINATE_CPRIMEXP_ID" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CPRIMEXP_ID", getLineno());

        s_context->clearContext();
        s_context->tmpOpType = ItmCode::OPR_ID;
        s_context->tmpIdenName = token;

        break;
    }
    case T_CTERMINATE_CPRIMEXP_STR: {
        //std::cout << "walk in T_CTERMINATE_CPRIMEXP_STR" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CPRIMEXP_STR", getLineno());

        Symbol *rst = Scope::s_globalScope->resolveSymbol(token, Symbol::SYMBOL_STRING_LITERAL);

        if (NULL == rst) {
            rst = new Symbol(Symbol::SYMBOL_STRING_LITERAL);
            static int s_string=0;
            s_string++;
            string idString;
            string tmpName = ".S";
            stringstream ss;
            ss << s_string;
            ss >> idString;
            tmpName +=idString;

            rst->setSymbolName(tmpName);
            //string strValue = token.substr(1, token.size() - 2);
            rst->addSymbolValue(token);
            rst->typeClass.setTypeSfType(TypeClass::SF_INT);

           // cout << "!" << rst->getFirstSymbolValue() << endl;

            rst = (0 == Scope::s_curScope->defineSymbol(rst)) ? NULL : rst;

        }
        s_context->clearContext();
        s_context->tmpOpType = ItmCode::OPR_SYMBOL;
        s_context->tmpExpSymbol = rst;


        break;
    }

    //postfix_expression
    case T_CTERMINATE_CPOSTEXP_POSTEXP_REF_ID: {
        //std::cout << "walk in T_CTERMINATE_CPOSTEXP_POSTEXP_REF_ID" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CPOSTEXP_POSTEXP_REF_ID", getLineno());

        s_context->clearContext();
        s_context->tmpOpType = ItmCode::OPR_ID;
        s_context->tmpIdenName = token;

        break;
    }
    case T_CTERMINATE_CPOSTEXP_POSTEXP_PTR_ID: {
        //std::cout << "walk in T_CTERMINATE_CPOSTEXP_POSTEXP_PTR_ID" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CPOSTEXP_POSTEXP_PTR_ID", getLineno());

        break;
    }

    //unary_operator
    case T_CTERMINATE_CUNARY_OP_AND_OP: {
        //std::cout << "walk in T_CTERMINATE_CUNARY_OP_AND_OP" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CUNARY_OP_AND_OP", getLineno());

        break;
    }
	case T_CTERMINATE_CUNARY_OP_REF_OP: {
        //std::cout << "walk in T_CTERMINATE_CUNARY_OP_REF_OP" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CUNARY_OP_REF_OP", getLineno());

        break;
    }
	case T_CTERMINATE_CUNARY_OP_ADD_OP: {
        //std::cout << "walk in T_CTERMINATE_CUNARY_OP_ADD_OP" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CUNARY_OP_ADD_OP", getLineno());

        break;
    }
	case T_CTERMINATE_CUNARY_OP_SUB_OP: {
        //std::cout << "walk in T_CTERMINATE_CUNARY_OP_SUB_OP" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CUNARY_OP_SUB_OP", getLineno());

        break;
    }
	case T_CTERMINATE_CUNARY_OP_COMP_OP: {
        //std::cout << "walk in T_CTERMINATE_CUNARY_OP_COMP_OP" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CUNARY_OP_COMP_OP", getLineno());

        break;
    }
	case T_CTERMINATE_CUNARY_OP_NOT_OP: {
        //std::cout << "walk in T_CTERMINATE_CUNARY_OP_NOT_OP" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CUNARY_OP_NOT_OP", getLineno());

        break;
    }

    //assignment_operator
	case T_CTERMINATE_CASSIGN_OP_ASSIGN: {
        //std::cout << "walk in T_CTERMINATE_CASSIGN_OP_ASSIGN" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CASSIGN_OP_ASSIGN", getLineno());

        break;
    }
    case T_CTERMINATE_CASSIGN_OP_MUL_ASSIGN: {
        //std::cout << "walk in T_CTERMINATE_CASSIGN_OP_MUL_ASSIGN" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CASSIGN_OP_MUL_ASSIGN", getLineno());

        break;
    }
    case T_CTERMINATE_CASSIGN_OP_DIV_ASSIGN: {
        //std::cout << "walk in T_CTERMINATE_CASSIGN_OP_DIV_ASSIGN" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CASSIGN_OP_DIV_ASSIGN", getLineno());

        break;
    }
    case T_CTERMINATE_CASSIGN_OP_MOD_ASSIGN: {
        //std::cout << "walk in T_CTERMINATE_CASSIGN_OP_MOD_ASSIGN" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CASSIGN_OP_MOD_ASSIGN", getLineno());

        break;
    }
    case T_CTERMINATE_CASSIGN_OP_ADD_ASSIGN: {
        //std::cout << "walk in T_CTERMINATE_CASSIGN_OP_ADD_ASSIGN" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CASSIGN_OP_ADD_ASSIGN", getLineno());

        break;
    }
    case T_CTERMINATE_CASSIGN_OP_SUB_ASSIGN: {
        //std::cout << "walk in T_CTERMINATE_CASSIGN_OP_SUB_ASSIGN" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CASSIGN_OP_SUB_ASSIGN", getLineno());

        break;
    }
    case T_CTERMINATE_CASSIGN_OP_LEFT_ASSIGN: {
        //std::cout << "walk in T_CTERMINATE_CASSIGN_OP_LEFT_ASSIGN" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CASSIGN_OP_LEFT_ASSIGN", getLineno());

        break;
    }
    case T_CTERMINATE_CASSIGN_OP_RIGHT_ASSIGN: {
        //std::cout << "walk in T_CTERMINATE_CASSIGN_OP_RIGHT_ASSIGN" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CASSIGN_OP_RIGHT_ASSIGN", getLineno());

        break;
    }
    case T_CTERMINATE_CASSIGN_OP_AND_ASSIGN: {
        //std::cout << "walk in T_CTERMINATE_CASSIGN_OP_AND_ASSIGN" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CASSIGN_OP_AND_ASSIGN", getLineno());

        break;
    }
    case T_CTERMINATE_CASSIGN_OP_XOR_ASSIGN: {
        //std::cout << "walk in T_CTERMINATE_CASSIGN_OP_XOR_ASSIGN" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CASSIGN_OP_XOR_ASSIGN", getLineno());

        break;
    }
    case T_CTERMINATE_CASSIGN_OP_OR_ASSIGN: {
        //std::cout << "walk in T_CTERMINATE_CASSIGN_OP_OR_ASSIGN" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CASSIGN_OP_OR_ASSIGN", getLineno());

        break;
    }

    //assignment_expression
    case T_CTERMINATE_CASSIGNEXP_NEW_ID_VOID: {
        //std::cout << "walk in T_CTERMINATE_CASSIGNEXP_NEW_ID_VOID" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CASSIGNEXP_NEW_ID_VOID", getLineno());

        s_context->clearContext();
        s_context->tmpOpType = ItmCode::OPR_ID;
        s_context->tmpIdenName = token;

        break;
    }
    case T_CTERMINATE_CASSIGNEXP_DELETE_ID: {
        //std::cout << "walk in T_CTERMINATE_CASSIGNEXP_DELETE_ID" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CASSIGNEXP_DELETE_ID", getLineno());

        s_context->clearContext();
        s_context->tmpOpType = ItmCode::OPR_ID;
        s_context->tmpIdenName = token;

        break;
    }

    //jump_statement
    case T_CTERMINATE_CJUMPSTM_GOTO_ID: {
        //std::cout << "walk in T_CTERMINATE_CJUMPSTM_GOTO_ID" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CJUMPSTM_GOTO_ID", getLineno());

        break;
    }

    //labeled_statement
    case T_CTERMINATE_CLABSTM_ID_STM: {
        std::cout << "walk in T_CTERMINATE_CLABSTM_ID_STM" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CLABSTM_ID_STM", getLineno());

        break;
    }

    //identifier_list
    case T_CTERMINATE_CIDLIST_ID: {
        //std::cout << "walk in T_CTERMINATE_CIDLIST_ID" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CIDLIST_ID", getLineno());

        s_context->clearContext();
        //s_context->tmpOpType = ItmCode::OPR_ID;
        s_context->tmpIdenName = token;

        break;
    }
    case T_CTERMINATE_CIDLIST_IDLIST_ID: {
        //std::cout << "walk in T_CTERMINATE_CIDLIST_IDLIST_ID" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CIDLIST_IDLIST_ID", getLineno());

        break;
    }

    //direct_declarator
    case T_CTERMINATE_CDIRDECTOR_ID: {
        //std::cout << "walk in T_CTERMINATE_CDIRDECTOR_ID" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CDIRDECTOR_ID", getLineno());

        s_context->clearContext();
        //s_context->tmpOpType = ItmCode::OPR_ID;
        s_context->tmpIdenName = token;
        break;
    }

    //class_specifier
    case T_CTERMINATE_CCLASSSF_CLASS_ID_CLASSDECTIONLIST: {
        //std::cout << "walk in T_CTERMINATE_CCLASSSF_CLASS_ID_CLASSDECTIONLIST" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CCLASSSF_CLASS_ID_CLASSDECTIONLIST", getLineno());

        s_context->clearContext();
        //s_context->tmpOpType = ItmCode::OPR_ID;
        s_context->tmpIdenName = token;

        break;
    }
    case T_CTERMINATE_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST: {
        //std::cout << "walk in T_CTERMINATE_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CCLASSSF_CLASS_ID_IDLIST_CLASSDECTIONLIST", getLineno());

        s_context->clearContext();
        //s_context->tmpOpType = ItmCode::OPR_ID;
        s_context->tmpIdenName = token;
        break;
    }
    case T_CTERMINATE_CCLASSSF_CLASS_ID:{
        //std::cout << "walk in T_CTERMINATE_CCLASSSF_CLASS_ID" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CCLASSSF_CLASS_ID", getLineno());

        s_context->clearContext();
        //s_context->tmpOpType = ItmCode::OPR_ID;
        s_context->tmpIdenName = token;
        break;
    }

    //type_qualifier
    case T_CTERMINATE_CTYPEQF_CONST: {
        //std::cout << "walk in T_CTERMINATE_CTYPEQF_CONST" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CTYPEQF_CONST", getLineno());

        s_context->clearContext();
        s_context->tmpDeclType.setTypeQfType(TypeClass::QF_CONST);
        break;
    }
    case T_CTERMINATE_CTYPEQF_VOLATILE: {
        //std::cout << "walk in T_CTERMINATE_CTYPEQF_VOLATILE" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CTYPEQF_VOLATILE", getLineno());

        s_context->clearContext();
        s_context->tmpDeclType.setTypeQfType(TypeClass::QF_VOLATILE);

        break;
    }
    case T_CTERMINATE_CTYPEQF_VIRTUAL: {
        //std::cout << "walk in T_CTERMINATE_CTYPEQF_VIRTUAL" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CTYPEQF_VIRTUAL", getLineno());

        s_context->clearContext();
        s_context->tmpDeclType.setTypeQfType(TypeClass::QF_VIRTUAL);
        break;
    }

    //type_specifier
    case T_CTERMINATE_CTYPESF_VOID: {
        //std::cout << "walk in T_CTERMINATE_CTYPESF_VOID" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CTYPESF_VOID", getLineno());

        s_context->clearContext();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_VOID);
        break;
    }
    case T_CTERMINATE_CTYPESF_CHAR: {
        //std::cout << "walk in T_CTERMINATE_CTYPESF_CHAR" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CTYPESF_CHAR", getLineno());

        s_context->clearContext();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_CHAR);
        break;
    }
    case T_CTERMINATE_CTYPESF_SHORT: {
        //std::cout << "walk in T_CTERMINATE_CTYPESF_SHORT" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CTYPESF_SHORT", getLineno());

        s_context->clearContext();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_SHORT);
        break;
    }
    case T_CTERMINATE_CTYPESF_INT: {
        //std::cout << "walk in T_CTERMINATE_CTYPESF_INT" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CTYPESF_INT", getLineno());

        s_context->clearContext();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_INT);
        break;
    }
    case T_CTERMINATE_CTYPESF_LONG: {
        //std::cout << "walk in T_CTERMINATE_CTYPESF_LONG" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CTYPESF_LONG", getLineno());

        s_context->clearContext();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_LONG);
        break;
    }
    case T_CTERMINATE_CTYPESF_FLOAT: {
        //std::cout << "walk in T_CTERMINATE_CTYPESF_FLOAT" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CTYPESF_FLOAT", getLineno());

        s_context->clearContext();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_FLOAT);
        break;
    }
    case T_CTERMINATE_CTYPESF_DOUBLE: {
        //std::cout << "walk in T_CTERMINATE_CTYPESF_DOUBLE" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CTYPESF_DOUBLE", getLineno());

        s_context->clearContext();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_DOUBLE);
        break;
    }
    case T_CTERMINATE_CTYPESF_SIGNED: {
        //std::cout << "walk in T_CTERMINATE_CTYPESF_SIGNED" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CTYPESF_SIGNED", getLineno());

        s_context->clearContext();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_SIGNED);
        break;
    }
    case T_CTERMINATE_CTYPESF_UNSIGNED: {
        //std::cout << "walk in T_CTERMINATE_CTYPESF_UNSIGNED" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CTYPESF_UNSIGNED", getLineno());

        s_context->clearContext();
        s_context->tmpDeclType.setTypeSfType(TypeClass::SF_UNSIGNED);
        break;
    }

    //storage_class_specifier
    case T_CTERMINATE_CSTORCLASSSF_TYPEDEF: {
        //std::cout << "walk in T_CTERMINATE_CSTORCLASSSF_TYPEDEF" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CSTORCLASSSF_TYPEDEF", getLineno());

        break;
    }
    case T_CTERMINATE_CSTORCLASSSF_EXTERN: {
        //std::cout << "walk in T_CTERMINATE_CSTORCLASSSF_EXTERN" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CSTORCLASSSF_EXTERN", getLineno());

        s_context->clearContext();
        s_context->tmpDeclType.setStorageType(TypeClass::STOR_EXTERN);
        break;
    }
    case T_CTERMINATE_CSTORCLASSSF_STATIC: {
        //std::cout << "walk in T_CTERMINATE_CSTORCLASSSF_STATIC" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CSTORCLASSSF_STATIC", getLineno());

        s_context->clearContext();
        s_context->tmpDeclType.setStorageType(TypeClass::STOR_STATIC);
        break;
    }
    case T_CTERMINATE_CSTORCLASSSF_AUTO: {
        //std::cout << "walk in T_CTERMINATE_CSTORCLASSSF_AUTO" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CSTORCLASSSF_AUTO", getLineno());

        s_context->clearContext();
        s_context->tmpDeclType.setStorageType(TypeClass::STOR_AUTO);
        break;
    }
    case T_CTERMINATE_CSTORCLASSSF_REGISITER: {
        //std::cout << "walk in T_CTERMINATE_CSTORCLASSSF_REGISITER" << endl;
        LogiMsg::logi("walk in T_CTERMINATE_CSTORCLASSSF_REGISITER", getLineno());

        s_context->clearContext();
        s_context->tmpDeclType.setStorageType(TypeClass::STOR_REGISTER);
        break;
    }

    default: {
        //std::cout<<"error in TerminateAst: nodetype is invalid"<<std::endl;
        LogiMsg::logi("error in TerminateAst: nodetype is invalid", getLineno());

        break;
    }

    }


}




