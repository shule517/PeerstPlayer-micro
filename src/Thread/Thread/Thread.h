#pragma once

#include <windows.h>

// スレッド管理クラス.
// 排他制御は行わない.
class Thread
{
public:
	Thread();
	virtual ~Thread();

public:
	void start();								// runメソッドをスレッド実行.
	virtual void run() = 0;						// 実行処理内容.
	// TODO スレッドの終了処理が必要？.

private:
	static void threadMethod(void * arg);		// スレッドに指定するメソッド.
};
