#include <stdio.h>
#include <winsock2.h>
#include <Windows.h>
#pragma warning(disable:4996)

#pragma comment(lib,"ws2_32.lib")
#define  PORT 1030

int main(int argc, char* argv[])
{
    //初始化网络环境
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("WSAStartup failed\n");
        return -1;
    }
    // 初始化完成，创建一个TCP的socket
    SOCKET sServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
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
    addrServ.sin_addr.S_un.S_addr = inet_addr("192.168.1.122");

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
    char szBuf[1024];
    memset(szBuf, 0, sizeof(szBuf));
    sprintf_s(szBuf, sizeof(szBuf), "Hello server");
    //当服务端是recv的时候，客户端就需要send，若两端同时进行收发则会卡在这里，因为recv和send是阻塞的
    int i = 0;
    while (1)
    {
        i++;
        sprintf_s(szBuf, sizeof(szBuf), "Hello server%d",i);
        ret = send(sServer, szBuf, strlen(szBuf), 0);
        if (SOCKET_ERROR == ret)
        {
            printf("socket send failed\n");
            closesocket(sServer);
            return -1;
        }
        //Sleep(200);
        memset(szBuf, 0, sizeof(szBuf));

        ret = recv(sServer, szBuf, sizeof(szBuf), 0);
        if (SOCKET_ERROR == ret)
        {
            printf("socket recv failed\n");
            closesocket(sServer);
            return -1;
        }
        printf("%s\n", szBuf);
        if (i > 1000000)
        {
            i = 0;
        }
    }
    closesocket(sServer);
    WSACleanup();
    return 0;

}