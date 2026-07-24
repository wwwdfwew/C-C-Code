#include "myspdlog.h"

namespace myspdlog
{
    //1.定义一个全局日志器对象
    std::shared_ptr<spdlog::logger> logger;

    //2.定义日志器初始化函数
    void init_logger(const log_setting& setting)
    {
        //3.日志器是否异步以及输出位置
        //异步日志器
        if(setting.is_async==true)
        {
            if(setting.log_output=="stdout")
           {
                logger=spdlog::stdout_color_mt<spdlog::async_factory>("async_stdout_log");
           }
           else if(setting.log_output=="file")
           {
                spdlog::init_thread_pool(8192, 1);
                logger=spdlog::basic_logger_mt<spdlog::async_factory>("async_file_log", setting.log_format);
           }
        }
        //同步日志器
        else
        {
            if(setting.log_output=="stdout")
           {
                logger=spdlog::stdout_color_mt("async_stdout_log");
           }
           else if(setting.log_output=="file")
           {
                logger=spdlog::basic_logger_mt("async_file_log", setting.log_format);
           }
        }
        //4.设置日志器输出等级
        logger->set_level(spdlog::level::level_enum(setting.log_level));
        //5.设置日志器输出格式
        logger->set_pattern(setting.log_format);
       
    }

}
