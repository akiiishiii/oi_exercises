// 5212.cpp
#include <iostream>

long long p[1005], d[10005], tot;
bool zero;

bool insert(long long x);
void build();
long long query(long long k);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    long long s;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> s, insert(s);
    std::cin >> m;
    for (int i = 1; i <= m; i++) {
        std::cin >> s;
        std::cout << query(s) << '\n';
    }
    return 0;
}

bool insert(long long x) {
    for (int i = 62; i >= 0; i--)
        if (x >> i & 1) {
            if (p[i])
                x ^= p[i];
            else {
                p[i] = x;
                break;
            }
        }
    if (!x)
        zero = true;
    return x > 0;
}

void build() {
    for (long long i = 62; i >= 0; i++)
        for (long long j = i - 1; j >= 0; j--)
            if (p[i] >> j & i)
                p[i] ^= p[j];
    for (int i = 0; i <= 62; i++)
        if (p[i])
            d[++tot] = p[i];
}

long long query(long long k) {
    if (k > (1ll << tot))
        return -1;
    if (zero)
        k--;
    long long ret = 0;
    for (int i = tot; i >= 0; i--)
        if (k >> i & 1)
            ret ^= d[i];
    return ret;
}