#include "WaiwaiStrategy.h"
#include "../Thread/Web/HttpRequest.h"

WaiwaiStrategy::WaiwaiStrategy(const std::string &url)
:BBSStrategy(url)
{
}

WaiwaiStrategy::~WaiwaiStrategy()
{
}

/* ========================================================================= */
/* ŠÖ”–¼: GetBoardName														 */
/* “à—e: ŒfŽ¦”Â–¼Žæ“¾														 */
/* ”õl: 																	 */
/* ========================================================================= */
bool WaiwaiStrategy::GetBoardName(std::string &boardName)
{
	httpRequest->requestMessage("http://jbbs.livedoor.jp/bbs/read.cgi/game/45037/1345901480/", boardName);
	return true;
}
