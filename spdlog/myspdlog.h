#pragma once
// 本项目是一个简单的二次封装spdlog的项目，主要解决spdlog库在输出日志过程中，无法输出错误信息位置的问题：文件位置和行号
// 项目思路：
// 1.声明一个全局日志器，
// 2.配置这个全局日志器，如日志器类型是什么，日志级别是什么，日志输出到哪里等
// 3.封装日志器输出宏

// 在myspdlog.h中声明相关信息

//1. 包含头文件
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/stdout_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include<spdlog/async.h>
//2.声明命名空间
namespace myspdlog 
{
    //3.声明全局日志器，用智能指针进行管理
    extern std::shared_ptr<spdlog::logger> logger;
    //4.声明日志器配置结构体
    struct log_setting
    {
        //日志器是否异步
        bool is_async;
        //日志器输出等级
        std::int32_t log_level;
        //日志器输出格式
        std::string log_format;
        //日志器输出到哪里
        std::string log_output;
    };
    //5.声明日志器初始化函数
    void init_logger(const log_setting& setting);
    //6.声明日志器输出宏
    //由于[{}:{}]是一个const char[],因此不能修改，所以用一个string对象和fmt进行相加
    #define ERR(fmt,...) logger->error(std::string("[{}:{}]")+fmt,__FILE__,__LINE__,##__VA_ARGS__);
    #define INFO(fmt,...) logger->info(std::string("[{}:{}]")+fmt,__FILE__,__LINE__,##__VA_ARGS__);
    #define DEBUG(fmt,...) logger->debug(std::string("[{}:{}]")+fmt,__FILE__,__LINE__,##__VA_ARGS__);
    #define TRACE(fmt,...) logger->trace(std::string("[{}:{}]")+fmt,__FILE__,__LINE__,##__VA_ARGS__);

}
