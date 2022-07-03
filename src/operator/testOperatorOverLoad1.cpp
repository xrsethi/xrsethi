#include <iostream>
using namespace std;

class Complex
{
public:
	Complex(int a = 0, int b = 0)
	{
		this->a = a;
		this->b = b;
	}

	~Complex()
	{
	}
	void printDoc()
	{
		cout << a << "+" << b << "i" << endl;
	}
public:
	
	int a;
	int b;
private:

};


Complex operator+(Complex &c1, Complex &c2)
{
	return Complex(c1.a + c2.a, c1.b + c2.b);
}



int main()
{
	Complex c1(1, 2), c2(3, 4);
	Complex c3;

	c3 = c1 + c2;
	c3.printDoc();

	return 0;
}