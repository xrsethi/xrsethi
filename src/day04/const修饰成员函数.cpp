#include <iostream>
using namespace std;

class MyClass
{

public:
	void OpVar(int a, int b) const //==> void OpVar(const Test *this,int a, int b) |const ���ε���This ָ��
	{	// const This *this ,ָ����ָ����ڴ�ռ䲻���޸�
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