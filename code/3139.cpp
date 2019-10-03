// 3139.cpp
#include <iostream>
#include <algorithm>

struct stone {
	int v, pos;
	bool operator<(stone const &b) const { return v < b.v || (v == b.v && pos > b.pos);	}
} a[500005];

int n, len=0, d[500005], b[500005];

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i].v;
		a[i].pos = i - a[i].v;
	}
	std::sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		b[i] = a[i].pos;
	for (int i = 1; i <= n; i++) {
		if (b[i] < 0)
			continue;
		if (d[len] <= b[i])
			d[++len] = b[i];
		else {
			int l = 1, r = len;
			while (l <= r) {
				int mid = (l + r) / 2;
				if (d[mid] <= b[i])
					l = mid + 1;
				else
					r = mid - 1;
			}
			d[l] = b[i];
		}
	}
	std::cout << len << '\n';
	return 0;
}
