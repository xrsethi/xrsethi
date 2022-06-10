#include <iostream>
using namespace std;

class Base
{
public:
	Base(int k = 0)
	{
		this->k = k;
		cout << "My is Base " << endl;
	}
protected:
private:
	int k;
};

class Base2
{
public:
	Base2(int k = 0)
	{
		this->k = k;
		cout << "My is Base 2" << endl;
	}
protected:
private:
	int k;
};

class Child1 : public Base,public Base2
{
public:
	Child1(int c = 0) : Base(10), Base2(20)
	{
		this->c = c;
	}
protected:
private:
	int c;
};

int main21()
{
	//Child c1;
	//c1.k = 10;  //��̳еĶ�����
	return 0;
}

/**
 * ��̳е�Ӧ�ó���
 * Note: 1 �����������������Զ���֧�ֶ�̳�
 *		 2 �����������������Զ�֧�ֽӿڸ���	
 *		 3 c++����ʹ�ô��麯��ʵ�ֽӿ�
 *		 4 �ӿ�����ֻ�к���ԭ�Ͷ��壬û���κ����Ķ���
 * eg: 
 *	class Interface 
 *	{
 *		public:
 *			virtual void func1() = 0;
 *			virtual void func2(int i) = 0;
 *			virtual void func3(int i) = 0;
 *	}
 * ʵ�ʹ��̾���֤��
 * 1 ��̳нӿڲ�����������Ժ͸����Ե�����
 * 2 ��̳п��Ծ�������õ��̳кͽӿ�������
 * 3 �ӿ���ֻ��һ������˵���������ǹ���ʵ��
 * 4 ������Ҫ���ݹ���˵�����幦��ʵ��
 */

// �����ǳ������ڶ�̳��е�Ӧ��

class Interface1
{
public:
	virtual int add(int a, int b) = 0;
	virtual void print() = 0;
protected:
private:
};
class Interface2
{
public:
	virtual int mult(int a, int b) = 0;
	virtual void print() = 0;
protected:
private:
};

class Parent
{
public:
	int getA()
	{
		a = 0;
		return a;
	}
protected:
private:
	int a;
};

class Child :public Parent, public Interface1, public Interface2
{
public:
	virtual int add(int a, int b)
	{
		cout << "Child : add" << endl;
		return a + b;
	}
	virtual void print()
	{
		cout << "Child : print" << endl;
	}
	virtual int mult(int a, int b)
	{
		cout << "Child : mult" << endl;
		return a * b;
	}
protected:
private:
};


int main()  //��̳�ʹ�ð���
{
	Child c1;
	c1.print();
	c1.add(1, 3);

	Interface1* it1 = &c1;
	it1->add(2, 3);

	Interface2* it2 = &c1;
	it2->mult(3, 4);
	it2->print();
	return 0;
}