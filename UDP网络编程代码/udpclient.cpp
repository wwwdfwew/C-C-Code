
#include<iostream>
#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include <netinet/in.h>
#include<strings.h>
#include<string>
#include <arpa/inet.h>
#include <arpa/inet.h>


void Usage(const std::string& process)
{
    std::cout << "Usage: " << process << " server_ip server_port" << std::endl;
}
int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        Usage(argv[0]);
        return 1;
    }
    // ./udp_client server_ip server_port


    std::string serverIp = argv[1];
    uint16_t serverPort = std::stoi(argv[2]);

    //创建socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0)
    {
        std::cout << "client socket error" << std::endl;
    }
    std::cout << "client socket success" << std::endl;

    //bind socket:客户端绑定socket不需要显示的写出来
    //发送消息
    //1）服务端信息
    struct sockaddr_in server;
    bzero(&server, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(serverPort);
    server.sin_addr.s_addr = inet_addr(serverIp.c_str());
    while (1) {
        std::string buf;
        std::cout << "send message:";
        std::getline(std::cin, buf);
        ssize_t m = sendto(sockfd, buf.c_str(), buf.size(), 0, (const struct sockaddr*)&server, sizeof(server));
        if (m == -1)
        {
            std::cout << "sendto fail" << std::endl;
        }
        std::cout << "sendto success" << std::endl;
        //接收消息
        char buff[1024];
        struct sockaddr_in client;
        socklen_t addrlen = sizeof(client);
        ssize_t n = recvfrom(sockfd, buff, 1023, 0, (struct sockaddr*)&client, &addrlen);
        if (n > 0)
        {
            buff[n] = 0;
            std::cout << buff << std::endl;
        }
        else
            std::cout << "recv fail" << std::endl;

    }
    return 0;
}