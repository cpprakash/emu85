#ifndef __INCLUDES_LOGGER_HPP__
#define __INCLUDES_LOGGER_HPP__

#include "./Types.hpp"

#include <string>

class Logger {
public:
  Logger();
  void WriteLog(LOG_LEVELS level, const std::string &message);

private:
  void SetLogLevel(LOG_LEVELS level);
  void WriteLogFatal(const std::string &message);
  void WriteLogError(const std::string &message);
  void WriteLogWarn(const std::string &message);
  void WriteLogInfo(const std::string &message);
  void WriteLogDebug(const std::string &message);
  void WriteLogTrace(const std::string &message);

public:
  int a;

private:
  LOG_LEVELS m_currentLogLevel = LOG_TRACE;
};

#endif