#include <stdio.h>
#include <string.h>
#include <windows.h>

// メイン関数
int main( void )
{
    TCHAR           szRoot[ 16 ];
    ULARGE_INTEGER  i64Used;
    ULARGE_INTEGER  i64Free;
    ULARGE_INTEGER  i64Avail;
    ULARGE_INTEGER  i64Total;
    
    // ドライブの設定
    strcpy( szRoot, TEXT("C:\\") );
    // ディスク情報の取得
    GetDiskFreeSpaceEx( szRoot, &i64Free, &i64Total, &i64Avail );
    // 結果表示
    i64Used.QuadPart = (i64Total.QuadPart - i64Avail.QuadPart);
    printf( TEXT("used disksize：%12I64u GB\n"), i64Used.QuadPart/(1024*1024*1024) );
    printf( TEXT("avail disksize：%12I64u GB\n"), i64Avail.QuadPart/(1024*1024*1024));
    printf( TEXT("total disksize：%12I64u GB\n"), i64Total.QuadPart/(1024*1024*1024) );
    return 0;
}