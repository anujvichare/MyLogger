
#include "MyLogger.h"
#include <thread>
#include<sstream>

void threadFunc(MyLogger& logger, const LogLevel& level)
{
	std::stringstream log;
	log << std::this_thread::get_id();
	log << ": log statement";
	for(int i = 0 ; i < 10000; ++i )
	{
		switch(level)
		{
			case LogLevel::eVerbose :
				logger.LogV(log.str());
				break;
			case LogLevel::eNormal :
				logger.LogN(log.str());
				break;
			case LogLevel::eWarning :
				logger.LogW(log.str());
				break;
			case LogLevel::eError :
				logger.LogE(log.str());
				break;
		};
	}
	
}

int main()
{
	MyLogger logger("TestLog", LogLevel::eVerbose);
	std::thread t1(threadFunc, std::ref(logger), LogLevel::eVerbose);
	std::thread t2(threadFunc, std::ref(logger), LogLevel::eNormal);
	std::thread t3(threadFunc, std::ref(logger), LogLevel::eWarning);
	std::thread t4(threadFunc, std::ref(logger), LogLevel::eError);

	t1.join();
	t2.join();
	t3.join();
	t4.join();
}
