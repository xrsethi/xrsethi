#include <iostream>
using namespace std;

/**
 * 函数类型语法基础：
 * 1 C 语言中的函数有自己特定的类型
 * 2 C 语言中通过 typedef 为函数类型重命名
 * 3  typedef type name(parameter list)
 * 4  函数指针
 */


// 数组类型基本语法知识梳理
/**
 * 1 定义一个数组类型  typedef int (myArray)[10]  myArray 提升为 int [10] myArray[0] = 10;
					note:  a[10]  a 代表的是数组的首地址 ， &a 代表整个数组的地址
 * 2 定义一个指针数组类型 typedef int (*pTypeArray)[10] =》int *p //这个类型指向一个数组
 *					use: (*myPArray)[0] = 20;
 * 3 定义一个指向数组类型的指针 数组类的指针 (能不能直接定义类型)
 *					e g: int (*MyPointer)[10]; MyPointer = &a;
 *					use: (*MyPointer)[0] = 40;     itn a[10]      MyPointer = &a
 * 
 * 
 */

int main()
{
	
}

/**
 * 函数指针的基本语法    int add(int  a, int b)
 * 1 如何定义一个函数类型 
 *		e g: typedef int (MyFuncType)(int a, int b) 
 *		use: MyFuncType *myPointerFunc = NULL; 定义了一个指针，指向某一种类的函数...
 * 2 如何定义一个函数指针类型
 * 3 如何定义一个函数指针 （指向一个函数的入口地址）(函数名就是函数的入口地址)
 */