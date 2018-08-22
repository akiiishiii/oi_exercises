#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

int n = 0, x, vis1[51] = {0}, vis2[51] = {0};
std::vector<int> g[51], ans1, ans2;

void dfs1(int i);
void dfs2(int i);

int main(int argc, char const *argv[]) {
    while (true) {
        std::cin >> x;
        if (x == -1)
            break;
        else if (x == -2)
            n++;
        else {
            g[n].push_back(x);
        }
    }
    n--;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i < n; i++) {
        memset(vis1, 0, sizeof(vis1));
        vis1[i] = 1;
        dfs1(0);
        if (!vis1[n]) {
            cnt1++;
            ans1.push_back(i);
        }
        memset(vis2, 0, sizeof(vis2));
        dfs2(i);
        int ok = 1;
        for (int j = 0; j <= n; j++)
            if (vis1[j] == 1 && vis2[j] == 1 && j != i) {
                ok = 0;
                break;
            }
        if (ok == 1) {
            cnt2++;
            ans2.push_back(i);
        }
    }
    std::cout << cnt1 << ' ';
    for (int k = 0; k < ans1.size(); k++)
        std::cout << ans1[k] << ' ';
    std::cout << '\n';
    std::cout << cnt2 << ' ';
    for (int k = 0; k < ans2.size(); k++)
        std::cout << ans2[k] << ' ';
    std::cout << '\n';
    return 0;
}

void dfs1(int i) {
    vis1[i] = 1;
    for (int k = 0; k < g[i].size(); k++) {
        int j = g[i][k];
        if (vis1[j])
            continue;
        dfs1(j);
    }
}

void dfs2(int i) {
    vis2[i] = 1;
    for (int k = 0; k < g[i].size(); k++) {
        int j = g[i][k];
        if (vis2[j])
            continue;
        dfs2(j);
    }
}