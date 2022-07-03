#include <iostream>
using namespace std;

//void myswap(int& a, int& b)
//{
//	int c = 0;
//
//	c = b;
//	b = a;
//	a = c;
//}
//
//void myswap(char& a, char& b)
//{
//	char c ;
//
//	c = b;
//	b = a;
//	a = c;
//}

/**
 * 让类型参数化， 方便程序员编程：泛行编程 typename T
 */
/**
 * template <typename T> :template 告诉C++编译器 我要开始泛型编程了，不要随便报错(T)
 */
template <typename T>
void myswaypp(T &a, T &b)
{
	T c;
	c = b;
	b = a;
	a = c;
}

//函数模板的调用 1 显示类型 调用 2 自动类型推导
void main()
{
	{
		int x = 10;
		int y = 20;

		myswaypp<int>(x, y);	//1 显示类型调用
		cout << "x = " << x << "y = " << y << endl;
	}

	{
		char a = 'x';
		char b = 'y';

		//myswaypp<char>(a, b);	//1 显示类型调用
		myswaypp(a, b);			//2 自动类型推导 (比较少用)
		cout << "a = " << a << "b = " << b << endl;

	}
}

int main01()
{
	char x = 'x';
	char y = 'y';
	//myswap(x, y);

	cout << "x = " << x << "y = " << y << endl;
	cout << "My Project" << endl;
	return 0;
}
