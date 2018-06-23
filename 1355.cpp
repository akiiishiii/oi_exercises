#include <iostream>

template <typename T>
inline T max(const T a, const T b) { return a > b ? a : b;}

int main(int argc, const char * argv[]) {
	int n, arr[1005] = {-1}, f[1005], maxi = 0;
	f[0] = 0;
	std::cin >> n;
	for (int i = 1; i <= n; i++)
		std::cin >> arr[i];
	for (int i = 1; i <= n; i++) {
		int maxj = 0;
		for (int j = 1; j < i; j++)
			if (arr[j] < arr[i])
				maxj = f[j] > maxj ? f[j] : maxj;
		f[i] = maxj + 1;
	}
	for (int i = 1; i <= n; i++)
		maxi = f[i] > maxi ? f[i] : maxi;
	std::cout << maxi << std::endl;
	return 0;
}
