#pragma once

#include <iostream>
#include <chrono>
#include <thread>

enum LogLevel {
	UNKNOWN,
	DEBUG,
	INFO,
	WARNING,
	ERROR,
	CRITICAL
};

class LogMessage
{
public:
	LogMessage(std::string message,
		LogLevel logLevel,
		std::chrono::time_point<std::chrono::system_clock> timestamp,
		std::thread::id threadId);

	[[nodiscard]] const std::string& message() const noexcept;
	[[nodiscard]] LogLevel logLevel() const noexcept;
	[[nodiscard]] std::chrono::time_point<std::chrono::system_clock> timestamp() const noexcept;
	[[nodiscard]] std::thread::id threadId() const noexcept;

private:
	std::string message_;
	LogLevel logLevel_;
	std::chrono::time_point<std::chrono::system_clock> timestamp_ = std::chrono::system_clock::now();
	std::thread::id threadId_;
};

class Logger
{
public:
	void Debug(const std::string& message)
	{
		Log(DEBUG, message);
	}

	void Info(const std::string& message)
	{
		Log(INFO, message);
	}

	void Warning(const std::string& message)
	{
		Log(WARNING, message);
	}

	void Error(const std::string& message)
	{
		Log(ERROR, message);
	}

	void Critical(const std::string& message)
	{
		Log(CRITICAL, message);
	}

	void Log(LogLevel logLevel, const std::string& message)
	{
		LogMessage logMessage(
			message,
			logLevel,
			std::chrono::system_clock::now(),
			std::this_thread::get_id()
		);

		processMessage(logMessage);
	}

private:
	std::string enumToString(LogLevel logLevel)
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

	void processMessage(const LogMessage& logMessage)
	{
		std::cout << "[" << logMessage.timestamp() << "] "
			<< "[" << enumToString(logMessage.logLevel()) << "] "
			<< "[" << logMessage.threadId() << "] "
			<< logMessage.message() << '\n';
	}
};
