// 1057.cpp
#include <iostream>
#include <cstring>

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, s, t;
    int l[4] = {0}, c[4] = {0};
    int f[101], d[101] = {0};
    memset(f, 0x3f, sizeof f);
    std::cin >> l[1] >> l[2] >> l[3]
             >> c[1] >> c[2] >> c[3]
             >> n    >> s    >> t;
    if (s > t)
        std::swap(s, t);
    for (int i = 2; i <= n; i++)
        std::cin >> d[i];
    f[s] = 0;
    for (int i = s + 1; i <= t; i++)
        for (int j = s; j < i; j++)
            for (int k = 1; k <= 3; k++)
                if (d[i] - d[j] > l[k - 1] && d[i] - d[j] <= l[k])
                    f[i] = std::min(f[i], f[j] + c[k]);
    std::cout << f[t] << '\n';
    return 0;
}
