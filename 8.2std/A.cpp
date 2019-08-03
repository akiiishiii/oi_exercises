// A.cpp
#include <cmath>
#include <iostream>

int const Maxn = 35000;
double const eps = 1e-5;
int p[Maxn], vst[Maxn], cnt;

bool ispow(long long x, int d) {
    double t = pow(x, 1.0 / d);
    return (std::abs(round(t) - t) < eps);
}

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    for (int i = 2; i < Maxn; i++) {
        if (!vst[i])
            p[++cnt] = i;
        for (int j = 1; j <= cnt && i * p[j] < Maxn; j++) {
            vst[i * p[j]] = 1;
            if (i % p[j] == 0)
                break;
        }
    }
    int T;
    std::cin >> T;
    while (T--) {
        long long x;
        std::cin >> x;
        int d = pow(x, 0.2) + 5, ans = 1e8;
        for (int i = 1; i <= cnt && p[i] <= d; i++) {
            int tot = 0;
            while (x % p[i] == 0)
                x /= p[i], tot++;
            if (tot)
                ans = std::min(ans, tot);
        }
        if (x != 1) {
            if (ispow(x, 4))
                ans = std::min(ans, 4);
            else if (ispow(x, 3))
                ans = std::min(ans, 3);
            else if (ispow(x, 2))
                ans = std::min(ans, 2);
            else
                ans = 1;
        }
        std::cout << ans << '\n';
    }
    return 0;
}
