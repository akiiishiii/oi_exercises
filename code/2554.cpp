// 2554.cpp
#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

int const Maxnm = 16, Maxp = 11;
int n, m, p, tot;
int mat[Maxnm * Maxnm][Maxnm * Maxnm], num[Maxnm][Maxnm], head[230401], ver[600000], edge[600000], Next[600000], d[230401];
bool v[230401];
std::vector<std::pair<int, int> > key[Maxp];
std::queue<int> q;

void add(int x, int y, int z) {	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
void spfa();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    memset(mat, 0, sizeof(mat));
    memset(num, 0, sizeof(num));
    int k, s, ans = 0x3f3f3f3f, dlayer = m * n, layer = 1 << p;
    std::cin >> n >> m >> p >> k;
    for (int i = 1, tmp = 0; i <= n; i++)
        for (int j = 1; j <= n; j++)
            num[i][j] = ++tmp;
    for (int i = 0, x1, y1, x2, y2, g; i < k; i++) {
        std::cin >> x1 >> y1 >> x2 >> y2 >> g;
        if (g)
            mat[num[x1][y1]][num[x2][y2]] = mat[num[x2][y2]][num[x1][y1]] = g;
        else
            mat[num[x1][y1]][num[x2][y2]] = mat[num[x2][y2]][num[x1][y1]] = -1;
    }
    std::cin >> s;
    for (int i = 0, x, y, pi; i < s; i++) {
        std::cin >> x >> y >> pi;
        key[pi].push_back(std::make_pair(x, y));
    }
    bool taken[15] = {false};
    for (int t = 0; t < layer; t++) {
        for (int i = 1; i <= p; i++)
            taken[i] = bool(t & (1 << (i - 1)));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                if (num[i][j + 1] && mat[num[i][j]][num[i][j + 1]] != -1)
                    if (!mat[num[i][j]][num[i][j + 1]] || taken[mat[num[i][j]][num[i][j + 1]]])
                        add(t * dlayer + num[i][j], t * dlayer + num[i][j + 1], 1), add(t * dlayer + num[i][j + 1], t * dlayer + num[i][j], 1);
                if (num[i + 1][j] && mat[num[i][j]][num[i + 1][j]] != -1)
                    if (!mat[num[i][j]][num[i + 1][j]] || taken[mat[num[i][j]][num[i + 1][j]]])
                        add(t * dlayer + num[i][j], t * dlayer + num[i + 1][j], 1), add(t * dlayer + num[i + 1][j], t * dlayer + num[i][j], 1);
            }
        for (int i = 1; i <= p; i++)
            if (!taken[i])
                for (int j = 0, tmp = t + (1 << (i - 1)); j < int(key[i].size()); j++)
                    add(t * dlayer + num[key[i][j].first][key[i][j].second], tmp * dlayer + num[key[i][j].first][key[i][j].second], 0);
    }
    spfa();
    for (int i = 0; i < layer; i++)
        ans = std::min(ans, d[i * dlayer + num[n][m]]);
    if (ans < 0x3f3f3f3f)
        std::cout << ans << '\n';
    else
        std::cout << "-1\n";
    return 0;
}

void spfa() {
	memset(d, 0x3f, sizeof(d));
	memset(v, 0, sizeof(v));
	d[1] = 1; v[1] = 1;
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