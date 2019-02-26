// 2283.cpp
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int const Maxn = 505;
int prt[Maxn];
int m, n, cnt = 0;
double ans, maxx;
bool first = true;
std::vector<int> chose;
struct edge {
    int u, v, id;
    double w;
} e[Maxn * 10], tmp;
void sort();
int search(int x) { return (prt[x] == x ? x : prt[x] = search(prt[x])); }
bool kruskal();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        std::cin >> tmp.u >> tmp.v >> tmp.w, tmp.id = i;
        if (!first && tmp.w > maxx) {
            std::cout << std::fixed << std::setprecision(2) << ans / 2.0 << ' ';
            for (auto &&it : chose)
                std::cout << it << ' ';
            std::cout << '\n';
            continue;
        }
        chose.clear();
        sort();
        if (kruskal()) {
            std::sort(chose.begin(), chose.end());
            first = false, std::cout << std::fixed << std::setprecision(2) << ans / 2.0 << ' ';
            for (auto &&it : chose)
                std::cout << it << ' ';
            std::cout << '\n';
        } else
            std::cout << "0\n";
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
            prt[p1] = p2, ans += e[i].w, k++, maxx = e[i].w, chose.push_back(e[i].id);
        if (k == n - 1)
            break;
    }
    if (k < n - 1)
        return false;
    return true;
}