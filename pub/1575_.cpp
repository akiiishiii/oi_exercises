#include <iostream>
const int Maxn = 10005;
struct edge
{
    int to, next;
} w[50005], fw[50005];
int Scc = 0, vst[Maxn] = {0}, h[Maxn] = {0}, fh[Maxn] = {0}, n, a[Maxn];
int cnt = 0, fcnt = 0, Out[Maxn] = {0}, wt[Maxn] = {0};
void addedge(int x, int y)
{
    cnt++;
    w[cnt].to = y;
    w[cnt].next = h[x];
    h[x] = cnt;
    fcnt++;
    fw[fcnt].to = x;
    fw[fcnt].next = fh[y];
    fh[y] = fcnt;
}
void Read()
{
    int i, x, m, y;
    scanf("%d%d", &n, &m);
    for (i = 1; i <= m; i++)
    {
        scanf("%d%d", &x, &y);
        addedge(x, y);
    }
    a[0] = 0;
}
void dfsOne(int x)
{
    int y, p;
    vst[x] = -1;
    for (p = h[x]; p; p = w[p].next)
    {
        y = w[p].to;
        if (vst[y] == 0)
            dfsOne(y);
    }
    a[++a[0]] = x;
}
void dfsTwo(int x)
{
    int y, p;
    vst[x] = Scc;
    wt[Scc]++;
    for (p = fh[x]; p; p = fw[p].next)
    {
        y = fw[p].to;
        if (vst[y] == -1)
            dfsTwo(y);
    }
}
void Solve()
{
    int i, p, y, num, ans = 0;
    for (i = 1; i <= n; i++)
        if (vst[i] == 0)
            dfsOne(i);
    for (i = n; i >= 1; i--)
        if (vst[a[i]] == -1)
        {
            Scc++;
            dfsTwo(a[i]);
        }
    for (i = 1; i <= n; i++) //统计出度
        for (p = h[i]; p; p = w[p].next)
        {
            y = w[p].to;
            if (vst[i] != vst[y])
                Out[vst[i]]++;
        }
    num = 0;
    for (i = 1; i <= Scc; i++) //统计出度为0的点个数
        if (Out[i] == 0)
        {
            num++;
            ans = wt[i];
        }
    if (num == 1)
        printf("%d\n", ans);
    else
        printf("0\n");
}
int main()
{
    Read();
    Solve();
}