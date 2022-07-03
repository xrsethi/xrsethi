#include <iostream>
using namespace std;
/**
 * c++ 风格类型转换,提供4种类型操作符
 * 
 * 1. static_cast 静态类型转换。如int转换char
 *	静态类型转换 编译时c++编译器会做类型检查，可用编译器检查
 * 2. reinterpreter_cast 重新解释类型.强制类型转换
 * 3. dynamic_cast 命名上理解动态类型转换
 *	命名上理解是动态类型转换。如子类和父类之间的多态类型转换
 * 4. const_cast 字面理解去掉const属性。c++中的const是符号表机制
 * 
 *  统一格式： TYPE B = static_cast<TYPE> (a)
 */

int main11()
{
	double dPi = 3.1415926;
	int num1 = (int)dPi;  //c 类型
	int num3 = dPi;  //c 类型
	int num2 = static_cast<int>(dPi);

	//char* p1 = "hello... itcast";
	int* p2 = NULL;
	//p2 = p1;
	//p2 = reinterpret_cast<int*>(p1);强制类型转换
	/* 总结：通过reinterpret_cast<>()和static_cast<>()把c语言的强制类型转换都覆盖了*/
	cout << "num1:" << num1 << endl;
	cout << "num2:" << num2 << endl;
	cout << "My Project" << endl;

	/* dynamic_cast */
	
	return 0;


}

/* dynamic_cast */
class Animal
{
public:
	virtual void cry() = 0;
private:

};

class Dog : public Animal
{
public:
	virtual void cry()
	{
		cout << "汪汪" << endl;
	}
	void doHome()
	{
		cout << "看家" << endl;
	}
protected:
private:
};

class Cat : public Animal
{
public:
	virtual void cry()
	{
		cout << "喵喵" << endl;
	}
	void doThing()
	{
		cout << "抓老鼠" << endl;
	}
protected:
private:
};


void playObj(Animal *base)
{
	//base->cry(); //1 有继承 2 虚函数重写 3 父类指针 指向子类对象 ==>多态发生
	//dynamic_cast 可用于运行时类型识别
	Dog* pDog = dynamic_cast<Dog*>(base);
	//父类对象 ===> 子类对象，向下转型
	if (pDog !=NULL)
	{
		pDog->doHome();
	}
	pDog->doHome();
}


/**
 * 提出需求：能识别子类对象
 */

int main()
{
	Dog d1;
	Cat c1;



	playObj(&d1);
	playObj(&c1);
	cout << "Test ...." << endl;
	return 0;
}