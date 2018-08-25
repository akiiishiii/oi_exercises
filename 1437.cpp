// 1437.cpp
#include <iomanip>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

int x[160], y[160];
double d[160][160], l[160] = {0.0}, r = 0.0;
int n;

double dist(int a, int b) { return sqrt((long long)(x[a] - x[b]) * (x[a] - x[b]) + (long long)(y[a] - y[b]) * (y[a] - y[b])); };
void read(int &x);
void write(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    double ans = 1e10;
    read(n);
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (int i = 1; i <= n; i++) {
        read(x[i]);
        read(y[i]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            if (i != j)
                d[i][j] = 1e10;
            char c;
            std::cin >> c;
            if (c == '1')
                d[i][j] = dist(i, j);
        }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][k] != 1e10 && d[k][j] != 1e10)
                    d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (d[i][j] != 1e10)
                l[i] = std::max(l[i], d[i][j]);
        r = std::max(r, l[i]);
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (i != j && d[i][j] == 1e10)
                ans = std::min(ans, dist(i, j) + l[i] + l[j]);
    std::cout << std::fixed << std::setprecision(6) << std::max(ans, r);
    std::cout.put('\n');
    return 0;
}

void read(int &x) {
    x = 0;
    char c = std::cin.get();
    while (c < '0' || c > '9')
        c = std::cin.get();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = std::cin.get();
    }
}

void write(int x) {
    int y = 10, len = 1;
    while (y <= x) {
        y *= 10;
        len++;
    }
    while (len--) {
        y /= 10;
        std::cout.put(x / y + 48);
        x %= y;
    }
}