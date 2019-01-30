// 3579.cpp
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

char s[400005];
int l, sa[400005], rk[400005], a[400005], fir[400005], sec[400005], sum[400005],
    h[400005];
int rmq[400005][20], ans = 0, pos;

int turn(char c);
void makesa(int m);
void geth();
void st(int n);
int lcp(int l, int r);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> s;
    l = strlen(s);
    for (int i = 1; i <= l; i++)
        a[i] = turn(s[i - 1]);
    a[l + 1] = 53;
    for (int i = 1; i <= l; i++)
        a[l * 2 - i + 2] = a[i];
    l = l * 2 + 1;
    makesa(53);
    geth();
    st(l);
    for (int i = 1; i <= l / 2; i++) {
        int k = lcp(rk[i], rk[l - i + 1]);
        if (k * 2 - 1 > ans)
            ans = k * 2 - 1, pos = i - k;
        k = lcp(rk[i], rk[l - i]);
        if (k * 2 - 2 > ans)
            ans = k * 2 - 2, pos = i - k + 1;
    }
    for (int i = pos; i <= pos + ans - 1; i++)
        std::cout << s[i];
    std::cout << '\n';
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

void st(int n) {
    for (int i = 1; i <= n; i++)
        rmq[i][0] = h[i];
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++)
            rmq[i][j] = std::min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
}

int lcp(int l, int r) {
    if (l > r)
        std::swap(l, r);
    l++;
    int x = (int)log2(r - l + 1);
    return std::min(rmq[l][x], rmq[r - (1 << x) + 1][x]);
}