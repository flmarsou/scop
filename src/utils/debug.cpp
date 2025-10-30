#include "debug.hpp"

#include <chrono>
#include <iostream>
#include <iomanip>

void	printLog(const LogType type, const std::string &message)
{
	std::string	typeStr;

	switch (type)
	{
		case (LogType::Success): typeStr = "\033[32m OK \033[0m"; break ;
		case (LogType::Info): typeStr = "\033[36mINFO\033[0m"; break ;
		case (LogType::Warning): typeStr = "\033[35mWARN\033[0m"; break ;
		case (LogType::Error): typeStr = "\033[31m KO \033[0m"; break ;
		case (LogType::Message): typeStr = "\033[33mTEXT\033[0m"; break ;
		default: break ;
	}

	const auto	now = std::chrono::system_clock::now();
	const auto	time = std::chrono::system_clock::to_time_t(now);
	const auto	localTime = *std::localtime(&time);

	std::cout << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S") << " [ " << typeStr << " ] " << message << std::endl;
}
