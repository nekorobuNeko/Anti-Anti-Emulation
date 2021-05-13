#include <stdio.h>
#include <stdlib.h>
 #include <windows.h>

int
main(){
char buf[1000];
	HWND hWnd;

	/* フォアグラウンドウィンドウの取得 */
	hWnd = GetForegroundWindow();

	/* ウィンドウタイトルの表示 */
	GetWindowText(hWnd, buf, 1000);
	MessageBox(NULL, buf, "DoGetForegroundWindow", MB_OK);


return 0;         
}

