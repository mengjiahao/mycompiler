#include "../../include/symbol/Asm.h"

list<string> Asm::dataSectionList;
list<string> Asm::bssSectionList;
list<string> Asm::textSectionList;

/*ofstream Asm::dataSection;
ofstream Asm::bssSection;
ofstream Asm::textSection;*/

void Asm::addToDataSectionList(const string& a)
{
    dataSectionList.push_back(a);
}

void Asm::addToBssSectionList(const string& a)
{
    bssSectionList.push_back(a);
}

void Asm::addToTextSectionList(const string& a)
{
    textSectionList.push_back(a);
}



void Asm::printScopeAsm(Scope *scope_t)
{
    if (scope_t->scopeType == Scope::SCOPE_CLASS)
    {
        std::cout << "!!!!!!!!!!!!!1zhufanzhufan!!!!!!!!!!!!!!!!!" << std::endl;
        vector<Scope *>::iterator childItr;

        for (childItr=scope_t->childs.begin(); childItr!=scope_t->childs.end(); childItr++)
        {
            Asm::printScopeAsm(*childItr);
        }

    }
    else if (scope_t->scopeType == Scope::SCOPE_GLOBALFUNC)
    {
        //textSection << scope_t->getScopeName() << ":\n";
        string a = scope_t->getScopeName() + ":\n";
        addToTextSectionList(a);
        //addToTextSectionList("\tpushl $0\n");

        vector<Scope *>::iterator childItr;

        for (childItr=scope_t->childs.begin(); childItr!=scope_t->childs.end(); childItr++)
        {
            Asm::printScopeAsm(*childItr);
        }

        //textSection << "\tret\n";
        //addToTextSectionList("\taddl $4, %esp\n");
        addToTextSectionList("\tret\n");

    }
    else if (scope_t->scopeType == Scope::SCOPE_GLOBALFUNCCHAN)
    {
        //textSection << scope_t->getScopeName() << ":\n";
        string a = scope_t->getScopeName() + ":\n";
        addToTextSectionList(a);
        //addToTextSectionList("\tpushl $0\n");


        vector<Scope *>::iterator childItr;

        for (childItr=scope_t->childs.begin(); childItr!=scope_t->childs.end(); childItr++)
        {
            Asm::printScopeAsm(*childItr);
        }

        //textSection << "\tret\n";
       // addToTextSectionList("\taddl $4, %esp\n");
        addToTextSectionList("\tret\n");

    }
    else if (scope_t->scopeType == Scope::SCOPE_CLASSFUNC)
    {
        if (scope_t->parent == NULL)
        {
            LogiMsg::logi("error in printScopeAsm there is no class \n");
            //exit(0);
            return ;
        }

        //textSection << scope_t->superClass->getScopeName() << "_" << scope_t->getScopeName() << ":\n";
        string a = scope_t->parent->getScopeName() + "_" + scope_t->getScopeName() + ":\n";
        addToTextSectionList(a);
        //addToTextSectionList("\tpushl $0\n");

        vector<Scope *>::iterator childItr;

        for (childItr=scope_t->childs.begin(); childItr!=scope_t->childs.end(); childItr++)
        {
            Asm::printScopeAsm(*childItr);
        }

        //textSection << "\tret\n";
        //addToTextSectionList("\taddl $4, %esp\n");
        addToTextSectionList("\tret\n");

    }
    else if (scope_t->scopeType == Scope::SCOPE_LOCAL)
    {

        Asm::genFuncStart(scope_t);

        list<Symbol *>::iterator staItr;
        stringstream ss;

        for (staItr=scope_t->symbolSeqList.begin(); staItr!=scope_t->symbolSeqList.end(); staItr++ )
        {
            if ((*staItr)->typeClass.storageType & TypeClass::STOR_STATIC) {
                //bssSection << "\t.lcomm " << (*staItr)->getSymbolName() << ", " << (*staItr)->getByteSize() << "\n";
                string a;
                ss.clear();
                string b;
                ss << (*staItr)->getByteSize();
                ss >> b;
                a = "\t.lcomm " + (*staItr)->getSymbolName() + ", " + b + "\n";

                addToBssSectionList(a);

            }



        }

        vector<Scope *>::iterator childItr;
        vector<ItmCode *>::iterator codeItr;

        codeItr=scope_t->itemcodeVec.begin();
        for (childItr=scope_t->childs.begin(); childItr!=scope_t->childs.end(); childItr++)
        {
            while ((codeItr != scope_t->itemcodeVec.end()) && ((*codeItr)->getCodeId() <= (*childItr)->startCodeNo))
            {
                Asm::printExpAsm(*codeItr, scope_t);
                codeItr++;
            }
            Asm::printScopeAsm(*childItr);
        }

        while (codeItr != scope_t->itemcodeVec.end())
        {
            Asm::printExpAsm(*codeItr, scope_t);
            codeItr++;
        }



        Asm::genFuncEnd(scope_t);
    }
    else
    {

    }

}






