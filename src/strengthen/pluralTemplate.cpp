#include <iostream>
using namespace std;

/**
 * ������ģ�壺
 *		note:һ������Ŀ�У������������к����ֿ�д:���е� ��ģ�庯��д������ⲿ���ڲ�ͬ��.h��.cpp��
 */
template <typename T>
class A
{
public:
	A(T a)
	{
		this->a = a;
	}

	~A()
	{

	}
public:
	//void printA()
	//{
	//	cout << "a:" << a << endl;
	//}
	void printA();

private:
	T a;
};

template <typename T>
void A::printA()
{
	
}


int main()
{


	cout << "My Project plutalTemp" << endl;
	return 0;
}