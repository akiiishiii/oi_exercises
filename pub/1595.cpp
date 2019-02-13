// 1595.cpp
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>

int const Maxn = 1002, Maxm = 6001;
int head[Maxn], ver[Maxm], edge[Maxm], Next[Maxm], d[Maxn], used[Maxn];
int n, m, tot;
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
    n++;
    read(m);
    for (int i = 1; i < n; i++)
        add(0, i, 0);
    for (int i = 1, x, y, z; i <= m; i++) {
        read(x);
        read(y);
        read(z);
        add(y, x, z);
    }
    if (spfa(0)) {
        int k = d[1];
        for (int i = 2; i < n; i++)
            k = std::min(k, d[i]);
        for (int i = 1; i < n; i++) {
            write(d[i] - k);
            std::cout.put('\n');
        }
    } else {
        std::cout.put('N');
        std::cout.put('O');
        std::cout.put(' ');
        std::cout.put('S');
        std::cout.put('O');
        std::cout.put('L');
        std::cout.put('U');
        std::cout.put('T');
        std::cout.put('I');
        std::cout.put('O');
        std::cout.put('N');
        std::cout.put('\n');
    }
    return 0;
}

void read(int &x) {
    int minus = 1;
    x = 0;
    char c = std::cin.get();
    while (c < '0' || c > '9') {
        if (c == '-')
            minus = -1;
        c = std::cin.get();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = std::cin.get();
    }
    x *= minus;
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
    return true;
}