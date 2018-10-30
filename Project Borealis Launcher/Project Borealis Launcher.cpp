// Project Borealis Launcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <tchar.h>
#include <string>
#include <corecrt_wstring.h>

std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}

int main(int argc, char* argv[], char* envp[])
{
	FreeConsole();
	std::string commandLineStr = "";
	for (int i = 1; i < argc; i++) commandLineStr.append(argv[i]).append(" ");
	//commandLineStr.append(" -dx10"); // L"-vulkan" or L"-dx10" or comment out
	std::wstring wstringtemp = s2ws(commandLineStr);
	LPCWSTR result = wstringtemp.c_str();
	if (ShellExecute(
		NULL, // No parent window
		L"open",
		L".\\WindowsNoEditor\\projectborealis_ue.exe",
		result,
		NULL, // cwd
		10 // Let application decide
	))
	{
		printf("Executed with Code %d", GetLastError());
		return 0;
	}
	printf("Failed with Error %d", GetLastError());
	return 1;
}

