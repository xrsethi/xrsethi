#include <iostream>
using namespace std;

/*
*	day02_06 ** 函数重载:同一个函数名定义不同的函数
*		当函数名和不同的参数搭配时函数的含义不同
*		--返回值不是函数重载的标准
*		--函数重载本质是相互独立的不同函数
*/

void func1(int x)
{
	cout << "func1:x= " << x << endl;
}

void func1(int x, int y)
{
	cout << "func2:x= " << x << "y=" << y<< endl;
}

void func1(char x)
{
	cout << "func3:x= " << x << endl;
}


int main1()
{
	func1(1);
	func1(1, 2);
	func1('x');
	//func1();
	cout << "hi c++:" << endl;
	return 0;
}


/*
*	day02_07 *** 函数重载和函数指针在一起
*		当使用重载函数名对函数指针赋值时
*		根据重载规则挑选与函数指针参数指针的函数类型
*		--后面还会介绍 函数的重载、函数重写、函数重定义
*/
int funcp(int a)
{
	return a;
}
int funcp(int a, int b)
{
	return a + b;
}

int funcp(const char *s)
{
	return strlen(s);
}

typedef int(*Pfunc)(int a,int b);//int(int a) //根据Pfunc 类型，实际调用哪个值

/*
*	函数指针
*	1）声明一个函数类型（函数三要素，名称，参数，返回值）
*		void myfunc(int a,int b)
*		typedef void (myTypeFunc)(int a,int b) 用于定义函数指针 相当于自定义类型
*		myTypeFunc * myfuncp = NULL; 定义一个函数指针 这个指针指向函数的入口
*	2）声明一个函数指针类型
*		typedef void (*myTypeFunc)(int a,int b)
*		myTypeFunc myfuncp = NULL; 通过 函数指针类型定义了一个指针
*	3）直接定义一个函数指针 变量
*		void (*myVarPfunc)(int a, int b);
*/
int main2()
{
	int c = 0;
	Pfunc p = funcp;
	c = p(1,2);

	cout << "c = " << c << endl;
	return 0;
}


/*
*	day02_08 下接08节
*/
int main()
{
	

	cout <<"hi " << endl;

}
