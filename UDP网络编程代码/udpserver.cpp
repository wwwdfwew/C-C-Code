#include<iostream>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<strings.h>
#include<string>
#include<arpa/inet.h>


const std::string defaultip = "0.0.0.0";
const uint16_t defaultport = 8888;

class udpserver
{
public:
    //构造函数
    udpserver(const std::string& ip = defaultip, const uint16_t port = defaultport) :ip(ip), port(port)
    {

    }
    //初始化函数
    void Init()
    {
        //1.创建套接字
        sockfd = socket(AF_INET, SOCK_DGRAM, 0);
        if (sockfd < 0)
        {
            std::cout << "socket error" << std::endl;
            exit(1);
        }
        std::cout << "socket success" << std::endl;
        //2.bind socket
        struct sockaddr_in local;
        bzero(&local, sizeof(local));
        local.sin_family = AF_INET;
        local.sin_port = htons(port);
        local.sin_addr.s_addr = inet_addr(ip.c_str());
        socklen_t len = sizeof(local);
        int n = bind(sockfd, (const struct sockaddr*)&local, len);
        if (n < 0)
        {
            std::cout << "bind fail" << std::endl;
            exit(1);
        }
        std::cout << "bind success" << std::endl;
    }
    //运行函数

    char buffer[1024];
    void Run()
    {
        bool isrunning = true;
        while (isrunning)
        {

            //接收客户端消息
            struct sockaddr_in client;//用来接收客户端port和ip
            socklen_t addrlen = sizeof(client);//接收结构体长度
            ssize_t n = recvfrom(sockfd, buffer, sizeof(buffer) - 1, 0, (struct sockaddr*)&client, &addrlen);
            if (n > 0)
            {
                buffer[n] = 0;
                std::cout << buffer << std::endl;
            }
            else
                std::cout << "recv fail" << std::endl;


            //处理客户端消息
            std::string bf = buffer;
            std::string buf = "send t0" + bf;
            //将处理后的消息发送回客户端
            auto x = sendto(sockfd, buf.c_str(), buf.size(), 0, (const struct sockaddr*)&client, addrlen);
            if (x > 0)
            {
                std::cout << "sendto success" << std::endl;
            }
            else
                std::cout << "sendto fail" << std::endl;

        }
    }
    //析构函数
    ~udpserver()
    {

    }
private:
    int sockfd;
    std::string ip;
    uint16_t port;

};