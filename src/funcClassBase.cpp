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

int main()
{
	
}

/**
 * ����ָ��Ļ����﷨    int add(int  a, int b)
 * 1 ��ζ���һ���������� 
 *		e g: typedef int (MyFuncType)(int a, int b) 
 *		use: MyFuncType *myPointerFunc = NULL; ������һ��ָ�룬ָ��ĳһ����ĺ���...
 * 2 ��ζ���һ������ָ������
 * 3 ��ζ���һ������ָ�� ��ָ��һ����������ڵ�ַ��(���������Ǻ�������ڵ�ַ)
 */