// rally.cpp
#include <fstream>
#include <iostream>

//#define debug

#ifndef debug

std::ifstream in("rally.in");
std::ofstream out("rally.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, m, k;
long long mat[401][401];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            in >> mat[i][j];
            mat[i][j] += mat[i][j - 1] + mat[i - 1][j] - mat[i - 1][j - 1];
        }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 1; k <= i; k++)
                for (int l = 1; l <= j; l++)
                    if ((mat[i][j] - mat[k - 1][j] - mat[i][l - 1] +
                         mat[k - 1][l - 1]) % k == 0)
                        ans++;
    out << ans << '\n';
    return 0;
}
