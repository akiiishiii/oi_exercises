// game.cpp
#include <iostream>
#include <fstream>
#include <queue>
#include <cstring>
#include <algorithm>

std::ifstream in("game.in");
std::ofstream out("game.out");

void dfs(int k,int step);

int parent[10005][10005], vis[10005], n, m1, m2, maxn;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int a, b, alice, bob, t;
    in >> t;
    for (int times = 0; times < t; times++) {
        in >> n >> m1 >> m2;
        memset(parent, 0, sizeof(parent));
        for(int i = 1; i < n; i++) {
            in >> a >> b;
            parent[a][b] = 1;
            parent[b][a] = 1;
        }
        alice = bob = 0;
        for (int i = 1; i <= m1; i++) {
            in >> a;
            maxn=0x3F3F3F3F;
            memset(vis, 0, sizeof(vis));
            vis[a] = 1;
            dfs(a, 0);
            alice += maxn;
        }
        for (int i = 1; i <= m2; i++) {
            in >> b;
            maxn=0x3F3F3F3F;
            memset(vis, 0, sizeof(vis));
            vis[b] = 1;
            dfs(b, 0);
            bob += maxn;
        }
        if(alice <= bob)
            out << "Bob\n";
        else
            out << "Alice\n";
    }
    return 0;
}

void dfs(int k,int step) {
    if(!k) {
        if(step < maxn) {
            maxn = step;
            return;
        }
    }
    for(int j = 0; j < n; j++) {
        if(!vis[j] && parent[k][j] == 1) {
            vis[j] = 1;
            dfs(j, step + 1);
            vis[j] = 0;
        }
    }
}