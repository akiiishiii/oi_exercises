// 1479.cpp
#include <iostream>
#include <algorithm>

int n, m, ans, f[1<<10][1<<10][3], a[105], cnt[1<<10];

int getsum(int num);

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
        	char x;
            std::cin >> x;
			a[i] <<= 1;
			a[i] += x == 'H' ? 1 : 0;
        }
    for (int i = 0; i < (1 << m); i++)
        cnt[i] = getsum(i);
    for (int j = 0; j < (1 << m); j++)
        if (!(j & a[0] || (j & (j << 1)) || (j & (j << 2))))
            f[0][j][0] = cnt[j];
    for (int k = 0; k < (1 << m); k++)
        for (int j = 0; j < (1 << m); j++)
            if (!(k & j || k & a[0] || j & a[1] || (k & (k << 1)) || (k & (k << 2)) || (j & (j << 1)) || (j & (j << 2))))
                f[k][j][1] = cnt[j] + cnt[k];
    for (int i = 2; i < n; i++)
        for (int k = 0; k < (1 << m); k++) {
            if (k & a[i-1] || (k & (k << 1)) || (k & (k << 2)))
				continue;
            for (int j = 0; j < (1 << m); j++) {
                if (j & a[i] || k & j || (j & (j << 1)) || (j & (j << 2)))
					continue;
                for (int tmp = 0; tmp < (1 << m); tmp++) {
                    if (tmp & k || tmp & j || tmp & a[i-2] || (tmp & (tmp << 1)) || (tmp & (tmp << 2)))
						continue;
                    f[k][j][i % 3] = std::max(f[k][j][i % 3], f[tmp][k][(i - 1) % 3] + cnt[j]);
                }
            }
        }
    for (int k = 0; k < (1 << m); k++)
        for (int j = 0; j < (1 << m); j++)
            ans = std::max(ans, f[k][j][(n - 1) % 3]);
    std::cout << ans << '\n';
	return 0;
}

int getsum(int num) {
    int tot = 0;
    while (num) {
		if(num & 1)
			tot++;
		num >>= 1;
	}
    return tot;
}
