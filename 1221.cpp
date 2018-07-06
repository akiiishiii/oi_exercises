// 1221.cpp
#include <iostream>

int a[10] = {0}, n;
bool b[10] = {false};
void dfs(int sta);

int main(int argc, const char * argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin >> n;
    dfs(1);
    return 0;
}

void dfs(int sta) {
    if (sta == n + 1) {
        for (int i = 1; i <= n; i++)
            std::cout << a[i] << ' ';
        std::cout << std::endl;
    }
    else
        for (int i = 1; i <= n; i++)
            if (!b[i]) {
                a[sta] = i;
                b[i] = true;
                dfs(sta + 1);
                b[i] = false;
            }
}