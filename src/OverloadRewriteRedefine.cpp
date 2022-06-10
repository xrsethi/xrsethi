#include <iostream>
using namespace std;


class Parent
{
public:
	virtual void func()							//重载 1
	{
		cout << "func() do...." << endl;
	}
	virtual void func(int i)					//重载 2
	{
		cout << "func() do...." << i << endl;
	}
	virtual void func(int i, int j)				//重载 3
	{
		cout << "func() do...." << i << "  "<< j << endl;
	}
protected:
private:
	
};

class Child : public Parent
{
public:
	virtual void func(int i, int j)
	{
		cout << "func() do...." << i << "  " << j << endl;
	}
	virtual void func(int i, int j, int k)
	{
		cout << "func() do...." << i << "  " << j << endl;
	}
protected:
private:
};


int main()
{
	Child c1;
	//c1.func();
	/*
	* func 函数的名字，在子类中发生了名称覆盖；子类的函数的名，占用了父类函数的名字的位置
	* 因为子类中已经有了func名字的重载形式
	* 编译器开始在子类中找func函数 。。。但是没有0个参数的func函数
	*/
}

/**
 *	函数重载：
 *		必须在同一个类中进行
 *		子类无法重载父类的函数，父类同名函数将被名称覆盖
 *		重载是在编译期间根据参数类型和个数决定函数调用
 *	函数重写：
 *		必须发生于父子类之间
 *		并且父类与子类中的函数必须完全相同的原型
 *		兵分两路：使用virtual声明之后能够产生多态(如果不使用virtual，那叫重定义)
 *		多态是在运行期间根据具体对象的类型决定函数调用
 */