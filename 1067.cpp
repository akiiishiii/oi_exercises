// 1067.cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main(int argc, const char * argv[]) {
	std::vector<int> q;
	int n, x;
	std::cin >> n;
	q.resize(n);
	for (std::vector<int>::iterator it = q.begin(); it != q.end(); it++)
		std::cin >> *it;
	std::cin >> x;
	std::vector<int>::iterator it = std::search_n(q.begin(), q.end(), 1, x);
	if (it != q.end())
		q.erase(it);
	else {
		q.push_back(x);
		std::sort(q.begin(), q.end());
	}
	for (std::vector<int>::iterator it = q.begin(); it != q.end(); it++)
		std::cout << *it << ' ';
	std::cout << std::endl;
	return 0;
}
