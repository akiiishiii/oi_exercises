#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#define MAX 1000005
#define _MAX 100005
#define MAX_ 1200005
#define INF 0x7fffffff
using namespace std;
inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 &&
                   (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2)
               ? EOF
               : *p1++;
}
// inline char nc(){return getchar();}
inline int read() {
    char t;
    int u = 0, k = 1;
    t = nc();
    while (t < '0' || t > '9') {
        if (t == '-')
            k = -1;
        t = nc();
    }
    while (t >= '0' && t <= '9') {
        u = u * 10 + t - '0';
        t = nc();
    }
    return u * k;
}
int n, m, Q, tot = 0, cnt = 0, p_fa[MAX_][2], vst[MAX], ans[_MAX];
struct bianji {
    int st, to, val;
} b[MAX];
bool cmp(bianji x, bianji y) { return x.val < y.val; }
struct query {
    int op, x, y, val;
} q[_MAX];
vector<int> id[_MAX], To[_MAX];
//--------------------
int ch[MAX_][2], fa[MAX_], rev[MAX_], val[MAX_], aux[MAX_], mx[MAX_],
    mxid[MAX_];
int ID;
void pushup(int x) {
    if (mx[ch[x][0]] > mx[ch[x][1]]) {
        mx[x] = mx[ch[x][0]];
        mxid[x] = mxid[ch[x][0]];
    } else {
        mx[x] = mx[ch[x][1]];
        mxid[x] = mxid[ch[x][1]];
    }
    if (val[x] > mx[x]) {
        mx[x] = val[x];
        mxid[x] = x;
    }
}
void addrev(int x) {
    swap(ch[x][0], ch[x][1]);
    rev[x] ^= 1;
}
void pushdown(int x) {
    if (rev[x]) {
        addrev(ch[x][0]);
        addrev(ch[x][1]);
        rev[x] = 0;
    }
}
void rotate(int x) {
    int y = fa[x], z = fa[y], L = (ch[y][0] != x), R = L ^ 1;
    if (!aux[y])
        aux[y] = 1, aux[x] = 0;
    else {
        if (ch[z][0] == y)
            ch[z][0] = x;
        else
            ch[z][1] = x;
    }
    fa[x] = z;
    fa[y] = x;
    fa[ch[x][R]] = y;
    ch[y][L] = ch[x][R];
    ch[x][R] = y;
    pushup(y);
    pushup(x);
}
void splay(int x) {
    pushdown(x);
    while (aux[x]) {
        int y = fa[x], z = fa[y];
        if (aux[y])
            pushdown(z);
        pushdown(y);
        pushdown(x);
        if (aux[y]) {
            if (ch[y][0] == x ^ ch[z][0] == y)
                rotate(x);
            else
                rotate(y);
        }
        rotate(x);
    }
}
void access(int x) {
    int y = 0;
    while (x) {
        splay(x);
        aux[ch[x][1]] = 0;
        ch[x][1] = y;
        aux[y] = 1;
        pushup(x);
        y = x;
        x = fa[x];
    }
}
void makeroot(int x) {
    access(x);
    splay(x);
    addrev(x);
}
void link(int x, int y) {
    makeroot(x);
    fa[x] = y;
}
void cut(int x, int y) {
    makeroot(x);
    access(y);
    splay(y);
    ch[y][0] = fa[x] = aux[x] = 0;
}
void split(int x, int y) {
    makeroot(x);
    access(y);
    splay(y);
}
int getmax(int x, int y) {
    split(x, y);
    ID = mxid[y];
    return mx[y];
}
//--------------------
int prt[MAX];
int findprt(int x) {
    if (prt[x] == x)
        return x;
    return prt[x] = findprt(prt[x]);
}
void Kruskal() {
    sort(b + 1, b + tot + 1, cmp);
    for (int i = 1; i <= n; i++)
        prt[i] = i;
    int num = 0;
    for (int i = 1; i <= tot; i++) {
        int f1 = findprt(b[i].st), f2 = findprt(b[i].to);
        if (f1 != f2) {
            prt[f1] = f2;
            num++;
            val[++cnt] = mx[cnt] = b[i].val;
            mxid[cnt] = cnt;
            link(cnt, b[i].st);
            link(cnt, b[i].to);
            p_fa[cnt][0] = b[i].st;
            p_fa[cnt][1] = b[i].to;
        }
        if (num == n - 1)
            break;
    }
}
int main() {
    n = read();
    m = read();
    Q = read();
    cnt = n;
    for (int i = 1; i <= n; i++)
        val[i] = mx[i] = 0, mxid[i] = i;
    for (int i = 1; i <= m; i++) {
        b[i].st = read();
        b[i].to = read();
        b[i].val = read();
        if (b[i].st > b[i].to)
            swap(b[i].st, b[i].to);
        To[b[i].st].push_back(b[i].to);
        id[b[i].st].push_back(i);
    }
    for (int i = 1; i <= Q; i++) {
        q[i].op = read();
        q[i].x = read();
        q[i].y = read();
        if (q[i].x > q[i].y)
            swap(q[i].x, q[i].y);
        if (q[i].op == 2) {
            for (int j = 0; j < To[q[i].x].size(); j++)
                if (To[q[i].x][j] == q[i].y) {
                    vst[id[q[i].x][j]] = 1;
                    q[i].val = b[id[q[i].x][j]].val;
                    break;
                }
        }
    }
    for (int i = 1; i <= m; i++)
        if (!vst[i])
            b[++tot] = b[i];
    Kruskal();
    while (Q) {
        if (q[Q].op == 1)
            ans[++ans[0]] = getmax(q[Q].x, q[Q].y);
        else {
            int MX = getmax(q[Q].x, q[Q].y);
            if (MX > q[Q].val) {
                cut(ID, p_fa[ID][0]);
                cut(ID, p_fa[ID][1]);
                val[++cnt] = mx[cnt] = q[Q].val;
                mxid[cnt] = cnt;
                link(cnt, q[Q].x);
                link(cnt, q[Q].y);
                p_fa[cnt][0] = q[Q].x;
                p_fa[cnt][1] = q[Q].y;
            }
        }
        Q--;
    }
    for (int i = ans[0]; i >= 1; i--)
        printf("%d\n", ans[i]);
    return 0;
}