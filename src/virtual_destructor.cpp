#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/*
* ʲô�����ʹ��������
*/

class A
{
public:
	A()
	{
		cout << "A::A() is called.\n" << endl;
		p = new char[20];
		strcpy(p, "aaaaa");
	}
	
	virtual ~A()
	//~A()
	{
		cout << "A::~A() is called.\n" << endl;
		delete[] p;
	}
protected:
private:
	char* p;
};

class B : public A
{
public:
	B()
	{
		cout << "B::B() is called.\n" << endl;
		p = new char[20];
		strcpy(p, "bbbbbb");
	}
	void printB()
	{
		cout << this->p << endl;
	}
	~B()
	{
		cout << "B::~B() is called.\n" << endl;
		delete[] p;
	}
protected:
private:
	char* p;
};

class C : public B
{
public:
	C()
	{
		cout << "C::C() is called.\n" << endl;
		p = new char[20];
		strcpy(p, "ccccccc");
	}
	~C()
	{
		cout << "C::~C() is called.\n" << endl;
		delete[] p;
	}
protected:
private:
	char* p;
};
void howtodelete(A *base)
{
	delete base;
}
int main()
{
	//A* Ap = new B;
	//B* Bp = new B;
	C* Cp = new C;
	//Bp->printB();
	cout << "delete first object:\n" << endl;
	//delete Ap;
	cout << "delete second object:\n" << endl;
	//howtodelete(Bp);
	howtodelete(Cp);

}

/*
* ���ۣ�ͨ������ָ�� �����е�������������������ִ��һ��
* ͨ������ָ�� �ͷ�����������Դ
*/