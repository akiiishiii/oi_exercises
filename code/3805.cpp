// 3805.cpp
#include <iostream>
#include <functional>
#include <algorithm>

int c[20], cab[20], n, w, ans;

void dfs(int now, int cnt);

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n >> w;
	for (int i = 1; i <= n; i++)
		std::cin >> c[i];
	std::sort(c + 1, c + n + 1, std::greater<int>());
	ans = n;
	dfs(1, 0);
	std::cout << ans << '\n';
	return 0;
}

void dfs(int now, int cnt) {
	if (cnt >= ans) return;
	if (now == n + 1) {
		ans = std::min(ans, cnt);
		return;
	}
	for (int i = 1; i <= cnt; i++) {
		if (cab[i] + c[now] <= w) {
			cab[i] += c[now];
			dfs(now + 1, cnt);
			cab[i] -= c[now];
		}
	}
	cab[cnt + 1] = c[now];
	dfs(now + 1, cnt + 1);
	cab[cnt + 1] = 0;
}
