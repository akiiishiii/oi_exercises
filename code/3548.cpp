// 3548.cpp
#include <algorithm>
#include <iostream>

struct point {
    int x, y;
    bool operator<(point const &p) const {
        return x < p.x || (x == p.x && y < p.y);
    }
} a[505];

int n, m, ans;

bool check(int x);

int main(int const argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> m >> n;
    for (int i = 0; i < n; i++)
        std::cin >> a[i].x >> a[i].y;
    std::sort(a, a + n);
    int l = 0, r = 10000;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    std::cout << ans << '\n';
    return 0;
}

bool check(int x) {
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j < n && a[j].x - a[i].x <= x - 1)
            j++;
        j--;
        if (j - i + 1 < m)
            return false;
        for (int k = i; k <= j; k++) {
            int l = a[k].y, r = a[k].y + x - 1;
            int sum = 0;
            for (int u = i; u <= j; u++) {
                if (a[u].y >= l && a[u].y <= r)
                    sum++;
            }
            if (sum >= m)
                return true;
        }
    }
    return false;
}