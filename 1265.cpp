// 1265.cpp
#include <iostream>

int main(int argc, const char *argv[]) {
    long long x, y, z, f[55], s[55];
    std::cin >> x >> y >> z;
    for (int i = 0; i <= x; i++) {
        f[i] = 1;
        s[i] = 0;
    }
    for (int i = x + 1; i <= z + 1; i++) {
        s[i] = f[i - x] * y;
        f[i] = f[i - 1] + s[i - 2];
    }
    std::cout << f[z + 1] << std::endl;
    return 0;
}