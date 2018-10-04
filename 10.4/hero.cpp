// hero.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <functional>

#define debug

#ifndef debug

std::ifstream in("hero.in");
std::ofstream out("hero.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

struct edge {
    int u;
    int v;
    int z;
};

struct compare : public std::binary_function<edge, edge, bool> {
    bool operator()(edge const &a, edge const &b) { return a.z == b.z ? a.u < b.u : a.z < b.z; }
};


int n, k;

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
    memset(d, -1, sizeof(d));
    in >> n >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            in >> d[i][j];

    return 0;
}