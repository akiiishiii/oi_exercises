// lineup.cpp
#include <iostream>
#include <fstream>

#define debug

#ifndef debug

std::ifstream in("lineup.in");
std::ofstream out("lineup.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Mod=10007;
int f[2005], son[2005], c[2005][2005], n, a[2005][2005] = {0};

int dfs(int x);
void dp(int x);

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	int T, n, k, y;
	for (int i = 0; i <= 2000; i++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++)
			c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % Mod;
	}
	in >> T;
	for (int t = 1; t <= T; t++) {
		in >> n;
		for (int i = 1; i <= n; i++) {
			in >> k, a[i][0] = k;
			for (int j = 1; j <= k; j++)
				in >> y, a[i][j] = y;
		}
		dfs(1);
		dp(1);
		out << f[1] << '\n';
	}
	return 0;
}

int dfs(int x) {
	son[x] = 0;
	for (int i = 1; i <= a[x][0]; i++)
		son[x] += dfs(a[x][i]) + 1;
	return son[x];
}

void dp(int x) {
	int s = 0;
	f[x] = 1;
	for (int i = a[x][0]; i >= 1; i--) {
		dp(a[x][i]);
		s += son[a[x][i]];
		f[x] = (f[x] * c[s++][son[a[x][i]]] % Mod) * f[a[x][i]] % Mod;
	}
}
