// park.cpp
#include <iostream>
#include <fstream>
#include <queue>
#include <utility>
#include <vector>
#include <functional>

//#define debug

#ifndef debug

std::ifstream in("park.in");
std::ofstream out("park.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, m;
int s[1001];
std::priority_queue<std::pair<long long, int>, std::vector<std::pair<int, int> >, std::greater<std::pair<int, int> > > q;

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	in >> n >> m;
	for (int i = 1; i <= m; i++)
		in >> s[i], q.push(std::make_pair(0ll, i));
	for (int i = 1; i < n; i++) {
		std::pair<long long, int> now = q.top();
		out << i << ' ' << now.first << ' ' << now.second << '\n';
		q.pop();
		q.push(std::make_pair(now.first + (long long)s[now.second], now.second));
	}
	out << q.top().second << '\n';
	return 0;
}
