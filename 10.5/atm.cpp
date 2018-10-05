// atm.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include <queue>
#include <vector>

//#define debug

#ifndef debug

std::ifstream in("atm.in");
std::ofstream out("atm.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const N = 500010, M = 500010;
int ver[M], Next[M], head[N], dfn[N], low[N], money[N];
int stack[N], ins[N], c[N], sum[N], d[N];
int vc[M], ec[M], nc[M], hc[N], tc;
int n, m, tot, num, top, cnt, s, p;
bool v[N];
std::queue<int> q;

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
inline void add_c(int x, int y, int z) { vc[++tc] = y, ec[tc] = z, nc[tc] = hc[x], hc[x] = tc; }
void spfa();
void tarjan(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y;
		in >> x >> y;
		add(x, y);
	}
    for (int i = 1; i <= n; i++)
        in >> money[i];
	for (int i = 1; i <= n; i++)
		if (!dfn[i]) tarjan(i);
	for (int x = 1; x <= n; x++)
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i];
			if (c[x] == c[y]) continue;
			add_c(c[x], c[y], -sum[c[y]]);
		}
    in >> s;
    spfa();
    in >> p;
    int ans = 0;
    for (int i = 1, tmp; i <= p; i++) {
        in >> tmp;
        if (-d[c[tmp]] > ans)
            ans = -d[c[tmp]];
    }
    out << ans << '\n';
    return 0;
}

void spfa() {
	memset(d, 0x3f, sizeof(d));
	memset(v, 0, sizeof(v));
	d[c[s]] = -sum[c[s]]; v[c[s]] = 1;
	q.push(1);
	while (q.size()) {
		int x = q.front(); q.pop();
		v[x] = 0;
		for (int i = hc[x]; i; i = nc[i]) {
			int y = vc[i], z = ec[i];
			if (d[y] > d[x] + z) {
				d[y] = d[x] + z;
				if (!v[y]) q.push(y), v[y] = 1;
			}
		}
	}
}


void tarjan(int x) {
	dfn[x] = low[x] = ++num;
	stack[++top] = x, ins[x] = 1;
	for (int i = head[x]; i; i = Next[i])
		if (!dfn[ver[i]]) {
			tarjan(ver[i]);
			low[x] = std::min(low[x], low[ver[i]]);
		}
		else if (ins[ver[i]])
			low[x] = std::min(low[x], low[ver[i]]);
	if (dfn[x] == low[x]) {
		cnt++; int y;
		do {
			y = stack[top--], ins[y] = 0;
            c[y] = cnt, sum[cnt] += money[y];
        } while (x != y);
	}
}
