#include <iostream>
using namespace std;

/* ����Ķ�̬�������ͷ� new �� delete ,����������������Ǻ��������ִ��Ч�ʸ� */
class Test
{
public:
	Test(int _a)
	{
		m_a = _a;
	}

	~Test()
	{
		cout << "~Test" << endl;
	}
	int getC()
	{
		 return m_b;
	}
	void AddC()
	{
		m_b++;
	}
private:
	int m_a;
	static int  m_b;
};
int Test::m_b = 0;
int main()
{
	int* p = (int *)malloc(sizeof(int));
	*p = 10;

	
	int* p2 = new int;
	*p2 = 20;
	

	int* p3 = new int(30);
	free (p3);

	int* pp = (int*)malloc(sizeof(int) * 10);
	pp[0] = 1;
	free(pp);

	int* pArray = new int[10];
	pArray[0] = 12;
	delete(pArray);

	Test *pT2 = new Test(10);	// ִ�й��캯��
	//delete( pT2);					// ִ����������

	cout << "m_b"<< pT2->getC() <<endl;
	pT2->AddC();
	Test* pT3 = new Test(10);
	cout << "m_b" << pT3->getC() << endl;
	//cout << *p << *p2 << *p3 << endl;
}	

/* 1.��malloc ������ڴ���delete�����ͷ��*/
//��û��
/* 2.��new ������ڴ� ��free �����ͷ���*/
//���� free �����ʱ����ٵ���һ����������