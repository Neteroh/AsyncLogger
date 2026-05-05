#pragma once
#include <chrono>
#include <string>
#include <thread>
#include "AsyncLogger/LogLevel.h"

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