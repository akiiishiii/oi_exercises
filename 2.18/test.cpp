#include <cstdio>
#include <cstring>
#include <iostream>
#define inf 0x7fffffff
using namespace std;
const int N = 205;
int n, m, cnt = 1, ans, S, T;
int last[N], b[N], q[N], d[N], inq[N], from[N];
struct Edge {
    int to, v, next, c, from;
} e[N * N * 5];
void insert(int u, int v, int w, int c) {
    e[++cnt].to = v;
    e[cnt].c = c;
    e[cnt].v = w;
    e[cnt].next = last[u];
    last[u] = cnt;
    e[cnt].from = u;
    e[++cnt].to = u;
    e[cnt].c = -c;
    e[cnt].v = 0;
    e[cnt].next = last[v];
    last[v] = cnt;
    e[cnt].from = v;
}
bool spfa() {
    for (int i = 0; i <= T; i++)
        d[i] = inf;
    int head = 0, tail = 1;
    d[0] = 0;
    q[0] = 0;
    inq[0] = 1;
    while (head != tail) {
        int now = q[head++];
        if (head == T)
            head = 0;
        for (int i = last[now]; i; i = e[i].next)
            if (e[i].v && e[i].c + d[now] < d[e[i].to]) {
                d[e[i].to] = e[i].c + d[now];
                from[e[i].to] = i;
                if (!inq[e[i].to]) {
                    inq[e[i].to] = 1;
                    q[tail++] = e[i].to;
                    if (tail == T)
                        tail = 0;
                }
            }
        inq[now] = 0;
    }
    return d[T] != inf;
}
void mcf() {
    int x = inf;
    for (int i = from[T]; i; i = from[e[i].from])
        x = min(e[i].v, x);
    for (int i = from[T]; i; i = from[e[i].from]) {
        ans += x * e[i].c;
        e[i].v -= x;
        e[i ^ 1].v += x;
    }
}
int main() {
    scanf("%d%d", &n, &m);
    S = n * 2 + 1;
    T = n * 2 + 2;
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        insert(i, i + n, 0, 0);
        b[i] -= x;
        b[i + n] += x;
    }
    insert(0, S, m, 0);
    for (int i = 1; i <= n; i++)
        insert(S, i, inf, 0);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1, x; j <= n; j++) {
            scanf("%d", &x);
            if (x != -1)
                insert(i + n, j, inf, x);
        }
    for (int i = 1; i <= n * 2; i++) {
        if (b[i] > 0)
            insert(0, i, b[i], 0);
        if (b[i] < 0)
            insert(i, T, -b[i], 0);
    }
    while (spfa())
        mcf();
        printf("%d", ans);
        return 0;
}