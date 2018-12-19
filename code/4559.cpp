// 4559.cpp
#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>

int const maxn = 10001;
int n, m, blks, qcnt, ccnt, l, r, h, ans;
int a[maxn], b[maxn], res[maxn], cnt[1000001];

struct query {
    int l, r;
    int lb, rb;
    int tim, id;
    bool operator<(query const &qs) const;
} qs[maxn];

struct modify {
    int x, y, latest;
} ms[maxn];

void change(int x, int col);
void update(int x, int d);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::string ch;
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++)
        std::cin >> a[i], b[i] = a[i];
    blks = int(sqrt(n));
    for (int i = 1; i <= m; i++) {
        std::cin >> ch;
        if (ch[0] == 'R') {
            ccnt++, std::cin >> ms[ccnt].x >> ms[ccnt].y;
            ms[ccnt].latest = b[ms[ccnt].x];
            b[ms[ccnt].x] = ms[ccnt].y;
        } else {
            qcnt++, std::cin >> qs[qcnt].l >> qs[qcnt].r;
            qs[qcnt].id = qcnt;
            qs[qcnt].lb = (qs[qcnt].l - 1) / blks + 1;
            qs[qcnt].rb = (qs[qcnt].r - 1) / blks + 1;
            qs[qcnt].tim = ccnt;
        }
    }
    std::sort(qs + 1, qs + qcnt + 1);
    l = 1, r = 0, h = 0;
    for (int i = 1; i <= qcnt; i++) {
        while (h > qs[i].tim)
            change(ms[h].x, ms[h].latest), h--;
        while (h < qs[i].tim)
            h++, change(ms[h].x, ms[h].y);
        while (r < qs[i].r)
            update(++r, 1);
        while (l > qs[i].l)
            update(--l, 1);
        while (r > qs[i].r)
            update(r--, -1);
        while (l < qs[i].l)
            update(l++, -1);
        res[qs[i].id] = ans;
    }
    for (int i = 1; i <= qcnt; i++)
        std::cout << res[i] << '\n';
    return 0;
}

bool query::operator<(query const &qs) const {
    if (lb == qs.lb) {
        if (rb == qs.rb)
            return tim < qs.tim;
        return rb < qs.rb;
    }
    return lb < qs.lb;
}

void change(int x, int col) {
    if ((l <= x && x <= r) && !(--cnt[a[x]]))
        ans--;
    a[x] = col;
    if ((l <= x && x <= r) && !(cnt[a[x]]++))
        ans++;
}

void update(int x, int d) {
    int temp = cnt[a[x]];
    cnt[a[x]] += d;
    if (temp == 0 && cnt[a[x]] == 1)
        ans++;
    else if (temp == 1 && cnt[a[x]] == 0)
        ans--;
}