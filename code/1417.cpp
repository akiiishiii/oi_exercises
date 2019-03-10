// 1417.cpp
#include <iostream>

int const Maxn = 510;
int n, a[Maxn][Maxn];

bool gauss();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1, x; i <= n; i++) {
        while (std::cin >> x) {
            if (x == -1)
                break;
            a[x][i] = 1;
        }
        a[i][n + 1] = 1;
    }
    if (gauss()) {
        for (int i = 1; i <= n; i++)
            if (a[i][n + 1])
                std::cout << i << ' ';
        return 0;
    }
    std::cout << "No solution\n";
    return 0;
}

bool gauss() {
    int pos = 1, i;
    for (int j = 1; j <= n; j++) {
        for (i = pos; i <= n; i++)
            if (a[i][j])
                break;
        if (i <= n) {
            if (pos != i)
                for (int k = 1; k <= n + 1; k++)
                    std::swap(a[pos][k], a[i][k]);
            for (i = 1; i <= n + 1; i++)
                if (pos != i && a[i][j])
                    for (int k = 1; k <= n + 1; k++)
                        a[i][k] ^= a[pos][k];
            pos++;
        }
    }
    for (i = pos; i <= n; i++)
        if (a[i][n + 1])
            return false;
    return true;
}