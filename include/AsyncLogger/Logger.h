#pragma once

#include <fstream>
#include <string>

#include "AsyncLogger/LogLevel.h"
#include "AsyncLogger/LogMessage.h"
#include "AsyncLogger/LoggerConfig.h"

class Logger
{
public:
	Logger(const LoggerConfig& config);
	~Logger();

	void Debug(const std::string& message);
	void Info(const std::string& message);
	void Warning(const std::string& message);
	void Error(const std::string& message);
	void Critical(const std::string& message);
	void Log(LogLevel logLevel, const std::string& message);

private:
	std::ofstream logFile_;
	bool logToConsole_;
	bool logToFile_;
	LogLevel minLogLevel_;

	std::string enumToString(LogLevel logLevel);
	std::string processMessage(const LogMessage& logMessage);
};
