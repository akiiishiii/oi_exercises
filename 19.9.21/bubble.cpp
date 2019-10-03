// bubble.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("bubble.in");
std::ofstream out("bubble.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, ans = 0, a[100005], f[100005], ff[100005];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n;
    for (int i = 1; i <= n; i++)
        in >> a[i];
    for (int i = 1; i <= n; i++)
		f[i] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i - 1; j++)
            if (a[j] < a[i] && f[j] + 1 > f[i])
				f[i] = f[j] + 1;
    for (int i = 1; i <= n; i++)
        if (f[i] > ans)
			ans = f[i];
	out << ans << '\n';
	for (int i = 1; i <= n; i++)
		ff[i] = 1;
    for (int i = n + 1; i >= 1; i--)
        for (int j = n; j >= i + 1; j--)
            if (a[j] > a[i] && ff[j] + 1 > ff[i])
				ff[i] = ff[j] + 1;
	for (int i = 1; i <= n; i++)
		if (f[i] + ff[i] == ans + 1)
			out << i << ' ';
	out << '\n';
    return 0;
}
