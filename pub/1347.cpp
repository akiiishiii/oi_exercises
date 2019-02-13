// 1347.cpp
#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
    std::vector<int> val, f;
    int n, ans = 1;
    std::cin >> n;
    val.resize(n + 1);
    f.resize(n + 1);
    for (int i = 1; i <= n; i++)
        std::cin >> val[i];
    for (int i = 1; i <= n; i++) {
        int maxx = 0;
        for (int j = 0; j < i; j++)
            if (val[j] <= val[i])
                maxx = f[j] + 1 > maxx ? f[j] + 1 : maxx;
        f[i] = maxx;
    }
    for (int i = 1; i <= n; i++)
        ans = ans > f[i] ? ans : f[i];
    std::cout << ans << '\n';
    return 0;
}
