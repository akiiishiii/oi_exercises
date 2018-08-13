// 1348.cpp
#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> val, f, ff;
    int n, ans = 0, cnt = 0;
    std::cin >> n;
    val.resize(n + 1);
    f.resize(n + 1);
    ff.resize(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> val[i];
    for (int i = 1; i <= n; i++) {
        int maxx = 1, maxxx = 1;
        for (int j = 0; j < i; j++) {
            if (val[j] >= val[i])
                maxx = f[j] + 1 > maxx ? f[j] + 1 : maxx;
            if (val[j] < val[i])
                maxxx = ff[j] + 1 > maxxx ? ff[j] + 1 : maxxx;
        }
        f[i] = maxx;
        ff[i] = maxxx;
    }
    for (int i = 1; i <= n; i++) {
        ans = ans > f[i] ? ans : f[i];
        cnt = cnt > ff[i] ? cnt : ff[i];
    }
    std::cout << ans << '\n' << cnt << '\n';
    return 0;
}
