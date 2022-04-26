#include <iostream>
using namespace std;

class MyClass
{

public:
	void OpVar(int a, int b) const //==> void OpVar(const Test *this,int a, int b) |const 修饰得是This 指针
	{	// const This *this ,指针所指向的内存空间不可修改
	}
public:
	MyClass()
	{
	}

	~MyClass()
	{
	}

private:

};


int main()
{

	cout << "Project3 hello..." << endl;
	return 0;
}