// 1619.cpp(Tarjan)
#include <iostream>

struct edge {
    int to;
    int next;
} a[200001 << 1];

struct query {
    int to;
    int next;
    int num;
} q[200001 << 1];

int root = 0, ans[200001] = {0}, a0[200001] = {0}, q0[200001] = {0}, prt[200001] = {0}, n, m, na = 0, nq = 0;
bool vst[200001] = {false}, mark[200001] = {false};

int search(int mx);
void addedge(int mx, int my);
void addquery(int mx, int my, int mnum);
void tarjan(int mx);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1, x, y; i < n; i++) {
        std::cin >> x >> y;
        addedge(x, y);
        prt[y] = x;
    }
    for (int i = 1, x, y; i <= m; i++) {
        std::cin >> x >> y;
        addquery(x, y, i);
        addquery(y, x, i);
    }
    root = 1;
    while (prt[root])
        root = prt[root];
    tarjan(root);
    for (int i = 1; i <= m; i++)
        std::cout << ans[i] << '\n';
    return 0;
}

int search(int mx) {
    if (prt[mx] == mx)
        return mx;
    prt[mx] = search(prt[mx]);
    return prt[mx];
}

void addedge(int mx, int my) {
    na++;
    a[na].to = my;
    a[na].next = a0[mx];
    a0[mx] = na;
}

void addquery(int mx, int my, int mnum) {
    nq++;
    q[nq].to = my;
    q[nq].next = q0[mx];
    q0[mx] = nq;
    q[nq].num = mnum;
}

void tarjan(int mx) {
    vst[mx] = true;
    prt[mx] = mx;
    for (int i = a0[mx], y; i; i = a[i].next) {
        y = a[i].to;
        if (!vst[y]) {
            tarjan(y);
            prt[y] = mx;
        }
    }
    mark[mx] = true;
    for (int i = q0[mx], y; i; i = q[i].next) {
        y = q[i].to;
        if (mark[y])
            ans[q[i].num] = search(y);
    }
}