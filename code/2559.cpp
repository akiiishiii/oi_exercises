// 2559.cpp
#include <queue>
#include <cstring>
#include <iostream>

int const Maxn = 105, Maxm = 15005;
int head[Maxn], ver[Maxm << 1], flow[Maxm << 1], Next[Maxm << 1], cash[Maxm << 1], tot = 1;
int d[Maxn], p[Maxn], f[Maxn];
bool v[Maxn];
int n, m, s, t;

inline void add(int s, int t, int p, int w);
bool spfa();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int maxf = 0, minc = 0;
    int sum = 0, ave;
    std::cin >> n;
    s = 0, t = n + 1;
    for (int i = 1; i <= n; i++) {
        std::cin >> f[i];
        sum += f[i];
    }
    ave = sum / n;
    for (int i = 1, y; i <= n; i++) {
        if (ave < f[i])
            add(s, i, f[i] - ave, 0);
        else if (ave > f[i])
            add(i, t, ave - f[i], 0);
        if (i == n)
            y = 1;
        else
            y = i + 1;
        add(i, y, 0x3f3f3f3f, 1);
        if (i == 1)
            y = n;
        else
            y = i - 1;
        add(i, y, 0x3f3f3f3f, 1);
    }
    while (spfa()) {
        int pre, dlt = 0x3f3f3f3f;
        for (int i = t; i != s; i = ver[pre ^ 1])
            pre = p[i], dlt = std::min(dlt, flow[pre]);
        for (int i = t; i != s; i = ver[pre ^ 1])
            pre = p[i], flow[pre] -= dlt, flow[pre ^ 1] += dlt;
        maxf += dlt;
        minc += d[t] * dlt;
    }
    std::cout << minc << '\n';
    return 0;
}

inline void add(int s, int t, int p, int w) {
    ver[++tot] = t, flow[tot] = p, cash[tot] = w, Next[tot] = head[s], head[s] = tot;
    ver[++tot] = s, flow[tot] = 0, cash[tot] = -w, Next[tot] = head[t], head[t] = tot;
}

bool spfa() {
    std::queue<int> q;
    memset(v, false, sizeof v);
    memset(p, false, sizeof p);
    memset(d, 0x3f, sizeof(d));
    d[s] = 0, v[s] = true;
    q.push(s);
    while (q.size()) {
        int x = q.front(); q.pop();
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