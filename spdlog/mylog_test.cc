#include "./myspdlog.h"
#include<gflags/gflags.h>
//1.通过gflags定义要捕获的参数
DEFINE_bool(is_async, true, "日志器是否异步");
DEFINE_int32(log_level, 1, "日志器输出等级:1-debug,2-info,3-warning,4-error");
DEFINE_string(log_format, "%Y-%m-%d %H:%M:%S [%t] [%-7l] %v", "日志器输出格式");
DEFINE_string(log_output, "stdout", "日志器输出到哪里");

int main(int argc, char* argv[])
{
    //2，解析命令行参数
    google::ParseCommandLineFlags(&argc, &argv, true);
    //3.初始化日志器配置参数    
    myspdlog::log_setting setting;
    setting.is_async = FLAGS_is_async;
    setting.log_level = FLAGS_log_level;
    setting.log_format = FLAGS_log_format;
    setting.log_output = FLAGS_log_output;
    //4.初始化日志器
    myspdlog::init_logger(setting);
    //5.测试日志器输出
    myspdlog::ERR("这是一条错误日志");
    myspdlog::INFO("这是一条信息日志");
    myspdlog::DEBUG("这是一条调试日志");
    myspdlog::ERR("这是一条错误日志");
    return 0;
}