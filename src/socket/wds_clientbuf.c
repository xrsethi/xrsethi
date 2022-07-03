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
    short 	state;
    short 	sdata;
    float	fdata;
} EthRxBuf_TypeDef;
DWORD WINAPI ThreadFunc(LPVOID p)
{
    EthRxBuf_TypeDef RxBuf;
    int ret = 0;
    printf("我是子线程， pid = %d\n", GetCurrentThreadId());   //输出子线程pid
    while (1)
    {
        ret = recv(sServer, &RxBuf, sizeof(RxBuf), 0);
        if (SOCKET_ERROR == ret)
        {
            printf("socket recv failed\n");
            closesocket(sServer);
            return -1;
        }
        printf("cmd = %d state = %d sdata = %d fdata = %f\n", RxBuf.cmd, RxBuf.state, RxBuf.sdata, RxBuf.fdata);
    }
    return 0;
}
int main(int argc, char* argv[])
{
    HANDLE hThread;
    DWORD  threadId;
    //初始化网络环境
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("WSAStartup failed\n");
        return -1;
    }
    // 初始化完成，创建一个TCP的socket
    sServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sServer == INVALID_SOCKET)
    {
        printf("socket failed\n");
        return -1;
    }
    //指定连接的服务端信息
    SOCKADDR_IN addrServ;
    addrServ.sin_family = AF_INET;
    addrServ.sin_port = htons(PORT);
    //客户端只需要连接指定的服务器地址，127.0.0.1是本机的回环地址
    addrServ.sin_addr.S_un.S_addr = inet_addr("192.168.0.6");

    // 服务器Bind 客户端是进行连接
    int ret = connect(sServer, (SOCKADDR*)&addrServ, sizeof(SOCKADDR));//开始连接
    if (SOCKET_ERROR == ret)
    {
        printf("socket connect failed\n");
        WSACleanup();
        closesocket(sServer);
        return -1;
    }
    //连接成功后，就可以进行通信了
    EthRxBuf_TypeDef TxBuf;

    hThread = CreateThread(NULL, 0, ThreadFunc, 0, 0, &threadId);
    //当服务端是recv的时候，客户端就需要send，若两端同时进行收发则会卡在这里，因为recv和send是阻塞的
    short i = 0; 
    short j = 0;
    printf("我是主线程， pid = %d\n", GetCurrentThreadId());  //输出主线程pid
    while (1)
    {
        i++;
        if(i == 1)
        {
            TxBuf.cmd = 0x0020;
            TxBuf.state = 0;
            TxBuf.sdata = 3;
            TxBuf.fdata = 4;
        }
	
#if 0
        if (i == 2)
        {
            TxBuf.cmd = 0x0030;
            TxBuf.state = 0;
            TxBuf.sdata = 0;
            TxBuf.fdata = 0;
        }
        if (i == 88)
        {
            TxBuf.cmd = 0x0031;
            TxBuf.state = 0;
            TxBuf.sdata = 0;
            TxBuf.fdata = 0;
        }

        if (i > 3)
        {
            TxBuf.cmd = 0x02;
            TxBuf.state = 0;
            TxBuf.sdata = 0x00;
            TxBuf.fdata = 0;
        }
#endif
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
        TxBuf.fdata = 0;
        TxBuf.sdata = 0;
        TxBuf.fdata= 0;
        if (i >= 100)
        {
            i = 0;
            break;
        }
    }
    while (1);
    //closesocket(sServer);
    //WSACleanup();
    return 0;

}