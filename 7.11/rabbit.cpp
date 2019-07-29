// rabbit.cpp
#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <functional>

//#define debug

#ifndef debug

std::ifstream in("rabbit.in");
std::ofstream out("rabbit.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, cnt;
int f[51][51];

struct yama {
	int x, y;
	int height;
	yama() { x = y = height = 0; }
	yama(int _x, int _y, int _h) : x(_x), y(_y), height(_h) {}
	bool operator>(yama const &y) const { return height > y.height; }
	inline friend int dist2(yama const &y1, yama const &y2) { return (std::abs(y1.x - y2.x) + std::abs(y1.y - y2.y)) * (std::abs(y1.x - y2.x) + std::abs(y1.y - y2.y)); }
} map[2501];

int dfs(int now);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n;
    int tmp;
    cnt = n * n;
    for (int i = 1; i <= n; i++)
    	for (int j = 1; j <= n; j++) {
    		in >> tmp;
    		map[(i - 1) * n + j] = yama(i, j, tmp);
		}
    std::sort(map + 1, map + cnt + 1, std::greater<yama>());
    dfs(1);
    out << f[map[1].x][map[1].y] << '\n';
    return 0;
}

int dfs(int now) {
	if (!f[map[now].x][map[now].y])
		for (int i = now + 1; i <= cnt; i++)
			f[map[now].x][map[now].y] = std::max(f[map[now].x][map[now].y], dfs(i) + dist2(map[now], map[i]));
	return f[map[now].x][map[now].y];
}
