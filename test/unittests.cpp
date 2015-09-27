#include "unittests.h"
#include "../common/logger.h"
#include "../engine/gridscene.h"
#include<memory>

using namespace std;
#define TESTPARAMS FUNCLINE, engine
#define ENGINEINIT(ENGINE) Engine ENGINE;
#define TESTINIT mTests++; ENGINEINIT(engine)
#define FAIL test(false, TESTPARAMS);

UnitTests::UnitTests()
{
	mTests = mAsserts = mPassed = mFailed = 0;
}

void UnitTests::run()
{
	initTest();
	initSceneTest();
	gridCollisionTest();
	irregularGridObjectTest();

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

void UnitTests::gridCollisionTest()
{
	TESTINIT;
	GridScene sc;
	sc.mObjects.push_back(make_unique<GridObject>(GridObject::intvec(1,1), GridObject::intvec(2,2)));
	test(sc.getObjectInPoint(GridObject::intvec(3,3)) == nullptr, FUNCLINE);
	test(sc.getObjectInPoint(GridObject::intvec(3,1)) == nullptr, FUNCLINE);
	test(sc.getObjectInPoint(GridObject::intvec(0,0)) == nullptr, FUNCLINE);
	test(sc.getObjectInPoint(GridObject::intvec(2,1)) != nullptr, FUNCLINE);
	test(sc.getObjectInPoint(GridObject::intvec(2,2)) != nullptr, FUNCLINE);
	test(sc.getObjectInPoint(GridObject::intvec(1,2)) != nullptr, FUNCLINE);
	test(sc.getObjectInPoint(GridObject::intvec(1,1)) != nullptr, FUNCLINE);
}

void UnitTests::irregularGridObjectTest()
{
	TESTINIT;
	GridScene sc;
	shared_ptr<GridObject> obj = make_unique<GridObject>(GridObject::intvec(1,1), GridObject::intvec(1,1));
	obj->mColliders.push_back(GridObject::intrec(GridObject::intvec(3,3), GridObject::intvec(1,1)));
	sc.mObjects.push_back(obj);
	test(sc.getObjectInPoint(GridObject::intvec(4,4)) == obj, FUNCLINE);
	test(sc.getObjectInPoint(GridObject::intvec(1,1)) == obj, FUNCLINE);
}
