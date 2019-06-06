// 1346.cpp
#include <iostream>
#include <stack>

int n, k;
int num[25];
bool vis[25];

bool check(int *num);
void dfs(int pos);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    k = 0;
    dfs(1);
    return 0;
}

bool check(int *num) {
    int i, j;
    std::stack<int> s;
    for (i = 1, j = 1; i <= n;) {
        if (i == num[j]) {
            i++, j++;
        } else if (s.empty() || s.top() != num[j]) {
            s.push(i);
            i++;
        } else if (s.top() == num[j]) {
            s.pop();
            j++;
        }
    }
    while (!s.empty()) {
        if (s.top() == num[j]) {
            s.pop();
            j++;
        } else
            return false;
    }
    return true;
}

void dfs(int pos) {
    if (k == 20)
        return;
    if (pos == n + 1) {
        if (check(num)) {
            k++;
            for (int i = 1; i <= n; i++)
                std::cout << num[i];
            std::cout << '\n';
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            vis[i] = true;
            num[pos] = i;
            dfs(pos + 1);
            vis[i] = false;
            num[pos] = 0;
        }
    }
}