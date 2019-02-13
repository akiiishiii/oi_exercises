// 1270.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int f[1001][2], n;
    std::cin >> n;
    f[1][0] = 3;
    f[1][1] = 1;
    for (int i = 2; i <= n; i++) {
        f[i][0] = (3 * f[i - 1][0] % 12345 + 2 * f[i - 1][1] % 12345) % 12345;
        f[i][1] = (f[i - 1][0] % 12345 + f[i - 1][1] % 12345) % 12345;
    }
    std::cout << (f[n][0] + f[n][1]) % 12345 << std::endl;
    return 0;
}