
#include <iostream>
using namespace std;
// continue day06_17
class Parent
{
public:

	Parent(int a)
	{
		this->a = a;
		cout <<"Parent a = " << a << endl;
	}
	//virtual void print()
	void print()
	{
		cout << "Parent ��ӡa =" << a << endl;
	}
	~Parent()
	{
	}
protected:
private:
	int a;
};
class Child : public Parent
{
public:
	Child(int b) : Parent(10)
	{
		this->b = b;
		cout << "Child b = " << b << endl;
	}
	void print()
	{
		cout << "Parent ��ӡb =" << b << endl;
	}
protected:
private:
	int b;
};


int main()
{
	Parent* base = NULL;
	Child* Cp = NULL;
	cout << "Parent ? base =" << sizeof(base) << endl;
	Parent p1(20);
	Child c1(30);

	base = &p1;
	cout << "Parent ? base =" << sizeof(c1) << endl;
	base->print(); //ִ�и����ӡ����

	base = &c1;
	base->print(); //ִ��˭�ĺ���
	Cp = &c1;
	Cp->print();
	c1.print();
	cout << "--------------------------" << endl;
	{
		Parent& base2 = p1;
		base2.print();

		Parent& base3 = c1; //base3 �� c1 �ı���
		base3.print(); 
	}
	//ͨ�����ϴ�ӡ������������ ��̬
	//c++ ͨ�� virtual�ؼ��ֶԶ�̬����֧��
	//�� ������д��virtual�ؼ��֣���ʵ�ֶ�̬�������п�д�ɲ�д��һ��д�ϣ����������Ķ���
	return 0;
}


/*
* ��ֵ���ݹ���
* 1 ����������Ķ��󸳸�������Ķ���
* 2 ������Ķ�����Ը�������Ķ���
* 3 �ɽ�������Ķ����ָ�븳�������ָ�����
* 4 �����������Գ�ʼ�������͵�����
*/

/*
* ��̬���ڵ�3������
* 1 �̳��Ƕ�̬�Ļ���
* 2 Ҫ���麯����д
* 3 �ø���ָ��ָ�����������ν����̨
*/
// ָ����ڵ���������Ǽ�Ӹ�ֵ
/*
* ��̬�����ģʽ�Ļ�������̬�ǿ�ܵĻ���
* 
* ��̬����Ͷ�̬����(��̬�����ǳٰ󶨣���̬�����Ǳ����ڼ��)
*/