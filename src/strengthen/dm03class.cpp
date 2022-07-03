#include <iostream>
using namespace std;

/**
 * ��ģ�壺������һ���ģ������������Ͳ�һ�����������������ģ��
 * ���ó���������ҵ���߼�һ�����������Ͳ�һ������ʱ�ò���ģ��
 * ˼����
 *	1 ��ģ���ڼ̳�ʱ��ô�㣿
 *  ��  12
 */

template <typename T>
class A
{
public:
	A(T a = 0)
	{
		this->a = a;
	}
	void printA()
	{
		cout << "a ��" << a << endl;
	}
protected:
	T a;
private:

};
//��ģ���������ǣ���Ҫ���廯ģ���࣬c++��������Ҫ֪��������ռ�ڴ��С�Ƕ���
//��ģ����������ͨ��
class B : public A<int>
{
public:
	B(int a = 10, int b = 20) : A<int>(a)
	{
		this->b = b;
	}
	void printB()
	{
		cout << "a:" << a << "b:" << b << endl;
	}
protected:
private:
	int b;
};

//��ģ��������ģ����
template <typename T>
class C : public A<int>
{
public:
	C(T c, T a) : A<T>(a)
	{
		this->c = c;
	}
	void printC()
	{
		cout << "a:" << a << "c:"<< c << endl;
	}
protected:
private:
	T c;
};


/**
 * ��ģ������������
 */

void UseA(A<int> a)
{
	a.printA();
}

int main()
{
	A<int> a(10), a2(20), a3(30);  //���߱��������������ͣ�����֪����η����ڴ棬��Ҫ���;��廯
	B b1;
	C<int> c1(10,20);
	b1.printB();
	c1.printC();
	UseA(a);
	UseA(a2);
	UseA(a3);
	
	cout << "My Project" << endl;
	return 0;
}