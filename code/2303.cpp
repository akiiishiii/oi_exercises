#include <iostream>

int vis[1005] = {0}, b[1005], a[1005], map[1005][1005] = {0}, i, j, n;
int s1[1005], s2[1005], Flag;
bool noans;

void DFS(int x, int color) {
    vis[x] = color;
    for (int i = 1; i <= n; i++)
        if (map[x][i]) {
            if (!vis[i])
                DFS(i, 3 - color);
            else if (vis[i] != 3 - color) {
                Flag = 0;
                return;
            }
        }
}

int RanColor() {
    Flag = 1;
    for (int i = 1; i <= n; i++)
        if (vis[i] == 0) {
            DFS(i, 1);
            if (!Flag)
                return 0;
        }
    return 1;
}

void Print() {
    int i, top1 = 0, top2 = 0, t = 1;
    for (i = 1; i <= n; i++) {
        if (vis[i] == 1) {
            top1++;
            s1[top1] = a[i];
            std::cout << 'a' << "";
        } else {
            top2++;
            s2[top2] = a[i];
            std::cout << 'c' << "";
        }
        while ((top1 > 0 && s1[top1] == t) || (top2 > 0 && s2[top2] == t)) {
            if (top1 > 0 && s1[top1] == t) {
                top1--;
                std::cout << 'b' << "";
            } else {
                top2--;
                std::cout << 'd' << "";
            }
            t++;
        }
    }
}

int main() {
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i];
    b[n] = a[n];
    for (int i = n - 1; i >= 1; i--)
        b[i] = std::min(b[i + 1], a[i]);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n - 1; j++)
            if (a[i] < a[j] && a[i] > b[j + 1]) {
                map[i][j] = 1;
                map[j][i] = 1;
            }
    if (!RanColor())
        std::cout << 0 << std::endl;
    else
        Print();
    return 0;
}
