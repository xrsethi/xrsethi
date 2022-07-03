#include <iostream>
using namespace std;

//void myswap(int& a, int& b)
//{
//	int c = 0;
//
//	c = b;
//	b = a;
//	a = c;
//}
//
//void myswap(char& a, char& b)
//{
//	char c ;
//
//	c = b;
//	b = a;
//	a = c;
//}

/**
 * �����Ͳ������� �������Ա��̣����б�� typename T
 */
/**
 * template <typename T> :template ����C++������ ��Ҫ��ʼ���ͱ���ˣ���Ҫ��㱨��(T)
 */
template <typename T>
void myswaypp(T &a, T &b)
{
	T c;
	c = b;
	b = a;
	a = c;
}

//����ģ��ĵ��� 1 ��ʾ���� ���� 2 �Զ������Ƶ�
void main()
{
	{
		int x = 10;
		int y = 20;

		myswaypp<int>(x, y);	//1 ��ʾ���͵���
		cout << "x = " << x << "y = " << y << endl;
	}

	{
		char a = 'x';
		char b = 'y';

		//myswaypp<char>(a, b);	//1 ��ʾ���͵���
		myswaypp(a, b);			//2 �Զ������Ƶ� (�Ƚ�����)
		cout << "a = " << a << "b = " << b << endl;

	}
}

int main01()
{
	char x = 'x';
	char y = 'y';
	//myswap(x, y);

	cout << "x = " << x << "y = " << y << endl;
	cout << "My Project" << endl;
	return 0;
}
