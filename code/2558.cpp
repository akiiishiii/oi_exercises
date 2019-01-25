// 2558.cpp
#include <cstring>
#include <iostream>

int map[105][105], g[105][105];
int x[105], y[105], lx[105], ly[105] = {0}, my[105] = {0};
int n, ans;

bool dfs(int i);
void adjust();
void km();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            std::cin >> g[i][j];
    for (int i = 0; i < 105; i++)
        for (int j = 0; j < 105; j++)
            map[i][j] = -g[i][j];
    km();
    std::cout << -ans << '\n';
    memcpy(map, g, sizeof(g));
    km();
    std::cout << ans << '\n';
    return 0;
}

bool dfs(int i) {
    x[i] = 1;
    for (int j = 1; j <= n; j++)
        if (!y[j] && lx[i] + ly[j] == map[i][j]) {
            y[j] = 1;
            if (!my[j] || dfs(my[j])) {
                my[j] = i;
                return true;
            }
        }
    return false;
}

void adjust() {
    int d = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
        if (x[i])
            for (int j = 1; j <= n; j++)
                if (!y[j])
                    d = std::min(d, lx[i] + ly[j] - map[i][j]);
    for (int i = 1; i <= n; i++) {
        if (x[i])
            lx[i] -= d;
        if (y[i])
            ly[i] += d;
    }
}

void km() {
    memset(my, 0, sizeof(my));
    memset(ly, 0, sizeof(ly));
    for (int i = 1; i <= n; i++) {
        lx[i] = 0xcfcfcfcf;
        for (int j = 1; j <= n; j++)
            if (map[i][j] > lx[i])
                lx[i] = map[i][j];
    }
    for (int i = 1; i <= n; i++) {
        memset(x, 0, sizeof(x));
        memset(y, 0, sizeof(y));
        while (!dfs(i)) {
            adjust();
            memset(x, 0, sizeof(x));
            memset(y, 0, sizeof(y));
        }
    }
    ans = 0;
    for (int i = 1; i <= n; i++)
        ans += map[my[i]][i];
}