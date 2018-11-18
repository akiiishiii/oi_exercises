// 1224.cpp
#include <iostream>
#include <string>
#include <algorithm>

struct star {
    int x;
    int y;
    bool operator<(star const &s) const { return ((x == s.x) ? (y < s.y) : (x < s.x)); }
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
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> s[i].x >> s[i].y;
        s[i].x++, s[i].y++;
        maxy = std::max(maxy, s[i].y);
    }
    std::sort(s + 1, s + n + 1);
    for (int i = 1; i <= n; i++)
        ans[sum(s[i].y)]++, add(s[i].y, 1);
    for (int i = 0; i < n; i++)
        std::cout << ans[i] << '\n';
    return 0;
}

void add(int x, int d) {
    for (int i = x; i <= maxy; i += lowbit(i))
        c[i] += d;
}

int sum(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans += c[i];
    return ans;
}