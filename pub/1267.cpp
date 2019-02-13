// 1267.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int n, a = 1, aa = 3, res;
    std::cin >> n;
    if (n == 1)
        std::cout << a << std::endl;
    else if (n == 2)
        std::cout << aa << std::endl;
    else {
        for (int i = 3; i <= n; i++) {
            res = (aa % 12345 + (a % 12345 * 2) % 12345) % 12345;
            a = aa;
            aa = res;
        }
        std::cout << res % 12345 << std::endl;
    }
    return 0;
}
