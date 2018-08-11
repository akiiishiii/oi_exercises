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
        int maxx = 1;
        for (int j = 0; j < i; j++)
            if (val[j] >= val[i])
                maxx = f[j] + 1 > maxx ? f[j] + 1 : maxx;
        f[i] = maxx;
    }
    for (int i = 1; i <= n; i++)
        ans = ans > f[i] ? ans : f[i];
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j <= cnt; j++) {
            if(ff[j] >= ff[i]) {
                ff[j] = val[i];
                break;
            }
        }
        if (ff[cnt] < val[i])
            ff[++cnt] = val[i];
    }
    std::cout << ans << '\n' << cnt << '\n';
    return 0;
}
