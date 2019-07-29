// POJ2248.cpp
#include <iostream>
#include <cstring>

int n, ans[100];
bool flag;

void dfs(int x, int depth);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (std::cin >> n && n) {
        memset(ans, 0, sizeof(ans));
        flag = false;
        ans[0] = 1;
        int tmp = n, depth = 0;
        while (tmp >>= 1)
            depth++;
        while (!flag)
            dfs(0, depth++);
        std::cout << ans[0];
        for (int i = 1; i < depth; i++)
            std::cout << " " << ans[i];
        std::cout << '\n';
    }
    return 0;
}

void dfs(int x, int depth) {
    if (flag)
        return;
    if (x == depth) {
        if(ans[x] == n)
            flag = 1;
        return;
    }
    for (int i = 0; i <= x; i++)
        for (int j = i; j <= x; j++)
            if (ans[i] + ans[j] > ans[x] && ans[i] + ans[j] <= n) {
                int sum = ans[i] + ans[j];
                for (int k = x + 2; k <= depth; k++)
                    sum <<= 1;
                if (sum < n)
                    continue;
                ans[x + 1] = ans[i] + ans[j];
                dfs(x + 1, depth);
                if (flag)
                    return;
            }
}
