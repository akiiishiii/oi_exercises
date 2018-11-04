#include <algorithm>
#include <iostream>
using namespace std;
int t, k;
int a[2001][2001];
int ans[2001][2001];
int n[10001], m[10001];
int main() {
    int x = 0;
    scanf("%d%d", &t, &k);
    for (int i = 1; i <= t; i++) {
        scanf("%d%d", &n[i], &m[i]);
        if (n[i] > x)
            x = n[i]; //只要算出所询问的最大范围内的组合数即可，效率优化
    }
    for (int i = 1; i <= x; i++) {
        a[1][i] = i % k;
        if (a[1][i] == 0)
            ans[1][i]++;
    }
    for (int i = 2; i <= x; i++) //组合数递推过程
        for (int j = 2; j <= i; j++) {
            a[j][i] = (a[j - 1][i - 1] + a[j][i - 1]) % k;
            if (a[j][i] == 0)
                ans[j][i]++;
        }
    for (int i = 1; i <= x; i++) //二维前缀和递推过程
        for (int j = 1; j <= x; j++)
            ans[j][i] += ans[j - 1][i] + ans[j][i - 1] - ans[j - 1][i - 1];
    for (int i = 1; i <= t; i++)
        printf("%d\n", ans[min(n[i], m[i])][n[i]]);
}
