// 5212.cpp
#include <iostream>

long long p[65], d[65], tot;
bool zero;

void insert(long long x);
void build();
long long query(long long k);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    long long s;
    std::cin >> n;
    for (long long i = 1; i <= n; i++)
        std::cin >> s, insert(s);
    build();
    std::cin >> m;
    for (int i = 1; i <= m; i++) {
        std::cin >> s;
        std::cout << query(s) << '\n';
    }
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

long long query(long long k) {
    long long ans = 0, i;
    if (zero) {
        if (k == 1)
            return 0;
        else
            k--;
    }
    if (k >> tot)
        return -1;
    for (i = tot - 1; i >= 0; i--)
        if ((k >> i) & 1)
            ans ^= d[i];
    return ans;
}