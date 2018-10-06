// murder.cpp
#include <iostream>
#include <fstream>
#include <cstring>

//#define debug

#ifndef debug

std::ifstream in("murder.in");
std::ofstream out("murder.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int mat[1005][1005]; //, f[1005][1005];
bool v[1005][1005], chk = false;
int n, m; //, ans = 0x3f3f3f3f;

void dfs(int mx, int my, int maxi);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    memset(mat, 0, sizeof(mat));
    //memset(f, 0x3f, sizeof(f));
    int l = 0, r = 1008;
    in >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            in >> mat[i][j];
    //    dfs(1, 1, mat[1][1]);
    while (l <= r) {
        int mid = (l + r) >> 1;
        memset(v, false, sizeof(v));
        chk = false;
        dfs(1, 1, mid);
        if (chk)
            r = mid - 1;
        else
            l = mid + 1;
    }
    out << l << '\n';
    return 0;
}
/*
void dfs(int mx, int my, int maxi) {
    if (maxi < f[mx][my])
        f[mx][my] = maxi;
    else
        return;
    if (mx == n) {
        ans = std::min(ans, maxi);
        return;
    }
    for (int i = 0, kx, ky; i < 4; i++) {
        kx = mx + dx[i], ky = my + dy[i];
        if (!v[kx][ky] && kx <= n && ky <= m && kx > 0 && ky > 0) {
            v[kx][ky] = true;
            dfs(kx, ky, std::max(maxi, mat[kx][ky]));
            v[kx][ky] = false;
        }
    }
}
*/
void dfs(int mx, int my, int maxi) {
    if (mx == n) {
        chk = true;
        return;
    }
    v[mx][my] = true;
    for (int i = 0, kx, ky; i < 4; i++) {
        kx = mx + dx[i], ky = my + dy[i];
        if (!v[kx][ky] && kx <= n && ky <= m && kx > 0 && ky > 0 && mat[kx][ky] <= maxi)
            dfs(kx, ky, maxi);
        if (chk)
            return;
    }
}