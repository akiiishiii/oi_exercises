// 1008.cpp
#include <iostream>

int n, m;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> m >> n;

    return 0;
}

/*
f[i, j] = max{f[i - 1, k] + a[i, j - k]} (1 ≤ i ≤ n, 0 ≤ j ≤ m, 0 ≤ k ≤ j)
f[i, 0] = 0
ans = f[n, m]
*/