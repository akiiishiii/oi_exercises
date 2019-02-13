// 1443.cpp
#include <iostream>

int prt[1005];

void initializer(int x);
void merge(int a, int b);
int search(int a);

int main(int argc, char const *argv[]) {
    int n, m, ans = 0, e[1005] = {0};
    bool vis[1005] = {false};
    std::cin >> n >> m;
    initializer(n);
    for (int i = 0, p, x, y; i < m; i++) {
        std::cin >> p >> x >> y;
        if (p) {
            if (!e[x])
                e[x] = search(y);
            else
                merge(y, e[x]);
            if (!e[y])
                e[y] = search(x);
            else
                merge(x, e[y]);
        } else
            merge(x, y);
    }
    for (int i = 1; i <= n; i++)
        if (!vis[prt[i]]) {
            ans++;
            vis[prt[i]] = true;
        }
    std::cout << ans << '\n';
    return 0;
}

void initializer(int x) {
    for (int i = 1; i <= x; i++)
        prt[i] = i;
}

void merge(int a, int b) {
    int fa = search(a), fb = search(b);
    if (fa != fb)
        prt[fa] = fb;
}

int search(int a) {
    if (prt[a] == a)
        return a;
    return prt[a] = search(prt[a]);
}