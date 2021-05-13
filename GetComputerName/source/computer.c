#include <windows.h>
#include <stdio.h>

int main()
{
	char szComputerName[256] = {'\0'};
	DWORD dwSize = sizeof(szComputerName)/sizeof(szComputerName[0]);
	
	if (GetComputerName(szComputerName, &dwSize)) {
		printf("%s\n", szComputerName);
	} else {
		puts("GetComputerName failed.");
	}

	return 0;
}