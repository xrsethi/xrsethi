#include <iostream>
using namespace std;

/**
 * ���������﷨������
 * 1 C �����еĺ������Լ��ض�������
 * 2 C ������ͨ�� typedef Ϊ��������������
 * 3  typedef type name(parameter list)
 * 4  ����ָ��
 */


// �������ͻ����﷨֪ʶ����
/**
 * 1 ����һ����������  typedef int (myArray)[10]  myArray ����Ϊ int [10] myArray[0] = 10;
					note:  a[10]  a �������������׵�ַ �� &a ������������ĵ�ַ
 * 2 ����һ��ָ���������� typedef int (*pTypeArray)[10] =��int *p //�������ָ��һ������
 *					use: (*myPArray)[0] = 20;
 * 3 ����һ��ָ���������͵�ָ�� �������ָ�� (�ܲ���ֱ�Ӷ�������)
 *					e g: int (*MyPointer)[10]; MyPointer = &a;
 *					use: (*MyPointer)[0] = 40;     itn a[10]      MyPointer = &a
 * 
 * 
 */

int myadd(int a, int b)  // �����ʵ����
{
	return a + b;
}

typedef int (*MyTypeFuncAdd)(int a, int b);

int MainOp1(MyTypeFuncAdd myFuncAdd) 
{
	int c = myFuncAdd(5, 6);
	return c;
}

int MainOp2(int (*MyPointerFuncAdd)(int a, int b))
{
	int c = MyPointerFuncAdd(5, 6);
	return c;
}
// ����ָ�뵽������ʲô������  Լ���˺����Ĳ����ͷ���ֵ���������Լ������������ɣ�
// ��ô�Ҿ�������������ʹ�û���˵�Ҿ��ܰ��������д�Ĵ����������  ....������ν�Ľӿ� �� c++�Ķ�̬
int main()
{
	MyTypeFuncAdd myFuncAdd = NULL;
	myadd(1, 2);

	myFuncAdd = myadd;
	myFuncAdd(3, 4);

	// ��mainop��� û�з����κα仯����� .. �޸�ʵ��������ĺ���
	MainOp1(myadd);
	MainOp2(myadd);
}

/**
 * ����ָ��Ļ����﷨    int add(int  a, int b)
 * 1 ��ζ���һ���������� 
 *		e g: typedef int (MyFuncType)(int a, int b);
 *		use: MyFuncType *myPointerFunc = NULL; ������һ��ָ�룬ָ��ĳһ����ĺ���...
 * 2 ��ζ���һ������ָ������
 *		e g: typedef int (*MyPointerFuncType)(int a, int b);
 * 
 * 3 ��ζ���һ������ָ�� ��ָ��һ����������ڵ�ַ��(���������Ǻ�������ڵ�ַ)
 *		e g: int (*MyPonterFUnc)(int a, int b); //����һ������
 * 
 */