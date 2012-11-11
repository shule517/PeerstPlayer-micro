#include "HttpRequest.h"
#include <windows.h>
#include <stdio.h>
#include <wininet.h>
#include <string>
#pragma comment(lib, "wininet.lib")

HttpRequest::HttpRequest()
{
}

HttpRequest::~HttpRequest()
{
}

/* ========================================================================= */
/* 関数名: requestMessage													 */
/* 内容: 指定URLのHTMLソースを取得する										 */
/* 備考:		requestURL:指定URL												 */
/*			htmlSource:取得HTMLソースの格納先									 */
/* ========================================================================= */
void HttpRequest::requestMessage(const std:: string &requestURL, std::string &htmlSource)
{
	const std::string agent = "peerst";

	// ライブラリ初期化.
	HINTERNET handleNet = NULL;
	handleNet = InternetOpen(agent.c_str(), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (NULL == handleNet)
	{
		return;
	}

	// URLを開く.
	HINTERNET handleURL = NULL;
	handleURL = InternetOpenUrl(handleNet, requestURL.c_str(), NULL, 0, 0, 0);
	if (NULL == handleURL)
	{
		return;
	}

	// ボディメッセージ読み込み.
	DWORD readSize = 0;
	const LONG bufferSize = 32;
	char str[bufferSize] = {};

	while (true)
	{
		BOOL ret = false;
		ret = InternetReadFile(handleURL, str, sizeof(str), &readSize);
		str[bufferSize - 1] = '\0';

		// エラー or 最後まで読み込みできたら次の処理へ.
		if ((FALSE == ret) || (0 == readSize))
		{
			break;
		}

		// 受信データを追記.
		htmlSource += str;
	}

	// TODO エンコード変換クラスを作成する.
	// TODO 文字エンコードをヘッダから取得し、指定の文字コードへエンコード？
	
	//	int ret = WideCharToMultiByte( CP_ACP, 0, str, -1, NULL, 0, NULL, NULL );

	//printf("%s", str);

	/*
	char *message = NULL;

	while (true)
	{
		if (!HttpQueryInfo(handleURL, HTTP_QUERY_RAW_HEADERS_CRLF, message, &size, NULL))
		{
			// 格納先メモリ確保.
			if (GetLastError() == ERROR_INSUFFICIENT_BUFFER)
			{
				message = new char[size];
				continue;
			}
			else
			{
				return;
			}
		}
		break; 
	}
	*/

//	printf("%s", message);

	InternetCloseHandle(handleURL);
	InternetCloseHandle(handleNet);
}
