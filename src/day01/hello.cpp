#include "iostream"			//����C++ͷ�ļ�
using namespace std;		//ʹ�������ռ� std ��׼�������ռ�(����������ռ��ж����˺ܶ��׼����)


void main01()
{
	//printf("hello...");  c++Ҳ֧��c���Ե��﷨
	//cout ��׼��� �൱�� linux �� �ն˴��� << ���Ʋ������������Ѿ�����ζ��(C++�Ĳ�����������) endl c++�й涨Ϊ�س����� \n
	cout << "hello ... word "<< endl;
}

/*
*������ ��Բ���ܳ������
*���� ����뾶 r 
		����ܳ� s = 2*pai*r;
		������ m = pai*r*r;
*/

//����һ���ýṹ�������̣���Բ���ܳ������
void main02()
{
	double r = 0;
	double s = 0;

	cout << "������Բ�İ뾶��";
	cin >> r;
	cout << "r��ֵ�ǣ�" << r << endl;
	s = 3.14 * r * r;
	cout << "Բ�ε�����ǣ�" << s << endl;

}

//������������������̣���Բ���ܳ������
//c�ж���һ����������
struct Circle
{
	double m_s;
	double m_r;
};

//c++����һ���������� ��ĳ��� ��Ա�����ͳ�Ա����
class MyCircle
{
public:
	double m_s;	//���� ��Ա����
	double m_r; //Բ�İ뾶

public:
	void setR(double r) //��Ա����
	{
		m_r = r;
	}
	double getR() //��Ա����
	{
		return m_r;
	}
	MyCircle();
	~MyCircle();

protected:
private:

}; 

MyCircle::MyCircle()
{
}

MyCircle::~MyCircle()
{
}
//ʵ������
void main()
{
	MyCircle c1;//���ඨ����� c++�к��������ֶ���
}
3�ף�����