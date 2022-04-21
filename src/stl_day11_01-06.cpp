/*
*	STL (标准模板库)
*/
#include <iostream>
using namespace std;

#include "vector"
#include "algorithm"

/*
*	STL 六大组件
*		- 容器 (Container):相当于链表，二叉树...
* 		- 算法 (Alorithm)
*  		- 迭代器 (Iterator)
*  		- 仿函数 (Function object)
*  		- 适配器 (Adaptor)
*  		- 空间配置器 (allocator)
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

	int numl = count(v1.begin(), v1.end(), 3);	/* 3 的个数 */
	cout << "numl:" << numl << endl;

}
int main()
{
	funa();

	cout << "hello..." << endl;
	return 0;
}

/*
*	算法部分主要由头文件<algorithm> <numeric> 和 <functional> 组成
* 
*/