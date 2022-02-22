#include <iostream>
using namespace std;

//continue 18 引用 
/*
* 1. 引用的基础:可以媲美指针
* 
* 变量名回顾：
*	变量名实质上是内存（一段连续存储空间）的标号
* 问题1：对一段内存空间只能取一个别名嘛？答，未必，这个就可以用引用实现
* 
* 引用的概念：
*	a) 在c++中新增了引用的概念
*   b) 引用可以看做一个已定义变量的别名
*	c) 引用的语法： Type(类型)& name = var;
*	d) 引用做为函数参数那？（引用做为函数参数声明时不进行初始化）
*/

int  main91()
{
	int a = 10;
	int& b = a;		//引用案例，不能再用C语言的思考去思考这句话了
					/* 普通引用在声明时必须用其它变量进行初始化 */

	b = 100;		//相当于把a修改成员，c++检测到b是引用他就偷偷的这么做 *b = 100
	cout <<"a的值是：" << a << endl;
	cout <<"b的值是：" << b << endl;
	return 0;
}

//引用做函数参数：引用做函数参数时不用进行初始化
void myswap(int a, int b);
void mycppswap(int& a, int& b);
int main992()
{
	int x = 10;
	int y = 11;
	mycppswap(x, y);
	cout << "x = " << x << " y = " << y << endl;
}
//并不能实现，因为作用域不同，栈不同
void myswap(int a, int b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}
//此内容，用c++实现,交换成功，因为形参就是实参的别名，所以这样直接就把实参给改了
void mycppswap(int& a, int& b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}

//continue 19 引用 复杂数据类型引用做函数参数 