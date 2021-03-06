#include "BBSOperator.h"
#include "WaiWaiStrategy.h"

BBSOperator::BBSOperator(const std::string &url)
:strategy(NULL)
{
	// TODO まずは、YY固定で.
	strategy = new WaiwaiStrategy(url);
}

BBSOperator::~BBSOperator()
{
}

/* ========================================================================= */
/* 関数名: GetBoardName														 */
/* 内容: 掲示板名取得														 */
/* 備考: 																	 */
/* ========================================================================= */
bool BBSOperator::GetBoardName(std::string &boardName)
{
	return strategy->GetBoardName(boardName);
}
