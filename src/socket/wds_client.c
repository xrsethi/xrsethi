#include <stdio.h>
#include <winsock2.h>
#include <Windows.h>
#pragma warning(disable:4996)

#pragma comment(lib,"ws2_32.lib")
#define  PORT 1030

int main(int argc, char* argv[])
{
    //��ʼ�����绷��
    WSADATA wsa;
    if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
    {
        printf("WSAStartup failed\n");
        return -1;
    }
    // ��ʼ����ɣ�����һ��TCP��socket
    SOCKET sServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
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
    char szBuf[1024];
    memset(szBuf, 0, sizeof(szBuf));
    sprintf_s(szBuf, sizeof(szBuf), "Hello server");
    //���������recv��ʱ�򣬿ͻ��˾���Ҫsend��������ͬʱ�����շ���Ῠ�������Ϊrecv��send��������
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