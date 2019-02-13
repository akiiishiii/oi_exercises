// 1210.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int n, f[1001] = {1, 1, 2};
    std::cin >> n;
    for (int i = 3; i <= n; i++)
        f[i] = f[i - 1] + (i % 2 ? 0 : f[i / 2]);
    std::cout << f[n] << std::endl;
    return 0;
}