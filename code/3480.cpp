// 3480.cpp
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

int const Maxn = 1000005;
int cnt = 0, stack[Maxn], size[Maxn], b[Maxn];
long long ans = 0;
struct tree {
    int l, r;
    int key, d, size;
} a[Maxn];

int merge(int x, int y);
int make_node(int val);
int del(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, now = 0, p = 0;
    std::cin >> n;
    for (int i = 1, x; i <= n; i++) {
        std::cin >> x;
        b[i] = x;
        stack[++now] = make_node(x);
        size[now] = 1;
        while (now > 1 && a[stack[now]].key < a[stack[now - 1]].key) {
            now--;
            stack[now] = merge(stack[now], stack[now + 1]);
            size[now] += size[now + 1];
            while (size[now] + 1 < a[stack[now]].size * 2)
                stack[now] = del(stack[now]);
        }
    }
    for (int j = 1; j <= now; j++)
        for (int i = 1; i <= size[j]; i++)
            ans += abs(b[++p] - a[stack[j]].key);
    std::cout << ans << '\n';
    return 0;
}

int merge(int x, int y) {
    if (!(x && y))
        return x + y;
    if (a[x].key < a[y].key)
        std::swap(x, y);
    a[x].r = merge(a[x].r, y);
    a[x].size = a[a[x].l].size + a[a[x].r].size + 1;
    if (a[a[x].r].d > a[a[x].l].d)
        std::swap(a[x].l, a[x].r);
    if (!a[x].r)
        a[x].d = 0;
    else
        a[x].d = a[a[x].r].d + 1;
    return x;
}

int make_node(int val) {
    a[++cnt].key = val;
    a[cnt].size = 1;
    a[cnt].l = a[cnt].r = a[cnt].d = 0;
    return cnt;
}

int del(int x) {
    int tmp = merge(a[x].l, a[x].r);
    a[x].l = a[x].r = a[x].d = a[x].key = 0;
    return tmp;
}