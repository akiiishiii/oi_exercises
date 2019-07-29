// 1886.cpp
#include <iostream>
#include <cmath>

int mins[21] = {0}, minv[21] = {0}, n, m, maxx;

void dfs(int depth, int sums, int sumv, int r, int h);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    maxx = 0x3f3f3f3f;
    std::cin >> n >> m;
    dfs(m, 0, 0, sqrt(n) + 1, n + 1);
    if (maxx == 0x3f3f3f3f)
        std::cout << "0\n";
    else
        std::cout << maxx << '\n';
    return 0;
}

void dfs(int depth, int sums, int sumv, int r, int h) {
    if(!depth) {
        if (sumv == n && sums < maxx)
            maxx = sums;
        return;
    }
    if (sums + mins[depth] > maxx || sumv + minv[depth] > n || (2 * (n - sumv) / r + sums >= maxx))
        return;
    for (int i = r - 1, maxh; i >= depth; i--) {
        if (depth == m)
            sums = i * i;
        maxh = std::min(n - sumv - minv[depth - 1] / i * i, h - 1);
        for (int j = maxh; j >= depth; j--)
            dfs(depth - 1, sums + 2 * i * j, sumv + j * i * i, i, j);
    }
}
