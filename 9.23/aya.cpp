// aya.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>

//#define debug

#ifndef debug

std::ifstream in("aya.in");
std::ofstream out("aya.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, m, r, c, num[1001][1001], s[1001][1001], ans = 0;

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	memset(s, 0, sizeof(s));
	in >> n >> m >> r >> c;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			in >> num[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			s[i][j] = s[i - 1][j] + s[i][j - 1] +num[i][j] - s[i - 1][j - 1];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			ans = std::max(ans, s[std::min(i + r - 1, n)][std::min(j + c - 1, m)] - s[i - 1][std::min(j + c - 1, m)] - s[std::min(i + r - 1, n)][j - 1] + s[i - 1][j - 1]);
	out << ans << '\n';
	return 0;
}
