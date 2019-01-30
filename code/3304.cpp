// 3304.cpp
#include <iostream>
#include <string>

std::string ss, s;
int len, p[1000005], mx, id, ans, n, pp[1000005];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n >> ss;
    ans = len = 0;
    s += '*';
    for (int i = 0; i < n; i++)
        s += '#', s += ss[i];
    s += '#';
    len = s.length();
    mx = id = 0;
    for (int i = 1; i < len; i++) {
        if (mx > i)
            p[i] = std::min(p[id * 2 - i], mx - i);
        else
            p[i] = 1;
        while (s[i + p[i]] == s[i - p[i]])
            p[i]++;
        if (p[i] + i > mx)
            mx = p[i] + i, id = i;
    }
    for (int i = 1; i <= n; i++)
        pp[i] = (p[i * 2 + 1] - 1) / 2;
    for (int i = 1; i <= n; i++) {
        for (int j = pp[i] / 2; j >= 1 && j > ans; j--)
            if (pp[i - j] >= j && pp[i + j] >= j)
                ans = std::max(ans, j);
    }
    std::cout << ans * 4 << '\n';
    return 0;
}