// 1633.cpp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

struct present {
    int x;
    int y;
    int w;
    present() = default;
    ~present() = default;
    present(int mx, int my) : x(mx), y(my) { w = 0; }
};

bool cmpx(present const &a, present const &b) { return (a.x == b.x ? a.y < b.y : a.x < b.x); }
bool cmpy(present const &a, present const &b) { return (a.y == b.y ? a.x < b.x : a.y < b.y); }

int l[100001] = {0}, r[100001] = {0}, s1[100001] = {0}, s2[100001] = {0};

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::vector<present> vp;
    int n, ans = 0x3f3f3f3f;
    std::cin >> n;
    for (int i = 0, tx, ty; i < n; i++) {
        std::cin >> tx >> ty;
        vp.push_back(present(tx, ty));
    }
    std::sort(vp.begin(), vp.end(), cmpx);
    for (int i = 1; i < n; i++)
        l[i] = l[i - 1] + i * (vp[i].x - vp[i - 1].x);
    for (int i = n - 2; i >= 0; i--)
        r[i] = r[i + 1] + (n - 1 - i) * (vp[i + 1].x - vp[i].x);
    for (int i = 1; i <= n; i++)
        vp[i].w = i;
    std::sort(vp.begin(), vp.end(), cmpy);
    for (int i = 0; i < n; i++)
        s1[i] = s1[i - 1] + i * (vp[i].y - vp[i - 1].y);
    for (int i = n - 2; i >= 0; i--)
        s2[i] = s2[i + 1] + (n - 1 - i) * (vp[i + 1].y - vp[i].y);
    for (int i = 0; i < n; i++) {
        int sum = l[vp[i].w] + r[vp[i].w] + s1[i] + s2[i];
        ans = std::min(ans, sum);
    }
    std::cout << ans << '\n';
    return 0;
}