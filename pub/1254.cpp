// 1254.cpp
#include <iostream>
#include <algorithm>
#include <vector>

int po(int n) {
	int res = 1;
	for (int i = 0; i < n; i++)
		res *= 10;
	return res;
}

int main(int argc, const char * argv[]) {
	int n, q, tmp, bits, need;
	std::vector<int> boo, sboo;
	std::cin >> n >> q;
	for (int i = 0; i < n; i++){
		std::cin >> tmp;
		boo.push_back(tmp);
	}

	for (int i = 0; i < q; i++) {
		std::cin >> bits >> need;
		sboo.clear();
		for (std::vector<int>::iterator it = boo.begin(); it != boo.end(); it++) {
			tmp = (*it) % po(bits);
			if (tmp == need)
				sboo.push_back(*it);
		}
		if (sboo.empty())
			std::cout << -1 << std::endl;
		else {
			std::sort(sboo.begin(), sboo.end());
			std::cout << sboo[0] << std::endl;
		}
	}

	return 0;
}