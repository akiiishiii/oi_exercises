// 1228.cpp
#include <cstring>
#include <iostream>

int const Maxn = 105;
int c[Maxn][Maxn][Maxn], n, m;

inline int lowbit(int const x) { return x & (-x); }
void add(int x, int y, int z);
int sum(int x, int y, int z);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (std::cin >> n >> m) {
        memset(c, 0, sizeof(c));
        for (int i = 1, t, x1, x2, y1, y2, z1, z2; i <= m; i++) {
            std::cin >> t;
            if (t) {
                std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
                add(x1, y1, z1);
                add(x2 + 1, y1, z1);
                add(x1, y2 + 1, z1);
                add(x1, y1, z2 + 1);
                add(x2 + 1, y2 + 1, z1);
                add(x2 + 1, y1, z2 + 1);
                add(x1, y2 + 1, z2 + 1);
                add(x2 + 1, y2 + 1, z2 + 1);
            } else {
                std::cin >> x1 >> y1 >> z1;
                std::cout << (sum(x1, y1, z1) & 1) << '\n';
            }
        }
    }
    return 0;
}

void add(int x, int y, int z) {
    for (int i = x; i < Maxn; i += lowbit(i))
        for (int j = y; j < Maxn; j += lowbit(j))
            for (int k = z; k < Maxn; k += lowbit(k))
                c[i][j][k]++;
}

int sum(int x, int y, int z) {
    int ret = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        for (int j = y; j > 0; j -= lowbit(j))
            for (int k = z; k > 0; k -= lowbit(k))
                ret += c[i][j][k];
    return ret;
}