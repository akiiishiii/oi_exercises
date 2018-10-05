// 1120.cpp
#include <iostream>
#include <cstring>

long long f[25][25];
int num[25] = {0};

long long cal(int pos, int sta, bool limit);
long long query(long long n);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    memset(f, -1, sizeof(f));
    int x, y;
    while (std::cin >> x >> y)
        std::cout << query(y) - query(x - 1) << '\n';
    return 0;
}

long long cal(int pos, int sta, bool limit) {
    long long res = 0;
    if (pos == -1)
        return 1;
    if (!limit && f[pos][sta] != -1)
        return f[pos][sta];

    int range = limit ? num[pos] : 9;
    for (int i = sta; i <= range; i++)
        res += cal(pos - 1, i, limit && i == range);
    if (!limit)
        f[pos][sta] = res;
    return res;
}

long long query(long long n) {
    int len = 0;
    memset(f, -1, sizeof(f));
    while (n) {
        num[len++] = n % 10;
        n /= 10;
    }
    return cal(len - 1, 0, 1);
}