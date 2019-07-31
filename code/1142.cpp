// 1142.cpp
#include <algorithm>
#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

int const Inf = 19931117, Maxn = 1000010;
int prt[Maxn], n;
int indeg[Maxn], p[Maxn], f[Maxn][2];
int head[Maxn], ver[Maxn], Next[Maxn], tot;
std::vector<std::pair<int, int>> elm;
int q[Maxn], l, r;

int search(int a) { return prt[a] == a ? a : (prt[a] = search(prt[a])); }

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> n;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= n; i++)
        prt[i] = i;
    for (int i = 1, x; i <= n; i++) {
        std::cin >> x;
        if (search(i) != search(x)) {
            p[i] = x, prt[search(i)] = search(x), ++indeg[x];
            ver[tot] = i, Next[tot] = head[x];
            head[x] = tot++;
        } else
            p[i] = -1, elm.push_back(std::make_pair(i, x));
    }
    for (int i = 1; i <= n; i++)
        if (!indeg[i])
            q[r++] = i;
    while (l != r) {
        int c = q[l++];
        if (head[c] == -1)
            f[c][0] = 0, f[c][1] = -Inf;
        else {
            f[c][0] = 0, f[c][1] = 1;
            bool zr = false;
            for (int x = head[c]; x != -1; x = Next[x]) {
                int y = ver[x], rr = std::max(f[y][0], f[y][1]);
                if (f[y][0] == rr)
                    zr = true;
                f[c][0] += rr, f[c][1] += rr;
            }
            if (!zr) {
                int dlt = Inf;
                for (int x = head[c]; x != -1; x = Next[x]) {
                    int y = ver[x];
                    dlt = std::min(dlt, f[y][1] - f[y][0]);
                }
                f[c][1] -= dlt;
            }
        }
        if (p[c] != -1) {
            --indeg[p[c]];
            if (!indeg[p[c]])
                q[r++] = p[c];
        }
    }
    int ans = 0;
    for (std::vector<std::pair<int, int>>::iterator it = elm.begin();
         it != elm.end(); ++it) {
        int x = it->first, y = it->second;
        int tmp = f[x][1], sum = 0;
        for (int p = head[y]; p != -1; p = Next[p])
            sum += f[ver[p]][1];
        if (f[y][1] < sum + 1) {
            f[y][1] = sum + 1;
            int py = p[y];
            while (py != -1) {
                int t0 = f[py][0], t1 = f[py][1];
                if (head[py] == -1)
                    f[py][0] = 0, f[py][1] = -Inf;
                else {
                    f[py][0] = 0, f[py][1] = 1;
                    bool zr = false;
                    for (int p = head[py]; p != -1; p = Next[p]) {
                        int t = ver[p], rr = std::max(f[t][0], f[t][1]);
                        if (f[t][0] == rr)
                            zr = true;
                        f[py][0] += rr, f[py][1] += rr;
                    }
                    if (!zr) {
                        int dlt = Inf;
                        for (int p = head[py]; p != -1; p = Next[p]) {
                            int t = ver[p];
                            dlt = std::min(dlt, f[t][1] - f[t][0]);
                        }
                        f[py][1] -= dlt;
                    }
                }
                if (t0 == f[py][0] && t1 == f[py][1])
                    break;
                else
                    py = p[py];
            }
        }
        tmp = std::max(tmp, f[x][0]), ans += tmp;
    }
    std::cout << ans << '\n';
    return 0;
}