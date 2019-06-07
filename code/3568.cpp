// 3568.cpp
#include <iostream>
#include <string>

int l[100002], r[100002];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, x, y;
    std::string s;
    std::cin >> n >> m;
    for (int i = 0; i <= n + 1; i++)
        l[i] = i - 1, r[i] = i + 1;
    for (int i = 1; i <= m; i++) {
        std::cin >> s >> x >> y;
        if (s[0] == 'A') {
            r[l[x]] = r[x];
            l[r[x]] = l[x];
            r[x] = y;
            l[x] = l[y];
            r[l[y]] = x;
            l[y] = x;
        } else {
            r[l[x]] = r[x];
            l[r[x]] = l[x];
            l[x] = y;
            r[x] = r[y];
            l[r[y]] = x;
            r[y] = x;
        }
    }
    for (int i = 1, j = 0; i <= n; i++, j = r[j])
        std::cout << r[j] << '\n';
    return 0;
}