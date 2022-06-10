#include <iostream>
using namespace std;

/**
 * 纯虚函数和抽象类：
 * 1 纯虚函数是一个在基类中说明的虚函数，在基类中没有定义，
 *	 要求任何派生类都定义自己的版本
 * 2 纯虚函数为各派生类提供一个公共界面(接口的封装和设计、软件的模块功能划分)
 * 3 一个含有纯虚函数的基类称为抽象类
 * shape x;		//error , 抽象类不能建立对象
 * shape *p;	//ok, 可以声明抽象类的指针
 * shape  f()	//error, 抽象类不能做为返回类型
 * void g(shape xxx) //error, 抽象类不能做为参数类型
 * shape & h(shape&) //ok, 可以声明抽象类的引用
 */

class Figure  //抽象类
{
public:
	//约定一个统一界面(接口)，让子类使用，让子类必须实现，要不不可以实例化
	virtual void getArea() = 0;  // 纯虚函数
protected:
private:
};

class Circle : public Figure
{
public:
	Circle(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "Circular area ：" << 3.14 * a * a << endl;
	}
protected:
private:
	int a;
	int b;
};

class Tri : public Figure
{
public:
	Tri(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "triangle Area：" << a*b/2 << endl;
	}
protected:
private:
	int a;
	int b;
};


class Square : public Figure
{
public:
	Square(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "Square Area:" << a * b << endl;
	}
protected:
private:
	int a;
	int b;
};

void ObjPlay(Figure *pBase)
{
	pBase->getArea();
}
int main()
{
	Figure* base = NULL;

	Circle c1(10, 20);
	Tri t1(20, 30);
	Square s1(50, 60);

	ObjPlay(&c1);
	ObjPlay(&t1);
	ObjPlay(&s1);
}

// 主要实现两个不同厂商的解耦合

// 解开偶尔，进行模块划分(你按照我这接口把功能实现了)

//connect day_07 09 抽象类在继承中的应用


/**
 * 有关多继承的说明：
 * 1 工程开发中真正意义上的多继承几乎不被使用的
 * 2 多重继承带来的代码复杂性远多于起带来的便利性
 * 3 多重继承对代码维护性上的影响是灾难性的
 * 4 在设计方法上，任何多继承都可以用单继承代替
 */