// cdgame.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("cdgame.in");
std::ofstream out("cdgame.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int t, n;
bool f[1000001] = {false};

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> t;
    for (int i = 1; i <= 1000000; i++) {
        int maxn = 0, minn = 2147483647, x = i;
        while (x) {
            if (x % 10) {
                maxn = std::max(maxn, x % 10);
                minn = std::min(minn, x % 10);
            }
            x /= 10;
        }
        f[i] = !f[i - maxn] || !f[i - minn];
    }
    for (int i = 1; i <= t; i++) {
        in >> n;
        out << (f[n] ? "YES\n" : "NO\n");
    }
}