// Project Borealis Launcher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <windows.h>
#include <stdio.h>
#include <tchar.h>

int main()
{
	if (ShellExecute(
		NULL, // No parent window
		L"open",
		L".\\WindowsNoEditor\\projectborealis_ue.exe",
		NULL, // L"-vulkan" or L"-dx10" or NULL
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

