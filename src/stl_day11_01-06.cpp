/*
*	STL (��׼ģ���)
*/
#include <iostream>
using namespace std;

#include "vector"
#include "algorithm"

/*
*	STL �������
*		- ���� (Container):�൱������������...
* 		- �㷨 (Alorithm)
*  		- ������ (Iterator)
*  		- �º��� (Function object)
*  		- ������ (Adaptor)
*  		- �ռ������� (allocator)
*/

void funa()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(-2);
	v1.push_back(-5);

	for (vector<int>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << endl;
	}

	int numl = count(v1.begin(), v1.end(), 3);	/* 3 �ĸ��� */
	cout << "numl:" << numl << endl;

}
int main()
{
	funa();

	cout << "hello..." << endl;
	return 0;
}

/*
*	�㷨������Ҫ��ͷ�ļ�<algorithm> <numeric> �� <functional> ���
* 
*/