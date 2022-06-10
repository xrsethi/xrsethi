
#include <iostream>
using namespace std;
// continue day06_17
class Parent
{
public:

	Parent(int a)
	{
		this->a = a;
		cout <<"Parent a = " << a << endl;
	}
	//virtual void print()
	void print()
	{
		cout << "Parent 打印a =" << a << endl;
	}
	~Parent()
	{
	}
protected:
private:
	int a;
};
class Child : public Parent
{
public:
	Child(int b) : Parent(10)
	{
		this->b = b;
		cout << "Child b = " << b << endl;
	}
	void print()
	{
		cout << "Parent 打印b =" << b << endl;
	}
protected:
private:
	int b;
};


int main()
{
	Parent* base = NULL;
	Child* Cp = NULL;
	cout << "Parent ? base =" << sizeof(base) << endl;
	Parent p1(20);
	Child c1(30);

	base = &p1;
	cout << "Parent ? base =" << sizeof(c1) << endl;
	base->print(); //执行父类打印函数

	base = &c1;
	base->print(); //执行谁的函数
	Cp = &c1;
	Cp->print();
	c1.print();
	cout << "--------------------------" << endl;
	{
		Parent& base2 = p1;
		base2.print();

		Parent& base3 = c1; //base3 是 c1 的别名
		base3.print(); 
	}
	//通过以上打印结果提出新需求 多态
	//c++ 通过 virtual关键字对多态进行支持
	//在 父类中写了virtual关键字，可实现多态，子类中可写可不写，一般写上，用来提醒阅读者
	return 0;
}


/*
* 赋值兼容规则
* 1 不允许将基类的对象赋给派生类的对象
* 2 派生类的对象可以赋给基类的对象
* 3 可将派生类的对象的指针赋给基类的指针变量
* 4 派生类对象可以初始化基类型的引用
*/

/*
* 多态存在的3大：意义
* 1 继承是多态的基础
* 2 要有虚函数重写
* 3 用父类指针指向子类对象，所谓的舞台
*/
// 指针存在的最大意义是间接赋值
/*
* 多态是设计模式的基础，多态是框架的基础
* 
* 静态联编和动态联编(动态联编是迟绑定，静态联编是编译期间绑定)
*/