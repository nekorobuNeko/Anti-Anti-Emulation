#include <stdio.h>
#include <stdlib.h>
 #include <windows.h>

int
main(){
char buf[1000];
	HWND hWnd;
hWnd = GetForegroundWindow();
WINDOWINFO windowInfo;
    windowInfo.cbSize = sizeof(WINDOWINFO);
    
    GetWindowInfo(hWnd, &windowInfo);

    printf("bottom=%d, left=%d, right=%d, top=%d\n", 
        windowInfo.rcWindow.bottom, 
        windowInfo.rcWindow.left,
        windowInfo.rcWindow.right,
        windowInfo.rcWindow.top);
    


return 0;         
}

