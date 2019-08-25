// tree.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("tree.in");
std::ofstream out("tree.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const mod = 1000000000;

int n, f[3005][3005], maxx[3005], minn[3005], ans[3005], d;

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	maxx[1] = minn[1] = 1;
	f[0][0] = f[1][1] = 1;
	for(d = 2; d; d++) {
		minn[d] = minn[d - 1] + minn[d - 2] + 1;
		if (minn[d] > 3000)
			break;
		maxx[d] = maxx[d - 1] + maxx[d - 1] + 1;
		if (maxx[d] > 3000)
			maxx[d] = 3000;
		for (int i = minn[d]; i <= maxx[d]; i++)
			for (int j = minn[d - 1]; j <= maxx[d - 1] && j < i; j++) {
				f[i][d] = ((long long)f[j][d - 1] * f[i - 1 - j][d - 2] * 2 + f[i][d]) % mod;
				f[i][d] = (f[i][d] + (long long)f[j][d - 1] * f[i - 1 - j][d - 1]) % mod;
			}
	}
	for (int i = 1; i <= 3000; i++)
		for (int j = 1; j <= d; j++)
			ans[i] = (ans[i] + f[i][j])%mod;
	while (in >> n && n)
		out << ans[n] << '\n';
	return 0;
}
