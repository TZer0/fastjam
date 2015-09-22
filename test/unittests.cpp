#include "unittests.h"
#include "../common/logger.h"
#include "../engine/gridscene.h"

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
	initSceneTest();

	printResults();
}

void UnitTests::initSceneTest()
{
	TESTINIT;
	GridScene sc;
}

void UnitTests::initTest()
{
	TESTINIT;
}
