// 1256copy.c
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int front = 0;
int back = 2010;
int mid = 1005;
long long ans = -1;
long long n, d, k;
long long f[500010], x[500010], s[500010];

int max(int a, int b) { return a > b ? a : b;}

bool check(int g)
{
    long long l = d - g;
    long long r = d + g;
    if (l <= 0)
        l = 1;
    memset(f, -128, sizeof(f));
    f[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = i - 1; j >= 0; j--)
        {
            if (x[i] - x[j] < l)
                continue;
            if (x[i] - x[j] > r)
                break;
            f[i] = max(f[i], f[j] + s[i]);
            if (f[i] >= k)
                return 1;
        }
    return 0;
}

int main(void)
{
    scanf("%lld%lld%lld", &n, &d, &k);
    for (int i = 1; i <= n; i++)
        scanf("%lld%lld", &x[i], &s[i]);
    while (front <= back)
    {
        if (check(mid))
            ans = mid, back = mid - 1;
        if (!check(mid))
            front = mid + 1;
        mid = (front + back) >> 1;
    }
    printf("%lld\n", ans);
    return 0;
}