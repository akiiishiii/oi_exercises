// 1269.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int n, f[1001] = {0};
    std::cin >> n;
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= i - 2; j++)
            f[i] = (f[i] + f[j] * f[i - j - 2]) % 12345;
        f[i] = (f[i] + f[i - 1]) % 12345;
    }
    std::cout << f[n] % 12345 << std::endl;
    return 0;
}