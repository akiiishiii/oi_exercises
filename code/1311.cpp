// 1311.cpp
#include <cstring>
#include <iostream>
#include <vector>

int n, c[1000010];
std::vector<int> a, b;

int ask(int x);
void add(int x);
long long calc(std::vector<int> a);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x;
    while (std::cin >> n) {
        a.clear(), b.clear();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                std::cin >> x;
                if (x)
                    a.push_back(x);
            }
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++) {
                std::cin >> x;
                if (x)
                    b.push_back(x);
            }
        std::cout << (calc(a) - calc(b) & 1 ? "NIE" : "TAK") << '\n';
    }
    return 0;
}

int ask(int x) {
    int ret = 0;
    for (; x; x -= x & -x)
        ret += c[x];
    return ret;
}

void add(int x) {
    for (; x <= n * n - 1; x += x & -x)
        c[x]++;
}

long long calc(std::vector<int> a) {
    long long ans = 0;
    memset(c, 0, sizeof(c));
    for (int i = a.size() - 1; i >= 0; i--) {
        ans += ask(a[i]);
        add(a[i]);
    }
    return ans;
}