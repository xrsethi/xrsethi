#include <iostream>
using namespace std;

class Base
{
public:
	Base(int k = 0)
	{
		this->k = k;
		cout << "My is Base " << endl;
	}
protected:
private:
	int k;
};

class Base2
{
public:
	Base2(int k = 0)
	{
		this->k = k;
		cout << "My is Base 2" << endl;
	}
protected:
private:
	int k;
};

class Child1 : public Base,public Base2
{
public:
	Child1(int c = 0) : Base(10), Base2(20)
	{
		this->c = c;
	}
protected:
private:
	int c;
};

int main21()
{
	//Child c1;
	//c1.k = 10;  //多继承的二义性
	return 0;
}

/**
 * 多继承的应用场景
 * Note: 1 绝大多数面向对象语言都不支持多继承
 *		 2 绝大多数面向对象语言都支持接口概念	
 *		 3 c++可以使用纯虚函数实现接口
 *		 4 接口类中只有函数原型定义，没有任何数的定义
 * eg: 
 *	class Interface 
 *	{
 *		public:
 *			virtual void func1() = 0;
 *			virtual void func2(int i) = 0;
 *			virtual void func3(int i) = 0;
 *	}
 * 实际工程经验证明
 * 1 多继承接口不会带来二义性和复杂性等问题
 * 2 多继承可以精心设计用单继承和接口来代替
 * 3 接口类只是一个功能说明，而不是功能实现
 * 4 子类需要根据功能说明定义功能实现
 */

// 下面是抽象类在多继承中的应用

class Interface1
{
public:
	virtual int add(int a, int b) = 0;
	virtual void print() = 0;
protected:
private:
};
class Interface2
{
public:
	virtual int mult(int a, int b) = 0;
	virtual void print() = 0;
protected:
private:
};

class Parent
{
public:
	int getA()
	{
		a = 0;
		return a;
	}
protected:
private:
	int a;
};

class Child :public Parent, public Interface1, public Interface2
{
public:
	virtual int add(int a, int b)
	{
		cout << "Child : add" << endl;
		return a + b;
	}
	virtual void print()
	{
		cout << "Child : print" << endl;
	}
	virtual int mult(int a, int b)
	{
		cout << "Child : mult" << endl;
		return a * b;
	}
protected:
private:
};


int main()  //多继承使用案例
{
	Child c1;
	c1.print();
	c1.add(1, 3);

	Interface1* it1 = &c1;
	it1->add(2, 3);

	Interface2* it2 = &c1;
	it2->mult(3, 4);
	it2->print();
	return 0;
}