// station.cpp
#include <iostream>
#include <fstream>

#define debug

#ifndef debug

std::ifstream in("station.in");
std::ofstream out("station.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, m, k;
bool mamapp[1001][2001], now[2001];

bool check(int r);

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	char tmp;
	in >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= 2 * m; j++)
			in >> tmp, mamapp[i][j] = (tmp == '1');
	for (int i = 1; i <= m; i++) {
		int miid = (n + 1) >> 1, cnt = 0;
		for (int j = miid; j <= n; j++)
			now[++cnt] = mamapp[j][i];
		for (int j = n; j >= 1; j--)
			now[++cnt] = mamapp[j][i + m];
		for (int j = 1; j < miid; j++)
			now[++cnt] = mamapp[j][i];
		int l = 1, r = n / 2, mid;
		while (l <= r) {
			mid = (l + r) / 2;
			if (check(mid))
				r = mid - 1;
			else
				l = mid + 1;
		}
		out << l << '\n';
	}
	return 0;
}

bool check(int r) {
	int i = 1, ans = 1, j;
	while (true) {
		if (i + 2 * r >= 2 * n)
			break;
		for (j = std::min(i + 2 * r + 1, 2 * n); j > i; j--)
			if (now[j])
				break;
		if (j <= i)
			return 0;
		i = j;
		ans++;
	}
	return (ans <= k);
}
