#include <iostream>
using namespace std;

/* c++�ṩ��ʼ���б��Գ�Ա�������г�ʼ�� */

class A
{
public:
	
	A(int _a)
	{
		my_a = _a;
		cout << "A.." << endl;
	}

	~A()
	{
		cout << "~A.." << endl;
	}

private:
	int my_a;
};

class B
{
public:
#if 0
	B()			// û���б������ı�������
	{
	}
#endif
	B(int _b1, int _b2) : a1(2),a2(3)	// ���캯����ʼ���б���
	{
		my_b1 = _b1;
		my_b2 = _b2;
		cout << "B.." << endl;
	}
	B(int _b1, int _b2,int m,int n) : a1(m), a2(n)	// ���캯����ʼ���б���
	{
		my_b1 = _b1;
		my_b2 = _b2;
		cout << "B.." << endl;
	}

	~B()
	{
		cout << "~B.." << endl;
	}

private:
	int my_b1;
	int my_b2;
	A a1;		// ���������ʱ��û�л����ʼ��A������c++��֪��������Ҫ����ڴ棩
	A a2;		// �����϶����ж�������ն���˳����г�ʼ���������͹����෴
	const int c;	//const ��Ա�����ʼ��
};


int main()
{
	A a1(10);
	B objB(1,2);

	cout << "hello.." << endl;
	return 0;
}