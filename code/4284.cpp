// 4284.cpp
#include <iostream>

int const Maxn = 205;
int n, na, nb, a[Maxn], b[Maxn], ansa, ansb;
int s[5][5] = {{0, 0, 1, 1, 0},
               {1, 0, 0, 1, 0},
               {0, 1, 0, 0, 1},
               {0, 0, 1, 0, 1},
               {1, 1, 0, 0, 0}};

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> na >> nb;
    for (int i = 0; i < na; i++)
        std::cin >> a[i];
    for (int i = 0; i < nb; i++)
        std::cin >> b[i];
    for (int i = 0; i < n; i++) {
        ansa += s[a[i % na]][b[i % nb]];
        ansb += s[b[i % nb]][a[i % na]];
    }
    std::cout << ansa << " " << ansb << '\n';
    return 0;
}