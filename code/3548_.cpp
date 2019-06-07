// 3548_.cpp
#include <algorithm>
#include <iostream>

int c, n;
int mid, ans, cnt, tmp[525];
struct node {
    int x, y;
    bool operator<(node const &n) const { return x < n.x; }
} pos[525];

bool judge(int l, int r);
bool check(int x);

int main(int const argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> c >> n;
    for (int i = 1; i <= n; ++i)
        std::cin >> pos[i].x >> pos[i].y;
    std::sort(pos + 1, pos + 1 + n);
    int l = 1, r = 1e4;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (check(mid))
            r = mid - 1, ans = mid + 1;
        else
            l = mid + 1;
    }
    std::cout << ans << '\n';
    return 0;
}

bool judge(int l, int r) {
    if (r - l < c - 1)
        return false;
    cnt = 0;
    for (int i = l; i <= r; ++i)
        tmp[++cnt] = pos[i].y;
    std::sort(tmp + 1, tmp + cnt + 1);
    for (int i = c; i <= cnt; ++i)
        if (tmp[i] - tmp[i - c + 1] <= mid)
            return true;
    return false;
}

bool check(int x) {
    int l = 1, r = 1;
    while (r <= n) {
        if (pos[r].x - pos[l].x > x)
            if (judge(l, r - 1))
                return true;
        while (pos[r].x - pos[l].x > x)
            l++;
        r++;
    }
    return judge(l, n);
}