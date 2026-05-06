#include <AsyncLogger/Logger.h>

int main()
{
	LoggerConfig config("bubble.txt", INFO, true, true);
	Logger logger(config);

	logger.Log(DEBUG, "This is me debugging buddy!");
	logger.Log(INFO, "Hello there buddy, this is just info!");


	LoggerConfig config1("bubble.txt", DEBUG, false, true);
	Logger logger1(config1);
	logger1.Log(WARNING, "Warning buddy, this is a warning!");

	LoggerConfig config2("bubble.txt", ERROR, true, false);
	Logger logger2(config2);
	logger2.Log(ERROR, "Buddy i think you have an error!");
	logger2.Log(CRITICAL, "Buddy you have to leave this is critical!");

	return 0;
}
