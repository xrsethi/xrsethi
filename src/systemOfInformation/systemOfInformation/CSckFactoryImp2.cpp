#include <iostream>
using namespace std;
#include "CsckFactoryImp2.h"


//客户端初始化 获取handle 上下
int CSokFactoryImp2::cltSocketInit()
{
	p = NULL;
	len = 0;

	return 0;
}

//客户端发送报文
int CSokFactoryImp2::cltSocketSend(unsigned char* buf, int buflen)
{
	p = (unsigned char*)malloc(sizeof(unsigned char) * buflen);
	if (p == NULL)
	{
		printf("error: cltSocketSend p == NULL\n");
		return -1;
	}

	memcpy(p, buf, buflen);
	len = buflen;

	return 0;
}

//客户端收报文
int CSokFactoryImp2::cltSocketRev(unsigned char* buf, int* buflen)
{
	if ((buf == NULL) || (buflen == NULL))
	{
		return -1;
	}

	*buflen = this->len;
	memcpy(buf, this->p, this->len);
	return 0;
}

//客服端释放资源
int CSokFactoryImp2::cltSocketDestory()
{
	if (p != NULL)
	{
		free(p);
		p = NULL;
		len = 0;
	}
	return 0;
}