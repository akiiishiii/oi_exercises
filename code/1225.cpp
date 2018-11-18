// 1225.cpp
#include <iostream>
#include <cstring>
#include <algorithm>

struct cow {
    int x;
    int y;
    int id;
    bool operator<(cow const &s) const { return ((x == s.x) ? (y > s.y) : (x < s.x)); }
} s[100005];

int c[100005] = {0}, ans[100005] = {0};
int n, maxy = 0;

template <typename T>
inline T lowbit(T const &x) { return x & (-x); }
void add(int x, int d);
int sum(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while ((std::cin >> n) && n) {
        memset(c, 0, sizeof(c));
        for (int i = 1; i <= n; i++) {
            std::cin >> s[i].x >> s[i].y;
            s[i].x++, s[i].y++;
            s[i].id=i;
        }
        std::sort(s + 1, s + n + 1);
        memset(c, 0, sizeof(c));
        ans[s[1].id] = 0;
        add(s[1].y, 1);
        maxy = s[1].y;
        for (int i = 2; i <= n; i++) {
            if ((s[i].x == s[i - 1].x) && (s[i].y == s[i - 1].y))
                ans[s[i].id] = ans[s[i - 1].id];
            else
                ans[s[i].id] = sum(maxy) - sum(s[i].y - 1);
            add(s[i].y, 1);
            maxy = std::max(maxy, s[i].y);
        }
        for (int i = 1; i <= n; i++)
            std::cout << ans[i] << ' ';
        std::cout << '\n';
    }
    return 0;
}

void add(int x, int d) {
    for (int i = x; i <= 100005; i += lowbit(i))
        c[i] += d;
}

int sum(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += c[i];
    return ans;
}