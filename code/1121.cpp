// 1121.cpp
#include <iostream>
#include <cstring>

long long f[105][105], mod;
int num[105] = {0};

long long cal(int pos, int pre, bool limit);
long long query(int n);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long x, y;
    while (std::cin >> x >> y >> mod) {
        memset(f, -1, sizeof(f));
        std::cout << query(y) - query(x - 1) << '\n';
    }
    return 0;
}

long long cal(int pos, int pre, bool limit) {
    if (pos == -1)
        return pre == 0;
    if (!limit && ~f[pos][pre])
        return f[pos][pre];
    long long res = 0 ;
    int range = limit ? num[pos] : 9;
    for (int i = 0; i <= range; i++)
        res += cal(pos - 1, (pre + i) % mod, limit && i == range);
    if (!limit)
        f[pos][pre] = res;
    return res;
}

long long query(int n) {
    int len = 0;
    while (n) {
        num[len++] = n % 10;
        n /= 10;
    }
    return cal(len - 1, 0, 1);
}