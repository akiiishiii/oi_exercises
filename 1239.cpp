// 1239.cpp
#include <iostream>

int w(int a, int b, int c);

int main(int argc, const char * argv[]) {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << w(a, b, c);
    return 0;
}

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0)
        return 1;
    else if (a > 5 || b > 5 || c > 5)
        return w(5, 5, 5);
    else if (a < b && b < c)
        return w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        return w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}