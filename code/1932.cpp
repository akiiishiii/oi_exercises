// 1932.cpp
#include <iostream>
#include <string>

int a[150][150], ap[150], ans[150], deg[150];
int n, cnt = 0, d = 123;
bool esc = false;
std::string s;

void dfs(int v, int d);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> s;
        ap[int(s[0])] = ap[int(s[1])] = 1;
        a[int(s[0])][int(s[1])] = a[int(s[1])][int(s[0])] = 1;
        deg[int(s[0])]++, deg[int(s[1])]++;
        if (s[0] < d)
            d = s[0];
        if (s[1] < d)
            d = s[1];
    }
    for (int i = 'z'; i >= 'A'; i--)
        if (ap[i] && deg[i] % 2)
            cnt++, d = i;
    if (!cnt || cnt == 2)
        ans[1] = d, dfs(d, 2);
    else
        std::cout << "No Solution\n";
    return 0;
}

void dfs(int v, int d) {
    if (d == n + 2) {
        for (int i = 1; i <= n + 1; i++)
            std::cout << char(ans[i]);
        esc = true;
        return;
    }
    for (int i = 'A'; i <= 'z'; i++)
        if (ap[i] && a[v][i]) {
            a[v][i] = a[i][v] = 0;
            ans[d] = i;
            dfs(i, d + 1);
            if (esc)
                return;
            a[v][i] = a[i][v] = 1;
        }
}