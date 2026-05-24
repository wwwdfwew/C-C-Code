#include<iostream>
#include<string>
#include<cstdio>
#include<WinSock2.h>
#include<Windows.h>
#include <WS2tcpip.h>

#pragma warning(disable:4996)
#pragma comment(lib, "ws2_32.lib")
uint16_t serverPort = 8888;
std::string serverIp = "124.223.106.168";
int main()
{
	WSAData wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);

    //创建socket
    SOCKET sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        std::cout << "client socket error" << std::endl;
    }
    std::cout << "client socket success" << std::endl;

  /*  bind socket:客户端绑定socket不需要显示的写出来
    发送消息
    1）服务端信息*/
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(serverPort);
    server.sin_addr.s_addr = inet_addr(serverIp.c_str());
    while (1) {
        std::string buf;
        std::cout << "send message:";
        std::getline(std::cin, buf);
        int  m = sendto(sockfd, buf.c_str(), (int)buf.size(), 0, (const struct sockaddr*)&server, sizeof(server));
        if (m == -1)
        {
            std::cout << "sendto fail" << std::endl;
        }
        std::cout << "sendto success" << std::endl;
        //接收消息
        char buff[1024];
        struct sockaddr_in client;
        int  addrlen = sizeof(client);
        int  n = recvfrom(sockfd, buff, 1023, 0, (struct sockaddr*)&client, &addrlen);
        if (n > 0)
        {
            buff[n] = 0;
            std::cout << buff << std::endl;
        }
        else
            std::cout << "recv fail" << std::endl;

    }

    closesocket(sockfd);
	WSACleanup();
	return 0;
}