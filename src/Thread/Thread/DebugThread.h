#pragma once
#include "thread.h"
#include <string>

class DebugThread :
	public Thread
{
public:
	DebugThread(const std::string name);
	virtual ~DebugThread();

	void run();

private:
	const std::string name;
};
