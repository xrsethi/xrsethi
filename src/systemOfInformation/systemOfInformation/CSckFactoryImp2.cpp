#include <iostream>
using namespace std;
#include "CsckFactoryImp2.h"


//�ͻ��˳�ʼ�� ��ȡhandle ����
int CSokFactoryImp2::cltSocketInit()
{
	p = NULL;
	len = 0;

	return 0;
}

//�ͻ��˷��ͱ���
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

//�ͻ����ձ���
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

//�ͷ����ͷ���Դ
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