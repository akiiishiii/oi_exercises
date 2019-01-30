// 5209.cpp
#include <iostream>
#include <cstring>

int const Maxn = 1000005;
int n, rk[Maxn], sec[Maxn], sa[Maxn], sm[Maxn], h[Maxn], a[Maxn];
char s[Maxn];

void makesa(int m);
void geth();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> (s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i++)
        a[i] = s[i] - 96;
    makesa(26);
    geth();
    for (int i = 1; i <= n; i++)
        std::cout << sa[i] << ' ';
    std::cout.put('\n');
    for (int i = 2; i <= n; i++)
        std::cout << h[i] << ' ';
    std::cout.put('\n');
    return 0;
}

void makesa(int m) {
    int *x = rk, *y = sec;
    for (int i = 0; i <= m; i++)
        sm[i] = 0;
    for (int i = 1; i <= n; i++)
        sm[x[i] = a[i]]++;
    for (int i = 1; i <= m; i++)
        sm[i] += sm[i - 1];
    for (int i = n; i >= 1; i--)
        sa[sm[x[i]]--] = i;
    for (int j = 1, p = 0; p < n; j *= 2, m = p) {
        p = 0;
        for (int i = n - j + 1; i <= n; i++)
            y[++p] = i;
        for (int i = 1; i <= n; i++)
            if (sa[i] - j > 0)
                y[++p] = sa[i] - j;
        for (int i = 0; i <= m; i++)
            sm[i] = 0;
        for (int i = 1; i <= n; i++)
            sm[x[i]]++;
        for (int i = 1; i <= m; i++)
            sm[i] += sm[i - 1];
        for (int i = n; i >= 1; i--)
            sa[sm[x[y[i]]]--] = y[i];
        std::swap(x, y);
        x[sa[1]] = 1;
        p = 1;
        for (int i = 2; i <= n; i++) {
            if (y[sa[i - 1]] != y[sa[i]] || y[sa[i - 1] + j] != y[sa[i] + j])
                p++;
            x[sa[i]] = p;
        }
    }
    for (int i = 1; i <= n; i++)
        rk[sa[i]] = i;
}

void geth() {
    int k = 0;
    for (int i = 1; i <= n; i++)
        if (rk[i] == 1)
            h[rk[i]] = 0;
        else {
            int j = sa[rk[i] - 1];
            while (a[i + k] == a[j + k])
                k++;
            h[rk[i]] = k;
            if (k > 0)
                k--;
        }
}