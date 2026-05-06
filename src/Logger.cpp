#include "AsyncLogger/Logger.h"

#include <chrono>
#include <iostream>
#include <sstream>
#include <thread>

Logger::Logger(const LoggerConfig& config)
	: logToConsole_(config.logToConsole()),
	logToFile_(config.logToFile()),
	minLogLevel_(config.minLogLevel())
{
	if (logToFile_)
	{
		logFile_.open(config.filepath(), std::ofstream::out | std::ofstream::app);

		if (!logFile_.is_open())
		{
			std::cerr << "Failed to open the log file\n";
			logToFile_ = false;
		}
	}
};

std::string Logger::enumToString(LogLevel logLevel)
{
	switch (logLevel)
	{
	case DEBUG:
		return "DEBUG";
	case INFO:
		return "INFO";
	case WARNING:
		return "WARNING";
	case ERROR:
		return "ERROR";
	case CRITICAL:
		return "CRITICAL";
	default:
		return "UNKNOWN";
	};
}

std::string Logger::processMessage(const LogMessage& logMessage)
{
	std::ostringstream formattedString;

	formattedString << "[" << logMessage.timestamp() << "] "
		<< "[" << enumToString(logMessage.logLevel()) << "] "
		<< "[" << logMessage.threadId() << "] "
		<< logMessage.message() << '\n';

	return formattedString.str();
}

void Logger::Log(LogLevel logLevel, const std::string& message)
{
	if (logLevel < minLogLevel_) return;

	LogMessage logMessage(
		message,
		logLevel,
		std::chrono::system_clock::now(),
		std::this_thread::get_id()
	);

	const std::string formattedString = processMessage(logMessage);

	if (logToConsole_)
		std::cout << formattedString;
	if (logToFile_ && logFile_.is_open())
		logFile_ << formattedString;
}

void Logger::Debug(const std::string& message)
{
	Log(DEBUG, message);
}

void Logger::Info(const std::string& message)
{
	Log(INFO, message);
}

void Logger::Warning(const std::string& message)
{
	Log(WARNING, message);
}

void Logger::Error(const std::string& message)
{
	Log(ERROR, message);
}

void Logger::Critical(const std::string& message)
{
	Log(CRITICAL, message);
}

Logger::~Logger()
{
	if (logFile_.is_open())
	{
		logFile_.flush();
		logFile_.close();
	}
};