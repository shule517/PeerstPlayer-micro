#include "BBSOperator.h"
#include "WaiWaiStrategy.h"

BBSOperator::BBSOperator(const std::string &url)
:strategy(NULL)
{
	// TODO ‚Ü‚¸‚ÍAYYŒÅ’è‚Å.
	strategy = new WaiwaiStrategy(url);
}

BBSOperator::~BBSOperator()
{
}

/* ========================================================================= */
/* ŠÖ”–¼: GetBoardName														 */
/* “à—e: ŒfŽ¦”Â–¼Žæ“¾														 */
/* ”õl: 																	 */
/* ========================================================================= */
bool BBSOperator::GetBoardName(std::string &boardName)
{
	return strategy->GetBoardName(boardName);
}
