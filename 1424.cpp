// 1424.cpp
#include <queue>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>

int in = 0;
bool vis[51] = {false}, vis2[51] = {false};
std::vector<int> v[51], must, middle;

bool bfs(int mx);
void bfsv(int mx);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int k;
    while (true) {
        std::cin >> k;
        if (k == -1)
            break;
        while (k != -2) {
            v[in].push_back(k);
            std::cin >> k;
        }
        in++;
    }
    in--;
    for (int i = 1; i < in; i++) {
        memset(vis, false, sizeof vis);
        vis[i] = true;
        if (!bfs(0)) {
            must.push_back(i);
            memcpy(vis2, vis, sizeof vis);
            memset(vis, false, sizeof vis);
            vis2[i] = false;
            bfsv(i);
            for (int j = 0; j <= in; j++)
                if (vis[j] && vis2[j]) {
                    middle.push_back(i);
                    break;
                }
        }
    }
    std::cout << must.size() << ' ';
    for (auto &&it : must)
        std::cout << it << ' ';
    std::cout << '\n';
    std::cout << middle.size() << ' ';
    for (auto &&it : middle)
        std::cout << it << ' ';
    std::cout << '\n';
    return 0;
}

bool bfs(int mx) {
    bool res = false;
    std::queue<int> q;
    q.push(mx);
    vis[mx] = true;
    while(!q.empty()) {
        for (auto &&it : v[q.front()]) {
            if (!vis[it]) {
                if (it == 9)
                    res = true;
                q.push(it);
                vis[it] = true;
            }
        }
        q.pop();
    }
    return res;
}

void bfsv(int mx) {
    std::queue<int> q;
    q.push(mx);
    vis[mx] = true;
    while(!q.empty()) {
        for (auto &&it : v[q.front()]) {
            if (!vis[it]) {
                q.push(it);
                vis[it] = true;
            }
        }
        q.pop();
    }
}