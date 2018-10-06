#include <algorithm>
#include <cstdio>
#define maxn 1000005
using namespace std;
int n, m, ans;
int fir[maxn], nxt[2 * maxn], to[2 * maxn], w[2 * maxn], tot;
long long f[maxn];
int S1[maxn], S2[maxn], h1, h2, t1 = -1, t2 = -1;
inline void add(int x, int y, int z)
{
    nxt[++tot] = fir[x];
    fir[x] = tot;
    to[tot] = y;
    w[tot] = z;
}
inline void dfs(int u, int past, long long s, int &id)
{
    if (s > f[id])
        id = u;
    if (s > f[u])
        f[u] = s;
    for (int i = fir[u]; i; i = nxt[i])
        if (to[i] != past)
            dfs(to[i], u, s + w[i], id);
}
int main()
{
    int x, y, L;
    in >>n >> m;
    for (int i = 2; i <= n; i++)
        in >> x>>y, add(i, x, y), add(x, i, y);
    x = y = 0, dfs(1, 0, 0, x);
    dfs(x, 0, 0, y);
    dfs(y, 0, 0, x);
    L = 1;
    for (int i = 1; i <= n; i++)
    {
        while (t1 >= h1 && f[S1[t1]] <= f[i])
            t1--;
        S1[++t1] = i;
        while (t2 >= h2 && f[S2[t2]] >= f[i])
            t2--;
        S2[++t2] = i;
        while (f[S1[h1]] - f[S2[h2]] > m)
        {
            if (L == S1[h1])
                h1++;
            if (L == S2[h2])
                h2++;
            L++;
        }
        ans = max(ans, i - L + 1);
    }
    printf("%d", ans);
}
