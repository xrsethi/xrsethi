#pragma once
#include <iostream>
using namespace std;
#include "CSocketProtocol.h"

//�����������麯����д
class CSokFactoryImp2 :public CSocketProtocol
{
public:
	//�ͻ��˳�ʼ�� ��ȡhandle ����
	virtual int cltSocketInit();
	//�ͻ��˷��ͱ���
	virtual int cltSocketSend(unsigned char* buf, int buflen);
	//�ͻ����ձ���
	virtual int cltSocketRev(unsigned char* buf, int* buflen);
	//�ͷ����ͷ���Դ
	virtual int cltSocketDestory();
protected:
private:
	unsigned char* p;
	int len;

};