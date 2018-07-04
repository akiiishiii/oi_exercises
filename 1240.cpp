// 1240.cpp
#include <iostream>

int w(int a, int b, int c);

int main(int argc, const char * argv[]) {
    int a, b, c;
    std::cin >> a >> b >> c;
    w(a, b, c);
    return 0;
}

int w(int a, int b, int c) {
    int ret;
    if (a <= 0 || b <= 0 || c <= 0)
        ret = 1;
    else if (a > 5 || b > 5 || c > 5)
        ret = w(5, 5, 5);
    else if (a < b && b < c)
        ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        ret = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    std::cout << "w(" << a << ',' << b << ',' << c << ")=" << ret << std::endl;
    return ret;
}