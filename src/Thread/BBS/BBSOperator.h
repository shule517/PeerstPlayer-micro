#pragma once
#include <string>
#include "BBSStrategy.h"

class BBSOperator
{
public:
	BBSOperator(const std::string &url);
	virtual ~BBSOperator();

	bool GetBoardName(std::string &boardName);

private:
	BBSStrategy* strategy;
};
