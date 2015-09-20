#include "unittests.h"
#include "../common/logger.h"

using namespace std;
#define TESTPARAMS FUNCLINE, engine
#define ENGINEINIT(ENGINE) Engine ENGINE;
#define TESTINIT mTests++; ENGINEINIT(engine)
#define FAIL test(false, TESTPARAMS);

UnitTests::UnitTests()
{
	mTests = mPassed = mFailed = 0;
}

void UnitTests::run()
{
	initTest();

	printResults();
}

void UnitTests::initTest()
{
	TESTINIT;
	FAIL;
}
