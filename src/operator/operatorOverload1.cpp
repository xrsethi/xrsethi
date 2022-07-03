#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(int a, int b);
	~Complex()
	{
		
	}
	void printCom()
	{
		cout << a << "+" << b << "i" << endl;
	}
public:
	int a;
	int b;
private:

};

Complex::Complex(int a = 0, int b = 0)
{
	this->a = a;
	this->b = b;
}
//+号运算符重载，编译器会根据你的类型去找相应函数
Complex myAdd(Complex& c1, Complex& c2)
{
	Complex tmp(1, 2);
	return tmp;
}

Complex operator+(Complex& c1, Complex& c2)
{
	Complex tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}

int main2()
{
	Complex c1(1, 2), c2(3, 4);
	Complex c3;		/* 用户自定义数据类型， c++编译器默认是不知道的*/
	// a + bi
	/* c++提供一种机制，让自定义数据类型，有机会进行运算符操作*/
	
	//c3 = c1 + c2;

	/* 运算符重载机制 */
	//c3 = myAdd(c1, c2);
	c3 = c1 + c2;
	c3.printCom();
	cout << "operator Test" << endl;
	return 0;
}

/* 运算符重载分为两种方法 成员或友元函数重载运算符 */
/*
* 运算符函数可以重载为成员函数或友元函数
* 关键区别在于成员函数具有this指针，友元函数没有this指针
* 不管是成员函数还是友元函数重载，运算符的使用方法相同
* 但传递阐述的方式不同，实现代码不同，应用场合也不同
*/


int main()
{
	cout << "hi" << endl;
}