#include <iostream>
using namespace std;

//continue 18 引用 
/*
* 1. 引用的基础:可以媲美指针
* 
* 变量名回顾：
*	变量名实质上是内存（一段连续存储空间）的标号
* 问题1：对一段内存空间只能取一个别名嘛？答，未必，这个就可以用引用实现
* 
* 引用的概念：
*	a) 在c++中新增了引用的概念
*   b) 引用可以看做一个已定义变量的别名
*	c) 引用的语法： Type(类型)& name = var;
*	d) 引用做为函数参数那？（引用做为函数参数声明时不进行初始化）
*/

int  main91()
{
	int a = 10;
	int& b = a;		//引用案例，不能再用C语言的思考去思考这句话了
					/* 普通引用在声明时必须用其它变量进行初始化 */

	b = 100;		//相当于把a修改成员，c++检测到b是引用他就偷偷的这么做 *b = 100
	cout <<"a的值是：" << a << endl;
	cout <<"b的值是：" << b << endl;
	return 0;
}

//引用做函数参数：引用做函数参数时不用进行初始化
void myswap(int a, int b);
void mycppswap(int& a, int& b);
int main992()
{
	int x = 10;
	int y = 11;
	mycppswap(x, y);
	cout << "x = " << x << " y = " << y << endl;
	return 0;
}
//并不能实现，因为作用域不同，栈不同
void myswap(int a, int b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}
//此内容，用c++实现,交换成功，因为形参就是实参的别名，所以这样直接就把实参给改了
void mycppswap(int& a, int& b)
{
	int c = 0;
	c = a;
	a = b;
	b = c;
}

//continue 19 引用 复杂数据类型的引用（函数参数 ）

/*
*	printfT()、 printfT1()、 printfT2()、
*   三个函数有天然区别，见下述main()
*/
struct Teacher
{
	char name[64];
	int  age;
};
void printfT(Teacher* pT)
{
	cout << pT->age << endl;
}
void printfT1(Teacher& pT)
{
	cout << pT.age << endl;
	//pT.age = 45;
}
void printfT2(Teacher pT)
{
	cout << pT.age << endl;
	pT.age = 55;
}
int main22()
{
	Teacher t1;
	t1.age = 35;

	printfT(&t1);	//手动取地址
	printfT1(t1);	//（c++编译器帮我们取了地址）pT是t1的别名,修改pT相当于修改t1
	printfT2(t1);	//pT是形参，t1 copy 一份数据给pT 相当于 pT = t1;(这里有点意思，后续可见)
	printf("t1.age:%d \n",t1.age);
	return 0;
}

//continue 20 引用的意思和引用的本质
/*
*引用的意思：
*	1）引用做为其它变量的别名而存在，因此在一些场合可以代替指针
*	2）引用相对于指针来说具有更好的可读性和实用性
*引用的本质：
*	1) a 和 b就是同一块内存空间的别名
*	2) 引用占不占内存空间？答.占用，和普通指针一样,其实引用在c++内部实现就是一个常量指针 
*													   Type& name <--> Type * const name
*	3)c++编译器在编译过程中使用常量指针做为引用的内部实现，因此引用所占用的空间大小与指针相同
*	4)从使用的角度，引用会让人误会其只是一个别名，没有自己的存储空间。这是c++为了实用性而做出的细节隐藏
*  void func(int &a)			void func(int* const a)
*  {							{
*		a = 5;			c++->>		*a = 5;
*	}							}
*	5) 间接赋值的后两个条件写在一起（没必要理解，就和学英语语法一样，啥用没有）
*/	

int main12()
{
	int a = 10;
	int* b = NULL;

	printf("&a:%p \n", &a);
	printf("size a = %d \n", sizeof(b));
	printf("&b:%p \n", &b); // ====> a 和 b就是同一块内存空间的别名
	return 0;
}

//continue 21 函数返回值是引用（当左值右值）
int main()
{
	
	
	return 0;
}