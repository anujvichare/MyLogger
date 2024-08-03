
#include "MyLogger.h"
#include <iomanip>

MyLogger::MyLogger(const std::string& fileName, const LogLevel& level)
{
	m_logLevel = level;
	m_fileName = fileName + "_00.log";

	m_file.open(m_fileName.c_str(), std::ofstream::out | std::ofstream::app);
}

MyLogger::~MyLogger()
{
	if(m_file.is_open())
		m_file.close();
}

void MyLogger::LogV(const std::string& logStatement)
{
	if(LogLevel::eVerbose >= m_logLevel)
		Log(LogLevel::eVerbose, logStatement);
}

void MyLogger::LogN(const std::string& logStatement)
{
	if(LogLevel::eNormal >= m_logLevel)
		Log(LogLevel::eNormal, logStatement);
}

void MyLogger::LogW(const std::string& logStatement)
{
	if(LogLevel::eWarning >= m_logLevel)
		Log(LogLevel::eWarning, logStatement);
}

void MyLogger::LogE(const std::string& logStatement)
{
	if(LogLevel::eError >= m_logLevel)
		Log(LogLevel::eError, logStatement);
}

void MyLogger::Log(const LogLevel& level, const std::string& logStatement)
{
	std::lock_guard<std::mutex> lg(m_mutex);
	std::time_t ct = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
	std::string time = std::ctime(&ct); 
	time.pop_back();
	m_file << time << ", "<< LogLevel_toString(level) << ", " << logStatement << std::endl;
}

std::string LogLevel_toString(LogLevel level)
{
	switch(level)
	{
		case eVerbose:
			return "Verbose";
		case eNormal:
			return "Normal";
		case eWarning: 
			return "Warning";
		case eError:
			return "Error";
	};
	return "";
}
