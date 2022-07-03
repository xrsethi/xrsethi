#include <iostream>
#include <string.h>
using namespace std;

/**
 * 对字符数组进行排序
 */

/**
 * 函数模板的本质：类型参数化 方便.....
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
 * 函数模板遇上函数重载 :将会进行严格的类型匹配
 * 
 * 1 优先考虑普通函数 
 * 2 如果必须要使用模板函数可通过 Mac<>(a,n) 通过空参数列表进行显示的调用
 * 3 如果函数模板产生更好的匹配 使用函数模板
 * 4 调用普通函数 可以隐式转换 
 * 
 * 结论：C++进行两次编译：第一次编译根据模板进行词法分析，句法分析，长生简陋模型
 *						  第二次编译根据调用语句产生具体函数原型（根据参数类型产生具体替换）
 */

int mySort(int* array, int size)
{
	cout << "size =" << size << endl;
	cout << "普通函数..." << endl;

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