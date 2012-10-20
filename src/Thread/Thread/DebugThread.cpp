// Threadクラステスト用.
#include "DebugThread.h"
#include <stdio.h>

DebugThread::DebugThread(const std::string _name)
:name(_name)
{
}

DebugThread::~DebugThread()
{
}

// スレッド処理内容.
void DebugThread::run()
{
	for (long i = 0; i < 20; i++)
	{
		printf("%s:%d\n", name.c_str(), i);
	}
}
