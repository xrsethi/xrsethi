#include <iostream>
using namespace std;

/*
*	copy���캯������һ�������ʼ������һ������
*	��ֵ���캯�������ֵ��ó���
*	note:������ʹ�ã�ʹ���ǽ��ñ������õķ����������˵���·()ȥ�������
*		 �����ǽ������ķ���,�Ǵ�����·ȥ������⣬��������һ�������·
*		 ʲô�������·�������㾭��˼��ʵ�飬��Ȼ������ԭ�з���(һ�㶼�Ǿ�����ʱ���õ�)��ı����
*/

class AAA
{
public:
	AAA()
	{
		m_a = 1;
		m_b = 2;
		cout << "AAA() " << endl;
	}
	AAA(int a,int b)
	{
		m_a = a;
		m_b = b;
		cout << "AAA(int a,int b) " << endl;
	}
#if 1
	AAA(const AAA& obj) //�����д�������Ĭ�ϵ�c++�������캯��
	{
		m_a = obj.m_a + 100;
		m_b = obj.m_b + 100;
		cout << "AAA(const AAA& obj) " << endl;
	}
#endif
	~AAA() //�������������в���
	{
		cout << "~AAA) " << endl;
	}

private:
public:
	int m_a;
	int m_b;
};

void fun(AAA Data)
{
	cout << "Fun .." << Data.m_a << Data.m_b << endl;
}
AAA funBack()  //����һ�������������������ȥ������Ҫ����ô��
{
	cout << "funBack .." << endl;
	AAA m1(6, 7);
	return m1;	//ִ��һ��copy,�� m1 ������һ����������
}
int main()
{
	AAA t1;
	AAA t2(5, 4);
	AAA t3 = t2;	/* ������ù��캯�� ��һ�ֵ���ʱ��*/
	AAA t4(t1);		/* ������ù��캯�� �ڶ��ֵ���ʱ��*/
	fun(t2);		/* ʵ�γ�ʼ���β�   �����ֵ���ʱ��*/
	/* �Ƿ��ǵ����ֵ���ʱ�䣬��Ҫ����ô�ӷ���ֵ*/
	AAA t5 = funBack();    /* ��������ֱ��ת����Ҳ�Ͳ��õ���copy������ */
	cout << "AAA t5 .." << t5.m_a << t5.m_b << endl;
	AAA t6;
	t6 = funBack();		   /* �����ֵ������һ��ͬ���Ͷ�����ô���������ᱻ���� */
	cout << "AAA t6 .." << t6.m_a << t6.m_b << endl;
	t1 = t2;		/* ����ĸ�ֵ�Ͷ���ĳ�ʼ������������ */
	// = ��ʾ����
	cout << "m_a = "<< t3.m_a << endl;
}