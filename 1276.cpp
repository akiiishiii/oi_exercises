// 1276.cpp
#include <iostream>

int n, num[22] = {0};
void dfs(int cur, int sum);

int main(int argc, const char * argv[]) {
    std::cin >> n;
	dfs(1, 0);
    return 0;
}

void dfs(int cur, int sum) {
    if (sum > n)
        return;
    if (sum == n) {
        for (int i = 1; i < cur - 1; i++)
            std::cout << num[i] << '+';
        std::cout << num[cur - 1] << std::endl;
        return;
    }
    for (int i = 1; i < n; i++) {
        if (i >= num[cur - 1]) {
            num[cur] = i;
            dfs(cur + 1, sum + i);
            num[cur] = 0;
        }
    }
}