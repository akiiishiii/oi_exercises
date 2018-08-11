// 1488.cpp
#include <iostream>
#include <cmath>

int const Inf = 1000000;
int mins[21] = {0}, minv[21] = {0}, n, m, best;

#define min(a, b) ((a) < (b) ? (a) : (b))

void init();
void dfs(int deep, int sums, int sumv, int r, int h);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    best = Inf;
    std::cin >> n >> m;
    dfs(m, 0, 0, sqrt(n) + 1, n + 1);
    if (best == Inf)
        std::cout << "0\n";
    else
        std::cout << best << '\n';
    return 0;
}

void init() {
    int i;
    for(i = 1; i < 21; i++) {
        mins[i] = mins[i - 1] + 2 * i * i;
        minv[i] = minv[i - 1] + i * i * i;
    }
}

void dfs(int deep, int sums, int sumv, int r, int h) {
    if(!deep) {
        if (sumv == n && sums < best)
            best = sums;
        return;
    }
    if (sums + mins[deep] > best || sumv + minv[deep] > n || (2 * (n - sumv) / r + sums >= best))
        return;
    int i, j,  maxh;
    for (i = r - 1; i >= deep; i--) {
        if (deep == m)
            sums = i * i;
        maxh = min(n - sumv - minv[deep - 1] / i * i, h - 1);
        for (j = maxh; j >= deep; j--)
            dfs(deep - 1, sums + 2 * i * j, sumv + j * i * i, i, j);
    }
}