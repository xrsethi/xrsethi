#include <iostream>
using namespace std;
/**
 * c++ �������ת��,�ṩ4�����Ͳ�����
 * 
 * 1. static_cast ��̬����ת������intת��char
 *	��̬����ת�� ����ʱc++�������������ͼ�飬���ñ��������
 * 2. reinterpreter_cast ���½�������.ǿ������ת��
 * 3. dynamic_cast ��������⶯̬����ת��
 *	����������Ƕ�̬����ת����������͸���֮��Ķ�̬����ת��
 * 4. const_cast �������ȥ��const���ԡ�c++�е�const�Ƿ��ű����
 * 
 *  ͳһ��ʽ�� TYPE B = static_cast<TYPE> (a)
 */

int main11()
{
	double dPi = 3.1415926;
	int num1 = (int)dPi;  //c ����
	int num3 = dPi;  //c ����
	int num2 = static_cast<int>(dPi);

	//char* p1 = "hello... itcast";
	int* p2 = NULL;
	//p2 = p1;
	//p2 = reinterpret_cast<int*>(p1);ǿ������ת��
	/* �ܽ᣺ͨ��reinterpret_cast<>()��static_cast<>()��c���Ե�ǿ������ת����������*/
	cout << "num1:" << num1 << endl;
	cout << "num2:" << num2 << endl;
	cout << "My Project" << endl;

	/* dynamic_cast */
	
	return 0;


}

/* dynamic_cast */
class Animal
{
public:
	virtual void cry() = 0;
private:

};

class Dog : public Animal
{
public:
	virtual void cry()
	{
		cout << "����" << endl;
	}
	void doHome()
	{
		cout << "����" << endl;
	}
protected:
private:
};

class Cat : public Animal
{
public:
	virtual void cry()
	{
		cout << "����" << endl;
	}
	void doThing()
	{
		cout << "ץ����" << endl;
	}
protected:
private:
};


void playObj(Animal *base)
{
	//base->cry(); //1 �м̳� 2 �麯����д 3 ����ָ�� ָ��������� ==>��̬����
	//dynamic_cast ����������ʱ����ʶ��
	Dog* pDog = dynamic_cast<Dog*>(base);
	//������� ===> �����������ת��
	if (pDog !=NULL)
	{
		pDog->doHome();
	}
	pDog->doHome();
}


/**
 * ���������ʶ���������
 */

int main()
{
	Dog d1;
	Cat c1;



	playObj(&d1);
	playObj(&c1);
	cout << "Test ...." << endl;
	return 0;
}