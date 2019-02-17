// 1348.cpp
#include <bits/stdc++.h>
using namespace std;
int n, m, h[100002], g[100002];
struct rec {
    int x, y;
};
set<rec> s;
set<rec>::iterator it, lt, rt;
bool operator<(rec a, rec b) { return a.y < b.y; }
bool cmp(int a, int b, int i) {
    return abs(h[a] - h[i]) < abs(h[b] - h[i]) || (abs(h[a] - h[i]) == abs(h[b] - h[i]) && h[a] < h[b]);
}
int main() {
    int i, j, p;
    n = in();
    for (i = 1; i <= n; i++)
        h[i] = in();
    for (i = 1; i <= n; i++) {
        rec r;
        r.x = i;
        r.y = h[i];
        s.insert(r);
        it = s.find(r);
        lt = rt = it;
        m = 0;
        if (lt != s.begin())
            lt--, g[++m] = lt->x;
        if (rt++, rt != s.end())
            g[++m] = rt->x;
        if (i >= 2) {
            if (m < 2 || cmp(g[1], g[2], i))
                p = g[1];
            else
                p = g[2];
            printf("%d %d\n", abs(h[i] - h[p]), p);
        }
    }
}