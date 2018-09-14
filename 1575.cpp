// 1575.cpp
#include <iostream>

int const Maxn = 10005;
int scc = 0, vst[Maxn], head[Maxn], ver[50005], Next[50005], fhead[Maxn], fver[50005], ffNext[50005], n, a[Maxn];
int tot = 0, ftot = 0, outdeg[Maxn] = {0}, wt[Maxn] = {0};

void add(int x, int y);
void dfs1(int x);
void dfs2(int x);

int main(int argc, char const *argv[]) {
    int m, ans = 0;
    std::cin >> n >> m;
    for (int i = 1, x, y; i <= m; i++) {
        std::cin >> x >> y;
        add(x, y);
    }
    a[0] = 0;
    for (int i = 1; i <= n; i++)
        if (!vst[i])
            dfs1(i);
    for (int i = n; i >= 1; i--)
        if (vst[a[i]] == -1) {
            scc++;
            dfs2(a[i]);
        }
    for (int i = 1; i <= n; i++)
        for (int p = head[i]; p; p = Next[p]) {
            int y = ver[p];
            if (vst[i] != vst[y])
                outdeg[vst[i]]++;
        }
    int num = 0;
    for (int i = 1; i <= scc; i++)
        if (!outdeg[i]) {
            num++;
            ans = wt[i];
        }
    if (num == 1)
        std::cout << ans;
    else
        std::cout << 0;
    std::cout << '\n';
    return 0;
}

void add(int x, int y) {
    ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
    fver[++ftot] = y, ffNext[ftot] = fhead[x], fhead[x] = ftot;
}

void dfs1(int x) {
    vst[x] = -1;
    for (int p = head[x]; p; p = Next[p]) {
        int y = ver[p];
        if (!vst[y])
            dfs1(y);
    }
    a[++a[0]] = x;
}

void dfs2(int x) {
    vst[x] = scc;
    wt[scc]++;
    for (int p = fhead[x]; p; p = ffNext[p]) {
        int y = fver[p];
        if (vst[y] == -1)
            dfs2(y);
    }
}