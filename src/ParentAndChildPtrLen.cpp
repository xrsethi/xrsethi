#include <iostream>
using namespace std;
/**
 * day_07 06 父类指针的步长和子类指针的步常
 * 
 * 在 c++中，使用子类指针和父类指针同时操作数组会怎样？
 * 
 * 结论：父类P++与子类P++步长不同；不要混搭，不要在数组上使用多态
 */
class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
	}
	virtual void print()
	{
		cout << "My is Parent a = " << a << endl;

	}

protected:
private:
	int a;
};


class Child : public Parent
{
public:
	Child(int a = 0, int b = 0) : Parent(a)
	{
		this->b = b;
	}

	virtual void print()
	{
		cout << "My is Child b = " << b << endl;
	}
protected:
private:
	int b;
};
void HowToPlay(Parent* base)
{
	base->print();   //有多态发生
}
// 一次偶然的成功，比必然的失败更可怕
// 指针的步长：根据指针的类型决定
int main()
{
	Child* pC = NULL;
	Parent* pP = NULL;

	Child array[] = {Child(1, 5), Child(2,6), Child(3),Child(4)};
	pP = array;
	pC = array;
	pP->print();
	pC->print(); //发生多态

	//pP++;		//在Child不占内存时没问题，但是子类中如果占用内存，那么直接挂掉
	pC++;
	pP = pC;
	pP->print();
	pC->print(); //发生多态

	cout << "size Parent"  << sizeof(Parent) << "size Child" << sizeof(Child) << endl;
}

// 典型的子类和父类指针步长不一样的问题，学完多态千万注意这种问题
// 结论：多态是父类指针指向子类对象 和 父类步长++，是两中不同的概念