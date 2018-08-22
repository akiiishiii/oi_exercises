// 1422.cpp
#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
    int n, m, k;
    std::cin >> n >> m;
    std::vector<int> v(n);
    for (int t = 0, i, j; t < m; t++) {
        std::cin >> i >> j;
        v[i - 1]++;
    }
    std::cin >> k;
    std::cout << v[k - 1] << '\n';
    return 0;
}
