// 2528_.cpp
#include <cstring>
#include <iostream>

int const Maxn = 1005;
int const dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
int n, nx, ny, nh, nl, rest;
int map[45][45], c1[45][45], c2[45][45], my[Maxn], f[Maxn][5], vst[Maxn];

struct node {
    int x, y;
} ax[Maxn], ay[Maxn], ah[Maxn], al[Maxn];

bool dfs(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int p, x, y;
    std::cin >> n >> p;
    rest = n * n - p;
    if (rest % 2) {
        std::cout << "No\n";
        return 0;
    }
    while (p--) {
        std::cin >> x >> y;
        map[x][y] = 1;
    }
    nx = ny = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (!map[i][j]) {
                if ((i + j) % 2) {
                    nx++;
                    ax[nx].x = i;
                    ax[nx].y = j;
                    c1[i][j] = nx;
                } else {
                    ny++;
                    ay[ny].x = i;
                    ay[ny].y = j;
                    c2[i][j] = ny;
                }
            }
    for (int x = 1; x <= nx; x++) {
        int i = ax[x].x, j = ax[x].y;
        for (int k = 0; k < 4; k++) {
            int tx = i + dx[k], ty = j + dy[k];
            if (c2[tx][ty]) {
                int y = c2[tx][ty];
                f[x][++f[x][0]] = y;
            }
        }
    }
    memset(my, 0, sizeof(my));
    for (int i = 1; i <= nx; i++) {
        memset(vst, 0, sizeof(vst));
        if (dfs(i))
            rest -= 2;
    }
    if (rest)
        std::cout << "No\n";
    else {
        std::cout << "Yes\n";
        nh = nl = 0;
        for (int j = 1; j <= ny; j++) {
            int i = my[j];
            if (ax[i].x == ay[j].x - 1) {
                nh++;
                ah[nh] = ax[i];
            }
            if (ax[i].x == ay[j].x + 1) {
                nh++;
                ah[nh] = ay[j];
            }
            if (ax[i].y == ay[j].y + 1) {
                nl++;
                al[nl] = ay[j];
            }
            if (ax[i].y == ay[j].y - 1) {
                nl++;
                al[nl] = ax[i];
            }
        }
        std::cout << nh << '\n';
        for (int i = 1; i <= nh; i++)
            std::cout << ah[i].x << " " << ah[i].y << '\n';
        std::cout << nl << '\n';
        for (int i = 1; i <= nl; i++)
            std::cout << al[i].x << " " << al[i].y << '\n';
    }
    return 0;
}

bool dfs(int x) {
    for (int i = 1; i <= f[x][0]; i++) {
        int y = f[x][i];
        if (!vst[y]) {
            vst[y] = 1;
            if (!my[y] || dfs(my[y])) {
                my[y] = x;
                return true;
            }
        }
    }
    return false;
}