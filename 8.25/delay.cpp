// delay.cpp
#include <algorithm> 
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>

//#define debug

#ifndef debug

std::ifstream in("delay.in");
std::ofstream out("delay.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 20005, Maxm = 100005;
int head[Maxn], ver[Maxm], edge[Maxm], age[Maxm], Next[Maxm];
int d[Maxn];
bool v[Maxn];
int n, m, t, tot;

struct Edge {
	int s, t, l, y;
	Edge() {}
	Edge(int _s, int _t, int _l, int _y) : s(_s), t(_t), l(_l), y(_y) {}
	bool operator<(Edge const &e) const { return y < e.y; }
} e[Maxm];

inline void add(int x, int y, int z, int a);
void spfa(int midy);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m >> t;
	for (int i = 1, s, tt, l ,y; i <= m; i++) {
		in >> s >> tt >> l >> y;
		add(s, tt, l, y);
		e[i] = Edge(s, tt, l ,y);
	}
    spfa(0);
    if (d[n] >= t) {
        out << "-1 " << d[n] << '\n';
        return 0;
    }
    std::sort(e + 1, e + m + 1);
	int l = 1, r = m;
    while (l <= r) {
        int mid = l + r >> 1;
        spfa(e[mid].y);
        if (d[n] >= t)
            r = mid - 1;
        else
            l = mid + 1;
    }
    out << e[l].y << '\n';
    return 0;
}

inline void add(int x, int y, int z, int a) {
	ver[++tot] = y, edge[tot] = z, age[tot] = a, Next[tot] = head[x], head[x] = tot;
}

void spfa(int midy) {
	memset(d, 0x3f, sizeof d);
	memset(v, false, sizeof v);
    std::queue<int> q;
    q.push(1);
    v[1] = true;
    d[1] = 0;
    while (q.size()) {
        int x = q.front();
        q.pop();
        v[x] = false;
        for (int i = head[x]; i; i = Next[i]) {
        	int y = ver[i], z = edge[i], a = age[i];
            if (a <= midy)
                z = 0x3f3f3f3f;
            if (d[y] >= d[x] + z) {
                if (!v[y]) {
                    v[y] = true;
                    q.push(y);
                }
                d[y] = d[x] + z;
            }
		}
    }
}
