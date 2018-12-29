// 2845.cpp
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 100010;
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define erp(i, a, b) for (int i = a; i >= b; --i)

int N, M;
namespace BIT {
int c[MAXN], r;
void add(int i, int x) {
    for (; i <= N; i += i & -i)
        c[i] += x;
}
int sum(int i) {
    r = 0;
    for (; i > 0; i -= i & -i)
        r += c[i];
    return r;
}
}; // namespace BIT

struct dot {
    int t, x, y; // every t, x, y is unique
} a[MAXN], np[MAXN];

int rxiao[MAXN], lda[MAXN];
long long ans[MAXN];
void cdq(int L, int R) {
    using namespace BIT;
    if (L >= R)
        return;
    int mid = (L + R) >> 1;

    int l1 = L, l2 = mid + 1;
    rep(i, L, R) {
        if (a[i].t <= mid)
            np[l1++] = a[i];
        else
            np[l2++] = a[i];
    }
    rep(i, L, R) a[i] = np[i];

    l1 = L;
    rep(i, mid + 1, R) // 先找坐标更小，值更大的
    {
        for (; l1 <= mid && np[l1].x < np[i].x; ++l1)
            add(np[l1].y, 1);
        lda[np[i].t] += (l1 - L) - sum(np[i].y); //注意是+=
    }
    rep(i, L, l1 - 1) add(np[i].y, -1); //将树状数组清零

    l1 = mid;
    erp(i, R, mid + 1) // 再找坐标更大，值更小的
    {
        for (; l1 >= L && np[l1].x > np[i].x; --l1)
            add(np[l1].y, 1);
        rxiao[np[i].t] += sum(np[i].y - 1);
    }
    rep(i, l1 + 1, mid) add(np[i].y, -1);

    cdq(L, mid), cdq(mid + 1, R);
}

int pos[MAXN];
int main() {
    std::cin >> N >> M;
    rep(i, 1, N) std::cin >> a[i].y, a[i].x = i, pos[a[i].y] = i;
    int t, tmr = N;
    rep(i, 1, M) std::cin >> t, a[pos[t]].t = tmr--;
    rep(i, 1, N) if (!a[i].t) a[i].t = tmr--;
    cdq(1, N);
    rep(i, 1, N) ans[i] = ans[i - 1] + rxiao[i] + lda[i];
    erp(i, N, N - M + 1) cout << ans[i] << '\n';
    return 0;
}