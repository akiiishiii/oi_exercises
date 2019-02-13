// 1268.cpp
#include <iostream>

int main(int argc, const char * argv[]) {
    int n, res = 0, a = 0, aa = 0;
    std::cin >> n;
    if (n == 1)
        res = 3;
    else if (n == 2)
        res = 7;
    else {
        a = 7;
        aa = 3;
        for (int i = 3; i <= n; i++) {
            res = ((2 * a % 12345) % 12345 + aa % 12345) % 12345;
            aa = a;
            a = res;
        }
    }
    std::cout << res % 12345 << std::endl;
    return 0;
}