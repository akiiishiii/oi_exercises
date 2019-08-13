// light.cpp
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <utility>

//#define debug

#ifndef debug

std::ifstream in("light.in");
std::ofstream out("light.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 1100001;
double a, b, c, d;
int ans = 0, n;
double ls[Maxn];
std::pair<double, double> p[Maxn];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(nullptr);
    in >> a >> b >> d >> n;
    for (int i = 1; i <= n; i++)
        in >> p[i].first >> p[i].second;
    d = d * (c = sqrt(a * a + b * b));
    for (int i = 1; i <= n; i++)
        ls[i] = p[i].first * a + p[i].second * b;
    std::sort(ls + 1, ls + n + 1);
    int l = 0, r = 1;
    while (r < n) {
        l++;
        while (ls[r + 1] - ls[l] <= d * 2 && r < n)
            r++;
        ans = std::max(ans, r - l + 1);
    }
    out << ans << '\n';
    return 0;
}