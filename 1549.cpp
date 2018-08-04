// 1549.cpp
#include <iostream>

int wid[105] = {0}, dep = 0, prt[105] = {0}, n;

void dfs(int root,int k);

int main(int argc, char const * argv[]) {
    int root = 0, ans = 0;
    std::cin >> n;
    for (int i = 1, x, y; i < n; i++) {
        std::cin >> x >> y;
        prt[x] = y;
    }
    for (int i = 1; i <= n; i++)
        if (!prt[i]) {
            root = i;
            break;
        }
    wid[1] = 1;
    dfs(root, 1);
    for(int i = 1; i <= dep; i++)
        ans=wid[i] > ans ? wid[i] : ans;
    std::cout << dep << " " << ans << '\n';
    return 0;
}

void dfs(int root,int k) {
    dep = dep > k ? dep : k;
    for(int i=1;i<=n;i++)
        if(prt[i] == root) {
            wid[k + 1]++;
            dfs(i, k + 1);
        }
}
