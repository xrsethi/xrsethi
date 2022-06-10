#include <iostream>
using namespace std;

/**
 * ���麯���ͳ����ࣺ
 * 1 ���麯����һ���ڻ�����˵�����麯�����ڻ�����û�ж��壬
 *	 Ҫ���κ������඼�����Լ��İ汾
 * 2 ���麯��Ϊ���������ṩһ����������(�ӿڵķ�װ����ơ������ģ�鹦�ܻ���)
 * 3 һ�����д��麯���Ļ����Ϊ������
 * shape x;		//error , �����಻�ܽ�������
 * shape *p;	//ok, ���������������ָ��
 * shape  f()	//error, �����಻����Ϊ��������
 * void g(shape xxx) //error, �����಻����Ϊ��������
 * shape & h(shape&) //ok, �������������������
 */

class Figure  //������
{
public:
	//Լ��һ��ͳһ����(�ӿ�)��������ʹ�ã����������ʵ�֣�Ҫ��������ʵ����
	virtual void getArea() = 0;  // ���麯��
protected:
private:
};

class Circle : public Figure
{
public:
	Circle(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "Circular area ��" << 3.14 * a * a << endl;
	}
protected:
private:
	int a;
	int b;
};

class Tri : public Figure
{
public:
	Tri(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "triangle Area��" << a*b/2 << endl;
	}
protected:
private:
	int a;
	int b;
};


class Square : public Figure
{
public:
	Square(int a, int b)
	{
		this->a = a;
		this->b = b;
	}
	virtual void getArea()
	{
		cout << "Square Area:" << a * b << endl;
	}
protected:
private:
	int a;
	int b;
};

void ObjPlay(Figure *pBase)
{
	pBase->getArea();
}
int main()
{
	Figure* base = NULL;

	Circle c1(10, 20);
	Tri t1(20, 30);
	Square s1(50, 60);

	ObjPlay(&c1);
	ObjPlay(&t1);
	ObjPlay(&s1);
}

// ��Ҫʵ��������ͬ���̵Ľ����

// �⿪ż��������ģ�黮��(�㰴������ӿڰѹ���ʵ����)

//connect day_07 09 �������ڼ̳��е�Ӧ��


/**
 * �йض�̳е�˵����
 * 1 ���̿��������������ϵĶ�̳м�������ʹ�õ�
 * 2 ���ؼ̳д����Ĵ��븴����Զ����������ı�����
 * 3 ���ؼ̳жԴ���ά�����ϵ�Ӱ���������Ե�
 * 4 ����Ʒ����ϣ��κζ�̳ж������õ��̳д���
 */