void Asm::printAllAsm()
{
    /*dataSection << ".section .data\n";
    bssSection << ".section .bss\n";
    bssSection << "\t.lcomm .st0buff, 8\n\t.lcomm .st1buff, 8\n\t.lcomm .bxbuff, 4\n";
    textSection << ".section .text\n";
    textSection << ".global _start\n";
    textSection << "_start:\n";
    textSection << "\tnop\n";
    textSection << "\tfinit\n";*/
    addToDataSectionList(".section .data\n");
    addToBssSectionList(".section .bss\n");
    addToBssSectionList("\t.lcomm .st0buff, 8\n\t.lcomm .st1buff, 8\n\t.lcomm .bxbuff, 4\n");
    addToTextSectionList(".section .text\n");
    addToTextSectionList(".global _start\n");
    addToTextSectionList("_start:\n");
    addToTextSectionList("\tnop\n");
    addToTextSectionList("\tfinit\n");




    list<Symbol *>::iterator symItr;
    stringstream ss;

    for (symItr=Scope::s_globalScope->symbolSeqList.begin(); symItr!=Scope::s_globalScope->symbolSeqList.end(); symItr++)
    {
        //bssSection << "\t.lcomm " << (*symItr)->getSymbolName() << ", " << (*symItr)->getByteSize() << "\n";
        string a;
        ss.clear();
        string b;
        ss << (*symItr)->getByteSize();
        ss >> b;
        a = "\t.lcomm " + (*symItr)->getSymbolName() + ", " + b + "\n";

        addToBssSectionList(a);

    }

    map<string, Symbol *>::iterator constItr;

    for (constItr=Scope::s_constMap.begin(); constItr!=Scope::s_constMap.end(); constItr++)
    {
        if (constItr->second->symbolType==Symbol::SYMBOL_STRING_LITERAL)
        {
            if (constItr->second->symbolValue.size() != 1)
            {
                LogiMsg::logi("error in printAllAsm, the size of symbolvalue is not 1\n");
                //exit(0);
                return ;
            }
            /*dataSection << constItr->second->getSymbolName()
            << ":\n\t.asciz " << constItr->second->symbolValue.at(0) << "\n";*/
            string a = constItr->second->getSymbolName() + ":\n\t.asciz "
            + constItr->second->symbolValue.at(0) + "\n";

            addToDataSectionList(a);


        }
    }

    vector<ItmCode *>::iterator codeItr;

    for (codeItr=Scope::s_globalScope->itemcodeVec.begin(); codeItr!=Scope::s_globalScope->itemcodeVec.end(); codeItr++)
    {
        Asm::printExpAsm(*codeItr, Scope::s_globalScope);
    }


    /*textSection << "\tcall main\n";
    textSection << "\tpush %eax\n";
    textSection << "\tcall exit\n";*/
    addToTextSectionList("\tcall main\n");
    addToTextSectionList("\tpushl %eax\n");
    addToTextSectionList("\tcall exit\n");


    vector<Scope *>::iterator childItr;

    for (childItr=Scope::s_globalScope->childs.begin(); childItr!=Scope::s_globalScope->childs.end(); childItr++)
    {
        Asm::printScopeAsm(*childItr);
    }

 /*   string text;
    string bss;
    string data;
    textSection >> text;
    bssSection >>bss;
    dataSection >>data;

    if (ofs_t.is_open())
    {
        ofs_t << bss;
        ofs_t << data ;
        ofs_t << text ;
    }*/



}



