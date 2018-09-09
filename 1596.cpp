// 1596.cpp
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>

int const Maxn = 1003, Maxm = 6666;
int head[Maxn], ver[Maxm], edge[Maxm], Next[Maxm], d[Maxn], used[Maxn], s[Maxn];
int n, m, tot, maxx = 0xcfcfcfcf;
std::queue<int> q;
bool v[Maxn];

void read(int &x);
void write(int x);
void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
bool spfa(int mx);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    read(n);
    for (int i = 1, l, r, v; i <= n; i++) {
        read(l);
        read(r);
        read(v);
        maxx = std::max(r, maxx);
        add(r, l - 1, v);
    }
    for (int i = 1; i <= maxx; i++)
        add(i, i - 1, 0), add(i - 1, i, -1);
    for (int i = 0; i <= maxx; i++)
        add(1002, i, 0);
    if (spfa(1002)) {
        write(d[0]);
    } else {
        std::cout.put('-');
        std::cout.put('1');
    }
    std::cout.put('\n');
    return 0;
}

void read(int &x) {
    x = 0;
    char c = std::cin.get();
    while (c < '0' || c > '9')
        c = std::cin.get();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = std::cin.get();
    }
}

void write(int x) {
    int y = 10, len = 1;
    while (y <= x) {
        y *= 10;
        len++;
    }
    while (len--) {
        y /= 10;
        std::cout.put(x / y + 48);
        x %= y;
    }
}

bool spfa(int mx) {
    memset(d, 0xcf, sizeof(d));
    memset(v, false, sizeof(v));
    d[mx] = 0; v[mx] = true;
    q.push(mx);
    while (q.size()) {
        int x = q.front(); q.pop();
        v[x] = false;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (d[y] < d[x] + z) {
                d[y] = d[x] + z;
                used[y]++;
                if (used[y] >= Maxn) return false;
                if (!v[y]) q.push(y), v[y] = true;
            }
        }
    }
    return true;
}