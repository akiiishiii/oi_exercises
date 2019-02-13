//1598.cpp
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>

int const Maxn = 30, Maxm = 101;
int head[Maxn], ver[Maxm], edge[Maxm], Next[Maxm], d[Maxn], used[Maxn], r[Maxn], t[Maxn] = {0};
int n, sum, tot, cnt = 0;
std::queue<int> q;
bool v[Maxn];

void read(int &x);
void write(int x);
void add(int x, int y, int z) { ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot; }
bool spfa(int mx);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    for (int i = 1; i <= 24; i++)
        read(r[i]);
    read(n);
    for (int i = 1, m; i <= n; i++) {
        read(m);
        t[m + 1]++;
        cnt++;
    }
    for(sum = 0; sum <= cnt; sum++)
        if (spfa(24)) {
            write(sum);
            std::cout.put('\n');
            return 0;
        }
    std::cout.put('N');
    std::cout.put('o');
    std::cout.put(' ');
    std::cout.put('S');
    std::cout.put('o');
    std::cout.put('l');
    std::cout.put('u');
    std::cout.put('t');
    std::cout.put('i');
    std::cout.put('o');
    std::cout.put('n');
    std::cout.put('!');
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
    tot = 0;
    add(24, 0, -sum);
    for (int i = 0; i <= 23; i++)
        add(i + 1, i, 0);
    for (int i = 0; i <= 23; i++)
        add(i, i + 1, t[i]);
    for (int i = 8; i <= 24; i++)
        add(i, i - 8, -r[i]);
    for (int i = 1; i <= 7; i++)
        add(i, i + 16, sum - r[i]);
    memset(d, 0x3f, sizeof(d));
    memset(used, 0, sizeof(used));
    memset(v, false, sizeof(v));
    while(q.size()) q.pop();
    d[mx] = 0; v[mx] = true; used[mx]++;
    q.push(mx);
    while (q.size()) {
        int x = q.front(); q.pop();
        v[x] = false;
        for (int i = head[x]; i; i = Next[i]) {
            int y = ver[i], z = edge[i];
            if (d[y] > d[x] + z) {
                d[y] = d[x] + z;
                used[y]++;
                if (used[y] > 25) return false;
                if (!v[y]) q.push(y), v[y] = true;
            }
        }
    }
    return d[0] == -sum;
}