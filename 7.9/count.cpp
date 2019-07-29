// count.cpp
#include <iostream>
#include <fstream>

//#define debug

#ifndef debug

std::ifstream in("count.in");
std::ofstream out("count.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Mod = 124567;
long long a[1001][1001];
long long b = 0, c = 0, m, n;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m;
	a[2][0] = a[2][1] = 1;
    for (int i = 3; i <= n; i++)
    	for (int j = 0; j <= m; j++) {
    		b = j - i;
    		if (b < 0)
    			b = 0;
    		else
    			b = j - i + 1;
    		for (int k = b; k <= j; k++)
    			c += a[i - 1][k];
    		a[i][j] = c;
    		c = 0;
		}
	out << a[n][m] << '\n';
    return 0;
}
