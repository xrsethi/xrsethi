#include <iostream>
using namespace std;

/* 对象的动态建立和释放 new 和 delete ,它们是运算符，不是函数，因此执行效率高 */
class Test
{
public:
	Test(int _a)
	{
		m_a = _a;
	}

	~Test()
	{
		cout << "~Test" << endl;
	}
	int getC()
	{
		 return m_b;
	}
	void AddC()
	{
		m_b++;
	}
private:
	int m_a;
	static int  m_b;
};
int Test::m_b = 0;
int main()
{
	int* p = (int *)malloc(sizeof(int));
	*p = 10;

	
	int* p2 = new int;
	*p2 = 20;
	

	int* p3 = new int(30);
	free (p3);

	int* pp = (int*)malloc(sizeof(int) * 10);
	pp[0] = 1;
	free(pp);

	int* pArray = new int[10];
	pArray[0] = 12;
	delete(pArray);

	Test *pT2 = new Test(10);	// 执行构造函数
	//delete( pT2);					// 执行析构函数

	cout << "m_b"<< pT2->getC() <<endl;
	pT2->AddC();
	Test* pT3 = new Test(10);
	cout << "m_b" << pT3->getC() << endl;
	//cout << *p << *p2 << *p3 << endl;
}	

/* 1.用malloc 分配的内存用delete可以释放嘛？*/
//都没事
/* 2.用new 分配的内存 用free 可以释放吗？*/
//但是 free 对象的时候会少调用一个析构函数