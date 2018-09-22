// 1402.cpp
#include <iostream>
#include <cstring>

int n, k, num = 0;
long long s[1005] = {0}, c[1005] = {0}, f[20][1005][200], ans = 0;

void dfs(int d, int cnt, int tot);

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> k;
	memset(f, 0, sizeof(f));
	dfs(0, 0, 0);
    f[0][1][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= num; j++)
            for (int nk = 0; nk <= k; nk++)
                if (nk >= c[j])
                    for (int t = 1; t <= num; t++)
                        if (!(s[t] & s[j]) && !(s[t] & (s[j] << 1)) && !(s[t] & (s[j] >> 1)))
                            f[i][j][nk] += f[i -1][t][nk - c[j]];
    for (int i = 1; i <= num; i++)
        ans += f[n][i][k];
    std::cout << ans << '\n';
    return 0;
}

void dfs(int d, int cnt, int tot) {
    if (d == n) {
	    s[++num] = cnt;
		c[num] = tot;
		return;
	}
    dfs(d + 1, cnt << 1, tot);
    if (!(cnt & 1))
	    dfs(d + 1, (cnt << 1) | 1, tot + 1);
}

