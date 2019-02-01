// 4027.cpp
#include <algorithm>
#include <iostream>

int const Maxn = 250005, Maxw = 30;
int ch[Maxn * 2][Maxw], len[Maxn * 2], prt[Maxn * 2];
int cnt = 0, last, root, n, x, ans[Maxn * 2], sum[Maxn * 2], f[Maxn * 2];
std::string s;

bool cmp(int const &x, int const &y) { return len[x] > len[y]; }
int new_node(int n);
void insert(int w);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    last = root = new_node(0);
    std::cin >> s;
    for (int i = 0; i < s.length(); i++)
        insert(s[i] - 96);
    for (int i = 1; i <= cnt; i++)
        f[i] = i;
    std::sort(f + 1, f + cnt + 1, cmp);
    int n = root;
    for (int i = 0; i < s.length(); i++) {
        n = ch[n][s[i] - 96];
        sum[n]++;
    }
    for (int i = 1; i <= cnt; i++) {
        ans[len[f[i]]] = std::max(ans[len[f[i]]], sum[f[i]]);
        if (prt[f[i]])
            sum[prt[f[i]]] += sum[f[i]];
    }
    for (int i = s.length() - 1; i >= 1; i--)
        ans[i] = std::max(ans[i], ans[i + 1]);
    for (int i = 1; i <= s.length(); i++)
        std::cout << ans[i] << '\n';
    return 0;
}

int new_node(int n) {
    len[++cnt] = n;
    return cnt;
}

void insert(int w) {
    int p = last, u = new_node(len[p] + 1);
    for (; p && !ch[p][w]; p = prt[p])
        ch[p][w] = u;
    if (!p)
        prt[u] = root;
    else {
        int o = ch[p][w];
        if (len[o] == len[p] + 1)
            prt[u] = o;
        else {
            int n = new_node(len[p] + 1);
            std::copy(ch[o], ch[o] + Maxw, ch[n]);
            prt[n] = prt[o];
            prt[u] = prt[o] = n;
            for (; p && ch[p][w] == o; p = prt[p])
                ch[p][w] = n;
        }
    }
    last = u;
}