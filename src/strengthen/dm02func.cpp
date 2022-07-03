#include <iostream>
#include <string.h>
using namespace std;

/**
 * ���ַ������������
 */

/**
 * ����ģ��ı��ʣ����Ͳ����� ����.....
 */


template <typename T> // template <typename T, typename T2>
int mySort(T* array, int size)
{
	T tmp;
	if (array == NULL)
	{
		return -1;
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (array[i] < array[j])
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
			}
		}
	}

	return 0;
}


/**
 * ����ģ�����Ϻ������� :��������ϸ������ƥ��
 * 
 * 1 ���ȿ�����ͨ���� 
 * 2 �������Ҫʹ��ģ�庯����ͨ�� Mac<>(a,n) ͨ���ղ����б������ʾ�ĵ���
 * 3 �������ģ��������õ�ƥ�� ʹ�ú���ģ��
 * 4 ������ͨ���� ������ʽת�� 
 * 
 * ���ۣ�C++�������α��룺��һ�α������ģ����дʷ��������䷨������������ªģ��
 *						  �ڶ��α�����ݵ������������庯��ԭ�ͣ����ݲ������Ͳ��������滻��
 */

int mySort(int* array, int size)
{
	cout << "size =" << size << endl;
	cout << "��ͨ����..." << endl;

	return 0;
}

template <typename T>
int myPrint(T* array, short size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}

int main()
{
	int tmp = 5 / 2;
	{
		int myarray[] = { 11, 33, 44, 44, 22, 2, 4, 5, 6 };

		myPrint(myarray, sizeof(myarray) / sizeof(*myarray));
		mySort(myarray, sizeof(myarray) / sizeof(*myarray));
		myPrint(myarray, sizeof(myarray) / sizeof(*myarray));
	}

	{
		char buf[] = "asfgohijdgfsaouihjojhi;gfdsas";
		short len = strlen(buf);
		mySort(buf, len);
		myPrint(buf, len);
	}
	cout << "My Project" << endl;
	return 0;
}