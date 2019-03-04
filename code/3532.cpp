// 3532.cpp
#include<iostream>

long long a, b, x, y;

long long exgcd(long long a, long long b, long long &x, long long &y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> a >> b;
    exgcd(a, b, x, y);
    std::cout << (x % b + b) % b << '\n';
}

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (!b) { x=1, y=0; return a; }
    long long d = exgcd(b, a%b, x, y);
    long long z = x; x = y; y = z - y*(a/b);
    return d;
}