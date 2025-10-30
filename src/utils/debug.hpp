#pragma once

# include <string>

enum class	LogType
{
	Success,
	Info,
	Warning,
	Error,
	Message
};

void	printLog(const LogType type, const std::string &message);
