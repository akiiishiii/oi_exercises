// sequence.cpp
#include <fstream>
#include <iostream>

#define debug

#ifndef debug

std::ifstream in("sequence.in");
std::ofstream out("sequence.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int const Maxn = 1000005;
int n, p, tot;
int pri[Maxn], cnt[2 * Maxn], num[2 * Maxn];
bool vis[2 * Maxn];

void getp();
void edit(int x, int dlt);
long long catalan(int n);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> p;
    getp();
    out << catalan(n) << '\n';
    return 0;
}

void getp() {
    for (int i = 2; i <= 2 * n; i++) {
        if (!vis[i])
            pri[++tot] = i, cnt[i] = tot;
        for (int j = 1; pri[j] * i <= 2 * n && j <= tot; j++) {
            vis[pri[j] * i] = 1;
            cnt[pri[j] * i] = j;
            if (i % pri[j] == 0)
                break;
        }
    }
}

void edit(int x, int dlt) {
    while (x != 1) {
        num[cnt[x]] += dlt;
        x /= pri[cnt[x]];
    }
}

long long catalan(int n) {
    long long ret = 1;
    for (int i = 2 * n; i > n; i--)
        edit(i, 1);
    for (int i = 1; i <= n; i++)
        edit(i, -1);
    edit(n + 1, -1);
    for (int i = 1; i <= tot; i++)
        while (num[i]--)
            ret = (ret * pri[i]) % p;
    return ret;
}