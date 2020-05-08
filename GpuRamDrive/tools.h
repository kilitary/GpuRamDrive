#pragma once


class tools
{
	public:
	static void deb(char *msg, ...);
	static wchar_t* fmterr(DWORD err = GetLastError());
};