void Asm::printExpAsm(ItmCode *code_t ,Scope *scope_t)
{
    addToTextSectionList("#***************************************#\n");

    switch (code_t->iRType){
        case ItmCode::IR_INVALID:{
            LogiMsg::logi("error in printExpAsm the code is invalid");
            //exit(0);
            return ;
            break;
        }
        case ItmCode::IR_PUSHVAR:{

            break;
        }
        case ItmCode::IR_POPVAR:{

            break;
        }
        case ItmCode::IR_MOVVAR:{

            break;
        }
        case ItmCode::IR_EMITVAR:{

            break;
        }
        case ItmCode::IR_EMITCLASSMEMVAR:{

            break;
        }
        case ItmCode::IR_EMITCLASS:{

            break;
        }
        case ItmCode::IR_EMITCLASSFUNC:{

            break;
        }
        case ItmCode::IR_EMITFUNC:{

            break;
        }
        case ItmCode::IR_EMITLABEL:{

            if (code_t->t3 != ItmCode::OPR_SYMBOL)
            {
                LogiMsg::logi("error in IR_EMITLABEL\n");
                //exit(0);
                return ;
            }
            string tmp=Asm::genSymbol(code_t->v3, scope_t);
            //textSection << tmp  << ":\n";
            string a = tmp + ":\n";
            addToTextSectionList(a);

            break;
        }
        case ItmCode::IR_CALLFUNC:{

            if (code_t->t1 != ItmCode::OPR_SCOPE)
            {
                LogiMsg::logi("error in IR_CALLFUNC\n");
                //exit(0);
                return ;
            }

            int byteSize=0;
            if (code_t->t2 == ItmCode::OPR_ARGLIST)
            {
                byteSize = Asm::genPushArgu(code_t->v2, false, scope_t, "");
            }

            /*textSection << "\tmovl %ebx, .bxbuff\n";
            textSection << "\tcall " << ((Scope *)(code_t->v1))->getScopeName() << "\n";*/
            addToTextSectionList("\tmovl %ebx, .bxbuff\n");
            string a = "\tcall " + ((Scope *)(code_t->v1))->getScopeName() + "\n";
            addToTextSectionList(a);


            if (code_t->t2 == ItmCode::OPR_ARGLIST)
            {
                //textSection << "\taddl $" << byteSize << ", %esp\n";
                string a;
                stringstream ss;
                string b;
                ss << byteSize;
                ss >> b;
                a = "\taddl $" + b + ", %esp\n";

                addToTextSectionList(a);

            }

            //textSection << "\tmovl .bxbuff, %ebx\n";
            addToTextSectionList("\tmovl .bxbuff, %ebx\n");

            break;
        }
        case ItmCode::IR_CALLCLASSFUNC:{


            int byteSize=0;
            string tmpThis;
            if (code_t->t1 == ItmCode::OPR_SCOPE)
            {
                tmpThis = "8(%ebp)";
            }
            else if ((code_t->t1 == ItmCode::OPR_CLASS_REFLIST)
                || (code_t->t1 == ItmCode::OPR_CLASS_REFLIST_POINTER))
            {
                vector<void* >* refList_t = ( vector<void* >*)(code_t->v1);
                if (refList_t->size()!=2)
                {
                    LogiMsg::logi("error in IR_CALLCLASSFUNC\n");
                    //exit(0);
                    return ;
                }
                tmpThis = Asm::genSymbol(refList_t->at(0), scope_t);
            }

            if (code_t->t2 == ItmCode::OPR_ARGLIST)
            {
                byteSize = Asm::genPushArgu(code_t->v2, true, scope_t, tmpThis);
            }
            else
            {
                string a = "\tpushl " + tmpThis + "\n";
                addToTextSectionList(a);
                byteSize=4;
            }

            /*textSection << "\tmovl %ebx, .bxbuff\n";
            textSection << "\tmovl " << tmpThis << ", %ecx\n";*/
            addToTextSectionList("\tmovl %ebx, .bxbuff\n");
            string a = "\tmovl " + tmpThis + ", %ecx\n";
            addToTextSectionList(a);

            int offset=0;

            if (code_t->t1 == ItmCode::OPR_SCOPE)
            {
                offset = ((Scope *)(code_t->v1))->funcOffset;
            }
            else if ((code_t->t1 == ItmCode::OPR_CLASS_REFLIST)
                || (code_t->t1 == ItmCode::OPR_CLASS_REFLIST_POINTER))
            {
                vector<void* >* refList_t = ( vector<void* >*)(code_t->v1);
                if (refList_t->size()!=2)
                {
                    LogiMsg::logi("error in IR_CALLCLASSFUNC\n");
                    //exit(0);
                    return ;
                }
                offset = ((Scope *)(refList_t->at(1)))->funcOffset+((Scope *)(refList_t->at(1)))->parent->totalByteSize;
            }

            //textSection << "\tcall *" << offset << "(%ecx)\n";
            stringstream ss;
            string b;
            ss << offset;
            ss >> b;
            a = "\tcall *" + b + "(%ecx)\n";
            addToTextSectionList(a);




                //textSection << "\taddl $" << byteSize << ", %esp\n";
                //string a;
                a="";
                ss.clear();
                b="";
                ss << byteSize;
                ss >> b;
                a = "\taddl $" + b + ", %esp\n";
                addToTextSectionList(a);


            //textSection << "\tmovl .bxbuff, %ebx\n";
            addToTextSectionList("\tmovl .bxbuff, %ebx\n");

            break;
        }
        case ItmCode::IR_FETCHARRAY:{

            break;
        }
        case ItmCode::IR_NEW_OP:{

            if (code_t->t1 != ItmCode::OPR_SCOPE)
            {
                LogiMsg::logi("error in IR_NEW_OP \n");
                //exit(0);
                return ;
            }
            Scope *tmpScope = (Scope *)(code_t->v1);

            /*textSection << "\tpushl $" << tmpScope->totalByteSize+tmpScope->totalFuncByteSize << "\n";
            textSection << "\tcall malloc\n";
            textSection << "\taddl $4, %esp\n";*/
            string a;
            stringstream ss;
            string b;
            ss << tmpScope->totalByteSize+tmpScope->totalFuncByteSize;
            ss >> b;
            a = "\tpushl $" + b + "\n";
            addToTextSectionList(a);
            addToTextSectionList("\tcall malloc\n");
            addToTextSectionList("\taddl $4, %esp\n");


            for (int i=0; i < tmpScope->totalFuncByteSize; i+=4)
            {
                Scope *tmpMemFunc = tmpScope->resolveMemFunByOffset(i);
                if (tmpMemFunc)
                {
                    /*textSection << "\tmovl $" << tmpScope->getScopeName() << "_"
                    << tmpMemFunc->getScopeName() << ", " << i+tmpScope->totalByteSize << "(%eax) \n";*/
                    string a;
                    ss.clear();
                    string b;
                    ss << i+tmpScope->totalByteSize;
                    ss >> b;
                    a = "\tmovl $" + tmpMemFunc->className + "_"
                    + tmpMemFunc->getScopeName() + ", " + b + "(%eax) \n";
                    addToTextSectionList(a);

                }
            }


            break;
        }
        case ItmCode::IR_DELETE_OP:{

            if (code_t->t1 != ItmCode::OPR_SYMBOL)
            {
                LogiMsg::logi("error in IR_DELETE_OP\n");
                //exit(0);
                return ;
            }
            string tmp = Asm::genSymbol(code_t->v1, scope_t);

            /*textSection << "\tpushl " << tmp << "\n";
            textSection << "\tcall free\n";
            textSection << "\taddl $4, %esp\n";*/
            string a = "\tpushl " + tmp + "\n";
            addToTextSectionList(a);
            addToTextSectionList("\tcall free\n");
            addToTextSectionList("\taddl $4, %esp\n");


            break;
        }
        case ItmCode::IR_ASSIGN_OP:{

            switch (code_t->t3){
                case ItmCode::OPR_REGISTER:{

                    if (code_t->t1 == ItmCode::OPR_SYMBOL)
                    {
                        string tmp = Asm::genSymbol(code_t->v1, scope_t);
                        Asm::genMovToReg( ((Reg *)(code_t->v3))->regIndex,  ((Reg *)(code_t->v3))->typeSfType, tmp);

                    }
                    else if (code_t->t1 == ItmCode::OPR_CLASS_REFLIST || code_t->t1 == ItmCode::OPR_CLASS_REFLIST_POINTER)
                    {

                        string tmp= Asm::genRefList(code_t->v1, scope_t);
                        Asm::genMovToReg( ((Reg *)(code_t->v3))->regIndex,  ((Reg *)(code_t->v3))->typeSfType, tmp);
                    }
                    else if (code_t->t1 == ItmCode::OPR_REGISTER)
                    {
                        string opr;
                        opr=Asm::genReg(((Reg *)(code_t->v1))->regIndex, ((Reg *)(code_t->v1))->typeSfType);
                         Asm::genMovToReg( ((Reg *)(code_t->v3))->regIndex,  ((Reg *)(code_t->v3))->typeSfType, opr);
                    }

                    break;
                }
                case ItmCode::OPR_SYMBOL:{
                    if (code_t->t1 != ItmCode::OPR_REGISTER)
                    {
                        LogiMsg::logi("error in IR_ASSIGN_OP ItmCode::OPR_SYMBOL\n");
                        //exit(0);
                        return ;
                    }
                    string tmp;
                    tmp=Asm::genSymbol(code_t->v3, scope_t);
                    int otherType;

                    otherType=((Symbol *)(code_t->v3))->typeClass.typeSfType;

                    Asm::genRegMovTo(((Reg *)(code_t->v1))->regIndex, ((Reg *)(code_t->v1))->typeSfType, otherType, tmp);

                    break;
                }
                case ItmCode::OPR_CLASS_REFLIST:
                case ItmCode::OPR_CLASS_REFLIST_POINTER:{
                    if (code_t->t1 != ItmCode::OPR_REGISTER)
                    {
                        LogiMsg::logi("error in IR_ASSIGN_OP OPR_CLASS_REFLIST_POINTER\n");
                        //exit(0);
                        return ;
                    }
                    string tmp;
                    vector<void* >* listTmp = (vector<void* >*)(code_t->v3);

                    tmp=Asm::genRefList(code_t->v3, scope_t);
                    int otherType;

                    otherType=((Symbol *)(listTmp->at(1)))->typeClass.typeSfType;

                    Asm::genRegMovTo(((Reg *)(code_t->v1))->regIndex, ((Reg *)(code_t->v1))->typeSfType, otherType, tmp);

                    break;
                }
                default:{
                }
            }

            break;
        }
        case ItmCode::IR_MUL_ASSIGN:{

            break;
        }
        case ItmCode::IR_DIV_ASSIGN:{

            break;
        }
        case ItmCode::IR_MOD_ASSIGN:{

            break;
        }
        case ItmCode::IR_ADD_ASSIGN:{

            break;
        }
        case ItmCode::IR_SUB_ASSIGN:{

            break;
        }
        case ItmCode::IR_LEFT_ASSIGN:{

            break;
        }
        case ItmCode::IR_RIGHT_ASSIGN:{

            break;
        }
        case ItmCode::IR_AND_ASSIGN:{

            break;
        }
        case ItmCode::IR_XOR_ASSIGN:{

            break;
        }
        case ItmCode::IR_OR_ASSIGN:{

            break;
        }
        case ItmCode::IR_REG_ISTRUE_ASSIGN:{

            break;
        }
        case ItmCode::IR_LOG_OR_OP:{

            break;
        }
        case ItmCode::IR_LOG_AND_OP:{

            break;
        }
        case ItmCode::IR_EQ_OP:{

            Asm::genJum("jz", code_t);

            break;
        }
        case ItmCode::IR_NE_OP:{


            Asm::genJum("jnz", code_t);


            break;
        }
        case ItmCode::IR_L_OP:{

            Asm::genJum("jl", code_t);

            break;
        }
        case ItmCode::IR_G_OP:{

            Asm::genJum("jg", code_t);

            break;
        }
        case ItmCode::IR_LE_OP:{

            Asm::genJum("jle", code_t);

            break;
        }
        case ItmCode::IR_GE_OP:{

            Asm::genJum("jge", code_t);

            break;
        }
        case ItmCode::IR_LEFT_OP:{

            break;
        }
        case ItmCode::IR_RIGHT_OP:{

            break;
        }
        case ItmCode::IR_ADD_OP:{

            if ((((Reg *)(code_t->v3))->typeSfType == TypeClass::SF_FLOAT) ||
                (((Reg *)(code_t->v3))->typeSfType == TypeClass::SF_DOUBLE))
            {
                Asm::genFLoatOpe("fadd", code_t->v1, code_t->v2, code_t->v3);

            }
            else
            {
                Asm::genIntOpe("addl", code_t->v1, code_t->v2, code_t->v3);

            }



            break;
        }
        case ItmCode::IR_SUB_OP:{
            if ((((Reg *)(code_t->v3))->typeSfType == TypeClass::SF_FLOAT) ||
                (((Reg *)(code_t->v3))->typeSfType == TypeClass::SF_DOUBLE))
            {

            }
            else
            {
                Asm::genIntOpe("subl", code_t->v1, code_t->v2, code_t->v3);
            }


            break;
        }
        case ItmCode::IR_MUL_OP:{
            if ((((Reg *)(code_t->v3))->typeSfType == TypeClass::SF_FLOAT) ||
                (((Reg *)(code_t->v3))->typeSfType == TypeClass::SF_DOUBLE))
            {
                Asm::genFLoatOpe("fmul", code_t->v1, code_t->v2, code_t->v3);


            }
            else
            {

                Asm::genIntOpe("imull", code_t->v1, code_t->v2, code_t->v3);

            }


            break;
        }
        case ItmCode::IR_DIV_OP:{
            if ((((Reg *)(code_t->v3))->typeSfType == TypeClass::SF_FLOAT) ||
                (((Reg *)(code_t->v3))->typeSfType == TypeClass::SF_DOUBLE))
            {

            }
            else
            {

                /*textSection << "\tmovl %ebx, %ecx\n";
                textSection << "\tmovl %eax, %ebx\n";
                textSection << "\tmovl %ecx, %eax\n";
                textSection << "\tmovl $0, %edx\n";
                textSection << "\tidivl %ebx\n";*/
                addToTextSectionList("\tmovl %ebx, %ecx\n");
                addToTextSectionList("\tmovl %eax, %ebx\n");
                addToTextSectionList("\tmovl %ecx, %eax\n");
                addToTextSectionList("\tmovl $0, %edx\n");
                addToTextSectionList("\tidivl %ebx\n");
            }

            break;
        }
        case ItmCode::IR_MOD_OP:{

            break;
        }
        case ItmCode::IR_INC_OP:{

            break;
        }
        case ItmCode::IR_DEC_OP:{

            break;
        }
        case ItmCode::IR_SIZEOF:{

            break;
        }
        case ItmCode::IR_INC_OP_POST:{

            break;
        }
        case ItmCode::IR_DEC_OP_POST:{

            break;
        }
        case ItmCode::IR_UAND_OP:{

            break;
        }
        case ItmCode::IR_UREF_OP:{

            break;
        }
        case ItmCode::IR_UADD_OP:{

            break;
        }
        case ItmCode::IR_USUB_OP:{

            break;
        }
        case ItmCode::IR_UCOMP_OP:{

            break;
        }
        case ItmCode::IR_UNOT_OP:{

            break;
        }
        case ItmCode::IR_GOTO:{

            if (code_t->t3 != ItmCode::OPR_SYMBOL)
            {
                LogiMsg::logi("error in IR_GOTO\n");
                //exit(0);
                return ;
            }
            string tmp =genSymbol(code_t->v3, scope_t);
            //textSection << "\tjmp " << tmp << "\n";
            string a = "\tjmp " + tmp + "\n";
            addToTextSectionList(a);


            break;
        }
        case ItmCode::IR_IF_GOTO:{

            string tmpReg =Asm::genReg(((Reg *)(code_t->v1))->regIndex, TypeClass::SF_INT);
            string tmp = genSymbol(code_t->v3, scope_t);

            /*textSection << "\tcmp " <<"$0"<< ", " <<tmpReg  << "\n";
            textSection << "\tjnz " << tmp  << "\n";*/
            string a = "\tcmp $0, " + tmpReg  + "\n";
            addToTextSectionList(a);
            a = "\tjnz " + tmp + "\n";
            addToTextSectionList(a);

            break;
        }
        case ItmCode::IR_IF_NOT_GOTO:{
            string tmpReg =Asm::genReg(((Reg *)(code_t->v1))->regIndex, TypeClass::SF_INT);
            string tmp = genSymbol(code_t->v3, scope_t);

            /*textSection << "\tcmp " <<"$0"<< ", " <<tmpReg  << "\n";
            textSection << "\tjz " << tmp << "\n";*/
            string a = "\tcmp $0, " + tmpReg  + "\n";
            addToTextSectionList(a);
            a = "\tjz " + tmp + "\n";
            addToTextSectionList(a);

            break;
        }
        case ItmCode::IR_RETURN_VOID:{

            Asm::genFuncEnd(scope_t);

            //textSection << "\tret\n";
           // addToTextSectionList("\taddl $4, %esp\n");
            addToTextSectionList("\tret\n");

            break;
        }
        case ItmCode::IR_RETURN_REG:{

            Asm::genFuncEnd(scope_t);

            string tmpReg =Asm::genReg(((Reg *)(code_t->v3))->regIndex, TypeClass::SF_INT);
            //textSection <<  "\tmovl " << tmpReg << ", %eax\n";
            string a = "\tmovl " + tmpReg + ", %eax\n";
            addToTextSectionList(a);

           // Asm::genFuncEnd(scope_t);

            //textSection << "\tret\n";
           // addToTextSectionList("\taddl $4, %esp\n");
            addToTextSectionList("\tret\n");

            break;
        }


    }



}

