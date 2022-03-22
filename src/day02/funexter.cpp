#include <iostream>
using namespace std;

/*
*	continue day_02 04
*	C++ 对c的函数扩展 inline 内联函数
*	c++中的const常量可以替代宏常数定义
*	const int A = 3;  ==>	#define A 3
*	c++中是否有解决方案替代宏代码片段那？（替代宏代码片段就能避免宏的副作用）
*	c++中推荐使用内联函数替代宏代码片段
*	c++中使用inline关键字声明内联函数
*	内联函数声明时inline关键字必须和关述定义结合在一起，否则编译器会直接忽略内联请求！
*	
* 
*/

#define MYFUNC(a, b) (((a)<(b))?(a):(b))
int main1()
{
	int c = 0, d = 0,a = 10 , b = 20;
	d = MYFUNC(600, 500);
	cout << d << endl;
	return 0;
}

/*
* 内联函数必须和实现体写在一块，内联函数最终生成的代码中是没有定义的
* c++编译器直接将函数体插入函数调用的地方，内联函数没有普通函数调用时
* 的额外开销(压栈，跳转，返回)，c++编译器不一定准许内联请求
* 现在c++编译器提供扩展语法，能够对函数进行强制内联
* 如：g++中的 __attribute__((always_inline))属性
*/