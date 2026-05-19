#include<iostream>
#include"udpserver.hpp"
#include<memory>

int main()//int argc, char *argv[]
{
    // if(argc!=2)
    // {
    //     return 1;
    // }
    // uint16_t port=std::stoi(argv[1]);
    //1.创建服务器对象
    std::unique_ptr<udpserver> svr(new udpserver());
    //2.初始化服务器
    svr->Init();
    svr->Run();
    //3.运行服务器
    return 0;
}