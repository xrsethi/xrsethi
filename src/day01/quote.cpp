#include <iostream>
using namespace std;

//continue 18 ���� 
/*
* 1. ���õĻ���:��������ָ��
* 
* �������عˣ�
*	������ʵ�������ڴ棨һ�������洢�ռ䣩�ı��
* ����1����һ���ڴ�ռ�ֻ��ȡһ���������δ�أ�����Ϳ���������ʵ��
* 
* ���õĸ��
*	a) ��c++�����������õĸ���
*   b) ���ÿ��Կ���һ���Ѷ�������ı���
*	c) ���õ��﷨�� Type(����)& name = var;
*	d) ������Ϊ���������ǣ���������Ϊ������������ʱ�����г�ʼ����
*/

int  main91()
{
	int a = 10;
	int& b = a;		//���ð�������������C���Ե�˼��ȥ˼����仰��
					/* ��ͨ����������ʱ�����������������г�ʼ�� */

	b = 100;		//�൱�ڰ�a�޸ĳ�Ա��c++��⵽b����������͵͵����ô�� *b = 100
	cout <<"a��ֵ�ǣ�" << a << endl;
	cout <<"b��ֵ�ǣ�" << b << endl;
	return 0;
}

//������������������������������ʱ���ý��г�ʼ��
void myswap(int a, int b);
void mycppswap(int& a, int& b);
int main992()
{
	int x = 10;
	int y = 11;
	mycppswap(x, y);
	cout << "x = " << x << " y = " << y << endl;
	return 0;
}
//������ʵ�֣���Ϊ������ͬ��ջ��ͬ
void myswap(int a, int b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}
//�����ݣ���c++ʵ��,�����ɹ�����Ϊ�βξ���ʵ�εı�������������ֱ�ӾͰ�ʵ�θ�����
void mycppswap(int& a, int& b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}

//continue 19 ���� �����������͵����ã��������� ��

/*
*	printfT()�� printfT1()�� printfT2()��
*   ������������Ȼ���𣬼�����main()
*/
struct Teacher
{
	char name[64];
	int  age;
};
void printfT(Teacher* pT)
{
	cout << pT->age << endl;
}
void printfT1(Teacher& pT)
{
	cout << pT.age << endl;
	//pT.age = 45;
}
void printfT2(Teacher pT)
{
	cout << pT.age << endl;
	pT.age = 55;
}
int main()
{
	Teacher t1;
	t1.age = 35;

	printfT(&t1); 
	printfT1(t1);	//pT��t1�ı���,�޸�pT�൱���޸�t1
	printfT2(t1);	//pT���βΣ�t1 copy һ�����ݸ�pT �൱�� pT = t1;(�����е���˼�������ɼ�)
	printf("t1.age:%d \n",t1.age);
	return 0;
}

//continue 20 ���õ���˼�����õı���