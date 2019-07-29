#include<iostream>
#include<cstdio>
// 1170.cpp
#include <iostream>
#include <iomanip>
#include <queue>

int ver[200002], edge[200002], Next[200002], head[100002];
int out[100002], deg[100002];
int n, m, tot;
double dis[100002];
std::queue<int> q;

void add(int x, int y, int z) {	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		std::cin >> x >> y >> z;
		add(y, x, z);
		deg[x]++; out[x]++;
	}
	q.push(n); 
	while (q.size()) {
		int x = q.front(); q.pop();
		for (int i = head[x]; i; i = Next[i]) {
			int y = ver[i];
			dis[y] += (dis[x] + edge[i]) / deg[y];
			out[y]--;
			if (!out[y]) q.push(y);
		}
	}
	std::cout << std::fixed << std::setprecision(2) << dis[1] << '\n';
	return 0;
}
