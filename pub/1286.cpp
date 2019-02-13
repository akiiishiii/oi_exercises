// 1286.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int n;
    long long f[61] = {0};
    f[1] = 1;
    f[2] = 2;
    f[3] = 4;
    for (int i = 4; i <= 60; i++)
        f[i] = f[i - 1] + f[i - 2] + f[i - 3];
    while (true) {
        std::cin >> n;
        if (!n)
            break;
        std::cout << f[n] << std::endl;
    }
    return 0;
}