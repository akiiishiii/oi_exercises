// 1544.cpp
#include <algorithm>
#include <cstring>
#include <iostream>

int const Maxn = 200002;
int tot, n, m;
int siz[Maxn], prt[Maxn], val[Maxn], sum[Maxn];
int head[Maxn], ver[Maxn << 1], Next[Maxn << 1];

struct edges {
    int a, b, w;
    bool operator<(edges const &e) const { return w > e.w; }
} e[100002];

inline void add(int x, int y) { ver[++tot] = y, Next[tot] = head[x], head[x] = tot; }
int search(int x) { return (x == prt[x] ? x : search(prt[x])); }
void dfs(int x);
inline void ex_kruskal();
inline void read(int &x);
inline void write(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int T, ans;
    read(T);
    for (int t = 1, tmp; t <= T; t++) {
        read(n);
        m = n - 1, tmp = (n << 1) - 1;
        ans = tot = 0;
        for (int i = 1; i <= tmp; i++)
            head[i] = 0;
        for (int i = 1; i <= m; i++)
            read(e[i].a), read(e[i].b), read(e[i].w);
        ex_kruskal();
        dfs(tmp);
        for (int i = 1; i <= tmp; i++)
            ans = std::max(ans, sum[i]);
        std::cout.put('C');
        std::cout.put('a');
        std::cout.put('s');
        std::cout.put('e');
        std::cout.put(' ');
        write(t);
        std::cout.put(':');
        std::cout.put(' ');
        write(ans);
        std::cout.put('\n');
    }
    return 0;
}

void dfs(int x) {
    int num = 0;
    sum[x] = siz[x] = 0;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        num++;
        dfs(y);
        if (y > n && num == 1)
            sum[x] = sum[y];
        if (siz[x])
            sum[x] = std::max(sum[x] + val[x] * siz[y], sum[y] + siz[x] * val[x]);
        siz[x] += siz[y];
    }
    if (!head[x])
        siz[x] = 1;
}

void ex_kruskal() {
    int cnt = n, tot = n << 1;
    std::sort(e + 1, e + 1 + m);
    for (int i = 1; i <= tot; i++)
        prt[i] = i;
    for (int i = 1, p1, p2; i <= m; i++) {
        p1 = search(e[i].a), p2 = search(e[i].b);
        if (p1 != p2) {
            prt[p1] = prt[p2] = ++cnt;
            val[cnt] = e[i].w;
            add(cnt, p1), add(cnt, p2);
            if (cnt == tot - 1)
                break;
        }
    }
}

inline void read(int &x) {
    x = 0;
    char c = std::cin.get();
    while (c < '0' || c > '9')
        c = std::cin.get();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = std::cin.get();
    }
}

inline void write(int x) {
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