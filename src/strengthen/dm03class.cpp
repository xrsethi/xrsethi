#include <iostream>
using namespace std;

/**
 * 类模板：功能是一样的，仅仅数据类型不一样，这种情况适用类模板
 * 适用场景：函数业务逻辑一样，但是类型不一样，这时用参数模板
 * 思考：
 *	1 类模板在继承时怎么搞？
 *  接  12
 */

template <typename T>
class A
{
public:
	A(T a = 0)
	{
		this->a = a;
	}
	void printA()
	{
		cout << "a ：" << a << endl;
	}
protected:
	T a;
private:

};
//从模板类派生是，需要具体化模板类，c++编译器需要知道父类所占内存大小是多少
//从模板类派生普通类
class B : public A<int>
{
public:
	B(int a = 10, int b = 20) : A<int>(a)
	{
		this->b = b;
	}
	void printB()
	{
		cout << "a:" << a << "b:" << b << endl;
	}
protected:
private:
	int b;
};

//从模板类派生模板类
template <typename T>
class C : public A<int>
{
public:
	C(T c, T a) : A<T>(a)
	{
		this->c = c;
	}
	void printC()
	{
		cout << "a:" << a << "c:"<< c << endl;
	}
protected:
private:
	T c;
};


/**
 * 类模板做函数参数
 */

void UseA(A<int> a)
{
	a.printA();
}

int main()
{
	A<int> a(10), a2(20), a3(30);  //告诉编译器是那种类型，否则不知道如何分配内存，需要类型具体化
	B b1;
	C<int> c1(10,20);
	b1.printB();
	c1.printC();
	UseA(a);
	UseA(a2);
	UseA(a3);
	
	cout << "My Project" << endl;
	return 0;
}