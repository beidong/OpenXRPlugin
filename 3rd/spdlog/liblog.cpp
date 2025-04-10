#include "liblog.h"

#include "spdlog/async_logger.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"
#include "spdlog/details/thread_pool.h"
#include "spdlog/details/thread_pool-inl.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/async.h"

//日志名称
const std::string g_LogNameUid = "907B7F20-25B0-49B9-A60C-B656D382DE95";
LibLog *LibLog::Instance()
{
    static LibLog g_log;
    return &g_log;
}

bool LibLog::init(const char* nFileName, const int nMaxFileSize, const int nMaxFile, const OutMode outMode, const OutPosition outPos, const OutLevel outLevel)
{
    if (m_pLogger)
        return true;

    //const char* pFormat = "[%Y-%m-%d %H:%M:%S.%e] <thread %t> [%^%l%$][%@,%!]%v";
    const char* pFormat = "%Y.%m.%d_%H:%M:%S.%e<thread:%t>[%@,%!][%^%l%$] %v";
    std::vector<spdlog::sink_ptr> vecSink;

    try
    {
        //控制台
        if (outPos & CONSOLE)
        {
            auto console_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
            //console_sink->set_level(spdlog::level::trace);
            console_sink->set_pattern(pFormat);
            vecSink.push_back(console_sink);
        }

        //文件
        if (outPos & FILE)
        {
            auto file_sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(nFileName, nMaxFileSize, nMaxFile);
            //file_sink->set_level(spdlog::level::trace);
            file_sink->set_pattern(pFormat);
            vecSink.push_back(file_sink);
        }

        //设置logger使用多个sink
        if (outMode == ASYNC)//异步
        {
            spdlog::init_thread_pool(10240, 2);
            auto tp = spdlog::thread_pool();
            m_pLogger = std::make_shared<spdlog::async_logger>(g_LogNameUid, begin(vecSink), end(vecSink), tp, spdlog::async_overflow_policy::block);
        }
        else//同步
        {
            m_pLogger = std::make_shared<spdlog::logger>(g_LogNameUid, begin(vecSink), end(vecSink));
        }

        m_pLogger->set_level((spdlog::level::level_enum)outLevel);

        //遇到warn级别，立即flush到文件
        m_pLogger->flush_on(spdlog::level::warn);
        //定时flush到文件，每2秒刷新一次
        spdlog::flush_every(std::chrono::seconds(2));
        spdlog::register_logger(m_pLogger);
    }
    catch (const std::exception&)
    {
        return false;
    }

    return true;
}