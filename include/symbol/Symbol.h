#ifndef INCLUDE_SYMBOL_H
#define INCLUDE_SYMBOL_H

#include <vector>
#include <string>
#include <map>
using namespace std;
class Symbol{    //最基本的类,所有的符号和作用域都需要继承这个类
public:
	Symbol(string name);
	string getName();	
private:
	string name;
}

class Scope{   //作用域类,所有的作用域都需继承这个类
public:
	static Scope *head;            //指向作用域树的头
	static Scope *currentScope;   //指向当前作用域
	Symbol **resolve(string name);          //在当前及上层作用域中按名查找
	void def(Symbol * name);              //在当前域中定义符号
	Scope *getUpScop();          //得到上一层作用域
	void push(Scope *name);     //向下移动作用域
	void pop();              //向上移动作用域

private:
	map<string, Symbol **> dataDic;      //数据字典,存放当前作用域中的符号,为了方便修改所以为**
	Scope *upScop;       //上一个作用域

}

class Type:public Symbol{    //内置类以及用户定义类需要继承该类


}

class MethodDeclare:public Symbol{  //遇到函数声明时使用,不能算作scope
private:
	vector<Type *> argu;    //参数列表
} 

class MethodScop:public MethodDeclare, public Scope {   //遇到函数定义时使用

}

class ClassDeclare:public Type{   //遇到类的声明时用

}

class ClassScop:public ClassDeclare public Scope {   //遇到类的定义时用
public:
	Symbol **resolveMember(string name);   //只在继承链中解析,不在外围作用域中解析,用于解析成员变量
private:
	ClassScop *upClass;   //指向父类

}

class VariableSymbol: public Symbol{   //变量
private:
	Type * varType;    //变量类型
}

class BuiltInType: public Type{ //内置类型
	
}

//int 等数据类型全部继承BuiltInType


#endif
