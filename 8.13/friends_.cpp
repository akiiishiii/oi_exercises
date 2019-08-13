#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define N 400001
#define PER(i, a, b) for (int i = a; i <= b; i++)
bool pg[N];
int ver[N];
int edge[N];
int head[N], cis;
int ond, sed;
int q[2 * N];
int d[N], Next[N], cir[N], civ[N];
int n, l, tot, ans = 2e9, u, v, w, he, ta, onen;
void s() {
    puts("no answer");
    exit(0);
}
void add(int u, int v, int w) {
    ver[++tot] = v;
    edge[tot] = w;
    Next[tot] = head[u];
    head[u] = tot;
}
void init() {
    scanf("%d", &n);
    PER(i, 1, n) {
        scanf("%d%d%d", &u, &v, &w), add(u, v, w), add(v, u, w), d[u]++, d[v]++;
    }
    if (n % 2)
        s();
}
void dfs(int x, int nownum) {
    if (pg[x])
        return;
    cis = nownum;
    cir[nownum] = x;
    pg[x] = 1;
    for (int i = head[x]; i; i = Next[i]) {
        if (!pg[ver[i]]) {
            dfs(ver[i], nownum + 1);
            civ[nownum] = edge[i];
            break;
        }
    }
    return;
}
int main() {
    init();
    he = ta = 0;
    PER(i, 1, n) {
        if (d[i] == 1)
            q[++ta] = i;
        else if (d[i] == 0)
            s();
    }
    while (he++ < ta) {
        if (pg[q[he]])
            continue;
        l = 0;
        for (int i = head[q[he]]; i; i = Next[i]) {
            if (!pg[ver[i]]) {
                l = ver[i];
                pg[ver[i]] = pg[q[he]] = 1;
                ans = min(ans, edge[i]);
                break;
            }
        }
        if (!l)
            s();
        for (int i = head[l]; i; i = Next[i]) {
            if (!pg[ver[i]]) {
                if (--d[ver[i]] == 1)
                    q[++ta] = ver[i];
                else if (!d[ver[i]])
                    s();
            }
        }
    }
    bool flag = 0;
    PER(i, 1, n) if (!pg[i]) {
        onen = i;
        flag = 1;
        break;
    }
    if (!flag) {
        cout << ans;
        return 0;
    }
    dfs(onen, 1);
    for (int i = head[cir[cis]]; i; i = Next[i]) {
        if (ver[i] == cir[1]) {
            civ[0] = edge[i];
            break;
        }
    }
    sed = ond = ans;
    PER(i, 1, cis / 2) {
        ond = min(ond, civ[i * 2 - 1]);
        sed = min(sed, civ[i * 2 - 2]);
    }
    ans = max(sed, ond);
    cout << ans;
}