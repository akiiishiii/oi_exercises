// cross.cpp
#include <fstream>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cmath>
#include <iomanip>

//#define debug

#ifndef debug

std::ifstream in("cross.in");
std::ofstream out("cross.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

double const eps = 0.0001;
double h, x0;
double x[10], dr[10];
std::pair<double ,double> c[10];

bool check(double mid);

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	in >> h >> x0;
	double ans;
	for (int i = 1; i <= 7; i++)
		in >> x[i] >> dr[i];
	double l = 0, r = 10000;
	while (l + eps < r) {
		double mid = (l + r) / 2;
		if (!check(mid)) {
			ans = l = mid;
		} else r = mid;
		for (int i = 1; i <= 7; i++)
			dr[i] -= mid;
	}
	out << std::fixed << std::setprecision(2) << ans << '\n';
	return 0;
}

bool check(double mid) {
	for (int i = 1; i <= 7; i++)
		dr[i] += mid;
	for (int i = 1; i <= 7; i++) {
		double dis = sqrt(dr[i] * dr[i] - h * h);
		c[i].first = x[i] - dis;
		c[i].second = x[i] + dis;
	}
	std::sort(c + 1, c + 8);
	double end = 0;
	for (int i = 1; i <= 7; i++) {
		if (end > x0)
			return true;
		if (end < c[i].first)
			return false;
		end = c[i].second;
		end = std::max(end, c[i].second);
	}
	if (end < x0)
		return false;
	return true;
}
