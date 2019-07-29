// cut.cpp
#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>

//#define debug

#ifndef debug

std::ifstream in("cut.in");
std::ofstream out("cut.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, m, ns = 1, ms = 1, dn = 1, dm = 1;
long long ans = 0;
int cn[2001], cm[2001];

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	in >> n >> m;
	for (int i = 1; i < n; i++)
		in >> cn[i];
	for (int i = 1; i < m; i++)
		in >> cm[i];
	std::sort(cn + 1, cn + n + 1, std::greater<int>());
	std::sort(cm + 1, cm + m + 1, std::greater<int>());
	while (dn < n && dm < m) {
		if (cn[dn] > cm[dm])
			ans += cn[dn++] * ns, ms++;
		else if (cn[dn] < cm[dm])
			ans += cm[dm++] * ms, ns++;
		else {
			if (ms >= ns)
				ans += cn[dn++] * ns, ms++;
			else
				ans += cm[dm++] * ms, ns++;
		}
	}
	while (dn < n)
		ans += cn[dn++] * ns; 
	while (dm < m)
		ans += cm[dm++] * ms;
	out << ans << '\n';
	return 0;
}
