#pragma once

#include <iostream>

class Logger
{
public:
	void LogInfo(const std::string& message)
	{
		std::cout << "[INFO] : " << message << '\n';
	}
};
