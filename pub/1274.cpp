// 1274.cpp
#include <iostream>
#include <cstring>

bool is_Prime(int n);
void dfs(int cur);
int n, ans = 0, ring[12] = {0};
bool vis[12] = {false};

int main(int argc, const char * argv[]) {
    std::cin >> n;
    if (n == 1)
        std::cout << "NO\n";
    else {
        for (int i = 1; i <= n; i++) {
            memset(vis, false, sizeof(vis));
            memset(ring, 0, sizeof(ring));
            ring[0] = i;
            dfs(1);
        }
        if (ans == 0)
            std::cout << "NO\n";
    }
    return 0;
}

bool is_Prime(int n) {
    int i;
    if (n <= 1)
        return false;
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

void dfs(int cur) {
    int i;
    if (cur == n) {
        if (is_Prime(ring[0] + ring[cur - 1])) {
            for (i = 0; i < cur - 1; i++)
                std::cout << ring[i] << ' ';
            std::cout << ring[cur - 1] << std::endl;;
            ans++;
        }
        return;
    }
    for (i = 2; i <= n; i++) {
        if (!vis[i] && is_Prime(ring[cur - 1] + i)) {
            vis[i] = 1;
            ring[cur] = i;
            dfs(cur + 1);
            vis[i] = 0;
        }
    }
}