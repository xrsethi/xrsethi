#pragma once

#include <iostream>
using namespace std;
class Array
{
public:
	Array()
	{
	}
	Array(const Array& obj);
	~Array()
	{
	}
public:
	void setData(int index, int valude);
	int getData(int index);
	int length();
private:

};
