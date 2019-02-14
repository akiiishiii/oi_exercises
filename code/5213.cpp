// 5213.cpp
#include <cstring>
#include <iostream>
#include <queue>
#define MAX 5005
int n, m, S, T, ANS, SUM, gap[MAX], d[MAX], head[MAX], down[MAX], cnt;

struct edge {
    int next, to, flow;
} a[MAX * 10];

void clean() {
    cnt = 1;
    ANS = SUM = 0;
    memset(gap, 0, sizeof(gap));
    memset(d, 0, sizeof(d));
    memset(a, 0, sizeof(a));
    memset(head, 0, sizeof(head));
    memset(down, 0, sizeof(down));
}

void add(int x, int y, int z) {
    a[++cnt].next = head[x];
    a[cnt].to = y;
    a[cnt].flow = z;
    head[x] = cnt;
    a[++cnt].next = head[y];
    a[cnt].to = x;
    a[cnt].flow = 0;
    head[y] = cnt;
}

int dfs(int x, int maxf, int to) {
    if (x == to)
        return maxf;
    int ans = 0, dlt;
    for (int i = head[x]; i; i = a[i].next) {
        int t = a[i].to;
        if (a[i].flow && d[x] == d[t] + 1) {
            dlt = dfs(t, std::min(maxf, a[i].flow), to);
            ans += dlt;
            maxf -= dlt;
            a[i].flow -= dlt;
            a[i ^ 1].flow += dlt;
            if (!maxf || d[S] == n + 2)
                return ans;
        }
    }
    gap[d[x]]--;
    if (!gap[d[x]])
        d[S] = n + 2;
    gap[++d[x]]++;
    return ans;
}

int sap(int st, int to) {
    int ans = 0;
    gap[0] = n + 2;
    while (d[st] < n + 2)
        ans += dfs(st, 0x3f3f3f3f, to);
    return ans;
}

int main() {
    int I, x, y, z, u;
    scanf("%d", &I);
    while (I--) {
        clean();
        scanf("%d%d", &n, &m);
        S = n + 1;
        T = n + 2;
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d%d", &x, &y, &z, &u);
            down[x] -= z;
            down[y] += z;
            add(x, y, u - z);
        }
        for (int i = 1; i <= n; i++) {
            if (down[i] > 0)
                add(S, i, down[i]), SUM += down[i];
            else
                add(i, T, -down[i]);
        }
        ANS = sap(S, T);
        if (ANS == SUM)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}