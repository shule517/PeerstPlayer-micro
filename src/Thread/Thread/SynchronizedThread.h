#pragma once

#include <windows.h>
#include <process.h>

// スレッド管理クラス.
// クリティカルセクションにて排他制御を行う.
class SynchronizedThread
{
public:
	SynchronizedThread();
	virtual ~SynchronizedThread();

public:
	void start();								// runメソッドをスレッド実行.
	virtual void run() = 0;						// 実行処理内容.

private:
	static void threadMethod(void * arg);		// スレッドに指定するメソッド.
	static CRITICAL_SECTION criticalSection;	// クリティカルセクション.
};
