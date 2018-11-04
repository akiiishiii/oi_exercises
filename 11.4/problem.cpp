// problem.cpp
#include <iostream>
#include <fstream>
#include <algorithm>

//#define debug

#ifndef debug

std::ifstream in("problem.in");
std::ofstream out("problem.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int t, k;
int c[2001][2001], s[2001][2001];
int n[10001], m[10001];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int maxn = 0;
    in >> t >> k;
    for (int i = 1; i <= t; i++) {
        in >> n[i] >> m[i];
        maxn = std::max(n[i], maxn);
    }
    for (int i = 1; i <= maxn; i++) {
        c[1][i] = i % k;
        if (!c[1][i])
            s[1][i]++;
    }
    for (int i = 2; i <= maxn; i++)
        for (int j = 2; j <= i; j++) {
            c[j][i] = (c[j - 1][i - 1] + c[j][i - 1]) % k;
            if (!c[j][i])
                s[j][i]++;
        }
    for (int i = 1; i <= maxn; i++)
        for (int j = 1; j <= maxn; j++)
            s[j][i] += s[j - 1][i] + s[j][i - 1] - s[j - 1][i - 1];
    for (int i = 1; i <= t; i++)
        out << s[std::min(n[i], m[i])][n[i]] << '\n';
    return 0;
}