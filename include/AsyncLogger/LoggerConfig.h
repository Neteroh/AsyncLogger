#pragma once
#include <filesystem>
#include <AsyncLogger/LogLevel.h>
#include <utility>


class LoggerConfig
{
public:
	LoggerConfig(std::filesystem::path filePath = "logs/app.log", LogLevel minLogLevel = DEBUG, bool logToConsole = true, bool logToFile = true);

	[[nodiscard]] std::filesystem::path filepath() const noexcept;
	[[nodiscard]] LogLevel minLogLevel() const noexcept;
	[[nodiscard]] bool logToConsole() const noexcept;
	[[nodiscard]] bool logToFile() const noexcept;

private:
	std::filesystem::path filePath_;
	LogLevel minLogLevel_;
	bool logToConsole_;
	bool logToFile_;
};