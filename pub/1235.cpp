// 1235.cpp
#include <iostream>
#include <vector>

int main(int argc, const char *argv[]) {
    std::vector<int> v;
    int n, m;
    std::cin >> n >> m;
    v.resize(n + 1);
    v[0] = 0;
    for (int temp, i = 1; i <= n; i++) {
        std::cin >> temp;
        v[i] = temp + v[i - 1];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        std::cin >> a >> b;
        std::cout << v[b] - v[a - 1] << std::endl;
    }
    return 0;
}