#include <iostream>
using namespace std;

/*
*	copy构造函数：用一个对象初始化另外一个对象
*	赋值构造函数的四种调用场景
*	note:制作和使用，使用是借用别人做好的方法，按别人的套路()去解决问题
*		 制作是解决问题的方法,是创造套路去解决问题，往往会有一种最佳套路
*		 什么是最佳套路，就是你经过思考实验，忽然发现与原有方案(一般都是经过历时推敲的)不谋而合
*/

class AAA
{
public:
	AAA()
	{
		m_a = 1;
		m_b = 2;
		cout << "AAA() " << endl;
	}
	AAA(int a,int b)
	{
		m_a = a;
		m_b = b;
		cout << "AAA(int a,int b) " << endl;
	}
#if 1
	AAA(const AAA& obj) //如果不写，则调用默认的c++拷贝构造函数
	{
		m_a = obj.m_a + 100;
		m_b = obj.m_b + 100;
		cout << "AAA(const AAA& obj) " << endl;
	}
#endif
	~AAA() //析构函数不能有参数
	{
		cout << "~AAA) " << endl;
	}

private:
public:
	int m_a;
	int m_b;
};

void fun(AAA Data)
{
	cout << "Fun .." << Data.m_a << Data.m_b << endl;
}
AAA funBack()  //返回一个匿名对象，匿名对象的去留，主要看怎么接
{
	cout << "funBack .." << endl;
	AAA m1(6, 7);
	return m1;	//执行一此copy,用 m1 创建了一个匿名对象
}
int main()
{
	AAA t1;
	AAA t2(5, 4);
	AAA t3 = t2;	/* 都会调用构造函数 第一种调用时机*/
	AAA t4(t1);		/* 都会调用构造函数 第二种调用时机*/
	fun(t2);		/* 实参初始化形参   第三种调用时机*/
	/* 是否是第四种调用时间，主要看怎么接返回值*/
	AAA t5 = funBack();    /* 匿名对象直接转正，也就不用调用copy函数了 */
	cout << "AAA t5 .." << t5.m_a << t5.m_b << endl;
	AAA t6;
	t6 = funBack();		   /* 如果赋值给另外一个同类型对象，那么匿名函数会被析构 */
	cout << "AAA t6 .." << t6.m_a << t6.m_b << endl;
	t1 = t2;		/* 对象的赋值和对象的初始化是两个概念 */
	// = 显示重载
	cout << "m_a = "<< t3.m_a << endl;
}