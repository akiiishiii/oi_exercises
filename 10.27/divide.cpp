// divide.cpp
#include <iostream>
#include <fstream>
#include <cstring>

//#define debug

#ifndef debug

std::ifstream in("divide.in");
std::ofstream out("divide.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int m, n, a, b;
int x[10005], g[205], num[205];
long long s[10005], avg = 0, ans = 0x3f3f3f3f3f3f3f3f;
bool flag = true;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int T;
    in >> T;
    while (T--) {
        memset(s, 0, sizeof(s));
        avg = 0, ans = 0x3f3f3f3f3f3f3f3f;
        in >> m >> n >> a >> b;
        for (int i = 1; i <= m; i++)
            in >> x[i], avg += x[i];
        avg /= m;
        for (int i = 1; i <= m; i++)
            s[i] = s[i - 1] + (x[i] - avg) * (x[i] - avg);
        for (int i = 1; i <= n; i++) {
            in >> g[i];
            if (g[i] < 0)
                flag = false;
        }
        if (flag) {
            for (int i = 1; i <= n; i++) {

            }
        } else {
            for (int i = 1; i <= n; i++) {

            }
        }
    }
    return 0;
}