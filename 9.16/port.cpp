// port.cpp
#include <iostream>
#include <fstream>
#include <queue>

//#define debug

#ifndef debug

std::ifstream in("port.in");
std::ofstream out("port.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int ans = 0, cnt = 0, n, t, k, r = 0, tmp[100001], x[300002], q[300002];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n;
    for (int times = 0; times < n; times++) {
        in >> t >> k;
        for (int i = 0; i < k; i++) {
            q[++r] = t;
            in >> x[r];
            if (!tmp[x[r]])
                ans++;
            tmp[x[r]]++;
        }
        while (t - q[cnt] >= 86400)
            if (!--tmp[x[cnt++]])
                ans--;
        out << ans << '\n';
    }
    return 0;
}