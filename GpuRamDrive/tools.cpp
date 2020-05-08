#include "stdafx.h"
#include "tools.h"

void tools::deb(char *msg, ...)
{
	va_list ap;
	char string[8192];
	char stringout[16384];

	va_start(ap, msg);
	vsprintf(string, msg, ap);
	va_end(ap);

	sprintf(stringout, "<%X> %s\r\n", GetCurrentThreadId(), string);
	OutputDebugStringA(stringout);
}

wchar_t* tools::fmterr(DWORD err)
{
	LPVOID lpMsgBuf = NULL;
	static wchar_t szInternal[255] = {0};

	FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, err,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPTSTR) &lpMsgBuf, 0, NULL);

	lstrcpy(szInternal, (wchar_t*) lpMsgBuf);
	LocalFree(lpMsgBuf);
	return szInternal;
}
