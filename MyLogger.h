#include <fstream>
#include <mutex>

enum LogLevel
{
	eVerbose = 0,
	eNormal = 1,
	eWarning = 2,
	eError = 3
};

std::string LogLevel_toString(LogLevel level);

class MyLogger
{
	public:
		MyLogger(const std::string& fileName, const LogLevel&);
		~MyLogger();
		MyLogger(const MyLogger&) = delete;
		void operator=(const MyLogger&) = delete;
		MyLogger(MyLogger&&) = delete;
		void operator=(MyLogger&&) = delete;	

		void LogV(const std::string& logStatement);
		void LogN(const std::string& logStatement);
		void LogW(const std::string& logStatement);
		void LogE(const std::string& logStatement);

	private:
		std::string m_fileName;
		std::fstream m_file;
		std::mutex m_mutex;
		LogLevel m_logLevel;

		void Log(const LogLevel& level, const std::string& logStatement);

};
