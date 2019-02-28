// 2674.cpp
#include <cstring>
#include <iostream>

int const Maxn = 510, Maxm = 50010;
int n, m, k, k0 = 0;
int bl[Maxn] = {0}, num[Maxn] = {0}, pre[Maxn];
int ans, a[Maxn], dis[Maxn], maxlen[Maxn], maxs[Maxn], maxe[Maxn];
bool vis[Maxn] = {false}, link[Maxn] = {false}, pv[Maxn], throwout = false;

struct graph {
    int head[Maxn], tot = 0;
    struct edges {
        int ver, edge, next;
    } e[Maxm];
    inline void add(int u, int v, int w) {
        e[++tot].ver = v, e[tot].edge = w, e[tot].next = head[u], head[u] = tot;
        e[++tot].ver = u, e[tot].edge = w, e[tot].next = head[v], head[v] = tot;
    }
} w, g;

void dfs(int x);
void prim();
void update(int x, int prt, int mx, int ms, int me);
void del(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1, p1, p2, d; i <= m; i++)
        std::cin >> p1 >> p2 >> d, w.add(p1, p2, d);
    std::cin >> k;
    vis[1] = true;
    ans = k0 = 0;
    for (int i = 2; i <= n; i++)
        if (!vis[i]) {
            if (++k0 > k) {
                std::cout << "-1\n";
                return 0;
            }
            dfs(i), prim();
        }
    if (throwout) {
        std::cout << "-1\n";
        return 0;
    }
    for (int i = 1, ch, d; i <= k - k0; i++) {
        memset(pv, false, sizeof(pv));
        update(1, 0, 0, 0, 0);
        int best = 0;
        for (int p = w.head[1]; p; p = w.e[p].next) {
            int v = w.e[p].ver;
            if (!link[v] && (w.e[p].edge - maxlen[v] < best)) {
                best = w.e[p].edge - maxlen[v];
                ch = v;
                d = w.e[p].edge;
            }
        }
        if (!best)
            break;
        del(maxs[ch], maxe[ch]), del(maxe[ch], maxs[ch]);
        g.add(1, ch, d);
        link[ch] = true;
        ans += best;
    }
    std::cout << ans << '\n';
    return 0;
}

void dfs(int x) {
    bl[x] = k0, vis[x] = true, a[++num[k0]] = x;
    for (int p = w.head[x]; p; p = w.e[p].next)
        if (!vis[w.e[p].ver])
            dfs(w.e[p].ver);
}

void prim() {
    int minn, t;
    for (int i = 1; i <= num[k0]; i++)
        dis[a[i]] = 0x3f3f3f3f, pv[a[i]] = false;
    dis[a[1]] = 0;
    pre[a[1]] = -1;
    for (int i = 1, t; i <= num[k0]; i++) {
        minn = 0x3f3f3f3f;
        for (int j = 1; j <= num[k0]; j++)
            if (!pv[a[j]] && minn > dis[a[j]])
                minn = dis[a[j]], t = j;
        if (minn == 0x3f3f3f3f)
            throwout = true;
        pv[a[t]] = true;
        if (pre[a[t]] != -1)
            g.add(pre[a[t]], a[t], dis[a[t]]);
        ans += dis[a[t]];
        for (int l = w.head[a[t]]; l; l = w.e[l].next) {
            int y = w.e[l].ver;
            if (y != 1 && (!pv[y]) && dis[y] > w.e[l].edge)
                dis[y] = w.e[l].edge, pre[y] = a[l];
        }
    }
    minn = 0x3f3f3f3f;
    for (int p = w.head[1]; p; p = w.e[p].next)
        if (bl[w.e[p].ver] == k0 && w.e[p].edge < minn)
            minn = w.e[p].edge, t = w.e[p].ver;
    if (minn == 0x3f3f3f3f)
        throwout = true;
    g.add(1, t, minn);
    link[t] = true, ans += minn;
}

void update(int x, int prt, int mx, int ms, int me) {
    for (int p = g.head[x]; p; p = g.e[p].next)
        if (g.e[p].ver != prt) {
            if (g.e[p].edge > mx)
                update(g.e[p].ver, x, g.e[p].edge, x, g.e[p].ver);
            else
                update(g.e[p].ver, x, mx, ms, me);
        }
    maxlen[x] = mx, maxs[x] = ms, maxe[x] = me;
}

void del(int x, int y) {
    if (g.e[g.head[x]].ver == y)
        g.head[x] = g.e[g.head[x]].next;
    else
        for (int p = g.head[x], q; p; q = p, p = g.e[p].next) {
            q = g.e[p].next;
            if (g.e[q].ver == y) {
                g.e[p].next = g.e[q].next;
                break;
            }
        }
}