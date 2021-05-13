#include <stdio.h>
#include <unistd.h>
#include <windows.h>
#include <winbase.h>

int main()
{
char *a;
SYSTEM_INFO info;
	GetSystemInfo(&info);
	printf("cpu = %d\n", info.dwNumberOfProcessors);

	return 0;
}