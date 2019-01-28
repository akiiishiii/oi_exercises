// 3976.cpp
#include <iostream>
#include <algorithm>

int const Maxn = 100005;
std::pair<int, int> f[Maxn];
int prime[Maxn], mu[Maxn], bit[Maxn], ans[Maxn];
bool vis[Maxn];

struct query {
    query() = default;
    ~query() = default;
    query(int _n, int _m, int _a, int _id) : n(_n), m(_m), a(_a), id(_id) {}
    int n, m, a, id;
    bool operator<(query const &q) const { return a < q.a; }
} q[20005];

inline int lowbit(int x) { return x & -x; }
void add(int p, int x);
int ask(int p);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int Q;
    mu[1] = 1;
    for (long long i = 2; i <= Maxn - 5; i++) {
        if (!vis[i])
            mu[i] = -1, prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && i * prime[j] <= Maxn - 5; j++) {
            vis[i * prime[j]] = 1;
            if (!(i % prime[j]))
                break;
            else
                mu[i * prime[j]] = -mu[i];
        }
    }
    for (int i = 1; i <= Maxn - 5; i++)
        for (int j = i; j <= Maxn - 5; j += i)
            f[j].first += i;
    for (int i = 1; i <= Maxn - 5; i++)
        f[i].second = i;
    std::cin >> Q;
    for (int i = 1, n, m, a; i <= Q; i++)
        std::cin >> n >> m >> a, q[i] = query(n, m, a, i);
    std::sort(q + 1, q + 1 + Q);
    std::sort(f + 1, f + Maxn - 4);
    int pos = 1;
    for (int T = 1; T <= Q; T++) {
        while (pos <= Maxn - 5 && f[pos].first <= q[T].a) {
            int k = f[pos].second;
            for (int j = k; j <= Maxn - 5; j += k)
                add(j, f[pos].first * mu[j / k]);
            pos++;
        }
        int divv, nn = q[T].n, mm = q[T].m, res = 0;
        if (nn > mm)
            std::swap(nn, mm);
        for (int i = 1; i <= nn; i = divv + 1) {
            divv = std::min(nn / (nn / i), mm / (mm / i));
            res += (nn / i) * (mm / i) * (ask(divv) - ask(i - 1));
        }
        ans[q[T].id] = res & 0x7fffffff;
    }
    for (int i = 1; i <= Q; i++)
        std::cout << ans[i] << '\n';
    return 0;
}

void add(int p, int x) {
    for (int i = p; i <= Maxn - 5; i += lowbit(i))
        bit[i] += x;
}

int ask(int p) {
    int ret = 0;
    for (int i = p; i > 0; i -= lowbit(i))
        ret += bit[i];
    return ret;
}