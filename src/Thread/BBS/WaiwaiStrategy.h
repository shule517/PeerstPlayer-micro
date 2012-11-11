#pragma once

#include "BBSStrategy.h"

class WaiwaiStrategy :
	public BBSStrategy
{
public:
	WaiwaiStrategy(const std::string &url);
	virtual ~WaiwaiStrategy();

	bool GetBoardName(std::string &boardName);
};
