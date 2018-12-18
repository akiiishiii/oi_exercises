// 3533.cpp
#include <cstring>
#include <iostream>

int const Maxn = 1000005;
int n, m, r[Maxn], s[Maxn];
struct classroom {
    int d;
    int s, t;
} cls[Maxn];

bool check(int dx);
int binary_search(int l, int r);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> r[i];
    for (int i = 1; i <= m; i++)
        std::cin >> cls[i].d >> cls[i].s >> cls[i].t;
    int maxcls = binary_search(0, m);
    if (maxcls == m)
        std::cout << "0\n";
    else
        std::cout << "-1\n" << maxcls + 1 << '\n';
    return 0;
}

bool check(int dx) {
    memset(s, 0, sizeof(s));
    for (int i = 1; i <= dx; i++) {
        s[cls[i].s] += cls[i].d;
        s[cls[i].t + 1] -= cls[i].d;
    }
    for (int i = 1; i <= n; i++) {
        s[i] += s[i - 1];
        if (s[i] > r[i])
            return false;
    }
    return true;
}

int binary_search(int l, int r) {
    int mid;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    return r;
}