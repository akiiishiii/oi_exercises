// park.cpp
#include <iostream>
#include <fstream>

//#define debug

#ifndef debug

std::ifstream in("park.in");
std::ofstream out("park.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 100005, Maxm = 200005;
int head[Maxn], ver[Maxm], Next[Maxm], edge[Maxm];
int n, m, tot;



int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    return 0;
}
