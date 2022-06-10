#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

/**
 * 接 18
 */

#include "CSocketProtocol.h"
#include "CsckFactoryImp1.h"
#include "CsckFactoryImp2.h"

int SocSendAndRec(CSocketProtocol* sp, unsigned char* in, int inlen, unsigned char* out, int* outlen)
{
	int ret = 0;
	ret = sp->cltSocketInit();
	if (ret != 0)
	{
		goto End;
	}
	ret = sp->cltSocketSend(in, inlen);
	ret = sp->cltSocketRev(out, outlen);
	ret = sp->cltSocketDestory();

End:
	ret = sp->cltSocketDestory();
	return 0;
}


//写一个框架
int main()
{
	int ret = 0;
	unsigned char in[4096];
	int inlen;
	unsigned char out[4096];
	int outlen = 0;

	strcpy((char *)in,"test socket program");
	inlen = 9;

	CSocketProtocol* sp = NULL;
	//sp = new CSokFactoryImp1;
	sp = new CSokFactoryImp2;
	ret = SocSendAndRec(sp, in, inlen, out, &outlen);
	if (ret != 0)
	{
		printf("func SokSendAndRec() err:%d \n", ret);
		return ret;
	}
	delete sp;  //想通过父类指针释放所有子类对象资源

	cout << "system of Information" << endl;

	return ret;
}