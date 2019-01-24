// 2665.cpp
#include <cstring>
#include <iostream>

struct point {
    int minx, maxx, miny, maxy;
} p[35];

struct node {
    int x, y;
} nd[35];

int n, map[35][35], mat[35];
bool use[35];

bool check(int i, int j);
bool path(int u);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int flag, test = 0;
    while (true) {
        std::cin >> n;
        if (!n)
            break;
        memset(map, 0, sizeof(map));
        for (int i = 1; i <= n; i++)
            std::cin >> p[i].minx >> p[i].maxx >> p[i].miny >> p[i].maxy;
        for (int i = 1; i <= n; i++)
            std::cin >> nd[i].x >> nd[i].y;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (check(i, j))
                    map[i][j] = 1;
        std::cout << "Heap " << ++test << '\n';
        memset(mat, -1, sizeof(mat));
        for (int i = 1; i <= n; i++) {
            memset(use, 0, sizeof(use));
            path(i);
        }
        flag = false;
        for (int i = 1; i <= n; i++) {
            int u = mat[i];
            if (u == -1)
                continue;
            mat[i] = -1;
            memset(use, 0, sizeof(use));
            map[u][i] = 0;
            if (!path(u)) {
                flag++;
                mat[i] = u;
                if (flag > 1)
                    std::cout << ' ';
                std::cout << '(' << char(i + 'A' - 1) << ',' << mat[i] << ')';
            }
            map[u][i] = 1;
        }
        if (!flag)
            std::cout << "none";
        std::cout << "\n\n";
    }
    return 0;
}

bool check(int i, int j) {
    if (nd[i].x >= p[j].minx && nd[i].x <= p[j].maxx && nd[i].y >= p[j].miny &&
        nd[i].y <= p[j].maxy)
        return true;
    return false;
}

bool path(int u) {
    for (int i = 1; i <= n; i++)
        if (map[u][i] && !use[i]) {
            use[i] = true;
            if (mat[i] == -1 || path(mat[i])) {
                mat[i] = u;
                return true;
            }
        }
    return false;
}