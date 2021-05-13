#include <windows.h>
#include <stdio.h>
#include <tchar.h>

// Use to convert bytes to KB
#define DIV 1024
#define WIDTH 7

void _tmain()
{
  MEMORYSTATUSEX statex;

  statex.dwLength = sizeof (statex);

  GlobalMemoryStatusEx (&statex);
  _tprintf (TEXT("There are %*I64d GB .\n"),
            WIDTH, statex.ullTotalPhys/(DIV*DIV*DIV));
}