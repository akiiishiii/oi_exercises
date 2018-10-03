// main.cpp
#include "windows.h"

int main(int argc, const TCHAR * argv[]) {
    int ret = MessageBox(NULL, TEXT("Object not found!"), TEXT("Error"), MB_ICONHAND | MB_RETRYCANCEL);
    if (ret == IDRETRY)
        MessageBox(NULL, TEXT("Fuck you!"), TEXT("Microsoft Software Manager"), MB_ICONHAND);
    return 0;
}