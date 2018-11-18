// 1211.cpp
#include <iostream>

int n, c[1100][1100];

template <typename T>
inline T lowbit(T const &x) { return x & (-x); }
void add(int x, int y, int k);
int sum(int x, int y);
int search(int x1, int y1, int x2, int y2) { return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1); }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (true) {
        int t, x1, y1;
        std::cin >> t;
        switch (t) {
        case 0:
            std::cin >> n;
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    c[i][j] = 0;
            break;
        case 1:
            int k;
            std::cin >> x1 >> y1 >> k;
            add(x1 + 1, y1 + 1, k);
            break;
        case 2:
            int x2, y2;
            std::cin >> x1 >> y1 >> x2 >> y2;
            std::cout << search(x1 + 1, y1 + 1, x2 + 1, y2 + 1) << '\n';
            break;
        case 3:
            return 0;
        default:
            break;
        }
    }
    return 0;
}

void add(int x, int y, int k) {
    for (int i = x; i <= n; i = i + lowbit(i))
        for (int j = y; j <= n; j = j + lowbit(j))
            c[i][j] += k;
}

int sum(int x, int y) {
    int ret = 0;
    for (int i = x; i > 0; i = i - lowbit(i))
        for (int j = y; j > 0; j = j - lowbit(j))
            ret += c[i][j];
    return ret;
}