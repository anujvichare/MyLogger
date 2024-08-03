
#include "MyLogger.h"

int main()
{
	MyLogger logger("TestLog", LogLevel::eError);

	logger.LogW("warning log ..........");
	logger.LogN("warning log ..........");
	logger.LogW("warning log ..........");
	logger.LogE("warning log ..........");
	logger.LogE("warning log ..........");
	logger.LogV("warning log ..........");
	logger.LogV("warning log ..........");
	logger.LogV("warning log ..........");
}
