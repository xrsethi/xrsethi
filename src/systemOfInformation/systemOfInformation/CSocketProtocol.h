#pragma once

class CSocketProtocol
{
public:
	CSocketProtocol()
	{
		;
	}
	virtual ~CSocketProtocol()  // 虚析构函数的细节
	{
		;
	}
	//客户端初始化 获取handle 上下
	virtual int cltSocketInit() = 0;
	 //客户端发送报文
	virtual int cltSocketSend( unsigned char* buf, int buflen) = 0;
	 //客户端收报文
	virtual int cltSocketRev(unsigned char* buf, int* buflen) = 0;
	 //客服端释放资源
	virtual int cltSocketDestory() = 0;
protected:
private:
};
