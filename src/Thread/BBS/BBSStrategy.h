#pragma once

#include <string>

class HttpRequest;
class BBSStrategy
{
public:
	BBSStrategy(const std::string& url);
	virtual ~BBSStrategy();

	virtual bool GetBoardName(std::string &boardName) = 0;
//	virtual bool WriteRes(std::string name, std::string mail, std::string text) = 0;
//	virtual bool ReadThread(/*threadList& list*/) = 0;
//	virtual bool GetThreadList() = 0;

protected:
//	virtual bool GetThreadStopNum(long &threadStopNum);
	HttpRequest *httpRequest;
};
