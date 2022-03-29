#include <stdio.h>
#include <winsock2.h>
#include <Windows.h>
DWORD WINAPI ThreadFunc(LPVOID);

#pragma warning(disable:4996)
#pragma comment(lib,"ws2_32.lib")
#define  PORT 1030
SOCKET sServer;
typedef struct
{
    short	cmd;
    short 	len;
    short 	data;
} EthRxBuf_TypeDef;
DWORD WINAPI ThreadFunc(LPVOID p)
{
    EthRxBuf_TypeDef RxBuf;
    int ret = 0;
    printf("�������̣߳� pid = %d\n", GetCurrentThreadId());   //������߳�pid
    while (1)
    {
        ret = recv(sServer, &RxBuf, sizeof(RxBuf), 0);
        if (SOCKET_ERROR == ret)
        {
            printf("socket recv failed\n");
            closesocket(sServer);
            return -1;
        }
        printf("cmd = %d len = %d data = %d\n", RxBuf.cmd, RxBuf.len, RxBuf.data);
    }
    return 0;
}
int main(int argc, char* argv[])
{
    HANDLE hThread;
    DWORD  threadId;
    //��ʼ�����绷��
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("WSAStartup failed\n");
        return -1;
    }
    // ��ʼ����ɣ�����һ��TCP��socket
    sServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sServer == INVALID_SOCKET)
    {
        printf("socket failed\n");
        return -1;
    }
    //ָ�����ӵķ������Ϣ
    SOCKADDR_IN addrServ;
    addrServ.sin_family = AF_INET;
    addrServ.sin_port = htons(PORT);
    //�ͻ���ֻ��Ҫ����ָ���ķ�������ַ��127.0.0.1�Ǳ����Ļػ���ַ
    addrServ.sin_addr.S_un.S_addr = inet_addr("192.168.1.122");

    // ������Bind �ͻ����ǽ�������
    int ret = connect(sServer, (SOCKADDR*)&addrServ, sizeof(SOCKADDR));//��ʼ����
    if (SOCKET_ERROR == ret)
    {
        printf("socket connect failed\n");
        WSACleanup();
        closesocket(sServer);
        return -1;
    }
    //���ӳɹ��󣬾Ϳ��Խ���ͨ����
    EthRxBuf_TypeDef TxBuf;

    hThread = CreateThread(NULL, 0, ThreadFunc, 0, 0, &threadId);
    //���������recv��ʱ�򣬿ͻ��˾���Ҫsend��������ͬʱ�����շ���Ῠ�������Ϊrecv��send��������
    short i = 0;
    printf("�������̣߳� pid = %d\n", GetCurrentThreadId());  //������߳�pid
    while (1)
    {
        i++;
        TxBuf.cmd = i;
        TxBuf.len = 3;
        TxBuf.data = i + 5;
        ret = send(sServer, &TxBuf, sizeof(TxBuf), 0);
        if (SOCKET_ERROR == ret)
        {
            printf("socket send failed\n");
            closesocket(sServer);
            return -1;
        }
        Sleep(2000);

#if 0
        ret = recv(sServer, &RxBuf, sizeof(RxBuf), 0);
        if (SOCKET_ERROR == ret)
        {
            printf("socket recv failed\n");
            closesocket(sServer);
            return -1;
        }
        printf("cmd = %d len = %d data = %d\n", RxBuf.cmd, RxBuf.len, RxBuf.data);
        ret = recv(sServer, &RxBuf, sizeof(RxBuf), 0);
        if (SOCKET_ERROR == ret)
        {
            printf("socket recv failed\n");
            closesocket(sServer);
            return -1;
        }
        printf("cmd = %d len = %d data = %d\n", RxBuf.cmd, RxBuf.len, RxBuf.data);
#endif
        TxBuf.cmd = 0;
        TxBuf.len = 0;
        TxBuf.data = 0;
        if (i > 10)
        {
            i = 0;
            break;
        }
    }
    //closesocket(sServer);
    //WSACleanup();
    return 0;

}