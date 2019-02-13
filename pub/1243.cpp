// 1243.cpp
#include <iostream>
#include <cstring>

long long w(int a, int b, int c);
long long f[105][105][105];

int main(int argc, const char * argv[]) {
    int a, b, c;
    memset(f, -1, sizeof f);
    std::cin >> a >> b >> c;
    std::cout << w(a, b, c);
    return 0;
}

long long w(int a, int b, int c) {
    if (f[a][b][c] != -1)
        return f[a][b][c];
    else if (a <= 0 || b <= 0 || c <= 0)
        return f[a][b][c] = 1;
    else if (a > 20 || b > 20 || c > 20)
        return f[a][b][c] = w(20, 20, 20);
    else if (a < b && b < c)
        return f[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    else
        return f[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}