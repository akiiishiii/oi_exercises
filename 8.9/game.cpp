// game.cpp
#include <cstring>
#include <fstream>
#include <iostream>

#define debug

#ifndef debug

std::ifstream in("game.in");
std::ofstream out("game.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, m1, m2;
int dep[10005];
bool vis[10005];
int head[10005], Next[20005], ver[20005], tot;

void dfs(int x);
inline void add(int x, int y);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    int a, b, alice, bob, T;
    in >> T;
    while (T--) {
        memset(head, 0, sizeof head);
        memset(dep, 0, sizeof dep);
        memset(vis, false, sizeof vis);
        alice = bob = tot = 0;
        in >> n >> m1 >> m2;
        for (int i = 1; i < n; i++) {
            in >> a >> b;
            a++, b++;
            add(a, b), add(b, a);
        }
        dfs(1);
        for (int i = 1; i <= m1; i++) {
            in >> a;
            alice += dep[a + 1];
        }
        for (int i = 1; i <= m2; i++) {
            in >> b;
            bob += dep[b + 1];
        }
        if (alice <= bob)
            out << "Bob\n";
        else
            out << "Alice\n";
    }
    return 0;
}

void dfs(int x) {
    vis[x] = true;
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (!vis[y]) {
            dep[y] = dep[x] + 1;
            dfs(y);
        }
    }
}

inline void add(int x, int y) {
    ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}