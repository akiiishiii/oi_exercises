// 2576.cpp
#include <iostream>

int const Mod = 100000000;
int f[13][5000], chked[13], mked[5000];
int n, m, cnt;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1, tmp; j <= m; j++) {
            std::cin >> tmp;
            chked[i] <<= 1;
            chked[i] |= tmp;
        }
    }
    int const Maxn = (1 << m) - 1;
    for (int i = 0; i <= Maxn; i++)
		if (!(i & (i << 1)))
			mked[++cnt] = i;
    for (int i = 1; i <= cnt; i++) {
        if (mked[i] & (~chked[1]))
			continue;
        f[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= cnt; j++) {
            int x = mked[j];
            for (int z = 1; z <= cnt; z++) {
                int y = mked[z];
                if(x & y || x & (~chked[i]) || y & (~chked[i - 1]))
					continue;
                f[i][j] = (f[i][j] + f[i - 1][z]) % Mod;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= cnt; i++)
		ans = (ans + f[n][i]) % Mod;
    std::cout << ans << '\n';
	return 0;
}
