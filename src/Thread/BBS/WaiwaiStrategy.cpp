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
/* 関数名: GetBoardName														 */
/* 内容: 掲示板名取得														 */
/* 備考: 																	 */
/* ========================================================================= */
bool WaiwaiStrategy::GetBoardName(std::string &boardName)
{
	httpRequest->requestMessage("http://jbbs.livedoor.jp/bbs/read.cgi/game/45037/1345901480/", boardName);
	return true;
}
