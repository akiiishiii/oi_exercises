// main.cpp
#include "windows.h"

int main(int argc, const TCHAR * argv[]) {
    int ret = MessageBox(NULL, TEXT("找不到对象！"), TEXT("郝唯志"), MB_ICONHAND | MB_RETRYCANCEL);
    if (ret == IDRETRY)
        MessageBox(NULL, TEXT("郝唯志已停止工作。"), TEXT("Microsoft Software Manager"), MB_ICONHAND);
    return 0;
}