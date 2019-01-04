// 5244.cpp
#include <cstdlib>
#include <ctime>
#include <iostream>

int const Maxn = 500010;
int cnt, rts[Maxn];
struct treap {
    int key, rnd, size;
    int ch[2];
} t[Maxn * 50];

inline void newnode(int &k, int x) { t[k = ++cnt].key = x, t[k].size = 1, t[k].rnd = rand(); }
inline void update(int k) { t[k].size = t[t[k].ch[0]].size + t[t[k].ch[1]].size + 1; }
void split(int now, int k, int &x, int &y);
int merge(int x, int y);
void del(int &root, int w);
void ins(int &root, int w);
int getpos(int k, int w);
inline int getval(int k, int w) { return t[getpos(k, w)].key; }
int getkth(int &root, int w);
int getprev(int &root, int w);
int getnext(int &root, int w);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    srand(unsigned(time(NULL)));
    int n;
    std::cin >> n;
    for (int i = 1, v, opt, x; i <= n; ++i) {
        std::cin >> v >> opt >> x;
        rts[i] = rts[v];
        switch (opt) {
        case 1:
            ins(rts[i], x);
            break;
        case 2:
            del(rts[i], x);
            break;
        case 3:
            std::cout << getkth(rts[i], x) << '\n';
            break;
        case 4:
            std::cout << getval(rts[i], x) << '\n';
            break;
        case 5:
            std::cout << getprev(rts[i], x) << '\n';
            break;
        case 6:
            std::cout << getnext(rts[i], x) << '\n';
            break;
        default:
            break;
        }
    }
    return 0;
}

void split(int now, int k, int &x, int &y) {
    if (!now) {
        x = y = 0;
        return;
    }
    if (t[now].key <= k) {
        x = ++cnt;
        t[x] = t[now];
        split(t[x].ch[1], k, t[x].ch[1], y);
        update(x);
    } else {
        y = ++cnt;
        t[y] = t[now];
        split(t[y].ch[0], k, x, t[y].ch[0]);
        update(y);
    }
}

int merge(int x, int y) {
    if (!x || !y)
        return x + y;
    if (t[x].rnd > t[y].rnd) {
        int z = ++cnt;
        t[z] = t[x];
        t[z].ch[1] = merge(t[z].ch[1], y);
        update(z);
        return z;
    } else {
        int z = ++cnt;
        t[z] = t[y];
        t[z].ch[0] = merge(x, t[z].ch[0]);
        update(z);
        return z;
    }
}

void del(int &root, int w) {
    int x = 0, y = 0, z = 0;
    split(root, w, x, z);
    split(x, w - 1, x, y);
    y = merge(t[y].ch[0], t[y].ch[1]);
    root = merge(merge(x, y), z);
}

void ins(int &root, int w) {
    int x = 0, y = 0, z = 0;
    split(root, w, x, y);
    newnode(z, w);
    root = merge(merge(x, z), y);
}

int getpos(int k, int w) {
    while (true) {
        if (w <= t[t[k].ch[0]].size)
            k = t[k].ch[0];
        else if (w == t[t[k].ch[0]].size + 1)
            return k;
        else
            w -= t[t[k].ch[0]].size + 1, k = t[k].ch[1];
    }
}

int getkth(int &root, int w) {
    int x, y;
    split(root, w - 1, x, y);
    int ans = t[x].size + 1;
    root = merge(x, y);
    return ans;
}

int getprev(int &root, int w) {
    int x, y, k, ans;
    split(root, w - 1, x, y);
    if (!x)
        return -2147483647;
    k = t[x].size;
    ans = getval(x, k);
    root = merge(x, y);
    return ans;
}

int getnext(int &root, int w) {
    int x, y, ans;
    split(root, w, x, y);
    if (!y)
        return 2147483647;
    else
        ans = getval(y, 1);
    root = merge(x, y);
    return ans;
}