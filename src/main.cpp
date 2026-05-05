#include <AsyncLogger/Logger.h>

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
