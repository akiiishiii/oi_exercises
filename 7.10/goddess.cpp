// goddess.cpp
#include <iostream>
#include <fstream>
#include <cstring>

#define debug

#ifndef debug

std::ifstream in("goddess.in");
std::ofstream out("goddess.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

long long h[10010], f[10010][2][2], n, m;

int main(int argc, char const *argv[]) {
    std::ios_base::sync_with_stdio(false);
    in.tie(NULL);
    in >> n >> m;
    for (int i = 1; i <= n; i++)
    	in >> h[i];
    h[n + 1] = h[1];
    long long ans = 0x3f3f3f3f3f3f3f3fll, ans1 = 0ll;
    for (int i = 2; i <= n + 1; i++)
    	if (h[i] > h[i - 1])
    		ans1 += h[1] - h[i - 1];
    	else
    		ans1 += (h[1] - h[i - 1]) * (h[1] - h[i - 1]);
    ans = ans1;
	ans1 = 0;
	for (int i = 2; i <= n + 1; i++)
    	if (h[i] < h[i - 1])
    		ans1 += h[1] - h[i - 1];
    	else
    		ans1 += (h[1] - h[i - 1]) * (h[1] - h[i - 1]);
    ans = std::min(ans, ans1);
    memset(f, 0x3f, sizeof f);
    f[1][0][0] = f[1][0][1] = 0;
    for (int i = 2; i <= n + 1; i++)
    	for (int j = 0; j <= 1; j++)
    		if (h[i] > h[i - 1]) {
    			f[i][j][1] = std::min(f[i - 1][j ^ 1][0] + m + (h[i] - h[i - 1]) * (h[i] - h[i - 1]), f[i - 1][j][1] + (h[i] - h[i - 1]) * (h[i] - h[i - 1]));
    			f[i][j][0] = std::min(f[i - 1][j ^ 1][1] + m + (h[i] - h[i - 1]), f[i - 1][j][0] + (h[i] - h[i - 1]));
			} else {
				f[i][j][1] = std::min(f[i - 1][j ^ 1][0] + m + (h[i - 1] - h[i]), f[i - 1][j][1] + (h[i - 1] - h[i]));
    			f[i][j][0] = std::min(f[i - 1][j ^ 1][1] + m + (h[i - 1] - h[i]) * (h[i - 1] - h[i]), f[i - 1][j][0] + (h[i - 1] - h[i]) * (h[i - 1] - h[i]));
			}
	ans = std::min(ans, std::min(f[n + 1][1][1], f[n + 1][1][0]));
	memset(f, 0x3f, sizeof f);
    f[1][0][0] = 0;
    for (int i = 2; i <= n + 1; i++)
    	for (int j = 0; j <= 1; j++)
    		if (h[i] > h[i - 1]) {
    			f[i][j][0] = f[i - 1][j][0] + (h[i] - h[i - 1]);
    			if (j)
    				f[i][j][1] = std::min(f[i - 1][j][1], std::min(f[i - 1][j ^ 1][0], f[i - 1][j ^ 1][1]) + m) + (h[i] - h[i - 1]) * (h[i] - h[i - 1]);
    			else
    				f[i][j][1] = std::min(f[i - 1][j][1], std::min(f[i - 1][j ^ 1][0], f[i - 1][j ^ 1][1]) + m) + (h[i] - h[i - 1]);
			} else {
				f[i][j][0] = f[i - 1][j][0] + (h[i - 1] - h[i]) * (h[i - 1] - h[i]);
    			if (j)
    				f[i][j][1] = std::min(f[i - 1][j][1], std::min(f[i - 1][j ^ 1][0], f[i - 1][j ^ 1][1]) + m) + (h[i - 1] - h[i]);
    			else
    				f[i][j][1] = std::min(f[i - 1][j][1], std::min(f[i - 1][j ^ 1][0], f[i - 1][j ^ 1][1]) + m) + (h[i - 1] - h[i]) * (h[i - 1] - h[i]);
			}
	ans = std::min(ans, f[n + 1][0][1] - m);
	memset(f, 0x3f, sizeof f);
    f[1][0][0] = 0;
    for (int i = 2; i <= n + 1; i++)
    	for (int j = 0; j <= 1; j++)
    		if (h[i] > h[i - 1]) {
    			f[i][j][0] = f[i - 1][j][0] + (h[i] - h[i - 1]) * (h[i] - h[i - 1]);
    			if (j)
    				f[i][j][1] = std::min(f[i - 1][j][1], std::min(f[i - 1][j ^ 1][0], f[i - 1][j ^ 1][1]) + m) + (h[i] - h[i - 1]);
    			else
    				f[i][j][1] = std::min(f[i - 1][j][1], std::min(f[i - 1][j ^ 1][0], f[i - 1][j ^ 1][1]) + m) + (h[i] - h[i - 1]) * (h[i] - h[i - 1]);
			} else {
				f[i][j][0] = f[i - 1][j][0] + (h[i - 1] - h[i]);
    			if (j)
    				f[i][j][1] = std::min(f[i - 1][j][1], std::min(f[i - 1][j ^ 1][0], f[i - 1][j ^ 1][1]) + m) + (h[i - 1] - h[i]) * (h[i - 1] - h[i]);
    			else
    				f[i][j][1] = std::min(f[i - 1][j][1], std::min(f[i - 1][j ^ 1][0], f[i - 1][j ^ 1][1]) + m) + (h[i - 1] - h[i]);
			}
	ans = std::min(ans, f[n + 1][0][1] - m);
	out << ans << '\n';
    return 0;
}