string Asm::genSymbol(void *v1, Scope *scope_t)
{
    Symbol *symbol_t = (Symbol *)v1;
    string symStr;

    switch (symbol_t->symbolType){
        case Symbol::SYMBOL_INTEGER_CONSTANT:
        case Symbol::SYMBOL_CHARACTER_CONSTANT:
        case Symbol::SYMBOL_FLOATING_CONSTANT:{

            if (symbol_t->symbolValue.size() != 1 )
            {
                LogiMsg::logi("error in genSymbol\n");
                //exit(0);
                return "";
            }

            symStr ="$";
            symStr += symbol_t->symbolValue.at(0);

            break;

        }
        case Symbol::SYMBOL_STRING_LITERAL:{

            symStr ="$";
            symStr += symbol_t->getSymbolName();
            break;
        }

        case Symbol::SYMBOL_VAR:

        case Symbol::SYMBOL_CLASSREFVAR:

        case Symbol::SYMBOL_CONSTANTVAR:{

            if (symbol_t->typeClass.storageType & TypeClass::STOR_STATIC)
            {
                symStr = symbol_t->getSymbolName();

            }
            else if (symbol_t->isglobal)
            {
                symStr = symbol_t->getSymbolName();

            }
            else
            {
                stringstream ss;
                ss << scope_t->curStartOffset-symbol_t->offset << "(%ebp)";
                ss >> symStr;
            }

            break;
        }

        case Symbol::SYMBOL_TEMPVAR:{

            stringstream ss;
            ss << scope_t->curStartOffset-symbol_t->offset << "(%ebp)";
            ss >> symStr;

            break;
        }

        case Symbol::SYMBOL_CLASSMEMVAR:{

            //textSection << "\tmovl 8(%ebp), %ecx\n";
            addToTextSectionList("\tmovl 8(%ebp), %ecx\n");

            stringstream ss;
            ss << symbol_t->getOffset() << "(%ecx)" ;
            ss >> symStr;


            break;
        }
        case Symbol::SYMBOL_LABEL:{

            symStr = symbol_t->getSymbolName();

            break;
        }
        default:{
            LogiMsg::logi("error in genSymbol\n");
            //exit(0);
            return "";
        }


    }

    return symStr;
}

