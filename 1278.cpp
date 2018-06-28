// 1278.cpp
#include <iostream>
#include <cstring>

char a[110][110];                                 //迷宫，根据题目要求，这么大足够了。使用DFS也不会超时
int pa[110][110], ans[101], n;                                 //0 1 2  标记位置如果是0，代表没走过的位置；如果是1，代表走过的位置；如果是2，代表死胡同（这里不仅仅是上下左右有三个方向都是墙的死胡同，墙的位置还可以是走过的位置）
int zx[4] = {1, -1, 0, 0}, zy[4] = {0, 0, 1, -1}; //代表坐标的增量，上下左右
bool flag;
void dfs(int x1, int y1, int x2, int y2);

int main(int argc, const char *argv[]) {
    int cas;
    std::cin >> cas;
    for (int i = 0; i < cas; i++) {
        int x1, y1, x2, y2;
        memset(a, '#', sizeof(a));
        memset(pa, 0, sizeof(pa));
        flag = true;
        std::cin >> n;
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++)
                std::cin >> a[j][k];
            std::cin.get();
        }
        std::cin >> x1 >> y1 >> x2 >> y2;
        dfs(x1 + 1, y1 + 1, x2 + 1, y2 + 1);
        if (flag)
            ans[i] = 0;
        else
            ans[i] = 1;
    }
    for (int i = 0; i < cas; i++)
        if (ans[i])
            std::cout << "YES\n";
        else
            std::cout << "NO\n";
    return 0;
}

void dfs(int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {
        flag = false;
        return;
    }
    if (a[x1][y1] == '#' || a[x2][y2] == '#')
        return;
    flag = true;
    pa[x1][y1] = 1;
    for (int j = 0; j < 4; j++) {
        int newx = x1, newy = y1;
        newx += zx[j];
        newy += zy[j];
        if (pa[newx][newy] == 0 && a[newx][newy] != '#') {
            flag = false;
            dfs(newx, newy, x2, y2);
        }
    }
    if (flag) {
        pa[x1][y1] = 2;
        a[x1][y1] = '#';
    }
}