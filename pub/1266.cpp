// 1266.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int n, x = 9, e[1001] = {0}, o[1001] = {0};
    std::cin >> n;
    e[1] = 9;
    o[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (i == n)
            x = 8;
        e[i] = (e[i - 1] * x + o[i - 1]) % 12345;
        o[i] = (e[i - 1] + o[i - 1] * 9) % 12345;
    }
    std::cout << e[n] % 12345 << std::endl;
    return 0;
}