string Asm::genRefList(void *v1, Scope *scope_t)
{

    vector<void* >* refList_t = ( vector<void* >*)v1;
    if (refList_t->size()!=2)
    {
        LogiMsg::logi("error in genRefList\n");
        //exit(0);
        return "";
    }

    string tmp = Asm::genSymbol(refList_t->at(0), scope_t);

    //textSection << "\tmovl " << tmp << ", %ecx\n";
    string a = "\tmovl " + tmp + ", %ecx\n";
    addToTextSectionList(a);

    stringstream ss;
    ss << ((Symbol *)(refList_t->at(1)))->getOffset() << "(%ecx)";
    ss >> tmp;
    return tmp;
}




void Asm::genMovToReg(int reg_t, int type_t, string opr)
{
    if (type_t & TypeClass::SF_FLOAT)
    {
        //textSection << "\tflds " << opr <<"\n";
        string a = "\tflds " + opr + "\n";
        addToTextSectionList(a);

    }
    else if (type_t & TypeClass::SF_DOUBLE)
    {
        //textSection << "\tfldl " << opr <<"\n";
        string a = "\tfldl " + opr + "\n";
        addToTextSectionList(a);
    }
    else
    {
        string regTmp;
        string movTmp;
        if (type_t & TypeClass::SF_CHAR)
        {
            if (reg_t == 0)
            {
                //textSection << "\tmovl $0, %eax\n";
                addToTextSectionList("\tmovl $0, %eax\n");
                regTmp = "%al";
            }
            else if (reg_t == 1)
            {
                //textSection << "\tmovl $0, %ebx\n";
                addToTextSectionList("\tmovl $0, %ebx\n");
                regTmp = "%bl";
            }
            movTmp = "movb";

        }
        else if (type_t & TypeClass::SF_INT)
        {
            if (reg_t == 0)
            {
                regTmp = "%eax";
            }
            else if (reg_t == 1)
            {
                regTmp = "%ebx";
            }
            movTmp = "movl";
        }

        //textSection << "\t" << movTmp << " " << opr << ", " << regTmp <<"\n";
        string a = "\t" + movTmp + " " + opr + ", " + regTmp + "\n";
        addToTextSectionList(a);
    }
}

