// 2412.cpp
#include <iostream>

int const Maxn = 2005;
int prt[Maxn];
int m, n, cnt = 0, maxx, ans;
bool first = true;
struct edge {
    int u, v, w;
} e[Maxn], tmp;

void sort();
int search(int x) { return (prt[x] == x ? x : prt[x] = search(prt[x])); }
bool kruskal();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        std::cin >> tmp.u >> tmp.v >> tmp.w;
        if (!first && tmp.w > maxx) {
            std::cout << ans << '\n';
            continue;
        }
        sort();
        if (kruskal())
            first = false, std::cout << ans << '\n';
        else
            std::cout << "-1\n";
    }
    return 0;
}

void sort() {
    int pos;
    for (pos = cnt; pos >= 1; pos--)
        if (e[pos].w <= tmp.w)
            break;
    for (int i = cnt; i >= pos + 1; i--)
        e[i + 1] = e[i];
    e[pos + 1] = tmp, cnt++;
}

bool kruskal() {
    int k = 0;
    ans = 0;
    for (int i = 1; i <= n; i++)
        prt[i] = i;
    for (int i = 1, p1, p2; i <= cnt; i++) {
        p1 = search(e[i].u), p2 = search(e[i].v);
        if (p1 != p2)
            prt[p1] = p2, ans += e[i].w, k++, maxx = e[i].w;
        if (k == n - 1)
            break;
    }
    if (k < n - 1)
        return false;
    return true;
}