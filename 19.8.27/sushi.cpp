// sushi.cpp
#include <cstring>
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("sushi.in");
std::ofstream out("sushi.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 500001;
int n;
char s[Maxn << 2];
long long sl[Maxn << 2], sr[Maxn << 2], bl[Maxn << 2], br[Maxn << 2],
    rl[Maxn << 2];
long long ans;

long long chk(int x, int l, int r) {
    return sl[x] - sl[l - 1] - bl[l - 1] * (rl[x] - rl[l - 1]) + sr[x + 1] -
           sr[r + 1] - br[r + 1] * (rl[r] - rl[x]);
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int T;
    in >> T;
    while (T--) {
        in >> (s + 1);
        n = strlen(s + 1);
        ans = 0x3f3f3f3f3f3f3f3f;
        for (int i = 1; i <= n; i++)
            s[n + i] = s[i];
        bl[0] = sl[0] = rl[0] = sr[(n << 1) | 1] = br[(n << 1) | 1] = 0;
        for (int i = 1; i <= n << 1; i++) {
            bl[i] = bl[i - 1];
            sl[i] = sl[i - 1];
            rl[i] = rl[i - 1];
            if (s[i] == 'B')
                bl[i]++;
            else
                rl[i]++, sl[i] += bl[i];
        }
        for (int i = n << 1; i; i--) {
            br[i] = br[i + 1];
            sr[i] = sr[i + 1];
            if (s[i] == 'B')
                br[i]++;
            else
                sr[i] += br[i];
        }
        int x = 1;
        for (int i = 1; i <= n; i++) {
            while (x != n + i &&
                   chk(x, i, i + n - 1) >= chk(x + 1, i, i + n - 1))
                x++;
            ans = std::min(ans, chk(x, i, i + n - 1));
        }
        out << ans << '\n';
    }
    return 0;
}