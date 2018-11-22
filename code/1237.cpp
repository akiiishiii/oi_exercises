// 1237.cpp
#include<iostream>

long long c[5005][5005];
int n, m;

inline int lowbit(int x) { return x & (-x); }
void add(int x, int y, int k);
long long sum(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int x, y, w, z, k, d;
    std::cin >> n >> m;
    while(std::cin >> d) {
        if(d == 1) {
            std::cin >> x >> y >> k;
            add(x, y, k);
        } else {
            std::cin >> w >> x >> y >> z;
            std::cout << sum(y, z) - sum(y, x - 1) - sum(w - 1, z) + sum(w - 1, x - 1) << "\n";
        }
    }
    return 0;
}

void add(int x, int y, int k) {
    for (int i = x; i <= n; i += lowbit(i))
        for (int j = y; j <= m; j += lowbit(j))
            c[i][j] += k;
}

long long sum(int x, int y) {
    long long ans = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        for (int j = y; j > 0; j -= lowbit(j))
            ans += c[i][j];
    return ans;
}