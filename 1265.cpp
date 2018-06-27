// 1265.cpp
#include <iostream>

int main(int argc, const char *argv[]) {
    int x, y, z;
    long long f[55] = {0}, c[55] = {0};
    std::cin >> x >> y >> z;
    for (int i = 1; i <= x; i++) {
        f[i] = 1;
        c[i] = 0;
    }
    for (int i = x + 1; i <= z + 1; i++) {
        c[i] = f[i - x] * y;
        f[i] = f[i - 1] + c[i - 2];
    }
    std::cout << f[z + 1] << std::endl;
    return 0;
}