void Asm::genRegMovTo(int reg_t, int regtype_t, int othertype_t, string opr)
{
    if ((regtype_t & TypeClass::SF_FLOAT)  ||  (regtype_t & TypeClass::SF_DOUBLE))
    {
        if (othertype_t & TypeClass::SF_FLOAT)
        {
            //textSection << "\tfsts " << opr <<"\n";
            string a = "\tfsts " + opr + "\n";
            addToTextSectionList(a);
        }
        else if (othertype_t & TypeClass::SF_DOUBLE)
        {
            //textSection << "\tfstl " << opr <<"\n";
            string a = "\tfstl " + opr + "\n";
            addToTextSectionList(a);
        }
        else if ((othertype_t & TypeClass::SF_INT))
        {
            if (regtype_t & TypeClass::SF_FLOAT)
            {
                //textSection << "\tfists " << opr <<"\n";
                string a = "\tfists " + opr + "\n";
                addToTextSectionList(a);
            }
            else
            {
                //textSection << "\tfistl " << opr <<"\n";
                string a = "\tfistl " + opr + "\n";
                addToTextSectionList(a);
            }
        }
    }
    else if (regtype_t & TypeClass::SF_CHAR)
    {
        if ((othertype_t &  TypeClass::SF_CHAR) || (othertype_t &  TypeClass::SF_INT))
        {

            string tmpReg;
            string tmpMov;
            tmpReg = Asm::genReg(reg_t, othertype_t);
            tmpMov = Asm::genMov(othertype_t);

            //textSection << "\t" << tmpMov << " " << tmpReg << ", " << opr <<"\n";
            string a = "\t" + tmpMov + " " + tmpReg + ", " + opr + "\n";
            addToTextSectionList(a);
        }


    }
    else if (regtype_t & TypeClass::SF_INT)
    {
        if ((othertype_t &  TypeClass::SF_CHAR) || (othertype_t &  TypeClass::SF_INT))
        {

            string tmpReg;
            string tmpMov;
            tmpReg = Asm::genReg(reg_t, othertype_t);
            tmpMov = Asm::genMov(othertype_t);
            //textSection << "\t" << tmpMov << " " << tmpReg << ", " << opr <<"\n";
            string a = "\t" + tmpMov + " " + tmpReg + ", " + opr + "\n";
            addToTextSectionList(a);
        }
        else if (othertype_t & TypeClass::SF_FLOAT)
        {
            string tmpReg;
            tmpReg = Asm::genReg(reg_t, regtype_t);
            //textSection << "\tfilds " << tmpReg << "\n";
            //textSection << "\tfsts " << opr << "\n";
            string a = "\tfilds " + tmpReg + "\n";
            addToTextSectionList(a);
            a = "\tfsts " + opr + "\n";
            addToTextSectionList(a);
        }
        else if (othertype_t & TypeClass::SF_DOUBLE)
        {
            string tmpReg;
            tmpReg = Asm::genReg(reg_t, regtype_t);
            //textSection << "\tfildl " << tmpReg << "\n";
            //textSection << "\tfstl " << opr << "\n";
            string a = "\tfildl " + tmpReg + "\n";
            addToTextSectionList(a);
            a = "\tfstl " + opr + "\n";
            addToTextSectionList(a);
        }
    }

}

