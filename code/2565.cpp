// 2565.cpp
#include <iostream>
#include <cstring>

int const Maxm = 260, Maxn = 40;
int K, C, M, map[Maxm][Maxm], mid, mapy[Maxn][20], vmy[Maxn];
bool vst[Maxn];

bool dfs(int i);
bool mhungary();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> K >> C >> M;
    for (int i = 1; i <= K + C; i++)
        for (int j = 1; j <= K + C; j++) {
            std::cin >> map[i][j];
            if (!map[i][j])
                map[i][j] = 0x3f3f3f3f;
        }
    for (int k = 1; k <= K + C; k++)
        for (int i = 1; i <= K + C; i++)
            for (int j = 1; j <= K + C; j++)
                if (map[i][j] >= map[i][k] + map[k][j])
                    map[i][j] = map[i][k] + map[k][j];
    int l = 1, r = 9900;
    while (l <= r) {
        mid = (l + r) >> 1;
        if (mhungary())
            r = mid - 1;
        else
            l = mid + 1;
    }
    std::cout << l << '\n';
    return 0;
}

bool dfs(int i) {
    for (int j = 1; j <= K; j++)
        if (map[i][j] <= mid && !vst[j]) {
            vst[j] = 1;
            if (vmy[j] < M) {
                mapy[j][++vmy[j]] = i;
                return true;
            }
            for (int k = 1; k <= vmy[j]; k++)
                if (dfs(mapy[j][k])) {
                    mapy[j][k] = i;
                    return true;
                }
        }
    return false;
}

bool mhungary() {
    memset(vmy, 0, sizeof(vmy));
    for (int i = 1; i <= C; i++) {
        memset(vst, 0, sizeof(vst));
        if (!dfs(i + K))
            return false;
    }
    return true;
}