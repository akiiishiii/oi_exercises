// 2282.cpp
#include <algorithm>
#include <iostream>

struct citizen {
    int b, e, t;
    int now = 0;
    bool operator<(citizen const &c) const { return e < c.e; }
} c[5001];

bool mark[30001] = {false};
int n, m, cnt = 0;

void set(int mx, int mi);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++)
        std::cin >> c[i].b >> c[i].e >> c[i].t;
    std::sort(c + 1, c + m + 1);
    for (int i = 1; i <= m; i++)
        for (int k = c[i].e; k >= c[i].b && c[i].now < c[i].t; k--)
            if (!mark[k])
                set(k, i);
    std::cout << cnt << '\n';
    return 0;
}

void set(int mx, int mi) {
    bool flag = true;
    for (int i = mi; i <= m; i++)
        if (mx >= c[i].b && mx <= c[i].e) {
            if (flag) {
                mark[mx] = true, cnt++;
                flag = false;
            }
            c[i].now++;
        }
}