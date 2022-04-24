#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
using namespace std;

/* 浅拷贝：就是指针变量赋值 （不会拷贝指针变量所指向的内存空间）*/

class BBB
{
public:
	BBB()
	{
	}
	BBB(const char *myp)
	{
		int  len = strlen(myp);
		p = (char *)malloc(len + 1);	// 丢失0可能会导致能存越界
		strcpy(p, myp);
		cout << "BBB()..." << endl;
	}
	BBB(const BBB& obj1)	// 解决方案，手工编写深拷贝构造函数
	{
		int len = obj1.len;
		p = (char*)malloc(len + 1);			// 成功实现内存越界 堆被破坏
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
	BBB obj2 = obj1;			// c++ 没写构造函数，则使用c++提供的默认函数
								// 而这个构造函数只是一个浅拷贝(只是指针的拷贝)
								// 对象析构的时候出现 coredump 现象
	BBB obj3;
	obj3 = obj1;				// 相当于把对象1的属性赋值给对象3，使用c++提供的 = 操作
	cout << "hello..." << endl;
	return 0;
}