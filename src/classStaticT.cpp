#include <iostream>
#include <string>
#include "test.h"

using namespace std;

#define DEBUG


void MyLog(string logger)
{
#if defined(DEBUG)
	cout << "Logger In This:" << logger << endl;
#endif
}

int main(int argc, char** argv)
{

#if defined(WIN32)
	cout << "this device is WIN32" << endl;
#endif 

#if !defined(WIN32)
	cout << "this device is not WIN32" << endl;
#endif 

#if defined(WIN32)&&defined(LINUX)
	cout << "win32 and linux" << endl;
#endif
	MyLog("1");
	MyLog("2");
	MyLog("3");
#undef DEBUG 
	MyLog("4");

	system("pause");
}

/**
 * continue 05
 */