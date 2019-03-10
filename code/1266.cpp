// 1266.cpp
#include <iostream>

long long p[65], d[65], tot;
bool zero;

void insert(long long x);
void build();
long long getmax();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    long long s;
    std::cin >> n;
    for (long long i = 1; i <= n; i++)
        std::cin >> s, insert(s);
    build();
    long long ans = getmax();
    std::cout << ans << ' ' << (ans ^ d[0]) << '\n';
    return 0;
}

void insert(long long x) {
    for (long long i = 62; i >= 0; i--)
        if ((x >> i) & 1) {
            if (!p[i]) {
                p[i] = x;
                return;
            }
            x ^= p[i];
        }
    if (!x)
        zero = true;
}

void build() {
    for (long long i = 62; i >= 0; i--)
        for (long long j = i - 1; j >= 0; j--)
            if ((p[i] >> j) & 1)
                p[i] ^= p[j];
    for (long long i = 0; i <= 62; i++)
        if (p[i])
            d[tot++] = p[i];
}

long long getmax() {
    long long ret = 0;
    for (long long i = 62; i >= 0; i--)
        if (ret < (ret ^ p[i]))
            ret ^= p[i];
    return ret;
}