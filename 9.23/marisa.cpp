// marisa.cpp
#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <algorithm>

//#define debug

#ifndef debug

std::ifstream in("marisa.in");
std::ofstream out("marisa.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 2005;
double const Pi = 3.1415926;

struct mob {
    int x;
	int y;
	int v;
	int m;
    double b;
} a[Maxn];

struct rec {
    int v,m;
} ff[Maxn];

int b[Maxn], n;
double alpha;
double f[Maxn];

bool comp1(mob const &a, mob const &b) { return a.x < b.x; }
bool comp2(mob const &a, mob const &b) { return a.b < b.b; }

inline double clac(int l, int r) {
    double x = ff[r].v - ff[l-1].v, y = ff[r].m - ff[l-1].m;
    return (double)x * y / (r - l + 1);
}
int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	in >> n;
    for (int i = 1; i <= n; i++)
		in >> a[i].x >> a[i].y >> a[i].v >> a[i].m; 
    in >> alpha;
    if (alpha == 90)
		std::sort(a + 1, a + n + 1, comp1);
    else {
        alpha = tan((double) alpha * Pi /180);
        for (int i = 1; i <= n; i++)
			a[i].b = -alpha * a[i].x + a[i].y;
        std::sort(a + 1, a + n + 1, comp2);
    }
    for (int i = 1; i <= n; i++) {
        ff[i].v += ff[i-1].v + a[i].v;
        ff[i].m += ff[i-1].m + a[i].m;
    }
    for (int i = 1; i <= n; i++)
		f[i] = -2147483647;
    f[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= i - 1; j++)
            if (a[i].x == a[j].x && a[i].y == a[j].y)
				break;
            else
				f[i] = std::max(f[i], f[j] + clac(j + 1, i));
    out << std::fixed << std::setprecision(3) << f[n] << '\n';
    return 0;
}
