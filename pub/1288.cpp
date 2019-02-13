// 1288.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int n, f[21];
    std::cin >> n;
    f[1] = 1;
    f[2] = 2;
    for (int i = 3; i <= n; i++)
        f[i] = f[i - 1] + f[i - 2];
    std::cout << f[n] << std::endl;
    return 0;
}