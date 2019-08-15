// genes.cpp
#include <fstream>
#include <iostream>
#include <queue>
#include <utility>

//#define debug

#ifndef debug

std::ifstream in("genes.in");
std::ofstream out("genes.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int s[2000005];
int n, l, r, ans;
std::pair<int, int> q[5000005];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n;
    for (int i = 1; i <= n; i++)
        in >> s[i], s[i + n] = s[i];
    int nn = n << 1;
    for (int i = 1; i <= nn; i++)
        s[i] += s[i - 1];
    q[++r] = std::make_pair(s[nn - 1], nn - 1);
    l = 1;
    for (int i = nn - 2; i >= n; i--) {
        while (s[i] < q[r].first && r >= l)
            r--;
        q[++r] = std::make_pair(s[i], i);
    }
    for (int i = n; i >= 1; i--) {
        if (q[l].first >= s[i - 1])
            ans++;
        while (q[l].second - n + 1 > i && l < r)
            l++;
        while (s[i - 1] < q[r].first && r >= l)
            r--;
        q[++r] = std::make_pair(s[i - 1], i - 1);
    }
    out << ans << '\n';
    return 0;
}