// attack.cpp 二分图最大独立集
#include <cstring>
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("attack.in");
std::ofstream out("attack.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int ver[320005], Next[320005], head[40005] = {0}, tot = 0;
int my[40005] = {0};
int n;
bool map[205][205], vst[40005] = {false};
int const dx[9] = {-1, 1, -2, 2, -1, 1, -2, 2}, dy[9] = {-2, -2, -1, -1, 2, 2, 1, 1};

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
inline int calc(int x, int y) { return (x - 1) * n + y; }
bool dfs(int u);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int ans = 0, p = 0;
    in >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            if (in.get() == '1')
                map[i][j] = true, p++;
            else
                map[i][j] = false;
        in.get();
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!map[i][j] && (i + j) % 2)
                for (int k = 0; k < 8; k++) {
                    int tx = i + dx[k], ty = j + dy[k];
                    if (tx < 1 || ty < 1 || tx > n || ty > n || map[tx][ty])
                        continue;
                    add(calc(i, j), calc(tx, ty));
                }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!map[i][j] && (i + j) % 2) {
                memset(vst, 0, sizeof(vst));
                if (dfs(calc(i, j)))
                    ans++;
            }
    out << n * n - p - ans << '\n';
    return 0;
}

bool dfs(int x) {
    for (int i = head[x]; i; i = Next[i])
        if (!vst[ver[i]]) {
            int y = ver[i];
            vst[y] = 1;
            if (!my[y] || dfs(my[y])) {
                my[y] = x;
                return true;
            }
        }
    return false;
}