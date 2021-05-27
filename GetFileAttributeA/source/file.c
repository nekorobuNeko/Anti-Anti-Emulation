#include <stdio.h>
#include <tchar.h>


#include <windows.h>
int _tmain
(
      int argc
    , _TCHAR* argv[]
)
{
    HANDLE hFile = CreateFile(
              "test.txt",GENERIC_WRITE,0,NULL,
                CREATE_ALWAYS,FILE_ATTRIBUTE_NORMAL,NULL);
    if (hFile!=INVALID_HANDLE_VALUE) {
 
       puts("success");
    }
    else {
       
       puts("failed");
    }
 
    // 正常終了
    return( 0 );
}