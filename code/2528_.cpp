#include <cstring>
#include <iostream>

const int Maxn = 1005;

struct Node {
    int x, y;
} ax[Maxn], ay[Maxn], ah[Maxn], al[Maxn];

int n, nx, ny, nh, nl, rest, map[45][45] = {0}, c1[45][45] = {0};
int c2[45][45] = {0}, my[Maxn], f[Maxn][5] = {0}, vst[Maxn];
int const dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};

void BuildGraph() {
    int i, j, tx, ty, k, y, x;
    nx = ny = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
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
    for (x = 1; x <= nx; x++) {
        i = ax[x].x;
        j = ax[x].y;
        for (k = 0; k < 4; k++) {
            tx = i + dx[k];
            ty = j + dy[k];
            if (c2[tx][ty]) {
                y = c2[tx][ty];
                f[x][++f[x][0]] = y;
            }
        }
    }
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

void Print() {
    int i, j;
    std::cout << "Yes\n";
    nh = nl = 0;
    for (j = 1; j <= ny; j++) {
        i = my[j];
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
    for (i = 1; i <= nh; i++)
        std::cout << ah[i].x << " " << ah[i].y << '\n';
    std::cout << nl << '\n';
    for (i = 1; i <= nl; i++)
        std::cout << al[i].x << " " << al[i].y << '\n';
}


int main() {
    if (Read()) {
        memset(my, 0, sizeof(my));
    for (int i = 1; i <= nx; i++) {
        memset(vst, 0, sizeof(vst));
        if (dfs(i))
            rest -= 2;
    }
    if (rest)
        std::cout << "No\n";
    else
        Print();
    }
    return 0;
}
