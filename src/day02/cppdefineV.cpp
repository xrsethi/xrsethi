#include <iostream>
using namespace std;
/*
* 1. c++�е�Ĭ�ϲ�����
*/




void myPrint(int x = 3)
{
	cout << "x = " << x << endl;
}
void myPrint2(int x = 3,int y = 4)	//void myPrint2(int x = 3,int y = 4,int m)
{									//**�����ԣ���Ĭ�ϲ����󲻿��ԼӲ��������Ĳ�����֮ǰ����
	cout << "x = " << x << endl;
}
int main1()
{
	//*�������д������ʹ������д�Ĳ���������дʹ��Ĭ��ֵ(ǰ���Ǳ����Ĭ��ֵ)
	//
	myPrint(4);
	myPrint();

	return 0;
}

/*
* 2. c++�еĺ���ռλ������
*/

void func(int  a, int b, int)
{
	cout << "a= " << a << "b=" << b << endl;
}
int main2()
{
	//func(1,2);	//����ռλ���������������Ǳ���д������
	func(1,2,3);
	return 0;
}

/*
* 3. c++�еĺ���ռλ������Ĭ�ϲ���һ��ʹ�ã�������Ϊ�Ժ�������չ��������
*/

void func1(int  a, int b, int = 0)
{
	cout << "a= " << a << ";b=" << b << endl;
}
int main()
{
	func1(1,2);	//����ռλ���������������ǲ�����д��������Ҳ���Ե�������
	func1(1, 2, 3);
	return 0;
}