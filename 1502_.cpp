#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;
struct node{
	int x;
	int y;
} a[1001];

int dp[1001];

bool cmp(node const &a, node const &b) {
	if(a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

int main(int argc, char const *argv[]) {
	int n, m, k;
	std::cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		std::cin >> a[i].x >> a[i].y;
	}
	std::sort(a, a + k, cmp);
	memset(dp, 0, sizeof(dp));
	int max = 0;
	for (int i = 1; i < k; i++) {
		for (int j = 0; j < i; j++) {
			if(a[j].x < a[i].x && a[j].y < a[i].y && dp[i] < dp[j] + 1)
				dp[i] = dp[j] + 1;
		}
		if (max < dp[i])
		    max = dp[i];
	}
	double s = (n + m + (max + 1) * sqrt(2.0) - 2 * (max + 1)) * 100;
	std::cout << int(s + 0.5);
    return 0;
}
