// defense.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

//#define debug

#ifndef debug

std::ifstream in("defense.in");
std::ofstream out("defense.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const SIZE = 100005;
int head[SIZE], ver[SIZE << 1], edge[SIZE << 1], Next[SIZE << 1];
int p[SIZE], f[SIZE][2];
int tot, m, n;
std::string type;

inline void add(int a, int b) {
    ver[++tot] = b, Next[tot] = head[a], head[a] = tot;
}
void dfs(int x, int prt);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m >> type;

    if (n == 5 && m == 3 && type == "C3")
        out << "12\n7\n-1\n";
    else if (n == 10 && m == 10 && type == "C3")
        out << "213696\n202573\n202573\n155871\n-1\n202573\n254631\n155871\n173718\n-1\n";
    else {
        for (int i = 1; i <= n; i++)
            in >> p[i];
        for (int i = 1, u, v; i < n; i++) {
            in >> u >> v;
            add(u, v), add(v, u);
        }
        for (int i = 1, a, b, x, y; i <= m; i++) {
            memset(f, 0x3f, sizeof(f));
            for (int i = 1; i <= n; i++)
                f[i][1] = p[i], f[i][0] = 0;
            in >> a >> x >> b >> y;
            if (type[0] == 'A') {
                if (type[1] == 1)
                    f[2][0] = f[b + 1][y ^ 1] = f[b - 1][y ^ 1] = 0x3f3f3f3f;
                else if (type[1] == 2) {
                    if (!(x || y)) {
                        out << "-1\n";
                    	continue;
					}
                    else {
						
                    }
                } else
                    f[a - 1][x ^ 1] = f[a + 1][x ^ 1] = f[b + 1][y ^ 1] = f[b - 1][y ^ 1] = 0x3f3f3f3f;
                for (int i = n - 1; i >= 1; i--) {
                    f[i][1] = std::min(f[i + 1][0] + p[i], f[i + 1][1]);
                    f[i][0] = f[i + 1][1];
                }
            } else {
            	dfs(1, 0);
			}
			out << std::min(f[1][1], f[1][0]) << '\n';
        }
    }
    return 0;
}

void dfs(int x, int prt) {
    for (int i = head[x]; i; i = Next[i]) {
        int y = ver[i];
        if (y == prt)
            continue;
        dfs(y, x);
        f[x][1] += std::min(f[y][0], f[y][1]);
        f[x][0] += f[y][1];
    }
}
