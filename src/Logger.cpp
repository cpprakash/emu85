#include "../includes/Logger.hpp"

#include "../includes/Types.hpp"

#include <string>

Logger::Logger() {}

void Logger::WriteLog(LOG_LEVELS level, const std::string &message) {}

/***
 * private functions start
 */

void Logger::SetLogLevel(LOG_LEVELS level) {}
void Logger::WriteLogFatal(const std::string &message) {}
void Logger::WriteLogError(const std::string &message) {}
void Logger::WriteLogWarn(const std::string &message) {}
void Logger::WriteLogInfo(const std::string &message) {}
void Logger::WriteLogDebug(const std::string &message) {}
void Logger::WriteLogTrace(const std::string &message) {}