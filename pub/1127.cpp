// 1127.cpp
#include <iostream>

int f[100001] = {0};

int main(int argc, const char * argv[]) {
    int n, k;
    std::cin >> n >> k;
    if (k == 1) {
        std::cout << 1 << std::endl;
        return 0;
    }
    for (int i = 1; i <= k; i++)
        f[i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= k && j <= i; j++)
        f[i] = (f[i] + f[i - j]) % 100003;
    std::cout << f[n] << std::endl;
    return 0;
}