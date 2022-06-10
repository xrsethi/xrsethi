#include <iostream>
using namespace std;

class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
		print();
	}

	virtual void print()
	{	
		cout << "My is Parent a = "<< a << endl;
	}

protected:
private:
	int a;
};

class Child:public Parent
{
public:
	Child(int a = 10, int b = 0) :Parent(a)
	{
		this->b = b;
		print();	//����Child �� print ,����漰��vptr�ֲ���ʼ��
					// ��ʼ�� c1ʱ �Ȱ� c1.vptr ָ���࣬�ȸ������
					//��ʼ����c1.vptr ָ������
	}

	virtual  void print()
	{
		cout << "My is Child b = "<< b << endl;
	}
protected:
private:
	int b;
};

void HowToPlay(Parent* base)
{
	base->print();
}

int main()
{
	Parent p1;
	Child c1; //����һ���������������������ڸ��๹�캯���е����麯��print ���ᷢ����̬
	HowToPlay(&c1);
	//HowToPlay(&p1);
	cout << "Child size =" << sizeof(c1) << endl;
	cout << "Child size =" << sizeof(p1) << endl;
	return 0;
}