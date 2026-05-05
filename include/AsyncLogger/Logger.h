#pragma once

#include <iostream>
#include <string>
#include<fstream>
#include "AsyncLogger/LogLevel.h"
#include "AsyncLogger/LogMessage.h"

class Logger
{
public:
	Logger();
	void Debug(const std::string& message);
	void Info(const std::string& message);
	void Warning(const std::string& message);
	void Error(const std::string& message);
	void Critical(const std::string& message);
	void Log(LogLevel logLevel, const std::string& message);
	std::string enumToString(LogLevel logLevel);
	std::string processMessage(const LogMessage& logMessage);
	~Logger();

private:
	std::ofstream logFile_;
};
