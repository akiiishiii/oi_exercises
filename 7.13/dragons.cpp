// dragons.cpp
#include <iostream>
#include <fstream>
#include <queue>

//#define debug

#ifndef debug

std::ifstream in("dragons.in");
std::ofstream out("dragons.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, cnt, ans;
std::priority_queue<int> q;

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	char c;
	int x;
	in >> n;
	for (int i = 1; i < n; i++) {
		in >> c >> x;
		if (c == 'c')
			q.push(-x);
		else
			while ((int)q.size() > x - 1)
				q.pop();
	}
	in >> c >> x;
	if ((int)q.size() < x)
		out << "-1\n";
	else {
		while (q.size()) {
			ans += -q.top();
			q.pop();
		}
		out << ans << '\n';
	}
	return 0;
}
