// 1428.cpp
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>

double a[110][110], d[110];
int x[110], y[110];
bool v[110];
int n, m;

void dijkstra(int s) {
    int k;
    memset(v, false, sizeof(v));
    for (int i = 0; i <= n; i++)
        d[i] = 10000000000;
	d[s] = 0;
	for (int i = 1; i < n; i++) {
		int x = 0;
		for (int j = 1; j <= n; j++)
			if (!v[j] && x > d[j]) {
                k = j;
                x = d[j];
            }
		v[x] = true;
		for (int y = 1; y <= n; y++)
			d[y] = std::min(d[y], d[k] + a[k][y]);
	}
}

double dis(int a, int b) { return sqrt((long long)(x[a] - x[b]) * (x[a] - x[b]) + (long long)(y[a] - y[b]) * (y[a] - y[b])); }

int main(int argc, char const *argv[]) {
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> x[i] >> y[i];
    std::cin >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        std::cin >> x >> y;
        a[x][y] = a[y][x] = dis(x, y);
    }
    int s, t;
    std::cin >> s >> t;
    dijkstra(s);
    std::cout << std::fixed << std::setprecision(2) << d[t] << '\n';
    return 0;
}