// 1488.cpp
#include <iostream>
#include <cmath>

int n, m;

int dfs(int dep, int s, int v, int h, int r);

int main(int argc, char const *argv[]) {
    std::cin >> n >> m;
    for (int r = m; r <= sqrt(n); r++)
        for (int h = n / (r * r); h >= m; h--) {
            dfs(m - 1, s, v, h, r);

        }
    return 0;
}

int dfs(int dep, int s, int v, int h, int r) {

}
