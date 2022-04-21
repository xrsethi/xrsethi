/* Object Construction And Destruction						:对象的构造和析构  */
/* Constructor And Destructor;Construction And Destruction	:构造函数和析构函数*/

#include <iostream>
using namespace std;

/*
*	c++ 对象的构造和析构：创建一个对象时，常常需要做某些初始化工作，例如对象数据成员赋初值。
*	为解决这个问题，c++ 编译器提供了构造函数来处理对象的初始化。构造函数属于特殊成员，不需要
*	用户来调用它，而是在建立对象时自动执行
* 
*	1.构造和析构的基本概念
*   day_03 05c 
*	day_03 06c ：构造和析构存在的意义：显示调用初始化，比较繁琐，并有些不能显示，例如数组，
*	所以还是选择构造和析构函数
* 
*	如果没有提供构造或者析构函数，c++还有默认构造函数：
*	如果没有提供拷贝函数，c++也会提供默认的拷贝构造函数
*/

class MyClass
{
public:
	MyClass();	//构造函数分类：1.无参构造 2.有参构造 3.赋值构造也叫拷贝构造
	MyClass(int a, int b);	//调用有参构造函数 MyClass t1(1，2);
	MyClass(const MyClass& obj);	//拷贝构造函数(copy构造函数)
	~MyClass();

private:
protected:
	int m_a;
	int m_b;
	//char* pDate;		//c++并不检查野指针
};

MyClass::MyClass()
{
	m_a = 0;
	m_b = 0;
	cout << "Constructor MyClass ..." << endl;
}
MyClass::MyClass(int a, int b)
{
	m_a = a;
	m_b = b;
	cout << "Constructor MyClass1..." << endl;
}
MyClass::MyClass(const MyClass& obj)
{
	cout << "Constructor MyClass2..." << endl;
}

MyClass::~MyClass()
{
	cout << "Destructor ..." << endl;
}

void objplay()
{
	//先创建的对象后释放
	MyClass t1();		//1 当时并没有报错，但当你调用对象中成员变量时就会暴漏出来
	MyClass t2(1, 2);	//2 可成功调用 ,但 MyClass t1 = (1, 2) 不可以 c++ 对 = 操作符进行功能增强
	//3 手动调用构造
	MyClass t4 = MyClass(2,1);	//会产生匿名函数，匿名对象的去和留
	t2 = t4;			//对象的初始化和对象的赋值是两个不同的概念
	//MyClass t2;
}

int main()
{
	objplay();
	cout << "hello..." << endl;
	return 0;
}


/*
*	day_03 07c 开始要，规范笔记编写，这样方便以后查找
*	1.把存储day_0xx 去掉，直接存源文件，源文件内首先标记学习位置
*	2.规范编写源文件文件名，这样有利于知识点定位，便于查找，根据文件名变可确定文件内容
*	3.文件内编写，不要有过多文字，不便于以后查看，也未必能理解当时的内容，条目清晰，案例典型，
*	突出知识点内容
*/