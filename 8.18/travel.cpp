// travel.cpp
#include <algorithm>
#include <iostream>
#include <fstream>

//#define debug

#ifndef debug

std::ifstream in("travel.in");
std::ofstream out("travel.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

struct er {
	int c, d;
	bool operator<(er const &e) const;
} e[1005];

int n, k;

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	in >> n;
	for (int i = 1; i <= n; i++)
		in >> e[i].c;
	for (int i = 1; i <= n; i++)
		in >> e[i].d;
	int ans = 0, cnt = 0;
	for (k = 1; k <= n; k++) {
		std::sort(e + 1, e + 1 + n);
		int sum = 0;
		for (int i = 1; i <= k; i++)
			sum += e[i].c - (k - 1) * e[i].d;
		if (sum > ans || (sum == ans && cnt < k)) {
			ans = sum;
			cnt = k;
		}
	}
	out << ans << '\n' << cnt << '\n';
	return 0;
}

bool er::operator<(er const &e) const {
	return c - (k - 1) * d > e.c - (k - 1) * e.d;
}
