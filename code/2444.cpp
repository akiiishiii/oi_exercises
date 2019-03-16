// 2444.cpp
#include <iostream>

long long facts[1000005];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int t;
    long long a, b, r;
    std::cin >> t;
    while (t--) {
        std::cin >> a >> b >> r;
        int tot = 0;
        long long ans1 = 0, ans2 = 0;
        a--;
        for (long long i = 2; i * i <= r; ++i) {
            if (!(r % i)) {
                facts[tot++] = i;
                while (!(r % i))
                    r /= i;
            }
        }
        if (r > 1)
            facts[tot++] = r;
        for (int i = 1; i < (1 << tot); ++i) {
            long long mul = 1, cnt = 0;
            for (int j = 0; j < tot; ++j)
                if (i & (1 << j))
                    mul *= facts[j], cnt += 1ll;
            if (cnt & 1)
                ans1 += a / mul, ans2 += b / mul;
            else
                ans1 -= a / mul, ans2 -= b / mul;
        }
        std::cout << b - a + ans1 - ans2 << '\n';
    }
    return 0;
}
