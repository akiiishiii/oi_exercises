// robot.cpp
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#define debug

#ifndef debug

std::ifstream in("robot.in");
std::ofstream out("robot.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const SIZE = 50001;
int n, m1, m2, ans = 0x3f3f3f3f;
int p[SIZE], tmp[SIZE], f1[SIZE][1001], f2[SIZE][1001];

//template <typename T1, typename T2>
//auto max(T1 const &p, T2 const &b) -> decltype(p > b ? p : b) { return p > b ? p : b; }

inline void read(int &x);
inline void write(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    ::read(n);
    ::read(m1);
    ::read(m2);
    for (int i = 1; i <= n; i++)
        ::read(p[i]), tmp[i] = p[i];
    std::sort(tmp + 1, tmp + n + 1);
    int tot = std::unique(tmp + 1, tmp + n + 1) - tmp - 1;
    for (int i = 1; i <= n; ++i)
        p[i] = std::lower_bound(tmp + 1, tmp + tot + 1, p[i]) - tmp;
    for (int i = 1; i <= n; ++i) {
        int mn1 = 0x3f3f3f3f, mn2 = 0x3f3f3f3f;
        for (int j = 1; j <= tot; ++j) {
            mn1 = std::min(mn1, f1[i - 1][j]);
            f1[i][j] = mn1 + (j < p[i] ? m2 : (j == p[i] ? 0 : m1));
        }
        for (int j = tot; j >= 1; --j) {
            mn2 = std::min(mn2, f2[i - 1][j]);
            f2[i][j] = mn2 + (j < p[i] ? m2 : (j == p[i] ? 0 : m1));
        }
    }
    for (int i = 1; i <= tot; ++i)
        ans = std::min(ans, std::min(f1[n][i], f2[n][i]));
    write(ans);
    out.put('\n');
    return 0;
}

inline void read(int &x) {
    x = 0;
    char c = in.get();
    while (c < '0' || c > '9')
        c = in.get();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = in.get();
    }
}

inline void write(int x) {
    int y = 10, len = 1;
    while (y <= x) {
        y *= 10;
        len++;
    }
    while (len--) {
        y /= 10;
        out.put(x / y + 48);
        x %= y;
    }
}