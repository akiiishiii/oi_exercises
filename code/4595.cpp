// 4595.cpp
#include <cstdlib>
#include <ctime>
#include <iostream>

long long const Mod = 1 << 31;
long long multi(long long a, long long b, long long mod);
bool miller_rabin(long long n);
long long power(long long a, long long b, long long p);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long n;
    srand(unsigned(time(NULL)));
    std::cin >> n;
    for (int i = 1; i <= 100000; i++, n = (n + 1234567890) % Mod)
        std::cout.put(int(miller_rabin(n)) + '0');
    std::cout.put('\n');
    return 0;
}

long long power(long long a, long long b, long long p) {
    long long ans = 1;
    while (b) {
        if (b & 1)
            ans = multi(ans, a, p);
        b >>= 1;
        a = multi(a, a, p);
    }
    return ans;
}

long long multi(long long a, long long b, long long p) {
    long long ans = 0;
    while (b) {
        if (b & 1)
            ans = (ans + a) % p;
        b >>= 1;
        a = (a + a) % p;
    }
    return ans;
}

bool miller_rabin(long long n) {
    if (n == 2)
        return true;
    if (n < 2 || !(n & 1))
        return false;
    long long m = n - 1;
    int k = 0;
    while (!(m & 1))
        k++, m >>= 1;
    for (int i = 1; i <= 10; i++) {
        long long a = rand() % (n - 1) + 1, y = 0;
        long long x = power(a, m, n);
        for (int j = 1; j <= k; j++) {
            y = multi(x, x, n);
            if (y == 1 && x != 1 && x != n - 1)
                return false;
            x = y;
        }
        if (y != 1)
            return false;
    }
    return true;
}