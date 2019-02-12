// 2558_.cpp
#include <cstring>
#include <iostream>
#include <queue>

int const Maxn = 205, Maxm = 5000005;
int head[Maxn], ver[Maxm << 1], flow[Maxm << 1], Next[Maxm << 1], cash[Maxm << 1], tot = 1;
int d[Maxn], p[Maxn];
int tmp[Maxn];
bool v[Maxn];
int n, s, t;

inline void add(int s, int t, int p, int w);
bool minspfa();
bool maxspfa();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int minc = 0, maxc = 0;
    std::cin >> n, s = 2 * n + 1, t = 2 * n + 2;
    for (int i = 1, x; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> x, add(i, j + n, 0x3f3f3f3f, x);
    for (int i = 1; i <= n; i++)
        add(s, i, 1, 0), add(i + n, t, 1, 0);
    memcpy(tmp, flow, sizeof flow);
    while (minspfa()) {
        int pre, dlt = 0x3f3f3f3f;
        for (int i = t; i != s; i = ver[pre ^ 1])
            pre = p[i], dlt = std::min(dlt, flow[pre]);
        for (int i = t; i != s; i = ver[pre ^ 1])
            pre = p[i], flow[pre] -= dlt, flow[pre ^ 1] += dlt;
        minc += d[t] * dlt;
    }
    while (maxspfa()) {
        int pre, dlt = 0x3f3f3f3f;
        for (int i = t; i != s; i = ver[pre ^ 1])
            pre = p[i], dlt = std::min(dlt, tmp[pre]);
        for (int i = t; i != s; i = ver[pre ^ 1])
            pre = p[i], tmp[pre] -= dlt, tmp[pre ^ 1] += dlt;
        maxc += d[t] * dlt;
    }
    std::cout << minc << ' ' << maxc << '\n';
    return 0;
}

inline void add(int s, int t, int p, int w) {
    ver[++tot] = t, flow[tot] = p, cash[tot] = w, Next[tot] = head[s], head[s] = tot;
    ver[++tot] = s, flow[tot] = 0, cash[tot] = -w, Next[tot] = head[t], head[t] = tot;
}

bool minspfa() {
    std::queue<int> q;
    memset(v, false, sizeof v);
    memset(p, false, sizeof p);
    memset(d, 0x3f, sizeof(d));
    d[s] = 0, v[s] = true;
    q.push(s);
    while (q.size()) {
        int x = q.front();
        q.pop();
        v[x] = false;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = cash[i];
            if (d[y] > d[x] + z && flow[i]) {
                d[y] = d[x] + z;
                p[y] = i;
                if (!v[y])
                    q.push(y), v[y] = true;
            }
        }
    }
    return d[t] < 0x3f3f3f3f;
}

bool maxspfa() {
    std::queue<int> q;
    memset(v, false, sizeof v);
    memset(p, false, sizeof p);
    memset(d, 0xcf, sizeof(d));
    d[s] = 0, v[s] = true;
    q.push(s);
    while (q.size()) {
        int x = q.front();
        q.pop();
        v[x] = false;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = cash[i];
            if (d[y] < d[x] + z && tmp[i]) {
                d[y] = d[x] + z;
                p[y] = i;
                if (!v[y])
                    q.push(y), v[y] = true;
            }
        }
    }
    return d[t] > 0xcfcfcfcf;
}