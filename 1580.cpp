// 1580.cpp
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

const int N = 100010, M = 500010;

int head[N], ver[M], edge[M], Next[M], d[N];
int n, m, tot;
std::queue<int> q;
bool v[N];

void add(int x, int y, int z) {	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
void spfa();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
	std::cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
        std::cin >> x >> y >> z;
		add(x, y, z);
        add(y, x, z);
    }
	spfa();
    std::cout << d[n] << '\n';
    return 0;
}

void spfa() {
	memset(d, 0x3f, sizeof(d));
	memset(v, 0, sizeof(v));
	d[1] = 0; v[1] = 1;
	q.push(1);
	while (q.size()) {
		int x = q.front(); q.pop();
		v[x] = 0;
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i], z = edge[i];
			if (d[y] > d[x] + z) {
				d[y] = d[x] + z;
				if (!v[y]) q.push(y), v[y] = 1;
			}
		}
	}
}