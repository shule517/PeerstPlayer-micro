#include <iostream>
#include "BBSOperator.h"

int main()
{
	BBSOperator bbs("http://yy33.kakiko.com/test/read.cgi/peercast/1350753291/");

	// ŒfŽ¦”Â–¼Žæ“¾.
	std::string boardName = "";
	bbs.GetBoardName(boardName);
	printf("ŒfŽ¦”Â–¼: %s", boardName.c_str());
}
