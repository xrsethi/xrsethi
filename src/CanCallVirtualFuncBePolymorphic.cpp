#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
		print();
	}

	virtual void print()
	{	
		cout << "My is Parent a = "<< a << endl;
	}

protected:
private:
	int a;
};

class Child:public Parent
{
public:
	Child(int a = 10, int b = 0) :Parent(a)
	{
		this->b = b;
		print();	//调用Child 中 print ,这就涉及到vptr分步初始化
					// 初始化 c1时 先把 c1.vptr 指向父类，等父类完成
					//初始化后，c1.vptr 指向子类
	}

	virtual  void print()
	{
		cout << "My is Child b = "<< b << endl;
	}
protected:
private:
	int b;
};

void HowToPlay(Parent* base)
{
	base->print();
}

int main()
{
	Parent p1;
	Child c1; //定义一个子类对象，在这个过程中在父类构造函数中调用虚函数print 不会发生多态
	HowToPlay(&c1);
	//HowToPlay(&p1);
	cout << "Child size =" << sizeof(c1) << endl;
	cout << "Child size =" << sizeof(p1) << endl;
	return 0;
}