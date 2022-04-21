/* Object Construction And Destruction						:����Ĺ��������  */
/* Constructor And Destructor;Construction And Destruction	:���캯������������*/

#include <iostream>
using namespace std;

/*
*	c++ ����Ĺ��������������һ������ʱ��������Ҫ��ĳЩ��ʼ������������������ݳ�Ա����ֵ��
*	Ϊ���������⣬c++ �������ṩ�˹��캯�����������ĳ�ʼ�������캯�����������Ա������Ҫ
*	�û����������������ڽ�������ʱ�Զ�ִ��
* 
*	1.����������Ļ�������
*   day_03 05c 
*	day_03 06c ��������������ڵ����壺��ʾ���ó�ʼ�����ȽϷ���������Щ������ʾ���������飬
*	���Ի���ѡ�������������
* 
*	���û���ṩ�����������������c++����Ĭ�Ϲ��캯����
*	���û���ṩ����������c++Ҳ���ṩĬ�ϵĿ������캯��
*/

class MyClass
{
public:
	MyClass();	//���캯�����ࣺ1.�޲ι��� 2.�вι��� 3.��ֵ����Ҳ�п�������
	MyClass(int a, int b);	//�����вι��캯�� MyClass t1(1��2);
	MyClass(const MyClass& obj);	//�������캯��(copy���캯��)
	~MyClass();

private:
protected:
	int m_a;
	int m_b;
	//char* pDate;		//c++�������Ұָ��
};

MyClass::MyClass()
{
	m_a = 0;
	m_b = 0;
	cout << "Constructor MyClass ..." << endl;
}
MyClass::MyClass(int a, int b)
{
	m_a = a;
	m_b = b;
	cout << "Constructor MyClass1..." << endl;
}
MyClass::MyClass(const MyClass& obj)
{
	cout << "Constructor MyClass2..." << endl;
}

MyClass::~MyClass()
{
	cout << "Destructor ..." << endl;
}

void objplay()
{
	//�ȴ����Ķ�����ͷ�
	MyClass t1();		//1 ��ʱ��û�б�����������ö����г�Ա����ʱ�ͻᱩ©����
	MyClass t2(1, 2);	//2 �ɳɹ����� ,�� MyClass t1 = (1, 2) ������ c++ �� = ���������й�����ǿ
	//3 �ֶ����ù���
	MyClass t4 = MyClass(2,1);	//������������������������ȥ����
	t2 = t4;			//����ĳ�ʼ���Ͷ���ĸ�ֵ��������ͬ�ĸ���
	//MyClass t2;
}

int main()
{
	objplay();
	cout << "hello..." << endl;
	return 0;
}


/*
*	day_03 07c ��ʼҪ���淶�ʼǱ�д�����������Ժ����
*	1.�Ѵ洢day_0xx ȥ����ֱ�Ӵ�Դ�ļ���Դ�ļ������ȱ��ѧϰλ��
*	2.�淶��дԴ�ļ��ļ���������������֪ʶ�㶨λ�����ڲ��ң������ļ������ȷ���ļ�����
*	3.�ļ��ڱ�д����Ҫ�й������֣��������Ժ�鿴��Ҳδ������⵱ʱ�����ݣ���Ŀ�������������ͣ�
*	ͻ��֪ʶ������
*/