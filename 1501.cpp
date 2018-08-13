// 1501.cpp
#include <iostream>
#include <utility>
#include <functional>
#include <algorithm>

struct Compare : public std::binary_function<std::pair<int, int>, std::pair<int, int>, bool> {
    bool operator()(std::pair<int, int> const &a, std::pair<int, int> const &b) { return a.first < b.first; }
};

int main(int argc, const char * argv[]) {
	int n, f[2010], maxi = 0;
    std::pair<int, int> arr[2010];
	f[0] = 0;
    arr[0].first = arr[0].second = 0;
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cin >> arr[i].first >> arr[i].second;
    std::sort(arr + 1, arr + n + 1, Compare());
	for (int i = 1; i <= n; i++) {
		int maxj = 0;
		for (int j = 0; j < i; j++)
			if (arr[j].second < arr[i].second)
				maxj = f[j] > maxj ? f[j] : maxj;
		f[i] = maxj + 1;
	}
	for (int i = 1; i <= n; i++)
		maxi = f[i] > maxi ? f[i] : maxi;
	std::cout << maxi << std::endl;
	return 0;
}
