// 1275.cpp
#include <iostream>

void dfs(int cur);
int n, r, a[22] = {0};
bool vis[22] = {false};

int main(int argc, const char * argv[]) {
    std::cin >> n >> r;
    dfs(0);
    return 0;
}

void dfs(int cur) {
    int i;
    if (cur == r) {
        for (i = 0; i < cur; i++)
            std::cout << a[i] << ' ';
        std::cout << std::endl;
        return;
    }
    for (i = 1; i <= n; i++) {
        if ((cur == 0) || (cur > 0 && i > a[cur - 1])) {
            vis[i] = 1;
            a[cur] = i;
            dfs(cur + 1);
            vis[i] = 0;
        }
    }
}
