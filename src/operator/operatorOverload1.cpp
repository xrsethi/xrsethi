#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(int a, int b);
	~Complex()
	{
		
	}
	void printCom()
	{
		cout << a << "+" << b << "i" << endl;
	}
public:
	int a;
	int b;
private:

};

Complex::Complex(int a = 0, int b = 0)
{
	this->a = a;
	this->b = b;
}
//+����������أ�������������������ȥ����Ӧ����
Complex myAdd(Complex& c1, Complex& c2)
{
	Complex tmp(1, 2);
	return tmp;
}

Complex operator+(Complex& c1, Complex& c2)
{
	Complex tmp(c1.a + c2.a, c1.b + c2.b);
	return tmp;
}

int main2()
{
	Complex c1(1, 2), c2(3, 4);
	Complex c3;		/* �û��Զ����������ͣ� c++������Ĭ���ǲ�֪����*/
	// a + bi
	/* c++�ṩһ�ֻ��ƣ����Զ����������ͣ��л���������������*/
	
	//c3 = c1 + c2;

	/* ��������ػ��� */
	//c3 = myAdd(c1, c2);
	c3 = c1 + c2;
	c3.printCom();
	cout << "operator Test" << endl;
	return 0;
}

/* ��������ط�Ϊ���ַ��� ��Ա����Ԫ������������� */
/*
* �����������������Ϊ��Ա��������Ԫ����
* �ؼ��������ڳ�Ա��������thisָ�룬��Ԫ����û��thisָ��
* �����ǳ�Ա����������Ԫ�������أ��������ʹ�÷�����ͬ
* �����ݲ����ķ�ʽ��ͬ��ʵ�ִ��벻ͬ��Ӧ�ó���Ҳ��ͬ
*/


int main()
{
	cout << "hi" << endl;
}