#include "AsyncLogger/AsyncLogger.h"

using namespace std;

int main()
{
	Logger logger;

	logger.Log(DEBUG, "This is me debugging buddy!");
	logger.Log(INFO, "Hello there buddy, this is just info!");
	logger.Log(WARNING, "Warning buddy, this is a warning!");
	logger.Log(ERROR, "Buddy i think you have an error!");
	logger.Log(CRITICAL, "Buddy you have to leave this is critical!");

	return 0;
}

LogMessage::LogMessage(std::string message,
	LogLevel logLevel,
	std::chrono::time_point<std::chrono::system_clock> timestamp,
	std::thread::id threadId)
	: message_(std::move(message)),
	logLevel_(std::move(logLevel)),
	timestamp_(std::move(timestamp)),
	threadId_(std::move(threadId))
{

}

const std::string& LogMessage::message() const noexcept
{
	return message_;
}

LogLevel LogMessage::logLevel() const noexcept
{
	return logLevel_;
}

std::chrono::time_point<std::chrono::system_clock> LogMessage::timestamp() const noexcept
{
	return timestamp_;
}

std::thread::id LogMessage::threadId() const noexcept
{
	return threadId_;
}
