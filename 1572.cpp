// 1572.cpp
#include <iostream>

int main(int argc, char const *argv[]) {
    for (int i = 1; i <= n; i++)
        if (!DFN[i])
            Tarjan(i);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (g[i][j] && Belong[i] != Belong[j])
                Rd[Belong[j]]++;
    for (int i = 1; i <= scc; i++)
        if (Rd[i] == 0)
            ans++;
    return 0;
}
