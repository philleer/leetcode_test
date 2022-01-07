#ifndef __MYLOG_H__
#define __MYLOG_H__

#include <stdio.h>
#include <stddef.h>	// size_t, wchar_t, NULL, offsetof
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE
#include <unistd.h>	// getcwd, access, F_OK
#include <sys/stat.h> // mkdir, S_IRUSR, S_IWUSR, S_IXUSR
#include <spdlog/spdlog.h>
#include <spdlog/fmt/bundled/printf.h>

template <class loggerPtr, class... Args>
void loglineprintf(loggerPtr logger,
				   spdlog::level::level_enum level,
				   spdlog::source_loc loc,
				   const char* fmt,
				   const Args&... args) noexcept
{
    if (logger && logger->should_log(level))
    {
        logger->log(loc, level, "{}", fmt::sprintf(fmt, args...));
    }
}

#define SPDLOG_LOGGER_PRINTF(logger, level, ...) \
	    loglineprintf(logger, level, spdlog::source_loc{__FILE__, __LINE__, SPDLOG_FUNCTION}, __VA_ARGS__)

//specific log implementation macros
#define LOG_INFO(...) SPDLOG_LOGGER_PRINTF(spdlog::default_logger(),spdlog::level::info,__VA_ARGS__)
#define LOG_ERROR(...) SPDLOG_LOGGER_PRINTF(spdlog::default_logger(),spdlog::level::err,__VA_ARGS__)

void log_runtime_info(void);

void log_init(const int argc, char *argv[]);

#endif /* __MYLOG_H__ */