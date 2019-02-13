#include <iostream>
#include <algorithm>

struct data
{
    int x, y, v;
    bool operator<(data const &d) const { return v < d.v; }
} e[20001];

int n, m, prt[2001], cnt, ans;

int find(int x) { return x == prt[x] ? x : prt[x] = find(prt[x]); }
void un(int x, int y, int v);
void insert(int x, int y, int v);

int main(int argc, char const *argv[]) {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        prt[i] = i;
    for (int i = 1; i <= m; i++) {
        int flag, x, y, v;
        std::cin >> flag >> x >> y >> v;
        if (flag == 1)
            un(x, y, v);
        else
            insert(x, y, v);
    }
    std::sort(e + 1, e + cnt + 1);
    for (int i = 1; i <= cnt; i++) {
        int x = find(e[i].x), y = find(e[i].y);
        if (prt[x] != prt[y])
            un(x, y, e[i].v);
    }
    std::cout << ans << '\n';
    return 0;
}

void un(int x, int y, int v) {
    prt[find(x)] = find(y);
    ans += v;
}

void insert(int x, int y, int v) {
    cnt++;
    e[cnt].x = x;
    e[cnt].y = y;
    e[cnt].v = v;
}