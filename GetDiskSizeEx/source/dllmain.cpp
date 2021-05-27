// dllmain.cpp : DLL アプリケーションのエントリ ポイントを定義します。


//////////////////////////////////////////////////////////////////////////////
//
//  Detours Test Program (simple.cpp of simple.dll)
//
//  Microsoft Research Detours Package, Version 3.0.
//
//  Copyright (c) Microsoft Corporation.  All rights reserved.
//
//  This DLL will detour the Windows SleepEx API so that TimedSleep function
//  gets called instead.  TimedSleepEx records the before and after times, and
//  calls the real SleepEx API through the TrueSleepEx function pointer.
//
#include <stdio.h>
#include <windows.h>
#include <detours.h>
#pragma comment(lib, "detours.lib")
static LONG dwSlept = 0;
static BOOL (WINAPI* TrueGetDiskFreeSpaceEx)(LPCTSTR lpDirectoryName, PULARGE_INTEGER lpFreeBytesAvailable,
	PULARGE_INTEGER lpTotalNumberOfBytes,
	PULARGE_INTEGER lpTotalNumberOfFreeBytes) = GetDiskFreeSpaceEx;
SYSTEM_INFO info;
void WINAPI newGetDiskFreeSpaceEx(LPCTSTR lpDirectoryName, PULARGE_INTEGER lpFreeBytesAvailable,
	PULARGE_INTEGER lpTotalNumberOfBytes,
	PULARGE_INTEGER lpTotalNumberOfFreeBytes) {
	ULONGLONG a = 64424509440;
	ULONGLONG b = 42949672960;
	TrueGetDiskFreeSpaceEx(lpDirectoryName, lpFreeBytesAvailable, lpTotalNumberOfBytes, lpTotalNumberOfFreeBytes);
	puts("hooked");
	lpFreeBytesAvailable->QuadPart = b;
	lpTotalNumberOfFreeBytes->QuadPart = b;
	lpTotalNumberOfBytes->QuadPart = a;
}


BOOL WINAPI DllMain(HINSTANCE hinst, DWORD dwReason, LPVOID reserved)
{
	LONG error;
	(void)hinst;
	(void)reserved;

	if (DetourIsHelperProcess()) {
		return TRUE;
	}

	if (dwReason == DLL_PROCESS_ATTACH) {
		DetourRestoreAfterWith();

		//printf("simple" DETOURS_STRINGIFY(DETOURS_BITS) ".dll:"
			//" Starting.\n");
		fflush(stdout);

		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourAttach(&(PVOID&)TrueGetDiskFreeSpaceEx, newGetDiskFreeSpaceEx);
		error = DetourTransactionCommit();

		if (error == NO_ERROR) {
			//printf("simple" DETOURS_STRINGIFY(DETOURS_BITS) ".dll:"
				//" Detoured SleepEx().\n");
		}
		else {
			//printf("simple" DETOURS_STRINGIFY(DETOURS_BITS) ".dll:"
				//" Error detouring SleepEx(): %d\n", error);
		}
	}
	else if (dwReason == DLL_PROCESS_DETACH) {
		DetourTransactionBegin();
		DetourUpdateThread(GetCurrentThread());
		DetourDetach(&(PVOID&)TrueGetDiskFreeSpaceEx, newGetDiskFreeSpaceEx);
		error = DetourTransactionCommit();

		//   printf("simple" DETOURS_STRINGIFY(DETOURS_BITS) ".dll:"
		//        " Removed SleepEx() (result=%d), slept %d ticks.\n", error, dwSlept);
		fflush(stdout);
	}
	return TRUE;
}

//
///////////////////////////////////////////////////////////////// End of File.
