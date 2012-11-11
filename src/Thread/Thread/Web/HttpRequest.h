#pragma once

#include <string>

class HttpRequest
{
public:
	HttpRequest();
	virtual ~HttpRequest();

	void requestMessage(const std::string &requestURL, std::string &htmlSource);
};
