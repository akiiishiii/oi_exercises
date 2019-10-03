// route.cpp
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstdlib>

//#define debug

#ifndef debug

std::ifstream in("route.in");
std::ofstream out("route.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 200005;
int head[Maxn], ver[Maxn << 1], Next[Maxn << 1];
bool norm[Maxn << 1];
int n, m, tot;

inline void add(int x, int y, bool b) {
	ver[++tot] = y, norm[tot] = b, Next[tot] = head[x], head[x] = tot;
}

long long random(long long n) { return (long long)rand() * rand() % n; }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m;
    for (int i = 1, x, y; i <= m; i++)
    	in >> x, y, add(x, y, i < n);
    out << random(200) << '\n';
    return 0;
}
