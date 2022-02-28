
#include <iostream>
using namespace std;

/*
*	continue day_02 02
*	指针的引用，指针是个引用
*/
struct Teacher
{
	char name[64];
	int age;
};

//在调用函数获取资源，需要二级指针（或者说给一级指针赋值个地址），也可称为二级指针做输出
int getTeacher(Teacher** p)		//二级指针模型，pT1是核心，p是传递值，例如p是
{								//0xaa11,也就是pT1的地址，装载pT1一个地址，实现
								//拿回资源，pT1也类似于卡车的车厢，p是卡车本身
								//卡车的车厢装载（指向）目标资源的地址，或者说
								//货物的名称，而名称在计算机中就是数据，就是变量，就是值

	Teacher* tmp = NULL;
	tmp = (Teacher*)malloc(sizeof(Teacher));
	if (tmp == NULL)
	{
		return -2;
	}
	tmp->age = 78;
	*p = tmp;
	// p是实参的地址 *实参的地址去间接的修改实参的值
}
void freeTeacher(Teacher* pT1)
{
	if (pT1 == NULL)
	{
		return;
	}
	free(pT1);
}
//c++里面指针的引用
int getTeacher2(Teacher* & myp)		//可把 Teacher* ==》int& myp
{
	//给myp赋值 相当于给main函数中的pT1赋值
	myp = (Teacher*)malloc(sizeof(Teacher));
	if (myp == NULL)
	{
		return -1;
	}
	myp->age = 36;
}
int mainM()
{
	Teacher* pT1 = NULL;
	//1 c语言中的二级指针
	getTeacher(&pT1);
	freeTeacher(pT1);
	cout << "age:" << pT1->age << endl;
	//2 c++中的引用(指针的引用)
	getTeacher2(pT1);
	cout << "age:" << pT1->age<< endl;
	freeTeacher(pT1);
	cout << "hello..." << endl;
	return 0;
}

/*
*	continue day_02 03
*	常引用和普通引用
*	常引用初始化方式
*	1）用变量初始化常引用
*	2）用字面量初始化常引用
*/

int main1()
{
	//普通引用
	int a = 10;
	int& b = a;

	//常引用
	int x = 20; 
	const int& y = x; //让变量拥有只读属性，做常数参数时比较大，不能通过y修改x
	x = 30;		//没问题
	//y = 40;		//不可修改
	cout << "x = "<< x << endl;
	cout << "7TH start" << endl;
	{
		const int d = 40;
		//int& m = 41;	//普通引用引用字面量 请问字面量有没有内存
						//引用就是给内存标号取多个别名，没内存啥都取不了
		const int& w = 42;	//2）这就是const 和引用在一起的一个特殊点
							//此时，引用w被使用，所以c++编译器透偷分配了空间，然后w指向这里

	}
	return 0;
}

void printTeacher(const Teacher*& p)
{
	//p->age = 40;
	//在这里只能使用常引用，但是我们不能修改
}
//void printTeacher2(const Teacher* const p) //相当于这么写
void printTeacher2(const Teacher& p)
{
	printf("p.age=%d",p.age);
	//在这里只能使用常引用，但是我们不能修改
}

int main()
{
	Teacher t1;
	t1.age = 10;

	printTeacher2(t1);

}