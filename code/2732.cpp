// 2732.cpp
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const int INF = 0x7fffffff / 3;
struct WITCH {
    int x, y, r, t;
} A[505];
struct JL {
    int x, y;
} B[505];
struct Tree {
    int x, y, r;
} C[505];
struct front_star {
    int ne, to, v, tmp;
} a[100005];
int h[100005] = {0}, cnt = 1, N, M, K, S, T, Gap[100005] = {0},
    dis[100005] = {0};
void Addedge(int x, int y, int v) {
    a[++cnt].to = y;
    a[cnt].v = a[cnt].tmp = v;
    a[cnt].ne = h[x];
    h[x] = cnt;
    a[++cnt].to = x;
    a[cnt].v = a[cnt].tmp = 0;
    a[cnt].ne = h[y];
    h[y] = cnt;
}
double dist(int x1, int y1, int x2, int y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
bool Conflict(WITCH A, JL B, Tree C) {
    double d1 = sqrt(dist(A.x, A.y, C.x, C.y) - C.r * C.r),
           d2 = sqrt(dist(B.x, B.y, C.x, C.y) - C.r * C.r);
    return d1 + d2 < sqrt(dist(A.x, A.y, B.x, B.y));
}
void Read() {
    scanf("%d%d%d", &N, &M, &K);
    int i, j, k, bj;
    for (i = 1; i <= N; i++)
        scanf("%d%d%d%d", &A[i].x, &A[i].y, &A[i].r, &A[i].t);
    for (i = 1; i <= M; i++)
        scanf("%d%d", &B[i].x, &B[i].y);
    for (i = 1; i <= K; i++)
        scanf("%d%d%d", &C[i].x, &C[i].y, &C[i].r);
    for (i = 1; i <= N; i++) {
        Addedge(0, i, INF);
        for (j = 1; j <= M; j++) {
            if (dist(A[i].x, A[i].y, B[j].x, B[j].y) > A[i].r * A[i].r)
                continue;
            bj = 0;
            for (k = 1; k <= K; k++)
                if (Conflict(A[i], B[j], C[k])) {
                    bj = 1;
                    break;
                }
            if (!bj) {
                Addedge(i, j + N, 1);
            }
        }
    }
    for (i = 1; i <= M; i++)
        Addedge(i + N, M + N + 1, 1);
    S = 0;
    T = N + M + 1;
    N = T + 1;
}
int DFS(int x, int maxf) {
    if (x == T)
        return maxf;
    int y, k, ret = 0, dlt;
    for (k = h[x]; k; k = a[k].ne) {
        y = a[k].to;
        if (a[k].v && dis[x] == dis[y] + 1) {
            dlt = DFS(y, min(maxf, a[k].v));
            a[k].v -= dlt;
            a[k ^ 1].v += dlt;
            maxf -= dlt;
            ret += dlt;
            if (maxf == 0 || dis[S] == N)
                return ret;
        }
    }
    if (!(--Gap[dis[x]]))
        dis[S] = N;
    Gap[++dis[x]]++;
    return ret;
}
int Sap(int tot) {
    int i, k, ans = 0;
    for (i = 0; i <= N; i++)
        Gap[i] = dis[i] = 0;
    for (i = 2; i <= cnt; i++)
        a[i].v = a[i].tmp;
    for (k = h[0]; k; k = a[k].ne)
        a[k].v = tot / A[a[k].to].t + 1;
    Gap[0] = N;
    while (dis[S] < N)
        ans += DFS(S, INF);
    return ans;
}
int Binary() {
    int L = 0, R = 500000, mid;
    while (L <= R) {
        mid = (L + R) / 2;
        if (Sap(mid) == M)
            R = mid - 1;
        else
            L = mid + 1;
    }
    if (L > 500000)
        return -1;
    return L;
}
int main() {
    Read();
    printf("%d", Binary());
    return 0;
}
