// 1950.cpp
#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <cctype>

int bx, by, sx, sy, tx, ty;
int m, n, dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
bool mark[25][25][4];
int vis[25][25];
char map[25][25];

struct boxes {
	int x, y, xx, yy;
	std::string ans;
} bnow, beed;

struct men {
	int x, y;
	std::string ans;
} ynow, yeed;

bool expand(int s, int e, int aa, int bb, int ss, int ee);
bool bfs();

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			std::cin >> map[i][j];
			if (map[i][j] == 'S')
				sx = i, sy = j;
			else if (map[i][j] == 'T')
				tx = i, ty = j;
			else if (map[i][j] == 'B')
				bx = i, by = j;
		}
	if(bfs())
		std::cout << bnow.ans << '\n';
	else
		std::cout << "Impossible!\n";
	return 0;
}

bool expand(int s, int e, int aa, int bb, int ss, int ee) {
	if (s < 0 || s > m || e < 0 || e > n || map[s][e] == '#')
		return false;
	ynow.x = ss, ynow.y = ee;
	ynow.ans = "";
	memset(vis, 0, sizeof(vis));
	vis[aa][bb] = vis[ss][ee] = 1;
	man.push(ynow);
	while (man.size()) {
		ynow = man.front();
		man.pop();
		if (ynow.x == s && ynow.y == e)
			return true;
		for (int i = 0; i < 4; i++) {
			yeed.x = ynow.x + dir[i][0], yeed.y = ynow.y + dir[i][1];
			if (yeed.x > 0 && yeed.x <= m && yeed.y > 0 && yeed.y <= n && !vis[yeed.x][yeed.y] && map[yeed.x][yeed.y] != '#') {
				yeed.ans = ynow.ans + op[i];
				vis[yeed.x][yeed.y] = 1;
				man.push(yeed);
			}
		}
	}
	return false;
}

bool bfs() {
	std::queue<boxes> box;
	bnow.x = bx, bnow.y = by;
	bnow.ans = "";
	bnow.xx = sx, bnow.yy = sy;
	box.push(bnow);
	while (!box.empty()) {
		bnow = box.front();
		box.pop();
		if (bnow.x == tx && bnow.y == ty)
			return true;
		for (int i = 0; i < 4; i++) {
			beed.x = bnow.x + dir[i][0];
			beed.y = bnow.y + dir[i][1];
			if (beed.x > 0 && beed.x <= m && beed.y > 0 && beed.y <= n && !mark[beed.x][beed.y][i] && map[beed.x][beed.y] != '#') {
				if (expand(beed.x - 2 * dir[i][0], beed.y - 2 * dir[i][1], bnow.x, bnow.y, bnow.xx, bnow.yy)) {
					beed.yy = bnow.y;
					beed.ans = bnow.ans + ynow.ans + toupper(op[i]);
					mark[beed.x][beed.y][i] = true;
					box.push(beed);
				}
			}
		}
	}
	return false;
}
