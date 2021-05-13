﻿// dllmain.cpp : DLL アプリケーションのエントリ ポイントを定義します。
//#include "stdafx.h"

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
DWORD dw1 = 10;
static LONG dwSlept = 0;
static BOOL(WINAPI* TrueGetDiskFreeSpace)(LPCTSTR RootPathName,
	LPDWORD SectorsPerCluster,
	LPDWORD BytesPerSector,
	LPDWORD FreeClusters,
	LPDWORD Clusters) = GetDiskFreeSpace;

BOOL WINAPI newGetDiskFreeSpace(__out LPCTSTR RootPathName,
	LPDWORD SectorsPerCluster,
	LPDWORD BytesPerSector,
	LPDWORD FreeClusters,
	LPDWORD Clusters) {
	
		puts("hooked!!");
		return TrueGetDiskFreeSpace(RootPathName,
			SectorsPerCluster,
			BytesPerSector,
			FreeClusters,
			&dw1);
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
		DetourAttach(&(PVOID&)TrueGetDiskFreeSpace, newGetDiskFreeSpace);
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
		DetourDetach(&(PVOID&)TrueGetDiskFreeSpace, newGetDiskFreeSpace);
		error = DetourTransactionCommit();

		//   printf("simple" DETOURS_STRINGIFY(DETOURS_BITS) ".dll:"
		//        " Removed SleepEx() (result=%d), slept %d ticks.\n", error, dwSlept);
		fflush(stdout);
	}
	return TRUE;
}