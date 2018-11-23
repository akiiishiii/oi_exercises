// 1234.cpp
#include <iostream>
#include <string>

int const Maxn = 20005;
int c[200005];

inline int lowbit(int const x) { return x & (-x); }
void add(int x, int d);
int sum(int x);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x, d;
    std::string s;
    while (std::cin >> s) {
        if (s == "ADD" || s == "REMOVE")
            std::cin >> x, add(x, x);
        else if (s == "XOR") {
            std::cin >> s >> x >> s >> d;
            std::cout << ((x > d) ? 0 : (sum(x - 1) ^ sum(d))) << '\n';
        }
    }
    return 0;
}

void add(int x, int d) {
    for (int i = x; i <= Maxn; i += lowbit(i))
        c[i] ^= d;
    return;
}

int sum(int x) {
    int ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        ans ^= c[i];
    return ans;
}