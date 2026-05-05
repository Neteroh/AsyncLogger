#include "AsyncLogger/Logger.h"
#include <chrono>
#include <iostream>
#include <thread>

Logger::Logger()
{
	logFile_.open("logs/app.log", std::ofstream::out | std::ofstream::app);

	if (!logFile_.is_open())
	{
		std::cerr << "Failed to open the log file\n";
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
	LogMessage logMessage(
		message,
		logLevel,
		std::chrono::system_clock::now(),
		std::this_thread::get_id()
	);

	std::string formattedString = processMessage(logMessage);

	std::cout << formattedString;
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
	logFile_.flush();
	logFile_.close();
};