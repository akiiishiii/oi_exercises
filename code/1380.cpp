// 1380.cpp
#include <iostream>
#include <cstring>
#include <queue>

struct status {
	int x, y, lie;
} st, ed;

char s[505][505];
int n, m, d[505][505][3];
std::queue<status> q;
int const next_x[3][4] = {{0, 0, -2, 1}, {0, 0, -1, 1}, {0, 0, -1, 2}};
int const next_y[3][4] = {{-2, 1, 0, 0}, {-1, 2, 0, 0}, {-1, 1, 0, 0}};
int const next_lie[3][4] = {{1, 1, 2, 2}, {0, 0, 1, 1}, {2, 2, 0, 0}};
int const dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

bool valid(int x, int y);
bool valid(status next);
int bfs();

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	while (std::cin >> n >> m && n) {
		for (int i = 1; i <= n; i++)
			std::cin >> (s[i] + 1);
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (s[i][j] == 'O') {
					ed.x = i, ed.y = j, ed.lie = 0, s[i][j] = '.';
				} else if (s[i][j] == 'X') {
					for (int k = 0; k < 3; k++) {
						int x = i + dx[k], y = j + dy[k];
						if (valid(x, y) && s[x][y] == 'X') {
							st.x = std::min(i, x), st.y = std::min(j, y), st.lie = k < 2 ? 1 : 2;
							s[i][j] = s[x][y] = '.';
							break;
						}
					}
					if (s[i][j] == 'X') {
						st.x = i, st.y = j, st.lie = 0;
					}
				}
		int ans = bfs();
		if (ans == -1)
			std::cout << "Impossible\n";
		else
			std::cout << ans << '\n';
	}
}

bool valid(int x, int y) {
	return x >= 1 && y >= 1 && x <= n && y <= m;
}

bool valid(status next) {
	return !(!valid(next.x, next.y) || (s[next.x][next.y] == '#') || (next.lie == 0 && s[next.x][next.y] != '.') || 
			(next.lie == 1 && s[next.x][next.y + 1] == '#') || (next.lie == 2 && s[next.x + 1][next.y] == '#'));
}

int bfs() {
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (int k = 0; k < 3; k++)
				d[i][j][k] = -1;
	while (q.size())
		q.pop();
	d[st.x][st.y][st.lie] = 0;
	q.push(st);
	while (q.size()) {
		status now = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			status next;
			next.x = now.x + next_x[now.lie][i];
			next.y = now.y + next_y[now.lie][i];
			next.lie = next_lie[now.lie][i];
			if (!valid(next))
				continue;
			if (d[next.x][next.y][next.lie] == -1) {
				d[next.x][next.y][next.lie] = d[now.x][now.y][now.lie]+1;
				q.push(next);
				if (next.x == ed.x && next.y == ed.y && next.lie == ed.lie)
					return d[next.x][next.y][next.lie];
			}
		}
	}
	return -1;
}