string Asm::genReg(int reg_t, int type_t)
{
    string tmp;
    if (type_t & TypeClass::SF_CHAR)
    {
        if (reg_t == 0)
            tmp="%al";
        else if (reg_t == 1)
            tmp="%bl";
    }
    else if (type_t & TypeClass::SF_INT)
    {
        if (reg_t==0)
            tmp="%eax";
        else if (reg_t ==1)
            tmp="%ebx";
    }
    return tmp;
}


void Asm::genFuncStart(Scope *scope_t)
{

    //textSection << "\tpushl %ebp\n";
    //textSection << "\tmovl %esp, %ebp\n";
    //textSection << "\tsubl $" << scope_t->totalByteSize-scope_t->curStartOffset << ", %esp\n";
    addToTextSectionList("\tpushl %ebp\n");
    addToTextSectionList("\tmovl %esp, %ebp\n");
    string a;
    stringstream ss;
    string b;
    ss << scope_t->totalByteSize-scope_t->curStartOffset;
    ss >> b;
    a = "\tsubl $" + b + ", %esp\n";
    addToTextSectionList(a);
}

void Asm::genFuncEnd(Scope *scope_t)
{
    /*textSection << "\tmovl %ebp, %esp\n";
    textSection << "\tpopl %ebp\n";*/
    addToTextSectionList("\tmovl %ebp, %esp\n");
    addToTextSectionList("\tpopl %ebp\n");
   // addToTextSectionList("\tsubl $4, %esp\n");
}

string Asm::genMov(int type_t)
{
    string tmp;
    if (type_t & TypeClass::SF_CHAR)
    {
        tmp="movb";
    }
    else if (type_t & TypeClass::SF_INT)
    {
        tmp="movl";
    }
    return tmp;
}


int Asm::genPushArgu(void *v1, bool isthis, Scope *scope_t, string thisstr)
{
    vector<void* >* arguList = (vector<void* >*)(v1);
    vector<void *>::reverse_iterator r_itr;
    int byteSize=0;
    for (r_itr = arguList->rbegin(); r_itr != arguList->rend(); r_itr++)
    {
        string tmp = Asm::genSymbol(*r_itr, scope_t);

        switch (((Symbol *)(*r_itr))->getByteSize()){
            case 1:{
                //textSection << "\tpushb " << tmp << "\n";
                string a = "\tpush " + tmp + "\n";
                addToTextSectionList(a);
                byteSize+=1;

                break;
            }
            case 2:{
                //textSection << "\tpushw " << tmp << "\n";
                string a = "\tpushw " + tmp + "\n";
                addToTextSectionList(a);
                byteSize+=2;

                break;
            }
            case 4:{
                //textSection << "\tpushl " << tmp << "\n";
                string a = "\tpushl " + tmp + "\n";
                addToTextSectionList(a);
                byteSize+=4;
                break;
            }
            case 8:{
                //textSection << "\tpushl " << 4+scope_t->curStartOffset-((Symbol *)(*r_itr))->offset << "(%ebp)\n";
                //textSection << "\tpushl " << tmp << "\n";
                string a;
                stringstream ss;
                string b;
                ss << 4 + scope_t->curStartOffset-((Symbol *)(*r_itr))->offset;
                ss >> b;
                a = "\tpushl " + b + "(%ebp)\n";
                addToTextSectionList(a);
                a = "\tpushl " + tmp + "\n";
                addToTextSectionList(a);

                byteSize += 8;

                break;
            }
        }


    }
    if (isthis)
    {
        //textSection << "\tpushl " << thisstr << "\n";
        string a = "\tpushl " + thisstr + "\n";
        addToTextSectionList(a);

        byteSize+=4;
    }
    return byteSize;

}

