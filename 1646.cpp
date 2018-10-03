// 1646.cpp
#include<iostream>

long long X,Y;

long long exgcd(long long a, long long b);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long x, y, m, n, L;
    while (std::cin >> x >> y >> m >> n >> L) {
        long long d = exgcd(n - m, L);
        long long r = L / d;
        if ((x - y) % d)
            std::cout << "Impossible\n";
        else
            std::cout << ((x - y) / d * X % r + r) % r << '\n';
    }
    return 0;
}

long long exgcd(long long a, long long b) {
    if(!b) {
        X = 1, Y = 0;
        return a;
    }
    long long d = exgcd(b, a % b);
    long long t = X - a / b * Y;
    X = Y;
    Y = t;
    return d;
}
