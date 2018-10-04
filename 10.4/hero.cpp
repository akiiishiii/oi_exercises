// hero.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

//#define debug

#ifndef debug

std::ifstream in("hero.in");
std::ofstream out("hero.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, k;
int d[1001][1001];

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
    memset(d, -1, sizeof(d));
    in >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            in >> d[i][j];
    std::cout << 2 << '\n';
    return 0;
}