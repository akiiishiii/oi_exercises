// road.cpp
#include <iostream>
#include <fstream>

//#define debug

#ifndef debug

std::ifstream in("road.in");
std::ofstream out("road.out");

#else

#define in std::cin
#define out std::cout

#endif // debug

int n, ans = 0;
int d[100005] = {0};

int fillarr(int l, int r);

int main(int argc, char const *argv[]) {
	std::ios_base::sync_with_stdio(false);
	in.tie(NULL);
	
	int l = 1, r = 0, minn = 0x3f3f3f3f;
	
	in >> n;
	for (int i = 1; i <= n; i++) {
		in >> d[i];
		if (minn > d[i])
			minn = d[i], r = i;
	}
	ans += minn;
	for (int i = 1; i <= n; i++)
		d[i] -= minn;

	while (l <= n) {
		r = fillarr(l, r);
//		std::cout << "out l = " << l << " r = " << r << '\n';
		if (l + 1 >= r) {
//			std::cout << "updatelr\n";
			ans += d[l];
			d[l] = 0;
			while (!d[l] && l <= n)
				l++;
			for (int i = l; i <= n + 1; i++)
				if (!d[i]) {
					r = i;
					break;
			}
//			std::cout << "endupdate\n";
		}
	}
	
//	std::cout << ans << '\n';
	out << ans << '\n';
	
	return 0;
}

int fillarr(int l, int r) {
	int minn = 0x3f3f3f3f, nr;
	for (int i = l; i < r; i++) {
		if (minn > d[i])
			minn = d[i], nr = i;
	}
	ans += minn;
	for (int i = l; i < r; i++)
		d[i] -= minn;
//	std::cout << "fillarr\n";
	return nr;
}
