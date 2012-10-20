#include "Thread.h"
#include <process.h>

Thread::Thread()
{
}

Thread::~Thread()
{
}

// スレッドを実行.
void Thread::start()
{
	// スレッドハンドルは自動で解放される.
	_beginthread(&Thread::threadMethod, 0, this);
}

// 具象クラスにて実装したrunメソッドを呼び出す.
void Thread::threadMethod(void * arg)
{
	Thread * thread = reinterpret_cast<Thread*>(arg);

	if (NULL != thread)
	{
		// スレッド実行.
		thread->run();
	}
}
