// 2674.cpp
#include <algorithm>
#include <iostream>

int n, m, x, y, z, k, num, ans, cnt = 0;
int prt[1010], head[1010], vst[1010], k0 = 0;
int maxlen[1010], maxs[1010], maxe[1010];
int id[1010], cnt0 = 0, head0[1010], minn[1010];
int minid[1010], best, link[1010], ch, d;

struct edge {
    int st, to, value;
    bool operator<(edge const &e) const { return value < e.value; }
} a[200010];

struct old_ {
    int next, to, value;
} c[200010];

struct new_ {
    int next, to, value;
} b[200010];

int getfather(int x);
void add(int x, int y, int z);
void add0(int x, int y, int z);
void dfs(int v);
int kruskal();
void update(int x, int fa, int mv, int ms, int me);
void del(int s, int e);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        std::cin >> a[i].st >> a[i].to >> a[i].value;
        add0(a[i].st, a[i].to, a[i].value);
        add0(a[i].to, a[i].st, a[i].value);
    }
    std::cin >> k;
    for (int i = 1; i <= n; i++)
        prt[i] = i;
    std::sort(a + 1, a + m + 1);
    vst[1] = 1;
    for (int i = 2; i <= n; i++)
        if (!vst[i]) {
            k0++;
            dfs(i);
            minn[k0] = 0xfffffff;
            if (k0 > k) {
                std::cout << "-1\n";
                return 0;
            }
        }
    if (!kruskal()) {
        std::cout << "-1\n";
        return 0;
    }
    for (int i = head0[1]; i; i = c[i].next) {
        int t = c[i].to;
        if (c[i].value < minn[id[t]]) {
            minn[id[t]] = c[i].value;
            minid[id[t]] = t;
        }
    }
    for (int i = 1; i <= k0; i++) {
        if (minn[i] == 0xfffffff) {
            std::cout << "-1\n";
            return 0;
        }
        ans += minn[i];
        add(minid[i], 1, minn[i]);
        add(1, minid[i], minn[i]);
        link[minid[i]] = 1;
    }
    for (int i = 1; i <= k - k0; i++) {
        update(1, 0, 0, 0, 0);
        best = 0;
        for (int i = head0[1]; i; i = c[i].next) {
            int t = c[i].to;
            if (!link[t] && c[i].value - maxlen[t] < best) {
                best = c[i].value - maxlen[t];
                ch = t;
                d = c[i].value;
            }
        }
        if (best == 0)
            break;
        del(maxs[ch], maxe[ch]);
        del(maxe[ch], maxs[ch]);
        add(1, ch, d);
        link[ch] = 1;
        ans += best;
    }
    std::cout << ans << '\n';
    return 0;
}

int getfather(int x) {
    if (prt[x] == x)
        return x;
    prt[x] = getfather(prt[x]);
    return prt[x];
}

void add(int x, int y, int z) {
    cnt++;
    b[cnt].next = head[x];
    b[cnt].to = y;
    b[cnt].value = z;
    head[x] = cnt;
}

void add0(int x, int y, int z) {
    cnt0++;
    c[cnt0].next = head0[x];
    c[cnt0].to = y;
    c[cnt0].value = z;
    head0[x] = cnt0;
}

void dfs(int v) {
    id[v] = k0;
    vst[v] = 1;
    for (int i = head0[v]; i; i = c[i].next) {
        int t = c[i].to;
        if (!vst[t])
            dfs(t);
    }
}

int kruskal() {
    num = ans = 0;
    for (int i = 1; i <= n; i++)
        prt[i] = i;
    for (int i = 1; i <= m; i++) {
        if (a[i].st == 1 || a[i].to == 1)
            continue;
        int fx = getfather(a[i].st), fy = getfather(a[i].to);
        if (fx != fy) {
            prt[fx] = fy;
            num++;
            add(a[i].st, a[i].to, a[i].value);
            add(a[i].to, a[i].st, a[i].value);
            ans += a[i].value;
            if (num == n - k0 - 1)
                break;
        }
    }
    if (num == n - k0 - 1)
        return 1;
    return 0;
}

void update(int x, int fa, int mv, int ms, int me) {
    maxlen[x] = mv;
    maxs[x] = ms;
    maxe[x] = me;
    for (int i = head[x]; i; i = b[i].next) {
        int t = b[i].to;
        if (t != fa) {
            if (b[i].value > mv)
                update(t, x, b[i].value, x, t);
            else
                update(t, x, mv, ms, me);
        }
    }
}

void del(int s, int e) {
    if (b[head[s]].to == e)
        head[s] = b[head[s]].next;
    else {
        for (int i = head[s]; i; i = b[i].next) {
            int q = b[i].next;
            int t = b[q].to;
            if (t == e) {
                b[i].next = b[q].next;
                break;
            }
        }
    }
}