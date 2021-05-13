#include <stdio.h>

/*
    ファイルの存在を確認する。

    path:   ファイルパス。
    戻り値: 存在したら 0以外、存在しなければ 0
*/
int existFile(const char* path)
{
    FILE* fp = fopen(path, "r");
    if (fp == NULL) {
        return 0;
    }

    fclose(fp);
    return 1;
}

int main(void)
{
    if (existFile("VmwareService.exe")) {
        puts("success");
    }
    else {
        puts("failed");
    }

    return 0;
}