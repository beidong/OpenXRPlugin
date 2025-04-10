#ifndef LIBLOG_H
#define LIBLOG_H

#include "spdlog.h"
#include "spdlog/logger.h"

#if defined(LIBLOG_LIBRARY)
#  define LIBLOG_EXPORT __declspec(dllexport)
#else
#  define LIBLOG_EXPORT __declspec(dllimport)
#endif

//封装宏，没有该宏无法输出文件名、行号等信息
#define LOG_TRACE(...)  do { auto logger = LibLog::Instance()->getLoger(); if (logger) SPDLOG_LOGGER_CALL(logger, spdlog::level::trace, __VA_ARGS__); } while (0)
#define LOG_DEBUG(...) do { auto logger = LibLog::Instance()->getLoger(); if (logger) SPDLOG_LOGGER_CALL(logger, spdlog::level::debug, __VA_ARGS__); } while (0)
#define LOG_INFO(...)    do { auto logger = LibLog::Instance()->getLoger(); if (logger) SPDLOG_LOGGER_CALL(logger, spdlog::level::info, __VA_ARGS__); } while (0)
#define LOG_WARN(...)  do { auto logger = LibLog::Instance()->getLoger(); if (logger) SPDLOG_LOGGER_CALL(logger, spdlog::level::warn, __VA_ARGS__); } while (0)
#define LOG_ERROR(...) do { auto logger = LibLog::Instance()->getLoger(); if (logger) SPDLOG_LOGGER_CALL(logger, spdlog::level::err, __VA_ARGS__); } while (0)
#define LOG_CRITI(...)    do {auto logger = LibLog::Instance()->getLoger(); if (logger) SPDLOG_LOGGER_CALL(logger, spdlog::level::critical, __VA_ARGS__); } while (0)

class LIBLOG_EXPORT LibLog
{
    //日志输出位置
    enum OutPosition {
        CONSOLE             = 0x01,	//控制台
        FILE                = 0X02,	//文件
        CONSOLE_AND_FILE    = 0x03, //控制台+文件
    };
 
    enum OutMode {
        SYNC,   //同步模式
        ASYNC,  //异步模式
    };
 
    //日志输出等级
    enum OutLevel {
        LEVEL_TRACE     = 0,
        LEVEL_DEBUG     = 1,
        LEVEL_INFO      = 2,
        LEVEL_WARN      = 3,
        LEVEL_ERROR     = 4,
        LEVEL_CRITI     = 5,
        LEVEL_OFF       = 6,
	};

public:
    static LibLog* Instance();
    ~LibLog() = default;

    bool init(const char* nFileName, const int nMaxFileSize = 1024 * 1024 * 5, const int nMaxFile = 5,
        const OutMode outMode = ASYNC, const OutPosition outPos = FILE, const OutLevel outLevel = LEVEL_DEBUG);

    std::shared_ptr<spdlog::logger> getLoger() const { return m_pLogger; };

private:
    LibLog() = default;
    LibLog(const LibLog&) = delete;
    LibLog& operator=(const LibLog&) = delete;

private:
    std::shared_ptr<spdlog::logger> m_pLogger = nullptr;
};

#endif // LIBLOG_H
