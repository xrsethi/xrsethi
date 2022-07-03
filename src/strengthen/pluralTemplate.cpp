#include <iostream>
using namespace std;

/**
 * 复数类模板：
 *		note:一般在项目中，类声明和类中函数分开写:所有的 类模板函数写在类的外部，在不同的.h和.cpp中
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