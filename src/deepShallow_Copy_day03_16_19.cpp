#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/* ǳ����������ָ�������ֵ �����´��ָ�������ָ����ڴ�ռ䣩*/

class BBB
{
public:
	BBB()
	{
	}
	BBB(const char *myp)
	{
		int  len = strlen(myp);
		p = (char *)malloc(len + 1);	// ��ʧ0���ܻᵼ���ܴ�Խ��
		strcpy(p, myp);
		cout << "BBB()..." << endl;
	}
	BBB(const BBB& obj1)	// ����������ֹ���д������캯��
	{
		int len = obj1.len;
		p = (char*)malloc(len + 1);			// �ɹ�ʵ���ڴ�Խ�� �ѱ��ƻ�
		strcpy(p, obj1.p);
	}
	~BBB()
	{
		if (p != NULL)
		{
			free(p);
			p = NULL;
			len = 0;
			cout << "~BBB()..." << endl;
		}
	}

private:
	char* p;
	int len;
};


int main()
{
	BBB obj1("aaassd");			
	BBB obj2 = obj1;			// c++ ûд���캯������ʹ��c++�ṩ��Ĭ�Ϻ���
								// ��������캯��ֻ��һ��ǳ����(ֻ��ָ��Ŀ���)
								// ����������ʱ����� coredump ����
	BBB obj3;
	obj3 = obj1;				// �൱�ڰѶ���1�����Ը�ֵ������3��ʹ��c++�ṩ�� = ����
	cout << "hello..." << endl;
	return 0;
}