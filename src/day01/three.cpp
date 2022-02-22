#include <iostream>
using namespace std;
//continue 15
//1.在C语言中表达式的结果放在什么地方？寄存器中，所以表达式的返回值是一个数(一个值) (a < b ? a:b) = 30; C中形态(10 = 30)
//但是在c++中，表达式返回的是变量的自身，牛逼

//2.他是如何做到的，如果要当左值，表达式需要返回一个内存空间，内存空间就是内存首地址
//(a < b ? a:b) 理论推导
/*
*返回一个a的地址
* *(a < b ? &a:&b) c编译通过，所以说c语言非常灵活，不要轻易说对c语言掌握的非常好
*/
//int main01()
//{
//	int a = 10;
//	int b = 20;
//	(a < b ? a : b) = 30;
//	cout << a << b << endl;
//}
//continue 16 const基础用法
//1.在C语言中const的表现，const主要看是修饰了指针本身还是修饰了指向的内存空间
//  c语言中的const 是冒牌货
/*
*	const int a = 10;
*	int *p = NULL;
*	p = (int *)&a;
*	*p = 20;
*   已验证：在C中确实可以修改
*/

void main02()
{
	//const int a;
	//int const b;	//一样
	////观察const 放在星左面还是星右面
	//const int* c;   //const修饰的是指针所指向的内存空间，不能被修改
	//int* const d;	//const修饰的是指针本身，不能被修改
	//const int* const e; //指针所指向的内存空间，不能被修改；指针本身也不能被修改
}

void main03()
{
	const int a = 10;
	int* p = NULL;
	p = (int*)&a;
	*p = 20;
	printf("a = %d", a);  // a = 10
}

//可见在C++语言中const是个真正常量
//2.原因：c++编译器会把变量放在 符号表中， key valude 当你做地址赋值时其实是另一块空间，都和符号表中数值没有关系
//  所以在c++ const 是个真正的常量

/*
* 结论：
* c: const变量是只读变量，有自己的存储空间
* c++:可能分配空间也可能不分配空间，当const常量为全局，并且需要在其他文件中使用或者&操作符时才会分配空间
*/

//continue 17
//3 const 分配内的时机， 编译器编译时间，扫描之后发现取地址，在实际运行中到a就分配了

//4 const 和 #define 的区别
/*
*  c++的const常量类似于宏定义：
*  const int c = 5 约等于 #define c 5
*  c++中的const常量与宏定义不同：
*  const常量是由编译器处理并提供类型检查和作用域检查
*  宏定义由预处理器处理，单纯的文本替换 （#define #undef  中间便是其作用域）
*/
void main()
{
	const int a = 1;
	const int b = 2;
	int arrary[a + b] = { 0 };
}