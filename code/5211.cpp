// 5211.cpp
#include <iostream>

long long p[1005];

bool insert(long long x);
long long get_max();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    long long s;
    std::cin >> n;
    for (int i = 1; i <= n; i++)
        std::cin >> s, insert(s);
    std::cout << get_max() << '\n';
    return 0;
}

bool insert(long long x) {
    for (int i = 62; i >= 0; i--)
        if (x >> i & 1) {
            if (p[i])
                x ^= p[i];
            else {
                p[i] = x;
                break;
            }
        }
    return x > 0;
}

long long get_max() {
    long long ret = 0;
    for (int i = 62; i >= 0; i--)
        if (ret < (ret ^ p[i]))
            ret ^= p[i];
    return ret;
}