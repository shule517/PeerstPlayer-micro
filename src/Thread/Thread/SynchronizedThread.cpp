#include "SynchronizedThread.h"

CRITICAL_SECTION SynchronizedThread::criticalSection = {};

SynchronizedThread::SynchronizedThread()
{
	InitializeCriticalSection(&criticalSection);
}

SynchronizedThread::~SynchronizedThread()
{
}

// スレッドを実行.
void SynchronizedThread::start()
{
	// スレッドハンドルは自動で解放される.
	_beginthread(&SynchronizedThread::threadMethod, 0, this);
}

// 具象クラスにて実装したrunメソッドを呼び出す.
void SynchronizedThread::threadMethod(void * arg)
{
	SynchronizedThread * thread = reinterpret_cast<SynchronizedThread*>(arg);

	if (NULL != thread)
	{
		// クリティカルセクション / スレッド実行.
		EnterCriticalSection(&criticalSection);
		thread->run();
		LeaveCriticalSection(&criticalSection);
	}
}
