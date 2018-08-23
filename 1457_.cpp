#include <bits/stdc++.h>
using namespace std;

long long n, m, x[1005], y[1005], fa[200005];
double ans = 0;

struct edge
{
    long long u, v;
    double w;
} e[2000005];

long long aim = 0;

void add(long long u, long long v, double w)
{
    e[++aim].u = u;
    e[aim].v = v;
    e[aim].w = w;
}

double f(long long a, long long b) { return double(sqrt((x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]))); }
bool cmp(edge a, edge b) { return a.w < b.w; }
long long get(long long x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }

int main()
{
    cin >> m >> n;
    for (long long i = 1; i <= n; i++)
        cin >> x[i] >> y[i];
    for (long long i = 1; i <= n; i++)
        for (long long j = i + 1; j <= n; j++)
            add(i, j, f(i, j));
    sort(e + 1, e + 1 + aim, cmp);
    long long cnt = 0;
    for (long long i = 1; i <= n; i++)
        fa[i] = i;
    for (long long i = 1; i <= aim; i++)
    {
        long long a = get(e[i].u), b = get(e[i].v);
        if (a != b)
        {
            fa[a] = b;
            if (cnt <= n - m - 1)
                ans = e[i].w;
            cnt++;
        }
        if (cnt == n - 1)
            break;
    }
    printf("%.2f", ans);
    return 0;
}