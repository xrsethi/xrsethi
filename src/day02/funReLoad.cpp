#include <iostream>
using namespace std;

/*
*	day02_06 ** ��������:ͬһ�����������岻ͬ�ĺ���
*		���������Ͳ�ͬ�Ĳ�������ʱ�����ĺ��岻ͬ
*		--����ֵ���Ǻ������صı�׼
*		--�������ر������໥�����Ĳ�ͬ����
*/

void func1(int x)
{
	cout << "func1:x= " << x << endl;
}

void func1(int x, int y)
{
	cout << "func2:x= " << x << "y=" << y<< endl;
}

void func1(char x)
{
	cout << "func3:x= " << x << endl;
}


int main1()
{
	func1(1);
	func1(1, 2);
	func1('x');
	//func1();
	cout << "hi c++:" << endl;
	return 0;
}


/*
*	day02_07 *** �������غͺ���ָ����һ��
*		��ʹ�����غ������Ժ���ָ�븳ֵʱ
*		�������ع�����ѡ�뺯��ָ�����ָ��ĺ�������
*		--���滹����� ���������ء�������д�������ض���
*/
int funcp(int a)
{
	return a;
}
int funcp(int a, int b)
{
	return a + b;
}

int funcp(const char *s)
{
	return strlen(s);
}

typedef int(*Pfunc)(int a,int b);//int(int a) //����Pfunc ���ͣ�ʵ�ʵ����ĸ�ֵ

/*
*	����ָ��
*	1������һ���������ͣ�������Ҫ�أ����ƣ�����������ֵ��
*		void myfunc(int a,int b)
*		typedef void (myTypeFunc)(int a,int b) ���ڶ��庯��ָ�� �൱���Զ�������
*		myTypeFunc * myfuncp = NULL; ����һ������ָ�� ���ָ��ָ���������
*	2������һ������ָ������
*		typedef void (*myTypeFunc)(int a,int b)
*		myTypeFunc myfuncp = NULL; ͨ�� ����ָ�����Ͷ�����һ��ָ��
*	3��ֱ�Ӷ���һ������ָ�� ����
*		void (*myVarPfunc)(int a, int b);
*/
int main2()
{
	int c = 0;
	Pfunc p = funcp;
	c = p(1,2);

	cout << "c = " << c << endl;
	return 0;
}


/*
*	day02_08 �½�08��
*/
int main()
{
	

	cout <<"hi " << endl;

}
