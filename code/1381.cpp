// 1381.cpp
#include <queue>
#include <cstring>
#include <utility>
#include <iostream>

int d[510][510];
char mat[510][510];
bool v[510][510];
std::deque<std::pair<int, int> > q;
int r, c, li, ri;

inline bool chk(int x, int y);
inline void push(int x, int y, int v);

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int T;
	std::cin >> T;
	while (T--) {
		std::cin >> r >> c;
		if ((r + c) % 2) {
			for (int i = 0; i < r; i++)
				std::cin >> mat[i];
			std::cout << "NO SOLUTION\n";
		} else {
			for (int i = 0; i < r; i++)
				std::cin >> mat[i];
			q.push_back(std::make_pair(0, 0));
			memset(d, -1, sizeof d);
			d[0][0] = 0;
			memset(v, false, sizeof v);
			while (q.size()) {
				int cx = q.front().first, cy = q.front().second;
				q.pop_front();
				if (chk(cx - 1, cy - 1)) {
					if (mat[cx - 1][cy - 1] == '\\')
						push(cx - 1, cy - 1, d[cx][cy]);
					else
						push(cx - 1, cy - 1, d[cx][cy] + 1);
				}
				if (chk(cx - 1, cy + 1)) {
					if (mat[cx - 1][cy] == '/')
						push(cx - 1, cy + 1, d[cx][cy]);
					else
						push(cx - 1, cy + 1, d[cx][cy] + 1);
				}
				if (chk(cx + 1, cy - 1)) {
					if (mat[cx][cy - 1] == '/')
						push(cx + 1, cy - 1, d[cx][cy]);
					else
						push(cx + 1, cy - 1, d[cx][cy] + 1);
				}
				if (chk(cx + 1, cy + 1)) {
					if (mat[cx][cy] == '\\')
						push(cx + 1, cy + 1, d[cx][cy]);
					else
						push(cx + 1, cy + 1, d[cx][cy] + 1);
				}
			}
			std::cout << d[r][c] << '\n';
		}
	}
	return 0;
}

inline bool chk(int x, int y) {
	return x >= 0 && x <= r && y >= 0 && y <= c;
}

inline void push(int x, int y, int v) {
	if (d[x][y] < 0 || v < d[x][y]) {
		d[x][y] = v;
		if (li == ri || v > d[q.front().first][q.front().second])
			q.push_back(std::make_pair(x, y));
		else
			q.push_front(std::make_pair(x, y));
	}
}
