#include <iostream>
using namespace std;

//register 关键字 请求编译器让变量a直接放在寄存器里面，速度快（在C中解释）早期 register int a = 0; 导致a不能直接取地址，因为a是寄存器不是地址
/*
*register关键字 在C++中
* 1.register关键字请求“编译器”将局部变量存储于寄存器中
*	c语言中无法取得register变量地址
*	在c++中依然支持register并可以取得变量地址 c++有自己的优化方式，不使用register也可能做优化 
* 2.c++编译器发现程序中需要取得register变量得地址时，register对变量的声明变得无效
* 3.早期c语言编译器不会对代码进行优化，因此register变量是一个很好的补充
*/

//变量检测增强
/*
*c++检测增强 禁止重定义 
*/

//struct类型加强
/*
*c语言中得struct定义了一组变量得集合，C编译器并不认为这是一种新类型
* 1.c++中的struct是一个新类型定义声明
* 2.struct 和 class关键字完成的功能是一样的
* 3.区别：
*/
struct Teacher
{
	char name[32];
	int age;
};

void main01()
{
	Teacher t1;
	t1.age = 10;
	printf("%d", t1.age);
}

//c++类型检查增强
/*
*1.c++中所有的变量和函数都必须有类型
*	void f(i)
*	{
*		printf("i = %d\n", i);
*	} 
* 在c中这段代码确实会执行，但会提示：type of ‘i’ defaults to ‘int’i的类型默认为 int
*	g( )
*	{
*		return 5;
*	}
* 在c语言main函数中掉g(1,2,3) 是可以的
* 而在C++进行了优化 规定：所有的变量和函数都必须有类型，c语言中的默认类型在c++中是不合法的，c++检查的更加严格
*/

//新增类型Bool类型
int main()
{
	bool b1 = true; //告诉c++编译器给我分配1个字节的内存，bool 要不是1要不是0 （true 和 false）
	cout << "sizeof(bool)" << sizeof(bool) << endl;
}

//接14
