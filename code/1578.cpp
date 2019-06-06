// 1578.cpp
#include <iostream>
#include <queue>

std::deque<int> q[1010], p;
int c[1000010], n;
char s[10];

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x, t = 0;
    while (std::cin >> n && n) {
        p.clear();
        for (int i = 1; i <= n; i++)
            q[i].clear();
        for (int i = 1, m; i <= n; i++) {
            std::cin >> m;
            for (int j = 1; j <= m; j++)
                std::cin >> x, c[x] = i;
        }
        std::cout << "Scenario #" << ++t << '\n';
        while (std::cin >> s && s[0] != 'S')
            if (s[0] == 'E') {
                std::cin >> x;
                if (!q[c[x]].size())
                    p.push_back(c[x]);
                q[c[x]].push_back(x);
            } else {
                x = p.front();
                std::cout << q[x].front() << '\n';
                q[x].pop_front();
                if (!q[x].size())
                    p.pop_front();
            }
        std::cout << '\n';
    }
    return 0;
}