#ifndef LOGGER_H
#define LOGGER_H

//#include<boost/filesystem/fstream.hpp>
#include<iostream>

class Logger
{
public:
	static Logger &getInstance() {
		static Logger instance;
		return instance;
	}

	static void log(std::string message) {
		getInstance().writeToLog(message);
	}

	static void init(std::string name, bool printAll = false) {
		getInstance().initLog(name, printAll);
	}

	static std::string getLogName() {
		return getInstance().getPath();
	}

	void initLog(std::string name, bool printAll) {
		if (mInit) {
			return;
		}
		mPrintAll = printAll;
		mName = name;
		mInit = true;
	}

	void writeToLog(std::string message) {
		if (mInit) {
//			boost::filesystem::ofstream mOut;
//			mOut.open(getPath(), std::ofstream::out | std::ofstream::app);
//			mOut << message << std::endl;
//			mOut.close();
		}
	}

private:
	std::string getPath() { return mName + std::string(".log"); }
	Logger();
	Logger(Logger &);
	Logger operator=(Logger const&);
	bool mInit, mPrintAll;
	std::string mName;
};

#endif // DEBUGGER_H
