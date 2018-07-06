// 1249.cpp
#include <iostream>

int n, ans = 0, map[14] = {0}, cnt = 0;
void dfs(int cur);

int main(int argc, const char * argv[]) {
    std::cin >> n;
    dfs(0);
    std::cout << ans << std::endl;
    return 0;
}

void dfs(int cur) {
    int i, j;
    int suc;
    if (cur == n) {
        if (++cnt <= 3) {
            for (i = 0; i < cur; i++)
                std::cout << map[i] + 1 << ' ';
            std::cout << std::endl;
        }
        ans++;
        return;
    }
    for (j = 0; j < n; j++) {
        suc = 1;
        map[cur] = j;
        for (i = 0; i < cur; i++) {
            if (map[cur] == map[i] || cur - map[cur] == i - map[i] || cur + map[cur] == i + map[i]) {
                suc = 0;
                break;
            }
        }
        if (suc == 1)
            dfs(cur + 1);
    }
}