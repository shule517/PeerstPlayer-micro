#include "BBSStrategy.h"
#include "../Thread/Web/HttpRequest.h"

BBSStrategy::BBSStrategy(const std::string &url)
{
	httpRequest = new HttpRequest();
}

BBSStrategy::~BBSStrategy()
{
	delete httpRequest;
}
