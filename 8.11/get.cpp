// get.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("get.in");
std::ofstream out("get.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int a[200005], f[200005], n;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n;
    for (int i = 1; i <= n; i++)
        in >> a[i], a[n + i] = a[i];
    for (int i = 2; i <= n << 1; i++)
        for (int j = 1; j < i; j++)
            if (std::abs(a[i] - a[j]) != 1)
                f[i] = std::max(f[j] + 1, f[i]);
    out << (f[n << 1] >> 1) << '\n';
    return 0;
}