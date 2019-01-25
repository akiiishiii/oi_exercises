// 3150.cpp
#include <string>
#include <cstring>
#include <iostream>

struct query {
    int x1, y1, x2, y2, t, t2;
} q[605];

int n, my[605];
bool vis[605], map[605][605];

bool dfs(int p);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T;
    std::string t;
    std::cin >> T;
    while (T--) {
        memset(map, 0, sizeof map);
        memset(my, -1, sizeof my);
        std::cin >> n;
        for (int i = 0; i < n; i++) {
            std::cin >> t >> q[i].x1 >> q[i].y1 >> q[i].x2 >> q[i].y2;
            q[i].t = ((t[0] - '0') * 10 + (t[1] - '0')) * 60 + (t[3] - '0') * 10 + (t[4] - '0');
            q[i].t2 = q[i].t + abs(q[i].x1 - q[i].x2) + abs(q[i].y1 - q[i].y2);
        }
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (q[i].t2 + abs(q[i].x2 - q[j].x1) + abs(q[i].y2 - q[j].y1) < q[j].t)
                    map[i][j] = true;
        int res = 0;
        for (int i = 0; i < n; i++) {
            memset(vis, false, sizeof(vis));
            if (dfs(i))
                res++;
        }
        std::cout << n - res << '\n';
    }
    return 0;
}

bool dfs(int p) {
    for (int i = 0; i < n; i++)
        if (map[p][i] && !vis[i]) {
            vis[i] = true;
            if (my[i] == -1 || dfs(my[i])) {
                my[i] = p;
                return true;
            }
        }
    return false;
}