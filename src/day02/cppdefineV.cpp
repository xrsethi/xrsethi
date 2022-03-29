#include <iostream>
using namespace std;
/*
* 1. c++中的默认参数：
*/




void myPrint(int x = 3)
{
	cout << "x = " << x << endl;
}
void myPrint2(int x = 3,int y = 4)	//void myPrint2(int x = 3,int y = 4,int m)
{									//**不可以，有默认参数后不可以加不带参数的参数，之前可以
	cout << "x = " << x << endl;
}
int main1()
{
	//*如果你填写参数，使用你填写的参数，不填写使用默认值(前提是必须给默认值)
	//
	myPrint(4);
	myPrint();

	return 0;
}

/*
* 2. c++中的函数占位参数：
*/

void func(int  a, int b, int)
{
	cout << "a= " << a << "b=" << b << endl;
}
int main2()
{
	//func(1,2);	//函数占位参数，函数调用是必须写够参数
	func(1,2,3);
	return 0;
}

/*
* 3. c++中的函数占位参数和默认参数一起使用：意义是为以后程序的扩展留下线索
*/

void func1(int  a, int b, int = 0)
{
	cout << "a= " << a << ";b=" << b << endl;
}
int main()
{
	func1(1,2);	//函数占位参数，函数调用是不必须写够参数，也可以调用起来
	func1(1, 2, 3);
	return 0;
}