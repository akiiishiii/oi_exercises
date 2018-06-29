// 1211.cpp
#include <iostream>

inline int gcd(int a, int b) { return b ? gcd(b, a % b) : a;}

int main(int argc, const char *argv[])
{
    int x0, y0, num = 0, y;
    std::cin >> x0 >> y0;
    for (int i = x0; i <= y0; i++) {
        y = x0 * y0 / i;
        if (!((x0 * y0) % i) && gcd(i, y) == x0)
            num++;
    }
    std::cout << num << std::endl;
    return 0;
}