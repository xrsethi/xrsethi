#include <iostream>
using namespace std;


//��ϵͳ֧����չ
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
	junior_programmer jp((char *)"С��", (char*)"����", 4000);
	mid_programmer mp((char*)"С��", (char*)"�м�", 8600);
	adv_programmer ap((char*)"С��", (char*)"�߼�", 15000);

	CalProgSal(&jp);
	CalProgSal(&mp);
	CalProgSal(&ap);
	return 0;
}