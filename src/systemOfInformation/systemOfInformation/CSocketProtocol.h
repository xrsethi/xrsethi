#pragma once

class CSocketProtocol
{
public:
	CSocketProtocol()
	{
		;
	}
	virtual ~CSocketProtocol()  // ������������ϸ��
	{
		;
	}
	//�ͻ��˳�ʼ�� ��ȡhandle ����
	virtual int cltSocketInit() = 0;
	 //�ͻ��˷��ͱ���
	virtual int cltSocketSend( unsigned char* buf, int buflen) = 0;
	 //�ͻ����ձ���
	virtual int cltSocketRev(unsigned char* buf, int* buflen) = 0;
	 //�ͷ����ͷ���Դ
	virtual int cltSocketDestory() = 0;
protected:
private:
};
