#include <windows.h>
#include <stdio.h>
#include <shlwapi.h>
//#pragma comment(lib, "C:\borland\bcc55\Lib\PSDK\shlwapi.lib")
void GetValue(void)
{
	HKEY hKey;
	DWORD ValueType;
	DWORD ValueSize;
	char Value[1000];

	/* レジストリキーのオープン */
	RegOpenKeyEx(
		HKEY_CURRENT_USER,
		"AppEvents\\EventLabels",
		0,
		KEY_ALL_ACCESS,
		&hKey);

	ValueSize = 1000;

	/* レジストリ値の取得 */
	SHGetValue(
		hKey,
		"Close",
		"DispFileName",
		&ValueType,
		Value,
		&ValueSize);

	/* 結果の表示 */
	if (ValueType == REG_SZ) printf("%s\n", Value);
	else printf("...\n");

	/* 終了 */
	RegCloseKey(hKey);

}

int main(void)
{
	
	GetValue();

	return 0;
}