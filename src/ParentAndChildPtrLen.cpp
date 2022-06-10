#include <iostream>
using namespace std;
/**
 * day_07 06 ����ָ��Ĳ���������ָ��Ĳ���
 * 
 * �� c++�У�ʹ������ָ��͸���ָ��ͬʱ���������������
 * 
 * ���ۣ�����P++������P++������ͬ����Ҫ����Ҫ��������ʹ�ö�̬
 */
class Parent
{
public:
	Parent(int a = 0)
	{
		this->a = a;
	}
	virtual void print()
	{
		cout << "My is Parent a = " << a << endl;

	}

protected:
private:
	int a;
};


class Child : public Parent
{
public:
	Child(int a = 0, int b = 0) : Parent(a)
	{
		this->b = b;
	}

	virtual void print()
	{
		cout << "My is Child b = " << b << endl;
	}
protected:
private:
	int b;
};
void HowToPlay(Parent* base)
{
	base->print();   //�ж�̬����
}
// һ��żȻ�ĳɹ����ȱ�Ȼ��ʧ�ܸ�����
// ָ��Ĳ���������ָ������;���
int main()
{
	Child* pC = NULL;
	Parent* pP = NULL;

	Child array[] = {Child(1, 5), Child(2,6), Child(3),Child(4)};
	pP = array;
	pC = array;
	pP->print();
	pC->print(); //������̬

	//pP++;		//��Child��ռ�ڴ�ʱû���⣬�������������ռ���ڴ棬��ôֱ�ӹҵ�
	pC++;
	pP = pC;
	pP->print();
	pC->print(); //������̬

	cout << "size Parent"  << sizeof(Parent) << "size Child" << sizeof(Child) << endl;
}

// ���͵�����͸���ָ�벽����һ�������⣬ѧ���̬ǧ��ע����������
// ���ۣ���̬�Ǹ���ָ��ָ��������� �� ���ಽ��++�������в�ͬ�ĸ���