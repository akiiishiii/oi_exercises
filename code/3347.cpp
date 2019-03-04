// 3374.cpp
#include <iostream>
#include <cmath>
#include <map>

long long baby_step_giant_step(long long a, long long b, long long p);
long long power(long long a, long long b, long long p);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long a, b, p, ans;
    while (std::cin >> p >> a >> b) {
        ans = baby_step_giant_step(a, b, p);
        if (ans == -1)
            std::cout << "no solution\n";
        else
            std::cout << ans << '\n';
    }
    return 0;
}

long long baby_step_giant_step(long long a, long long b, long long p) {
    std::map<long long, long long> hash;
    hash.clear();
    b %= p;
    long long t = (long long)sqrt(p) + 1;
    for (long long j = 0; j < t; j++) {
        long long val = (long long)b * power(a, j, p) % p;
        hash[val] = j;
    }
    a = power(a, t, p);
    if (a == 0)
        return b == 0 ? 1 : -1;
    for (long long i = 0; i <= t; i++) {
        long long val = power(a, i, p);
        long long j = hash.find(val) == hash.end() ? -1 : hash[val];
        if (j >= 0 && i * t - j >= 0)
            return i * t - j;
    }
    return -1;
}

long long power(long long a, long long b, long long p) {
    long long ans = 1;
    while (b) {
        if (b & 1)
            ans = ans % p * a % p;
        a = a * a % p;
        b = b / 2;
    }
    return ans;
}