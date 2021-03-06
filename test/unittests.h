#ifndef UNITTESTS_H
#define UNITTESTS_H

#include<iostream>
#include "../engine/engine.h"

#define DEFAULT_MSG ""
#define FUNCLINE (std::string(__FUNCTION__) + std::string(" - line ") + std::to_string(__LINE__))

class UnitTests
{
public:
	UnitTests();
	void run();
private:
	void printResults()
	{
		std::cout << "Tests: " << mTests << std::endl << "Asserts: " << mAsserts << std::endl << "Passed: " << mPassed << std::endl << "Failed: " << mFailed << std::endl;
	}

	void initTest();
	void initSceneTest();
	void gridCollisionTest();
	void irregularGridObjectTest();

	void test(bool val, std::string msg)
	{
		mAsserts++;
		if (val) {
			mPassed++;
		} else {
			mFailed++;
			std::cout << msg << " failed." << std::endl;
		}
	}

	void test(bool val, const std::string &msg, Engine &engine)
	{
		test(val, msg);
		if (!val) {
			//std::cout << "Map:" << std::endl;
			//game.print(true);

			//auto ev = game.getLatestEvents();
			//std::cout << STRFORMAT("Messages (%d):", % ev.size()) << std::endl;
			/*for (size_t i = 0; i < ev.size(); i++) {
				std::cout << ev[i].getDescription() << std::endl;
			}*/
		}
	}
	int mPassed, mFailed, mTests, mAsserts;
};

#endif // UNITTESTS_H
