// 1119.cpp
#include <iostream>
#include <cstring>

int num[15] = {0};
long long f[15][2];

long long cal(long long val, bool is6, bool flag);
long long query(long long n);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    memset(f, -1, sizeof(f));
    long long x, y;
    while (std::cin >> x >> y) {
        if (!(x || y))
            break;
        std::cout << query(y) - query(x - 1) << '\n';
    }
    return 0;
}

long long cal(long long val, bool is6, bool flag) {
    if (!val)
        return 1;
    if (!flag && ~f[val][is6])
        return f[val][is6];
    long long range = (flag ? num[val] : 9), ans = 0;
    for (int i = 0; i <= range; i++) {
        if (i == 4 || (is6 && i == 2))
            continue;
        ans += cal(val - 1, i == 6, flag && i == range);
    }
    if (!flag)
        f[val][is6] = ans;
    return ans;
}

long long query(long long n) {
    num[0] = 0;
    while (n) {
        num[++num[0]] = n % 10;
        n /= 10;
    }
    return cal(num[0], false, true);
}