void Asm::genJum(string jmp_t, ItmCode *code_t)
{
    static int tmpSymbol=0;
    string r1;
    string r2;
    string r3;
    r1=Asm::genReg(((Reg *)(code_t->v1))->regIndex, TypeClass::SF_INT);
    r2=Asm::genReg(((Reg *)(code_t->v2))->regIndex, TypeClass::SF_INT);
    r3=Asm::genReg(((Reg *)(code_t->v3))->regIndex, TypeClass::SF_INT);

    /*textSection << "\tmovl $1, " << r3 << "\n";
    textSection << "\tcmp " << r1 << ", " << r2 << "\n";
    textSection << "\t" << jmp_t << " .TM" <<tmpSymbol << "\n";
    textSection << "\tmovl $0, " << r3 << "\n";
    textSection << ".TM" << tmpSymbol << ":\n";*/
    //string a = "\tmovl $1, " + r3 + "\n";
    //addToTextSectionList(a);
    string a = "\tcmp " + r2 + ", " + r1 + "\n";
    addToTextSectionList(a);
    stringstream ss;
    string b;
    ss << tmpSymbol;
    ss >> b;
    a = "\t" + jmp_t + " .T" + b + "\n";
    tmpSymbol++;
    addToTextSectionList(a);
    a = "\tmovl $0, " + r3 + "\n";
    addToTextSectionList(a);
    b="";
    ss.clear();
    ss << tmpSymbol;
    ss >> b;
    a = "\tjmp .T" + b + "\n";
    addToTextSectionList(a);
    tmpSymbol++;
    b="";
    ss.clear();
    ss << tmpSymbol-2;
    ss >> b;
    a = ".T" + b + ":\n";
    addToTextSectionList(a);
    a = "\tmovl $1, " + r3 + "\n";
    addToTextSectionList(a);
    b="";
    ss.clear();
    ss << tmpSymbol-1;
    ss >> b;
    a = ".T" + b + ":\n";
    addToTextSectionList(a);


}

void Asm::genFLoatOpe(string ope_t, void *v1, void *v2, void *v3)
{
    if ((((Reg *)(v1))->typeSfType != TypeClass::SF_FLOAT) &&
        (((Reg *)(v1))->typeSfType != TypeClass::SF_DOUBLE))
    {
        string tmp = Asm::genReg(((Reg *)(v1))->regIndex, TypeClass::SF_INT);
        //textSection << "\tfilds " << tmp << "\n";
        string a = "\tfilds " + tmp + "\n";
        addToTextSectionList(a);
    }
    if ((((Reg *)(v2))->typeSfType != TypeClass::SF_FLOAT) &&
        (((Reg *)(v2))->typeSfType != TypeClass::SF_DOUBLE))
    {
        string tmp = Asm::genReg(((Reg *)(v2))->regIndex, TypeClass::SF_INT);
        //textSection << "\tfilds " << tmp << "\n";
        string a = "\tfilds " + tmp + "\n";
        addToTextSectionList(a);
    }

    //textSection << "\t" << ope_t <<" %st(1), %st(0)\n";
    string a = "\t" + ope_t + " %st(1), %st(0)\n";
    addToTextSectionList(a);
}


void Asm::genIntOpe(string ope_t, void *v1, void *v2, void *v3)
{
    string r1;
    string r2;
    string r3;
    r1=Asm::genReg(((Reg *)(v1))->regIndex, TypeClass::SF_INT);
    r2=Asm::genReg(((Reg *)(v2))->regIndex, TypeClass::SF_INT);
    r3=Asm::genReg(((Reg *)(v3))->regIndex, TypeClass::SF_INT);

    //textSection << ope_t << " " << r2 << ", " << r1 <<"\n";
    //textSection << "movl " << r1 << ", " << r3 <<"\n";
    string a = ope_t + " " + r2 + ", " + r1 + "\n";
    addToTextSectionList(a);
    a = "movl " + r1 + ", " + r3 + "\n";
    addToTextSectionList(a);

}


void Asm::printAsm()
{

    /*cout << ">>>printScopeTree in SymbolTable.txt" << endl;*/
    LogiMsg::logi(">>>printAsm in out.s");

    /*textSection.open("out1.s");
    dataSection.open("out2.s");
    bssSection.open("out3.s");*/
    ofstream ofs;
    ofs.open("out.s");

    if (ofs.is_open()) {

        printAllAsm();

        list<string>::iterator itr;

        for(itr = dataSectionList.begin(); dataSectionList.end() != itr; ++itr) {
            ofs << *itr;
        }
        for(itr = bssSectionList.begin(); bssSectionList.end() != itr; ++itr) {
            ofs << *itr;
        }
        for(itr = textSectionList.begin(); textSectionList.end() != itr; ++itr) {
            ofs << *itr;
        }

        ofs.close();


    } else {
        LogiMsg::logi("error in Asm::printAsm(): cannot open out.s");
    }

    /*bssSection << dataSection.rdbuf();
    textSection << bssSection.rdbuf();
    textSection.close();
    dataSection.close();
    bssSection.close();*/


}
