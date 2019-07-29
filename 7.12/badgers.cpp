// badgers.cpp
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>

//#define debug

#ifndef debug

std::ifstream in("badgers.in");
std::ofstream out("badgers.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, tot, ans = 0;
int h[51], g[51], tmp[51];

bool chk(int x);

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	in >> n >> tot;
	for (int i = 1; i <= n; i++)
		in >> h[i];
	for (int i = 1; i <= n; i++)
		in >> g[i];
	int l = 0, r = n, mid, ans = 0;
	while (l <= r) {
		mid = (l + r) / 2;
		if (chk(mid)) {
			ans = mid;
			l = mid + 1;
		} else
			r = mid - 1;
	}
	out << ans << '\n';
	return 0;
}

bool chk(int x) {
	for (int i = 1; i <= n; i++)
		tmp[i] = h[i] + g[i] * (x - 1);
	std::sort(tmp + 1, tmp + n + 1);
	int ans = 0;
	for (int i = 1; i <= x; i++)
		ans += tmp[i];
	return (ans <= tot);
}
