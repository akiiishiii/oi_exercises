// 3584.cpp
#include <iostream>
#include <cstring>

int const Maxn = 200005;
int n, a[Maxn], rk[Maxn], sec[Maxn], sa[Maxn], sm[Maxn], h[Maxn];
int k, len1, len2, top;
long long tot, ans = 0;
char s1[Maxn], s2[Maxn];

struct node {
    int num, hei;
} sta[Maxn];

void makesa(int m);
void geth();
int turn(char c);

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> k >> (s1 + 1) >> (s2 + 1);
    len1 = strlen(s1 + 1), len2 = strlen(s2 + 1);
    for (int i = 1; i <= len1; i++)
        a[i] = turn(s1[i]);
    a[len1 + 1] = 53;
    for (int i = 1; i <= len2; i++)
        a[len1 + 1 + i] = turn(s2[i]);
    n = len1 + len2 + 1;
    makesa(53);
    geth();
    top = tot = 0;
    for (int i = 1; i <= n; i++) {
        if (h[i] < k)
            top = tot = 0;
        else {
            int cnt = 0;
            if (sa[i - 1] <= len1)
                cnt++, tot += h[i] - k + 1;
            while (top && h[i] <= sta[top].hei) {
                tot -= sta[top].num * (sta[top].hei - h[i]);
                cnt += sta[top--].num;
            }
            sta[++top].hei = h[i];
            sta[top].num = cnt;
            if (sa[i] >= len1 + 2)
                ans += tot;
        }
    }
    top = tot = 0;
    for (int i = 1; i <= n; i++) {
        if (h[i] < k)
            top = tot = 0;
        else {
            int cnt = 0;
            if (sa[i - 1] >= len1 + 2)
                cnt++, tot += h[i] - k + 1;
            while (top && h[i] <= sta[top].hei) {
                tot -= sta[top].num * (sta[top].hei - h[i]);
                cnt += sta[top--].num;
            }
            sta[++top].hei = h[i];
            sta[top].num = cnt;
            if (sa[i] <= len1)
                ans += tot;
        }
    }
    std::cout << ans << '\n';
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

int turn(char c) {
    if (c <= 'Z')
        return c - 64;
    else
        return c - 70;
}