// divide.cpp
#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <deque>

#define debug

#ifndef debug

std::ifstream in("divide.in");
std::ofstream out("divide.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

long long m, n, a, b, room, stu;
long long x[10005], g[205];
long long s[10005], f[205][10005], avg, ans;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int T;
    in >> T;
    while (T--) {
        memset(x, 0, sizeof(x));
        memset(s, 0, sizeof(s));
        memset(g, 0, sizeof(g));
        in >> m >> n >> a >> b;
        avg = 0, ans = 1ll << 60, room = 0, stu = 0;
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                f[i][j] = 1ll << 60;
        for (int i = 1; i <= m; i++)
            in >> x[i], avg += x[i];
        avg /= m;
        for (int i = 1; i <= m; i++)
            s[i] = s[i - 1] + (x[i] - avg) * (x[i] - avg);
        for (int i = 1; i <= n; i++)
            in >> g[i];
        f[0][0] = 0;
        std::deque<long long> q;
        for (int i = 1; i <= n; i++) {
            q.clear();
            for (int j = i * a; j <= std::min(m, i * b); j++) {
                while (q.size() && q.front() < j - b)
                    q.pop_front();
                while (q.size() && f[i - 1][q.back()] - g[i] * s[q.back()] > f[i - 1][j - a] - g[i] * s[j - a])
                    q.pop_back();
                q.push_back(j - a);
                f[i][j] = f[i - 1][q.front()] + g[i] * (s[j] - s[q.front()]);
            }
            if (f[i][m] < ans) {
                ans = f[i][m];
                room = i;
            }
        }
        for (int i = m - b; i <= m - a; i++)
            if (f[room - 1][i] + g[room] * (s[m] - s[i]) == ans)
                stu = m - i;
        out << ans << ' ' << room << ' ' << stu << '\n';
    }
    return 0;
}