#include <iostream>
using namespace std;


//此系统支持扩展
class programmer
{
public:
	virtual void getSal() = 0;
protected:
private:
};

class junior_programmer: public programmer
{
public:
	junior_programmer(char *name, char *job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()
	{
		cout << name << " " << job << " " << sal << endl;
	}
protected:
private:
	char* name;
	char* job;
	int sal;
};

class mid_programmer : public programmer
{
public:
	mid_programmer(char* name, char* job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()
	{
		cout << name << " " << job << " " << sal << endl;
	}
protected:
private:
	char* name;
	char* job;
	int sal;
};

class adv_programmer : public programmer
{
public:
	adv_programmer(char* name, char* job, int sal)
	{
		this->name = name;
		this->job = job;
		this->sal = sal;
	}
	virtual void getSal()
	{
		cout << name << " " << job << " " << sal << endl;
	}
protected:
private:
	char* name;
	char* job;
	int sal;
};

void CalProgSal(programmer *base)
{
	base->getSal();
}

int main()
{
	junior_programmer jp((char *)"小王", (char*)"初级", 4000);
	mid_programmer mp((char*)"小张", (char*)"中级", 8600);
	adv_programmer ap((char*)"小李", (char*)"高级", 15000);

	CalProgSal(&jp);
	CalProgSal(&mp);
	CalProgSal(&ap);
	return 0;
}