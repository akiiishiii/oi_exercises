// 3580.cpp
#include <cstring>
#include <iostream>

int l, sa[200005], rk[200005], a[200005], fir[200005], sec[200005], sum[200005];
long long h[200005], ans = 0;
char s[200005];

int turn(char c);
void makesa(int m);
void geth();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin.getline(s, 200005);
    l = strlen(s);
    for (int i = 1; i <= l; i++)
        a[i] = int(s[i - 1]);
    makesa(500);
    geth();
    for (int i = 1; i <= l; i++)
        ans += l - sa[i] + 1 - h[i];
    std::cout << ans << '\n';
    return 0;
}

int turn(char c) {
    if (c <= 'Z')
        return c - 64;
    else
        return c - 96 + 26;
}

void makesa(int m) {
    int p, i, j, *x = rk, *y = sec;
    for (i = 0; i <= m; i++)
        sum[i] = 0;
    for (i = 1; i <= l; i++)
        x[i] = a[i], sum[x[i]]++;
    for (i = 1; i <= m; i++)
        sum[i] += sum[i - 1];
    for (i = l; i >= 1; i--)
        sa[sum[x[i]]--] = i;
    for (p = 1, j = 1; p < l; j *= 2, m = p) {
        for (p = 0, i = l - j + 1; i <= l; i++)
            y[++p] = i;
        for (i = 1; i <= l; i++)
            if (sa[i] - j > 0)
                y[++p] = sa[i] - j;
        for (i = 1; i <= l; i++)
            fir[i] = x[y[i]];
        for (i = 0; i <= m; i++)
            sum[i] = 0;
        for (i = 1; i <= l; i++)
            sum[fir[i]]++;
        for (i = 1; i <= m; i++)
            sum[i] += sum[i - 1];
        for (i = l; i >= 1; i--)
            sa[sum[fir[i]]--] = y[i];
        std::swap(x, y);
        x[sa[1]] = 1;
        for (p = 1, i = 2; i <= l; i++) {
            if ((y[sa[i - 1]] != y[sa[i]]) ||
                (y[sa[i - 1] + j] != y[sa[i] + j]))
                p++;
            x[sa[i]] = p;
        }
    }
    for (i = 1; i <= l; i++)
        rk[sa[i]] = i;
}

void geth() {
    int k = 0;
    for (int i = 1; i <= l; i++)
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