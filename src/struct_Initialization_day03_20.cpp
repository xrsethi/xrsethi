#include <iostream>
using namespace std;

/* c++提供初始化列表，对成员变量进行初始化 */

class A
{
public:
	
	A(int _a)
	{
		my_a = _a;
		cout << "A.." << endl;
	}

	~A()
	{
		cout << "~A.." << endl;
	}

private:
	int my_a;
};

class B
{
public:
#if 0
	B()			// 没有列表的情况的报错例子
	{
	}
#endif
	B(int _b1, int _b2) : a1(2),a2(3)	// 构造函数初始化列表案例
	{
		my_b1 = _b1;
		my_b2 = _b2;
		cout << "B.." << endl;
	}
	B(int _b1, int _b2,int m,int n) : a1(m), a2(n)	// 构造函数初始化列表案例
	{
		my_b1 = _b1;
		my_b2 = _b2;
		cout << "B.." << endl;
	}

	~B()
	{
		cout << "~B.." << endl;
	}

private:
	int my_b1;
	int my_b2;
	A a1;		// 构造这个类时，没有机会初始化A（所以c++不知道此类需要多大内存）
	A a2;		// 如果组合对象有多个，按照定义顺序进行初始化，析构和构造相反
	const int c;	//const 成员必须初始化
};


int main()
{
	A a1(10);
	B objB(1,2);

	cout << "hello.." << endl;
	return 0;
}