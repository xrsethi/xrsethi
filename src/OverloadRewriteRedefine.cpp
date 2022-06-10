#include <iostream>
using namespace std;


class Parent
{
public:
	virtual void func()							//���� 1
	{
		cout << "func() do...." << endl;
	}
	virtual void func(int i)					//���� 2
	{
		cout << "func() do...." << i << endl;
	}
	virtual void func(int i, int j)				//���� 3
	{
		cout << "func() do...." << i << "  "<< j << endl;
	}
protected:
private:
	
};

class Child : public Parent
{
public:
	virtual void func(int i, int j)
	{
		cout << "func() do...." << i << "  " << j << endl;
	}
	virtual void func(int i, int j, int k)
	{
		cout << "func() do...." << i << "  " << j << endl;
	}
protected:
private:
};


int main()
{
	Child c1;
	//c1.func();
	/*
	* func ���������֣��������з��������Ƹ��ǣ�����ĺ���������ռ���˸��ຯ�������ֵ�λ��
	* ��Ϊ�������Ѿ�����func���ֵ�������ʽ
	* ��������ʼ����������func���� ����������û��0��������func����
	*/
}

/**
 *	�������أ�
 *		������ͬһ�����н���
 *		�����޷����ظ���ĺ���������ͬ�������������Ƹ���
 *		�������ڱ����ڼ���ݲ������ͺ͸���������������
 *	������д��
 *		���뷢���ڸ�����֮��
 *		���Ҹ����������еĺ���������ȫ��ͬ��ԭ��
 *		������·��ʹ��virtual����֮���ܹ�������̬(�����ʹ��virtual���ǽ��ض���)
 *		��̬���������ڼ���ݾ����������;�����������
 */