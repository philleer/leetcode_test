#ifndef __MYLOG_H__
#define __MYLOG_H__

#include <stdio.h>	// stdin/stdout/stderr, __DATE__/__TIME__/__FILE__/__func__/__LINE__
#include <stddef.h>	// size_t, wchar_t, offsetof, NULL
#include <stdlib.h> // EXIT_SUCCESS, EXIT_FAILURE
#include <unistd.h>	// getcwd, access, usleep, F_OK/STDIN_FILENO/STDOUT_FILENO/STDERR_FILENO
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

//=============================================================================
// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ stdio.h //////////////////////////////// *
//=============================================================================
// extern FILE *stdin;
// extern FILE *stdout;
// extern FILE *stderr;
//
//=============================================================================
// \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\ unistd.h //////////////////////////////// *
//=============================================================================
// STDIN_FILENO: Standard input value, stdin. Its value is 0.
// STDOUT_FILENO: Standard output value, stdout. Its value is 1.
// STDERR_FILENO: Standard error value, stderr. Its value is 2.

#endif /* __MYLOG_H__ */