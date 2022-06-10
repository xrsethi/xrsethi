#pragma once
#include <iostream>
using namespace std;
#include "CSocketProtocol.h"

//任务就是完成虚函数重写
class CSokFactoryImp2 :public CSocketProtocol
{
public:
	//客户端初始化 获取handle 上下
	virtual int cltSocketInit();
	//客户端发送报文
	virtual int cltSocketSend(unsigned char* buf, int buflen);
	//客户端收报文
	virtual int cltSocketRev(unsigned char* buf, int* buflen);
	//客服端释放资源
	virtual int cltSocketDestory();
protected:
private:
	unsigned char* p;
	int len;

};