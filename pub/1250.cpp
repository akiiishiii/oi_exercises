// 1250.cpp
#include <iostream>

int f[1000001] = {0};

int main(int argc, const char * argv[]) {
    int n, k;
    std::cin >> n;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= 1000000; i++)
        f[i] = (2 * f[i - 1] + f[i - 2]) % 32767;
    for (int i = 0; i < n; i++) {
        std::cin >> k;
        std::cout << f[k] << std::endl;
    }
    return 0;
}