// 2724.cpp
#include <iostream>

int const Maxm = 10005, Maxn = 1000005;
int prt[Maxm];
bool vst[Maxn];

int search(int x) { return x == prt[x] ? x : prt[x] = search(prt[x]); }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    std::cin >> n;
    for (int i = 1; i <= 10001; i++)
        prt[i] = i;
    for (int i = 1, x, y; i <= n; i++) {
        std::cin >> x >> y;
        x = search(x), y = search(y);
        if (x == y)
            vst[x] = true;
        else {
            if (x > y)
                std::swap(x, y);
            prt[x] = y;
            if (!vst[x])
                vst[x] = true;
            else
                vst[y] = true;
        }
    }
    for (int i = 1; i <= 10001; i++)
        if (!vst[i]) {
            std::cout << i - 1 << '\n';
            break;
        }
    return 0;
}