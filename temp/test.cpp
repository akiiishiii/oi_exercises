#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;
const int maxn = 111;
const int maxm = 1111;

struct pp {
    int a, b, c;
    bool operator<(const pp &x) const { return c < x.c; }
} e[maxm];

int n, m;
int mod;
long long f[maxn], U[maxn], vst[maxn];
long long g[maxn][maxn], c[maxn][maxn];
vector<int> v[maxn];
int find(int x, long long f[]) {
    if (x == f[x])
        return x;

    return f[x] = find(f[x], f);
}
long long det(long long a[][111], int n) {
    int i, j;
    long long ret = 1;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            a[i][j] %= mod;
    for (i = 1; i < n; i++) {
        for (j = i + 1; j < n; j++)
            while (a[j][i]) {
                int t = a[i][i] / a[j][i];
                for (int k = i; k < n; k++)
                    a[i][k] = (a[i][k] - a[j][k] * t) % mod;
                for (int k = i; k < n; k++)
                    swap(a[i][k], a[j][k]);
                ret = -ret;
            }
        if (a[i][i] == 0)
            return 0;
        ret = ret * a[i][i] % mod;
    }
    return (ret + mod) % mod;
}
void solve() {
    sort(e, e + m);
    for (int i = 1; i <= n; i++) {
        f[i] = i, vst[i] = 0;
    }
    long long ed = -1;
    long long ans = 1;
    for (int k = 0; k <= m; k++) {
        if (e[k].c != ed || k == m) {
            for (int i = 1; i <= n; i++) {
                if (vst[i]) {
                    long long u = find(i, U);
                    v[u].push_back(i);
                    vst[i] = 0;
                }
            }
            for (int i = 1; i <= n; i++) {
                if (v[i].size() > 1) {
                    for (int a = 1; a <= n; a++)
                        for (int b = 1; b <= n; b++)
                            c[a][b] = 0;
                    int len = v[i].size();
                    for (int a = 0; a < len; a++)
                        for (int b = a + 1; b < len; b++) {
                            int a1 = v[i][a];
                            int b1 = v[i][b];
                            c[a][b] = (c[b][a] -= g[a1][b1]);
                            c[a][a] += g[a1][b1];
                            c[b][b] += g[a1][b1];
                        }
                    long long ret = (long long)det(c, len);
                    ans = (ans * ret) % mod;
                    for (int a = 0; a < len; a++)
                        f[v[i][a]] = i;
                }
            }
            for (int i = 1; i <= n; i++) {
                U[i] = f[i] = find(i, f);
                v[i].clear();
            }
            if (k == m)
                break;
            ed = e[k].c;
        }
        int a = e[k].a;
        int b = e[k].b;
        int a1 = find(a, f);
        int b1 = find(b, f);
        if (a1 == b1)
            continue;
        vst[a1] = vst[b1] = 1;
        U[find(a1, U)] = find(b1, U);
        g[a1][b1]++;
        g[b1][a1]++;
    }
    int flag = 0;
    for (int i = 2; i <= n && !flag; i++)
        if (U[i] != U[i - 1])
            flag = 1;
    if (m == 0)
        flag = 1;
    printf("%lld\n", flag ? 0 : ans % mod);
}
int main() {
    mod = 31011;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        scanf("%d%d%d", &e[i].a, &e[i].b, &e[i].c);
    solve();
    return 0;
}