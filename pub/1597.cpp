// 1597.cpp
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>

int const Maxn = 1003, Maxm = 6666;
int head[Maxn], ver[Maxm], edge[Maxm], Next[Maxm], d[Maxn], used[Maxn], s[Maxn];
int n, nn, ss, tot, a0, b0, l0, a1, b1, l1;
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
    read(a0);
    read(b0);
    read(l0);
    read(a1);
    read(b1);
    read(l1);
    nn = n + 2, ss = n + 1;
    for (int i = 1; i <= n; i++) {
        add(i, i - 1, 0);
        add(i - 1, i, 1);
    }
    add(ss, 0, 0);
    for (int i = l0; i <= n; i++) {
        add(i, i - l0, -(l0 - b0));
        add(i - l0, i, +(l0 - a0));
    }
    for (int i = l1; i <= n; i++) {
        add(i, i - l1, -(a1));
        add(i - l1, i, +(b1));
    }
    if (spfa(ss))
        write(d[n] - d[0]);
    else {
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
    memset(d, 0x3f, sizeof(d));
    memset(v, false, sizeof(v));
    d[mx] = 0; v[mx] = true;
    q.push(mx);
    while (q.size()) {
        int x = q.front(); q.pop();
        v[x] = false;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                used[y]++;
                if (used[y] >= Maxn) return false;
                if (!v[y]) q.push(y), v[y] = true;
            }
        }
    }
    for (int i = 0; i < nn; i++)
        if (d[i] > (1 << 29))
            return false;
    return true;
}