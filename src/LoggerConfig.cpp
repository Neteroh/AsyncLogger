#include <AsyncLogger/LoggerConfig.h>

LoggerConfig::LoggerConfig(
    std::filesystem::path filePath,
    LogLevel minLogLevel,
    bool logToConsole,
    bool logToFile)
    : filePath_(std::move(filePath)),
    minLogLevel_(minLogLevel),
    logToConsole_(logToConsole),
    logToFile_(logToFile)

{
}

std::filesystem::path LoggerConfig::filepath() const noexcept
{
	return filePath_;
}
LogLevel LoggerConfig::minLogLevel() const noexcept
{
	return minLogLevel_;
}
bool LoggerConfig::logToConsole() const noexcept
{
	return logToConsole_;
}
bool LoggerConfig::logToFile() const noexcept
{
	return logToFile_;
}