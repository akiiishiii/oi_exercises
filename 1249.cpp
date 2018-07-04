// 1249.cpp
#include <iostream>
#include <cstring>

int dfs(int n, int m);

int main(int argc, const char * argv[]) {
    int t, n;
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        std::cin >> n;
        std::cout << dfs(n, n) << std::endl;
    }
    return 0;
}

int dfs(int n, int m) {
    if (n == 1)
        return 1;
    if (m == 1)
        return 0;
    if (n % m == 0)
        return dfs(n, m - 1) + dfs(n / m, m);
    return dfs(n, m - 1);
}