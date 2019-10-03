// mineral.cpp
#include <fstream>
#include <queue>
#include <algorithm>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("mineral.in");
std::ofstream out("mineral.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

long long const Mod = 998244353, Maxn = 100001;
long long pos[Maxn], n, m, ans, cnt, tmp1;
bool vis[Maxn];

struct Node {
    long long l, r, num;
    bool operator<(Node const &y) const { return r > y.r; }
} a[Maxn];

std::priority_queue<Node> q;

bool comp(Node const &x, Node const &y) { return x.l < y.l; }
inline long long power(long long x);
long long binary_search(long long val);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m;
    if (n <= 1000) {
        for (long long i = 1; i <= n; i++)
			in >> a[i].l >> a[i].r;
        for (long long i=1; i<=m; i++) {
            in >> pos[i];
            long long tmp1 = 0, tmp2 = 0;
            for (long long j = 1; j <= n; j++) {
                if (pos[i] <= a[j].r && pos[i] >= a[j].l) {
                    if (vis[j])
						tmp1++;
                    else
						tmp2++;
                    vis[j] = true;
                }
            }
            ans = (ans + (power(tmp1) * (power(tmp2) - 1)) % Mod) % Mod;
        }
    } else {
        for (long long i = 1; i <= n; i++)
			in >> a[i].l >> a[i].r;
        std::sort(a + 1, a + 1 + n, comp);
        for (long long i = 1; i <= n; i++)
			a[i].num = i;
        for (long long i = 1; i <= m; i++)
			in >> pos[i];
        std::sort(pos + 1, pos + 1 + m);
        for (long long i = 1; i <= m; i++) {
            long long tot = binary_search(pos[i]), dcnt = cnt, rec = 0;
            while (cnt < tot)
				q.push(a[++cnt]), rec++;
            if (q.size()) {
                while (q.top().r < pos[i]) {
                    if (q.top().num <= dcnt)
						tmp1--;
                    q.pop();
                    if (!q.size())
						break;
                }
            }
            ans = (ans + (power(tmp1) * (power(rec) - 1)) % Mod) % Mod;
            tmp1 += rec;
        }
        out << ans << '\n';
        return 0;
    }
}

inline long long power(long long x) {
    long long a = 2, ret = 1;
    while (x) {
        if (x % 2 == 1)
			ret = a * ret % Mod;
        x = x >> 1;
        a = a * a % Mod;
    }
    return ret;
}

long long binary_search(long long val) {
    long long l = 1, r = n, ret = 0;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (a[mid].l <= val)
			ret = mid, l = mid + 1;
        else
			r = mid - 1;
    }
    return ret;
}
