#include "iostream"			//包含C++头文件
using namespace std;		//使用命名空间 std 标准的命名空间(在这个命名空间中定义了很多标准定义)


void main01()
{
	//printf("hello...");  c++也支持c语言的语法
	//cout 标准输出 相当于 linux 的 终端窗口 << 左移操作符在这里已经变了味道(C++的操作符的重载) endl c++中规定为回车换行 \n
	cout << "hello ... word "<< endl;
}

/*
*描述： 求圆的周长和面积
*处理： 输入半径 r 
		输出周长 s = 2*pai*r;
		输出面积 m = pai*r*r;
*/

//方法一：用结构化程序编程，求圆的周长和面积
void main02()
{
	double r = 0;
	double s = 0;

	cout << "请输入圆的半径：";
	cin >> r;
	cout << "r的值是：" << r << endl;
	s = 3.14 * r * r;
	cout << "圆形的面积是：" << s << endl;

}

//方法二：用面向对象编程，求圆的周长和面积
//c中定义一个数据类型
struct Circle
{
	double m_s;
	double m_r;
};

//c++定义一个数据类型 类的抽象 成员变量和成员函数
class MyCircle
{
public:
	double m_s;	//属性 成员变量
	double m_r; //圆的半径

public:
	void setR(double r) //成员函数
	{
		m_r = r;
	}
	double getR() //成员函数
	{
		return m_r;
	}
	MyCircle();
	~MyCircle();

protected:
private:

}; 

MyCircle::MyCircle()
{
}

MyCircle::~MyCircle()
{
}
//实例化类
void main()
{
	MyCircle c1;//用类定义变量 c++中好听的名字对象
}
3阶：》》