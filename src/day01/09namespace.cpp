#include "iostream"			//包含C++头文件
using namespace std;        //文件 iostream 没有引入标准的 std:需要我们程序员自己写,如果不写需要显示的引入
//namespace ：为避免在大规模程序设计中以及在程序员使用各种各样的C++库时，这些标识符命名命名发生冲突 c++引入关键字 namespace,可以更好地控制标识符的作用域
/*
* c++命名空间的定义：namespace name { ... }
* 命名空间的使用 using namespace NamespaceA 一般使用情况
*/

void main01()
{
	std::cout << "namespace test" << std::endl;
}

//定义命名空间
namespace namespaceA
{
	int a = 0;
}
namespace namespaceB
{
	int a = 20;
	namespace namespaceC
	{
		struct Teacher
		{
			char name[10];
			int age;
		};
	}
}

//使用命名空间
void main02()
{
	using namespace namespaceA;
	using namespace namespaceB;
	cout << namespaceA::a << endl;
	cout << namespaceB::a << endl;

	namespaceB::namespaceC::Teacher t1;
	t1.age = 12;
	cout << t1.age << endl;

}

/*
* c++标准为了和c区分开，也为了正确使用命名空间，规定头文件不适用后缀 .h
* 如何成为高手，就得去源码里面看 看不懂就慢慢看，什么不懂就查什么
* 早期版本的c++他用的时 iostream.h 被人耻笑，说速度慢，继续优化去掉了.h 
* 
*/
//接 day01 10