// 4559.cpp
// 不知道
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;
const int maxn = 10001;
int n, m, block, qcnt, ccnt, L, R, head, ans;
int a[maxn], b[maxn], A[maxn], cnt[1000001];
char ch[5];
struct Ask {
    int l, r, lb, rb, tim, id;
} q[maxn];

struct Modify {
    int x, y, last;
} c[maxn];

inline int Getblock(int num) { return (num - 1) / block + 1; }

bool cmp(Ask q, Ask qq) {
    if (q.lb == qq.lb) {
        if (q.rb == qq.rb)
            return q.tim < qq.tim;
        return q.rb < qq.rb;
    }
    return q.lb < qq.lb;
}

void Change(int x, int col) {
    if (L <= x && x <= R) {
        cnt[a[x]]--;
        if (cnt[a[x]] == 0)
            ans--;
        a[x] = col;
        if (cnt[a[x]] == 0)
            ans++;
        cnt[a[x]]++;
    } else
        a[x] = col;
}

void Update(int x, int d) {
    int temp = cnt[a[x]];
    cnt[a[x]] += d;
    if (temp == 0 && cnt[a[x]] == 1)
        ans++;
    else if (temp == 1 && cnt[a[x]] == 0)
        ans--;
}

void MoDui() {
    L = 1;
    R = 0;
    head = 0;
    for (int i = 1; i <= qcnt; i++) {
        while (head > q[i].tim) {
            Change(c[head].x, c[head].last);
            head--;
        }
        while (head < q[i].tim) {
            head++;
            Change(c[head].x, c[head].y);
        }
        while (R < q[i].r)
            R++, Update(R, 1);
        while (L > q[i].l)
            L--, Update(L, 1);
        while (R > q[i].r)
            Update(R, -1), R--;
        while (L < q[i].l)
            Update(L, -1), L++;
        A[q[i].id] = ans;
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    block = sqrt(n);
    for (int i = 1; i <= m; i++) {
        scanf("%s", ch);
        if (ch[0] == 'R') {
            ccnt++;
            scanf("%d%d", &c[ccnt].x, &c[ccnt].y);
            c[ccnt].last = b[c[ccnt].x];
            b[c[ccnt].x] = c[ccnt].y;
        } else {
            qcnt++;
            scanf("%d%d", &q[qcnt].l, &q[qcnt].r);
            q[qcnt].id = qcnt;
            q[qcnt].lb = Getblock(q[qcnt].l);
            q[qcnt].rb = Getblock(q[qcnt].r);
            q[qcnt].tim = ccnt;
        }
    }
    sort(q + 1, q + qcnt + 1, cmp);
    MoDui();
    for (int i = 1; i <= qcnt; i++)
        printf("%d\n", A[i]);
    return 0;
}