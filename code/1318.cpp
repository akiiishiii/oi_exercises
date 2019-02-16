// 1318.cpp
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>

long long n, a[1000010];
double f[1000010], g[1000010];

struct status {
    long long l, r, id;
} q[1000010];

inline double calc(long long j, long long i) { return a[j] - a[i] + sqrt(llabs(i - j)); }
long long binary_search(status a, long long x);
void dp(double f[]);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (long long i = 1; i <= n; i++)
        std::cin >> a[i];
    dp(f);
    std::reverse(a + 1, a + n + 1);
    dp(g);
    for (long long i = 1; i <= n; i++)
        std::cout << std::max(0ll, (long long)ceil(std::max(f[i], g[n - i + 1]))) << '\n';
    return 0;
}

long long binary_search(status a, long long x) {
    long long l = a.l, r = a.r;
    while (l <= r) {
        long long mid = (l + r) >> 1;
        if (calc(x, mid) < calc(a.id, mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

void dp(double f[]) {
    long long head = 1, tail = 0;
    for (long long i = 1; i <= n; i++) {
        q[head].l++;
        if (head <= tail && q[head].l > q[head].r)
            head++;
        if (head > tail || calc(i, n) > calc(q[tail].id, n)) {
            while (head <= tail &&
                   calc(q[tail].id, q[tail].l) < calc(i, q[tail].l))
                tail--;
            if (head > tail)
                tail++, q[tail].l = i, q[tail].r = n, q[tail].id = i;
            else {
                long long t = binary_search(q[tail], i);
                q[tail].r = t - 1;
                tail++, q[tail].l = t, q[tail].r = n, q[tail].id = i;
            }
        }
        f[i] = calc(q[head].id, i);
    }
}