// 1348.cpp
#include <iostream>
#include <set>

struct rec {
    int x, y;
    bool operator<(rec const &r) const { return y < r.y; }
};

std::set<rec> s;
std::set<rec>::iterator it, lt, rt;
int n, m, h[100002], g[100002];

bool cmp(int a, int b, int i);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> h[i];
    for (int i = 1, p; i <= n; i++) {
        rec r;
        r.x = i, r.y = h[i];
        s.insert(r);
        it = s.find(r);
        lt = rt = it;
        m = 0;
        if (lt != s.begin())
            g[++m] = (--(lt))->x;
        if (++rt != s.end())
            g[++m] = rt->x;
        if (i >= 2) {
            if (m < 2 || cmp(g[1], g[2], i))
                p = g[1];
            else
                p = g[2];
            std::cout << abs(h[i] - h[p]) << ' ' << p << '\n';
        }
    }
    return 0;
}

bool cmp(int a, int b, int i) {
    return abs(h[a] - h[i]) < abs(h[b] - h[i]) ||
           (abs(h[a] - h[i]) == abs(h[b] - h[i]) && h[a] < h[b]);
}