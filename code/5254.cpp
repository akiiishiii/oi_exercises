// 5254.cpp
#include <iostream>

long long const P = 1e9 + 7;
long long a[5000005], s[5000005], sv[5000005], n;

long long power(long long x, long long p);
void read(long long &x);
void write(long long x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    read(n);
    for (int i = 1; i <= n; i++)
        read(a[i]);
    s[0] = 1;
    for (int i = 1; i <= n; ++i) {
        s[i] = s[i - 1] * a[i] % P;
    }
    sv[n] = power(s[n], P - 2) % P;
    for (int i = n; i >= 1; --i) {
        sv[i - 1] = sv[i] * a[i] % P;
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        long long t = sv[i] * s[i - 1] % P;
        ans = (ans * 998244353 + t) % P;
    }
    write(ans);
    std::cout.put('\n');
    return 0;
}

long long power(long long x, long long p) {
    long long ans = 1;
    while (p) {
        if (p & 1)
            ans = (ans * x) % P;
        x = (x * x) % P;
        p >>= 1;
    }
    return ans;
}

void read(long long &x) {
    x = 0;
    char c = std::cin.get();
    while (c < '0' || c > '9')
        c = std::cin.get();
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = std::cin.get();
    }
}

void write(long long x) {
    long long y = 10, len = 1;
    while (y <= x) {
        y *= 10;
        len++;
    }
    while (len--) {
        y /= 10;
        std::cout.put(x / y + 48);
        x %= y;
    }
}