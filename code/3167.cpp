// 3167.cpp
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

std::string s1, s2;
int l, a[200005], fir[200005], sec[200005], rank[200005], sa[200005],
    height[200005], sum[200005];
int ans = 0, oldl;

void makesa(int m);
void geth();

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cin >> s1 >> s2;
    oldl = s1.length();
    s1 += '{' + s2;
    l = s1.length();
    for (int i = 1; i <= l; i++)
        a[i] = s1[i - 1] - 96;
    makesa(27);
    ans = 0;
    geth();
    std::cout << ans << '\n';
    return 0;
}

void makesa(int m) {
    int p, i, j, *x = rank, *y = sec;
    for (i = 0; i <= m; i++)
        sum[i] = 0;
    for (i = 1; i <= l; i++)
        x[i] = a[i], sum[a[i]]++;
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
        rank[sa[i]] = i;
}

void geth() {
    int k = 0;
    for (int i = 1; i <= l; i++)
        if (rank[i] == 1)
            height[1] = 0;
        else {
            int j = sa[rank[i] - 1], J = sa[rank[i]];
            while (a[i + k] == a[j + k])
                k++;
            height[rank[i]] = k;
            if (j > J)
                std::swap(j, J);
            if (j <= oldl && J > oldl + 1)
                ans = std::max(ans, k);
            if (k)
                k--;
        }
}