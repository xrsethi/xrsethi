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

//����һ���ýṹ�������̣���Բ���ܳ������ ����������ǲ�ͣ�ò���һ��һ���ģ��ӹ�һ��һ��������
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

//������������������̣���Բ���ܳ������ �����������ǲ�ͣ�Ĳ���������࣬�ӹ�����һ��һ�����ࣩ
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
	double getS()
	{
		m_s = 3.14 * m_r * m_r;
		return m_s;
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
//��ô����Ķ���
//vs���Կ�� F9�����öϵ� F10����һ�� F11�����뺯��
//����һ���������ͣ��������Ͳ�ռ���ڴ棬ʵ���Ż�
//c++ ������������c1�����c2����ģ�
void main03()
{
	MyCircle c1;//���ඨ����� c++�к��������֣�����
	double r;

	cout << "������c1Բ�εð뾶��";
	cin >> r;
	c1.setR(r);
	cout << "c1Բ�ε�����ǣ�" << c1.getS() << endl;
}

void main()
{


}
day01 04��ʼ ���� 