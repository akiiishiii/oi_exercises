// game.cpp
#include <iostream>
#include <fstream>
#include <algorithm>

//#define debug

#ifndef debug

std::ifstream in("game.in");
std::ofstream out("game.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int n, k, num[100001] = {0}, res[100001] = {0}, ans = 0;
    in >> n >> k;
    for (int i = 1; i <= n; i++)
        in >> num[i];
    std::sort(num + 1, num + n + 1);
    for (int i = 1; i < n; i++)
        res[i] = num[i + 1] - num[i];
    std::sort(res + 1, res + n);
    for (int i = 1; i < 1 + k; i++)
        ans += res[i];
    out << ans << '\n';
    return 0;
}
