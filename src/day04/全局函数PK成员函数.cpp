#include <iostream>
using namespace std;

class MyClass
{
public:
	MyClass MyClassAdd(MyClass &tmp)	// ���þ��൱��const ����ָ�룬c++��������Щϸ��
	{								// �������ö�������������ã������ڲ������൱�ڱ�������
		this->a = this->a + tmp.a;
		this->b = this->b + tmp.b;
		return *this;
	}
	MyClass(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	void MyClassPrint()
	{
		cout << "a = " << this->a << "b = " << this->b << endl;
	}
public:
	MyClass();
	~MyClass();

private:
	int a;
	int b;
};

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

int main()
{
	MyClass t1(1, 2);
	MyClass t2(3, 4);

	MyClass t3;
	t1.MyClassAdd(t2);
	t1.MyClassPrint();
	t2.MyClassPrint();
	t3.MyClassPrint();
	cout << "Project3 hello.." << endl;
	return 0;
}