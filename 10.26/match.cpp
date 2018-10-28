// match.cpp
#include <iostream>
#include <fstream>
#include <algorithm>

#define debug

#ifndef debug

std::ifstream in("match.in");
std::ofstream out("match.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, s[9], hash[9][192612];
bool v[9][192612];

int dfs(int a, int b);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n;
    for (int i = 1; i <= n; i++)
        in >> s[i];
    out << dfs(1, 2) << '\n';
    return 0;
}

int dfs(int a, int b) {
    if (a == n + 1)
        return 1;
    if (s[a] > (n - b + 1) * 3)
        return 0;
    if (b == n + 1) {
        if (s[a])
            return 0;
        int tmp[9], num = 0;
        for (int i = 1; i <= n - a; i++)
            tmp[i] = s[i + a];
        std::sort(tmp + 1, tmp + n - a + 1);
        for (int i = 1; i <= n - a; i++)
            num = (num * 23 + tmp[i]) % 192611;
        if (!v[n - a][num])
            hash[n - a][num] = dfs(a + 1, a + 2), v[n - a][num] = true;
        return hash[n - a][num];
    }
    int ret = 0;
    if (s[a] >= 1 && s[b] >= 1) {
        s[a]--, s[b]--;
        ret += dfs(a, b + 1);
        s[a]++, s[b]++;
    }
    if (s[a] >= 3) {
        s[a] -= 3;
        ret += dfs(a, b + 1);
        s[a] += 3;
    }
    if (s[b] >= 3) {
        s[b] -= 3;
        ret += dfs(a, b + 1);
        s[b] += 3;
    }
    return ret;
}